// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/get_host_timer.t.h

/** // doc: clxx/b5d/cl_fcn/get_host_timer.t.h {{{
 * \file clxx/b5d/cl_fcn/get_host_timer.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_GET_HOST_TIMER_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_GET_HOST_TIMER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class get_host_timer_test_suite; }

/** // doc: class clxx::get_host_timer_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::get_host_timer_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_host_timer()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_host_timer() {{{
   * \brief Test get_host_timer() in a normal situation
   */ // }}}
  void test__get_host_timer()
  {
#if CLXX_B5D_PROVIDES(get_host_timer)
    T::Dummy_clGetHostTimer mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_host_timer((cl_device_id)0x1234, (cl_ulong*)0x1111));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234, (cl_ulong*)0x1111));
#else
    TS_SKIP("get_host_timer not implemented");
#endif
  }
  /** // doc: test__get_host_timer__invalid_device() {{{
   * \brief Test get_host_timer() in a situation when clGetHostTimer() returns CL_INVALID_DEVICE
   */ // }}}
  void test__get_host_timer__invalid_device()
  {
#if CLXX_B5D_PROVIDES(get_host_timer)
    T::Dummy_clGetHostTimer mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(get_host_timer((cl_device_id)NULL, nullptr), clerror_no<status_t::invalid_device>);
#else
    TS_SKIP("get_host_timer not implemented");
#endif
  }
  /** // doc: test__get_host_timer__invalid_value() {{{
   * \brief Test get_host_timer() in a situation when clGetHostTimer() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_host_timer__invalid_value()
  {
#if CLXX_B5D_PROVIDES(get_host_timer)
    T::Dummy_clGetHostTimer mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_host_timer((cl_device_id)NULL, nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("get_host_timer not implemented");
#endif
  }
  /** // doc: test__get_host_timer__out_of_resources() {{{
   * \brief Test get_host_timer() in a situation when clGetHostTimer() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__get_host_timer__out_of_resources()
  {
#if CLXX_B5D_PROVIDES(get_host_timer)
    T::Dummy_clGetHostTimer mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_host_timer((cl_device_id)NULL, nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("get_host_timer not implemented");
#endif
  }
  /** // doc: test__get_host_timer__out_of_host_memory() {{{
   * \brief Test get_host_timer() in a situation when clGetHostTimer() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_host_timer__out_of_host_memory()
  {
#if CLXX_B5D_PROVIDES(get_host_timer)
    T::Dummy_clGetHostTimer mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_host_timer((cl_device_id)NULL, nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("get_host_timer not implemented");
#endif
  }
  /** // doc: test__get_host_timer__other_error() {{{
   * \brief Test get_host_timer() in a situation when clGetHostTimer() returns an unexpected error code
   */ // }}}
  void test__get_host_timer__other_error()
  {
#if CLXX_B5D_PROVIDES(get_host_timer)
    T::Dummy_clGetHostTimer mock(-0x3456);
    TS_ASSERT_THROWS(get_host_timer((cl_device_id)NULL, nullptr), unexpected_clerror);
#else
    TS_SKIP("get_host_timer not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_GET_HOST_TIMER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
