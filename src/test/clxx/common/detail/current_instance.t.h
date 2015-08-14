// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/detail/current_instance.t.h

/** // doc: clxx/common/detail/current_instance.t.h {{{
 * \file clxx/common/detail/current_instance.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMON_DETAIL_CURRENT_INSTANCE_T_H_INCLUDED
#define CLXX_COMMON_DETAIL_CURRENT_INSTANCE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/common/detail/current_instance.hpp>

namespace clxx { namespace detail { class current_instance_test_suite; } }

/** // doc: class clxx::detail::current_instance_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::detail::current_instance_test_suite : public CxxTest::TestSuite
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

#endif /* CLXX_COMMON_DETAIL_CURRENT_INSTANCE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
