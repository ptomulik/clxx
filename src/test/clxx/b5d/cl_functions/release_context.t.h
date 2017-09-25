// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_functions/release_context.t.h

/** // doc: clxx/b5d/cl_functions/release_context.t.h {{{
 * \file clxx/b5d/cl_functions/release_context.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FUNCTIONS_RELEASE_CONTEXT_T_H_INCLUDED
#define CLXX_B5D_CL_FUNCTIONS_RELEASE_CONTEXT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_functions.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class release_context_test_suite; }

/** // doc: class clxx::release_context_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::release_context_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  release_context()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__release_context() {{{
   * \brief Test release_context() in a normal situation
   */ // }}}
  void test__release_context( )
  {
#if CLXX_B5D_PROVIDES(release_context)
    T::Dummy_clReleaseContext mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_context((cl_context)NULL));
    TS_ASSERT(mock.called_once_with((cl_context)NULL));
#else
    TS_SKIP("release_context not implemented");
#endif
  }
  /** // doc: test__release_context__invalid_context() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__release_context__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(release_context)
    T::Dummy_clReleaseContext mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("release_context not implemented");
#endif
  }
  /** // doc: test__release_context__out_of_resources() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__release_context__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(release_context)
    T::Dummy_clReleaseContext mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("release_context not implemented");
#endif
  }
  /** // doc: test__release_context__out_of_host_memory() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__release_context__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(release_context)
    T::Dummy_clReleaseContext mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("release_context not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FUNCTIONS_RELEASE_CONTEXT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
