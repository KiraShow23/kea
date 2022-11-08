// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <asiolink/io_address.h>
#include <cc/data.h>
#include <dhcpsrv/lease_mgr.h>
#include <dhcpsrv/memfile_lease_mgr.h>
#include <testutils/gtest_utils.h>
#include <testutils/multi_threading_utils.h>

#include <gtest/gtest.h>

using namespace isc;
using namespace isc::asiolink;
using namespace isc::data;
using namespace isc::db;
using namespace isc::dhcp;
using namespace isc::test;
using namespace isc::util;
using namespace std;

namespace {

/// @brief IPv6 addresses used in the tests.
const vector<string> ADDRESS6 = {
    "2001:db8::0", "2001:db8::1", "2001:db8::2", "2001:db8::3",
    "2001:db8::4", "2001:db8::5", "2001:db8::6", "2001:db8::7"
};

/// @brief DUIDs used in the tests.
const vector<string> DUID6 = {
    "wwwwwwww", "BBBBBBBB", "::::::::", "0123456789acdef",
    "BBBBBBBB", "$$$$$$$$", "^^^^^^^^", "\xe5\xe5\xe5\xe5\xe5\xe5\xe5\xe5"
};

/// @brief A derivation of the lease manager exposing protected methods.
class NakedMemfileLeaseMgr : public Memfile_LeaseMgr {
public:
    /// @brief Constructor.
    ///
    /// Creates an instance of the lease manager.
    ///
    /// @param parameters Parameter map.
    NakedMemfileLeaseMgr(const DatabaseConnection::ParameterMap& parameters)
        : Memfile_LeaseMgr(parameters) {
    }

    /// @brief Destructor.
    virtual ~NakedMemfileLeaseMgr() {
    }

    /// @brief Exposes protected methods and members.
    using Memfile_LeaseMgr::relay_id6_;
    using Memfile_LeaseMgr::remote_id6_;
    using Memfile_LeaseMgr::deleteExtendedInfo6;
    using Memfile_LeaseMgr::addRelayId6;
    using Memfile_LeaseMgr::addRemoteId6;
};

/// @brief Type of unique pointers to naked lease manager.
typedef unique_ptr<NakedMemfileLeaseMgr> NakedMemfileLeaseMgrPtr;

/// @brief Test fixture class for extended info tests.
class MemfileExtendedInfoTest : public ::testing::Test {
public:
    /// @brief Constructor.
    MemfileExtendedInfoTest() {
        pmap_.clear();
        lease_mgr_.reset();
        leases6.clear();
        MultiThreadingMgr::instance().setMode(false);
    }

    /// @brief Destructor.
    ~MemfileExtendedInfoTest() {
        pmap_.clear();
        lease_mgr_.reset();
        leases6.clear();
        MultiThreadingMgr::instance().setMode(false);
    }

    /// @brief Start lease manager.
    ///
    /// @param universe Universe (@c Memfile_LeaseMgr::V4 or
    //  @c Memfile_LeaseMgr::v6).
    void start(Memfile_LeaseMgr::Universe u) {
        pmap_["universe"] = (u == Memfile_LeaseMgr::V4 ? "4" : "6");
        pmap_["persist"] = "false";
        pmap_["extended-info-tables"] = "true";

        ASSERT_NO_THROW(lease_mgr_.reset(new NakedMemfileLeaseMgr(pmap_)));
        EXPECT_TRUE(lease_mgr_->getExtendedInfoTablesEnabled());
    }

    /// @brief Create and set v6 leases.
    void initLease6() {
        ASSERT_EQ(ADDRESS6.size(), DUID6.size());
        for (size_t i = 0; i < ADDRESS6.size(); ++i) {
            Lease6Ptr lease;
            vector<uint8_t> duid_data = createFromString(DUID6[i]);
            DuidPtr duid(new DUID(duid_data));
            IOAddress addr(ADDRESS6[i]);
            ASSERT_NO_THROW(lease.reset(new Lease6(Lease::TYPE_NA, addr, duid,
                                                   123, 1000, 2000,
                                                   static_cast<SubnetID>(i))));
            leases6.push_back(lease);
            EXPECT_TRUE(lease_mgr_->addLease(lease));
        }
    }

