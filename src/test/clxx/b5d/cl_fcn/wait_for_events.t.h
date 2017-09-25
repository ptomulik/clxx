// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/wait_for_events.t.h

/** // doc: clxx/b5d/cl_fcn/wait_for_events.t.h {{{
 * \file clxx/b5d/cl_fcn/wait_for_events.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_WAIT_FOR_EVENTS_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_WAIT_FOR_EVENTS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class wait_for_events_test_suite; }

/** // doc: class clxx::wait_for_events_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::wait_for_events_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  wait_for_events()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__wait_for_events() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events( )
  {
#if CLXX_B5D_PROVIDES(wait_for_events)
    T::Dummy_clWaitForEvents mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(wait_for_events(0x123, (cl_event const*)0x7654));
    TS_ASSERT(mock.called_once_with(0x123, (cl_event const*)0x7654));
#else
    TS_SKIP("wait_for_events not implemented");
#endif
  }
  /** // doc: test__wait_for_events__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(wait_for_events)
    T::Dummy_clWaitForEvents mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("wait_for_events not implemented");
#endif
  }
  /** // doc: test__wait_for_events__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(wait_for_events)
    T::Dummy_clWaitForEvents mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("wait_for_events not implemented");
#endif
  }
  /** // doc: test__wait_for_events__invalid_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__invalid_event( )
  {
#if CLXX_B5D_PROVIDES(wait_for_events)
    T::Dummy_clWaitForEvents mock(CL_INVALID_EVENT);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), clerror_no<status_t::invalid_event>);
#else
    TS_SKIP("wait_for_events not implemented");
#endif
  }
  /** // doc: test__wait_for_events__exec_status_error_for_events_in_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__exec_status_error_for_events_in_wait_list( )
  {
#if CLXX_B5D_PROVIDES(wait_for_events)
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    T::Dummy_clWaitForEvents mock(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), clerror_no<status_t::exec_status_error_for_events_in_wait_list>);
#endif
#else
    TS_SKIP("wait_for_events not implemented");
#endif
  }
  /** // doc: test__wait_for_events__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(wait_for_events)
    T::Dummy_clWaitForEvents mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("wait_for_events not implemented");
#endif
  }
  /** // doc: test__wait_for_events__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(wait_for_events)
    T::Dummy_clWaitForEvents mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("wait_for_events not implemented");
#endif
  }
  /** // doc: test__wait_for_events__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(wait_for_events)
    T::Dummy_clWaitForEvents mock(-0x1234567);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), unexpected_clerror);
#else
    TS_SKIP("wait_for_events not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_WAIT_FOR_EVENTS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
