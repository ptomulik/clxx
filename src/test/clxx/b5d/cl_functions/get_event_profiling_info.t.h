// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_functions/get_event_profiling_info.t.h

/** // doc: clxx/b5d/cl_functions/get_event_profiling_info.t.h {{{
 * \file clxx/b5d/cl_functions/get_event_profiling_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FUNCTIONS_GET_EVENT_PROFILING_INFO_T_H_INCLUDED
#define CLXX_B5D_CL_FUNCTIONS_GET_EVENT_PROFILING_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_functions.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class get_event_profiling_info_test_suite; }

/** // doc: class clxx::get_event_profiling_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::get_event_profiling_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_event_profiling_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_event_profiling_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_event_profiling_info( )
  {
#if CLXX_B5D_PROVIDES(get_event_profiling_info)
    T::Dummy_clGetEventProfilingInfo mock(CL_SUCCESS);
    get_event_profiling_info                ((cl_event)0x395, profiling_info_t::start,            5, (void*)0x124, (size_t*)0x934);
    TS_ASSERT(mock.called_once_with((cl_event)0x395, (cl_profiling_info)CL_PROFILING_COMMAND_START, 5, (void*)0x124, (size_t*)0x934));
#else
    TS_SKIP("get_event_profiling_info not implemented");
#endif
  }
  /** // doc: test__get_event_profiling_info__profiling_info_not_available() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_event_profiling_info__profiling_info_not_available( )
  {
#if CLXX_B5D_PROVIDES(get_event_profiling_info)
    T::Dummy_clGetEventProfilingInfo mock(CL_PROFILING_INFO_NOT_AVAILABLE);
    TS_ASSERT_THROWS(get_event_profiling_info((cl_event)NULL, profiling_info_t::start, 0, nullptr, nullptr),clerror_no<status_t::profiling_info_not_available>);
#else
    TS_SKIP("get_event_profiling_info not implemented");
#endif
  }
  /** // doc: test__get_event_profiling_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_event_profiling_info__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(get_event_profiling_info)
    T::Dummy_clGetEventProfilingInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_event_profiling_info((cl_event)NULL, profiling_info_t::start, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("get_event_profiling_info not implemented");
#endif
  }
  /** // doc: test__get_event_profiling_info__invalid_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_event_profiling_info__invalid_event( )
  {
#if CLXX_B5D_PROVIDES(get_event_profiling_info)
    T::Dummy_clGetEventProfilingInfo mock(CL_INVALID_EVENT);
    TS_ASSERT_THROWS(get_event_profiling_info((cl_event)NULL, profiling_info_t::start, 0, nullptr, nullptr),clerror_no<status_t::invalid_event>);
#else
    TS_SKIP("get_event_profiling_info not implemented");
#endif
  }
  /** // doc: test__get_event_profiling_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_event_profiling_info__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(get_event_profiling_info)
    T::Dummy_clGetEventProfilingInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_event_profiling_info((cl_event)NULL, profiling_info_t::start, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("get_event_profiling_info not implemented");
#endif
  }
  /** // doc: test__get_event_profiling_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_event_profiling_info__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(get_event_profiling_info)
    T::Dummy_clGetEventProfilingInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_event_profiling_info((cl_event)NULL, profiling_info_t::start, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("get_event_profiling_info not implemented");
#endif
  }
  /** // doc: test__get_event_profiling_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_event_profiling_info__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(get_event_profiling_info)
    T::Dummy_clGetEventProfilingInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_event_profiling_info((cl_event)NULL, profiling_info_t::start, 0, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("get_event_profiling_info not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FUNCTIONS_GET_EVENT_PROFILING_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