    /// @brief Create a vector of uint8_t from a string.
    ///
    /// @param content A not empty string holding the content.
    /// @return A vector of uint8_t with the given content.
    inline vector<uint8_t> createFromString(const string& content) {
        vector<uint8_t> v;
        v.resize(content.size());
        memmove(&v[0], &content[0], v.size());
        return (v);
    }

    /// @brief Parameter map.
    DatabaseConnection::ParameterMap pmap_;

    /// @brief Lease manager.
    NakedMemfileLeaseMgrPtr lease_mgr_;

    /// @brief V6 leases.
    Lease6Collection leases6;
};

/// @brief Verifies that the lease manager can start in V4.
TEST_F(MemfileExtendedInfoTest, startV4) {
    start(Memfile_LeaseMgr::V4);
}

/// @brief Verifies that the lease manager can start in V4 with MT.
TEST_F(MemfileExtendedInfoTest, startV4MultiThreading) {
    MultiThreadingTest mt(true);
    start(Memfile_LeaseMgr::V4);
}

/// @brief Verifies that the lease manager can start in V6.
TEST_F(MemfileExtendedInfoTest, startV6) {
    start(Memfile_LeaseMgr::V6);
}

/// @brief Verifies that the lease manager can start in V6 with MT.
TEST_F(MemfileExtendedInfoTest, startV6MultiThreading) {
    MultiThreadingTest mt(true);
    start(Memfile_LeaseMgr::V6);
}

/// @brief Verifies that the lease manager can add the v6 leases.
TEST_F(MemfileExtendedInfoTest, initLease6) {
    start(Memfile_LeaseMgr::V6);
    initLease6();
    EXPECT_EQ(8, leases6.size());
    Lease6Collection got;
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6());
    ASSERT_EQ(leases6.size(), got.size());
    for (size_t i = 0; i < leases6.size(); ++i) {
        ConstElementPtr expected = leases6[i]->toElement();
        LeasePtr lease = got[i];
        ASSERT_TRUE(lease);
        EXPECT_TRUE(expected->equals(*lease->toElement()))
            << "expected: " << expected->str() << "\n"
            << "got: " << lease->toElement()->str() << "\n";
    }
}

/// @brief Verifies that the lease manager can add the v6 leases with MT.
TEST_F(MemfileExtendedInfoTest, initLease6MultiThreading) {
    MultiThreadingTest mt(true);
    start(Memfile_LeaseMgr::V6);
    initLease6();
    EXPECT_EQ(8, leases6.size());
    Lease6Collection got;
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6());
    ASSERT_EQ(leases6.size(), got.size());
    for (size_t i = 0; i < leases6.size(); ++i) {
        ConstElementPtr expected = leases6[i]->toElement();
        LeasePtr lease = got[i];
        ASSERT_TRUE(lease);
        EXPECT_TRUE(expected->equals(*lease->toElement()))
            << "expected: " << expected->str() << "\n"
            << "got: " << lease->toElement()->str() << "\n";
    }
}

