// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/detail/enum2name.t.h

/** // doc: clxx/c4n/detail/enum2name.t.h {{{
 * \file clxx/c4n/detail/enum2name.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_C4N_DETAIL_ENUM2NAME_T_H_INCLUDED
#define CLXX_C4N_DETAIL_ENUM2NAME_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/c4n/detail/enum2name.hpp>

namespace clxx { namespace detail { class enum2name_test_suite; } }

enum class number_t {
  one = 1,
  two = 2,
  three = 3
};

const char* enum2name(number_t n)
{
  switch(n)
  {
    case number_t::one:
      return "one";
    case number_t::two:
      return "two";
    default:
      return nullptr;
  }
}

/** // doc: class clxx::detail::enum2name_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::detail::enum2name_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__foo() {{{
   * \todo Write documentation
   */ // }}}
  void test__foo( )
  {
    TS_ASSERT_EQUALS(enum2name(number_t::one), "one");
    TS_ASSERT_EQUALS(enum2name(number_t::two), "two");
    TS_ASSERT(enum2name(number_t::three) == nullptr);
  }
};

#endif /* CLXX_C4N_DETAIL_ENUM2NAME_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
