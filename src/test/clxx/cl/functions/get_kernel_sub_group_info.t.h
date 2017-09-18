// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/get_kernel_sub_group_info.t.h

/** // doc: clxx/cl/functions/get_kernel_sub_group_info.t.h {{{
 * \file clxx/cl/functions/get_kernel_sub_group_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_GET_KERNEL_SUB_GROUP_INFO_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_GET_KERNEL_SUB_GROUP_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_get_kernel_sub_group_info_test_suite; }

/** // doc: class clxx::functions_get_kernel_sub_group_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_get_kernel_sub_group_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_kernel_sub_group_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_kernel_sub_group_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_sub_group_info( )
  {
    T::Dummy_clGetKernelSubGroupInfo mock(CL_SUCCESS);
    get_kernel_sub_group_info     ((cl_kernel)0x395, (cl_device_id)NULL, kernel_sub_group_info_t::max_sub_group_size_for_ndrange, 5, (const void*)0x124, 7, (void*)0x357, (size_t*)0x934);
    TS_ASSERT(mock.called_once_with((cl_kernel)0x395, (cl_device_id)NULL, (cl_kernel_sub_group_info)CL_KERNEL_MAX_SUB_GROUP_SIZE_FOR_NDRANGE, 5, (const void*)0x124, 7, (void*)0x357, (size_t*)0x934));
  }
  /** // doc: test__get_kernel_sub_group_info__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_sub_group_info__invalid_device( )
  {
    T::Dummy_clGetKernelSubGroupInfo mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(get_kernel_sub_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_sub_group_info_t::max_sub_group_size_for_ndrange, 0ul, nullptr, 0ul, nullptr, nullptr),clerror_no<status_t::invalid_device>);
  }
  /** // doc: test__get_kernel_sub_group_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_sub_group_info__invalid_value( )
  {
    T::Dummy_clGetKernelSubGroupInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_kernel_sub_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_sub_group_info_t::max_sub_group_size_for_ndrange, 0ul, nullptr, 0ul, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_kernel_sub_group_info__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_sub_group_info__invalid_kernel( )
  {
    T::Dummy_clGetKernelSubGroupInfo mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(get_kernel_sub_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_sub_group_info_t::max_sub_group_size_for_ndrange, 0ul, nullptr, 0ul, nullptr, nullptr),clerror_no<status_t::invalid_kernel>);
  }
  /** // doc: test__get_kernel_sub_group_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_sub_group_info__out_of_resources( )
  {
    T::Dummy_clGetKernelSubGroupInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_kernel_sub_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_sub_group_info_t::max_sub_group_size_for_ndrange, 0ul, nullptr, 0ul, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_kernel_sub_group_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_sub_group_info__out_of_host_memory( )
  {
    T::Dummy_clGetKernelSubGroupInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_kernel_sub_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_sub_group_info_t::max_sub_group_size_for_ndrange, 0ul, nullptr, 0ul, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_kernel_sub_group_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_sub_group_info__unexpected_clerror( )
  {
    T::Dummy_clGetKernelSubGroupInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_kernel_sub_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_sub_group_info_t::max_sub_group_size_for_ndrange, 0ul, nullptr, 0ul, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_GET_KERNEL_SUB_GROUP_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