/// @brief Verifies that add and delete work on the by relay id table.
TEST_F(MemfileExtendedInfoTest, relayIdTable6) {
    // Lease manager is created with empty tables.
    start(Memfile_LeaseMgr::V6);
    EXPECT_EQ(0, lease_mgr_->relay_id6_.size());

    // Create parameter values.
    IOAddress lease_addr0(ADDRESS6[0]);
    IOAddress lease_addr1(ADDRESS6[1]);
    IOAddress lease_addr2(ADDRESS6[2]);
    IOAddress other_lease_addr("2001:db8:1::4");
    vector<uint8_t> relay_id0 = createFromString(DUID6[0]);
    vector<uint8_t> relay_id1 = createFromString(DUID6[1]);

    // Fill the table.
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr0, relay_id0));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr0, relay_id0));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr0, relay_id1));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr1, relay_id0));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr1, relay_id1));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr2, relay_id1));

    // Check delete.
    EXPECT_EQ(6, lease_mgr_->relay_id6_.size());
    EXPECT_NO_THROW(lease_mgr_->deleteExtendedInfo6(other_lease_addr));
    // No match so doing nothing.
    EXPECT_EQ(6, lease_mgr_->relay_id6_.size());

    EXPECT_NO_THROW(lease_mgr_->deleteExtendedInfo6(lease_addr0));
    // Removed 3 entries.
    EXPECT_EQ(3, lease_mgr_->relay_id6_.size());
    EXPECT_NO_THROW(lease_mgr_->deleteExtendedInfo6(lease_addr0));
    // Already removed: doing nothing again.
    EXPECT_EQ(3, lease_mgr_->relay_id6_.size());

    EXPECT_NO_THROW(lease_mgr_->deleteExtendedInfo6(lease_addr1));
    // Removed 2 entries.
    EXPECT_EQ(1, lease_mgr_->relay_id6_.size());

    EXPECT_NO_THROW(lease_mgr_->deleteExtendedInfo6(lease_addr2));
    // Removed last entry.
    EXPECT_EQ(0, lease_mgr_->relay_id6_.size());
}

/// @brief Verifies that add and delete work on the by remote id table.
TEST_F(MemfileExtendedInfoTest, remoteIdTable6) {
    // Lease manager is created with empty tables.
    start(Memfile_LeaseMgr::V6);
    EXPECT_EQ(0, lease_mgr_->remote_id6_.size());

    // Create parameter values.
    IOAddress lease_addr0(ADDRESS6[0]);
    IOAddress lease_addr1(ADDRESS6[1]);
    IOAddress lease_addr2(ADDRESS6[2]);
    IOAddress other_lease_addr("2001:db8:1::4");
    vector<uint8_t> remote_id0 = createFromString(DUID6[0]);
    vector<uint8_t> remote_id1 = createFromString(DUID6[1]);

    // Fill the table.
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr0, remote_id0));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr0, remote_id0));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr0, remote_id1));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr1, remote_id0));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr1, remote_id1));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr2, remote_id1));

    // Check delete.
    EXPECT_EQ(6, lease_mgr_->remote_id6_.size());
    EXPECT_NO_THROW(lease_mgr_->deleteExtendedInfo6(other_lease_addr));
    // No match so doing nothing.
    EXPECT_EQ(6, lease_mgr_->remote_id6_.size());

    EXPECT_NO_THROW(lease_mgr_->deleteExtendedInfo6(lease_addr0));
    // Removed 3 entries.
    EXPECT_EQ(3, lease_mgr_->remote_id6_.size());
    EXPECT_NO_THROW(lease_mgr_->deleteExtendedInfo6(lease_addr0));
    // Already removed: doing nothing again.
    EXPECT_EQ(3, lease_mgr_->remote_id6_.size());

    EXPECT_NO_THROW(lease_mgr_->deleteExtendedInfo6(lease_addr1));
    // Removed 2 entries.
    EXPECT_EQ(1, lease_mgr_->remote_id6_.size());

    EXPECT_NO_THROW(lease_mgr_->deleteExtendedInfo6(lease_addr2));
    // Removed last entry.
    EXPECT_EQ(0, lease_mgr_->remote_id6_.size());
}

