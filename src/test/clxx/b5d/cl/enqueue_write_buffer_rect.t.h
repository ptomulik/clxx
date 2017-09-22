// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl/enqueue_write_buffer_rect.t.h

/** // doc: clxx/b5d/cl/enqueue_write_buffer_rect.t.h {{{
 * \file clxx/b5d/cl/enqueue_write_buffer_rect.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_ENQUEUE_WRITE_BUFFER_RECT_T_H_INCLUDED
#define CLXX_B5D_CL_ENQUEUE_WRITE_BUFFER_RECT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class enqueue_write_buffer_rect_test_suite; }

/** // doc: class clxx::enqueue_write_buffer_rect_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::enqueue_write_buffer_rect_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_write_buffer_rect()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_write_buffer_rect() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_rect( )
  {
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
    T::Dummy_clEnqueueWriteBufferRect mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_write_buffer_rect(
                                      (cl_command_queue)0x123,
                                      (cl_mem)0x234,
                                      (cl_bool)1,
                                      (const size_t*)0x111,
                                      (const size_t*)0x222,
                                      (const size_t*)0x333,
                                      11ul,
                                      22ul,
                                      33ul,
                                      44ul,
                                      (const void*)0x678,
                                      789ul,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      (cl_mem)0x234,
                                      (cl_bool)1,
                                      (const size_t*)0x111,
                                      (const size_t*)0x222,
                                      (const size_t*)0x333,
                                      11ul,
                                      22ul,
                                      33ul,
                                      44ul,
                                      (const void*)0x678,
                                      789ul,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );
#else
    TS_SKIP("enqueue_write_buffer_rect not implemented");
#endif
  }
  /** // doc: test__enqueue_write_buffer_rect__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_rect__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
    T::Dummy_clEnqueueWriteBufferRect mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_write_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
#else
    TS_SKIP("enqueue_write_buffer_rect not implemented");
#endif
  }
  /** // doc: test__enqueue_write_buffer_rect__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_rect__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
    T::Dummy_clEnqueueWriteBufferRect mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_write_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("enqueue_write_buffer_rect not implemented");
#endif
  }
  /** // doc: test__enqueue_write_buffer_rect__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_rect__invalid_mem_object( )
  {
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
    T::Dummy_clEnqueueWriteBufferRect mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(enqueue_write_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_mem_object>);
#else
    TS_SKIP("enqueue_write_buffer_rect not implemented");
#endif
  }
  /** // doc: test__enqueue_write_buffer_rect__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_rect__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
    T::Dummy_clEnqueueWriteBufferRect mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_write_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("enqueue_write_buffer_rect not implemented");
#endif
  }
  /** // doc: test__enqueue_write_buffer_rect__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_rect__invalid_event_wait_list( )
  {
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
    T::Dummy_clEnqueueWriteBufferRect mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_write_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
#else
    TS_SKIP("enqueue_write_buffer_rect not implemented");
#endif
  }
  /** // doc: test__enqueue_write_buffer_rect__misaligned_sub_buffer_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_rect__misaligned_sub_buffer_offset( )
  {
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    T::Dummy_clEnqueueWriteBufferRect mock(CL_MISALIGNED_SUB_BUFFER_OFFSET);
    TS_ASSERT_THROWS(enqueue_write_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::misaligned_sub_buffer_offset>);
#endif
#else
    TS_SKIP("enqueue_write_buffer_rect not implemented");
#endif
  }
  /** // doc: test__enqueue_write_buffer_rect__exec_status_error_for_events_in_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_rect__exec_status_error_for_events_in_wait_list( )
  {
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    T::Dummy_clEnqueueWriteBufferRect mock(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_write_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::exec_status_error_for_events_in_wait_list>);
#endif
#else
    TS_SKIP("enqueue_write_buffer_rect not implemented");
#endif
  }
  /** // doc: test__enqueue_write_buffer_rect__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_rect__mem_object_allocation_failure( )
  {
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
    T::Dummy_clEnqueueWriteBufferRect mock(CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_write_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::mem_object_allocation_failure>);
#else
    TS_SKIP("enqueue_write_buffer_rect not implemented");
#endif
  }
  /** // doc: test__enqueue_write_buffer_rect__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_rect__invalid_operation( )
  {
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
    T::Dummy_clEnqueueWriteBufferRect mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(enqueue_write_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_operation>);
#else
    TS_SKIP("enqueue_write_buffer_rect not implemented");
#endif
  }
  /** // doc: test__enqueue_write_buffer_rect__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_rect__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
    T::Dummy_clEnqueueWriteBufferRect mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_write_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("enqueue_write_buffer_rect not implemented");
#endif
  }
  /** // doc: test__enqueue_write_buffer_rect__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_rect__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
    T::Dummy_clEnqueueWriteBufferRect mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_write_buffer_rect((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, nullptr, 0ul, 0ul, 0ul, 0ul, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("enqueue_write_buffer_rect not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_ENQUEUE_WRITE_BUFFER_RECT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
