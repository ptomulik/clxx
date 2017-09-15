// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/create_sampler.t.h

/** // doc: clxx/cl/functions/create_sampler.t.h {{{
 * \file clxx/cl/functions/create_sampler.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_CREATE_SAMPLER_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_CREATE_SAMPLER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_sampler_test_suite; }

/** // doc: class clxx::functions_create_sampler_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_sampler_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  create_sampler()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_sampler() {{{
   * \brief Test create_sampler() in a normal situation.
   */ // }}}
  void test__create_sampler( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSampler)
    T::Dummy_clCreateSampler mock((cl_sampler)0x1234, CL_SUCCESS);
    TS_ASSERT(create_sampler((cl_context)0x7654, CL_TRUE, addressing_mode_t::clamp, filter_mode_t::linear) == (cl_sampler)0x1234);
    TS_ASSERT(mock.called_once());
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x7654)
    TS_ASSERT(std::get<1>(mock.calls().back()) == (cl_bool)CL_TRUE)
    TS_ASSERT(std::get<2>(mock.calls().back()) == (cl_addressing_mode)CL_ADDRESS_CLAMP)
    TS_ASSERT(std::get<3>(mock.calls().back()) == (cl_filter_mode)CL_FILTER_LINEAR)
#endif
  }
  /** // doc: test__create_sampler__invalid_context() {{{
   * \brief Test create_sampler() in a situation when clCreateSampler() returns CL_INVALID_CONTEXT.
   */ // }}}
  void test__create_sampler__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSampler)
    T::Dummy_clCreateSampler mock((cl_sampler)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_sampler((cl_context)0,CL_FALSE,addressing_mode_t::none,filter_mode_t::nearest), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__create_sampler__invalid_value() {{{
   * \brief Test create_sampler() in a situation when clCreateSampler() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_sampler__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSampler)
    T::Dummy_clCreateSampler mock((cl_sampler)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_sampler((cl_context)0,CL_FALSE,addressing_mode_t::none,filter_mode_t::nearest), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__create_sampler__invalid_operation() {{{
   * \brief Test create_sampler() in a situation when clCreateSampler() returns CL_INVALID_OPERATION.
   */ // }}}
  void test__create_sampler__invalid_operation( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSampler)
    T::Dummy_clCreateSampler mock((cl_sampler)NULL, CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(create_sampler((cl_context)0,CL_FALSE,addressing_mode_t::none,filter_mode_t::nearest), clerror_no<status_t::invalid_operation>);
#endif
  }
  /** // doc: test__create_sampler__out_of_resources() {{{
   * \brief Test create_sampler() in a situation when clCreateSampler() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_sampler__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSampler)
    T::Dummy_clCreateSampler mock((cl_sampler)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_sampler((cl_context)0,CL_FALSE,addressing_mode_t::none,filter_mode_t::nearest), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__create_sampler__out_of_host_memory() {{{
   * \brief Test create_sampler() in a situation when clCreateSampler() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_sampler__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSampler)
    T::Dummy_clCreateSampler mock((cl_sampler)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_sampler((cl_context)0,CL_FALSE,addressing_mode_t::none,filter_mode_t::nearest), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__create_sampler__unexpected_clerror() {{{
   * \brief Test create_sampler() in a situation when clCreateSampler() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_sampler__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSampler)
    T::Dummy_clCreateSampler mock((cl_sampler)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_sampler((cl_context)0,CL_FALSE,addressing_mode_t::none,filter_mode_t::nearest), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_CREATE_SAMPLER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