/// @brief Verifies that getLeases6ByRelayId works as expected.
TEST_F(MemfileExtendedInfoTest, getLeases6ByRelayId) {
    // Lease manager is created with empty tables.
    start(Memfile_LeaseMgr::V6);
    initLease6();
    EXPECT_EQ(0, lease_mgr_->relay_id6_.size());

    // Create parameter values.
    IOAddress lease_addr0(ADDRESS6[0]);
    IOAddress lease_addr1(ADDRESS6[1]);
    IOAddress lease_addr2(ADDRESS6[2]);
    IOAddress link_addr(ADDRESS6[4]);
    IOAddress other_link_addr("2001:db8:1::4");
    IOAddress zero = IOAddress::IPV6_ZERO_ADDRESS();
    vector<uint8_t> relay_id_data0 = createFromString(DUID6[0]);
    DUID relay_id0(relay_id_data0);
    vector<uint8_t> relay_id_data1 = createFromString(DUID6[1]);
    DUID relay_id1(relay_id_data1);
    vector<uint8_t> relay_id_data2 = createFromString(DUID6[2]);
    DUID relay_id2(relay_id_data2);

    // Fill the table.
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr0, relay_id_data0));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr0, relay_id_data0));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr0, relay_id_data1));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr1, relay_id_data0));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr1, relay_id_data1));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr2, relay_id_data1));
    EXPECT_EQ(6, lease_mgr_->relay_id6_.size());

    Lease6Collection got;
    // Unknown relay id #2, no link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id2,
                                                          zero,
                                                          0,
                                                          zero,
                                                          LeasePageSize(100)));
    EXPECT_EQ(0, got.size());

    // Unknown relay id #2, link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id2,
                                                          link_addr,
                                                          64,
                                                          zero,
                                                          LeasePageSize(100)));
    EXPECT_EQ(0, got.size());

    // Relay id #0, other link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id0,
                                                          other_link_addr,
                                                          64,
                                                          zero,
                                                          LeasePageSize(100)));
    EXPECT_EQ(0, got.size());

    // Relay id #0, no link: 3 entries but 2 addresses.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id0,
                                                          zero,
                                                          0,
                                                          zero,
                                                          LeasePageSize(100)));
    ASSERT_EQ(2, got.size());
    Lease6Ptr lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);
    lease = got[1];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);

    // Relay id #1, no link, partial: 2 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          zero,
                                                          0,
                                                          zero,
                                                          LeasePageSize(2)));
    ASSERT_EQ(2, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);
    lease = got[1];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);

    // Relay id #1, no link, partial from previous: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          zero,
                                                          0,
                                                          lease->addr_,
                                                          LeasePageSize(2)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr2, lease->addr_);

    // Add another entry for last tests.
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr0, relay_id_data1));
    EXPECT_EQ(7, lease_mgr_->relay_id6_.size());

    // Relay id #1, link: 3 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          link_addr,
                                                          64,
                                                          zero,
                                                          LeasePageSize(100)));
    ASSERT_EQ(3, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);
    lease = got[1];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);
    lease = got[2];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr2, lease->addr_);

    // Relay id #1, link, initial partial: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          link_addr,
                                                          64,
                                                          zero,
                                                          LeasePageSize(1)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);

    // Relay id #1, link, next partial: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          link_addr,
                                                          64,
                                                          lease->addr_,
                                                          LeasePageSize(1)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);

    // Relay id #1, link, next partial: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          link_addr,
                                                          64,
                                                          lease->addr_,
                                                          LeasePageSize(1)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr2, lease->addr_);

    // Relay id #1, link, final partial: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          link_addr,
                                                          64,
                                                          lease->addr_,
                                                          LeasePageSize(1)));
    EXPECT_EQ(0, got.size());
}

