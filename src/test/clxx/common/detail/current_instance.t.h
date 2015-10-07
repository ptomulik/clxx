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
#include <type_traits>

namespace clxx { namespace detail { class current_instance_test_suite; } }

/** // doc: class clxx::detail::current_instance_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::detail::current_instance_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__typedefs__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__typedefs__1( )
  {
    struct t : current_instance<t, int>{};
    TS_ASSERT((std::is_same<t::value_type, int>::value));
    TS_ASSERT((std::is_same<t::reference, int&>::value));
    TS_ASSERT((std::is_same<t::pointer, int*>::value));
  }
  /** // doc: test__typedefs__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__typedefs__2( )
  {
    struct t : current_instance<t, const int>{};
    TS_ASSERT((std::is_same<t::value_type, const int>::value));
    TS_ASSERT((std::is_same<t::reference, const int&>::value));
    TS_ASSERT((std::is_same<t::pointer, const int*>::value));
  }
  /** // doc: test__binding__default() {{{
   * \todo Write documentation
   */ // }}}
  void test__binding__default( )
  {
    struct t : current_instance<t, int> {};
    TS_ASSERT_EQUALS(t::binding(), current_instance_default_binding());
    TS_ASSERT(&t::get() != nullptr);
  }
  /** // doc: test__binding__static_instance() {{{
   * \todo Write documentation
   */ // }}}
  void test__binding__static_instance( )
  {
    struct t : current_instance<t, int> {};
    t::bind_static_instance();
    TS_ASSERT_EQUALS(t::binding(), current_instance_binding_t::static_instance);
    TS_ASSERT(&t::get() != nullptr);
  }
  /** // doc: test__binding__thread_instance() {{{
   * \todo Write documentation
   */ // }}}
  void test__binding__thread_instance( )
  {
    struct t : current_instance<t, int> {};
    t::bind_thread_instance();
    TS_ASSERT_EQUALS(t::binding(), current_instance_binding_t::thread_instance);
    TS_ASSERT(&t::get() != nullptr);
  }
  /** // doc: test__binding__custom_instance() {{{
   * \todo Write documentation
   */ // }}}
  void test__binding__custom_instance( )
  {
    struct t : current_instance<t, int> {};
    int u = 0; // user's instance
    t::bind_custom_instance(u);
    TS_ASSERT_EQUALS(t::binding(), current_instance_binding_t::custom_instance);
    TS_ASSERT_EQUALS(&t::get(), &u);
  }
  /** // doc: test__binding__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__binding__1( )
  {
    struct t : current_instance<t, int> {};
    int u = 0; // user's instance
    int *p_default, *p_static, *p_thread, *p_custom;
    //
    p_default = &t::get();
    TS_ASSERT(p_default != nullptr);
    //
    t::bind_static_instance();
    p_static = &t::get();
    TS_ASSERT(p_static != nullptr);
    //
    t::bind_thread_instance();
    p_thread = &t::get();
    TS_ASSERT(p_thread != nullptr);
    TS_ASSERT(p_thread != p_static);
    //
    t::bind_custom_instance(u);
    p_custom = &t::get();
    TS_ASSERT(p_custom == &u);
    TS_ASSERT(p_custom != p_static);
    TS_ASSERT(p_custom != p_thread);
  }
  /** // doc: test__default_static_instance() {{{
   * \todo Write documentation
   */ // }}}
  void test__default_static_instance( )
  {
    struct t : current_instance<t, int> {
      static int default_static_instance() { return 7; }
    };
    t::bind_static_instance();
    TS_ASSERT_EQUALS(t::get(), t::default_static_instance());
  }
  /** // doc: test__default_thread_instance() {{{
   * \todo Write documentation
   */ // }}}
  void test__default_thread_instance( )
  {
    struct t : current_instance<t, int> {
      static int default_thread_instance() { return 11; }
    };
    t::bind_thread_instance();
    TS_ASSERT_EQUALS(t::get(), t::default_thread_instance());
  }
  /** // doc: test__reset_binding() {{{
   * \todo Write documentation
   */ // }}}
  void test__reset_binding( )
  {
    struct t : current_instance<t, int> { };
    int u = 0; // user's instance
    t::bind_custom_instance(u);
    TS_ASSERT(t::binding() != current_instance_default_binding());
    t::reset_binding();
    TS_ASSERT(t::binding() == current_instance_default_binding());
  }
};

#endif /* CLXX_COMMON_DETAIL_CURRENT_INSTANCE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
