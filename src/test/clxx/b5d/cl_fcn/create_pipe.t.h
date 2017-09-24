// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/create_pipe.t.h

/** // doc: clxx/b5d/cl_fcn/create_pipe.t.h {{{
 * \file clxx/b5d/cl_fcn/create_pipe.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_CREATE_PIPE_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_CREATE_PIPE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class create_pipe_test_suite; }

/** // doc: class clxx::create_pipe_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::create_pipe_test_suite : public CxxTest::TestSuite
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
#if CLXX_B5D_PROVIDES(create_pipe)
    T::Dummy_clCreatePipe mock((cl_mem)0x1234, CL_SUCCESS);
    TS_ASSERT(create_pipe((cl_context)0x7654, mem_flags_t::read_write, 1u, 2u, (const cl_pipe_properties*)0x2345) == (cl_mem)0x1234);
    TS_ASSERT(mock.called_once());
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x7654)
    TS_ASSERT(std::get<1>(mock.calls().back()) == (cl_mem_flags)CL_MEM_READ_WRITE)
    TS_ASSERT(std::get<2>(mock.calls().back()) == 1u)
    TS_ASSERT(std::get<3>(mock.calls().back()) == 2u)
    TS_ASSERT(std::get<4>(mock.calls().back()) == (const cl_pipe_properties*)0x2345)
    TS_ASSERT(std::get<5>(mock.calls().back()) != nullptr)
#else
    TS_SKIP("create_pipe not implemented");
#endif
  }
  /** // doc: test__create_pipe__invalid_context() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_INVALID_CONTEXT.
   */ // }}}
  void test__create_pipe__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(create_pipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("create_pipe not implemented");
#endif
  }
  /** // doc: test__create_pipe__invalid_value() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_pipe__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(create_pipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("create_pipe not implemented");
#endif
  }
  /** // doc: test__create_pipe__invalid_pipe_size() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_INVALID_BUFFER_SIZE.
   */ // }}}
  void test__create_pipe__invalid_pipe_size( )
  {
#if CLXX_B5D_PROVIDES(create_pipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, CL_INVALID_PIPE_SIZE);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), clerror_no<status_t::invalid_pipe_size>);
#else
    TS_SKIP("create_pipe not implemented");
#endif
  }
  /** // doc: test__create_pipe__mem_object_allocation_failure() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_MEM_OBJECT_ALLOCATION_FAILURE.
   */ // }}}
  void test__create_pipe__mem_object_allocation_failure( )
  {
#if CLXX_B5D_PROVIDES(create_pipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), clerror_no<status_t::mem_object_allocation_failure>);
#else
    TS_SKIP("create_pipe not implemented");
#endif
  }
  /** // doc: test__create_pipe__out_of_resources() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_pipe__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(create_pipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("create_pipe not implemented");
#endif
  }
  /** // doc: test__create_pipe__out_of_host_memory() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_pipe__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(create_pipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("create_pipe not implemented");
#endif
  }
  /** // doc: test__create_pipe__unexpected_clerror() {{{
   * \brief Test create_pipe() in a situation when clCreatePipe() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_pipe__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(create_pipe)
    T::Dummy_clCreatePipe mock((cl_mem)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_pipe((cl_context)0,mem_flags_t::read_write,0u,0u,nullptr), unexpected_clerror);
#else
    TS_SKIP("create_pipe not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_CREATE_PIPE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
