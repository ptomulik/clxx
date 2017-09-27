// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/retain_event.t.h

/** // doc: clxx/b5d/functions/retain_event.t.h {{{
 * \file clxx/b5d/functions/retain_event.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_RETAIN_EVENT_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_RETAIN_EVENT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class retain_event_test_suite; }

/** // doc: class clxx::retain_event_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::retain_event_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  retain_event()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__retain_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_event( )
  {
#if CLXX_B5D_PROVIDES(retain_event)
    T::Dummy_clRetainEvent mock(CL_SUCCESS);
    retain_event                   ((cl_event)0x344);
    TS_ASSERT(mock.called_once_with((cl_event)0x344));
#else
    TS_SKIP("retain_event not implemented");
#endif
  }
  /** // doc: test__retain_event__invalid_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_event__invalid_event( )
  {
#if CLXX_B5D_PROVIDES(retain_event)
    T::Dummy_clRetainEvent mock(CL_INVALID_EVENT);
    TS_ASSERT_THROWS(retain_event((cl_event)NULL),clerror_no<status_t::invalid_event>);
#else
    TS_SKIP("retain_event not implemented");
#endif
  }
  /** // doc: test__retain_event__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_event__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(retain_event)
    T::Dummy_clRetainEvent mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_event((cl_event)NULL),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("retain_event not implemented");
#endif
  }
  /** // doc: test__retain_event__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_event__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(retain_event)
    T::Dummy_clRetainEvent mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_event((cl_event)NULL),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("retain_event not implemented");
#endif
  }
  /** // doc: test__retain_event__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_event__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(retain_event)
    T::Dummy_clRetainEvent mock(-0x1234567);
    TS_ASSERT_THROWS(retain_event((cl_event)NULL), unexpected_clerror);
#else
    TS_SKIP("retain_event not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_RETAIN_EVENT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
