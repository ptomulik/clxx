// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/enqueue_svm_map.t.h

/** // doc: clxx/cl/functions/enqueue_svm_map.t.h {{{
 * \file clxx/cl/functions/enqueue_svm_map.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_ENQUEUE_SVM_MAP_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_ENQUEUE_SVM_MAP_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_svm_map_test_suite; }

/** // doc: class clxx::functions_enqueue_svm_map_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_svm_map_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_svm_map()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_svm_map() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_map( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMap)
    T::Dummy_clEnqueueSVMMap mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_svm_map(
                                      (cl_command_queue)0x123,
                                      CL_TRUE,
                                      map_flags_t::read,
                                      (void*)0x1111,
                                      1111ul,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      CL_TRUE,
                                      CL_MAP_READ,
                                      (void*)0x1111,
                                      1111ul,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );
#endif
  }
  /** // doc: test__enqueue_svm_map__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_map__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMap)
    T::Dummy_clEnqueueSVMMap mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_svm_map((cl_command_queue)NULL, CL_FALSE, map_flags_t::none, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
#endif
  }
  /** // doc: test__enqueue_svm_map__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_map__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMap)
    T::Dummy_clEnqueueSVMMap mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_svm_map((cl_command_queue)NULL, CL_FALSE, map_flags_t::none, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__enqueue_svm_map__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_map__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMap)
    T::Dummy_clEnqueueSVMMap mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_svm_map((cl_command_queue)NULL, CL_FALSE, map_flags_t::none, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__enqueue_svm_map__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_map__invalid_event_wait_list( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMap)
    T::Dummy_clEnqueueSVMMap mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_svm_map((cl_command_queue)NULL, CL_FALSE, map_flags_t::none, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
#endif
  }
  /** // doc: test__enqueue_svm_map__exec_status_error_for_events_in_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_map__exec_status_error_for_events_in_wait_list( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMap)
    T::Dummy_clEnqueueSVMMap mock(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_svm_map((cl_command_queue)NULL, CL_FALSE, map_flags_t::none, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::exec_status_error_for_events_in_wait_list>);
#endif
  }
  /** // doc: test__enqueue_svm_map__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_map__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMap)
    T::Dummy_clEnqueueSVMMap mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_svm_map((cl_command_queue)NULL, CL_FALSE, map_flags_t::none, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__enqueue_svm_map__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_map__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMap)
    T::Dummy_clEnqueueSVMMap mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_svm_map((cl_command_queue)NULL, CL_FALSE, map_flags_t::none, nullptr, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__enqueue_svm_map__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_map__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueSVMMap)
    T::Dummy_clEnqueueSVMMap mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_svm_map((cl_command_queue)NULL, CL_FALSE, map_flags_t::none, nullptr, 0ul, 0u, nullptr, nullptr), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_ENQUEUE_SVM_MAP_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
