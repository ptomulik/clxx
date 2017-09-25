// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/set_kernel_arg_svm_pointer.t.h

/** // doc: clxx/b5d/cl_fcn/set_kernel_arg_svm_pointer.t.h {{{
 * \file clxx/b5d/cl_fcn/set_kernel_arg_svm_pointer.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_SET_KERNEL_ARG_SVM_POINTER_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_SET_KERNEL_ARG_SVM_POINTER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class set_kernel_arg_svm_pointer_test_suite; }

/** // doc: class clxx::set_kernel_arg_svm_pointer_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::set_kernel_arg_svm_pointer_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  set_kernel_arg_svm_pointer()
  ////////////////////////////////////////////////////////////////////////////
  /** // doc: test__set_kernel_arg_svm_pointer() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer( )
  {
#if CLXX_B5D_PROVIDES(set_kernel_arg_svm_pointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876));
    TS_ASSERT(mock.called_once_with(                    (cl_kernel)NULL, 0x123, (const void*)0x9876));
#else
    TS_SKIP("set_kernel_arg_svm_pointer not implemented");
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__invalid_kernel( )
  {
#if CLXX_B5D_PROVIDES(set_kernel_arg_svm_pointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_kernel>);
#else
    TS_SKIP("set_kernel_arg_svm_pointer not implemented");
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__invalid_arg_index() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__invalid_arg_index( )
  {
#if CLXX_B5D_PROVIDES(set_kernel_arg_svm_pointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_INVALID_ARG_INDEX);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_arg_index>);
#else
    TS_SKIP("set_kernel_arg_svm_pointer not implemented");
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__invalid_arg_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__invalid_arg_value( )
  {
#if CLXX_B5D_PROVIDES(set_kernel_arg_svm_pointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_INVALID_ARG_VALUE);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_arg_value>);
#else
    TS_SKIP("set_kernel_arg_svm_pointer not implemented");
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(set_kernel_arg_svm_pointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("set_kernel_arg_svm_pointer not implemented");
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(set_kernel_arg_svm_pointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("set_kernel_arg_svm_pointer not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_SET_KERNEL_ARG_SVM_POINTER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
