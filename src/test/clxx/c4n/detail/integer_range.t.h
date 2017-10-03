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

namespace clxx { namespace detail { class integer_iterator_test_suite; } }
namespace clxx { namespace detail { class integer_range_test_suite; } }

/** // doc: class clxx::detail::integer_iterator_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::detail::integer_iterator_test_suite : public CxxTest::TestSuite
{
public:
//  /** // doc: test__ctor__1() {{{
//   * \todo Write documentation
//   */ // }}}
  void test__ctor__1( )
  {
    static_assert(integer_iterator<unsigned>(2u, 3).value() == 2u, "");
    static_assert(integer_iterator<unsigned>(2u, 3).step() == 3, "");

    TS_ASSERT_EQUALS(integer_iterator<unsigned>(2u, 3).value(), 2u);
    TS_ASSERT_EQUALS(integer_iterator<unsigned>(2u, 3).step(), 3);
  }
  /** // doc: test__add__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__add__1( )
  {
    static_assert((integer_iterator<unsigned>(2u, 3) + 2).value() == 8u, "");
    static_assert((integer_iterator<unsigned>(2u, 3) + 2).step() == 3, "");

    TS_ASSERT_EQUALS((integer_iterator<unsigned>(2u, 3) + 2).value(), 8u);
    TS_ASSERT_EQUALS((integer_iterator<unsigned>(2u, 3) + 2).step(), 3);
  }
  /** // doc: test__add__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__add__2( )
  {
    static_assert((2 + integer_iterator<unsigned>(2u, 3)).value() == 8u, "");
    static_assert((2 + integer_iterator<unsigned>(2u, 3)).step() == 3, "");

    TS_ASSERT_EQUALS((2 + integer_iterator<unsigned>(2u, 3)).value(), 8u);
    TS_ASSERT_EQUALS((2 + integer_iterator<unsigned>(2u, 3)).step(), 3);
  }
  /** // doc: test__sub__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__sub__1( )
  {
    static_assert((integer_iterator<unsigned>(8u, 3) - 2).value() == 2u, "");
    static_assert((integer_iterator<unsigned>(8u, 3) - 2).step() == 3, "");

    TS_ASSERT_EQUALS((integer_iterator<unsigned>(8u, 3) - 2).value(), 2u);
    TS_ASSERT_EQUALS((integer_iterator<unsigned>(8u, 3) - 2).step(), 3);
  }
  /** // doc: test__sub__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__sub__2( )
  {
    static_assert((integer_iterator<unsigned>(5u, 1) - integer_iterator<unsigned>(2u, 1)) == 3, "");
    static_assert((integer_iterator<unsigned>(2u, 1) - integer_iterator<unsigned>(5u, 1)) ==-3, "");
    static_assert((integer_iterator<unsigned>(5u, 2) - integer_iterator<unsigned>(2u, 1)) == 3, "");
    static_assert((integer_iterator<unsigned>(2u, 2) - integer_iterator<unsigned>(5u, 1)) ==-3, "");
    static_assert((integer_iterator<unsigned>(5u, 2) - integer_iterator<unsigned>(2u,-1)) ==-3, "");
    static_assert((integer_iterator<unsigned>(2u, 2) - integer_iterator<unsigned>(5u,-1)) == 3, "");
    static_assert((integer_iterator<unsigned>(5u, 1) - integer_iterator<unsigned>(2u, 2)) == 2, "");
    static_assert((integer_iterator<unsigned>(2u, 1) - integer_iterator<unsigned>(5u, 2)) ==-2, "");
    static_assert((integer_iterator<unsigned>(5u, 1) - integer_iterator<unsigned>(2u,-2)) ==-2, "");
    static_assert((integer_iterator<unsigned>(2u, 1) - integer_iterator<unsigned>(5u,-2)) == 2, "");

    TS_ASSERT_EQUALS((integer_iterator<unsigned>(5u, 1) - integer_iterator<unsigned>(2u, 1)), 3);
    TS_ASSERT_EQUALS((integer_iterator<unsigned>(2u, 1) - integer_iterator<unsigned>(5u, 1)),-3);
    TS_ASSERT_EQUALS((integer_iterator<unsigned>(5u, 2) - integer_iterator<unsigned>(2u, 1)), 3);
    TS_ASSERT_EQUALS((integer_iterator<unsigned>(2u, 2) - integer_iterator<unsigned>(5u, 1)),-3);
    TS_ASSERT_EQUALS((integer_iterator<unsigned>(5u, 2) - integer_iterator<unsigned>(2u,-1)),-3);
    TS_ASSERT_EQUALS((integer_iterator<unsigned>(2u, 2) - integer_iterator<unsigned>(5u,-1)), 3);
    TS_ASSERT_EQUALS((integer_iterator<unsigned>(5u, 1) - integer_iterator<unsigned>(2u, 2)), 2);
    TS_ASSERT_EQUALS((integer_iterator<unsigned>(2u, 1) - integer_iterator<unsigned>(5u, 2)),-2);
    TS_ASSERT_EQUALS((integer_iterator<unsigned>(5u, 1) - integer_iterator<unsigned>(2u,-2)),-2);
    TS_ASSERT_EQUALS((integer_iterator<unsigned>(2u, 1) - integer_iterator<unsigned>(5u,-2)), 2);
  }
  /** // doc: test__distance__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__distance__1( )
  {
    static_assert(std::distance(integer_iterator<unsigned>(2u, 1), integer_iterator<unsigned>(5u, 1)) == 3, "");
    static_assert(std::distance(integer_iterator<unsigned>(5u, 1), integer_iterator<unsigned>(2u, 1)) ==-3, "");
    static_assert(std::distance(integer_iterator<unsigned>(2u, 1), integer_iterator<unsigned>(5u, 2)) == 3, "");
    static_assert(std::distance(integer_iterator<unsigned>(5u, 1), integer_iterator<unsigned>(2u, 2)) ==-3, "");
    static_assert(std::distance(integer_iterator<unsigned>(2u,-1), integer_iterator<unsigned>(5u, 2)) ==-3, "");
    static_assert(std::distance(integer_iterator<unsigned>(5u,-1), integer_iterator<unsigned>(2u, 2)) == 3, "");
    static_assert(std::distance(integer_iterator<unsigned>(2u, 2), integer_iterator<unsigned>(5u, 1)) == 2, "");
    static_assert(std::distance(integer_iterator<unsigned>(5u, 2), integer_iterator<unsigned>(2u, 1)) ==-2, "");
    static_assert(std::distance(integer_iterator<unsigned>(2u,-2), integer_iterator<unsigned>(5u, 1)) ==-2, "");
    static_assert(std::distance(integer_iterator<unsigned>(5u,-2), integer_iterator<unsigned>(2u, 1)) == 2, "");

    TS_ASSERT_EQUALS(std::distance(integer_iterator<unsigned>(2u, 1), integer_iterator<unsigned>(5u, 1)), 3);
    TS_ASSERT_EQUALS(std::distance(integer_iterator<unsigned>(5u, 1), integer_iterator<unsigned>(2u, 1)),-3);
    TS_ASSERT_EQUALS(std::distance(integer_iterator<unsigned>(2u, 1), integer_iterator<unsigned>(5u, 2)), 3);
    TS_ASSERT_EQUALS(std::distance(integer_iterator<unsigned>(5u, 1), integer_iterator<unsigned>(2u, 2)),-3);
    TS_ASSERT_EQUALS(std::distance(integer_iterator<unsigned>(2u,-1), integer_iterator<unsigned>(5u, 2)),-3);
    TS_ASSERT_EQUALS(std::distance(integer_iterator<unsigned>(5u,-1), integer_iterator<unsigned>(2u, 2)), 3);
    TS_ASSERT_EQUALS(std::distance(integer_iterator<unsigned>(2u, 2), integer_iterator<unsigned>(5u, 1)), 2);
    TS_ASSERT_EQUALS(std::distance(integer_iterator<unsigned>(5u, 2), integer_iterator<unsigned>(2u, 1)),-2);
    TS_ASSERT_EQUALS(std::distance(integer_iterator<unsigned>(2u,-2), integer_iterator<unsigned>(5u, 1)),-2);
    TS_ASSERT_EQUALS(std::distance(integer_iterator<unsigned>(5u,-2), integer_iterator<unsigned>(2u, 1)), 2);
  }
  /** // doc: test__subscript__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__subscript__1( )
  {
    integer_iterator<unsigned> it(2u, 1);
    TS_ASSERT_EQUALS(it[0], 2u);
    TS_ASSERT_EQUALS(it[1], 3u);
    TS_ASSERT_EQUALS(it[2], 4u);
    TS_ASSERT_EQUALS(it.value(), 2u);
  }
  /** // doc: test__subscript__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__subscript__2( )
  {
    integer_iterator<unsigned> it(2u, 3);
    TS_ASSERT_EQUALS(it[0], 2u);
    TS_ASSERT_EQUALS(it[1], 5u);
    TS_ASSERT_EQUALS(it[2], 8u);
    TS_ASSERT_EQUALS(it.value(), 2u);
  }
  /** // doc: test__deref__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__deref__1( )
  {
    static_assert(*(integer_iterator<unsigned>(2u, 3)) == 2u, "");
    static_assert(*(integer_iterator<unsigned>(5u, 3)) == 5u, "");

    TS_ASSERT_EQUALS(*(integer_iterator<unsigned>(2u, 3)), 2u);
    TS_ASSERT_EQUALS(*(integer_iterator<unsigned>(5u, 3)), 5u);
  }
  /** // doc: test__pre_inc__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__pre_inc__1( )
  {
    integer_iterator<unsigned> it(2u, 1);
    TS_ASSERT_EQUALS(it.value(), 2u);
    ++it;
    TS_ASSERT_EQUALS(it.value(), 3u);
    ++it;
    TS_ASSERT_EQUALS(it.value(), 4u);
  }
  /** // doc: test__pre_inc__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__pre_inc__2( )
  {
    integer_iterator<unsigned> it(2u, 3);
    TS_ASSERT_EQUALS(it.value(), 2u);
    ++it;
    TS_ASSERT_EQUALS(it.value(), 5u);
    ++it;
    TS_ASSERT_EQUALS(it.value(), 8u);
  }
  /** // doc: test__pre_inc__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__pre_inc__3( )
  {
    integer_iterator<unsigned> it(2u, 3);
    TS_ASSERT_EQUALS(*it, 2u);
    TS_ASSERT_EQUALS(*++it, 5u);
    TS_ASSERT_EQUALS(*++it, 8u);
  }
  /** // doc: test__pre_inc__4() {{{
   * \todo Write documentation
   */ // }}}
  void test__pre_inc__4( )
  {
    integer_iterator<unsigned> it(8u, -3);
    TS_ASSERT_EQUALS(it.value(), 8u);
    ++it;
    TS_ASSERT_EQUALS(it.value(), 5u);
    ++it;
    TS_ASSERT_EQUALS(it.value(), 2u);
  }
  /** // doc: test__pre_inc__5() {{{
   * \todo Write documentation
   */ // }}}
  void test__pre_inc__5( )
  {
    integer_iterator<unsigned> it(8u, -3);
    TS_ASSERT_EQUALS(*it, 8u);
    TS_ASSERT_EQUALS(*++it, 5u);
    TS_ASSERT_EQUALS(*++it, 2u);
  }
  /** // doc: test__pre_dec__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__pre_dec__1( )
  {
    integer_iterator<unsigned> it(8u, 1);
    TS_ASSERT_EQUALS(it.value(), 8u);
    --it;
    TS_ASSERT_EQUALS(it.value(), 7u);
    --it;
    TS_ASSERT_EQUALS(it.value(), 6u);
  }
  /** // doc: test__pre_dec__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__pre_dec__2( )
  {
    integer_iterator<unsigned> it(8u, 3);
    TS_ASSERT_EQUALS(it.value(), 8u);
    --it;
    TS_ASSERT_EQUALS(it.value(), 5u);
    --it;
    TS_ASSERT_EQUALS(it.value(), 2u);
  }
  /** // doc: test__pre_dec__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__pre_dec__3( )
  {
    integer_iterator<unsigned> it(8u, 3);
    TS_ASSERT_EQUALS(*it, 8u);
    TS_ASSERT_EQUALS(*--it, 5u);
    TS_ASSERT_EQUALS(*--it, 2u);
  }
  /** // doc: test__pre_dec__4() {{{
   * \todo Write documentation
   */ // }}}
  void test__pre_dec__4( )
  {
    integer_iterator<unsigned> it(2u, -3);
    TS_ASSERT_EQUALS(it.value(), 2u);
    --it;
    TS_ASSERT_EQUALS(it.value(), 5u);
    --it;
    TS_ASSERT_EQUALS(it.value(), 8u);
  }
  /** // doc: test__pre_dec__5() {{{
   * \todo Write documentation
   */ // }}}
  void test__pre_dec__5( )
  {
    integer_iterator<unsigned> it(2u, -3);
    TS_ASSERT_EQUALS(*it, 2u);
    TS_ASSERT_EQUALS(*--it, 5u);
    TS_ASSERT_EQUALS(*--it, 8u);
  }
  /** // doc: test__post_inc__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__post_inc__1( )
  {
    integer_iterator<unsigned> it(2u, 1);
    TS_ASSERT_EQUALS(it.value(), 2u);
    it++;
    TS_ASSERT_EQUALS(it.value(), 3u);
    it++;
    TS_ASSERT_EQUALS(it.value(), 4u);
  }
  /** // doc: test__post_inc__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__post_inc__2( )
  {
    integer_iterator<unsigned> it(2u, 3);
    TS_ASSERT_EQUALS(it.value(), 2u);
    it++;
    TS_ASSERT_EQUALS(it.value(), 5u);
    it++;
    TS_ASSERT_EQUALS(it.value(), 8u);
  }
  /** // doc: test__post_inc__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__post_inc__3( )
  {
    integer_iterator<unsigned> it(2u, 3);
    TS_ASSERT_EQUALS(*it++, 2u);
    TS_ASSERT_EQUALS(*it++, 5u);
    TS_ASSERT_EQUALS(*it, 8u);
  }
  /** // doc: test__post_inc__4() {{{
   * \todo Write documentation
   */ // }}}
  void test__post_inc__4( )
  {
    integer_iterator<unsigned> it(8u, -3);
    TS_ASSERT_EQUALS(it.value(), 8u);
    it++;
    TS_ASSERT_EQUALS(it.value(), 5u);
    it++;
    TS_ASSERT_EQUALS(it.value(), 2u);
  }
  /** // doc: test__post_inc__5() {{{
   * \todo Write documentation
   */ // }}}
  void test__post_inc__5( )
  {
    integer_iterator<unsigned> it(8u, -3);
    TS_ASSERT_EQUALS(*it++, 8u);
    TS_ASSERT_EQUALS(*it++, 5u);
    TS_ASSERT_EQUALS(*it, 2u);
  }
  /** // doc: test__post_dec__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__post_dec__1( )
  {
    integer_iterator<unsigned> it(8u, 1);
    TS_ASSERT_EQUALS(it.value(), 8u);
    it--;
    TS_ASSERT_EQUALS(it.value(), 7u);
    it--;
    TS_ASSERT_EQUALS(it.value(), 6u);
  }
  /** // doc: test__post_dec__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__post_dec__2( )
  {
    integer_iterator<unsigned> it(8u, 3);
    TS_ASSERT_EQUALS(it.value(), 8u);
    it--;
    TS_ASSERT_EQUALS(it.value(), 5u);
    it--;
    TS_ASSERT_EQUALS(it.value(), 2u);
  }
  /** // doc: test__post_dec__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__post_dec__3( )
  {
    integer_iterator<unsigned> it(8u, 3);
    TS_ASSERT_EQUALS(*it--, 8u);
    TS_ASSERT_EQUALS(*it--, 5u);
    TS_ASSERT_EQUALS(*it, 2u);
  }
  /** // doc: test__post_dec__4() {{{
   * \todo Write documentation
   */ // }}}
  void test__post_dec__4( )
  {
    integer_iterator<unsigned> it(2u, -3);
    TS_ASSERT_EQUALS(it.value(), 2u);
    it--;
    TS_ASSERT_EQUALS(it.value(), 5u);
    it--;
    TS_ASSERT_EQUALS(it.value(), 8u);
  }
  /** // doc: test__post_dec__5() {{{
   * \todo Write documentation
   */ // }}}
  void test__post_dec__5( )
  {
    integer_iterator<unsigned> it(2u, -3);
    TS_ASSERT_EQUALS(*it--, 2u);
    TS_ASSERT_EQUALS(*it--, 5u);
    TS_ASSERT_EQUALS(*it, 8u);
  }
  /** // doc: test__add_assign__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__add_assign__1( )
  {
    integer_iterator<unsigned> it(2u, 1);
    TS_ASSERT_EQUALS(*it, 2u);
    TS_ASSERT_EQUALS(*(it+=3), 5u);
    TS_ASSERT_EQUALS(*it, 5u);
    TS_ASSERT_EQUALS(*(it+=3), 8u);
    TS_ASSERT_EQUALS(*it, 8u);
  }
  /** // doc: test__add_assign__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__add_assign__2( )
  {
    integer_iterator<unsigned> it(2u, 3);
    TS_ASSERT_EQUALS(*it, 2u);
    TS_ASSERT_EQUALS(*(it+=3), 11u);
    TS_ASSERT_EQUALS(*it, 11u);
    TS_ASSERT_EQUALS(*(it+=3), 20u);
    TS_ASSERT_EQUALS(*it, 20u);
  }
  /** // doc: test__add_assign__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__add_assign__3( )
  {
    integer_iterator<unsigned> it(20u, -3);
    TS_ASSERT_EQUALS(*it, 20u);
    TS_ASSERT_EQUALS(*(it+=3), 11u);
    TS_ASSERT_EQUALS(*it, 11u);
    TS_ASSERT_EQUALS(*(it+=3), 2u);
    TS_ASSERT_EQUALS(*it, 2u);
  }
  /** // doc: test__sub_assign__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__sub_assign__1( )
  {
    integer_iterator<unsigned> it(8u, 1);
    TS_ASSERT_EQUALS(*it, 8u);
    TS_ASSERT_EQUALS(*(it-=3), 5u);
    TS_ASSERT_EQUALS(*it, 5u);
    TS_ASSERT_EQUALS(*(it-=3), 2u);
    TS_ASSERT_EQUALS(*it, 2u);
  }
  /** // doc: test__sub_assign__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__sub_assign__2( )
  {
    integer_iterator<unsigned> it(20u, 3);
    TS_ASSERT_EQUALS(*it, 20u);
    TS_ASSERT_EQUALS(*(it-=3), 11u);
    TS_ASSERT_EQUALS(*it, 11u);
    TS_ASSERT_EQUALS(*(it-=3), 2u);
    TS_ASSERT_EQUALS(*it, 2u);
  }
  /** // doc: test__sub_assign__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__sub_assign__3( )
  {
    integer_iterator<unsigned> it(2u, -3);
    TS_ASSERT_EQUALS(*it, 2u);
    TS_ASSERT_EQUALS(*(it-=3), 11u);
    TS_ASSERT_EQUALS(*it, 11u);
    TS_ASSERT_EQUALS(*(it-=3), 20u);
    TS_ASSERT_EQUALS(*it, 20u);
  }
  /** // doc: test__eq__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__eq__1( )
  {
    static_assert( (integer_iterator<unsigned>(2u,3) == integer_iterator<unsigned>(2u,3)), "");
    static_assert( (integer_iterator<unsigned>(2u,1) == integer_iterator<unsigned>(2u,3)), "");
    static_assert(!(integer_iterator<unsigned>(2u,3) == integer_iterator<unsigned>(1u,3)), "");
    static_assert(!(integer_iterator<unsigned>(2u,1) == integer_iterator<unsigned>(1u,3)), "");
    TS_ASSERT( (integer_iterator<unsigned>(2u,3) == integer_iterator<unsigned>(2u,3)));
    TS_ASSERT( (integer_iterator<unsigned>(2u,1) == integer_iterator<unsigned>(2u,3)));
    TS_ASSERT(!(integer_iterator<unsigned>(2u,3) == integer_iterator<unsigned>(1u,3)));
    TS_ASSERT(!(integer_iterator<unsigned>(2u,1) == integer_iterator<unsigned>(1u,3)));
  }
  /** // doc: test__neq__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__neq__1( )
  {
    static_assert(!(integer_iterator<unsigned>(2u,3) != integer_iterator<unsigned>(2u,3)), "");
    static_assert(!(integer_iterator<unsigned>(2u,1) != integer_iterator<unsigned>(2u,3)), "");
    static_assert( (integer_iterator<unsigned>(2u,3) != integer_iterator<unsigned>(1u,3)), "");
    static_assert( (integer_iterator<unsigned>(2u,1) != integer_iterator<unsigned>(1u,3)), "");
    TS_ASSERT(!(integer_iterator<unsigned>(2u,3) != integer_iterator<unsigned>(2u,3)));
    TS_ASSERT(!(integer_iterator<unsigned>(2u,1) != integer_iterator<unsigned>(2u,3)));
    TS_ASSERT( (integer_iterator<unsigned>(2u,3) != integer_iterator<unsigned>(1u,3)));
    TS_ASSERT( (integer_iterator<unsigned>(2u,1) != integer_iterator<unsigned>(1u,3)));
  }
  /** // doc: test__lt__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__lt__1( )
  {
    static_assert( (integer_iterator<unsigned>(2u, 1) < integer_iterator<unsigned>(3u, 1)), "");
    static_assert(!(integer_iterator<unsigned>(3u, 1) < integer_iterator<unsigned>(2u, 1)), "");
    static_assert(!(integer_iterator<unsigned>(3u, 1) < integer_iterator<unsigned>(3u, 1)), "");
    static_assert(!(integer_iterator<unsigned>(2u,-1) < integer_iterator<unsigned>(3u,-1)), "");
    static_assert( (integer_iterator<unsigned>(3u,-1) < integer_iterator<unsigned>(2u,-1)), "");
    static_assert(!(integer_iterator<unsigned>(3u,-1) < integer_iterator<unsigned>(3u,-1)), "");

    TS_ASSERT( (integer_iterator<unsigned>(2u, 1) < integer_iterator<unsigned>(3u, 1)));
    TS_ASSERT(!(integer_iterator<unsigned>(3u, 1) < integer_iterator<unsigned>(2u, 1)));
    TS_ASSERT(!(integer_iterator<unsigned>(3u, 1) < integer_iterator<unsigned>(3u, 1)));
    TS_ASSERT(!(integer_iterator<unsigned>(2u,-1) < integer_iterator<unsigned>(3u,-1)));
    TS_ASSERT( (integer_iterator<unsigned>(3u,-1) < integer_iterator<unsigned>(2u,-1)));
    TS_ASSERT(!(integer_iterator<unsigned>(3u,-1) < integer_iterator<unsigned>(3u,-1)));
  }
  /** // doc: test__gt__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__gt__1( )
  {
    static_assert(!(integer_iterator<unsigned>(2u, 1) > integer_iterator<unsigned>(3u, 1)), "");
    static_assert( (integer_iterator<unsigned>(3u, 1) > integer_iterator<unsigned>(2u, 1)), "");
    static_assert(!(integer_iterator<unsigned>(3u, 1) > integer_iterator<unsigned>(3u, 1)), "");
    static_assert( (integer_iterator<unsigned>(2u,-1) > integer_iterator<unsigned>(3u,-1)), "");
    static_assert(!(integer_iterator<unsigned>(3u,-1) > integer_iterator<unsigned>(2u,-1)), "");
    static_assert(!(integer_iterator<unsigned>(3u,-1) > integer_iterator<unsigned>(3u,-1)), "");

    TS_ASSERT(!(integer_iterator<unsigned>(2u, 1) > integer_iterator<unsigned>(3u, 1)));
    TS_ASSERT( (integer_iterator<unsigned>(3u, 1) > integer_iterator<unsigned>(2u, 1)));
    TS_ASSERT(!(integer_iterator<unsigned>(3u, 1) > integer_iterator<unsigned>(3u, 1)));
    TS_ASSERT( (integer_iterator<unsigned>(2u,-1) > integer_iterator<unsigned>(3u,-1)));
    TS_ASSERT(!(integer_iterator<unsigned>(3u,-1) > integer_iterator<unsigned>(2u,-1)));
    TS_ASSERT(!(integer_iterator<unsigned>(3u,-1) > integer_iterator<unsigned>(3u,-1)));
  }
  /** // doc: test__le__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__le__1( )
  {
    static_assert( (integer_iterator<unsigned>(2u, 1) <= integer_iterator<unsigned>(3u, 1)), "");
    static_assert(!(integer_iterator<unsigned>(3u, 1) <= integer_iterator<unsigned>(2u, 1)), "");
    static_assert( (integer_iterator<unsigned>(3u, 1) <= integer_iterator<unsigned>(3u, 1)), "");
    static_assert(!(integer_iterator<unsigned>(2u,-1) <= integer_iterator<unsigned>(3u,-1)), "");
    static_assert( (integer_iterator<unsigned>(3u,-1) <= integer_iterator<unsigned>(2u,-1)), "");
    static_assert( (integer_iterator<unsigned>(3u,-1) <= integer_iterator<unsigned>(3u,-1)), "");

    TS_ASSERT( (integer_iterator<unsigned>(2u, 1) <= integer_iterator<unsigned>(3u, 1)));
    TS_ASSERT(!(integer_iterator<unsigned>(3u, 1) <= integer_iterator<unsigned>(2u, 1)));
    TS_ASSERT( (integer_iterator<unsigned>(3u, 1) <= integer_iterator<unsigned>(3u, 1)));
    TS_ASSERT(!(integer_iterator<unsigned>(2u,-1) <= integer_iterator<unsigned>(3u,-1)));
    TS_ASSERT( (integer_iterator<unsigned>(3u,-1) <= integer_iterator<unsigned>(2u,-1)));
    TS_ASSERT( (integer_iterator<unsigned>(3u,-1) <= integer_iterator<unsigned>(3u,-1)));
  }
  /** // doc: test__ge__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__ge__1( )
  {
    static_assert(!(integer_iterator<unsigned>(2u, 1) >= integer_iterator<unsigned>(3u, 1)), "");
    static_assert( (integer_iterator<unsigned>(3u, 1) >= integer_iterator<unsigned>(2u, 1)), "");
    static_assert( (integer_iterator<unsigned>(3u, 1) >= integer_iterator<unsigned>(3u, 1)), "");
    static_assert( (integer_iterator<unsigned>(2u,-1) >= integer_iterator<unsigned>(3u,-1)), "");
    static_assert(!(integer_iterator<unsigned>(3u,-1) >= integer_iterator<unsigned>(2u,-1)), "");
    static_assert( (integer_iterator<unsigned>(3u,-1) >= integer_iterator<unsigned>(3u,-1)), "");

    TS_ASSERT(!(integer_iterator<unsigned>(2u, 1) >= integer_iterator<unsigned>(3u, 1)));
    TS_ASSERT( (integer_iterator<unsigned>(3u, 1) >= integer_iterator<unsigned>(2u, 1)));
    TS_ASSERT( (integer_iterator<unsigned>(3u, 1) >= integer_iterator<unsigned>(3u, 1)));
    TS_ASSERT( (integer_iterator<unsigned>(2u,-1) >= integer_iterator<unsigned>(3u,-1)));
    TS_ASSERT(!(integer_iterator<unsigned>(3u,-1) >= integer_iterator<unsigned>(2u,-1)));
    TS_ASSERT( (integer_iterator<unsigned>(3u,-1) >= integer_iterator<unsigned>(3u,-1)));
  }
};

/** // doc: class clxx::detail::integer_range_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::detail::integer_range_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor__1( )
  {
    static_assert(integer_range<unsigned>().start() == 0u, "");
    static_assert(integer_range<unsigned>().stop() == 0u, "");
    static_assert(integer_range<unsigned>().step() == 1, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>().start(), 0u);
    TS_ASSERT_EQUALS(integer_range<unsigned>().stop(), 0u);
    TS_ASSERT_EQUALS(integer_range<unsigned>().step(), 1);
  }
//  /** // doc: test__ctor__2() {{{
//   * \todo Write documentation
//   */ // }}}
  void test__ctor__2( )
  {
    static_assert(integer_range<unsigned>(5u).start() == 0u, "");
    static_assert(integer_range<unsigned>(5u).stop() == 5u, "");
    static_assert(integer_range<unsigned>(5u).step() == 1, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(5u).start(), 0u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u).stop(), 5u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u).step(), 1);
  }
