// Copyright (C) 2018 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>
#include <netconf/netconf_controller.h>
#include <netconf/netconf_process.h>
#include <cc/data.h>
#include <process/testutils/d_test_stubs.h>
#include <boost/pointer_cast.hpp>
#include <sstream>

using namespace std;
using namespace isc::netconf;
using namespace isc::data;
using namespace isc::http;
using namespace isc::process;
using namespace boost::posix_time;

namespace {

/// @brief test fixture class for testing NetconfController class.
///
/// This class derives from DControllerTest and wraps NetconfController. Much
/// of the underlying functionality is in the DControllerBase class which
/// has extensive set of unit tests that are independent from Netconf.
class NetconfControllerTest : public DControllerTest {
public:

    /// @brief Constructor.
    NetconfControllerTest()
        : DControllerTest(NetconfController::instance) {
    }

    /// @brief Returns pointer to NetconfProcess instance.
    NetconfProcessPtr getNetconfProcess() {
        return (boost::dynamic_pointer_cast<NetconfProcess>(getProcess()));
    }

    /// @brief Returns pointer to NetconfCfgMgr instance for a process.
    NetconfCfgMgrPtr getNetconfCfgMgr() {
        NetconfCfgMgrPtr p;
        if (getNetconfProcess()) {
            p = getNetconfProcess()->getNetconfCfgMgr();
        }
        return (p);
    }

    /// @brief Returns a pointer to the configuration context.
    NetconfConfigPtr getNetconfConfig() {
        NetconfConfigPtr p;
        if (getNetconfCfgMgr()) {
            p = getNetconfCfgMgr()->getNetconfConfig();
        }
        return (p);
    }
};

// Basic Controller instantiation testing.
// Verifies that the controller singleton gets created and that the
// basic derivation from the base class is intact.
TEST_F(NetconfControllerTest, basicInstanceTesting) {
    // Verify the singleton instance can be fetched and that
    // it has the correct type.
    DControllerBasePtr& controller = DControllerTest::getController();
    ASSERT_TRUE(controller);
    ASSERT_NO_THROW(boost::dynamic_pointer_cast<NetconfController>(controller));

    // Verify that controller's app name is correct.
    EXPECT_TRUE(checkAppName(NetconfController::netconf_app_name_));

    // Verify that controller's bin name is correct.
    EXPECT_TRUE(checkBinName(NetconfController::netconf_bin_name_));

    // Verify that controller's IOService exists.
    EXPECT_TRUE(checkIOService());

    // Verify that the Process does NOT exist.
    EXPECT_FALSE(checkProcess());
}


// Tests basic command line processing.
// Verifies that:
// 1. Standard command line options are supported.
// 2. Invalid options are detected.
TEST_F(NetconfControllerTest, commandLineArgs) {
    char* argv[] = { const_cast<char*>("progName"),
                     const_cast<char*>("-c"),
                     const_cast<char*>(DControllerTest::CFG_TEST_FILE),
                     const_cast<char*>("-d") };
    int argc = 4;

    // Verify that verbose flag is false initially.
    EXPECT_TRUE(checkVerbose(false));

    // Verify that standard options can be parsed without error.
    EXPECT_NO_THROW(parseArgs(argc, argv));

    // Verify that verbose flag is true.
    EXPECT_TRUE(checkVerbose(true));

    // Verify configuration file name is correct.
    EXPECT_TRUE(checkConfigFileName(DControllerTest::CFG_TEST_FILE));

    // Verify that an unknown option is detected.
    char* argv2[] = { const_cast<char*>("progName"),
                      const_cast<char*>("-x") };
    argc = 2;
    EXPECT_THROW(parseArgs(argc, argv2), InvalidUsage);
}

// Tests application process creation and initialization.
// Verifies that the process can be successfully created and initialized.
TEST_F(NetconfControllerTest, initProcessTesting) {
    ASSERT_NO_THROW(initProcess());
    EXPECT_TRUE(checkProcess());
}

}
