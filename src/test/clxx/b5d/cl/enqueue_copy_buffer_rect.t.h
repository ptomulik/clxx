// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/enqueue_copy_buffer_rect.t.h

/** // doc: clxx/cl/functions/enqueue_copy_buffer_rect.t.h {{{
 * \file clxx/cl/functions/enqueue_copy_buffer_rect.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_ENQUEUE_COPY_BUFFER_RECT_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_ENQUEUE_COPY_BUFFER_RECT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_copy_buffer_rect_test_suite; }

/** // doc: class clxx::functions_enqueue_copy_buffer_rect_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_copy_buffer_rect_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_copy_buffer_rect()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_copy_buffer_rect() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_rect( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueCopyBufferRect)
    T::Dummy_clEnqueueCopyBufferRect mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_copy_buffer_rect(
                                      (cl_command_queue)0x123,
                                      (cl_mem)0x234,
                                      (cl_mem)0x567,
                                      (const size_t*)0x111,
                                      (const size_t*)0x222,
                                      (const size_t*)0x333,
                                      (size_t)1ul,
                                      (size_t)2ul,
                                      (size_t)3ul,
                                      (size_t)4ul,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      (cl_mem)0x234,
                                      (cl_mem)0x567,
                                      (const size_t*)0x111,
                                      (const size_t*)0x222,
                                      (const size_t*)0x333,
                                      (size_t)1ul,
                                      (size_t)2ul,
                                      (size_t)3ul,
                                      (size_t)4ul,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );
#endif
  }
  /** // doc: test__enqueue_copy_buffer_rect__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_rect__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueCopyBufferRect)
    T::Dummy_clEnqueueCopyBufferRect mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_copy_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
#endif
  }
  /** // doc: test__enqueue_copy_buffer_rect__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_rect__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueCopyBufferRect)
    T::Dummy_clEnqueueCopyBufferRect mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_copy_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__enqueue_copy_buffer_rect__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_rect__invalid_mem_object( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueCopyBufferRect)
    T::Dummy_clEnqueueCopyBufferRect mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(enqueue_copy_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_mem_object>);
#endif
  }
  /** // doc: test__enqueue_copy_buffer_rect__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_rect__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueCopyBufferRect)
    T::Dummy_clEnqueueCopyBufferRect mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_copy_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__enqueue_copy_buffer_rect__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_rect__invalid_event_wait_list( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueCopyBufferRect)
    T::Dummy_clEnqueueCopyBufferRect mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_copy_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
#endif
  }
  /** // doc: test__enqueue_copy_buffer_rect__misaligned_sub_buffer_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_rect__misaligned_sub_buffer_offset( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueCopyBufferRect)
#if CLXX_CL_H_VERSION_1_1
    T::Dummy_clEnqueueCopyBufferRect mock(CL_MISALIGNED_SUB_BUFFER_OFFSET);
    TS_ASSERT_THROWS(enqueue_copy_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::misaligned_sub_buffer_offset>);
#endif
#endif
  }
  /** // doc: test__enqueue_copy_buffer_rect__mem_copy_overlap() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_rect__mem_copy_overlap( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueCopyBufferRect)
    T::Dummy_clEnqueueCopyBufferRect mock(CL_MEM_COPY_OVERLAP);
    TS_ASSERT_THROWS(enqueue_copy_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::mem_copy_overlap>);
#endif
  }
  /** // doc: test__enqueue_copy_buffer_rect__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_rect__mem_object_allocation_failure( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueCopyBufferRect)
    T::Dummy_clEnqueueCopyBufferRect mock(CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_copy_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::mem_object_allocation_failure>);
#endif
  }
  /** // doc: test__enqueue_copy_buffer_rect__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_rect__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueCopyBufferRect)
    T::Dummy_clEnqueueCopyBufferRect mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_copy_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__enqueue_copy_buffer_rect__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_rect__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueCopyBufferRect)
    T::Dummy_clEnqueueCopyBufferRect mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_copy_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_ENQUEUE_COPY_BUFFER_RECT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
