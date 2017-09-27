// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/get_pipe_info.t.h

/** // doc: clxx/b5d/functions/get_pipe_info.t.h {{{
 * \file clxx/b5d/functions/get_pipe_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_GET_PIPE_INFO_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_GET_PIPE_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class get_pipe_info_test_suite; }

/** // doc: class clxx::get_pipe_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::get_pipe_info_test_suite : public CxxTest::TestSuite
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
#if CLXX_B5D_PROVIDES(get_pipe_info)
    T::Dummy_clGetPipeInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_pipe_info((cl_mem)0x395, pipe_info_t::packet_size,  5, (void*)0x124, (size_t*)0x934));
    TS_ASSERT(mock.called_once_with((cl_mem)0x395, (cl_pipe_info)CL_PIPE_PACKET_SIZE, 5, (void*)0x124, (size_t*)0x934));
#else
    TS_SKIP("get_pipe_info not implemented");
#endif
  }
  /** // doc: test__get_pipe_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_pipe_info__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(get_pipe_info)
    T::Dummy_clGetPipeInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_pipe_info((cl_mem)NULL, pipe_info_t::packet_size, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("get_pipe_info not implemented");
#endif
  }
  /** // doc: test__get_pipe_info__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_pipe_info__invalid_mem_object( )
  {
#if CLXX_B5D_PROVIDES(get_pipe_info)
    T::Dummy_clGetPipeInfo mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(get_pipe_info((cl_mem)NULL, pipe_info_t::packet_size, 0, nullptr, nullptr),clerror_no<status_t::invalid_mem_object>);
#else
    TS_SKIP("get_pipe_info not implemented");
#endif
  }
  /** // doc: test__get_pipe_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_pipe_info__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(get_pipe_info)
    T::Dummy_clGetPipeInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_pipe_info((cl_mem)NULL, pipe_info_t::packet_size, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("get_pipe_info not implemented");
#endif
  }
  /** // doc: test__get_pipe_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_pipe_info__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(get_pipe_info)
    T::Dummy_clGetPipeInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_pipe_info((cl_mem)NULL, pipe_info_t::packet_size, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("get_pipe_info not implemented");
#endif
  }
  /** // doc: test__get_pipe_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_pipe_info__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(get_pipe_info)
    T::Dummy_clGetPipeInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_pipe_info((cl_mem)NULL, pipe_info_t::packet_size, 0, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("get_pipe_info not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_GET_PIPE_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
