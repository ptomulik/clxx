// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/current_runtime.t.h

/** // doc: clxx/cl/current_runtime.t.h {{{
 * \file clxx/cl/current_runtime.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_CURRENT_RUNTIME_T_H_INCLUDED
#define CLXX_CL_CURRENT_RUNTIME_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/current_runtime.hpp>

namespace clxx { class current_runtime_test_suite; }

/** // doc: class clxx::unit_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::current_runtime_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__current_runtime() {{{
   * \todo Write documentation
   */ // }}}
  void test__current_runtime( )
  {
    clxx::runtime r;

    current_runtime::reset_binding();
    TS_ASSERT(current_runtime::binding() == current_instance_default_binding());
    TS_ASSERT(&current_runtime::get() != nullptr);

    current_runtime::bind_static_instance();
    TS_ASSERT(current_runtime::binding() == current_instance_binding_t::static_instance);
    TS_ASSERT(&current_runtime::get() != nullptr);

    current_runtime::bind_thread_instance();
    TS_ASSERT(current_runtime::binding() == current_instance_binding_t::thread_instance);
    TS_ASSERT(&current_runtime::get() != nullptr);

    current_runtime::bind_custom_instance(r);
    TS_ASSERT(current_runtime::binding() == current_instance_binding_t::custom_instance);
    TS_ASSERT(&current_runtime::get() == &r);
  }
};

#endif /* CLXX_CL_CURRENT_RUNTIME_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
