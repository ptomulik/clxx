// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_functions/release_mem_object.t.h

/** // doc: clxx/b5d/cl_functions/release_mem_object.t.h {{{
 * \file clxx/b5d/cl_functions/release_mem_object.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FUNCTIONS_RELEASE_MEM_OBJECT_T_H_INCLUDED
#define CLXX_B5D_CL_FUNCTIONS_RELEASE_MEM_OBJECT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_functions.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class release_mem_object_test_suite; }

/** // doc: class clxx::release_mem_object_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::release_mem_object_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  release_mem_object()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__release_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_mem_object( )
  {
#if CLXX_B5D_PROVIDES(release_mem_object)
    T::Dummy_clReleaseMemObject mock(CL_SUCCESS);
    release_mem_object             ((cl_mem)0x433);
    TS_ASSERT(mock.called_once_with((cl_mem)0x433));
#else
    TS_SKIP("release_mem_object not implemented");
#endif
  }
  /** // doc: test__release_mem_object__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_mem_object__invalid_mem_object( )
  {
#if CLXX_B5D_PROVIDES(release_mem_object)
    T::Dummy_clReleaseMemObject mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(release_mem_object((cl_mem)NULL),clerror_no<status_t::invalid_mem_object>);
#else
    TS_SKIP("release_mem_object not implemented");
#endif
  }
  /** // doc: test__release_mem_object__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_mem_object__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(release_mem_object)
    T::Dummy_clReleaseMemObject mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_mem_object((cl_mem)NULL),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("release_mem_object not implemented");
#endif
  }
  /** // doc: test__release_mem_object__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_mem_object__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(release_mem_object)
    T::Dummy_clReleaseMemObject mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_mem_object((cl_mem)NULL),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("release_mem_object not implemented");
#endif
  }
  /** // doc: test__release_mem_object__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_mem_object__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(release_mem_object)
    T::Dummy_clReleaseMemObject mock(-0x1234567);
    TS_ASSERT_THROWS(release_mem_object((cl_mem)NULL), unexpected_clerror);
#else
    TS_SKIP("release_mem_object not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FUNCTIONS_RELEASE_MEM_OBJECT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
