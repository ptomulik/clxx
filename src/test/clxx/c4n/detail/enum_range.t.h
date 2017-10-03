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
#include <type_traits>

enum class number_t : unsigned {
  zero    =  0,
  one     =  1,
  two     =  2,
  three   =  3,
  four    =  4,
  five    =  5,
  six     =  6
};

typedef clxx::detail::enum_range<number_t> number_range;

namespace clxx { namespace detail { class enum_range_test_suite; } }

/** // doc: class clxx::detail::enum_range_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::detail::enum_range_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__base_class__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__base_class__1( )
  {
    static_assert(::std::is_base_of<integer_range<unsigned>, enum_range<number_t> >::value, "");
  }
  /** // doc: test__ctor__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor__1( )
  {
    static_assert(number_range(number_t::three).start() == 0u, "");
    static_assert(number_range(number_t::three).stop() == 3u, "");
    static_assert(number_range(number_t::three).step() == 1, "");

    TS_ASSERT_EQUALS(number_range(number_t::three).start(), 0u);
    TS_ASSERT_EQUALS(number_range(number_t::three).stop(), 3u);
    TS_ASSERT_EQUALS(number_range(number_t::three).step(), 1);
  }
  /** // doc: test__ctor__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor__2( )
  {
    static_assert(number_range(number_t::one, number_t::three).start() == 1u, "");
    static_assert(number_range(number_t::one, number_t::three).stop() == 3u, "");
    static_assert(number_range(number_t::one, number_t::three).step() == 1, "");

    TS_ASSERT_EQUALS(number_range(number_t::one, number_t::three).start(), 1u);
    TS_ASSERT_EQUALS(number_range(number_t::one, number_t::three).stop(), 3u);
    TS_ASSERT_EQUALS(number_range(number_t::one, number_t::three).step(), 1);
  }
  /** // doc: test__ctor__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor__3( )
  {
    static_assert(number_range(number_t::one, number_t::three, 2).start() == 1u, "");
    static_assert(number_range(number_t::one, number_t::three, 2).stop() == 3u, "");
    static_assert(number_range(number_t::one, number_t::three, 2).step() == 2, "");

    TS_ASSERT_EQUALS(number_range(number_t::one, number_t::three, 2).start(), 1u);
    TS_ASSERT_EQUALS(number_range(number_t::one, number_t::three, 2).stop(), 3u);
    TS_ASSERT_EQUALS(number_range(number_t::one, number_t::three, 2).step(), 2);
  }
  /** // doc: test__ctor__4() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor__4( )
  {
    static_assert(number_range(number_t::three, number_t::zero).start() == 3u, "");
    static_assert(number_range(number_t::three, number_t::zero).stop() == 0u, "");
    static_assert(number_range(number_t::three, number_t::zero).step() == -1, "");

    TS_ASSERT_EQUALS(number_range(number_t::three, number_t::zero).start(), 3u);
    TS_ASSERT_EQUALS(number_range(number_t::three, number_t::zero).stop(), 0u);
    TS_ASSERT_EQUALS(number_range(number_t::three, number_t::zero).step(), -1);
  }
  /** // doc: test__includes__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__includes__1( )
  {
    static_assert(!number_range(number_t::two, number_t::five, 2).includes(number_t::zero));
    static_assert(!number_range(number_t::two, number_t::five, 2).includes(number_t::one));
    static_assert( number_range(number_t::two, number_t::five, 2).includes(number_t::two));
    static_assert(!number_range(number_t::two, number_t::five, 2).includes(number_t::three));
    static_assert( number_range(number_t::two, number_t::five, 2).includes(number_t::four));
    static_assert(!number_range(number_t::two, number_t::five, 2).includes(number_t::five));
    static_assert(!number_range(number_t::two, number_t::five, 2).includes(number_t::six));
  }
};

#endif /* CLXX_C4N_DETAIL_ENUM_RANGE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
