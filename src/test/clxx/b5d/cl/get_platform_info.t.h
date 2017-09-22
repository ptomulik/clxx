// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl/get_platform_info.t.h

/** // doc: clxx/b5d/cl/get_platform_info.t.h {{{
 * \file clxx/b5d/cl/get_platform_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_GET_PLATFORM_INFO_T_H_INCLUDED
#define CLXX_B5D_CL_GET_PLATFORM_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class get_platform_info_test_suite; }

/** // doc: class clxx::get_platform_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::get_platform_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_platform_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_platform_info() {{{
   * \brief Test get_platform_info()
   */ // }}}
  void test__get_platform_info( )
  {
#if CLXX_B5D_PROVIDES(get_platform_info)
    T::Dummy_clGetPlatformInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_platform_id)NULL, (cl_platform_info)0, 0, nullptr, nullptr));
#else
    TS_SKIP("get_platform_info not implemented");
#endif
  }
  /** // doc: test__get_platform_info__invalid_platform() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_INVALID_PLATFORM
   */ // }}}
  void test__get_platform_info__invalid_platform( )
  {
#if CLXX_B5D_PROVIDES(get_platform_info)
    T::Dummy_clGetPlatformInfo mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), clerror_no<status_t::invalid_platform>);
#else
    TS_SKIP("get_platform_info not implemented");
#endif
  }
  /** // doc: test__get_platform_info__invalid_value() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_platform_info__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(get_platform_info)
    T::Dummy_clGetPlatformInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("get_platform_info not implemented");
#endif
  }
  /** // doc: test__get_platform_info__out_of_host_memory() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_platform_info__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(get_platform_info)
    T::Dummy_clGetPlatformInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("get_platform_info not implemented");
#endif
  }
  /** // doc: test__get_platform_info__other_error() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_platform_info__other_error( )
  {
#if CLXX_B5D_PROVIDES(get_platform_info)
    T::Dummy_clGetPlatformInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("get_platform_info not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_GET_PLATFORM_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