/// @brief Verifies that getLeases6ByRelayId works as expected with MT.
TEST_F(MemfileExtendedInfoTest, getLeases6ByRelayIdMultiThreading) {
    MultiThreadingTest mt(true);
    // Lease manager is created with empty tables.
    start(Memfile_LeaseMgr::V6);
    initLease6();
    EXPECT_EQ(0, lease_mgr_->relay_id6_.size());

    // Create parameter values.
    IOAddress lease_addr0(ADDRESS6[0]);
    IOAddress lease_addr1(ADDRESS6[1]);
    IOAddress lease_addr2(ADDRESS6[2]);
    IOAddress link_addr(ADDRESS6[4]);
    IOAddress other_link_addr("2001:db8:1::4");
    IOAddress zero = IOAddress::IPV6_ZERO_ADDRESS();
    vector<uint8_t> relay_id_data0 = createFromString(DUID6[0]);
    DUID relay_id0(relay_id_data0);
    vector<uint8_t> relay_id_data1 = createFromString(DUID6[1]);
    DUID relay_id1(relay_id_data1);
    vector<uint8_t> relay_id_data2 = createFromString(DUID6[2]);
    DUID relay_id2(relay_id_data2);

    // Fill the table.
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr0, relay_id_data0));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr0, relay_id_data0));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr0, relay_id_data1));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr1, relay_id_data0));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr1, relay_id_data1));
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr2, relay_id_data1));
    EXPECT_EQ(6, lease_mgr_->relay_id6_.size());

    Lease6Collection got;
    // Unknown relay id #2, no link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id2,
                                                          zero,
                                                          0,
                                                          zero,
                                                          LeasePageSize(100)));
    EXPECT_EQ(0, got.size());

    // Unknown relay id #2, link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id2,
                                                          link_addr,
                                                          64,
                                                          zero,
                                                          LeasePageSize(100)));
    EXPECT_EQ(0, got.size());

    // Relay id #0, other link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id0,
                                                          other_link_addr,
                                                          64,
                                                          zero,
                                                          LeasePageSize(100)));
    EXPECT_EQ(0, got.size());

    // Relay id #0, no link: 3 entries but 2 addresses.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id0,
                                                          zero,
                                                          0,
                                                          zero,
                                                          LeasePageSize(100)));
    ASSERT_EQ(2, got.size());
    Lease6Ptr lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);
    lease = got[1];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);

    // Relay id #1, no link, partial: 2 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          zero,
                                                          0,
                                                          zero,
                                                          LeasePageSize(2)));
    ASSERT_EQ(2, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);
    lease = got[1];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);

    // Relay id #1, no link, partial from previous: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          zero,
                                                          0,
                                                          lease->addr_,
                                                          LeasePageSize(2)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr2, lease->addr_);

    // Add another entry for last tests.
    EXPECT_NO_THROW(lease_mgr_->addRelayId6(lease_addr0, relay_id_data1));
    EXPECT_EQ(7, lease_mgr_->relay_id6_.size());

    // Relay id #1, link: 3 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          link_addr,
                                                          64,
                                                          zero,
                                                          LeasePageSize(100)));
    ASSERT_EQ(3, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);
    lease = got[1];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);
    lease = got[2];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr2, lease->addr_);

    // Relay id #1, link, initial partial: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          link_addr,
                                                          64,
                                                          zero,
                                                          LeasePageSize(1)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);

    // Relay id #1, link, next partial: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          link_addr,
                                                          64,
                                                          lease->addr_,
                                                          LeasePageSize(1)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);

    // Relay id #1, link, next partial: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          link_addr,
                                                          64,
                                                          lease->addr_,
                                                          LeasePageSize(1)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr2, lease->addr_);

    // Relay id #1, link, final partial: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRelayId(relay_id1,
                                                          link_addr,
                                                          64,
                                                          lease->addr_,
                                                          LeasePageSize(1)));
    EXPECT_EQ(0, got.size());
}

