// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/config.t.h

/** // doc: clxx/b5d/config.t.h {{{
 * \file clxx/b5d/config.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CONFIG_T_H_INCLUDED
#define CLXX_B5D_CONFIG_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/config.hpp>

namespace clxx { class config_test_suite; }

/** // doc: class clxx::config_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::config_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__config_params_included() {{{
   * \todo Write documentation
   */ // }}}
  void test__config_params_included( )
  {
#ifndef CLXX_B5D_OPENCL_CL_H_VERSION_1_0
# error clxx/b5d/config.hpp must include clxx/b5d/config_params.hpp
#else
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_CL_H_VERSION_1_0, 1);
#endif
  }
  /** // doc: test__functions_config_included() {{{
   * \todo Write documentation
   */ // }}}
  void test__functions_config_included( )
  {
#ifndef CLXX_B5D_FUNCTIONS_CONFIG_HPP_INCLUDED
# error clxx/b5d/config.hpp must include clxx/b5d/functions_config.hpp
#else
    TS_ASSERT(true);
#endif
  }

  /** // doc: test__api_entry() {{{
   * \todo Write documentation
   */ // }}}
  void test__api_entry( )
  {
#ifndef CLXX_B5D_API_ENTRY
# error CLXX_B5D_API_ENTRY is not defined in clxx/b5d/config.hpp
#else
    TS_ASSERT(true);
#endif
  }

  /** // doc: test__api_call() {{{
   * \todo Write documentation
   */ // }}}
  void test__api_call( )
  {
#ifndef CLXX_B5D_API_CALL
# error CLXX_B5D_API_CALL is not defined in clxx/b5d/config.hpp
#else
    TS_ASSERT(true);
#endif
  }

  /** // doc: test__callback() {{{
   * \todo Write documentation
   */ // }}}
  void test__callback( )
  {
#ifndef CLXX_B5D_CALLBACK
# error CLXX_B5D_CALLBACK is not defined in clxx/b5d/config.hpp
#else
    TS_ASSERT(true);
#endif
  }

  /** // doc: test__opencl_provides() {{{
   * \todo Write documentation
   */ // }}}
  void test__opencl_provides( )
  {
#ifndef CLXX_B5D_OPENCL_PROVIDES
# error CLXX_B5D_OPENCL_PROVIDES is not defined in clxx/b5d/config.hpp
#else
#  define CLXX_B5D_OPENCL_DECLARES_foo 123
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_PROVIDES(foo), 123);
#  undef CLXX_B5D_OPENCL_DECLARES_foo
#endif
  }

  /** // doc: test__provides() {{{
   * \todo Write documentation
   */ // }}}
  void test__provides( )
  {
#ifndef CLXX_B5D_PROVIDES
# error CLXX_B5D_PROVIDES is not defined in clxx/b5d/config.hpp
#else
#  define CLXX_B5D_PROVIDES_bar 321
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES(bar), 321);
#  undef CLXX_B5D_PROVIDES_bar
#endif
  }

  /** // doc: test__deprecation_prefix() {{{
   * \todo Write documentation
   */ // }}}
  void test__deprecation_prefix( )
  {
#ifndef CLXX_B5D_DEPRECATION_PREFIX
# error CLXX_B5D_DEPRECATION_PREFIX is not defined in clxx/b5d/config.hpp
#else
    TS_ASSERT(true);
#endif
  }

  /** // doc: test__deprecation_suffix() {{{
   * \todo Write documentation
   */ // }}}
  void test__deprecation_suffix( )
  {
#ifndef CLXX_B5D_DEPRECATION_SUFFIX
# error CLXX_B5D_DEPRECATION_SUFFIX is not defined in clxx/b5d/config.hpp
#else
    TS_ASSERT(true);
#endif
  }

  /** // doc: test__prefix_deprecated() {{{
   * \todo Write documentation
   */ // }}}
  void test__prefix_deprecated( )
  {
#ifndef CLXX_B5D_PREFIX_DEPRECATED
# error CLXX_B5D_PREFIX_DEPRECATED is not defined in clxx/b5d/config.hpp
#else
#  define CLXX_B5D_PREFIX_DEPRECATED_bar 777
    TS_ASSERT_EQUALS(CLXX_B5D_PREFIX_DEPRECATED(bar), 777);
#  undef CLXX_B5D_PREFIX_DEPRECATED_bar
#endif
  }

  /** // doc: test__suffix_deprecated() {{{
   * \todo Write documentation
   */ // }}}
  void test__suffix_deprecated( )
  {
#ifndef CLXX_B5D_SUFFIX_DEPRECATED
# error CLXX_B5D_SUFFIX_DEPRECATED is not defined in clxx/b5d/config.hpp
#else
#  define CLXX_B5D_SUFFIX_DEPRECATED_bar 888
    TS_ASSERT_EQUALS(CLXX_B5D_SUFFIX_DEPRECATED(bar), 888);
#  undef CLXX_B5D_SUFFIX_DEPRECATED_bar
#endif
  }

  /** // doc: test__api_prefix() {{{
   * \todo Write documentation
   */ // }}}
  void test__api_prefix( )
  {
#ifndef CLXX_B5D_API_PREFIX
# error CLXX_B5D_API_PREFIX is not defined in clxx/b5d/config.hpp
#else
    TS_ASSERT(true);
#endif
  }

  /** // doc: test__api_suffix() {{{
   * \todo Write documentation
   */ // }}}
  void test__api_suffix( )
  {
#ifndef CLXX_B5D_API_SUFFIX
# error CLXX_B5D_API_SUFFIX is not defined in clxx/b5d/config.hpp
#else
    TS_ASSERT(true);
#endif
  }
};

#endif /* CLXX_B5D_CONFIG_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
