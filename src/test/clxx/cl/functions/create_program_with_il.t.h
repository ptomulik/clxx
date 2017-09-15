// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/create_program_with_il.t.h

/** // doc: clxx/cl/functions/create_program_with_il.t.h {{{
 * \file clxx/cl/functions/create_program_with_il.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_CREATE_PROGRAM_WITH_IL_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_CREATE_PROGRAM_WITH_IL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_program_with_il_test_suite; }

/** // doc: class clxx::functions_create_program_with_il_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_program_with_il_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  create_program_with_il()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_program_with_il() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_il( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithIL)
    T::Dummy_clCreateProgramWithIL mock((cl_program)0x1234, CL_SUCCESS);
    TS_ASSERT_EQUALS(create_program_with_il((cl_context)0x567, (const void*)0x789, 22), (cl_program)0x1234);
    TS_ASSERT(mock.called_once())
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x567);
    TS_ASSERT(std::get<1>(mock.calls().back()) == (const void*)0x789);
    TS_ASSERT(std::get<2>(mock.calls().back()) == 22);
#endif
  }
  /** // doc: test__create_program_with_il__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_il__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithIL)
    T::Dummy_clCreateProgramWithIL mock((cl_program)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_program_with_il((cl_context)NULL,(const void*)NULL,0ul),clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__create_program_with_il__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_il__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithIL)
    T::Dummy_clCreateProgramWithIL mock((cl_program)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_program_with_il((cl_context)NULL,(const void*)NULL,0ul),clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__create_program_with_il__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_il__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithIL)
    T::Dummy_clCreateProgramWithIL mock((cl_program)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_program_with_il((cl_context)NULL,(const void*)NULL,0ul),clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__create_program_with_il__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_il__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithIL)
    T::Dummy_clCreateProgramWithIL mock((cl_program)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_program_with_il((cl_context)NULL,(const void*)NULL,0ul),clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__create_program_with_il__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_il__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithIL)
    T::Dummy_clCreateProgramWithIL mock((cl_program)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_program_with_il((cl_context)NULL,(const void*)NULL,0ul), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_CREATE_PROGRAM_WITH_IL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
