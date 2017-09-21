// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/enqueue_svm_memcpy.t.h

/** // doc: clxx/cl/functions/enqueue_svm_memcpy.t.h {{{
 * \file clxx/cl/functions/enqueue_svm_memcpy.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_ENQUEUE_SVM_MEMCPY_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_ENQUEUE_SVM_MEMCPY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_svm_memcpy_test_suite; }

/** // doc: class clxx::functions_enqueue_svm_memcpy_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_svm_memcpy_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_svm_memcpy()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_svm_memcpy() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_memcpy( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemcpy)
    T::Dummy_clEnqueueSVMMemcpy mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_svm_memcpy(
                                      (cl_command_queue)0x123,
                                      CL_TRUE,
                                      (void*)0x1111,
                                      (const void*)0x2222,
                                      1111ul,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      CL_TRUE,
                                      (void*)0x1111,
                                      (const void*)0x2222,
                                      1111ul,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );
#endif
  }
  /** // doc: test__enqueue_svm_memcpy__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_memcpy__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemcpy)
    T::Dummy_clEnqueueSVMMemcpy mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_svm_memcpy((cl_command_queue)NULL, CL_FALSE, nullptr, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
#endif
  }
  /** // doc: test__enqueue_svm_memcpy__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_memcpy__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemcpy)
    T::Dummy_clEnqueueSVMMemcpy mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_svm_memcpy((cl_command_queue)NULL, CL_FALSE, nullptr, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__enqueue_svm_memcpy__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_memcpy__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemcpy)
    T::Dummy_clEnqueueSVMMemcpy mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_svm_memcpy((cl_command_queue)NULL, CL_FALSE, nullptr, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__enqueue_svm_memcpy__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_memcpy__invalid_event_wait_list( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemcpy)
    T::Dummy_clEnqueueSVMMemcpy mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_svm_memcpy((cl_command_queue)NULL, CL_FALSE, nullptr, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
#endif
  }
  /** // doc: test__enqueue_svm_memcpy__exec_status_error_for_events_in_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_memcpy__exec_status_error_for_events_in_wait_list( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemcpy)
    T::Dummy_clEnqueueSVMMemcpy mock(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_svm_memcpy((cl_command_queue)NULL, CL_FALSE, nullptr, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::exec_status_error_for_events_in_wait_list>);
#endif
  }
  /** // doc: test__enqueue_svm_memcpy__mem_copy_overlap() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_memcpy__mem_copy_overlap( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemcpy)
    T::Dummy_clEnqueueSVMMemcpy mock(CL_MEM_COPY_OVERLAP);
    TS_ASSERT_THROWS(enqueue_svm_memcpy((cl_command_queue)NULL, CL_FALSE, nullptr, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::mem_copy_overlap>);
#endif
  }
  /** // doc: test__enqueue_svm_memcpy__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_memcpy__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemcpy)
    T::Dummy_clEnqueueSVMMemcpy mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_svm_memcpy((cl_command_queue)NULL, CL_FALSE, nullptr, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__enqueue_svm_memcpy__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_memcpy__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemcpy)
    T::Dummy_clEnqueueSVMMemcpy mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_svm_memcpy((cl_command_queue)NULL, CL_FALSE, nullptr, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__enqueue_svm_memcpy__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_memcpy__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMemcpy)
    T::Dummy_clEnqueueSVMMemcpy mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_svm_memcpy((cl_command_queue)NULL, CL_FALSE, nullptr, nullptr, 0ul, 0u, nullptr, nullptr), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_ENQUEUE_SVM_MEMCPY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
