// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/devices.t.h

/** // doc: clxx/devices.t.h {{{
 * \file clxx/devices.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_DEVICES_T_H_INCLUDED
#define CLXX_CL_DEVICES_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/devices.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class devices_test__suite; }

/** // doc: class clxx::devices_test__suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::devices_test__suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__get_num_devices_0() {{{
   * \brief Test get_num_devices() on Newton.
   */ // }}}
  void test__get_num_devices_1( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id const p = T::Newton_clGetPlatformIDs::platforms[0];
    TS_ASSERT_EQUALS(get_num_devices(p,device_type_t::cpu),1);
    TS_ASSERT_EQUALS(get_num_devices(p,device_type_t::gpu),0);
    TS_ASSERT_EQUALS(get_num_devices(p,device_type_t::accelerator),0);
    TS_ASSERT_EQUALS(get_num_devices(p,device_type_t::custom),0);
    TS_ASSERT_EQUALS(get_num_devices(p,device_type_t::default_),1);
    TS_ASSERT_EQUALS(get_num_devices(p,device_type_t::all),1);
  }
  /** // doc: test__get_num_devices_1() {{{
   * \brief Test get_num_devices() on Newton.
   */ // }}}
  void test__get_num_devices_2( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id const p = T::Newton_clGetPlatformIDs::platforms[1];
    TS_ASSERT_EQUALS(get_num_devices(p,device_type_t::cpu),0);
    TS_ASSERT_EQUALS(get_num_devices(p,device_type_t::gpu),2);
    TS_ASSERT_EQUALS(get_num_devices(p,device_type_t::accelerator),0);
    TS_ASSERT_EQUALS(get_num_devices(p,device_type_t::custom),0);
    TS_ASSERT_EQUALS(get_num_devices(p,device_type_t::all),2);
  }
  /** // doc: test__get_device_ids_3() {{{
   * \brief Test get_device_ids() on Newton - vector version.
   */ // }}}
  void test__get_device_ids_3( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[0];
    std::vector<cl_device_id> devices(get_device_ids(p,device_type_t::all));
    TS_ASSERT_EQUALS(devices[0], T::Newton_clGetDeviceIDs::devices[0]);
  }
  /** // doc: test__get_device_ids_4() {{{
   * \brief Test get_device_ids() on Newton - vector version.
   */ // }}}
  void test__get_device_ids_4( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[1];
    std::vector<cl_device_id> devices(get_device_ids(p,device_type_t::all));
    TS_ASSERT_EQUALS(devices[0], T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(devices[1], T::Newton_clGetDeviceIDs::devices[2]);
  }
  /** // doc: test__get_devices_1() {{{
   * \brief Test get_devices() on Newton.
   */ // }}}
  void test__get_devices_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[0];
    devices devices(get_devices(p, device_type_t::all));
    TS_ASSERT_EQUALS(static_cast<device>(devices[0]).handle(), T::Newton_clGetDeviceIDs::devices[0]);
  }
  /** // doc: test__get_devices_2() {{{
   * \brief Test get_devices() on Newton.
   */ // }}}
  void test__get_devices_2( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[1];
    devices devices(get_devices(p, device_type_t::all));
    TS_ASSERT_EQUALS(static_cast<device>(devices[0]).handle(), T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(static_cast<device>(devices[1]).handle(), T::Newton_clGetDeviceIDs::devices[2]);
  }
  /** // doc: test__get_devices_3() {{{
   * \brief Test get_devices() on Newton.
   */ // }}}
  void test__get_devices_3( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetDeviceIDs mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    devices devices(get_devices(p, device_type_t::all));
    TS_ASSERT_EQUALS(((device)devices[0]).handle(), T::Newton_clGetDeviceIDs::devices[0]);
  }
  /** // doc: test__get_devices_4() {{{
   * \brief Test get_devices() on Newton.
   */ // }}}
  void test__get_devices_4( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetDeviceIDs mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[1]);
    devices devices(get_devices(p, device_type_t::all));
    TS_ASSERT_EQUALS(((device)devices[0]).handle(), T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(((device)devices[1]).handle(), T::Newton_clGetDeviceIDs::devices[2]);
  }
  /** // doc: test__invalid_platform() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_INVALID_PLATFORM.
   */ // }}}
  void test__invalid_platform( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(get_num_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_platform>);
    TS_ASSERT_THROWS(get_device_ids(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_platform>);
    TS_ASSERT_THROWS(get_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test__invalid_device_type() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_INVALID_DEVICE_TYPE.
   */ // }}}
  void test__invalid_device_type( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_THROWS(get_num_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_device_type>);
    TS_ASSERT_THROWS(get_device_ids(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_device_type>);
    TS_ASSERT_THROWS(get_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_device_type>);
    TS_ASSERT_THROWS(get_devices(platform(NULL),static_cast<device_type_t>(0)),clerror_no<status_t::invalid_device_type>);
  }
  /** // doc: test__invalid_value() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_INVALID_VALUE.
   */ // }}}
  void test__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_num_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_value>);
    TS_ASSERT_THROWS(get_device_ids(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_value>);
    TS_ASSERT_THROWS(get_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_value>);
    TS_ASSERT_THROWS(get_devices(platform(NULL),static_cast<device_type_t>(0)),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__device_not_found() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_DEVICE_NOT_FOUND.
   */ // }}}
  void test__device_not_found( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(CL_DEVICE_NOT_FOUND);
    TS_ASSERT_THROWS_NOTHING(get_num_devices(NULL,static_cast<device_type_t>(0)))
    TS_ASSERT_THROWS_NOTHING(get_device_ids(NULL,static_cast<device_type_t>(0)))
    TS_ASSERT_THROWS_NOTHING(get_devices(NULL,static_cast<device_type_t>(0)))
    TS_ASSERT_THROWS_NOTHING(get_devices(platform(NULL),static_cast<device_type_t>(0)))
  }
  /** // doc: test__out_of_resources() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_num_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(get_device_ids(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(get_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(get_devices(platform(NULL),static_cast<device_type_t>(0)),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__out_of_host_memory() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_num_devices(NULL,static_cast<device_type_t>(0)), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(get_device_ids(NULL,static_cast<device_type_t>(0)), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(get_devices(NULL,static_cast<device_type_t>(0)), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(get_devices(platform(NULL),static_cast<device_type_t>(0)), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__other_error() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        unknown error code.
   */ // }}}
  void test__other_error( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_num_devices(NULL,static_cast<device_type_t>(0)),unexpected_clerror);
    TS_ASSERT_THROWS(get_device_ids(NULL,static_cast<device_type_t>(0)),unexpected_clerror);
    TS_ASSERT_THROWS(get_devices(NULL,static_cast<device_type_t>(0)),unexpected_clerror);
    TS_ASSERT_THROWS(get_devices(platform(NULL),static_cast<device_type_t>(0)),unexpected_clerror);
  }
};

#endif /* CLXX_CL_DEVICES_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
