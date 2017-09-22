// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl/get_context_info.t.h

/** // doc: clxx/b5d/cl/get_context_info.t.h {{{
 * \file clxx/b5d/cl/get_context_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_GET_CONTEXT_INFO_T_H_INCLUDED
#define CLXX_B5D_CL_GET_CONTEXT_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class get_context_info_test_suite; }

/** // doc: class clxx::get_context_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::get_context_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_context_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_context_info() {{{
   * \brief Test get_context_info() in a normal situation
   */ // }}}
  void test__get_context_info( )
  {
#if CLXX_B5D_PROVIDES(get_context_info)
    T::Dummy_clGetContextInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_context)NULL, CL_CONTEXT_REFERENCE_COUNT, 0, nullptr, nullptr));
#else
    TS_SKIP("get_context_info not implemented");
#endif
  }
  /** // doc: test__get_context_info__invalid_context() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__get_context_info__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(get_context_info)
    T::Dummy_clGetContextInfo mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("get_context_info not implemented");
#endif
  }
  /** // doc: test__get_context_info__invalid_value() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_context_info__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(get_context_info)
    T::Dummy_clGetContextInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("get_context_info not implemented");
#endif
  }
  /** // doc: test__get_context_info__out_of_resources() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__get_context_info__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(get_context_info)
    T::Dummy_clGetContextInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("get_context_info not implemented");
#endif
  }
  /** // doc: test__get_context_info__out_of_host_memory() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_context_info__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(get_context_info)
    T::Dummy_clGetContextInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("get_context_info not implemented");
#endif
  }
  /** // doc: test__get_context_info__other_error() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns an unexpected error code.
   */ // }}}
  void test__get_context_info__other_error( )
  {
#if CLXX_B5D_PROVIDES(get_context_info)
    T::Dummy_clGetContextInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("get_context_info not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_GET_CONTEXT_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
