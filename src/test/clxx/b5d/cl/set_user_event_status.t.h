// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl/set_user_event_status.t.h

/** // doc: clxx/b5d/cl/set_user_event_status.t.h {{{
 * \file clxx/b5d/cl/set_user_event_status.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_SET_USER_EVENT_STATUS_T_H_INCLUDED
#define CLXX_B5D_CL_SET_USER_EVENT_STATUS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class set_user_event_status_test_suite; }

/** // doc: class clxx::set_user_event_status_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::set_user_event_status_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  set_user_event_status()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__set_user_event_status() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status( )
  {
#if CLXX_B5D_PROVIDES(set_user_event_status)
    T::Dummy_clSetUserEventStatus mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_user_event_status((cl_event)0x123, CL_COMPLETE));
    TS_ASSERT(mock.called_once_with((cl_event)0x123, CL_COMPLETE));
#else
    TS_SKIP("set_user_event_status not implemented");
#endif
  }
  /** // doc: test__set_user_event_status__invalid_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status__invalid_event( )
  {
#if CLXX_B5D_PROVIDES(set_user_event_status)
    T::Dummy_clSetUserEventStatus mock(CL_INVALID_EVENT);
    TS_ASSERT_THROWS(set_user_event_status((cl_event)0, CL_COMPLETE), clerror_no<status_t::invalid_event>);
#else
    TS_SKIP("set_user_event_status not implemented");
#endif
  }
  /** // doc: test__set_user_event_status__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(set_user_event_status)
    T::Dummy_clSetUserEventStatus mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(set_user_event_status((cl_event)0, CL_COMPLETE), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("set_user_event_status not implemented");
#endif
  }
  /** // doc: test__set_user_event_status__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status__invalid_operation( )
  {
#if CLXX_B5D_PROVIDES(set_user_event_status)
    T::Dummy_clSetUserEventStatus mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(set_user_event_status((cl_event)0, CL_COMPLETE), clerror_no<status_t::invalid_operation>);
#else
    TS_SKIP("set_user_event_status not implemented");
#endif
  }
  /** // doc: test__set_user_event_status__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(set_user_event_status)
    T::Dummy_clSetUserEventStatus mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(set_user_event_status((cl_event)0, CL_COMPLETE), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("set_user_event_status not implemented");
#endif
  }
  /** // doc: test__set_user_event_status__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(set_user_event_status)
    T::Dummy_clSetUserEventStatus mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(set_user_event_status((cl_event)0, CL_COMPLETE), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("set_user_event_status not implemented");
#endif
  }
  /** // doc: test__set_user_event_status__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(set_user_event_status)
    T::Dummy_clSetUserEventStatus mock(-0x1234567);
    TS_ASSERT_THROWS(set_user_event_status((cl_event)0, CL_COMPLETE), unexpected_clerror);
#else
    TS_SKIP("set_user_event_status not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_SET_USER_EVENT_STATUS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