//  /** // doc: test__ctor__3() {{{
//   * \todo Write documentation
//   */ // }}}
  void test__ctor__3( )
  {
    static_assert(integer_range<unsigned>(2u,5u).start() == 2u, "");
    static_assert(integer_range<unsigned>(2u,5u).stop() == 5u, "");
    static_assert(integer_range<unsigned>(2u,5u).step() == 1, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).start(), 2u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).stop(), 5u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).step(), 1);
  }
//  /** // doc: test__ctor__4() {{{
//   * \todo Write documentation
//   */ // }}}
  void test__ctor__4( )
  {
    static_assert(integer_range<unsigned>(5u,2u).start() == 5u, "");
    static_assert(integer_range<unsigned>(5u,2u).stop() == 2u, "");
    static_assert(integer_range<unsigned>(5u,2u).step() == -1, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).start(), 5u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).stop(), 2u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).step(), -1);
  }
//  /** // doc: test__ctor__5() {{{
//   * \todo Write documentation
//   */ // }}}
  void test__ctor__5( )
  {
    static_assert(integer_range<unsigned>(2u,5u,3).start() == 2u, "");
    static_assert(integer_range<unsigned>(2u,5u,3).stop() == 5u, "");
    static_assert(integer_range<unsigned>(2u,5u,3).step() == 3, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u,3).start(), 2u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u,3).stop(), 5u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u,3).step(), 3);
  }
