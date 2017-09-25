// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/retain_device.t.h

/** // doc: clxx/b5d/cl_fcn/retain_device.t.h {{{
 * \file clxx/b5d/cl_fcn/retain_device.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_RETAIN_DEVICE_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_RETAIN_DEVICE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class retain_device_test_suite; }

/** // doc: class clxx::retain_device_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::retain_device_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  retain_device()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__retain_device() {{{
   * Test \ref retain_device() in normal situation
   */ // }}}
  void test__retain_device( )
  {
#if CLXX_B5D_PROVIDES(retain_device)
    T::Dummy_clRetainDevice mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(retain_device((cl_device_id)0x1234));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234));
#else
    TS_SKIP("retain_device not implemented");
#endif
  }
  /** // doc: test__retain_device__invalid_device() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns CL_INVALID_DEVICE
   */ // }}}
  void test__retain_device__invalid_device( )
  {
#if CLXX_B5D_PROVIDES(retain_device)
    T::Dummy_clRetainDevice mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(retain_device(NULL),clerror_no<status_t::invalid_device>);
#else
    TS_SKIP("retain_device not implemented");
#endif
  }
  /** // doc: test__retain_device__out_of_resources() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__retain_device__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(retain_device)
    T::Dummy_clRetainDevice mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_device(NULL),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("retain_device not implemented");
#endif
  }
  /** // doc: test__retain_device__out_of_host_memory() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__retain_device__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(retain_device)
    T::Dummy_clRetainDevice mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_device(NULL),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("retain_device not implemented");
#endif
  }
  /** // doc: test__retain_device__unexpected_clerror() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns unexpected error code
   */ // }}}
  void test__retain_device__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(retain_device)
    T::Dummy_clRetainDevice mock(-0x1234567);
    TS_ASSERT_THROWS(retain_device(NULL),unexpected_clerror);
#else
    TS_SKIP("retain_device not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_RETAIN_DEVICE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
