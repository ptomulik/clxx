// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/enqueue_task.t.h

/** // doc: clxx/cl/functions/enqueue_task.t.h {{{
 * \file clxx/cl/functions/enqueue_task.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_ENQUEUE_TASK_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_ENQUEUE_TASK_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_task_test_suite; }

/** // doc: class clxx::functions_enqueue_task_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_task_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_task()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_task() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_task(
                                      (cl_command_queue)0x123,
                                      (cl_kernel)0x234,
                                      789ul,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      (cl_kernel)0x234,
                                      789ul,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );
#endif
  }
  /** // doc: test__enqueue_task__invalid_program_executable() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_program_executable( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_INVALID_PROGRAM_EXECUTABLE);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_program_executable>);
#endif
  }
  /** // doc: test__enqueue_task__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
#endif
  }
  /** // doc: test__enqueue_task__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_kernel( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_kernel>);
#endif
  }
  /** // doc: test__enqueue_task__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__enqueue_task__invalid_kernel_args() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_kernel_args( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_INVALID_KERNEL_ARGS);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_kernel_args>);
#endif
  }
  /** // doc: test__enqueue_task__invalid_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_work_group_size( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_INVALID_WORK_GROUP_SIZE);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_work_group_size>);
#endif
  }
  /** // doc: test__enqueue_task__misaligned_sub_buffer_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__misaligned_sub_buffer_offset( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_MISALIGNED_SUB_BUFFER_OFFSET);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::misaligned_sub_buffer_offset>);
#endif
  }
  /** // doc: test__enqueue_task__invalid_image_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_image_size( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_INVALID_IMAGE_SIZE);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_image_size>);
#endif
  }
  /** // doc: test__enqueue_task__invalid_image_format_descriptor() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_image_format_descriptor( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_INVALID_IMAGE_FORMAT_DESCRIPTOR);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_image_format_descriptor>);
#endif
  }
  /** // doc: test__enqueue_task__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__mem_object_allocation_failure( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::mem_object_allocation_failure>);
#endif
  }
  /** // doc: test__enqueue_task__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_event_wait_list( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
#endif
  }
  /** // doc: test__enqueue_task__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__enqueue_task__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__enqueue_task__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueTask)
    T::Dummy_clEnqueueTask mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_ENQUEUE_TASK_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
