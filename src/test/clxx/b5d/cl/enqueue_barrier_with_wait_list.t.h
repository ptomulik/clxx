// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/enqueue_barrier_with_wait_list.t.h

/** // doc: clxx/cl/functions/enqueue_barrier_with_wait_list.t.h {{{
 * \file clxx/cl/functions/enqueue_barrier_with_wait_list.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_ENQUEUE_BARRIER_WITH_WAIT_LIST_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_ENQUEUE_BARRIER_WITH_WAIT_LIST_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_barrier_with_wait_list_test_suite; }

/** // doc: class clxx::functions_enqueue_barrier_with_wait_list_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_barrier_with_wait_list_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_barrier_with_wait_list()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_barrier_with_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_barrier_with_wait_list( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueBarrierWithWaitList)
    T::Dummy_clEnqueueBarrierWithWaitList mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_barrier_with_wait_list(
            (cl_command_queue)0x123,
            12u,
            (const cl_event*)0x4321,
            (cl_event*)0x7890
    ));
    TS_ASSERT(mock.called_once_with(
            (cl_command_queue)0x123,
            12u,
            (const cl_event*)0x4321,
            (cl_event*)0x7890
    ));
#endif
  }
  /** // doc: test__enqueue_barrier_with_wait_list__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_barrier_with_wait_list__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueBarrierWithWaitList)
    T::Dummy_clEnqueueBarrierWithWaitList mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_barrier_with_wait_list((cl_command_queue)NULL,0u,(const cl_event*)NULL,(cl_event*)NULL), clerror_no<status_t::invalid_command_queue>);
#endif
  }
  /** // doc: test__enqueue_barrier_with_wait_list__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_barrier_with_wait_list__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueBarrierWithWaitList)
    T::Dummy_clEnqueueBarrierWithWaitList mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_barrier_with_wait_list((cl_command_queue)NULL,0u,(const cl_event*)NULL,(cl_event*)NULL), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__enqueue_barrier_with_wait_list__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_barrier_with_wait_list__invalid_event_wait_list( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueBarrierWithWaitList)
    T::Dummy_clEnqueueBarrierWithWaitList mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_barrier_with_wait_list((cl_command_queue)NULL,0u,(const cl_event*)NULL,(cl_event*)NULL), clerror_no<status_t::invalid_event_wait_list>);
#endif
  }
  /** // doc: test__enqueue_barrier_with_wait_list__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_barrier_with_wait_list__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueBarrierWithWaitList)
    T::Dummy_clEnqueueBarrierWithWaitList mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_barrier_with_wait_list((cl_command_queue)NULL,0u,(const cl_event*)NULL,(cl_event*)NULL), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__enqueue_barrier_with_wait_list__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_barrier_with_wait_list__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueBarrierWithWaitList)
    T::Dummy_clEnqueueBarrierWithWaitList mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_barrier_with_wait_list((cl_command_queue)NULL,0u,(const cl_event*)NULL,(cl_event*)NULL), clerror_no<status_t::out_of_host_memory>);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_ENQUEUE_BARRIER_WITH_WAIT_LIST_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
