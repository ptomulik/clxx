// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/get_program_build_info.t.h

/** // doc: clxx/b5d/functions/get_program_build_info.t.h {{{
 * \file clxx/b5d/functions/get_program_build_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_GET_PROGRAM_BUILD_INFO_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_GET_PROGRAM_BUILD_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class get_program_build_info_test_suite; }

/** // doc: class clxx::get_program_build_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::get_program_build_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_program_build_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_program_build_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info( )
  {
#if CLXX_B5D_PROVIDES(get_program_build_info)
    T::Dummy_clGetProgramBuildInfo mock(CL_SUCCESS);
    get_program_build_info         ((cl_program)0x253, (cl_device_id)0x563, program_build_info_t::status,                   4, (void*)0x973, (size_t*)0x938);
    TS_ASSERT(mock.called_once_with((cl_program)0x253, (cl_device_id)0x563, (cl_program_build_info)CL_PROGRAM_BUILD_STATUS, 4, (void*)0x973, (size_t*)0x938));
#else
    TS_SKIP("get_program_build_info not implemented");
#endif
  }
  /** // doc: test__get_program_build_info__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info__invalid_device( )
  {
#if CLXX_B5D_PROVIDES(get_program_build_info)
    T::Dummy_clGetProgramBuildInfo mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::invalid_device>);
#else
    TS_SKIP("get_program_build_info not implemented");
#endif
  }
  /** // doc: test__get_program_build_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(get_program_build_info)
    T::Dummy_clGetProgramBuildInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("get_program_build_info not implemented");
#endif
  }
  /** // doc: test__get_program_build_info__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info__invalid_program( )
  {
#if CLXX_B5D_PROVIDES(get_program_build_info)
    T::Dummy_clGetProgramBuildInfo mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::invalid_program>);
#else
    TS_SKIP("get_program_build_info not implemented");
#endif
  }
  /** // doc: test__get_program_build_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(get_program_build_info)
    T::Dummy_clGetProgramBuildInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("get_program_build_info not implemented");
#endif
  }
  /** // doc: test__get_program_build_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(get_program_build_info)
    T::Dummy_clGetProgramBuildInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("get_program_build_info not implemented");
#endif
  }
  /** // doc: test__get_program_build_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(get_program_build_info)
    T::Dummy_clGetProgramBuildInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("get_program_build_info not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_GET_PROGRAM_BUILD_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
