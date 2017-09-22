// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl/create_program_with_built_in_kernels.t.h

/** // doc: clxx/b5d/cl/create_program_with_built_in_kernels.t.h {{{
 * \file clxx/b5d/cl/create_program_with_built_in_kernels.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_CREATE_PROGRAM_WITH_BUILT_IN_KERNELS_T_H_INCLUDED
#define CLXX_B5D_CL_CREATE_PROGRAM_WITH_BUILT_IN_KERNELS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class create_program_with_built_in_kernels_test_suite; }

/** // doc: class clxx::create_program_with_built_in_kernels_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::create_program_with_built_in_kernels_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  create_program_with_built_in_kernels()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_program_with_built_in_kernels() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_built_in_kernels)
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)0x1234, CL_SUCCESS);
    create_program_with_built_in_kernels((cl_context)0x113, 8, (const cl_device_id*)0x654, (const char*)0x938747);
    TS_ASSERT(mock.called_once());
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x113);
    TS_ASSERT(std::get<1>(mock.calls().back()) == 8);
    TS_ASSERT(std::get<2>(mock.calls().back()) == (const cl_device_id*)0x654);
    TS_ASSERT(std::get<3>(mock.calls().back()) == (const char*)0x938747);
#else
    TS_SKIP("create_program_with_built_in_kernels not implemented");
#endif
  }
  /** // doc: test__create_program_with_built_in_kernels__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_built_in_kernels)
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("create_program_with_built_in_kernels not implemented");
#endif
  }
  /** // doc: test__create_program_with_built_in_kernels__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_built_in_kernels)
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("create_program_with_built_in_kernels not implemented");
#endif
  }
  /** // doc: test__create_program_with_built_in_kernels__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels__invalid_device( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_built_in_kernels)
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::invalid_device>);
#else
    TS_SKIP("create_program_with_built_in_kernels not implemented");
#endif
  }
  /** // doc: test__create_program_with_built_in_kernels__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_built_in_kernels)
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("create_program_with_built_in_kernels not implemented");
#endif
  }
  /** // doc: test__create_program_with_built_in_kernels__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_built_in_kernels)
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("create_program_with_built_in_kernels not implemented");
#endif
  }
  /** // doc: test__create_program_with_built_in_kernels__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_built_in_kernels)
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("create_program_with_built_in_kernels not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_CREATE_PROGRAM_WITH_BUILT_IN_KERNELS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
