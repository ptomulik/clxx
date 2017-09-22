// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl/enqueue_barrier.t.h

/** // doc: clxx/b5d/cl/enqueue_barrier.t.h {{{
 * \file clxx/b5d/cl/enqueue_barrier.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_ENQUEUE_BARRIER_T_H_INCLUDED
#define CLXX_B5D_CL_ENQUEUE_BARRIER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class enqueue_barrier_test_suite; }

/** // doc: class clxx::enqueue_barrier_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::enqueue_barrier_test_suite : public CxxTest::TestSuite
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
#if CLXX_B5D_PROVIDES(enqueue_barrier)
    T::Dummy_clEnqueueBarrier mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_barrier((cl_command_queue)0x123));
    TS_ASSERT(mock.called_once_with((cl_command_queue)0x123));
#else
    TS_SKIP("enqueue_barrier not implemented");
#endif
  }
  /** // doc: test__enqueue_barrier__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_barrier__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(enqueue_barrier)
    T::Dummy_clEnqueueBarrier mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_barrier((cl_command_queue)NULL), clerror_no<status_t::invalid_command_queue>);
#else
    TS_SKIP("enqueue_barrier not implemented");
#endif
  }
  /** // doc: test__enqueue_barrier__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_barrier__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(enqueue_barrier)
    T::Dummy_clEnqueueBarrier mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_barrier((cl_command_queue)NULL), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("enqueue_barrier not implemented");
#endif
  }
  /** // doc: test__enqueue_barrier__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_barrier__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(enqueue_barrier)
    T::Dummy_clEnqueueBarrier mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_barrier((cl_command_queue)NULL), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("enqueue_barrier not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_ENQUEUE_BARRIER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
