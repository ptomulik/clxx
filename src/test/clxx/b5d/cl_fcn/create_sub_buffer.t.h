// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/create_sub_buffer.t.h

/** // doc: clxx/b5d/cl_fcn/create_sub_buffer.t.h {{{
 * \file clxx/b5d/cl_fcn/create_sub_buffer.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_CREATE_SUB_BUFFER_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_CREATE_SUB_BUFFER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class create_sub_buffer_test_suite; }

/** // doc: class clxx::create_sub_buffer_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::create_sub_buffer_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  create_sub_buffer()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_sub_buffer() {{{
   * \brief Test create_sub_buffer() in a normal situation.
   */ // }}}
  void test__create_sub_buffer( )
  {
#if CLXX_B5D_PROVIDES(create_sub_buffer)
    T::Dummy_clCreateSubBuffer mock((cl_mem)0x1234, CL_SUCCESS);
    TS_ASSERT(create_sub_buffer((cl_mem)0x7654, mem_flags_t::read_write, buffer_create_type_t::region, (const void*)0x4567) == (cl_mem)0x1234);
    TS_ASSERT(mock.called_once());
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_mem)0x7654)
    TS_ASSERT(std::get<1>(mock.calls().back()) == (cl_mem_flags)CL_MEM_READ_WRITE)
    TS_ASSERT(std::get<2>(mock.calls().back()) == (cl_buffer_create_type)CL_BUFFER_CREATE_TYPE_REGION)
    TS_ASSERT(std::get<3>(mock.calls().back()) == (const void*)0x4567)
#else
    TS_SKIP("create_sub_buffer not implemented");
#endif
  }
  /** // doc: test__create_sub_buffer__invalid_mem_object() {{{
   * \brief Test create_sub_buffer() in a situation when clCreateSubBuffer() returns CL_INVALID_MEM_OBJECT.
   */ // }}}
  void test__create_sub_buffer__invalid_mem_object( )
  {
#if CLXX_B5D_PROVIDES(create_sub_buffer)
    T::Dummy_clCreateSubBuffer mock((cl_mem)NULL, CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(create_sub_buffer((cl_mem)0,mem_flags_t::read_write,buffer_create_type_t::region,nullptr), clerror_no<status_t::invalid_mem_object>);
#else
    TS_SKIP("create_sub_buffer not implemented");
#endif
  }
  /** // doc: test__create_sub_buffer__invalid_value() {{{
   * \brief Test create_sub_buffer() in a situation when clCreateSubBuffer() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_sub_buffer__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(create_sub_buffer)
    T::Dummy_clCreateSubBuffer mock((cl_mem)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_sub_buffer((cl_mem)0,mem_flags_t::read_write,buffer_create_type_t::region,nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("create_sub_buffer not implemented");
#endif
  }
  /** // doc: test__create_sub_buffer__invalid_buffer_size() {{{
   * \brief Test create_sub_buffer() in a situation when clCreateSubBuffer() returns CL_INVALID_BUFFER_SIZE.
   */ // }}}
  void test__create_sub_buffer__invalid_buffer_size( )
  {
#if CLXX_B5D_PROVIDES(create_sub_buffer)
    T::Dummy_clCreateSubBuffer mock((cl_mem)NULL, CL_INVALID_BUFFER_SIZE);
    TS_ASSERT_THROWS(create_sub_buffer((cl_mem)0,mem_flags_t::read_write,buffer_create_type_t::region,nullptr), clerror_no<status_t::invalid_buffer_size>);
#else
    TS_SKIP("create_sub_buffer not implemented");
#endif
  }
  /** // doc: test__create_sub_buffer__mem_object_allocation_failure() {{{
   * \brief Test create_sub_buffer() in a situation when clCreateSubBuffer() returns CL_MEM_OBJECT_ALLOCATION_FAILURE.
   */ // }}}
  void test__create_sub_buffer__mem_object_allocation_failure( )
  {
#if CLXX_B5D_PROVIDES(create_sub_buffer)
    T::Dummy_clCreateSubBuffer mock((cl_mem)NULL, CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(create_sub_buffer((cl_mem)0,mem_flags_t::read_write,buffer_create_type_t::region,nullptr), clerror_no<status_t::mem_object_allocation_failure>);
#else
    TS_SKIP("create_sub_buffer not implemented");
#endif
  }
  /** // doc: test__create_sub_buffer__out_of_resources() {{{
   * \brief Test create_sub_buffer() in a situation when clCreateSubBuffer() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_sub_buffer__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(create_sub_buffer)
    T::Dummy_clCreateSubBuffer mock((cl_mem)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_sub_buffer((cl_mem)0,mem_flags_t::read_write,buffer_create_type_t::region,nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("create_sub_buffer not implemented");
#endif
  }
  /** // doc: test__create_sub_buffer__out_of_host_memory() {{{
   * \brief Test create_sub_buffer() in a situation when clCreateSubBuffer() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_sub_buffer__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(create_sub_buffer)
    T::Dummy_clCreateSubBuffer mock((cl_mem)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_sub_buffer((cl_mem)0,mem_flags_t::read_write,buffer_create_type_t::region,nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("create_sub_buffer not implemented");
#endif
  }
  /** // doc: test__create_sub_buffer__unexpected_clerror() {{{
   * \brief Test create_sub_buffer() in a situation when clCreateSubBuffer() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_sub_buffer__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(create_sub_buffer)
    T::Dummy_clCreateSubBuffer mock((cl_mem)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_sub_buffer((cl_mem)0,mem_flags_t::read_write,buffer_create_type_t::region,nullptr), unexpected_clerror);
#else
    TS_SKIP("create_sub_buffer not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_CREATE_SUB_BUFFER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
