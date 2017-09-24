// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/create_context.t.h

/** // doc: clxx/b5d/cl_fcn/create_context.t.h {{{
 * \file clxx/b5d/cl_fcn/create_context.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_CREATE_CONTEXT_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_CREATE_CONTEXT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class create_context_test_suite; }

/** // doc: class clxx::create_context_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::create_context_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  create_context()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_context() {{{
   * \brief Test create_context() in a normal situation.
   */ // }}}
  void test__create_context( )
  {
#if CLXX_B5D_PROVIDES(create_context)
    T::Dummy_clCreateContext mock((cl_context)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr));
    //TS_ASSERT(mock.called_once_with(nullptr,0,nullptr,nullptr,nullptr,??? - local variable within create_context(...){...}));
#else
    TS_SKIP("create_context not implemented");
#endif
  }
  /** // doc: test__create_context__invalid_platform() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_PLATFORM.
   */ // }}}
  void test__create_context__invalid_platform( )
  {
#if CLXX_B5D_PROVIDES(create_context)
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_platform>);
#else
    TS_SKIP("create_context not implemented");
#endif
  }
  /** // doc: test__create_context__invalid_property() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_PROPERTY.
   */ // }}}
  void test__create_context__invalid_property( )
  {
#if CLXX_B5D_PROVIDES(create_context)
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_PROPERTY);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_property>);
#endif
#else
    TS_SKIP("create_context not implemented");
#endif
  }
  /** // doc: test__create_context__invalid_operation() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_OPERATION.
   */ // }}}
  void test__create_context__invalid_operation( )
  {
#if CLXX_B5D_PROVIDES(create_context)
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_operation>);
#endif
#else
    TS_SKIP("create_context not implemented");
#endif
  }
  /** // doc: test__create_context__invalid_value() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_context__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(create_context)
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("create_context not implemented");
#endif
  }
  /** // doc: test__create_context__invalid_device() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_DEVICE.
   */ // }}}
  void test__create_context__invalid_device( )
  {
#if CLXX_B5D_PROVIDES(create_context)
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_device>);
#else
    TS_SKIP("create_context not implemented");
#endif
  }
  /** // doc: test__create_context__device_not_available() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test__create_context__device_not_available( )
  {
#if CLXX_B5D_PROVIDES(create_context)
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_DEVICE_NOT_AVAILABLE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::device_not_available>);
#else
    TS_SKIP("create_context not implemented");
#endif
  }
  /** // doc: test__create_context__out_of_resources() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_context__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(create_context)
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("create_context not implemented");
#endif
  }
  /** // doc: test__create_context__out_of_host_memory() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_context__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(create_context)
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("create_context not implemented");
#endif
  }
  /** // doc: test__create_context__other_error() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns an unexpected error code.
   */ // }}}
  void test__create_context__other_error( )
  {
#if CLXX_B5D_PROVIDES(create_context)
    T::Dummy_clCreateContext mock((cl_context)NULL, -0x3456);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), unexpected_clerror);
#else
    TS_SKIP("create_context not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_CREATE_CONTEXT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
