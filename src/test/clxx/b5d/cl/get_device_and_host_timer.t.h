// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/get_device_and_host_timer.t.h

/** // doc: clxx/cl/functions/get_device_and_host_timer.t.h {{{
 * \file clxx/cl/functions/get_device_and_host_timer.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_GET_DEVICE_AND_HOST_TIMER_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_GET_DEVICE_AND_HOST_TIMER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_get_device_and_host_timer_test_suite; }

/** // doc: class clxx::functions_get_device_and_host_timer_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_get_device_and_host_timer_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_device_and_host_timer()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_device_and_host_timer() {{{
   * \brief Test get_device_and_host_timer() in a normal situation
   */ // }}}
  void test__get_device_and_host_timer()
  {
#if CLXX_OPENCL_ALLOWED(clGetDeviceAndHostTimer)
    T::Dummy_clGetDeviceAndHostTimer mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_device_and_host_timer((cl_device_id)0x1234, (cl_ulong*)0x1111, (cl_ulong*)0x2222));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234, (cl_ulong*)0x1111, (cl_ulong*)0x2222));
#endif
  }
  /** // doc: test__get_device_and_host_timer__invalid_device() {{{
   * \brief Test get_device_and_host_timer() in a situation when clGetDeviceAndHostTimer() returns CL_INVALID_DEVICE
   */ // }}}
  void test__get_device_and_host_timer__invalid_device()
  {
#if CLXX_OPENCL_ALLOWED(clGetDeviceAndHostTimer)
    T::Dummy_clGetDeviceAndHostTimer mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(get_device_and_host_timer((cl_device_id)NULL, nullptr, nullptr), clerror_no<status_t::invalid_device>);
#endif
  }
  /** // doc: test__get_device_and_host_timer__invalid_value() {{{
   * \brief Test get_device_and_host_timer() in a situation when clGetDeviceAndHostTimer() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_device_and_host_timer__invalid_value()
  {
#if CLXX_OPENCL_ALLOWED(clGetDeviceAndHostTimer)
    T::Dummy_clGetDeviceAndHostTimer mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_device_and_host_timer((cl_device_id)NULL, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__get_device_and_host_timer__out_of_resources() {{{
   * \brief Test get_device_and_host_timer() in a situation when clGetDeviceAndHostTimer() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__get_device_and_host_timer__out_of_resources()
  {
#if CLXX_OPENCL_ALLOWED(clGetDeviceAndHostTimer)
    T::Dummy_clGetDeviceAndHostTimer mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_device_and_host_timer((cl_device_id)NULL, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__get_device_and_host_timer__out_of_host_memory() {{{
   * \brief Test get_device_and_host_timer() in a situation when clGetDeviceAndHostTimer() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_device_and_host_timer__out_of_host_memory()
  {
#if CLXX_OPENCL_ALLOWED(clGetDeviceAndHostTimer)
    T::Dummy_clGetDeviceAndHostTimer mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_device_and_host_timer((cl_device_id)NULL, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__get_device_and_host_timer__other_error() {{{
   * \brief Test get_device_and_host_timer() in a situation when clGetDeviceAndHostTimer() returns an unexpected error code
   */ // }}}
  void test__get_device_and_host_timer__other_error()
  {
#if CLXX_OPENCL_ALLOWED(clGetDeviceAndHostTimer)
    T::Dummy_clGetDeviceAndHostTimer mock(-0x3456);
    TS_ASSERT_THROWS(get_device_and_host_timer((cl_device_id)NULL, nullptr, nullptr), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_GET_DEVICE_AND_HOST_TIMER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
