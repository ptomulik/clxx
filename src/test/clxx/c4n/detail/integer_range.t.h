// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/detail/integer_range.t.h

/** // doc: clxx/c4n/detail/integer_range.t.h {{{
 * \file clxx/c4n/detail/integer_range.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_C4N_DETAIL_INTEGER_RANGE_T_H_INCLUDED
#define CLXX_C4N_DETAIL_INTEGER_RANGE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/c4n/detail/integer_range.hpp>

namespace clxx { namespace detail { class integer_range_test_suite; } }

/** // doc: class clxx::detail::integer_range_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::detail::integer_range_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__1( )
  {
    static_assert(integer_range<unsigned>().low() == 0u, "");
    static_assert(integer_range<unsigned>().high() == 0u, "");
    static_assert(integer_range<unsigned>().step() == 1, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>().low(), 0u);
    TS_ASSERT_EQUALS(integer_range<unsigned>().high(), 0u);
    TS_ASSERT_EQUALS(integer_range<unsigned>().step(), 1);
  }
  /** // doc: test__unsigned__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__2( )
  {
    static_assert(integer_range<unsigned>(2u,5u).low() == 2u, "");
    static_assert(integer_range<unsigned>(2u,5u).high() == 5u, "");
    static_assert(integer_range<unsigned>(2u,5u).step() == 1, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).low(), 2u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).high(), 5u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).step(), 1);
  }
  /** // doc: test__unsigned__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__3( )
  {
    static_assert(integer_range<unsigned>(5u,2u).low() == 2u, "");
    static_assert(integer_range<unsigned>(5u,2u).high() == 5u, "");
    static_assert(integer_range<unsigned>(5u,2u).step() == -1, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).low(), 2u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).high(), 5u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).step(), -1);
  }
  /** // doc: test__unsigned__begin__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__begin__1( )
  {
    static_assert(integer_range<unsigned>(2u,5u).begin().value() == 2u, "");
    static_assert(integer_range<unsigned>(2u,5u).begin().step() == 1, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).begin().value(), 2u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).begin().step(), 1);
  }
  /** // doc: test__unsigned__begin__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__begin__2( )
  {
    static_assert(integer_range<unsigned>(5u,2u).begin().value() == 5u, "");
    static_assert(integer_range<unsigned>(5u,2u).begin().step() == -1, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).begin().value(), 5u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).begin().step(), -1);
  }
  /** // doc: test__unsigned__begin__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__begin__3( )
  {
    static_assert(integer_range<unsigned>(5u,2u,-2).begin().value() == 5u, "");
    static_assert(integer_range<unsigned>(5u,2u,-2).begin().step() == -2, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u,-2).begin().value(), 5u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u,-2).begin().step(), -2);
  }
  /** // doc: test__unsigned__begin__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__iterator__1( )
  {
    static_assert(integer_range<unsigned>::iterator(2u, 3).value() == 2u, "");
    static_assert(integer_range<unsigned>::iterator(2u, 3).step() == 3, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>::iterator(2u, 3).value(), 2u);
    TS_ASSERT_EQUALS(integer_range<unsigned>::iterator(2u, 3).step(), 3);
  }
  /** // doc: test__unsigned__begin__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__iterator_plus__1( )
  {
    static_assert((integer_range<unsigned>::iterator(2u, 3) + 2).value() == 8u, "");
    static_assert((integer_range<unsigned>::iterator(2u, 3) + 2).step() == 3, "");

    TS_ASSERT_EQUALS((integer_range<unsigned>::iterator(2u, 3) + 2).value(), 8u);
    TS_ASSERT_EQUALS((integer_range<unsigned>::iterator(2u, 3) + 2).step(), 3);
  }
  /** // doc: test__unsigned__begin__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__iterator_plus__2( )
  {
    static_assert((2 + integer_range<unsigned>::iterator(2u, 3)).value() == 8u, "");
    static_assert((2 + integer_range<unsigned>::iterator(2u, 3)).step() == 3, "");

    TS_ASSERT_EQUALS((2 + integer_range<unsigned>::iterator(2u, 3)).value(), 8u);
    TS_ASSERT_EQUALS((2 + integer_range<unsigned>::iterator(2u, 3)).step(), 3);
  }
  /** // doc: test__unsigned__begin__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__iterator_minus__1( )
  {
    static_assert((integer_range<unsigned>::iterator(8u, 3) - 2).value() == 2u, "");
    static_assert((integer_range<unsigned>::iterator(8u, 3) - 2).step() == 3, "");

    TS_ASSERT_EQUALS((integer_range<unsigned>::iterator(8u, 3) - 2).value(), 2u);
    TS_ASSERT_EQUALS((integer_range<unsigned>::iterator(8u, 3) - 2).step(), 3);
  }
  /** // doc: test__unsigned__begin__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__unsigned__iterator__deref__1( )
  {
    static_assert(*(integer_range<unsigned>::iterator(2u, 3)) == 2u, "");
    static_assert(*(integer_range<unsigned>::iterator(5u, 3)) == 5u, "");

    TS_ASSERT_EQUALS(*(integer_range<unsigned>::iterator(2u, 3)), 2u);
    TS_ASSERT_EQUALS(*(integer_range<unsigned>::iterator(5u, 3)), 5u);
  }
};

#endif /* CLXX_C4N_DETAIL_INTEGER_RANGE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
