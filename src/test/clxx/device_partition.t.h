/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE
 */

// clxx/device_partition.t.h

/** // doc: clxx/device_partition.t.h {{{
 * \file clxx/device_partition.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_DEVICE_PARTITION_T_H_INCLUDED
#define CLXX_DEVICE_PARTITION_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/device_partition.hpp>
#include <clxx/cl/mock.hpp>

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
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_num_sub_devices(device((cl_device_id)0x1234),device_partition_properties()));
    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()),(cl_device_id)0x1234);
    TS_ASSERT(std::get<1>(mock.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()),0);
    TS_ASSERT_EQUALS(std::get<3>(mock.calls().back()),nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) != nullptr);
#endif
  }
  /** // doc: test_get_sub_devices_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_sub_devices_1( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(get_sub_devices(device((cl_device_id)0x1234), make_device_partition_properties(device_partition_equally(2))));

    TS_ASSERT(mock.called_once());

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()),(cl_device_id)0x1234);
    TS_ASSERT(std::get<1>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0);
    TS_ASSERT_EQUALS(std::get<3>(mock.calls().front()), nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);
#endif
  }
  /** // doc: test_get_sub_devices_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_sub_devices_2( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    cl_device_id const out_devices[] = { (cl_device_id)0x2345, (cl_device_id)0x3456 };
    cl_uint const num_devices_ret = 2;
    T::Dummy_clCreateSubDevices mock(CL_SUCCESS, out_devices, &num_devices_ret);

    devices devs(get_sub_devices(device((cl_device_id)0x1234), make_device_partition_properties(device_partition_equally(2))));

    TS_ASSERT(mock.called_twice());

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()),(cl_device_id)0x1234);
    TS_ASSERT(std::get<1>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0);
    TS_ASSERT_EQUALS(std::get<3>(mock.calls().front()), nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()),(cl_device_id)0x1234);
    TS_ASSERT(std::get<1>(mock.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), 2u);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<4>(mock.calls().back()), nullptr);

    TS_ASSERT_EQUALS(devs.size(),2);
    TS_ASSERT_EQUALS(devs[0].id(), (cl_device_id)0x2345);
    TS_ASSERT_EQUALS(devs[1].id(), (cl_device_id)0x3456);
#endif
  }
};

#endif /* CLXX_DEVICE_PARTITION_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4: