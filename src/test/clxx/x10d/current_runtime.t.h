// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/x10d/current_runtime.t.h

/** // doc: clxx/x10d/current_runtime.t.h {{{
 * \file clxx/x10d/current_runtime.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_X10D_CURRENT_RUNTIME_T_H_INCLUDED
#define CLXX_X10D_CURRENT_RUNTIME_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/x10d/current_runtime.hpp>

namespace clxx { class current_runtime_test_suite; }

/** // doc: class clxx::unit_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::current_runtime_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__current_runtime__binding() {{{
   * \todo Write documentation
   */ // }}}
  void test__current_runtime__binding( )
  {
    clxx::runtime custom;

    current_runtime::reset_binding();
    TS_ASSERT(current_runtime::binding() == current_instance_default_binding());

    current_runtime::bind_static_instance();
    TS_ASSERT(current_runtime::binding() == current_instance_binding_t::static_instance);

    current_runtime::bind_thread_instance();
    TS_ASSERT(current_runtime::binding() == current_instance_binding_t::thread_instance);

    current_runtime::bind_custom_instance(custom);
    TS_ASSERT(current_runtime::binding() == current_instance_binding_t::custom_instance);
  }
};

#endif /* CLXX_X10D_CURRENT_RUNTIME_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
