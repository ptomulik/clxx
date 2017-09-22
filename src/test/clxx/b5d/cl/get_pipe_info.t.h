// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/get_pipe_info.t.h

/** // doc: clxx/cl/functions/get_pipe_info.t.h {{{
 * \file clxx/cl/functions/get_pipe_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_GET_PIPE_INFO_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_GET_PIPE_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_get_pipe_info_test_suite; }

/** // doc: class clxx::functions_get_pipe_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_get_pipe_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_pipe_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_pipe_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_pipe_info( )
  {
#if CLXX_OPENCL_ALLOWED(clGetPipeInfo)
    T::Dummy_clGetPipeInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_pipe_info((cl_mem)0x395, pipe_info_t::packet_size,  5, (void*)0x124, (size_t*)0x934));
    TS_ASSERT(mock.called_once_with((cl_mem)0x395, (cl_pipe_info)CL_PIPE_PACKET_SIZE, 5, (void*)0x124, (size_t*)0x934));
#endif
  }
  /** // doc: test__get_pipe_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_pipe_info__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clGetPipeInfo)
    T::Dummy_clGetPipeInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_pipe_info((cl_mem)NULL, pipe_info_t::packet_size, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__get_pipe_info__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_pipe_info__invalid_mem_object( )
  {
#if CLXX_OPENCL_ALLOWED(clGetPipeInfo)
    T::Dummy_clGetPipeInfo mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(get_pipe_info((cl_mem)NULL, pipe_info_t::packet_size, 0, nullptr, nullptr),clerror_no<status_t::invalid_mem_object>);
#endif
  }
  /** // doc: test__get_pipe_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_pipe_info__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clGetPipeInfo)
    T::Dummy_clGetPipeInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_pipe_info((cl_mem)NULL, pipe_info_t::packet_size, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__get_pipe_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_pipe_info__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clGetPipeInfo)
    T::Dummy_clGetPipeInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_pipe_info((cl_mem)NULL, pipe_info_t::packet_size, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__get_pipe_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_pipe_info__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clGetPipeInfo)
    T::Dummy_clGetPipeInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_pipe_info((cl_mem)NULL, pipe_info_t::packet_size, 0, nullptr, nullptr), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_GET_PIPE_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
