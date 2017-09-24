// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/get_platform_ids.t.h

/** // doc: clxx/b5d/cl_fcn/get_platform_ids.t.h {{{
 * \file clxx/b5d/cl_fcn/get_platform_ids.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_GET_PLATFORM_IDS_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_GET_PLATFORM_IDS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class get_platform_ids_test_suite; }

/** // doc: class clxx::get_platform_ids_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::get_platform_ids_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  // get_platform_ids()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_platform_ids() {{{
   * \brief Test get_platform_ids() in a normal situation
   */ // }}}
  void test__get_platform_ids( )
  {
#if CLXX_B5D_PROVIDES(get_platform_ids)
    T::Dummy_clGetPlatformIDs mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_platform_ids(0,nullptr,NULL));
    TS_ASSERT(mock.called_once_with(0,nullptr,NULL));
#else
    TS_SKIP("get_platform_ids not implemented");
#endif
  }
  /** // doc: test__get_platform_ids__invalid_value() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_platform_ids__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(get_platform_ids)
    T::Dummy_clGetPlatformIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("get_platform_ids not implemented");
#endif
  }
  /** // doc: test__get_platform_ids__out_of_host_memory() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_platform_ids__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(get_platform_ids)
    T::Dummy_clGetPlatformIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("get_platform_ids not implemented");
#endif
  }
  /** // doc: test__get_platform_ids__other_error() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns unexpected error code.
   */ // }}}
  void test__get_platform_ids__other_error( )
  {
#if CLXX_B5D_PROVIDES(get_platform_ids)
    T::Dummy_clGetPlatformIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), unexpected_clerror);
#else
    TS_SKIP("get_platform_ids not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_GET_PLATFORM_IDS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
