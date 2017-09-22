// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/enqueue_marker.t.h

/** // doc: clxx/cl/functions/enqueue_marker.t.h {{{
 * \file clxx/cl/functions/enqueue_marker.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_ENQUEUE_MARKER_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_ENQUEUE_MARKER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_marker_test_suite; }

/** // doc: class clxx::functions_enqueue_marker_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_marker_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_marker()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_marker() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueMarker)
    T::Dummy_clEnqueueMarker mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_marker( (cl_command_queue)0x123,
                                             (cl_event*)0x901));

    TS_ASSERT(mock.called_once());

    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_command_queue)0x123);
    TS_ASSERT(std::get<1>(mock.calls().back()) == (cl_event*)0x901);
#endif
  }
  /** // doc: test__enqueue_marker__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueMarker)
    T::Dummy_clEnqueueMarker mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_marker((cl_command_queue)NULL,nullptr), clerror_no<status_t::invalid_command_queue>);
#endif
  }
  /** // doc: test__enqueue_marker__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueMarker)
    T::Dummy_clEnqueueMarker mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_marker((cl_command_queue)NULL,nullptr), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__enqueue_marker__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueMarker)
    T::Dummy_clEnqueueMarker mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_marker((cl_command_queue)NULL,nullptr), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__enqueue_marker__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueMarker)
    T::Dummy_clEnqueueMarker mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_marker((cl_command_queue)NULL,nullptr), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__enqueue_marker__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clEnqueueMarker)
    T::Dummy_clEnqueueMarker mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_marker((cl_command_queue)NULL,nullptr), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_ENQUEUE_MARKER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
