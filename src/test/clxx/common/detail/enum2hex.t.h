// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/detail/enum2hex.t.h

/** // doc: clxx/common/detail/enum2hex.t.h {{{
 * \file clxx/common/detail/enum2hex.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMON_DETAIL_ENUM2HEX_T_H_INCLUDED
#define CLXX_COMMON_DETAIL_ENUM2HEX_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/common/detail/enum2hex.hpp>
#include <climits>

namespace clxx { namespace detail { class enum2hex_test_suite; } }

/** // doc: class clxx::detail::enum2hex_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::detail::enum2hex_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_enum_char() {{{
   * \todo Write documentation
   */ // }}}
  void test_enum_char( )
  {
    enum class test_t : char { zero = 0x00, plus = 0x12, minus = -0x12 };
    TS_ASSERT_EQUALS(enum2hex(test_t::zero), "0x00");
    TS_ASSERT_EQUALS(enum2hex(test_t::plus), "0x12");
    TS_ASSERT_EQUALS(enum2hex(test_t::minus), "-0x12");
  }
  /** // doc: test_enum_unsigned_char() {{{
   * \todo Write documentation
   */ // }}}
  void test_enum_unsigned_char( )
  {
    enum class test_t : unsigned char { number = 0xff };
    TS_ASSERT_EQUALS(enum2hex(test_t::number), "0xff");
  }
  /** // doc: test_enum_short() {{{
   * \todo Write documentation
   */ // }}}
  void test_enum_short( )
  {
    enum class test_t : short { zero = 0x00, plus = 0x12, minus = -0x12 };
    TS_ASSERT_EQUALS(enum2hex(test_t::zero), "0x0000");
    TS_ASSERT_EQUALS(enum2hex(test_t::plus), "0x0012");
    TS_ASSERT_EQUALS(enum2hex(test_t::minus), "-0x0012");
  }
  /** // doc: test_enum_unsigned_short() {{{
   * \todo Write documentation
   */ // }}}
  void test_enum_unsigned_short( )
  {
    enum class test_t : unsigned short { number = 0xffff };
    TS_ASSERT_EQUALS(enum2hex(test_t::number), "0xffff");
  }
  /** // doc: test_enum_long() {{{
   * \todo Write documentation
   */ // }}}
  void test_enum_long( )
  {
    enum class test_t : long { zero = 0x00, plus = 0x12, minus = -0x12 };
    switch(sizeof(unsigned long))
      {
        case 4:
          TS_ASSERT_EQUALS(enum2hex(test_t::zero), "0x00000000");
          TS_ASSERT_EQUALS(enum2hex(test_t::plus), "0x00000012");
          TS_ASSERT_EQUALS(enum2hex(test_t::minus), "-0x00000012");
          break;
        case 8:
          TS_ASSERT_EQUALS(enum2hex(test_t::zero), "0x0000000000000000");
          TS_ASSERT_EQUALS(enum2hex(test_t::plus), "0x0000000000000012");
          TS_ASSERT_EQUALS(enum2hex(test_t::minus), "-0x0000000000000012");
          break;
        default:
          TS_FAIL("unsupported sizeof(unsigned long)");
          break;
      }
  }
  /** // doc: test_enum_unsigned_long() {{{
   * \todo Write documentation
   */ // }}}
  void test_enum_unsigned_long( )
  {
    enum class test_t : unsigned long { number = ULONG_MAX};
    switch(sizeof(unsigned long))
      {
        case 4:
          TS_ASSERT_EQUALS(enum2hex(test_t::number), "0xffffffff");
          break;
        case 8:
          TS_ASSERT_EQUALS(enum2hex(test_t::number), "0xffffffffffffffff");
          break;
        default:
          TS_FAIL("unsupported sizeof(unsigned long)");
          break;
      }
  }
};

#endif /* CLXX_COMMON_DETAIL_ENUM2HEX_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
