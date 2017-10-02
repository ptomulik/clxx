// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/detail/enum_range.t.h

/** // doc: clxx/c4n/detail/enum_range.t.h {{{
 * \file clxx/c4n/detail/enum_range.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_C4N_DETAIL_ENUM_RANGE_T_H_INCLUDED
#define CLXX_C4N_DETAIL_ENUM_RANGE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/c4n/detail/enum_range.hpp>

enum class unumber_t : unsigned int {
  zero    =  0,
  one     =  1,
  two     =  2,
  three   =  3
};

enum class snumber_t : signed int {
  minus_three   = -3,
  minus_two     = -2,
  minus_one     = -1,
  zero          =  0,
  one           =  1,
  two           =  2,
  three         =  3
};

typedef clxx::detail::enum_range<unumber_t> unumber_range;
typedef clxx::detail::enum_range<snumber_t> snumber_range;

namespace clxx { namespace detail { class enum_range_test_suite; } }

/** // doc: class clxx::detail::enum_range_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::detail::enum_range_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__unsigned__ctor__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__ctor__1( )
  {
    unumber_range r;
    TS_ASSERT_EQUALS(r.begin(), 0);
    TS_ASSERT_EQUALS(r.end(), 0);
  }
  /** // doc: test__unsigned__ctor__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__ctor__2( )
  {
    unumber_range r{unumber_t::zero, unumber_t::three};
    TS_ASSERT_EQUALS(r.begin(), 0u);
    TS_ASSERT_EQUALS(r.end(), 3u);
  }
  /** // doc: test__unsigned__ctor__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__ctor__3( )
  {
    unumber_range r(unumber_t::zero, unumber_t::three);
    TS_ASSERT_EQUALS(r.begin(), 0u);
    TS_ASSERT_EQUALS(r.end(), 3u);
  }
  /** // doc: test__unsigned__ctor__4() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__ctor__4( )
  {
    unumber_range r{0u, 3u};
    TS_ASSERT_EQUALS(r.begin(), 0u);
    TS_ASSERT_EQUALS(r.end(), 3u);
  }
  /** // doc: test__unsigned__ctor__5() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__ctor__5( )
  {
    unumber_range r(0u, 3u);
    TS_ASSERT_EQUALS(r.begin(), 0u);
    TS_ASSERT_EQUALS(r.end(), 3u);
  }
  /** // doc: test__unsigned__begin__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__begin__1( )
  {
    unumber_range r(0u, 3u);
    TS_ASSERT_EQUALS(r.begin(), 0u);
  }
  /** // doc: test__unsigned__end__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__end__1( )
  {
    unumber_range r(0u, 3u);
    TS_ASSERT_EQUALS(r.end(), 3u);
  }
  /** // doc: test__unsigned__begin__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__begin__2( )
  {
    unumber_range r(3u, 0u);
    TS_ASSERT_EQUALS(r.begin(), 3u);
  }
  /** // doc: test__unsigned__end__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__end__2( )
  {
    unumber_range r(3u, 0u);
    TS_ASSERT_EQUALS(r.end(), 0u);
  }
  /** // doc: test__unsigned__low__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__low__2( )
  {
    unumber_range r(3u, 0u);
    TS_ASSERT_EQUALS(r.low(), 0u);
  }
  /** // doc: test__unsigned__high__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__high__2( )
  {
    unumber_range r(3u, 0u);
    TS_ASSERT_EQUALS(r.high(), 3u);
  }
  /** // doc: test__unsigned__size__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__size__1( )
  {
    unumber_range r(1u, 4u);
    TS_ASSERT_EQUALS(r.size(), 3u);
  }
  /** // doc: test__unsigned__size__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__size__2( )
  {
    unumber_range r(4u, 1u);
    TS_ASSERT_EQUALS(r.size(), 3u);
  }
  /** // doc: test__unsigned__includes__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__includes__1( )
  {
    unumber_range r(2u, 4u);
    TS_ASSERT_EQUALS(r.includes(0u), false);
    TS_ASSERT_EQUALS(r.includes(1u), false);
    TS_ASSERT_EQUALS(r.includes(2u), true);
    TS_ASSERT_EQUALS(r.includes(3u), true);
    TS_ASSERT_EQUALS(r.includes(4u), false);
    TS_ASSERT_EQUALS(r.includes(5u), false);
  }
  /** // doc: test__unsigned__includes__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__includes__2( )
  {
    unumber_range r(4u, 2u);
    TS_ASSERT_EQUALS(r.includes(0u), false);
    TS_ASSERT_EQUALS(r.includes(1u), false);
    TS_ASSERT_EQUALS(r.includes(2u), true);
    TS_ASSERT_EQUALS(r.includes(3u), true);
    TS_ASSERT_EQUALS(r.includes(4u), false);
    TS_ASSERT_EQUALS(r.includes(5u), false);
  }
};

#endif /* CLXX_C4N_DETAIL_ENUM_RANGE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
