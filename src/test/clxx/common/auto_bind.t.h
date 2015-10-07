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
#include <clxx/common/detail/current_instance.hpp>

namespace clxx { class auto_bind_test_suite; }

/** // doc: class clxx::auto_bind_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::auto_bind_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__auto_bind__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__auto_bind__1( )
  {
    struct current_int : detail::current_instance<current_int, int>
    { static int default_static_instance() { return 7; } };

    current_int::bind_static_instance();
    TS_ASSERT(current_int::binding() == current_instance_binding_t::static_instance);
    TS_ASSERT(current_int::get() == current_int::default_static_instance());

    {
      int n = 8;
      auto_bind<current_int> ab1(n);
      TS_ASSERT(current_int::binding() == current_instance_binding_t::custom_instance);
      TS_ASSERT(&current_int::get() == &n);
      {
        int m = 9;
        auto_bind<current_int> ab2(m);
        TS_ASSERT(current_int::binding() == current_instance_binding_t::custom_instance);
        TS_ASSERT(&current_int::get() == &m);
      }
      TS_ASSERT_EQUALS(current_int::get(), 8);
    }

    TS_ASSERT(current_int::binding() == current_instance_binding_t::static_instance);
    TS_ASSERT(current_int::get() == current_int::default_static_instance());
  }
};

#endif /* CLXX_COMMON_AUTO_BIND_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