//  /** // doc: test__ctor__6() {{{
//   * \todo Write documentation
//   */ // }}}
  void test__ctor__6( )
  {
    static_assert(integer_range<unsigned>(5u,2u,-3).start() == 5u, "");
    static_assert(integer_range<unsigned>(5u,2u,-3).stop() == 2u, "");
    static_assert(integer_range<unsigned>(5u,2u,-3).step() == -3, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u,-3).start(), 5u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u,-3).stop(), 2u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u,-3).step(), -3);
  }
  /** // doc: test__low__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__low__1( )
  {
    static_assert(integer_range<unsigned>(2u,5u).low() == 2u, "");
    static_assert(integer_range<unsigned>(5u,2u).low() == 2u, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).low(), 2u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).low(), 2u);
  }
  /** // doc: test__high__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__high__1( )
  {
    static_assert(integer_range<unsigned>(2u,5u).high() == 5u, "");
    static_assert(integer_range<unsigned>(5u,2u).high() == 5u, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).high(), 5u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).high(), 5u);
  }
  /** // doc: test__begin__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__begin__1( )
  {
    static_assert(integer_range<unsigned>(2u,5u).begin().value() == 2u, "");
    static_assert(integer_range<unsigned>(2u,5u).begin().step() == 1, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).begin().value(), 2u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).begin().step(), 1);
  }
  /** // doc: test__begin__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__begin__2( )
  {
    static_assert(integer_range<unsigned>(5u,2u).begin().value() == 5u, "");
    static_assert(integer_range<unsigned>(5u,2u).begin().step() == -1, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).begin().value(), 5u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).begin().step(), -1);
  }
  /** // doc: test__begin__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__begin__3( )
  {
    static_assert(integer_range<unsigned>(5u,2u,-2).begin().value() == 5u, "");
    static_assert(integer_range<unsigned>(5u,2u,-2).begin().step() == -2, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u,-2).begin().value(), 5u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u,-2).begin().step(), -2);
  }
  /** // doc: test__end__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__end__1( )
  {
    static_assert(integer_range<unsigned>(2u,5u).end().value() == 5u, "");
    static_assert(integer_range<unsigned>(2u,5u).end().step() == 1, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).end().value(), 5u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u).end().step(), 1);
  }
  /** // doc: test__end__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__end__2( )
  {
    static_assert(integer_range<unsigned>(5u,2u).end().value() == 2u, "");
    static_assert(integer_range<unsigned>(5u,2u).end().step() == -1, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).end().value(), 2u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u).end().step(), -1);
  }
  /** // doc: test__end__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__end__3( )
  {
    static_assert(integer_range<unsigned>(5u,2u,-2).end().value() == 1u, "");
    static_assert(integer_range<unsigned>(5u,2u,-2).end().step() == -2, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u,-2).end().value(), 1u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u,-2).end().step(), -2);
  }
  /** // doc: test__end__4() {{{
   * \todo Write documentation
   */ // }}}
  void test__end__4( )
  {
    static_assert(integer_range<unsigned>(5u,3u,-2).end().value() == 3u, "");
    static_assert(integer_range<unsigned>(5u,3u,-2).end().step() == -2, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,3u,-2).end().value(), 3u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,3u,-2).end().step(), -2);
  }
  /** // doc: test__includes__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__includes__1( )
  {
    static_assert(!integer_range<unsigned>(2u,5u, 1).includes(1u), "");
    static_assert( integer_range<unsigned>(2u,5u, 1).includes(2u), "");
    static_assert( integer_range<unsigned>(2u,5u, 1).includes(3u), "");
    static_assert( integer_range<unsigned>(2u,5u, 1).includes(4u), "");
    static_assert(!integer_range<unsigned>(2u,5u, 1).includes(5u), "");
    static_assert(!integer_range<unsigned>(2u,5u, 1).includes(6u), "");

    TS_ASSERT(!integer_range<unsigned>(2u,5u, 1).includes(1u));
    TS_ASSERT( integer_range<unsigned>(2u,5u, 1).includes(2u));
    TS_ASSERT( integer_range<unsigned>(2u,5u, 1).includes(3u));
    TS_ASSERT( integer_range<unsigned>(2u,5u, 1).includes(4u));
    TS_ASSERT(!integer_range<unsigned>(2u,5u, 1).includes(5u));
    TS_ASSERT(!integer_range<unsigned>(2u,5u, 1).includes(6u));
  }
  /** // doc: test__includes__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__includes__2( )
  {
    static_assert(!integer_range<unsigned>(2u,5u, 2).includes(1u), "");
    static_assert( integer_range<unsigned>(2u,5u, 2).includes(2u), "");
    static_assert(!integer_range<unsigned>(2u,5u, 2).includes(3u), "");
    static_assert( integer_range<unsigned>(2u,5u, 2).includes(4u), "");
    static_assert(!integer_range<unsigned>(2u,5u, 2).includes(5u), "");
    static_assert(!integer_range<unsigned>(2u,5u, 2).includes(6u), "");

    TS_ASSERT(!integer_range<unsigned>(2u,5u, 2).includes(1u));
    TS_ASSERT( integer_range<unsigned>(2u,5u, 2).includes(2u));
    TS_ASSERT(!integer_range<unsigned>(2u,5u, 2).includes(3u));
    TS_ASSERT( integer_range<unsigned>(2u,5u, 2).includes(4u));
    TS_ASSERT(!integer_range<unsigned>(2u,5u, 2).includes(5u));
    TS_ASSERT(!integer_range<unsigned>(2u,5u, 2).includes(6u));
  }
  /** // doc: test__size__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__size__1( )
  {
    static_assert(integer_range<unsigned>(2u,5u, 1).size() == 3u, "");
    static_assert(integer_range<unsigned>(2u,5u, 2).size() == 2u, "");
    static_assert(integer_range<unsigned>(5u,2u,-1).size() == 3u, "");
    static_assert(integer_range<unsigned>(5u,2u,-2).size() == 2u, "");

    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u, 1).size(), 3u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(2u,5u, 2).size(), 2u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u,-1).size(), 3u);
    TS_ASSERT_EQUALS(integer_range<unsigned>(5u,2u,-2).size(), 2u);
  }
  /** // doc: test__for__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__for__1( )
  {
    const unsigned expected[] = { 0u, 1u, 2u, 3u };
    int i = 0;
    for(unsigned x : integer_range<unsigned>(4u)) {
      TS_ASSERT_EQUALS(x, expected[i]);
      ++i;
    }
    TS_ASSERT_EQUALS(i, 4);
  }
  /** // doc: test__for__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__for__2( )
  {
    const unsigned expected[] = { 2u, 4u };
    int i = 0;
    for(unsigned x : integer_range<unsigned>(2u, 5u, 2)) {
      TS_ASSERT_EQUALS(x, expected[i]);
      ++i;
    }
    TS_ASSERT_EQUALS(i, 2);
  }
  /** // doc: test__for__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__for__3( )
  {
    const unsigned expected[] = { 5u, 3u };
    int i = 0;
    for(unsigned x : integer_range<unsigned>(5u, 2u, -2)) {
      TS_ASSERT_EQUALS(x, expected[i]);
      ++i;
    }
    TS_ASSERT_EQUALS(i, 2);
  }
};

#endif /* CLXX_C4N_DETAIL_INTEGER_RANGE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
