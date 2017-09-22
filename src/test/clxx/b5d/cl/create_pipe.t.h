// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/create_pipe.t.h

/** // doc: clxx/cl/functions/create_pipe.t.h {{{
 * \file clxx/cl/functions/create_pipe.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_CREATE_PIPE_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_CREATE_PIPE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_pipe_test_suite; }

/** // doc: class clxx::functions_create_pipe_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_pipe_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  create_pipe()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_pipe() {{{
   * \brief Test create_pipe() in a normal situation.
   */ // }}}
  void test__create_pipe( )
  {
#if CLXX_OPENCL_ALLOWED(clCreatePipe)
    T::Dummy_clCreatePipe mock((cl_mem)0x1234, CL_SUCCESS);
    TS_ASSERT(create_pipe((cl_context)0x7654, mem_flags_t::read_write, 1u, 2u, (const cl_pipe_properties*)0x2345) == (cl_mem)0x1234);
    TS_ASSERT(mock.called_once());
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x7654)
    TS_ASSERT(std::get<1>(mock.calls().back()) == (cl_mem_flags)CL_MEM_READ_WRITE)
    TS_ASSERT(std::get<2>(mock.calls().back()) == 1u)
    TS_ASSERT(std::get<3>(mock.calls().back()) == 2u)
    TS_ASSERT(std::get<4>(mock.calls().back()) == (const cl_pipe_properties*)0x2345)
    TS_ASSERT(std::get<5>(mock.calls().back()) != nullptr)
#endif
  }
  /** // doc: test__create_pipe__invalid_context() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_INVALID_CONTEXT.
   */ // }}}
  void test__create_pipe__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clCreatePipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__create_pipe__invalid_value() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_pipe__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clCreatePipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__create_pipe__invalid_pipe_size() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_INVALID_BUFFER_SIZE.
   */ // }}}
  void test__create_pipe__invalid_pipe_size( )
  {
#if CLXX_OPENCL_ALLOWED(clCreatePipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, CL_INVALID_PIPE_SIZE);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), clerror_no<status_t::invalid_pipe_size>);
#endif
  }
  /** // doc: test__create_pipe__mem_object_allocation_failure() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_MEM_OBJECT_ALLOCATION_FAILURE.
   */ // }}}
  void test__create_pipe__mem_object_allocation_failure( )
  {
#if CLXX_OPENCL_ALLOWED(clCreatePipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), clerror_no<status_t::mem_object_allocation_failure>);
#endif
  }
  /** // doc: test__create_pipe__out_of_resources() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_pipe__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clCreatePipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__create_pipe__out_of_host_memory() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_pipe__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clCreatePipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__create_pipe__unexpected_clerror() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_pipe__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clCreatePipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_CREATE_PIPE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
