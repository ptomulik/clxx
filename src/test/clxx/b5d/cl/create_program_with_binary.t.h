// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl/create_program_with_binary.t.h

/** // doc: clxx/b5d/cl/create_program_with_binary.t.h {{{
 * \file clxx/b5d/cl/create_program_with_binary.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_CREATE_PROGRAM_WITH_BINARY_T_H_INCLUDED
#define CLXX_B5D_CL_CREATE_PROGRAM_WITH_BINARY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class create_program_with_binary_test_suite; }

/** // doc: class clxx::create_program_with_binary_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::create_program_with_binary_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  create_program_with_binary()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_program_with_binary() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_binary)
    T::Dummy_clCreateProgramWithBinary mock((cl_program)0x1234, CL_SUCCESS);
    TS_ASSERT_EQUALS(create_program_with_binary((cl_context)0x567, 5, (const cl_device_id*)0x487, (const size_t*)0x634, (const unsigned char**)0x174, (cl_int*)0x757), (cl_program)0x1234);
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x567);
    TS_ASSERT(std::get<1>(mock.calls().back()) == 5);
    TS_ASSERT(std::get<2>(mock.calls().back()) == (const cl_device_id*)0x487);
    TS_ASSERT(std::get<3>(mock.calls().back()) == (const size_t*)0x634);
    TS_ASSERT(std::get<4>(mock.calls().back()) == (const unsigned char**)0x174);
    TS_ASSERT(std::get<5>(mock.calls().back()) == (cl_int*)0x757);
    TS_ASSERT(mock.called_once());
#else
    TS_SKIP("create_program_with_binary not implemented");
#endif
  }
  /** // doc: test__create_program_with_binary__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_binary)
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("create_program_with_binary not implemented");
#endif
  }
  /** // doc: test__create_program_with_binary__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_binary)
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("create_program_with_binary not implemented");
#endif
  }
  /** // doc: test__create_program_with_binary__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__invalid_device( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_binary)
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_device>);
#else
    TS_SKIP("create_program_with_binary not implemented");
#endif
  }
  /** // doc: test__create_program_with_binary__invalid_binary() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__invalid_binary( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_binary)
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_INVALID_BINARY);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_binary>);
#else
    TS_SKIP("create_program_with_binary not implemented");
#endif
  }
  /** // doc: test__create_program_with_binary__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_binary)
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("create_program_with_binary not implemented");
#endif
  }
  /** // doc: test__create_program_with_binary__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_binary)
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("create_program_with_binary not implemented");
#endif
  }
  /** // doc: test__create_program_with_binary__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(create_program_with_binary)
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("create_program_with_binary not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_CREATE_PROGRAM_WITH_BINARY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
