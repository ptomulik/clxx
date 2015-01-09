// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

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
  /** // doc: test_get_platform_ids__success() {{{
   * \brief Test get_platform_ids() in a normal situation
   */ // }}}
  void test_get_platform_ids__success( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_platform_ids(0,nullptr,NULL));
    TS_ASSERT(mock.called_once_with(0,nullptr,NULL));
  }
  /** // doc: test_get_platform_ids__invalid_value() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns CL_INVALID_VALUE
   */ // }}}
  void test_get_platform_ids__invalid_value( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_platform_ids__out_of_host_memory() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_get_platform_ids__out_of_host_memory( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_platform_ids__other_error() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns unexpected error code.
   */ // }}}
  void test_get_platform_ids__other_error( )
  {
    T::Dummy_clGetPlatformIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), unexpected_clerror);
  }
  /** // doc: test_get_platform_info__success() {{{
   * \brief Test get_platform_info()
   */ // }}}
  void test_get_platform_info__success( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_platform_id)NULL, (cl_platform_info)0, 0, nullptr, nullptr));
  }
  /** // doc: test_get_platform_info__invalid_platform() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_INVALID_PLATFORM
   */ // }}}
  void test_get_platform_info__invalid_platform( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test_get_platform_info__invalid_value() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test_get_platform_info__invalid_value( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_platform_info__out_of_host_memory() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_get_platform_info__out_of_host_memory( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_platform_info__other_error() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_get_platform_info__other_error( )
  {
    T::Dummy_clGetPlatformInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test_get_device_ids__success() {{{
   * \brief Test get_device_ids()
   */ // }}}
  void test_get_device_ids__success( )
  {
    T::Dummy_clGetDeviceIDs mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_platform_id)NULL, CL_DEVICE_TYPE_ALL, 0, nullptr, nullptr));
  }
  /** // doc: test_get_device_ids__invalid_platform() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_INVALID_PLATFORM
   */ // }}}
  void test_get_device_ids__invalid_platform()
  {
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test_get_device_ids__invalid_device_type() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_INVALID_DEVICE_TYPE
   */ // }}}
  void test_get_device_ids__invalid_device_type()
  {
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::invalid_device_type>);
  }
  /** // doc: test_get_device_ids__invalid_value() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_INVALID_VALUE
   */ // }}}
  void test_get_device_ids__invalid_value()
  {
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_device_ids__device_not_found() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_DEVICE_NOT_FOUND
   */ // }}}
  void test_get_device_ids__device_not_found()
  {
    T::Dummy_clGetDeviceIDs mock(CL_DEVICE_NOT_FOUND);
    //TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::device_not_found>);
    TS_ASSERT_THROWS_NOTHING(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr));
  }
  /** // doc: test_get_device_ids__out_of_resources() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_get_device_ids__out_of_resources()
  {
    T::Dummy_clGetDeviceIDs mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_get_device_ids__out_of_host_memory() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_get_device_ids__out_of_host_memory()
  {
    T::Dummy_clGetDeviceIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_device_ids__other_error() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns an unexpected error code
   */ // }}}
  void test_get_device_ids__other_error()
  {
    T::Dummy_clGetDeviceIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test_get_device_info__success() {{{
   * \brief Test get_device_info() in a normal situation
   */ // }}}
  void test_get_device_info__success()
  {
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_device_id)NULL, CL_DEVICE_VENDOR_ID, 0, nullptr, nullptr));
  }
  /** // doc: test_get_device_info__invalid_device() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns CL_INVALID_DEVICE
   */ // }}}
  void test_get_device_info__invalid_device()
  {
    T::Dummy_clGetDeviceInfo mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), clerror_no<status_t::invalid_device>);
  }
  /** // doc: test_get_device_info__invalid_value() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test_get_device_info__invalid_value()
  {
    T::Dummy_clGetDeviceInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_device_info__out_of_resources() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_get_device_info__out_of_resources()
  {
    T::Dummy_clGetDeviceInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_get_device_info__out_of_host_memory() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_get_device_info__out_of_host_memory()
  {
    T::Dummy_clGetDeviceInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_device_info__other_error() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns an unexpected error code
   */ // }}}
  void test_get_device_info__other_error()
  {
    T::Dummy_clGetDeviceInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test_create_context__success() {{{
   * \brief Test create_context() in a normal situation.
   */ // }}}
  void test_create_context__success( )
  {
    T::Dummy_clCreateContext mock((cl_context)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr));
    //TS_ASSERT(mock.called_once_with(nullptr,0,nullptr,nullptr,nullptr,??? - local variable within create_context(...){...}));
  }
  /** // doc: test_create_context__invalid_platform() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_PLATFORM.
   */ // }}}
  void test_create_context__invalid_platform( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test_create_context__invalid_property() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_PROPERTY.
   */ // }}}
  void test_create_context__invalid_property( )
  {
#if CL_VERSION_1_1
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_PROPERTY);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_property>);
#endif
  }
  /** // doc: test_create_context__invalid_operation() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_OPERATION.
   */ // }}}
  void test_create_context__invalid_operation( )
  {
#if CL_VERSION_1_1
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_operation>);
#endif
  }
  /** // doc: test_create_context__invalid_value() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_VALUE.
   */ // }}}
  void test_create_context__invalid_value( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_create_context__invalid_device() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_DEVICE.
   */ // }}}
  void test_create_context__invalid_device( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_device>);
  }
  /** // doc: test_create_context__device_not_available() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test_create_context__device_not_available( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_DEVICE_NOT_AVAILABLE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::device_not_available>);
  }
  /** // doc: test_create_context__out_of_resources() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test_create_context__out_of_resources( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_create_context__out_of_host_memory() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test_create_context__out_of_host_memory( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_create_context__other_error() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns an unexpected error code.
   */ // }}}
  void test_create_context__other_error( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, -0x3456);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), unexpected_clerror);
  }
  /** // doc: test_create_context_from_type__success() {{{
   * \brief Test create_context_from_type().
   */ // }}}
  void test_create_context_from_type__success( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr));
  }
  /** // doc: test_create_context_from_type__invalid_platform() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_PLATFORM.
   */ // }}}
  void test_create_context_from_type__invalid_platform( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test_create_context_from_type__invalid_property() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_PROPERTY.
   */ // }}}
  void test_create_context_from_type__invalid_property( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_PROPERTY);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_property>);
  }
  /** // doc: test_create_context_from_type__invalid_value() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_VALUE.
   */ // }}}
  void test_create_context_from_type__invalid_value( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_create_context_from_type__invalid_device_type() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_DEVICE_TYPE.
   */ // }}}
  void test_create_context_from_type__invalid_device_type( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_device_type>);
  }
  /** // doc: test_create_context_from_type__device_not_available() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test_create_context_from_type__device_not_available( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_DEVICE_NOT_AVAILABLE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::device_not_available>);
  }
  /** // doc: test_create_context_from_type__out_of_resources() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test_create_context_from_type__out_of_resources( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_create_context_from_type__out_of_host_memory() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test_create_context_from_type__out_of_host_memory( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_create_context_from_type__other_error() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns an unexpected error code.
   */ // }}}
  void test_create_context_from_type__other_error( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, -0x3456);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), unexpected_clerror);
  }
  /** // doc: test_retain_context__success() {{{
   * \brief Test retain_context() in a normal situation
   */ // }}}
  void test_retain_context__success( )
  {
    T::Dummy_clRetainContext mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(retain_context((cl_context)NULL));
    TS_ASSERT(mock.called_once_with((cl_context)NULL));
  }
  /** // doc: test_retain_context__invalid_context() {{{
   * \brief Test retain_context() in a situation when clRetainContext() returns CL_INVALID_CONTEXT
   */ // }}}
  void test_retain_context__invalid_context( )
  {
    T::Dummy_clRetainContext mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(retain_context((cl_context)NULL), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test_retain_context__out_of_resources() {{{
   * \brief Test retain_context() in a situation when clRetainContext() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_retain_context__out_of_resources( )
  {
    T::Dummy_clRetainContext mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_context((cl_context)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_retain_context__out_of_host_memory() {{{
   * \brief Test retain_context() in a situation when clRetainContext() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_retain_context__out_of_host_memory( )
  {
    T::Dummy_clRetainContext mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_context((cl_context)NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_release_context__success() {{{
   * \brief Test release_context() in a normal situation
   */ // }}}
  void test_release_context__success( )
  {
    T::Dummy_clReleaseContext mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_context((cl_context)NULL));
    TS_ASSERT(mock.called_once_with((cl_context)NULL));
  }
  /** // doc: test_release_context__invalid_context() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_INVALID_CONTEXT
   */ // }}}
  void test_release_context__invalid_context( )
  {
    T::Dummy_clReleaseContext mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test_release_context__out_of_resources() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_release_context__out_of_resources( )
  {
    T::Dummy_clReleaseContext mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_release_context__out_of_host_memory() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_release_context__out_of_host_memory( )
  {
    T::Dummy_clReleaseContext mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_context_info__success() {{{
   * \brief Test get_context_info() in a normal situation
   */ // }}}
  void test_get_context_info__success( )
  {
    T::Dummy_clGetContextInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_context)NULL, CL_CONTEXT_REFERENCE_COUNT, 0, nullptr, nullptr));
  }
  /** // doc: test_get_context_info__invalid_context() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_INVALID_CONTEXT
   */ // }}}
  void test_get_context_info__invalid_context( )
  {
    T::Dummy_clGetContextInfo mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test_get_context_info__invalid_value() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test_get_context_info__invalid_value( )
  {
    T::Dummy_clGetContextInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_context_info__out_of_resources() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_get_context_info__out_of_resources( )
  {
    T::Dummy_clGetContextInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_get_context_info__out_of_host_memory() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_get_context_info__out_of_host_memory( )
  {
    T::Dummy_clGetContextInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_context_info__other_error() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns an unexpected error code.
   */ // }}}
  void test_get_context_info__other_error( )
  {
    T::Dummy_clGetContextInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test_create_sub_devices() {{{
   * \brief Test \ref create_sub_devices()() in normal situation.
   */ // }}}
  void test_create_sub_devices( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(create_sub_devices((cl_device_id)0x1234, (const cl_device_partition_property*)0x5678, 2, (cl_device_id*)0x4321, (cl_uint*)0x8765));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234, (const cl_device_partition_property*)0x5678, 2, (cl_device_id*)0x4321, (cl_uint*)0x8765));
#endif
  }
  /** // doc: test_create_sub_devices__invalid_device() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_INVALID_DEVICE
   */ // }}}
  void test_create_sub_devices__invalid_device( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_device>);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_create_sub_devices__invalid_value() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_INVALID_VALUE
   */ // }}}
  void test_create_sub_devices__invalid_value( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_create_sub_devices__device_partition_failed() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_DEVICE_PARTITION_FAILED
   */ // }}}
  void test_create_sub_devices__device_partition_failed( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_DEVICE_PARTITION_FAILED);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::device_partition_failed>);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_create_sub_devices__invalid_device_partition_count() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_INVALID_DEVICE_PARTITION_COUNT
   */ // }}}
  void test_create_sub_devices__invalid_device_partition_count( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_INVALID_DEVICE_PARTITION_COUNT);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_device_partition_count>);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_create_sub_devices__out_of_resources() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_create_sub_devices__out_of_resources( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_create_sub_devices__out_of_host_memory() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_create_sub_devices__out_of_host_memory( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_create_sub_devices__unexpected_clerror() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns unexpected error code
   */ // }}}
  void test_create_sub_devices__unexpected_clerror( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(-0x12334567);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), unexpected_clerror);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_retain_device() {{{
   * Test \ref retain_device() in normal situation
   */ // }}}
  void test_retain_device( )
  {
#if HAVE_OPENCL_clRetainDevice
    T::Dummy_clRetainDevice mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(retain_device((cl_device_id)0x1234));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234));
#endif // HAVE_OPENCL_clRetainDevice
  }
  /** // doc: test_retain_device__invalid_device() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns CL_INVALID_DEVICE
   */ // }}}
  void test_retain_device__invalid_device( )
  {
#if HAVE_OPENCL_clRetainDevice
    T::Dummy_clRetainDevice mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(retain_device(NULL),clerror_no<status_t::invalid_device>);
#endif // HAVE_OPENCL_clRetainDevice
  }
  /** // doc: test_retain_device__out_of_resources() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_retain_device__out_of_resources( )
  {
#if HAVE_OPENCL_clRetainDevice
    T::Dummy_clRetainDevice mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_device(NULL),clerror_no<status_t::out_of_resources>);
#endif // HAVE_OPENCL_clRetainDevice
  }
  /** // doc: test_retain_device__out_of_host_memory() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_retain_device__out_of_host_memory( )
  {
#if HAVE_OPENCL_clRetainDevice
    T::Dummy_clRetainDevice mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_device(NULL),clerror_no<status_t::out_of_host_memory>);
#endif // HAVE_OPENCL_clRetainDevice
  }
  /** // doc: test_retain_device__unexpected_clerror() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns unexpected error code
   */ // }}}
  void test_retain_device__unexpected_clerror( )
  {
#if HAVE_OPENCL_clRetainDevice
    T::Dummy_clRetainDevice mock(-0x1234567);
    TS_ASSERT_THROWS(retain_device(NULL),unexpected_clerror);
#endif // HAVE_OPENCL_clRetainDevice
  }
  /** // doc: test_release_device() {{{
   * \brief Test \ref release_device() in normal situation
   */ // }}}
  void test_release_device( )
  {
#if HAVE_OPENCL_clReleaseDevice
    T::Dummy_clReleaseDevice mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_device((cl_device_id)0x1234));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234));
#endif // HAVE_OPENCL_clReleaseDevice
  }
  /** // doc: test_release_device__invalid_device() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_INVALID_DEVICE
   */ // }}}
  void test_release_device__invalid_device( )
  {
#if HAVE_OPENCL_clReleaseDevice
    T::Dummy_clReleaseDevice mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::invalid_device>);
#endif // HAVE_OPENCL_clReleaseDevice
  }
  /** // doc: test_release_device__out_of_resources() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_release_device__out_of_resources( )
  {
#if HAVE_OPENCL_clReleaseDevice
    T::Dummy_clReleaseDevice mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::out_of_resources>);
#endif // HAVE_OPENCL_clReleaseDevice
  }
  /** // doc: test_release_device__out_of_host_memory() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_release_device__out_of_host_memory( )
  {
#if HAVE_OPENCL_clReleaseDevice
    T::Dummy_clReleaseDevice mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::out_of_host_memory>);
#endif // HAVE_OPENCL_clReleaseDevice
  }
  /** // doc: test_release_device__unexpected_clerror() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns unexpected error code
   */ // }}}
  void test_release_device__unexpected_clerror( )
  {
#if HAVE_OPENCL_clReleaseDevice
    T::Dummy_clReleaseDevice mock(-0x1234567);
    TS_ASSERT_THROWS(release_device(NULL),unexpected_clerror);
#endif // HAVE_OPENCL_clReleaseDevice
  }
};

#endif /* CLXX_FUNCTIONS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
