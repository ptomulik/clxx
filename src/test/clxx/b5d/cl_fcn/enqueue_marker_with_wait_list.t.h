// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/enqueue_marker_with_wait_list.t.h

/** // doc: clxx/b5d/cl_fcn/enqueue_marker_with_wait_list.t.h {{{
 * \file clxx/b5d/cl_fcn/enqueue_marker_with_wait_list.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_ENQUEUE_MARKER_WITH_WAIT_LIST_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_ENQUEUE_MARKER_WITH_WAIT_LIST_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class enqueue_marker_with_wait_list_test_suite; }

/** // doc: class clxx::enqueue_marker_with_wait_list_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::enqueue_marker_with_wait_list_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_marker_with_wait_list()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_marker_with_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker_with_wait_list( )
  {
#if CLXX_B5D_PROVIDES(enqueue_marker_with_wait_list)
    T::Dummy_clEnqueueMarkerWithWaitList mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_marker_with_wait_list(
                                                  (cl_command_queue)0x123,
                                                  12u,
                                                  (const cl_event*)0x111,
                                                  (cl_event*)0x901));

    TS_ASSERT(mock.called_once());

    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_command_queue)0x123);
    TS_ASSERT(std::get<1>(mock.calls().back()) == 12u);
    TS_ASSERT(std::get<2>(mock.calls().back()) == (const cl_event*)0x111);
    TS_ASSERT(std::get<3>(mock.calls().back()) == (cl_event*)0x901);
#else
    TS_SKIP("enqueue_marker_with_wait_list not implemented");
#endif
  }
  /** // doc: test__enqueue_marker_with_wait_list__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker_with_wait_list__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(enqueue_marker_with_wait_list)
    T::Dummy_clEnqueueMarkerWithWaitList mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_marker_with_wait_list((cl_command_queue)NULL,0u,nullptr,nullptr), clerror_no<status_t::invalid_command_queue>);
#else
    TS_SKIP("enqueue_marker_with_wait_list not implemented");
#endif
  }
  /** // doc: test__enqueue_marker_with_wait_list__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker_with_wait_list__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(enqueue_marker_with_wait_list)
    T::Dummy_clEnqueueMarkerWithWaitList mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_marker_with_wait_list((cl_command_queue)NULL,0u,nullptr,nullptr), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("enqueue_marker_with_wait_list not implemented");
#endif
  }
  /** // doc: test__enqueue_marker_with_wait_list__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker_with_wait_list__invalid_event_wait_list( )
  {
#if CLXX_B5D_PROVIDES(enqueue_marker_with_wait_list)
    T::Dummy_clEnqueueMarkerWithWaitList mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_marker_with_wait_list((cl_command_queue)NULL,0u,nullptr,nullptr), clerror_no<status_t::invalid_event_wait_list>);
#else
    TS_SKIP("enqueue_marker_with_wait_list not implemented");
#endif
  }
  /** // doc: test__enqueue_marker_with_wait_list__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker_with_wait_list__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(enqueue_marker_with_wait_list)
    T::Dummy_clEnqueueMarkerWithWaitList mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_marker_with_wait_list((cl_command_queue)NULL,0u,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("enqueue_marker_with_wait_list not implemented");
#endif
  }
  /** // doc: test__enqueue_marker_with_wait_list__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker_with_wait_list__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(enqueue_marker_with_wait_list)
    T::Dummy_clEnqueueMarkerWithWaitList mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_marker_with_wait_list((cl_command_queue)NULL,0u,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("enqueue_marker_with_wait_list not implemented");
#endif
  }
  /** // doc: test__enqueue_marker_with_wait_list__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker_with_wait_list__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(enqueue_marker_with_wait_list)
    T::Dummy_clEnqueueMarkerWithWaitList mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_marker_with_wait_list((cl_command_queue)NULL,0u,nullptr,nullptr), unexpected_clerror);
#else
    TS_SKIP("enqueue_marker_with_wait_list not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_ENQUEUE_MARKER_WITH_WAIT_LIST_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
