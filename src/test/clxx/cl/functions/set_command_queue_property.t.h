// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/set_command_queue_property.t.h

/** // doc: clxx/cl/functions/set_command_queue_property.t.h {{{
 * \file clxx/cl/functions/set_command_queue_property.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_SET_COMMAND_QUEUE_PROPERTY_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_SET_COMMAND_QUEUE_PROPERTY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_set_command_queue_property_test_suite; }

/** // doc: class clxx::functions_set_command_queue_property_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_set_command_queue_property_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  set_command_queue_property()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__set_command_queue_property() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_command_queue_property( )
  {
#if CLXX_OPENCL_ALLOWED(clSetCommandQueueProperty)
    T::Dummy_clSetCommandQueueProperty mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_command_queue_property((cl_command_queue)0x123, command_queue_properties_t::profiling_enable, CL_TRUE, (cl_command_queue_properties*)0x2222));
    TS_ASSERT(mock.called_once_with((cl_command_queue)0x123, CL_QUEUE_PROFILING_ENABLE, CL_TRUE, (cl_command_queue_properties*)0x2222));
#endif
  }
  /** // doc: test__set_command_queue_property__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_command_queue_property__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clSetCommandQueueProperty)
    T::Dummy_clSetCommandQueueProperty mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(set_command_queue_property((cl_command_queue)NULL, command_queue_properties_t::none, CL_FALSE, nullptr), clerror_no<status_t::invalid_command_queue>);
#endif
  }
  /** // doc: test__set_command_queue_property__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_command_queue_property__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clSetCommandQueueProperty)
    T::Dummy_clSetCommandQueueProperty mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(set_command_queue_property((cl_command_queue)NULL, command_queue_properties_t::none, CL_FALSE, nullptr), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__set_command_queue_property__invalid_queue_properties() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_command_queue_property__invalid_queue_properties( )
  {
#if CLXX_OPENCL_ALLOWED(clSetCommandQueueProperty)
    T::Dummy_clSetCommandQueueProperty mock(CL_INVALID_QUEUE_PROPERTIES);
    TS_ASSERT_THROWS(set_command_queue_property((cl_command_queue)NULL, command_queue_properties_t::none, CL_FALSE, nullptr), clerror_no<status_t::invalid_queue_properties>);
#endif
  }
  /** // doc: test__set_command_queue_property__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_command_queue_property__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clSetCommandQueueProperty)
    T::Dummy_clSetCommandQueueProperty mock(-0x1234567);
    TS_ASSERT_THROWS(set_command_queue_property((cl_command_queue)NULL, command_queue_properties_t::none, CL_FALSE, nullptr), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_SET_COMMAND_QUEUE_PROPERTY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
