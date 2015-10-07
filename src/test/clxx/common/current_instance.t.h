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
#include <type_traits>

namespace clxx { class current_instance_test_suite; }

/** // doc: class clxx::current_instance_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::current_instance_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__current_instance_binding_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__current_instance_binding_t( )
  {
    typedef typename std::underlying_type<current_instance_binding_t>::type I;
    TS_ASSERT_EQUALS(static_cast<I>(current_instance_binding_t::none), static_cast<I>(0));
    TS_ASSERT_EQUALS(static_cast<I>(current_instance_binding_t::static_instance), static_cast<I>(1));
    TS_ASSERT_EQUALS(static_cast<I>(current_instance_binding_t::thread_instance), static_cast<I>(2));
    TS_ASSERT_EQUALS(static_cast<I>(current_instance_binding_t::custom_instance), static_cast<I>(3));
  }
  /** // doc: test__current_instance_default_binding() {{{
   * \todo Write documentation
   */ // }}}
  void test__current_instance_default_binding( )
  {
    TS_ASSERT_EQUALS(current_instance_default_binding(), current_instance_binding_t::static_instance);
    // Set default binding to thread-local instance
    current_instance_default_to_thread_instance();
    TS_ASSERT_EQUALS(current_instance_default_binding(), current_instance_binding_t::thread_instance);
    // Set default binding to static instance
    current_instance_default_to_static_instance();
    TS_ASSERT_EQUALS(current_instance_default_binding(), current_instance_binding_t::static_instance);
    // Set default binding to thread-local and revert to default
    current_instance_default_to_thread_instance();
    current_instance_reset_default_binding();
    TS_ASSERT_EQUALS(current_instance_default_binding(), current_instance_binding_t::static_instance);
  }
};

#endif /* CLXX_COMMON_CURRENT_INSTANCE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
