// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/create_sub_devices.t.h

/** // doc: clxx/b5d/cl_fcn/create_sub_devices.t.h {{{
 * \file clxx/b5d/cl_fcn/create_sub_devices.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_CREATE_SUB_DEVICES_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_CREATE_SUB_DEVICES_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class create_sub_devices_test_suite; }

/** // doc: class clxx::create_sub_devices_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::create_sub_devices_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  create_sub_devices()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_sub_devices() {{{
   * \brief Test \ref create_sub_devices()() in normal situation.
   */ // }}}
  void test__create_sub_devices( )
  {
#if CLXX_B5D_PROVIDES(create_sub_devices)
    T::Dummy_clCreateSubDevices mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(create_sub_devices((cl_device_id)0x1234, (const cl_device_partition_property*)0x5678, 2, (cl_device_id*)0x4321, (cl_uint*)0x8765));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234, (const cl_device_partition_property*)0x5678, 2, (cl_device_id*)0x4321, (cl_uint*)0x8765));
#else
    TS_SKIP("create_sub_devices not implemented");
#endif
  }
  /** // doc: test__create_sub_devices__invalid_device() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_INVALID_DEVICE
   */ // }}}
  void test__create_sub_devices__invalid_device( )
  {
#if CLXX_B5D_PROVIDES(create_sub_devices)
    T::Dummy_clCreateSubDevices mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_device>);
#else
    TS_SKIP("create_sub_devices not implemented");
#endif
  }
  /** // doc: test__create_sub_devices__invalid_value() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_INVALID_VALUE
   */ // }}}
  void test__create_sub_devices__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(create_sub_devices)
    T::Dummy_clCreateSubDevices mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("create_sub_devices not implemented");
#endif
  }
  /** // doc: test__create_sub_devices__device_partition_failed() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_DEVICE_PARTITION_FAILED
   */ // }}}
  void test__create_sub_devices__device_partition_failed( )
  {
#if CLXX_B5D_PROVIDES(create_sub_devices)
    T::Dummy_clCreateSubDevices mock(CL_DEVICE_PARTITION_FAILED);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::device_partition_failed>);
#else
    TS_SKIP("create_sub_devices not implemented");
#endif
  }
  /** // doc: test__create_sub_devices__invalid_device_partition_count() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_INVALID_DEVICE_PARTITION_COUNT
   */ // }}}
  void test__create_sub_devices__invalid_device_partition_count( )
  {
#if CLXX_B5D_PROVIDES(create_sub_devices)
    T::Dummy_clCreateSubDevices mock(CL_INVALID_DEVICE_PARTITION_COUNT);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_device_partition_count>);
#else
    TS_SKIP("create_sub_devices not implemented");
#endif
  }
  /** // doc: test__create_sub_devices__out_of_resources() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__create_sub_devices__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(create_sub_devices)
    T::Dummy_clCreateSubDevices mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("create_sub_devices not implemented");
#endif
  }
  /** // doc: test__create_sub_devices__out_of_host_memory() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__create_sub_devices__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(create_sub_devices)
    T::Dummy_clCreateSubDevices mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("create_sub_devices not implemented");
#endif
  }
  /** // doc: test__create_sub_devices__unexpected_clerror() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns unexpected error code
   */ // }}}
  void test__create_sub_devices__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(create_sub_devices)
    T::Dummy_clCreateSubDevices mock(-0x12334567);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("create_sub_devices not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_CREATE_SUB_DEVICES_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
