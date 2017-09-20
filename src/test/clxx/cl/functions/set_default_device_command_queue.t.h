// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/set_default_device_command_queue.t.h

/** // doc: clxx/cl/functions/set_default_device_command_queue.t.h {{{
 * \file clxx/cl/functions/set_default_device_command_queue.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_SET_DEFAULT_DEVICE_COMMAND_QUEUE_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_SET_DEFAULT_DEVICE_COMMAND_QUEUE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_set_default_device_command_queue_test_suite; }

/** // doc: class clxx::functions_set_default_device_command_queue_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_set_default_device_command_queue_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  set_default_device_command_queue()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__set_default_device_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_default_device_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clSetDefaultDeviceCommandQueue)
    T::Dummy_clSetDefaultDeviceCommandQueue mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_default_device_command_queue((cl_context)0x123, (cl_device_id)0x1111, (cl_command_queue)0x2222));
    TS_ASSERT(mock.called_once_with((cl_context)0x123, (cl_device_id)0x1111, (cl_command_queue)0x2222));
#endif
  }
  /** // doc: test__set_default_device_command_queue__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_default_device_command_queue__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clSetDefaultDeviceCommandQueue)
    T::Dummy_clSetDefaultDeviceCommandQueue mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(set_default_device_command_queue((cl_context)NULL, (cl_device_id)NULL, (cl_command_queue)NULL), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__set_default_device_command_queue__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_default_device_command_queue__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clSetDefaultDeviceCommandQueue)
    T::Dummy_clSetDefaultDeviceCommandQueue mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(set_default_device_command_queue((cl_context)NULL, (cl_device_id)NULL, (cl_command_queue)NULL), clerror_no<status_t::invalid_device>);
#endif
  }
  /** // doc: test__set_default_device_command_queue__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_default_device_command_queue__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clSetDefaultDeviceCommandQueue)
    T::Dummy_clSetDefaultDeviceCommandQueue mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(set_default_device_command_queue((cl_context)NULL, (cl_device_id)NULL, (cl_command_queue)NULL), clerror_no<status_t::invalid_command_queue>);
#endif
  }
  /** // doc: test__set_default_device_command_queue__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_default_device_command_queue__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clSetDefaultDeviceCommandQueue)
    T::Dummy_clSetDefaultDeviceCommandQueue mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(set_default_device_command_queue((cl_context)NULL, (cl_device_id)NULL, (cl_command_queue)NULL), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__set_default_device_command_queue__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_default_device_command_queue__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clSetDefaultDeviceCommandQueue)
    T::Dummy_clSetDefaultDeviceCommandQueue mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(set_default_device_command_queue((cl_context)NULL, (cl_device_id)NULL, (cl_command_queue)NULL), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__set_default_device_command_queue__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_default_device_command_queue__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clSetDefaultDeviceCommandQueue)
    T::Dummy_clSetDefaultDeviceCommandQueue mock(-0x1234567);
    TS_ASSERT_THROWS(set_default_device_command_queue((cl_context)NULL, (cl_device_id)NULL, (cl_command_queue)NULL), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_SET_DEFAULT_DEVICE_COMMAND_QUEUE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
