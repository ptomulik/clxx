// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/auto_bind.t.h

/** // doc: clxx/common/auto_bind.t.h {{{
 * \file clxx/common/auto_bind.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMON_AUTO_BIND_T_H_INCLUDED
#define CLXX_COMMON_AUTO_BIND_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/common/auto_bind.hpp>

namespace clxx { class auto_bind_test_suite; }

/** // doc: class clxx::auto_bind_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::auto_bind_test_suite : public CxxTest::TestSuite
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

#endif /* CLXX_COMMON_AUTO_BIND_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