/// @brief Verifies that getLeases6ByRemoteId works as expected.
TEST_F(MemfileExtendedInfoTest, getLeases6ByRemoteId) {
    // Lease manager is created with empty tables.
    start(Memfile_LeaseMgr::V6);
    initLease6();
    EXPECT_EQ(0, lease_mgr_->remote_id6_.size());

    // Create parameter values.
    IOAddress lease_addr0(ADDRESS6[0]);
    IOAddress lease_addr1(ADDRESS6[1]);
    IOAddress lease_addr2(ADDRESS6[2]);
    IOAddress link_addr(ADDRESS6[4]);
    IOAddress other_link_addr("2001:db8:1::4");
    IOAddress zero = IOAddress::IPV6_ZERO_ADDRESS();
    vector<uint8_t> remote_id0 = createFromString(DUID6[0]);
    vector<uint8_t> remote_id1 = createFromString(DUID6[1]);
    vector<uint8_t> remote_id2 = createFromString(DUID6[2]);

    // Fill the table.
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr0, remote_id0));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr0, remote_id0));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr0, remote_id1));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr1, remote_id0));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr1, remote_id1));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr2, remote_id1));
    EXPECT_EQ(6, lease_mgr_->remote_id6_.size());

    Lease6Collection got;
    // Unknown remote id #2, no link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id2,
                                                           zero,
                                                           0,
                                                           zero,
                                                           LeasePageSize(10)));
    EXPECT_EQ(0, got.size());

    // Unknown remote id #2, link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id2,
                                                           link_addr,
                                                           64,
                                                           zero,
                                                           LeasePageSize(10)));
    EXPECT_EQ(0, got.size());

    // Remote id #0, other link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id0,
                                                           other_link_addr,
                                                           64,
                                                           zero,
                                                           LeasePageSize(10)));
    EXPECT_EQ(0, got.size());

    // Remote id #0, no link: 3 entries but 2 addresses.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id0,
                                                           zero,
                                                           0,
                                                           zero,
                                                           LeasePageSize(10)));
    ASSERT_EQ(2, got.size());
    Lease6Ptr lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);
    lease = got[1];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);

    // Remote id #1, no link, partial: 2 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           zero,
                                                           0,
                                                           zero,
                                                           LeasePageSize(2)));
    ASSERT_EQ(2, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);
    lease = got[1];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);

    // Remote id #1, no link, partial from previous: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           zero,
                                                           0,
                                                           lease->addr_,
                                                           LeasePageSize(2)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr2, lease->addr_);

    // Add another entry for last tests.
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr0, remote_id1));
    EXPECT_EQ(7, lease_mgr_->remote_id6_.size());

    // Remote id #1, link: 3 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           link_addr,
                                                           64,
                                                           zero,
                                                           LeasePageSize(10)));
    ASSERT_EQ(3, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);
    lease = got[1];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);
    lease = got[2];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr2, lease->addr_);

    // Remote id #1, link, initial partial: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           link_addr,
                                                           64,
                                                           zero,
                                                           LeasePageSize(1)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);

    // Remote id #1, link, next partial: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           link_addr,
                                                           64,
                                                           lease->addr_,
                                                           LeasePageSize(1)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);

    // Remote id #1, link, next partial: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           link_addr,
                                                           64,
                                                           lease->addr_,
                                                           LeasePageSize(1)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr2, lease->addr_);

    // Remote id #1, link, final partial: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           link_addr,
                                                           64,
                                                           lease->addr_,
                                                           LeasePageSize(1)));
    EXPECT_EQ(0, got.size());
}

