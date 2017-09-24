// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/release_kernel.t.h

/** // doc: clxx/b5d/cl_fcn/release_kernel.t.h {{{
 * \file clxx/b5d/cl_fcn/release_kernel.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_RELEASE_KERNEL_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_RELEASE_KERNEL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class release_kernel_test_suite; }

/** // doc: class clxx::release_kernel_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::release_kernel_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  release_kernel()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__release_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel( )
  {
#if CLXX_B5D_PROVIDES(release_kernel)
    T::Dummy_clReleaseKernel mock(CL_SUCCESS);
    release_kernel                ((cl_kernel)0x433);
    TS_ASSERT(mock.called_once_with((cl_kernel)0x433));
#else
    TS_SKIP("release_kernel not implemented");
#endif
  }
  /** // doc: test__release_kernel__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel__invalid_kernel( )
  {
#if CLXX_B5D_PROVIDES(release_kernel)
    T::Dummy_clReleaseKernel mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(release_kernel((cl_kernel)NULL),clerror_no<status_t::invalid_kernel>);
#else
    TS_SKIP("release_kernel not implemented");
#endif
  }
  /** // doc: test__release_kernel__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(release_kernel)
    T::Dummy_clReleaseKernel mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_kernel((cl_kernel)NULL),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("release_kernel not implemented");
#endif
  }
  /** // doc: test__release_kernel__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(release_kernel)
    T::Dummy_clReleaseKernel mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_kernel((cl_kernel)NULL),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("release_kernel not implemented");
#endif
  }
  /** // doc: test__release_kernel__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(release_kernel)
    T::Dummy_clReleaseKernel mock(-0x1234567);
    TS_ASSERT_THROWS(release_kernel((cl_kernel)NULL), unexpected_clerror);
#else
    TS_SKIP("release_kernel not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_RELEASE_KERNEL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
