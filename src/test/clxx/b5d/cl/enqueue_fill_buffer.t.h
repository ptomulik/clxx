// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/enqueue_fill_buffer.t.h

/** // doc: clxx/cl/functions/enqueue_fill_buffer.t.h {{{
 * \file clxx/cl/functions/enqueue_fill_buffer.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_ENQUEUE_FILL_BUFFER_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_ENQUEUE_FILL_BUFFER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_fill_buffer_test_suite; }

/** // doc: class clxx::functions_enqueue_fill_buffer_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_fill_buffer_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_fill_buffer()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_fill_buffer() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_buffer( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueFillBuffer)
    T::Dummy_clEnqueueFillBuffer mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_fill_buffer(
                                      (cl_command_queue)0x123,
                                      (cl_mem)0x234,
                                      (const void*)0x789,
                                      123ul,
                                      456ul,
                                      789ul,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      (cl_mem)0x234,
                                      (const void*)0x789,
                                      123ul,
                                      456ul,
                                      789ul,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );
#endif
  }
  /** // doc: test__enqueue_fill_buffer__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_buffer__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueFillBuffer)
    T::Dummy_clEnqueueFillBuffer mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_fill_buffer((cl_command_queue)NULL, (cl_mem)NULL, nullptr, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
#endif
  }
  /** // doc: test__enqueue_fill_buffer__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_buffer__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueFillBuffer)
    T::Dummy_clEnqueueFillBuffer mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_fill_buffer((cl_command_queue)NULL, (cl_mem)NULL, nullptr, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__enqueue_fill_buffer__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_buffer__invalid_mem_object( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueFillBuffer)
    T::Dummy_clEnqueueFillBuffer mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(enqueue_fill_buffer((cl_command_queue)NULL, (cl_mem)NULL, nullptr, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_mem_object>);
#endif
  }
  /** // doc: test__enqueue_fill_buffer__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_buffer__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueFillBuffer)
    T::Dummy_clEnqueueFillBuffer mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_fill_buffer((cl_command_queue)NULL, (cl_mem)NULL, nullptr, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__enqueue_fill_buffer__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_buffer__invalid_event_wait_list( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueFillBuffer)
    T::Dummy_clEnqueueFillBuffer mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_fill_buffer((cl_command_queue)NULL, (cl_mem)NULL, nullptr, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
#endif
  }
  /** // doc: test__enqueue_fill_buffer__misaligned_sub_buffer_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_buffer__misaligned_sub_buffer_offset( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueFillBuffer)
#if CLXX_CL_H_VERSION_1_1
    T::Dummy_clEnqueueFillBuffer mock(CL_MISALIGNED_SUB_BUFFER_OFFSET);
    TS_ASSERT_THROWS(enqueue_fill_buffer((cl_command_queue)NULL, (cl_mem)NULL, nullptr, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::misaligned_sub_buffer_offset>);
#endif
#endif
  }
  /** // doc: test__enqueue_fill_buffer__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_buffer__mem_object_allocation_failure( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueFillBuffer)
    T::Dummy_clEnqueueFillBuffer mock(CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_fill_buffer((cl_command_queue)NULL, (cl_mem)NULL, nullptr, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::mem_object_allocation_failure>);
#endif
  }
  /** // doc: test__enqueue_fill_buffer__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_buffer__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueFillBuffer)
    T::Dummy_clEnqueueFillBuffer mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_fill_buffer((cl_command_queue)NULL, (cl_mem)NULL, nullptr, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__enqueue_fill_buffer__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_buffer__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueFillBuffer)
    T::Dummy_clEnqueueFillBuffer mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_fill_buffer((cl_command_queue)NULL, (cl_mem)NULL, nullptr, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__enqueue_fill_buffer__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_buffer__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueFillBuffer)
    T::Dummy_clEnqueueFillBuffer mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_fill_buffer((cl_command_queue)NULL, (cl_mem)NULL, nullptr, 0ul, 0ul, 0ul, 0u, nullptr, nullptr), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_ENQUEUE_FILL_BUFFER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
