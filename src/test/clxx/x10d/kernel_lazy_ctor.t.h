// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/x10d/kernel_lazy_ctor.t.h

/** // doc: clxx/x10d/kernel_lazy_ctor.t.h {{{
 * \file clxx/x10d/kernel_lazy_ctor.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_X10D_KERNEL_LAZY_CTOR_T_H_INCLUDED
#define CLXX_X10D_KERNEL_LAZY_CTOR_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/x10d/kernel_lazy_ctor.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/kernel.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class kernel_lazy_ctor_test_suite; }

/** // doc: class clxx::kernel_lazy_ctor_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::kernel_lazy_ctor_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__kernel_lazy_ctor__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__kernel_lazy_ctor__1( )
  {
    T::Dummy_clRetainKernel mockRetainKernel(CL_SUCCESS);
    T::Dummy_clReleaseKernel mockReleaseKernel(CL_SUCCESS);
    T::Dummy_clRetainProgram mockRetainProgram(CL_SUCCESS);
    T::Dummy_clReleaseProgram mockReleaseProgram(CL_SUCCESS);
    T::Dummy_clCreateKernel mockCreateKernel((cl_kernel)0x1234, CL_SUCCESS);

    clxx::program p{(cl_program)0x5678};
    clxx::kernel_lazy_ctor lazy_create_kernel;

    clxx::kernel k;

    k = lazy_create_kernel(p, "foo");
    TS_ASSERT(k.get() == (cl_kernel)0x1234);
    TS_ASSERT(mockCreateKernel.called_once());
    TS_ASSERT(std::get<0>(mockCreateKernel.calls().front()) == p.get());
    TS_ASSERT(std::get<1>(mockCreateKernel.calls().front()) != nullptr);
    TS_ASSERT(std::get<2>(mockCreateKernel.calls().front()) != nullptr);

    mockCreateKernel.reset();
    k = lazy_create_kernel(p, "foo");
    TS_ASSERT(k.get() == (cl_kernel)0x1234);
    TS_ASSERT(mockCreateKernel.never_called());

    mockCreateKernel.reset();
    k = lazy_create_kernel(p, "bar");
    TS_ASSERT(k.get() == (cl_kernel)0x1234);
    TS_ASSERT(mockCreateKernel.called_once());
    TS_ASSERT(std::get<0>(mockCreateKernel.calls().front()) == p.get());
    TS_ASSERT(std::get<1>(mockCreateKernel.calls().front()) != nullptr);
    TS_ASSERT(std::get<2>(mockCreateKernel.calls().front()) != nullptr);

    mockCreateKernel.reset();
    k = lazy_create_kernel(p, "foo");
    TS_ASSERT(k.get() == (cl_kernel)0x1234);
    TS_ASSERT(mockCreateKernel.never_called());

    mockCreateKernel.reset();
    k = lazy_create_kernel(p, "bar");
    TS_ASSERT(k.get() == (cl_kernel)0x1234);
    TS_ASSERT(mockCreateKernel.never_called());
  }
};

#endif /* CLXX_X10D_KERNEL_LAZY_CTOR_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
