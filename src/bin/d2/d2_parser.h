// A Bison parser, made by GNU Bison 3.6.4.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file d2_parser.h
 ** Define the isc::d2::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_D2_PARSER_D2_PARSER_H_INCLUDED
# define YY_D2_PARSER_D2_PARSER_H_INCLUDED
// "%code requires" blocks.
#line 17 "d2_parser.yy"

#include <string>
#include <cc/data.h>
#include <d2/d2_config.h>
#include <boost/lexical_cast.hpp>
#include <d2/parser_context_decl.h>

using namespace isc::d2;
using namespace isc::data;
using namespace std;

#line 61 "d2_parser.h"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef D2_PARSER_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define D2_PARSER_DEBUG 1
#  else
#   define D2_PARSER_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define D2_PARSER_DEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined D2_PARSER_DEBUG */

#line 14 "d2_parser.yy"
namespace isc { namespace d2 {
#line 204 "d2_parser.h"




  /// A Bison parser.
  class D2Parser
  {
  public:
#ifndef D2_PARSER_STYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // value
      // map_value
      // ncr_protocol_value
      char dummy1[sizeof (ElementPtr)];

      // "boolean"
      char dummy2[sizeof (bool)];

      // "floating point"
      char dummy3[sizeof (double)];

      // "integer"
      char dummy4[sizeof (int64_t)];

