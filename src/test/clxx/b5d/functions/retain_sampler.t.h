// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/retain_sampler.t.h

/** // doc: clxx/b5d/functions/retain_sampler.t.h {{{
 * \file clxx/b5d/functions/retain_sampler.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_RETAIN_SAMPLER_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_RETAIN_SAMPLER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class retain_sampler_test_suite; }

/** // doc: class clxx::retain_sampler_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::retain_sampler_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  retain_sampler()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__retain_sampler() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_sampler( )
  {
#if CLXX_B5D_PROVIDES(retain_sampler)
    T::Dummy_clRetainSampler mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(retain_sampler((cl_sampler)0x344));
    TS_ASSERT(mock.called_once_with((cl_sampler)0x344));
#else
    TS_SKIP("retain_sampler not implemented");
#endif
  }
  /** // doc: test__retain_sampler__invalid_sampler() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_sampler__invalid_sampler( )
  {
#if CLXX_B5D_PROVIDES(retain_sampler)
    T::Dummy_clRetainSampler mock(CL_INVALID_SAMPLER);
    TS_ASSERT_THROWS(retain_sampler((cl_sampler)NULL),clerror_no<status_t::invalid_sampler>);
#else
    TS_SKIP("retain_sampler not implemented");
#endif
  }
  /** // doc: test__retain_sampler__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_sampler__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(retain_sampler)
    T::Dummy_clRetainSampler mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_sampler((cl_sampler)NULL),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("retain_sampler not implemented");
#endif
  }
  /** // doc: test__retain_sampler__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_sampler__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(retain_sampler)
    T::Dummy_clRetainSampler mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_sampler((cl_sampler)NULL),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("retain_sampler not implemented");
#endif
  }
  /** // doc: test__retain_sampler__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_sampler__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(retain_sampler)
    T::Dummy_clRetainSampler mock(-0x1234567);
    TS_ASSERT_THROWS(retain_sampler((cl_sampler)NULL), unexpected_clerror);
#else
    TS_SKIP("retain_sampler not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_RETAIN_SAMPLER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
