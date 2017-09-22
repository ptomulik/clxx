// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl/create_kernels_in_program.t.h

/** // doc: clxx/b5d/cl/create_kernels_in_program.t.h {{{
 * \file clxx/b5d/cl/create_kernels_in_program.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_CREATE_KERNELS_IN_PROGRAM_T_H_INCLUDED
#define CLXX_B5D_CL_CREATE_KERNELS_IN_PROGRAM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class create_kernels_in_program_test_suite; }

/** // doc: class clxx::create_kernels_in_program_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::create_kernels_in_program_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  create_kernels_in_program()
  ////////////////////////////////////////////////////////////////////////////
  /** // doc: test__create_kernels_in_program() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program( )
  {
#if CLXX_B5D_PROVIDES(create_kernels_in_program)
    T::Dummy_clCreateKernelsInProgram mock(CL_SUCCESS, nullptr, nullptr);
    TS_ASSERT_THROWS_NOTHING(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr));
    TS_ASSERT(mock.called_once_with((cl_program)NULL,0,nullptr,nullptr));
#else
    TS_SKIP("create_kernels_in_program not implemented");
#endif
  }
  /** // doc: test__create_kernels_in_program__invalid_program() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__invalid_program( )
  {
#if CLXX_B5D_PROVIDES(create_kernels_in_program)
    T::Dummy_clCreateKernelsInProgram mock(CL_INVALID_PROGRAM, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::invalid_program>);
#else
    TS_SKIP("create_kernels_in_program not implemented");
#endif
  }
  /** // doc: test__create_kernels_in_program__invalid_program_executable() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__invalid_program_executable( )
  {
#if CLXX_B5D_PROVIDES(create_kernels_in_program)
    T::Dummy_clCreateKernelsInProgram mock(CL_INVALID_PROGRAM_EXECUTABLE, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::invalid_program_executable>);
#else
    TS_SKIP("create_kernels_in_program not implemented");
#endif
  }
  /** // doc: test__create_kernels_in_program__invalid_value() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(create_kernels_in_program)
    T::Dummy_clCreateKernelsInProgram mock(CL_INVALID_VALUE, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("create_kernels_in_program not implemented");
#endif
  }
  /** // doc: test__create_kernels_in_program__out_of_resources() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(create_kernels_in_program)
    T::Dummy_clCreateKernelsInProgram mock(CL_OUT_OF_RESOURCES, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("create_kernels_in_program not implemented");
#endif
  }
  /** // doc: test__create_kernels_in_program__out_of_host_memory() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(create_kernels_in_program)
    T::Dummy_clCreateKernelsInProgram mock(CL_OUT_OF_HOST_MEMORY, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("create_kernels_in_program not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_CREATE_KERNELS_IN_PROGRAM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
