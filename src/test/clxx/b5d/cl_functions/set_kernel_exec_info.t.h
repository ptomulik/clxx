// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_functions/set_kernel_exec_info.t.h

/** // doc: clxx/b5d/cl_functions/set_kernel_exec_info.t.h {{{
 * \file clxx/b5d/cl_functions/set_kernel_exec_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FUNCTIONS_SET_KERNEL_EXEC_INFO_T_H_INCLUDED
#define CLXX_B5D_CL_FUNCTIONS_SET_KERNEL_EXEC_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_functions.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class set_kernel_exec_info_test_suite; }

/** // doc: class clxx::set_kernel_exec_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::set_kernel_exec_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  set_kernel_exec_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__set_kernel_exec_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info( )
  {
#if CLXX_B5D_PROVIDES(set_kernel_exec_info)
    T::Dummy_clSetKernelExecInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876));
    TS_ASSERT(mock.called_once_with(              (cl_kernel)NULL, CL_KERNEL_EXEC_INFO_SVM_PTRS, 0x123, (const void*)0x9876));
#else
    TS_SKIP("set_kernel_exec_info not implemented");
#endif
  }
  /** // doc: test__set_kernel_exec_info__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__invalid_kernel( )
  {
#if CLXX_B5D_PROVIDES(set_kernel_exec_info)
    T::Dummy_clSetKernelExecInfo mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_kernel>);
#else
    TS_SKIP("set_kernel_exec_info not implemented");
#endif
  }
  /** // doc: test__set_kernel_exec_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(set_kernel_exec_info)
    T::Dummy_clSetKernelExecInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("set_kernel_exec_info not implemented");
#endif
  }
  /** // doc: test__set_kernel_exec_info__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__invalid_operation( )
  {
#if CLXX_B5D_PROVIDES(set_kernel_exec_info)
    T::Dummy_clSetKernelExecInfo mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_operation>);
#else
    TS_SKIP("set_kernel_exec_info not implemented");
#endif
  }
  /** // doc: test__set_kernel_exec_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(set_kernel_exec_info)
    T::Dummy_clSetKernelExecInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("set_kernel_exec_info not implemented");
#endif
  }
  /** // doc: test__set_kernel_exec_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(set_kernel_exec_info)
    T::Dummy_clSetKernelExecInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("set_kernel_exec_info not implemented");
#endif
  }
  /** // doc: test__set_kernel_exec_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(set_kernel_exec_info)
    T::Dummy_clSetKernelExecInfo mock(-0x12345678);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), unexpected_clerror);
#else
    TS_SKIP("set_kernel_exec_info not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FUNCTIONS_SET_KERNEL_EXEC_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
