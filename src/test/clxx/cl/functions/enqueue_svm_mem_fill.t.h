// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/enqueue_svm_mem_fill.t.h

/** // doc: clxx/cl/functions/enqueue_svm_mem_fill.t.h {{{
 * \file clxx/cl/functions/enqueue_svm_mem_fill.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_ENQUEUE_SVM_MEM_FILL_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_ENQUEUE_SVM_MEM_FILL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_svm_mem_fill_test_suite; }

/** // doc: class clxx::functions_enqueue_svm_mem_fill_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_svm_mem_fill_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_svm_mem_fill()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_svm_mem_fill() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemFill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_svm_mem_fill(
                                      (cl_command_queue)0x123,
                                      (void*)0x1111,
                                      (const void*)0x2222,
                                      2222ul,
                                      1111ul,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      (void*)0x1111,
                                      (const void*)0x2222,
                                      2222ul,
                                      1111ul,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemFill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemFill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemFill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__invalid_event_wait_list( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemFill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemFill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemFill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemFill)
    T::Dummy_clEnqueueSVMMemFill mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_ENQUEUE_SVM_MEM_FILL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
