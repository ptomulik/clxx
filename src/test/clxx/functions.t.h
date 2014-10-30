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

// clxx/functions.t.h

/** // doc: clxx/functions.t.h {{{
 * \file clxx/functions.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_T_H_INCLUDED
#define CLXX_FUNCTIONS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_test_suite; }

/** // doc: class clxx::functions_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_get_device_ids_1() {{{
   * \brief Test get_device_ids() on Newton - array version.
   */ // }}}
  void test_get_device_ids_1( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[0];
    cl_device_id devices[1];
    get_device_ids(p,device_type_t::all,1,devices,NULL);
    TS_ASSERT_EQUALS(devices[0], T::Newton_clGetDeviceIDs::devices[0]);
  }
  /** // doc: test_get_device_ids_2() {{{
   * \brief Test get_device_ids() on Newton - array version.
   */ // }}}
  void test_get_device_ids_2( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[1];
    cl_device_id devices[2];
    get_device_ids(p,device_type_t::all,2,devices,NULL);
    TS_ASSERT_EQUALS(devices[0], T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(devices[1], T::Newton_clGetDeviceIDs::devices[2]);
  }
  /** // doc: test_get_device_ids_invalid_platform() {{{
   * \brief Test get_device_ids() on Newton when called with invalid platform id.
   */ // }}}
  void test_get_device_ids_invalid_platform( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = reinterpret_cast<cl_platform_id>(0x123456);
    cl_device_id devices[1];
    TS_ASSERT_THROWS(get_device_ids(p,device_type_t::all,1,devices,NULL), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test_get_device_ids_zero_num_entries() {{{
   * \brief Test get_device_ids() on Newton when called with num_entries == 0 and devices != NULL.
   */ // }}}
  void test_get_device_ids_zero_num_entries( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[0];
    cl_device_id devices[1];
    TS_ASSERT_THROWS(get_device_ids(p,device_type_t::all,0,devices,NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_device_ids_null_devices() {{{
   * \brief Test get_device_ids() on Newton when called with num_devices == NULL and devices != NULL.
   */ // }}}
  void test_get_device_ids_null_devices( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[0];
    TS_ASSERT_THROWS(get_device_ids(p,device_type_t::all,1,NULL,NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_device_ids_invalid_device_type() {{{
   * \brief Test get_device_ids() on Newton when called with wrong device type.
   */ // }}}
  void test_get_device_ids_invalid_device_type( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[0];
    cl_device_id devices[1];
    TS_ASSERT_THROWS(get_device_ids(p,static_cast<device_type_t>(0x34545),1,devices,NULL), clerror_no<status_t::invalid_device_type>);
  }
  /** // doc: test_get_device_ids_device_not_found() {{{
   * \brief Test get_device_ids() on Newton when called with wrong device type.
   */ // }}}
  void test_get_device_ids_device_not_found( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[0];
    cl_device_id devices[1];
    cl_uint num_devices;
    get_device_ids(p,device_type_t::accelerator,1,devices,&num_devices);
    TS_ASSERT_EQUALS(num_devices, 0);
  }
  /** // doc: test_get_device_ids_small_buffer() {{{
   * \brief Test get_device_ids() on Newton when we provide too small buffer.
   */ // }}}
  void test_get_device_ids_small_buffer( )
  {
    T::Newton_clGetDeviceIDs mock;
    cl_platform_id p = T::Newton_clGetPlatformIDs::platforms[1];
    cl_device_id devices[1];
    TS_ASSERT_THROWS(get_device_ids(p,device_type_t::all,1,devices,NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_platform_ids_1() {{{
   * \brief Test get_platform_ids() - array version.
   */ // }}}
  void test_get_platform_ids_1( )
  {
    T::Newton_clGetPlatformIDs mock;
    cl_platform_id ids[2];
    get_platform_ids(2, ids, NULL);
    TS_ASSERT_EQUALS(ids[0], T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(ids[1], T::Newton_clGetPlatformIDs::platforms[1]);
  }
  /** // doc: test_get_platform_ids_zero_num_entries() {{{
   * \brief Test get_platform_ids() - array version with num_entries == 0.
   */ // }}}
  void test_get_platform_ids_zero_num_entries( )
  {
    T::Newton_clGetPlatformIDs mock;
    cl_platform_id ids[2];
    TS_ASSERT_THROWS(get_platform_ids(0, ids, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_platform_ids_nulls() {{{
   * \brief Test get_platform_ids() - array version num_platforms == NULL and platforms == NULL.
   */ // }}}
  void test_get_platform_ids_nulls( )
  {
    T::Newton_clGetPlatformIDs mock;
    TS_ASSERT_THROWS(get_platform_ids(2, NULL, NULL), clerror_no<status_t::invalid_value>);
  }
// sorry, but this may irritate OOM instead of throw bad_alloc
//  /** // doc: test_get_platform_ids_get_platform_ids_negsize() {{{
//   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs()
//   *        returns negative num_platforms.
//   */ // }}}
//  void test_get_platform_ids_get_platform_ids_negsize( )
//  {
//    T::SizeRet_clGetPlatformIDs mock(-32);
//    TS_ASSERT_THROWS(get_platform_ids(), CLXX_EXCEPTION(Bad_Alloc));
//  }
  /** // doc: test_get_platform_ids_invalid_value() {{{
   * \brief Test get_xxx() in a situation when clGetPlatformIDs() returns
   *        status_t::invalid_value.
   */ // }}}
  void test_get_platform_ids_invalid_value( )
  {
    T::ErrRet_clGetPlatformIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_platform_ids_out_of_host_memory() {{{
   * \brief Test get_xxx() in a situation when clGetPlatformIDs() returns
   *        status_t::out_of_host_memory.
   */ // }}}
  void test_get_platform_ids_out_of_host_memory( )
  {
    T::ErrRet_clGetPlatformIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_platform_ids_other_error() {{{
   * \brief Test get_xxx() in a situation when clGetPlatformIDs() returns
   *        unknown error code.
   */ // }}}
  void test_get_platform_ids_other_error( )
  {
    T::ErrRet_clGetPlatformIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), unexpected_clerror);
  }
  /** // doc: test_get_platform_info_null_id() {{{
   * \brief Test get_platform_info(platform_info_t::profile, ...) on platform object having wrong id.
   */ // }}}
  void test_get_platform_info_null_id( )
  {
    T::Newton_clGetPlatformInfo mock;
    TS_ASSERT_THROWS(get_platform_info(NULL, platform_info_t::profile, 0, NULL, NULL), clerror_no<status_t::invalid_platform>);
  }
};

#endif /* CLXX_FUNCTIONS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
