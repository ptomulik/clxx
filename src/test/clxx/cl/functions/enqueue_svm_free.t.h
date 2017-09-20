// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/enqueue_svm_free.t.h

/** // doc: clxx/cl/functions/enqueue_svm_free.t.h {{{
 * \file clxx/cl/functions/enqueue_svm_free.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_ENQUEUE_SVM_FREE_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_ENQUEUE_SVM_FREE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_svm_free_test_suite; }

/** // doc: class clxx::functions_enqueue_svm_free_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_svm_free_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_svm_free()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_svm_free() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_free( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMFree)
    typedef void (CL_CALLBACK* callback_t)(cl_command_queue,cl_uint,void*[],void*);
    T::Dummy_clEnqueueSVMFree mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(enqueue_svm_free((cl_command_queue)0x123, 111u, (void**)0x1111, (callback_t)0x7654, (void*)0x9876, 222u, (const cl_event*)0x222, (cl_event*)0x333));
    TS_ASSERT(mock.called_once_with((cl_command_queue)0x123, 111u, (void**)0x1111, (callback_t)0x7654, (void*)0x9876, 222u, (const cl_event*)0x222, (cl_event*)0x333));
#endif
  }
//  /** // doc: test__enqueue_svm_free__invalid_command_queue() {{{
//   * \todo Write documentation
//   */ // }}}
  void test__enqueue_svm_free__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMFree)
    T::Dummy_clEnqueueSVMFree mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_svm_free((cl_command_queue)NULL, 0u, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
#endif
  }
  /** // doc: test__enqueue_svm_free__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_free__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMFree)
    T::Dummy_clEnqueueSVMFree mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_svm_free((cl_command_queue)NULL, 0u, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__enqueue_svm_free__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_free__invalid_event_wait_list( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMFree)
    T::Dummy_clEnqueueSVMFree mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_svm_free((cl_command_queue)NULL, 0u, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
#endif
  }
  /** // doc: test__enqueue_svm_free__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_free__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMFree)
    T::Dummy_clEnqueueSVMFree mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_svm_free((cl_command_queue)NULL, 0u, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__enqueue_svm_free__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_free__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMFree)
    T::Dummy_clEnqueueSVMFree mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_svm_free((cl_command_queue)NULL, 0u, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__enqueue_svm_free__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_free__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMFree)
    T::Dummy_clEnqueueSVMFree mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_svm_free((cl_command_queue)NULL, 0u, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_ENQUEUE_SVM_FREE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