      // "constant string"
      char dummy5[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef D2_PARSER_STYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOKEN_D2_PARSER_EMPTY = -2,
    TOKEN_END = 0,                 // "end of file"
    TOKEN_D2_PARSER_error = 256,   // error
    TOKEN_D2_PARSER_UNDEF = 257,   // "invalid token"
    TOKEN_COMMA = 258,             // ","
    TOKEN_COLON = 259,             // ":"
    TOKEN_LSQUARE_BRACKET = 260,   // "["
    TOKEN_RSQUARE_BRACKET = 261,   // "]"
    TOKEN_LCURLY_BRACKET = 262,    // "{"
    TOKEN_RCURLY_BRACKET = 263,    // "}"
    TOKEN_NULL_TYPE = 264,         // "null"
    TOKEN_DHCP6 = 265,             // "Dhcp6"
    TOKEN_DHCP4 = 266,             // "Dhcp4"
    TOKEN_CONTROL_AGENT = 267,     // "Control-agent"
    TOKEN_DHCPDDNS = 268,          // "DhcpDdns"
    TOKEN_IP_ADDRESS = 269,        // "ip-address"
    TOKEN_PORT = 270,              // "port"
    TOKEN_DNS_SERVER_TIMEOUT = 271, // "dns-server-timeout"
    TOKEN_NCR_PROTOCOL = 272,      // "ncr-protocol"
    TOKEN_UDP = 273,               // "UDP"
    TOKEN_TCP = 274,               // "TCP"
    TOKEN_NCR_FORMAT = 275,        // "ncr-format"
    TOKEN_JSON = 276,              // "JSON"
    TOKEN_USER_CONTEXT = 277,      // "user-context"
    TOKEN_COMMENT = 278,           // "comment"
    TOKEN_FORWARD_DDNS = 279,      // "forward-ddns"
    TOKEN_REVERSE_DDNS = 280,      // "reverse-ddns"
    TOKEN_DDNS_DOMAINS = 281,      // "ddns-domains"
    TOKEN_KEY_NAME = 282,          // "key-name"
    TOKEN_DNS_SERVERS = 283,       // "dns-servers"
    TOKEN_HOSTNAME = 284,          // "hostname"
    TOKEN_TSIG_KEYS = 285,         // "tsig-keys"
    TOKEN_ALGORITHM = 286,         // "algorithm"
    TOKEN_DIGEST_BITS = 287,       // "digest-bits"
    TOKEN_SECRET = 288,            // "secret"
    TOKEN_CONTROL_SOCKET = 289,    // "control-socket"
    TOKEN_SOCKET_TYPE = 290,       // "socket-type"
    TOKEN_SOCKET_NAME = 291,       // "socket-name"
    TOKEN_LOGGING = 292,           // "Logging"
    TOKEN_LOGGERS = 293,           // "loggers"
    TOKEN_NAME = 294,              // "name"
    TOKEN_OUTPUT_OPTIONS = 295,    // "output_options"
    TOKEN_OUTPUT = 296,            // "output"
    TOKEN_DEBUGLEVEL = 297,        // "debuglevel"
    TOKEN_SEVERITY = 298,          // "severity"
    TOKEN_FLUSH = 299,             // "flush"
    TOKEN_MAXSIZE = 300,           // "maxsize"
    TOKEN_MAXVER = 301,            // "maxver"
    TOKEN_PATTERN = 302,           // "pattern"
    TOKEN_TOPLEVEL_JSON = 303,     // TOPLEVEL_JSON
    TOKEN_TOPLEVEL_DHCPDDNS = 304, // TOPLEVEL_DHCPDDNS
    TOKEN_SUB_DHCPDDNS = 305,      // SUB_DHCPDDNS
    TOKEN_SUB_TSIG_KEY = 306,      // SUB_TSIG_KEY
    TOKEN_SUB_TSIG_KEYS = 307,     // SUB_TSIG_KEYS
    TOKEN_SUB_DDNS_DOMAIN = 308,   // SUB_DDNS_DOMAIN
    TOKEN_SUB_DDNS_DOMAINS = 309,  // SUB_DDNS_DOMAINS
    TOKEN_SUB_DNS_SERVER = 310,    // SUB_DNS_SERVER
    TOKEN_SUB_DNS_SERVERS = 311,   // SUB_DNS_SERVERS
    TOKEN_STRING = 312,            // "constant string"
    TOKEN_INTEGER = 313,           // "integer"
    TOKEN_FLOAT = 314,             // "floating point"
    TOKEN_BOOLEAN = 315            // "boolean"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 61, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_COMMA = 3,                             // ","
        S_COLON = 4,                             // ":"
        S_LSQUARE_BRACKET = 5,                   // "["
        S_RSQUARE_BRACKET = 6,                   // "]"
        S_LCURLY_BRACKET = 7,                    // "{"
        S_RCURLY_BRACKET = 8,                    // "}"
        S_NULL_TYPE = 9,                         // "null"
        S_DHCP6 = 10,                            // "Dhcp6"
        S_DHCP4 = 11,                            // "Dhcp4"
        S_CONTROL_AGENT = 12,                    // "Control-agent"
        S_DHCPDDNS = 13,                         // "DhcpDdns"
        S_IP_ADDRESS = 14,                       // "ip-address"
        S_PORT = 15,                             // "port"
        S_DNS_SERVER_TIMEOUT = 16,               // "dns-server-timeout"
        S_NCR_PROTOCOL = 17,                     // "ncr-protocol"
        S_UDP = 18,                              // "UDP"
        S_TCP = 19,                              // "TCP"
        S_NCR_FORMAT = 20,                       // "ncr-format"
        S_JSON = 21,                             // "JSON"
        S_USER_CONTEXT = 22,                     // "user-context"
        S_COMMENT = 23,                          // "comment"
        S_FORWARD_DDNS = 24,                     // "forward-ddns"
        S_REVERSE_DDNS = 25,                     // "reverse-ddns"
        S_DDNS_DOMAINS = 26,                     // "ddns-domains"
        S_KEY_NAME = 27,                         // "key-name"
        S_DNS_SERVERS = 28,                      // "dns-servers"
        S_HOSTNAME = 29,                         // "hostname"
        S_TSIG_KEYS = 30,                        // "tsig-keys"
        S_ALGORITHM = 31,                        // "algorithm"
        S_DIGEST_BITS = 32,                      // "digest-bits"
        S_SECRET = 33,                           // "secret"
        S_CONTROL_SOCKET = 34,                   // "control-socket"
        S_SOCKET_TYPE = 35,                      // "socket-type"
        S_SOCKET_NAME = 36,                      // "socket-name"
        S_LOGGING = 37,                          // "Logging"
        S_LOGGERS = 38,                          // "loggers"
        S_NAME = 39,                             // "name"
        S_OUTPUT_OPTIONS = 40,                   // "output_options"
        S_OUTPUT = 41,                           // "output"
        S_DEBUGLEVEL = 42,                       // "debuglevel"
        S_SEVERITY = 43,                         // "severity"
        S_FLUSH = 44,                            // "flush"
        S_MAXSIZE = 45,                          // "maxsize"
        S_MAXVER = 46,                           // "maxver"
        S_PATTERN = 47,                          // "pattern"
        S_TOPLEVEL_JSON = 48,                    // TOPLEVEL_JSON
        S_TOPLEVEL_DHCPDDNS = 49,                // TOPLEVEL_DHCPDDNS
        S_SUB_DHCPDDNS = 50,                     // SUB_DHCPDDNS
        S_SUB_TSIG_KEY = 51,                     // SUB_TSIG_KEY
        S_SUB_TSIG_KEYS = 52,                    // SUB_TSIG_KEYS
        S_SUB_DDNS_DOMAIN = 53,                  // SUB_DDNS_DOMAIN
        S_SUB_DDNS_DOMAINS = 54,                 // SUB_DDNS_DOMAINS
        S_SUB_DNS_SERVER = 55,                   // SUB_DNS_SERVER
        S_SUB_DNS_SERVERS = 56,                  // SUB_DNS_SERVERS
        S_STRING = 57,                           // "constant string"
        S_INTEGER = 58,                          // "integer"
        S_FLOAT = 59,                            // "floating point"
        S_BOOLEAN = 60,                          // "boolean"
        S_YYACCEPT = 61,                         // $accept
        S_start = 62,                            // start
        S_63_1 = 63,                             // $@1
        S_64_2 = 64,                             // $@2
        S_65_3 = 65,                             // $@3
        S_66_4 = 66,                             // $@4
        S_67_5 = 67,                             // $@5
        S_68_6 = 68,                             // $@6
        S_69_7 = 69,                             // $@7
        S_70_8 = 70,                             // $@8
        S_71_9 = 71,                             // $@9
        S_value = 72,                            // value
        S_sub_json = 73,                         // sub_json
        S_map2 = 74,                             // map2
        S_75_10 = 75,                            // $@10
        S_map_value = 76,                        // map_value
        S_map_content = 77,                      // map_content
        S_not_empty_map = 78,                    // not_empty_map
        S_list_generic = 79,                     // list_generic
        S_80_11 = 80,                            // $@11
        S_list_content = 81,                     // list_content
        S_not_empty_list = 82,                   // not_empty_list
        S_unknown_map_entry = 83,                // unknown_map_entry
        S_syntax_map = 84,                       // syntax_map
        S_85_12 = 85,                            // $@12
        S_global_objects = 86,                   // global_objects
        S_global_object = 87,                    // global_object
        S_dhcpddns_object = 88,                  // dhcpddns_object
        S_89_13 = 89,                            // $@13
        S_sub_dhcpddns = 90,                     // sub_dhcpddns
        S_91_14 = 91,                            // $@14
        S_dhcpddns_params = 92,                  // dhcpddns_params
        S_dhcpddns_param = 93,                   // dhcpddns_param
        S_ip_address = 94,                       // ip_address
        S_95_15 = 95,                            // $@15
        S_port = 96,                             // port
        S_dns_server_timeout = 97,               // dns_server_timeout
        S_ncr_protocol = 98,                     // ncr_protocol
        S_99_16 = 99,                            // $@16
        S_ncr_protocol_value = 100,              // ncr_protocol_value
        S_ncr_format = 101,                      // ncr_format
        S_102_17 = 102,                          // $@17
        S_user_context = 103,                    // user_context
        S_104_18 = 104,                          // $@18
        S_comment = 105,                         // comment
        S_106_19 = 106,                          // $@19
        S_forward_ddns = 107,                    // forward_ddns
        S_108_20 = 108,                          // $@20
        S_reverse_ddns = 109,                    // reverse_ddns
        S_110_21 = 110,                          // $@21
        S_ddns_mgr_params = 111,                 // ddns_mgr_params
        S_not_empty_ddns_mgr_params = 112,       // not_empty_ddns_mgr_params
        S_ddns_mgr_param = 113,                  // ddns_mgr_param
        S_ddns_domains = 114,                    // ddns_domains
        S_115_22 = 115,                          // $@22
        S_sub_ddns_domains = 116,                // sub_ddns_domains
        S_117_23 = 117,                          // $@23
        S_ddns_domain_list = 118,                // ddns_domain_list
        S_not_empty_ddns_domain_list = 119,      // not_empty_ddns_domain_list
        S_ddns_domain = 120,                     // ddns_domain
        S_121_24 = 121,                          // $@24
        S_sub_ddns_domain = 122,                 // sub_ddns_domain
        S_123_25 = 123,                          // $@25
        S_ddns_domain_params = 124,              // ddns_domain_params
        S_ddns_domain_param = 125,               // ddns_domain_param
        S_ddns_domain_name = 126,                // ddns_domain_name
        S_127_26 = 127,                          // $@26
        S_ddns_domain_key_name = 128,            // ddns_domain_key_name
        S_129_27 = 129,                          // $@27
        S_dns_servers = 130,                     // dns_servers
        S_131_28 = 131,                          // $@28
        S_sub_dns_servers = 132,                 // sub_dns_servers
        S_133_29 = 133,                          // $@29
        S_dns_server_list = 134,                 // dns_server_list
        S_dns_server = 135,                      // dns_server
        S_136_30 = 136,                          // $@30
        S_sub_dns_server = 137,                  // sub_dns_server
        S_138_31 = 138,                          // $@31
        S_dns_server_params = 139,               // dns_server_params
        S_dns_server_param = 140,                // dns_server_param
        S_dns_server_hostname = 141,             // dns_server_hostname
        S_142_32 = 142,                          // $@32
        S_dns_server_ip_address = 143,           // dns_server_ip_address
        S_144_33 = 144,                          // $@33
        S_dns_server_port = 145,                 // dns_server_port
        S_tsig_keys = 146,                       // tsig_keys
        S_147_34 = 147,                          // $@34
        S_sub_tsig_keys = 148,                   // sub_tsig_keys
        S_149_35 = 149,                          // $@35
        S_tsig_keys_list = 150,                  // tsig_keys_list
        S_not_empty_tsig_keys_list = 151,        // not_empty_tsig_keys_list
        S_tsig_key = 152,                        // tsig_key
        S_153_36 = 153,                          // $@36
        S_sub_tsig_key = 154,                    // sub_tsig_key
        S_155_37 = 155,                          // $@37
        S_tsig_key_params = 156,                 // tsig_key_params
        S_tsig_key_param = 157,                  // tsig_key_param
        S_tsig_key_name = 158,                   // tsig_key_name
        S_159_38 = 159,                          // $@38
        S_tsig_key_algorithm = 160,              // tsig_key_algorithm
        S_161_39 = 161,                          // $@39
        S_tsig_key_digest_bits = 162,            // tsig_key_digest_bits
        S_tsig_key_secret = 163,                 // tsig_key_secret
        S_164_40 = 164,                          // $@40
        S_control_socket = 165,                  // control_socket
        S_166_41 = 166,                          // $@41
        S_control_socket_params = 167,           // control_socket_params
        S_control_socket_param = 168,            // control_socket_param
        S_control_socket_type = 169,             // control_socket_type
        S_170_42 = 170,                          // $@42
        S_control_socket_name = 171,             // control_socket_name
        S_172_43 = 172,                          // $@43
        S_dhcp6_json_object = 173,               // dhcp6_json_object
        S_174_44 = 174,                          // $@44
        S_dhcp4_json_object = 175,               // dhcp4_json_object
        S_176_45 = 176,                          // $@45
        S_control_agent_json_object = 177,       // control_agent_json_object
        S_178_46 = 178,                          // $@46
        S_logging_object = 179,                  // logging_object
        S_180_47 = 180,                          // $@47
        S_logging_params = 181,                  // logging_params
        S_logging_param = 182,                   // logging_param
        S_loggers = 183,                         // loggers
        S_184_48 = 184,                          // $@48
        S_loggers_entries = 185,                 // loggers_entries
        S_logger_entry = 186,                    // logger_entry
        S_187_49 = 187,                          // $@49
        S_logger_params = 188,                   // logger_params
        S_logger_param = 189,                    // logger_param
        S_name = 190,                            // name
        S_191_50 = 191,                          // $@50
        S_debuglevel = 192,                      // debuglevel
        S_severity = 193,                        // severity
        S_194_51 = 194,                          // $@51
        S_output_options_list = 195,             // output_options_list
        S_196_52 = 196,                          // $@52
        S_output_options_list_content = 197,     // output_options_list_content
        S_output_entry = 198,                    // output_entry
        S_199_53 = 199,                          // $@53
        S_output_params_list = 200,              // output_params_list
        S_output_params = 201,                   // output_params
        S_output = 202,                          // output
        S_203_54 = 203,                          // $@54
        S_flush = 204,                           // flush
        S_maxsize = 205,                         // maxsize
        S_maxver = 206,                          // maxver
        S_pattern = 207,                         // pattern
        S_208_55 = 208                           // $@55
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case 72: // value
      case 76: // map_value
      case 100: // ncr_protocol_value
        value.move< ElementPtr > (std::move (that.value));
        break;

      case 60: // "boolean"
        value.move< bool > (std::move (that.value));
        break;

      case 59: // "floating point"
        value.move< double > (std::move (that.value));
        break;

      case 58: // "integer"
        value.move< int64_t > (std::move (that.value));
        break;

      case 57: // "constant string"
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ElementPtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ElementPtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, double&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const double& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int64_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int64_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case 72: // value
      case 76: // map_value
      case 100: // ncr_protocol_value
        value.template destroy< ElementPtr > ();
        break;

      case 60: // "boolean"
        value.template destroy< bool > ();
        break;

      case 59: // "floating point"
        value.template destroy< double > ();
        break;

      case 58: // "integer"
        value.template destroy< int64_t > ();
        break;

      case 57: // "constant string"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return D2Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_END || tok == token::TOKEN_D2_PARSER_error || tok == token::TOKEN_D2_PARSER_UNDEF || tok == token::TOKEN_COMMA || tok == token::TOKEN_COLON || tok == token::TOKEN_LSQUARE_BRACKET || tok == token::TOKEN_RSQUARE_BRACKET || tok == token::TOKEN_LCURLY_BRACKET || tok == token::TOKEN_RCURLY_BRACKET || tok == token::TOKEN_NULL_TYPE || tok == token::TOKEN_DHCP6 || tok == token::TOKEN_DHCP4 || tok == token::TOKEN_CONTROL_AGENT || tok == token::TOKEN_DHCPDDNS || tok == token::TOKEN_IP_ADDRESS || tok == token::TOKEN_PORT || tok == token::TOKEN_DNS_SERVER_TIMEOUT || tok == token::TOKEN_NCR_PROTOCOL || tok == token::TOKEN_UDP || tok == token::TOKEN_TCP || tok == token::TOKEN_NCR_FORMAT || tok == token::TOKEN_JSON || tok == token::TOKEN_USER_CONTEXT || tok == token::TOKEN_COMMENT || tok == token::TOKEN_FORWARD_DDNS || tok == token::TOKEN_REVERSE_DDNS || tok == token::TOKEN_DDNS_DOMAINS || tok == token::TOKEN_KEY_NAME || tok == token::TOKEN_DNS_SERVERS || tok == token::TOKEN_HOSTNAME || tok == token::TOKEN_TSIG_KEYS || tok == token::TOKEN_ALGORITHM || tok == token::TOKEN_DIGEST_BITS || tok == token::TOKEN_SECRET || tok == token::TOKEN_CONTROL_SOCKET || tok == token::TOKEN_SOCKET_TYPE || tok == token::TOKEN_SOCKET_NAME || tok == token::TOKEN_LOGGING || tok == token::TOKEN_LOGGERS || tok == token::TOKEN_NAME || tok == token::TOKEN_OUTPUT_OPTIONS || tok == token::TOKEN_OUTPUT || tok == token::TOKEN_DEBUGLEVEL || tok == token::TOKEN_SEVERITY || tok == token::TOKEN_FLUSH || tok == token::TOKEN_MAXSIZE || tok == token::TOKEN_MAXVER || tok == token::TOKEN_PATTERN || tok == token::TOKEN_TOPLEVEL_JSON || tok == token::TOKEN_TOPLEVEL_DHCPDDNS || tok == token::TOKEN_SUB_DHCPDDNS || tok == token::TOKEN_SUB_TSIG_KEY || tok == token::TOKEN_SUB_TSIG_KEYS || tok == token::TOKEN_SUB_DDNS_DOMAIN || tok == token::TOKEN_SUB_DDNS_DOMAINS || tok == token::TOKEN_SUB_DNS_SERVER || tok == token::TOKEN_SUB_DNS_SERVERS);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::TOKEN_END || tok == token::TOKEN_D2_PARSER_error || tok == token::TOKEN_D2_PARSER_UNDEF || tok == token::TOKEN_COMMA || tok == token::TOKEN_COLON || tok == token::TOKEN_LSQUARE_BRACKET || tok == token::TOKEN_RSQUARE_BRACKET || tok == token::TOKEN_LCURLY_BRACKET || tok == token::TOKEN_RCURLY_BRACKET || tok == token::TOKEN_NULL_TYPE || tok == token::TOKEN_DHCP6 || tok == token::TOKEN_DHCP4 || tok == token::TOKEN_CONTROL_AGENT || tok == token::TOKEN_DHCPDDNS || tok == token::TOKEN_IP_ADDRESS || tok == token::TOKEN_PORT || tok == token::TOKEN_DNS_SERVER_TIMEOUT || tok == token::TOKEN_NCR_PROTOCOL || tok == token::TOKEN_UDP || tok == token::TOKEN_TCP || tok == token::TOKEN_NCR_FORMAT || tok == token::TOKEN_JSON || tok == token::TOKEN_USER_CONTEXT || tok == token::TOKEN_COMMENT || tok == token::TOKEN_FORWARD_DDNS || tok == token::TOKEN_REVERSE_DDNS || tok == token::TOKEN_DDNS_DOMAINS || tok == token::TOKEN_KEY_NAME || tok == token::TOKEN_DNS_SERVERS || tok == token::TOKEN_HOSTNAME || tok == token::TOKEN_TSIG_KEYS || tok == token::TOKEN_ALGORITHM || tok == token::TOKEN_DIGEST_BITS || tok == token::TOKEN_SECRET || tok == token::TOKEN_CONTROL_SOCKET || tok == token::TOKEN_SOCKET_TYPE || tok == token::TOKEN_SOCKET_NAME || tok == token::TOKEN_LOGGING || tok == token::TOKEN_LOGGERS || tok == token::TOKEN_NAME || tok == token::TOKEN_OUTPUT_OPTIONS || tok == token::TOKEN_OUTPUT || tok == token::TOKEN_DEBUGLEVEL || tok == token::TOKEN_SEVERITY || tok == token::TOKEN_FLUSH || tok == token::TOKEN_MAXSIZE || tok == token::TOKEN_MAXVER || tok == token::TOKEN_PATTERN || tok == token::TOKEN_TOPLEVEL_JSON || tok == token::TOKEN_TOPLEVEL_DHCPDDNS || tok == token::TOKEN_SUB_DHCPDDNS || tok == token::TOKEN_SUB_TSIG_KEY || tok == token::TOKEN_SUB_TSIG_KEYS || tok == token::TOKEN_SUB_DDNS_DOMAIN || tok == token::TOKEN_SUB_DDNS_DOMAINS || tok == token::TOKEN_SUB_DNS_SERVER || tok == token::TOKEN_SUB_DNS_SERVERS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_BOOLEAN);
      }
#else
      symbol_type (int tok, const bool& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOKEN_BOOLEAN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, double v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_FLOAT);
      }
#else
      symbol_type (int tok, const double& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOKEN_FLOAT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int64_t v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_INTEGER);
      }
#else
      symbol_type (int tok, const int64_t& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOKEN_INTEGER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_STRING);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOKEN_STRING);
      }
