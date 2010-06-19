// Copyright (C) 2010  Internet Systems Consortium, Inc. ("ISC")
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

// $Id$

#ifndef __ASIO_LINK_H
#define __ASIO_LINK_H 1

#include <string>

#include <exceptions/exceptions.h>

namespace asio {
class io_service;

namespace ip {
class address;
}
}

class AuthSrv;

namespace asio_link {
struct IOServiceImpl;

/// \brief An exception that is thrown if an error occurs with in the IO
/// module.  This is mainly intended to be a wrapper exception class for
/// ASIO specific exceptions.
class IOError : public isc::Exception {
public:
    IOError(const char* file, size_t line, const char* what) :
        isc::Exception(file, line, what) {}
};

class IOAddress {
private:
    IOAddress(const IOAddress& source);
    IOAddress& operator=(const IOAddress& source);
public:
    IOAddress(const std::string& adress_str);
    IOAddress(const asio::ip::address& asio_adress);
    std::string toText() const;
    ~IOAddress();
private:
    asio::ip::address* asio_address_placeholder_;
    const asio::ip::address& asio_address_;
};

class IOMessage {
private:
    IOMessage(const IOMessage& source);
    IOMessage& operator=(const IOMessage& source);
public:
    IOMessage();
    ~IOMessage();
    const void* getData() const;
    size_t getDataSize() const;
    int getNative() const;
    const IOAddress& getRemoteAddress() const;
private:
    class IOMessageImpl;
    IOMessageImpl* impl_;
};

class IOService {
public:
    IOService(AuthSrv* auth_server, const char* port, bool use_ipv4,
              bool use_ipv6);
    ~IOService();
    void run();
    void stop();
    asio::io_service& get_io_service();
private:
    IOServiceImpl* impl_;
};
}      // asio_link
#endif // __ASIO_LINK_H

// Local Variables: 
// mode: c++
// End: 
