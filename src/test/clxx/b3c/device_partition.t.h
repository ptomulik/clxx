// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b3c/device_partition.t.h

/** // doc: clxx/b3c/device_partition.t.h {{{
 * \file clxx/b3c/device_partition.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B3C_DEVICE_PARTITION_T_H_INCLUDED
#define CLXX_B3C_DEVICE_PARTITION_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b3c/device_partition.hpp>
#include <clxx/b5d/mocks/functions.hpp>

namespace clxx { class device_partition_test_suite; }

/** // doc: class clxx::device_partition_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::device_partition_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_get_num_sub_devices_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_num_sub_devices_1( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clCreateSubDevices)
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clCreateSubDevices mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_num_sub_devices(device((cl_device_id)0x1234),device_partition_properties()));
    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()),(cl_device_id)0x1234);
    TS_ASSERT(std::get<1>(mock.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()),0);
    TS_ASSERT_EQUALS(std::get<3>(mock.calls().back()), static_cast<const void*>(nullptr));
    TS_ASSERT(std::get<4>(mock.calls().back()) != nullptr);
#endif
  }
  /** // doc: test_create_sub_devices_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_create_sub_devices_1( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clCreateSubDevices)
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clCreateSubDevices mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(create_sub_devices(device((cl_device_id)0x1234), make_device_partition_properties(device_partition_equally(2))));

    TS_ASSERT(mock.called_once());

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()),(cl_device_id)0x1234);
    TS_ASSERT(std::get<1>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0);
    TS_ASSERT_EQUALS(std::get<3>(mock.calls().front()), static_cast<const void*>(nullptr));
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);
#endif
  }
  /** // doc: test_create_sub_devices_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_create_sub_devices_2( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clCreateSubDevices)
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Pluggable_clCreateSubDevices mock(
        [] (cl_device_id,
            const cl_device_partition_property*,
            cl_uint num_devices,
            cl_device_id* out_devices,
            cl_uint* num_devices_ret) -> cl_int {
          if(out_devices) {
            if(num_devices > 0) out_devices[0] = (cl_device_id)0x2345;
            if(num_devices > 1) out_devices[1] = (cl_device_id)0x3456;
          }
          if(num_devices_ret) {
            if(num_devices > 0 && out_devices) {
              *num_devices_ret = num_devices < 2u ? num_devices : 2u;
            } else {
              *num_devices_ret = 2u;
            }
          }
          return CL_SUCCESS;
        }
    );


    devices devs(create_sub_devices(device((cl_device_id)0x1234), make_device_partition_properties(device_partition_equally(2))));

    TS_ASSERT(mock.called_twice());

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()),(cl_device_id)0x1234);
    TS_ASSERT(std::get<1>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0);
    TS_ASSERT_EQUALS(std::get<3>(mock.calls().front()), static_cast<const void*>(nullptr));
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()),(cl_device_id)0x1234);
    TS_ASSERT(std::get<1>(mock.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), 2u);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<4>(mock.calls().back()), static_cast<const void*>(nullptr));

    TS_ASSERT_EQUALS(devs.size(),2);
    TS_ASSERT_EQUALS(devs[0].get(), (cl_device_id)0x2345);
    TS_ASSERT_EQUALS(devs[1].get(), (cl_device_id)0x3456);
#endif
  }
};

#endif /* CLXX_B3C_DEVICE_PARTITION_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4: