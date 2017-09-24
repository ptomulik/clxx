// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/create_context.t.h

/** // doc: clxx/b5d/cl_fcn/create_context_from_type.t.h {{{
 * \file clxx/b5d/cl_fcn/create_context_from_type.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_CREATE_CONTEXT_FROM_TYPE_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_CREATE_CONTEXT_FROM_TYPE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class create_context_from_type_test_suite; }

/** // doc: class clxx::create_context_from_type_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::create_context_from_type_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  create_context_from_type()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_context_from_type() {{{
   * \brief Test create_context_from_type().
   */ // }}}
  void test__create_context_from_type( )
  {
#if CLXX_B5D_PROVIDES(create_context_from_type)
    T::Dummy_clCreateContextFromType mock((cl_context)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr));
#else
    TS_SKIP("create_context_from_type not implemented");
#endif
  }
  /** // doc: test__create_context_from_type__invalid_platform() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_PLATFORM.
   */ // }}}
  void test__create_context_from_type__invalid_platform( )
  {
#if CLXX_B5D_PROVIDES(create_context_from_type)
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_platform>);
#else
    TS_SKIP("create_context_from_type not implemented");
#endif
  }
  /** // doc: test__create_context_from_type__invalid_property() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_PROPERTY.
   */ // }}}
  void test__create_context_from_type__invalid_property( )
  {
#if CLXX_B5D_PROVIDES(create_context_from_type)
# if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_PROPERTY);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_property>);
# else
    TS_SKIP("CL_INVALID_PROPERTY not available in OpenCL < 1.1, skipping test");
# endif
#else
    TS_SKIP("create_context_from_type not implemented");
#endif
  }
  /** // doc: test__create_context_from_type__invalid_value() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_context_from_type__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(create_context_from_type)
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("create_context_from_type not implemented");
#endif
  }
  /** // doc: test__create_context_from_type__invalid_device_type() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_DEVICE_TYPE.
   */ // }}}
  void test__create_context_from_type__invalid_device_type( )
  {
#if CLXX_B5D_PROVIDES(create_context_from_type)
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_device_type>);
#else
    TS_SKIP("create_context_from_type not implemented");
#endif
  }
  /** // doc: test__create_context_from_type__device_not_available() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test__create_context_from_type__device_not_available( )
  {
#if CLXX_B5D_PROVIDES(create_context_from_type)
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_DEVICE_NOT_AVAILABLE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::device_not_available>);
#else
    TS_SKIP("create_context_from_type not implemented");
#endif
  }
  /** // doc: test__create_context_from_type__out_of_resources() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_context_from_type__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(create_context_from_type)
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("create_context_from_type not implemented");
#endif
  }
  /** // doc: test__create_context_from_type__out_of_host_memory() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_context_from_type__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(create_context_from_type)
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("create_context_from_type not implemented");
#endif
  }
  /** // doc: test__create_context_from_type__other_error() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns an unexpected error code.
   */ // }}}
  void test__create_context_from_type__other_error( )
  {
#if CLXX_B5D_PROVIDES(create_context_from_type)
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, -0x3456);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), unexpected_clerror);
#else
    TS_SKIP("create_context_from_type not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_CREATE_CONTEXT_FROM_TYPE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
