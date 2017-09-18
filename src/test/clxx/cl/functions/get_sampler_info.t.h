// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/get_sampler_info.t.h

/** // doc: clxx/cl/functions/get_sampler_info.t.h {{{
 * \file clxx/cl/functions/get_sampler_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_GET_SAMPLER_INFO_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_GET_SAMPLER_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_get_sampler_info_test_suite; }

/** // doc: class clxx::functions_get_sampler_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_get_sampler_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_sampler_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_sampler_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_sampler_info( )
  {
    T::Dummy_clGetSamplerInfo mock(CL_SUCCESS);
    get_sampler_info               ((cl_sampler)0x395, sampler_info_t::reference_count,             5, (void*)0x124, (size_t*)0x934);
    TS_ASSERT(mock.called_once_with((cl_sampler)0x395, (cl_sampler_info)CL_SAMPLER_REFERENCE_COUNT, 5, (void*)0x124, (size_t*)0x934));
  }
  /** // doc: test__get_sampler_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_sampler_info__invalid_value( )
  {
    T::Dummy_clGetSamplerInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_sampler_info((cl_sampler)NULL, sampler_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_sampler_info__invalid_sampler() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_sampler_info__invalid_sampler( )
  {
    T::Dummy_clGetSamplerInfo mock(CL_INVALID_SAMPLER);
    TS_ASSERT_THROWS(get_sampler_info((cl_sampler)NULL, sampler_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::invalid_sampler>);
  }
  /** // doc: test__get_sampler_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_sampler_info__out_of_resources( )
  {
    T::Dummy_clGetSamplerInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_sampler_info((cl_sampler)NULL, sampler_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_sampler_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_sampler_info__out_of_host_memory( )
  {
    T::Dummy_clGetSamplerInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_sampler_info((cl_sampler)NULL, sampler_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_sampler_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_sampler_info__unexpected_clerror( )
  {
    T::Dummy_clGetSamplerInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_sampler_info((cl_sampler)NULL, sampler_info_t::reference_count, 0, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_GET_SAMPLER_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
