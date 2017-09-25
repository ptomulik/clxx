// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_functions/release_device.t.h

/** // doc: clxx/b5d/cl_functions/release_device.t.h {{{
 * \file clxx/b5d/cl_functions/release_device.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FUNCTIONS_RELEASE_DEVICE_T_H_INCLUDED
#define CLXX_B5D_CL_FUNCTIONS_RELEASE_DEVICE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_functions.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class release_device_test_suite; }

/** // doc: class clxx::release_device_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::release_device_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  release_device()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__release_device() {{{
   * \brief Test \ref release_device() in normal situation
   */ // }}}
  void test__release_device( )
  {
#if CLXX_B5D_PROVIDES(release_device)
    T::Dummy_clReleaseDevice mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_device((cl_device_id)0x1234));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234));
#else
    TS_SKIP("release_device not implemented");
#endif
  }
  /** // doc: test__release_device__invalid_device() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_INVALID_DEVICE
   */ // }}}
  void test__release_device__invalid_device( )
  {
#if CLXX_B5D_PROVIDES(release_device)
    T::Dummy_clReleaseDevice mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::invalid_device>);
#else
    TS_SKIP("release_device not implemented");
#endif
  }
  /** // doc: test__release_device__out_of_resources() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__release_device__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(release_device)
    T::Dummy_clReleaseDevice mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("release_device not implemented");
#endif
  }
  /** // doc: test__release_device__out_of_host_memory() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__release_device__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(release_device)
    T::Dummy_clReleaseDevice mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("release_device not implemented");
#endif
  }
  /** // doc: test__release_device__unexpected_clerror() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns unexpected error code
   */ // }}}
  void test__release_device__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(release_device)
    T::Dummy_clReleaseDevice mock(-0x1234567);
    TS_ASSERT_THROWS(release_device(NULL),unexpected_clerror);
#else
    TS_SKIP("release_device not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FUNCTIONS_RELEASE_DEVICE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
