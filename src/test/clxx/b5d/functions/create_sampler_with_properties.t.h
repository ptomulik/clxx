// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/create_sampler_with_properties.t.h

/** // doc: clxx/b5d/functions/create_sampler_with_properties.t.h {{{
 * \file clxx/b5d/functions/create_sampler_with_properties.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_CREATE_SAMPLER_WITH_PROPERTIES_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_CREATE_SAMPLER_WITH_PROPERTIES_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class create_sampler_with_properties_test_suite; }

/** // doc: class clxx::create_sampler_with_properties_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::create_sampler_with_properties_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  create_sampler_with_properties()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_sampler_with_properties() {{{
   * \brief Test create_sampler_with_properties() in a normal situation.
   */ // }}}
  void test__create_sampler_with_properties( )
  {
#if CLXX_B5D_PROVIDES(create_sampler_with_properties)
    T::Dummy_clCreateSamplerWithProperties mock((cl_sampler)0x1234, CL_SUCCESS);
    TS_ASSERT(create_sampler_with_properties((cl_context)0x7654, (const cl_sampler_properties*)0x4567) == (cl_sampler)0x1234);
    TS_ASSERT(mock.called_once());
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x7654)
    TS_ASSERT(std::get<1>(mock.calls().back()) == (const cl_sampler_properties*)0x4567)
#else
    TS_SKIP("create_sampler_with_properties not implemented");
#endif
  }
  /** // doc: test__create_sampler_with_properties__invalid_context() {{{
   * \brief Test create_sampler_with_properties() in a situation when clCreateSamplerWithProperties() returns CL_INVALID_CONTEXT.
   */ // }}}
  void test__create_sampler_with_properties__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(create_sampler_with_properties)
    T::Dummy_clCreateSamplerWithProperties mock((cl_sampler)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_sampler_with_properties((cl_context)0,(const cl_sampler_properties*)NULL), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("create_sampler_with_properties not implemented");
#endif
  }
  /** // doc: test__create_sampler_with_properties__invalid_value() {{{
   * \brief Test create_sampler_with_properties() in a situation when clCreateSamplerWithProperties() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_sampler_with_properties__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(create_sampler_with_properties)
    T::Dummy_clCreateSamplerWithProperties mock((cl_sampler)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_sampler_with_properties((cl_context)0,(const cl_sampler_properties*)NULL), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("create_sampler_with_properties not implemented");
#endif
  }
  /** // doc: test__create_sampler_with_properties__invalid_operation() {{{
   * \brief Test create_sampler_with_properties() in a situation when clCreateSamplerWithProperties() returns CL_INVALID_OPERATION.
   */ // }}}
  void test__create_sampler_with_properties__invalid_operation( )
  {
#if CLXX_B5D_PROVIDES(create_sampler_with_properties)
    T::Dummy_clCreateSamplerWithProperties mock((cl_sampler)NULL, CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(create_sampler_with_properties((cl_context)0,(const cl_sampler_properties*)NULL), clerror_no<status_t::invalid_operation>);
#else
    TS_SKIP("create_sampler_with_properties not implemented");
#endif
  }
  /** // doc: test__create_sampler_with_properties__out_of_resources() {{{
   * \brief Test create_sampler_with_properties() in a situation when clCreateSamplerWithProperties() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_sampler_with_properties__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(create_sampler_with_properties)
    T::Dummy_clCreateSamplerWithProperties mock((cl_sampler)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_sampler_with_properties((cl_context)0,(const cl_sampler_properties*)NULL), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("create_sampler_with_properties not implemented");
#endif
  }
  /** // doc: test__create_sampler_with_properties__out_of_host_memory() {{{
   * \brief Test create_sampler_with_properties() in a situation when clCreateSamplerWithProperties() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_sampler_with_properties__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(create_sampler_with_properties)
    T::Dummy_clCreateSamplerWithProperties mock((cl_sampler)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_sampler_with_properties((cl_context)0,(const cl_sampler_properties*)NULL), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("create_sampler_with_properties not implemented");
#endif
  }
  /** // doc: test__create_sampler_with_properties__unexpected_clerror() {{{
   * \brief Test create_sampler_with_properties() in a situation when clCreateSamplerWithProperties() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_sampler_with_properties__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(create_sampler_with_properties)
    T::Dummy_clCreateSamplerWithProperties mock((cl_sampler)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_sampler_with_properties((cl_context)0,(const cl_sampler_properties*)NULL), unexpected_clerror);
#else
    TS_SKIP("create_sampler_with_properties not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_CREATE_SAMPLER_WITH_PROPERTIES_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