#endif
    };

    /// Build a parser object.
    D2Parser (isc::d2::D2ParserContext& ctx_yyarg);
    virtual ~D2Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    D2Parser (const D2Parser&) = delete;
    /// Non copyable.
    D2Parser& operator= (const D2Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if D2_PARSER_DEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::TOKEN_END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::TOKEN_END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_D2_PARSER_error (location_type l)
      {
        return symbol_type (token::TOKEN_D2_PARSER_error, std::move (l));
      }
#else
      static
      symbol_type
      make_D2_PARSER_error (const location_type& l)
      {
        return symbol_type (token::TOKEN_D2_PARSER_error, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_D2_PARSER_UNDEF (location_type l)
      {
        return symbol_type (token::TOKEN_D2_PARSER_UNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_D2_PARSER_UNDEF (const location_type& l)
      {
        return symbol_type (token::TOKEN_D2_PARSER_UNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::TOKEN_COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::TOKEN_COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::TOKEN_COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::TOKEN_COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSQUARE_BRACKET (location_type l)
      {
        return symbol_type (token::TOKEN_LSQUARE_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_LSQUARE_BRACKET (const location_type& l)
      {
        return symbol_type (token::TOKEN_LSQUARE_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSQUARE_BRACKET (location_type l)
      {
        return symbol_type (token::TOKEN_RSQUARE_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_RSQUARE_BRACKET (const location_type& l)
      {
        return symbol_type (token::TOKEN_RSQUARE_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LCURLY_BRACKET (location_type l)
      {
        return symbol_type (token::TOKEN_LCURLY_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_LCURLY_BRACKET (const location_type& l)
      {
        return symbol_type (token::TOKEN_LCURLY_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RCURLY_BRACKET (location_type l)
      {
        return symbol_type (token::TOKEN_RCURLY_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_RCURLY_BRACKET (const location_type& l)
      {
        return symbol_type (token::TOKEN_RCURLY_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NULL_TYPE (location_type l)
      {
        return symbol_type (token::TOKEN_NULL_TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_NULL_TYPE (const location_type& l)
      {
        return symbol_type (token::TOKEN_NULL_TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DHCP6 (location_type l)
      {
        return symbol_type (token::TOKEN_DHCP6, std::move (l));
      }
#else
      static
      symbol_type
      make_DHCP6 (const location_type& l)
      {
        return symbol_type (token::TOKEN_DHCP6, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DHCP4 (location_type l)
      {
        return symbol_type (token::TOKEN_DHCP4, std::move (l));
      }
#else
      static
      symbol_type
      make_DHCP4 (const location_type& l)
      {
        return symbol_type (token::TOKEN_DHCP4, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTROL_AGENT (location_type l)
      {
        return symbol_type (token::TOKEN_CONTROL_AGENT, std::move (l));
      }
#else
      static
      symbol_type
      make_CONTROL_AGENT (const location_type& l)
      {
        return symbol_type (token::TOKEN_CONTROL_AGENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DHCPDDNS (location_type l)
      {
        return symbol_type (token::TOKEN_DHCPDDNS, std::move (l));
      }
#else
      static
      symbol_type
      make_DHCPDDNS (const location_type& l)
      {
        return symbol_type (token::TOKEN_DHCPDDNS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IP_ADDRESS (location_type l)
      {
        return symbol_type (token::TOKEN_IP_ADDRESS, std::move (l));
      }
#else
      static
      symbol_type
      make_IP_ADDRESS (const location_type& l)
      {
        return symbol_type (token::TOKEN_IP_ADDRESS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PORT (location_type l)
      {
        return symbol_type (token::TOKEN_PORT, std::move (l));
      }
#else
      static
      symbol_type
      make_PORT (const location_type& l)
      {
        return symbol_type (token::TOKEN_PORT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DNS_SERVER_TIMEOUT (location_type l)
      {
        return symbol_type (token::TOKEN_DNS_SERVER_TIMEOUT, std::move (l));
      }
#else
      static
      symbol_type
      make_DNS_SERVER_TIMEOUT (const location_type& l)
      {
        return symbol_type (token::TOKEN_DNS_SERVER_TIMEOUT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NCR_PROTOCOL (location_type l)
      {
        return symbol_type (token::TOKEN_NCR_PROTOCOL, std::move (l));
      }
#else
      static
      symbol_type
      make_NCR_PROTOCOL (const location_type& l)
      {
        return symbol_type (token::TOKEN_NCR_PROTOCOL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UDP (location_type l)
      {
        return symbol_type (token::TOKEN_UDP, std::move (l));
      }
#else
      static
      symbol_type
      make_UDP (const location_type& l)
      {
        return symbol_type (token::TOKEN_UDP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCP (location_type l)
      {
        return symbol_type (token::TOKEN_TCP, std::move (l));
      }
#else
      static
      symbol_type
      make_TCP (const location_type& l)
      {
        return symbol_type (token::TOKEN_TCP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NCR_FORMAT (location_type l)
      {
        return symbol_type (token::TOKEN_NCR_FORMAT, std::move (l));
      }
#else
      static
      symbol_type
      make_NCR_FORMAT (const location_type& l)
      {
        return symbol_type (token::TOKEN_NCR_FORMAT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_JSON (location_type l)
      {
        return symbol_type (token::TOKEN_JSON, std::move (l));
      }
#else
      static
      symbol_type
      make_JSON (const location_type& l)
      {
        return symbol_type (token::TOKEN_JSON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USER_CONTEXT (location_type l)
      {
        return symbol_type (token::TOKEN_USER_CONTEXT, std::move (l));
      }
#else
      static
      symbol_type
      make_USER_CONTEXT (const location_type& l)
      {
        return symbol_type (token::TOKEN_USER_CONTEXT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMENT (location_type l)
      {
        return symbol_type (token::TOKEN_COMMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMENT (const location_type& l)
      {
        return symbol_type (token::TOKEN_COMMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FORWARD_DDNS (location_type l)
      {
        return symbol_type (token::TOKEN_FORWARD_DDNS, std::move (l));
      }
#else
      static
      symbol_type
      make_FORWARD_DDNS (const location_type& l)
      {
        return symbol_type (token::TOKEN_FORWARD_DDNS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REVERSE_DDNS (location_type l)
      {
        return symbol_type (token::TOKEN_REVERSE_DDNS, std::move (l));
      }
#else
      static
      symbol_type
      make_REVERSE_DDNS (const location_type& l)
      {
        return symbol_type (token::TOKEN_REVERSE_DDNS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DDNS_DOMAINS (location_type l)
      {
        return symbol_type (token::TOKEN_DDNS_DOMAINS, std::move (l));
      }
#else
      static
      symbol_type
      make_DDNS_DOMAINS (const location_type& l)
      {
        return symbol_type (token::TOKEN_DDNS_DOMAINS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KEY_NAME (location_type l)
      {
        return symbol_type (token::TOKEN_KEY_NAME, std::move (l));
      }
#else
      static
      symbol_type
      make_KEY_NAME (const location_type& l)
      {
        return symbol_type (token::TOKEN_KEY_NAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DNS_SERVERS (location_type l)
      {
        return symbol_type (token::TOKEN_DNS_SERVERS, std::move (l));
      }
#else
      static
      symbol_type
      make_DNS_SERVERS (const location_type& l)
      {
        return symbol_type (token::TOKEN_DNS_SERVERS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HOSTNAME (location_type l)
      {
        return symbol_type (token::TOKEN_HOSTNAME, std::move (l));
      }
#else
      static
      symbol_type
      make_HOSTNAME (const location_type& l)
      {
        return symbol_type (token::TOKEN_HOSTNAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TSIG_KEYS (location_type l)
      {
        return symbol_type (token::TOKEN_TSIG_KEYS, std::move (l));
      }
#else
      static
      symbol_type
      make_TSIG_KEYS (const location_type& l)
      {
        return symbol_type (token::TOKEN_TSIG_KEYS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALGORITHM (location_type l)
      {
        return symbol_type (token::TOKEN_ALGORITHM, std::move (l));
      }
#else
      static
      symbol_type
      make_ALGORITHM (const location_type& l)
      {
        return symbol_type (token::TOKEN_ALGORITHM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIGEST_BITS (location_type l)
      {
        return symbol_type (token::TOKEN_DIGEST_BITS, std::move (l));
      }
#else
      static
      symbol_type
      make_DIGEST_BITS (const location_type& l)
      {
        return symbol_type (token::TOKEN_DIGEST_BITS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SECRET (location_type l)
      {
        return symbol_type (token::TOKEN_SECRET, std::move (l));
      }
#else
      static
      symbol_type
      make_SECRET (const location_type& l)
      {
        return symbol_type (token::TOKEN_SECRET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTROL_SOCKET (location_type l)
      {
        return symbol_type (token::TOKEN_CONTROL_SOCKET, std::move (l));
      }
#else
      static
      symbol_type
      make_CONTROL_SOCKET (const location_type& l)
      {
        return symbol_type (token::TOKEN_CONTROL_SOCKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SOCKET_TYPE (location_type l)
      {
        return symbol_type (token::TOKEN_SOCKET_TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_SOCKET_TYPE (const location_type& l)
      {
        return symbol_type (token::TOKEN_SOCKET_TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SOCKET_NAME (location_type l)
      {
        return symbol_type (token::TOKEN_SOCKET_NAME, std::move (l));
      }
#else
      static
      symbol_type
      make_SOCKET_NAME (const location_type& l)
      {
        return symbol_type (token::TOKEN_SOCKET_NAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGGING (location_type l)
      {
        return symbol_type (token::TOKEN_LOGGING, std::move (l));
      }
#else
      static
      symbol_type
      make_LOGGING (const location_type& l)
      {
        return symbol_type (token::TOKEN_LOGGING, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGGERS (location_type l)
      {
        return symbol_type (token::TOKEN_LOGGERS, std::move (l));
      }
#else
      static
      symbol_type
      make_LOGGERS (const location_type& l)
      {
        return symbol_type (token::TOKEN_LOGGERS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAME (location_type l)
      {
        return symbol_type (token::TOKEN_NAME, std::move (l));
      }
#else
      static
      symbol_type
      make_NAME (const location_type& l)
      {
        return symbol_type (token::TOKEN_NAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUTPUT_OPTIONS (location_type l)
      {
        return symbol_type (token::TOKEN_OUTPUT_OPTIONS, std::move (l));
      }
#else
      static
      symbol_type
      make_OUTPUT_OPTIONS (const location_type& l)
      {
        return symbol_type (token::TOKEN_OUTPUT_OPTIONS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUTPUT (location_type l)
      {
        return symbol_type (token::TOKEN_OUTPUT, std::move (l));
      }
#else
      static
      symbol_type
      make_OUTPUT (const location_type& l)
      {
        return symbol_type (token::TOKEN_OUTPUT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEBUGLEVEL (location_type l)
      {
        return symbol_type (token::TOKEN_DEBUGLEVEL, std::move (l));
      }
#else
      static
      symbol_type
      make_DEBUGLEVEL (const location_type& l)
      {
        return symbol_type (token::TOKEN_DEBUGLEVEL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEVERITY (location_type l)
      {
        return symbol_type (token::TOKEN_SEVERITY, std::move (l));
      }
#else
      static
      symbol_type
      make_SEVERITY (const location_type& l)
      {
        return symbol_type (token::TOKEN_SEVERITY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLUSH (location_type l)
      {
        return symbol_type (token::TOKEN_FLUSH, std::move (l));
      }
#else
      static
      symbol_type
      make_FLUSH (const location_type& l)
      {
        return symbol_type (token::TOKEN_FLUSH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAXSIZE (location_type l)
      {
        return symbol_type (token::TOKEN_MAXSIZE, std::move (l));
      }
#else
      static
      symbol_type
      make_MAXSIZE (const location_type& l)
      {
        return symbol_type (token::TOKEN_MAXSIZE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAXVER (location_type l)
      {
        return symbol_type (token::TOKEN_MAXVER, std::move (l));
      }
#else
      static
      symbol_type
      make_MAXVER (const location_type& l)
      {
        return symbol_type (token::TOKEN_MAXVER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PATTERN (location_type l)
      {
        return symbol_type (token::TOKEN_PATTERN, std::move (l));
      }
#else
      static
      symbol_type
      make_PATTERN (const location_type& l)
      {
        return symbol_type (token::TOKEN_PATTERN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOPLEVEL_JSON (location_type l)
      {
        return symbol_type (token::TOKEN_TOPLEVEL_JSON, std::move (l));
      }
#else
      static
      symbol_type
      make_TOPLEVEL_JSON (const location_type& l)
      {
        return symbol_type (token::TOKEN_TOPLEVEL_JSON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOPLEVEL_DHCPDDNS (location_type l)
      {
        return symbol_type (token::TOKEN_TOPLEVEL_DHCPDDNS, std::move (l));
      }
#else
      static
      symbol_type
      make_TOPLEVEL_DHCPDDNS (const location_type& l)
      {
        return symbol_type (token::TOKEN_TOPLEVEL_DHCPDDNS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_DHCPDDNS (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_DHCPDDNS, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_DHCPDDNS (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_DHCPDDNS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_TSIG_KEY (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_TSIG_KEY, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_TSIG_KEY (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_TSIG_KEY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_TSIG_KEYS (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_TSIG_KEYS, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_TSIG_KEYS (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_TSIG_KEYS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_DDNS_DOMAIN (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_DDNS_DOMAIN, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_DDNS_DOMAIN (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_DDNS_DOMAIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_DDNS_DOMAINS (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_DDNS_DOMAINS, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_DDNS_DOMAINS (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_DDNS_DOMAINS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_DNS_SERVER (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_DNS_SERVER, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_DNS_SERVER (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_DNS_SERVER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_DNS_SERVERS (location_type l)
      {
        return symbol_type (token::TOKEN_SUB_DNS_SERVERS, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_DNS_SERVERS (const location_type& l)
      {
        return symbol_type (token::TOKEN_SUB_DNS_SERVERS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER (int64_t v, location_type l)
      {
        return symbol_type (token::TOKEN_INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER (const int64_t& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (double v, location_type l)
      {
        return symbol_type (token::TOKEN_FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const double& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEAN (bool v, location_type l)
      {
        return symbol_type (token::TOKEN_BOOLEAN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOLEAN (const bool& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_BOOLEAN, v, l);
      }
#endif


    class context
    {
    public:
      context (const D2Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const { return yyla_; }
      symbol_kind_type token () const { return yyla_.kind (); }
      const location_type& location () const { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const D2Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    D2Parser (const D2Parser&);
    /// Non copyable.
    D2Parser& operator= (const D2Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const unsigned char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if D2_PARSER_DEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 304,     ///< Last index in yytable_.
      yynnts_ = 148,  ///< Number of nonterminal symbols.
      yyfinal_ = 20 ///< Termination state number.
    };


    // User arguments.
    isc::d2::D2ParserContext& ctx;

  };

  inline
  D2Parser::symbol_kind_type
  D2Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
    };
    const int user_token_number_max_ = 315;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= user_token_number_max_)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  D2Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case 72: // value
      case 76: // map_value
      case 100: // ncr_protocol_value
        value.copy< ElementPtr > (YY_MOVE (that.value));
        break;

      case 60: // "boolean"
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case 59: // "floating point"
        value.copy< double > (YY_MOVE (that.value));
        break;

      case 58: // "integer"
        value.copy< int64_t > (YY_MOVE (that.value));
        break;

      case 57: // "constant string"
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  D2Parser::symbol_kind_type
  D2Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  D2Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  D2Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case 72: // value
      case 76: // map_value
      case 100: // ncr_protocol_value
        value.move< ElementPtr > (YY_MOVE (s.value));
        break;

      case 60: // "boolean"
        value.move< bool > (YY_MOVE (s.value));
        break;

      case 59: // "floating point"
        value.move< double > (YY_MOVE (s.value));
        break;

      case 58: // "integer"
        value.move< int64_t > (YY_MOVE (s.value));
        break;

      case 57: // "constant string"
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  D2Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  D2Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  D2Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  D2Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  D2Parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  D2Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  D2Parser::symbol_kind_type
  D2Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
  D2Parser::symbol_kind_type
  D2Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

#line 14 "d2_parser.yy"
} } // isc::d2
#line 2613 "d2_parser.h"





#endif // !YY_D2_PARSER_D2_PARSER_H_INCLUDED
