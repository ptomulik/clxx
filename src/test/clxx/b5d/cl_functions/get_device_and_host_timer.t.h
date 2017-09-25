// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_functions/get_device_and_host_timer.t.h

/** // doc: clxx/b5d/cl_functions/get_device_and_host_timer.t.h {{{
 * \file clxx/b5d/cl_functions/get_device_and_host_timer.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FUNCTIONS_GET_DEVICE_AND_HOST_TIMER_T_H_INCLUDED
#define CLXX_B5D_CL_FUNCTIONS_GET_DEVICE_AND_HOST_TIMER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_functions.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class get_device_and_host_timer_test_suite; }

/** // doc: class clxx::get_device_and_host_timer_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::get_device_and_host_timer_test_suite : public CxxTest::TestSuite
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
#if CLXX_B5D_PROVIDES(get_device_and_host_timer)
    T::Dummy_clGetDeviceAndHostTimer mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_device_and_host_timer((cl_device_id)0x1234, (cl_ulong*)0x1111, (cl_ulong*)0x2222));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234, (cl_ulong*)0x1111, (cl_ulong*)0x2222));
#else
    TS_SKIP("get_device_and_host_timer not implemented");
#endif
  }
  /** // doc: test__get_device_and_host_timer__invalid_device() {{{
   * \brief Test get_device_and_host_timer() in a situation when clGetDeviceAndHostTimer() returns CL_INVALID_DEVICE
   */ // }}}
  void test__get_device_and_host_timer__invalid_device()
  {
#if CLXX_B5D_PROVIDES(get_device_and_host_timer)
    T::Dummy_clGetDeviceAndHostTimer mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(get_device_and_host_timer((cl_device_id)NULL, nullptr, nullptr), clerror_no<status_t::invalid_device>);
#else
    TS_SKIP("get_device_and_host_timer not implemented");
#endif
  }
  /** // doc: test__get_device_and_host_timer__invalid_value() {{{
   * \brief Test get_device_and_host_timer() in a situation when clGetDeviceAndHostTimer() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_device_and_host_timer__invalid_value()
  {
#if CLXX_B5D_PROVIDES(get_device_and_host_timer)
    T::Dummy_clGetDeviceAndHostTimer mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_device_and_host_timer((cl_device_id)NULL, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("get_device_and_host_timer not implemented");
#endif
  }
  /** // doc: test__get_device_and_host_timer__out_of_resources() {{{
   * \brief Test get_device_and_host_timer() in a situation when clGetDeviceAndHostTimer() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__get_device_and_host_timer__out_of_resources()
  {
#if CLXX_B5D_PROVIDES(get_device_and_host_timer)
    T::Dummy_clGetDeviceAndHostTimer mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_device_and_host_timer((cl_device_id)NULL, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("get_device_and_host_timer not implemented");
#endif
  }
  /** // doc: test__get_device_and_host_timer__out_of_host_memory() {{{
   * \brief Test get_device_and_host_timer() in a situation when clGetDeviceAndHostTimer() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_device_and_host_timer__out_of_host_memory()
  {
#if CLXX_B5D_PROVIDES(get_device_and_host_timer)
    T::Dummy_clGetDeviceAndHostTimer mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_device_and_host_timer((cl_device_id)NULL, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("get_device_and_host_timer not implemented");
#endif
  }
  /** // doc: test__get_device_and_host_timer__other_error() {{{
   * \brief Test get_device_and_host_timer() in a situation when clGetDeviceAndHostTimer() returns an unexpected error code
   */ // }}}
  void test__get_device_and_host_timer__other_error()
  {
#if CLXX_B5D_PROVIDES(get_device_and_host_timer)
    T::Dummy_clGetDeviceAndHostTimer mock(-0x3456);
    TS_ASSERT_THROWS(get_device_and_host_timer((cl_device_id)NULL, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("get_device_and_host_timer not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FUNCTIONS_GET_DEVICE_AND_HOST_TIMER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
