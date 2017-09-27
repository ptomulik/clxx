// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/get_device_ids.t.h

/** // doc: clxx/b5d/functions/get_device_ids.t.h {{{
 * \file clxx/b5d/functions/get_device_ids.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_GET_DEVICE_IDS_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_GET_DEVICE_IDS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class get_device_ids_test_suite; }

/** // doc: class clxx::get_device_ids_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::get_device_ids_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  get_device_ids()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_device_ids() {{{
   * \brief Test get_device_ids()
   */ // }}}
  void test__get_device_ids( )
  {
#if CLXX_B5D_PROVIDES(get_device_ids)
    T::Dummy_clGetDeviceIDs mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_platform_id)NULL, CL_DEVICE_TYPE_ALL, 0, nullptr, nullptr));
#else
    TS_SKIP("get_device_ids not implemented");
#endif
  }
  /** // doc: test__get_device_ids__invalid_platform() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_INVALID_PLATFORM
   */ // }}}
  void test__get_device_ids__invalid_platform()
  {
#if CLXX_B5D_PROVIDES(get_device_ids)
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::invalid_platform>);
#else
    TS_SKIP("get_device_ids not implemented");
#endif
  }
  /** // doc: test__get_device_ids__invalid_device_type() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_INVALID_DEVICE_TYPE
   */ // }}}
  void test__get_device_ids__invalid_device_type()
  {
#if CLXX_B5D_PROVIDES(get_device_ids)
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::invalid_device_type>);
#else
    TS_SKIP("get_device_ids not implemented");
#endif
  }
  /** // doc: test__get_device_ids__invalid_value() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_device_ids__invalid_value()
  {
#if CLXX_B5D_PROVIDES(get_device_ids)
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("get_device_ids not implemented");
#endif
  }
  /** // doc: test__get_device_ids__device_not_found() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_DEVICE_NOT_FOUND
   */ // }}}
  void test__get_device_ids__device_not_found()
  {
#if CLXX_B5D_PROVIDES(get_device_ids)
    T::Dummy_clGetDeviceIDs mock(CL_DEVICE_NOT_FOUND);
    //TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::device_not_found>);
    TS_ASSERT_THROWS_NOTHING(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr));
#else
    TS_SKIP("get_device_ids not implemented");
#endif
  }
  /** // doc: test__get_device_ids__out_of_resources() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__get_device_ids__out_of_resources()
  {
#if CLXX_B5D_PROVIDES(get_device_ids)
    T::Dummy_clGetDeviceIDs mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("get_device_ids not implemented");
#endif
  }
  /** // doc: test__get_device_ids__out_of_host_memory() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_device_ids__out_of_host_memory()
  {
#if CLXX_B5D_PROVIDES(get_device_ids)
    T::Dummy_clGetDeviceIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("get_device_ids not implemented");
#endif
  }
  /** // doc: test__get_device_ids__other_error() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns an unexpected error code
   */ // }}}
  void test__get_device_ids__other_error()
  {
#if CLXX_B5D_PROVIDES(get_device_ids)
    T::Dummy_clGetDeviceIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("get_device_ids not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_GET_DEVICE_IDS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