/// @brief Verifies that getLeases6ByRemoteId works as expected with MT.
TEST_F(MemfileExtendedInfoTest, getLeases6ByRemoteIdMultiThreading) {
    MultiThreadingTest mt(true);
    // Lease manager is created with empty tables.
    start(Memfile_LeaseMgr::V6);
    initLease6();
    EXPECT_EQ(0, lease_mgr_->remote_id6_.size());

    // Create parameter values.
    IOAddress lease_addr0(ADDRESS6[0]);
    IOAddress lease_addr1(ADDRESS6[1]);
    IOAddress lease_addr2(ADDRESS6[2]);
    IOAddress link_addr(ADDRESS6[4]);
    IOAddress other_link_addr("2001:db8:1::4");
    IOAddress zero = IOAddress::IPV6_ZERO_ADDRESS();
    vector<uint8_t> remote_id0 = createFromString(DUID6[0]);
    vector<uint8_t> remote_id1 = createFromString(DUID6[1]);
    vector<uint8_t> remote_id2 = createFromString(DUID6[2]);

    // Fill the table.
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr0, remote_id0));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr0, remote_id0));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr0, remote_id1));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr1, remote_id0));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr1, remote_id1));
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr2, remote_id1));
    EXPECT_EQ(6, lease_mgr_->remote_id6_.size());

    Lease6Collection got;
    // Unknown remote id #2, no link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id2,
                                                           zero,
                                                           0,
                                                           zero,
                                                           LeasePageSize(10)));
    EXPECT_EQ(0, got.size());

    // Unknown remote id #2, link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id2,
                                                           link_addr,
                                                           64,
                                                           zero,
                                                           LeasePageSize(10)));
    EXPECT_EQ(0, got.size());

    // Remote id #0, other link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id0,
                                                           other_link_addr,
                                                           64,
                                                           zero,
                                                           LeasePageSize(10)));
    EXPECT_EQ(0, got.size());

    // Remote id #0, no link: 3 entries but 2 addresses.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id0,
                                                           zero,
                                                           0,
                                                           zero,
                                                           LeasePageSize(10)));
    ASSERT_EQ(2, got.size());
    Lease6Ptr lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);
    lease = got[1];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);

    // Remote id #1, no link, partial: 2 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           zero,
                                                           0,
                                                           zero,
                                                           LeasePageSize(2)));
    ASSERT_EQ(2, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);
    lease = got[1];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);

    // Remote id #1, no link, partial from previous: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           zero,
                                                           0,
                                                           lease->addr_,
                                                           LeasePageSize(2)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr2, lease->addr_);

    // Add another entry for last tests.
    EXPECT_NO_THROW(lease_mgr_->addRemoteId6(lease_addr0, remote_id1));
    EXPECT_EQ(7, lease_mgr_->remote_id6_.size());

    // Remote id #1, link: 3 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           link_addr,
                                                           64,
                                                           zero,
                                                           LeasePageSize(10)));
    ASSERT_EQ(3, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);
    lease = got[1];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);
    lease = got[2];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr2, lease->addr_);

    // Remote id #1, link, initial partial: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           link_addr,
                                                           64,
                                                           zero,
                                                           LeasePageSize(1)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr0, lease->addr_);

    // Remote id #1, link, next partial: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           link_addr,
                                                           64,
                                                           lease->addr_,
                                                           LeasePageSize(1)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr1, lease->addr_);

    // Remote id #1, link, next partial: 1 entry.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           link_addr,
                                                           64,
                                                           lease->addr_,
                                                           LeasePageSize(1)));
    ASSERT_EQ(1, got.size());
    lease = got[0];
    ASSERT_TRUE(lease);
    EXPECT_EQ(lease_addr2, lease->addr_);

    // Remote id #1, link, final partial: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByRemoteId(remote_id1,
                                                           link_addr,
                                                           64,
                                                           lease->addr_,
                                                           LeasePageSize(1)));
    EXPECT_EQ(0, got.size());
}

