// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/enqueue_ndrange_kernel.t.h

/** // doc: clxx/b5d/functions/enqueue_ndrange_kernel.t.h {{{
 * \file clxx/b5d/functions/enqueue_ndrange_kernel.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_ENQUEUE_NDRANGE_KERNEL_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_ENQUEUE_NDRANGE_KERNEL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class enqueue_ndrange_kernel_test_suite; }

/** // doc: class clxx::enqueue_ndrange_kernel_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::enqueue_ndrange_kernel_test_suite : public CxxTest::TestSuite
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
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
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
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__image_format_not_supported() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__image_format_not_supported( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_IMAGE_FORMAT_NOT_SUPPORTED);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::image_format_not_supported>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_event_wait_list( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_global_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_global_offset( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_GLOBAL_OFFSET);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_global_offset>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_global_work_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_global_work_size( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_GLOBAL_WORK_SIZE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_global_work_size>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_image_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_image_size( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_IMAGE_SIZE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_image_size>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_kernel( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_kernel>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_kernel_args() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_kernel_args( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_KERNEL_ARGS);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_kernel_args>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_operation( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_operation>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_program_executable() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_program_executable( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_PROGRAM_EXECUTABLE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_program_executable>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_work_dimension() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_work_dimension( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_WORK_DIMENSION);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_work_dimension>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_work_group_size( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_WORK_GROUP_SIZE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_work_group_size>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__invalid_work_item_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__invalid_work_item_size( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_INVALID_WORK_ITEM_SIZE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_work_item_size>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__mem_object_allocation_failure( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::mem_object_allocation_failure>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__misaligned_sub_buffer_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__misaligned_sub_buffer_offset( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    T::Dummy_clEnqueueNDRangeKernel mock(CL_MISALIGNED_SUB_BUFFER_OFFSET);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::misaligned_sub_buffer_offset>);
#endif
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_ndrange_kernel__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
    T::Dummy_clEnqueueNDRangeKernel mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_ndrange_kernel((cl_command_queue)NULL, (cl_kernel)NULL, 0, nullptr, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("enqueue_ndrange_kernel not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_ENQUEUE_NDRANGE_KERNEL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
