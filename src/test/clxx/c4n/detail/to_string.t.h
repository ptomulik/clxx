// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/to_string.t.h

/** // doc: clxx/c4n/to_string.t.h {{{
 * \file clxx/c4n/to_string.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_C4N_DETAIL_TO_STRING_T_H_INCLUDED
#define CLXX_C4N_DETAIL_TO_STRING_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/c4n/detail/to_string.hpp>

namespace clxx { class to_string_test_suite; }

/** // doc: class clxx::to_string_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::to_string_test_suite : public CxxTest::TestSuite
{
  // We take just few named codes for each enum type. Thorough tests are
  // provided by enum2name.t.h.
public:
  /** // doc: test_foo() {{{
   * \todo Write documentation
   */ // }}}
  void test_foo( )
  {
    TS_ASSERT(true);
  }
};

#endif /* CLXX_C4N_DETAIL_TO_STRING_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