/// @brief Verifies that getLeases6ByLink works as expected.
TEST_F(MemfileExtendedInfoTest, getLeases6ByLink) {
    // Lease manager is created with empty tables.
    start(Memfile_LeaseMgr::V6);
    initLease6();

    // Create parameter values.
    IOAddress link_addr(ADDRESS6[4]);
    IOAddress other_link_addr("2001:db8:1::4");
    IOAddress zero = IOAddress::IPV6_ZERO_ADDRESS();

    Lease6Collection got;
    // Other link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByLink(other_link_addr,
                                                       64,
                                                       zero,
                                                       LeasePageSize(10)));
    EXPECT_EQ(0, got.size());

    // Link: 8 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByLink(link_addr,
                                                       64,
                                                       zero,
                                                       LeasePageSize(10)));

    ASSERT_EQ(8, got.size());
    Lease6Ptr lease;
    for (size_t i = 0; i < 8; ++i) {
        lease = got[i];
        ASSERT_TRUE(lease);
        EXPECT_EQ(IOAddress(ADDRESS6[i]), lease->addr_);
    }

    // Link: initial partial: 4 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByLink(link_addr,
                                                       64,
                                                       zero,
                                                       LeasePageSize(4)));
    ASSERT_EQ(4, got.size());
    for (size_t i = 0; i < 4; ++i) {
        lease = got[i];
        ASSERT_TRUE(lease);
        EXPECT_EQ(IOAddress(ADDRESS6[i]), lease->addr_);
    }

    // Link: next partial: 4 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByLink(link_addr,
                                                       64,
                                                       lease->addr_,
                                                       LeasePageSize(4)));
    ASSERT_EQ(4, got.size());
    for (size_t i = 0; i < 4; ++i) {
        lease = got[i];
        ASSERT_TRUE(lease);
        EXPECT_EQ(IOAddress(ADDRESS6[i + 4]), lease->addr_);
    }

    // Link: further partial: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByLink(link_addr,
                                                       64,
                                                       lease->addr_,
                                                       LeasePageSize(4)));
    EXPECT_EQ(0, got.size());
}

/// @brief Verifies that getLeases6ByLink works as expected with MT.
TEST_F(MemfileExtendedInfoTest, getLeases6ByLinkMultiThreading) {
    MultiThreadingTest mt(true);
    start(Memfile_LeaseMgr::V6);
    initLease6();

    // Create parameter values.
    IOAddress link_addr(ADDRESS6[4]);
    IOAddress other_link_addr("2001:db8:1::4");
    IOAddress zero = IOAddress::IPV6_ZERO_ADDRESS();

    Lease6Collection got;
    // Other link: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByLink(other_link_addr,
                                                       64,
                                                       zero,
                                                       LeasePageSize(10)));
    EXPECT_EQ(0, got.size());

    // Link: 8 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByLink(link_addr,
                                                       64,
                                                       zero,
                                                       LeasePageSize(10)));

    ASSERT_EQ(8, got.size());
    Lease6Ptr lease;
    for (size_t i = 0; i < 8; ++i) {
        lease = got[i];
        ASSERT_TRUE(lease);
        EXPECT_EQ(IOAddress(ADDRESS6[i]), lease->addr_);
    }

    // Link: initial partial: 4 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByLink(link_addr,
                                                       64,
                                                       zero,
                                                       LeasePageSize(4)));
    ASSERT_EQ(4, got.size());
    for (size_t i = 0; i < 4; ++i) {
        lease = got[i];
        ASSERT_TRUE(lease);
        EXPECT_EQ(IOAddress(ADDRESS6[i]), lease->addr_);
    }

    // Link: next partial: 4 entries.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByLink(link_addr,
                                                       64,
                                                       lease->addr_,
                                                       LeasePageSize(4)));
    ASSERT_EQ(4, got.size());
    for (size_t i = 0; i < 4; ++i) {
        lease = got[i];
        ASSERT_TRUE(lease);
        EXPECT_EQ(IOAddress(ADDRESS6[i + 4]), lease->addr_);
    }

    // Link: further partial: nothing.
    EXPECT_NO_THROW(got = lease_mgr_->getLeases6ByLink(link_addr,
                                                       64,
                                                       lease->addr_,
                                                       LeasePageSize(4)));
    EXPECT_EQ(0, got.size());
}

}  // namespace