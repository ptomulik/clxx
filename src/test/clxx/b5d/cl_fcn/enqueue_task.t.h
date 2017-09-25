// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/enqueue_task.t.h

/** // doc: clxx/b5d/cl_fcn/enqueue_task.t.h {{{
 * \file clxx/b5d/cl_fcn/enqueue_task.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_ENQUEUE_TASK_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_ENQUEUE_TASK_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class enqueue_task_test_suite; }

/** // doc: class clxx::enqueue_task_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::enqueue_task_test_suite : public CxxTest::TestSuite
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
#if CLXX_B5D_PROVIDES(enqueue_task)
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
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__invalid_program_executable() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_program_executable( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
    T::Dummy_clEnqueueTask mock(CL_INVALID_PROGRAM_EXECUTABLE);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_program_executable>);
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
    T::Dummy_clEnqueueTask mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_kernel( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
    T::Dummy_clEnqueueTask mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_kernel>);
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
    T::Dummy_clEnqueueTask mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__invalid_kernel_args() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_kernel_args( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
    T::Dummy_clEnqueueTask mock(CL_INVALID_KERNEL_ARGS);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_kernel_args>);
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__invalid_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_work_group_size( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
    T::Dummy_clEnqueueTask mock(CL_INVALID_WORK_GROUP_SIZE);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_work_group_size>);
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__misaligned_sub_buffer_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__misaligned_sub_buffer_offset( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    T::Dummy_clEnqueueTask mock(CL_MISALIGNED_SUB_BUFFER_OFFSET);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::misaligned_sub_buffer_offset>);
#endif
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__invalid_image_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_image_size( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
    T::Dummy_clEnqueueTask mock(CL_INVALID_IMAGE_SIZE);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_image_size>);
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__invalid_image_format_descriptor() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_image_format_descriptor( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
    T::Dummy_clEnqueueTask mock(CL_INVALID_IMAGE_FORMAT_DESCRIPTOR);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_image_format_descriptor>);
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__mem_object_allocation_failure( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
    T::Dummy_clEnqueueTask mock(CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::mem_object_allocation_failure>);
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__invalid_event_wait_list( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
    T::Dummy_clEnqueueTask mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
    T::Dummy_clEnqueueTask mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
    T::Dummy_clEnqueueTask mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
  /** // doc: test__enqueue_task__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_task__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(enqueue_task)
    T::Dummy_clEnqueueTask mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_task((cl_command_queue)NULL, (cl_kernel)NULL, 0u, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("enqueue_task not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_ENQUEUE_TASK_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
