// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/set_event_callback.t.h

/** // doc: clxx/b5d/functions/set_event_callback.t.h {{{
 * \file clxx/b5d/functions/set_event_callback.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_SET_EVENT_CALLBACK_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_SET_EVENT_CALLBACK_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class set_event_callback_test_suite; }

/** // doc: class clxx::set_event_callback_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::set_event_callback_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  set_event_callback()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__set_event_callback() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_event_callback( )
  {
#if CLXX_B5D_PROVIDES(set_event_callback)
    typedef void (CL_CALLBACK* callback_t)(cl_event, cl_int, void*);
    T::Dummy_clSetEventCallback mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_event_callback((cl_event)0x123, CL_SUBMITTED, (callback_t)0x7654, (void*)0x9876));
    TS_ASSERT(mock.called_once_with            ((cl_event)0x123, CL_SUBMITTED, (callback_t)0x7654, (void*)0x9876));
#else
    TS_SKIP("set_event_callback not implemented");
#endif
  }
  /** // doc: test__set_event_callback__invalid_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_event_callback__invalid_event( )
  {
#if CLXX_B5D_PROVIDES(set_event_callback)
    typedef void (CL_CALLBACK* callback_t)(cl_event, cl_int, void*);
    T::Dummy_clSetEventCallback mock(CL_INVALID_EVENT);
    TS_ASSERT_THROWS(set_event_callback((cl_event)0x123, CL_SUBMITTED, (callback_t)0x7654, (void*)0x9876), clerror_no<status_t::invalid_event>);
#else
    TS_SKIP("set_event_callback not implemented");
#endif
  }
  /** // doc: test__set_event_callback__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_event_callback__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(set_event_callback)
    typedef void (CL_CALLBACK* callback_t)(cl_event, cl_int, void*);
    T::Dummy_clSetEventCallback mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(set_event_callback((cl_event)0x123, CL_SUBMITTED, (callback_t)0x7654, (void*)0x9876), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("set_event_callback not implemented");
#endif
  }
  /** // doc: test__set_event_callback__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_event_callback__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(set_event_callback)
    typedef void (CL_CALLBACK* callback_t)(cl_event, cl_int, void*);
    T::Dummy_clSetEventCallback mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(set_event_callback((cl_event)0x123, CL_SUBMITTED, (callback_t)0x7654, (void*)0x9876), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("set_event_callback not implemented");
#endif
  }
  /** // doc: test__set_event_callback__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_event_callback__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(set_event_callback)
    typedef void (CL_CALLBACK* callback_t)(cl_event, cl_int, void*);
    T::Dummy_clSetEventCallback mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(set_event_callback((cl_event)0x123, CL_SUBMITTED, (callback_t)0x7654, (void*)0x9876), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("set_event_callback not implemented");
#endif
  }
  /** // doc: test__set_event_callback__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_event_callback__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(set_event_callback)
    typedef void (CL_CALLBACK* callback_t)(cl_event, cl_int, void*);
    T::Dummy_clSetEventCallback mock(-0x1234567);
    TS_ASSERT_THROWS(set_event_callback((cl_event)0x123, CL_SUBMITTED, (callback_t)0x7654, (void*)0x9876), unexpected_clerror);
#else
    TS_SKIP("set_event_callback not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_SET_EVENT_CALLBACK_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
