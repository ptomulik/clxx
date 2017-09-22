// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl/clone_kernel.t.h

/** // doc: clxx/b5d/cl/clone_kernel.t.h {{{
 * \file clxx/b5d/cl/clone_kernel.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_CLONE_KERNEL_T_H_INCLUDED
#define CLXX_B5D_CL_CLONE_KERNEL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class clone_kernel_test_suite; }

/** // doc: class clxx::clone_kernel_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::clone_kernel_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  clone_kernel()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__clone_kernel() {{{
   * \brief Test clone_kernel() in a normal situation.
   */ // }}}
  void test__clone_kernel( )
  {
#if CLXX_B5D_PROVIDES(clone_kernel)
    T::Dummy_clCloneKernel mock((cl_kernel)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::clone_kernel((cl_kernel)0x4321));
    TS_ASSERT(mock.called_once());
    TS_ASSERT(clxx::clone_kernel((cl_kernel)0x4321) == (cl_kernel)0x1234);
#else
    TS_SKIP("clone_kernel not implemented");
#endif
  }
  /** // doc: test__clone_kernel__invalid_kernel() {{{
   * \brief Test clone_kernel() in a situation when clCloneKernel() returns CL_INVALID_PROGRAM.
   */ // }}}
  void test__clone_kernel__invalid_kernel( )
  {
#if CLXX_B5D_PROVIDES(clone_kernel)
    T::Dummy_clCloneKernel mock((cl_kernel)NULL, CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(clxx::clone_kernel((cl_kernel)0x4321), clerror_no<status_t::invalid_kernel>);
#else
    TS_SKIP("clone_kernel not implemented");
#endif
  }
  /** // doc: test__clone_kernel__out_of_resources() {{{
   * \brief Test clone_kernel() in a situation when clCloneKernel() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__clone_kernel__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(clone_kernel)
    T::Dummy_clCloneKernel mock((cl_kernel)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::clone_kernel((cl_kernel)0x4321), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("clone_kernel not implemented");
#endif
  }
  /** // doc: test__clone_kernel__out_of_host_memory() {{{
   * \brief Test clone_kernel() in a situation when clCloneKernel() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__clone_kernel__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(clone_kernel)
    T::Dummy_clCloneKernel mock((cl_kernel)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::clone_kernel((cl_kernel)0x4321), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("clone_kernel not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_CLONE_KERNEL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
