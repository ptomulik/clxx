// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/enqueue_wait_for_events.t.h

/** // doc: clxx/cl/functions/enqueue_wait_for_events.t.h {{{
 * \file clxx/cl/functions/enqueue_wait_for_events.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_ENQUEUE_WAIT_FOR_EVENTS_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_ENQUEUE_WAIT_FOR_EVENTS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_wait_for_events_test_suite; }

/** // doc: class clxx::functions_enqueue_wait_for_events_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_wait_for_events_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_wait_for_events()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_wait_for_events() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_wait_for_events( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueWaitForEvents)
    T::Dummy_clEnqueueWaitForEvents mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_wait_for_events(
                                                  (cl_command_queue)0x123,
                                                  12u,
                                                  (const cl_event*)0x111);

    TS_ASSERT(mock.called_once());

    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_command_queue)0x123);
    TS_ASSERT(std::get<1>(mock.calls().back()) == 12u);
    TS_ASSERT(std::get<2>(mock.calls().back()) == (const cl_event*)0x111);
#endif
  }
  /** // doc: test__enqueue_wait_for_events__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_wait_for_events__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueWaitForEvents)
    T::Dummy_clEnqueueWaitForEvents mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_wait_for_events((cl_command_queue)NULL,0u,nullptr), clerror_no<status_t::invalid_command_queue>);
#endif
  }
  /** // doc: test__enqueue_wait_for_events__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_wait_for_events__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueWaitForEvents)
    T::Dummy_clEnqueueWaitForEvents mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_wait_for_events((cl_command_queue)NULL,0u,nullptr), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__enqueue_wait_for_events__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_wait_for_events__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueWaitForEvents)
    T::Dummy_clEnqueueWaitForEvents mock(CL_INVALID_EVENT_VALUE);
    TS_ASSERT_THROWS(enqueue_wait_for_events((cl_command_queue)NULL,0u,nullptr), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__enqueue_wait_for_events__invalid_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_wait_for_events__invalid_event( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueWaitForEvents)
    T::Dummy_clEnqueueWaitForEvents mock(CL_INVALID_EVENT);
    TS_ASSERT_THROWS(enqueue_wait_for_events((cl_command_queue)NULL,0u,nullptr), clerror_no<status_t::invalid_event>);
#endif
  }
  /** // doc: test__enqueue_wait_for_events__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_wait_for_events__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueWaitForEvents)
    T::Dummy_clEnqueueWaitForEvents mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_wait_for_events((cl_command_queue)NULL,0u,nullptr), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__enqueue_wait_for_events__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_wait_for_events__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueWaitForEvents)
    T::Dummy_clEnqueueWaitForEvents mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_wait_for_events((cl_command_queue)NULL,0u,nullptr), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__enqueue_wait_for_events__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_wait_for_events__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueWaitForEvents)
    T::Dummy_clEnqueueWaitForEvents mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_wait_for_events((cl_command_queue)NULL,0u,nullptr), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_ENQUEUE_WAIT_FOR_EVENTS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
