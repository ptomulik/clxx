// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/create_user_event.t.h

/** // doc: clxx/b5d/cl_fcn/create_user_event.t.h {{{
 * \file clxx/b5d/cl_fcn/create_user_event.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_CREATE_USER_EVENT_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_CREATE_USER_EVENT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class create_user_event_test_suite; }

/** // doc: class clxx::create_user_event_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::create_user_event_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  create_user_event()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_user_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_user_event( )
  {
#if CLXX_B5D_PROVIDES(create_user_event)
    T::Dummy_clCreateUserEvent mock((cl_event)0x1234, CL_SUCCESS);
    TS_ASSERT(create_user_event((cl_context)0x7654) == (cl_event)0x1234);
    TS_ASSERT(mock.called_once());
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x7654);
#else
    TS_SKIP("create_user_event not implemented");
#endif
  }
  /** // doc: test__create_user_event__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_user_event__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(create_user_event)
    T::Dummy_clCreateUserEvent mock((cl_event)0x1234, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_user_event((cl_context)0), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("create_user_event not implemented");
#endif
  }
  /** // doc: test__create_user_event__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_user_event__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(create_user_event)
    T::Dummy_clCreateUserEvent mock((cl_event)0x1234, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_user_event((cl_context)0), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("create_user_event not implemented");
#endif
  }
  /** // doc: test__create_user_event__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_user_event__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(create_user_event)
    T::Dummy_clCreateUserEvent mock((cl_event)0x1234, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_user_event((cl_context)0), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("create_user_event not implemented");
#endif
  }
  /** // doc: test__create_user_event__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_user_event__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(create_user_event)
    T::Dummy_clCreateUserEvent mock((cl_event)0x1234, -0x1234567);
    TS_ASSERT_THROWS(create_user_event((cl_context)0), unexpected_clerror);
#else
    TS_SKIP("create_user_event not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_CREATE_USER_EVENT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
