// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl/get_kernel_work_group_info.t.h

/** // doc: clxx/b5d/cl/get_kernel_work_group_info.t.h {{{
 * \file clxx/b5d/cl/get_kernel_work_group_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_GET_KERNEL_WORK_GROUP_INFO_T_H_INCLUDED
#define CLXX_B5D_CL_GET_KERNEL_WORK_GROUP_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class get_kernel_work_group_info_test_suite; }

/** // doc: class clxx::get_kernel_work_group_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::get_kernel_work_group_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_kernel_work_group_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_kernel_work_group_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info( )
  {
#if CLXX_B5D_PROVIDES(get_kernel_work_group_info)
    T::Dummy_clGetKernelWorkGroupInfo mock(CL_SUCCESS);
    get_kernel_work_group_info     ((cl_kernel)0x395, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size,            5, (void*)0x124, (size_t*)0x934);
    TS_ASSERT(mock.called_once_with((cl_kernel)0x395, (cl_device_id)NULL, (cl_kernel_work_group_info)CL_KERNEL_WORK_GROUP_SIZE, 5, (void*)0x124, (size_t*)0x934));
#else
    TS_SKIP("get_kernel_work_group_info not implemented");
#endif
  }
  /** // doc: test__get_kernel_work_group_info__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info__invalid_device( )
  {
#if CLXX_B5D_PROVIDES(get_kernel_work_group_info)
    T::Dummy_clGetKernelWorkGroupInfo mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(get_kernel_work_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size, 0, nullptr, nullptr),clerror_no<status_t::invalid_device>);
#else
    TS_SKIP("get_kernel_work_group_info not implemented");
#endif
  }
  /** // doc: test__get_kernel_work_group_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(get_kernel_work_group_info)
    T::Dummy_clGetKernelWorkGroupInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_kernel_work_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("get_kernel_work_group_info not implemented");
#endif
  }
  /** // doc: test__get_kernel_work_group_info__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info__invalid_kernel( )
  {
#if CLXX_B5D_PROVIDES(get_kernel_work_group_info)
    T::Dummy_clGetKernelWorkGroupInfo mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(get_kernel_work_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size, 0, nullptr, nullptr),clerror_no<status_t::invalid_kernel>);
#else
    TS_SKIP("get_kernel_work_group_info not implemented");
#endif
  }
  /** // doc: test__get_kernel_work_group_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(get_kernel_work_group_info)
    T::Dummy_clGetKernelWorkGroupInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_kernel_work_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("get_kernel_work_group_info not implemented");
#endif
  }
  /** // doc: test__get_kernel_work_group_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(get_kernel_work_group_info)
    T::Dummy_clGetKernelWorkGroupInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_kernel_work_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("get_kernel_work_group_info not implemented");
#endif
  }
  /** // doc: test__get_kernel_work_group_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(get_kernel_work_group_info)
    T::Dummy_clGetKernelWorkGroupInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_kernel_work_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size, 0, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("get_kernel_work_group_info not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_GET_KERNEL_WORK_GROUP_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
