// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/enqueue_marker.t.h

/** // doc: clxx/b5d/cl_fcn/enqueue_marker.t.h {{{
 * \file clxx/b5d/cl_fcn/enqueue_marker.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_ENQUEUE_MARKER_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_ENQUEUE_MARKER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class enqueue_marker_test_suite; }

/** // doc: class clxx::enqueue_marker_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::enqueue_marker_test_suite : public CxxTest::TestSuite
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
#if CLXX_B5D_PROVIDES(enqueue_marker)
    T::Dummy_clEnqueueMarker mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_marker( (cl_command_queue)0x123,
                                             (cl_event*)0x901));

    TS_ASSERT(mock.called_once());

    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_command_queue)0x123);
    TS_ASSERT(std::get<1>(mock.calls().back()) == (cl_event*)0x901);
#else
    TS_SKIP("enqueue_marker not implemented");
#endif
  }
  /** // doc: test__enqueue_marker__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(enqueue_marker)
    T::Dummy_clEnqueueMarker mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_marker((cl_command_queue)NULL,nullptr), clerror_no<status_t::invalid_command_queue>);
#else
    TS_SKIP("enqueue_marker not implemented");
#endif
  }
  /** // doc: test__enqueue_marker__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(enqueue_marker)
    T::Dummy_clEnqueueMarker mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_marker((cl_command_queue)NULL,nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("enqueue_marker not implemented");
#endif
  }
  /** // doc: test__enqueue_marker__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(enqueue_marker)
    T::Dummy_clEnqueueMarker mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_marker((cl_command_queue)NULL,nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("enqueue_marker not implemented");
#endif
  }
  /** // doc: test__enqueue_marker__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(enqueue_marker)
    T::Dummy_clEnqueueMarker mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_marker((cl_command_queue)NULL,nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("enqueue_marker not implemented");
#endif
  }
  /** // doc: test__enqueue_marker__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_marker__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(enqueue_marker)
    T::Dummy_clEnqueueMarker mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_marker((cl_command_queue)NULL,nullptr), unexpected_clerror);
#else
    TS_SKIP("enqueue_marker not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_ENQUEUE_MARKER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
