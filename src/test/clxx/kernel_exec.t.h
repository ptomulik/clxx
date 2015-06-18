// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/kernel_exec.t.h

/** // doc: clxx/kernel_exec.t.h {{{
 * \file clxx/kernel_exec.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_KERNEL_EXEC_T_H_INCLUDED
#define CLXX_KERNEL_EXEC_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/kernel_exec.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class kernel_exec_test_suite; }

/** // doc: class clxx::kernel_exec_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::kernel_exec_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__enqueue_ndrange_kernel_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel_1( )
  {
    cl_event var = (cl_event)0x1234;

    T::Dummy_clEnqueueNDRangeKernel mock1(CL_SUCCESS, &var);
    T::Dummy_clRetainEvent mock2(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock3(CL_SUCCESS);
    T::Dummy_clRetainCommandQueue mock4(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock5(CL_SUCCESS);
    T::Dummy_clRetainKernel mock6(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x2345);
    kernel k((cl_kernel)0x3456);
    ndrange r{3,{1,2,3},{4,5,6},{7,8,9}};
    events e{event((cl_event)0x765), event((cl_event)0x876)};

    TS_ASSERT_EQUALS(enqueue_ndrange_kernel(q,k,r,e).id(), var);
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == q.id());
    TS_ASSERT(std::get<1>(mock1.calls().back()) == k.id());
    TS_ASSERT(std::get<2>(mock1.calls().back()) == r.dimension());
    TS_ASSERT(std::get<3>(mock1.calls().back()) == r.global_offset_ptr());
    TS_ASSERT(std::get<4>(mock1.calls().back()) == r.global_size_ptr());
    TS_ASSERT(std::get<5>(mock1.calls().back()) == r.local_size_ptr());
    TS_ASSERT(std::get<6>(mock1.calls().back()) == e.size());
    TS_ASSERT(std::get<7>(mock1.calls().back()) != nullptr);
  }
  /** // doc: test__foo() {{{
   * \todo Write documentation
   */ // }}}
  void test__foo( )
  {
    cl_event var = (cl_event)0x1234;

    T::Dummy_clEnqueueNDRangeKernel mock1(CL_SUCCESS, &var);
    T::Dummy_clRetainEvent mock2(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock3(CL_SUCCESS);
    T::Dummy_clRetainCommandQueue mock4(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock5(CL_SUCCESS);
    T::Dummy_clRetainKernel mock6(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x2345);
    kernel k((cl_kernel)0x3456);
    ndrange r{3,{1,2,3},{4,5,6},{7,8,9}};

    TS_ASSERT_EQUALS(enqueue_ndrange_kernel(q,k,r).id(), var);
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == q.id());
    TS_ASSERT(std::get<1>(mock1.calls().back()) == k.id());
    TS_ASSERT(std::get<2>(mock1.calls().back()) == r.dimension());
    TS_ASSERT(std::get<3>(mock1.calls().back()) == r.global_offset_ptr());
    TS_ASSERT(std::get<4>(mock1.calls().back()) == r.global_size_ptr());
    TS_ASSERT(std::get<5>(mock1.calls().back()) == r.local_size_ptr());
    TS_ASSERT(std::get<6>(mock1.calls().back()) == 0);
    TS_ASSERT(std::get<7>(mock1.calls().back()) == nullptr);
  }
};

#endif /* CLXX_KERNEL_EXEC_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4: