// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/current_instance.t.h

/** // doc: clxx/common/current_instance.t.h {{{
 * \file clxx/common/current_instance.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMON_CURRENT_INSTANCE_T_H_INCLUDED
#define CLXX_COMMON_CURRENT_INSTANCE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/common/current_instance.hpp>

namespace clxx { class current_instance_test_suite; }

/** // doc: class clxx::current_instance_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::current_instance_test_suite : public CxxTest::TestSuite
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

#endif /* CLXX_COMMON_CURRENT_INSTANCE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
