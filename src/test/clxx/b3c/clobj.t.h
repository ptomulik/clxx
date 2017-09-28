// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b3c/clobj.t.h

/** // doc: clxx/b3c/clobj.t.h {{{
 * \file clxx/b3c/clobj.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B3C_CLOBJ_T_H_INCLUDED
#define CLXX_B3C_CLOBJ_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b3c/clobj.hpp>
#include <clxx/b5d/mocks/functions.hpp>

namespace clxx { class clobj_test_suite; }

/** // doc: class clxx::clobj_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::clobj_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__foo() {{{
   * \todo Write documentation
   */ // }}}
  void test__foo( )
  {
    TS_ASSERT(true);
  }
};

#endif /* CLXX_B3C_CLOBJ_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
