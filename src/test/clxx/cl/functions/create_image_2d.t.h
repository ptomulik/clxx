// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/create_image_2d.t.h

/** // doc: clxx/cl/functions/create_image_2d.t.h {{{
 * \file clxx/cl/functions/create_image_2d.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_CREATE_IMAGE_2D_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_CREATE_IMAGE_2D_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_image_2d_test_suite; }

/** // doc: class clxx::functions_create_image_2d_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_image_2d_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  create_image_2d()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_image_2d() {{{
   * \brief Test create_image_2d() in a normal situation.
   */ // }}}
  void test__create_image_2d( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateImage2D)
    T::Dummy_clCreateImage2D mock((cl_mem)0x1234, CL_SUCCESS);
    TS_ASSERT(create_image_2d((cl_context)0x7654, mem_flags_t::read_write, (const cl_image_format*)0x4567, 1ul, 2ul, 3ul, (void*)0x2345) == (cl_mem)0x1234);
    TS_ASSERT(mock.called_once());
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x7654)
    TS_ASSERT(std::get<1>(mock.calls().back()) == (cl_mem_flags)CL_MEM_READ_WRITE)
    TS_ASSERT(std::get<2>(mock.calls().back()) == (const cl_image_format*)0x4567)
    TS_ASSERT(std::get<3>(mock.calls().back()) == 1ul)
    TS_ASSERT(std::get<4>(mock.calls().back()) == 2ul)
    TS_ASSERT(std::get<5>(mock.calls().back()) == 3ul)
    TS_ASSERT(std::get<6>(mock.calls().back()) == (void*)0x2345)
    TS_ASSERT(std::get<7>(mock.calls().back()) != nullptr)
#endif
  }
  /** // doc: test__create_image_2d__invalid_context() {{{
   * \brief Test create_image_2d() in a situation when clCreateImage2D() returns CL_INVALID_CONTEXT.
   */ // }}}
  void test__create_image_2d__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateImage2D)
    T::Dummy_clCreateImage2D mock((cl_mem)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_image_2d((cl_context)0,mem_flags_t::read_write,nullptr,0ul,0ul,0ul,nullptr), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__create_image_2d__invalid_value() {{{
   * \brief Test create_image_2d() in a situation when clCreateImage2D() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_image_2d__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateImage2D)
    T::Dummy_clCreateImage2D mock((cl_mem)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_image_2d((cl_context)0,mem_flags_t::read_write,nullptr,0ul,0ul,0ul,nullptr), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__create_image_2d__invalid_image_format_descriptor() {{{
   * \brief Test create_image_2d() in a situation when clCreateImage2D() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_image_2d__invalid_image_format_descriptor( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateImage2D)
    T::Dummy_clCreateImage2D mock((cl_mem)NULL, CL_INVALID_IMAGE_FORMAT_DESCRIPTOR);
    TS_ASSERT_THROWS(create_image_2d((cl_context)0,mem_flags_t::read_write,nullptr,0ul,0ul,0ul,nullptr), clerror_no<status_t::invalid_image_format_descriptor>);
#endif
  }
  /** // doc: test__create_image_2d__invalid_image_size() {{{
   * \brief Test create_image_2d() in a situation when clCreateImage2D() returns CL_INVALID_BUFFER_SIZE.
   */ // }}}
  void test__create_image_2d__invalid_image_size( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateImage2D)
    T::Dummy_clCreateImage2D mock((cl_mem)NULL, CL_INVALID_IMAGE_SIZE);
    TS_ASSERT_THROWS(create_image_2d((cl_context)0,mem_flags_t::read_write,nullptr,0ul,0ul,0ul,nullptr), clerror_no<status_t::invalid_image_size>);
#endif
  }
  /** // doc: test__create_image_2d__invalid_host_ptr() {{{
   * \brief Test create_image_2d() in a situation when clCreateImage2D() returns CL_INVALID_HOST_PTR.
   */ // }}}
  void test__create_image_2d__invalid_host_ptr( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateImage2D)
    T::Dummy_clCreateImage2D mock((cl_mem)NULL, CL_INVALID_HOST_PTR);
    TS_ASSERT_THROWS(create_image_2d((cl_context)0,mem_flags_t::read_write,nullptr,0ul,0ul,0ul,nullptr), clerror_no<status_t::invalid_host_ptr>);
#endif
  }
  /** // doc: test__create_image_2d__image_format_not_supported() {{{
   * \brief Test create_image_2d() in a situation when clCreateImage2D() returns CL_INVALID_BUFFER_SIZE.
   */ // }}}
  void test__create_image_2d__image_format_not_supported( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateImage2D)
    T::Dummy_clCreateImage2D mock((cl_mem)NULL, CL_IMAGE_FORMAT_NOT_SUPPORTED);
    TS_ASSERT_THROWS(create_image_2d((cl_context)0,mem_flags_t::read_write,nullptr,0ul,0ul,0ul,nullptr), clerror_no<status_t::image_format_not_supported>);
#endif
  }
  /** // doc: test__create_image_2d__mem_object_allocation_failure() {{{
   * \brief Test create_image_2d() in a situation when clCreateImage2D() returns CL_MEM_OBJECT_ALLOCATION_FAILURE.
   */ // }}}
  void test__create_image_2d__mem_object_allocation_failure( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateImage2D)
    T::Dummy_clCreateImage2D mock((cl_mem)NULL, CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(create_image_2d((cl_context)0,mem_flags_t::read_write,nullptr,0ul,0ul,0ul,nullptr), clerror_no<status_t::mem_object_allocation_failure>);
#endif
  }
  /** // doc: test__create_image_2d__invalid_operation() {{{
   * \brief Test create_image_2d() in a situation when clCreateImage2D() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_image_2d__invalid_operation( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateImage2D)
    T::Dummy_clCreateImage2D mock((cl_mem)NULL, CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(create_image_2d((cl_context)0,mem_flags_t::read_write,nullptr,0ul,0ul,0ul,nullptr), clerror_no<status_t::invalid_operation>);
#endif
  }
  /** // doc: test__create_image_2d__out_of_resources() {{{
   * \brief Test create_image_2d() in a situation when clCreateImage2D() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_image_2d__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateImage2D)
    T::Dummy_clCreateImage2D mock((cl_mem)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_image_2d((cl_context)0,mem_flags_t::read_write,nullptr,0ul,0ul,0ul,nullptr), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__create_image_2d__out_of_host_memory() {{{
   * \brief Test create_image_2d() in a situation when clCreateImage2D() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_image_2d__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateImage2D)
    T::Dummy_clCreateImage2D mock((cl_mem)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_image_2d((cl_context)0,mem_flags_t::read_write,nullptr,0ul,0ul,0ul,nullptr), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__create_image_2d__unexpected_clerror() {{{
   * \brief Test create_image_2d() in a situation when clCreateImage2D() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_image_2d__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateImage2D)
    T::Dummy_clCreateImage2D mock((cl_mem)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_image_2d((cl_context)0,mem_flags_t::read_write,nullptr,0ul,0ul,0ul,nullptr), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_CREATE_IMAGE_2D_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
