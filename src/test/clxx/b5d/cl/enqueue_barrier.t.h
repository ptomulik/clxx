// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/enqueue_barrier.t.h

/** // doc: clxx/cl/functions/enqueue_barrier.t.h {{{
 * \file clxx/cl/functions/enqueue_barrier.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_ENQUEUE_BARRIER_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_ENQUEUE_BARRIER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_barrier_test_suite; }

/** // doc: class clxx::functions_enqueue_barrier_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_barrier_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_barrier()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_barrier() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_barrier( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueBarrier)
    T::Dummy_clEnqueueBarrier mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_barrier((cl_command_queue)0x123));
    TS_ASSERT(mock.called_once_with((cl_command_queue)0x123));
#endif
  }
  /** // doc: test__enqueue_barrier__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_barrier__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueBarrier)
    T::Dummy_clEnqueueBarrier mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_barrier((cl_command_queue)NULL), clerror_no<status_t::invalid_command_queue>);
#endif
  }
  /** // doc: test__enqueue_barrier__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_barrier__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueBarrier)
    T::Dummy_clEnqueueBarrier mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_barrier((cl_command_queue)NULL), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__enqueue_barrier__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_barrier__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueBarrier)
    T::Dummy_clEnqueueBarrier mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_barrier((cl_command_queue)NULL), clerror_no<status_t::out_of_host_memory>);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_ENQUEUE_BARRIER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
