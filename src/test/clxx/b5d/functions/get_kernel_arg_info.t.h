// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/get_kernel_arg_info.t.h

/** // doc: clxx/b5d/functions/get_kernel_arg_info.t.h {{{
 * \file clxx/b5d/functions/get_kernel_arg_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_GET_KERNEL_ARG_INFO_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_GET_KERNEL_ARG_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class get_kernel_arg_info_test_suite; }

/** // doc: class clxx::get_kernel_arg_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::get_kernel_arg_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_kernel_arg_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_kernel_arg_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_arg_info( )
  {
#if CLXX_B5D_PROVIDES(get_kernel_arg_info)
    T::Dummy_clGetKernelArgInfo mock(CL_SUCCESS);
    get_kernel_arg_info            ((cl_kernel)0x395, 0, kernel_arg_info_t::name,                5, (void*)0x124, (size_t*)0x934);
    TS_ASSERT(mock.called_once_with((cl_kernel)0x395, 0, (cl_kernel_arg_info)CL_KERNEL_ARG_NAME, 5, (void*)0x124, (size_t*)0x934));
#else
    TS_SKIP("get_kernel_arg_info not implemented");
#endif
  }
  /** // doc: test__get_kernel_arg_info__invalid_arg_index() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_arg_info__invalid_arg_index( )
  {
#if CLXX_B5D_PROVIDES(get_kernel_arg_info)
    T::Dummy_clGetKernelArgInfo mock(CL_INVALID_ARG_INDEX);
    TS_ASSERT_THROWS(get_kernel_arg_info((cl_kernel)NULL, 0, kernel_arg_info_t::name, 0, nullptr, nullptr),clerror_no<status_t::invalid_arg_index>);
#else
    TS_SKIP("get_kernel_arg_info not implemented");
#endif
  }
  /** // doc: test__get_kernel_arg_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_arg_info__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(get_kernel_arg_info)
    T::Dummy_clGetKernelArgInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_kernel_arg_info((cl_kernel)NULL, 0, kernel_arg_info_t::name, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("get_kernel_arg_info not implemented");
#endif
  }
  /** // doc: test__get_kernel_arg_info__kernel_arg_info_not_available() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_arg_info__kernel_arg_info_not_available( )
  {
#if CLXX_B5D_PROVIDES(get_kernel_arg_info)
    T::Dummy_clGetKernelArgInfo mock(CL_KERNEL_ARG_INFO_NOT_AVAILABLE);
    TS_ASSERT_THROWS(get_kernel_arg_info((cl_kernel)NULL, 0, kernel_arg_info_t::name, 0, nullptr, nullptr),clerror_no<status_t::kernel_arg_info_not_available>);
#else
    TS_SKIP("get_kernel_arg_info not implemented");
#endif
  }
  /** // doc: test__get_kernel_arg_info__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_arg_info__invalid_kernel( )
  {
#if CLXX_B5D_PROVIDES(get_kernel_arg_info)
    T::Dummy_clGetKernelArgInfo mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(get_kernel_arg_info((cl_kernel)NULL, 0, kernel_arg_info_t::name, 0, nullptr, nullptr),clerror_no<status_t::invalid_kernel>);
#else
    TS_SKIP("get_kernel_arg_info not implemented");
#endif
  }
  /** // doc: test__get_kernel_arg_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_arg_info__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(get_kernel_arg_info)
    T::Dummy_clGetKernelArgInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_kernel_arg_info((cl_kernel)NULL, 0, kernel_arg_info_t::name, 0, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("get_kernel_arg_info not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_GET_KERNEL_ARG_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4: