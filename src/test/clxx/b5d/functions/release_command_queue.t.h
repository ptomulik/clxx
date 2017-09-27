// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/release_command_queue.t.h

/** // doc: clxx/b5d/functions/release_command_queue.t.h {{{
 * \file clxx/b5d/functions/release_command_queue.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_RELEASE_COMMAND_QUEUE_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_RELEASE_COMMAND_QUEUE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class release_command_queue_test_suite; }

/** // doc: class clxx::release_command_queue_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::release_command_queue_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  release_command_queue()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__release_command_queue() {{{
   * \brief Test release_command_queue() in a normal situation
   */ // }}}
  void test__release_command_queue( )
  {
#if CLXX_B5D_PROVIDES(release_command_queue)
    T::Dummy_clReleaseCommandQueue mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_command_queue((cl_command_queue)NULL));
    TS_ASSERT(mock.called_once_with((cl_command_queue)NULL));
#else
    TS_SKIP("release_command_queue not implemented");
#endif
  }
  /** // doc: test__release_command_queue__invalid_command_queue() {{{
   * \brief Test release_command_queue() in a situation when clReleaseCommandQueue() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__release_command_queue__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(release_command_queue)
    T::Dummy_clReleaseCommandQueue mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(release_command_queue((cl_command_queue)NULL), clerror_no<status_t::invalid_command_queue>);
#else
    TS_SKIP("release_command_queue not implemented");
#endif
  }
  /** // doc: test__release_command_queue__out_of_resources() {{{
   * \brief Test release_command_queue() in a situation when clReleaseCommandQueue() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__release_command_queue__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(release_command_queue)
    T::Dummy_clReleaseCommandQueue mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("release_command_queue not implemented");
#endif
  }
  /** // doc: test__release_command_queue__out_of_host_memory() {{{
   * \brief Test release_command_queue() in a situation when clReleaseCommandQueue() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__release_command_queue__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(release_command_queue)
    T::Dummy_clReleaseCommandQueue mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("release_command_queue not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_RELEASE_COMMAND_QUEUE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
