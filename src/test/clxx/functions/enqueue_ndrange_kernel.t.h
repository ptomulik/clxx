// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/enqueue_ndrange_kernel.t.h

/** // doc: clxx/functions/enqueue_ndrange_kernel.t.h {{{
 * \file clxx/functions/enqueue_ndrange_kernel.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_ENQUEUE_NDRANGE_KERNEL_T_H_INCLUDED
#define CLXX_FUNCTIONS_ENQUEUE_NDRANGE_KERNEL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_ndrange_kernel_test_suite; }

/** // doc: class clxx::functions_enqueue_ndrange_kernel_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_ndrange_kernel_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_ndrange_kernel()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_ndrange_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_ndrange_kernel(
                                      (cl_command_queue)0x123,
                                      (cl_kernel)0x234,
                                      0x345,
                                      (const size_t*)0x456,
                                      (const size_t*)0x567,
                                      (const size_t*)0x678,
                                      0x789,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      (cl_kernel)0x234,
                                      0x345,
                                      (const size_t*)0x456,
                                      (const size_t*)0x567,
                                      (const size_t*)0x678,
                                      0x789,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );
  }
  /** // doc: test__enqueue_ndrange_kernel__image_format_not_supported() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__image_format_not_supported( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_IMAGE_FORMAT_NOT_SUPPORTED);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::image_format_not_supported>);
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_command_queue( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_context( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_event_wait_list( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_global_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_global_offset( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_GLOBAL_OFFSET);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_global_offset>);
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_global_work_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_global_work_size( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_GLOBAL_WORK_SIZE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_global_work_size>);
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_image_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_image_size( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_IMAGE_SIZE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_image_size>);
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_kernel( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_kernel>);
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_kernel_args() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_kernel_args( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_KERNEL_ARGS);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_kernel_args>);
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_operation( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_operation>);
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_program_executable() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_program_executable( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_PROGRAM_EXECUTABLE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_program_executable>);
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_work_dimension() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_work_dimension( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_WORK_DIMENSION);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_work_dimension>);
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_work_group_size( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_WORK_GROUP_SIZE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_work_group_size>);
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_work_item_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_work_item_size( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_WORK_ITEM_SIZE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_work_item_size>);
  }
  /** // doc: test__enqueue_ndrange_kernel__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__mem_object_allocation_failure( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::mem_object_allocation_failure>);
  }
  /** // doc: test__enqueue_ndrange_kernel__misaligned_sub_buffer_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__misaligned_sub_buffer_offset( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_MISALIGNED_SUB_BUFFER_OFFSET);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::misaligned_sub_buffer_offset>);
  }
  /** // doc: test__enqueue_ndrange_kernel__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__out_of_host_memory( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__enqueue_ndrange_kernel__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__out_of_resources( )
  {
    T::Dummy_clEnqueueNDRangeKernel mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
};

#endif /* CLXX_FUNCTIONS_ENQUEUE_NDRANGE_KERNEL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
