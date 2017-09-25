// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_functions/create_kernel.t.h

/** // doc: clxx/b5d/cl_functions/create_kernel.t.h {{{
 * \file clxx/b5d/cl_functions/create_kernel.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FUNCTIONS_CREATE_KERNEL_T_H_INCLUDED
#define CLXX_B5D_CL_FUNCTIONS_CREATE_KERNEL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_functions.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class create_kernel_test_suite; }

/** // doc: class clxx::create_kernel_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::create_kernel_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  create_kernel()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_kernel() {{{
   * \brief Test create_kernel() in a normal situation.
   */ // }}}
  void test__create_kernel( )
  {
#if CLXX_B5D_PROVIDES(create_kernel)
    T::Dummy_clCreateKernel mock((cl_kernel)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::create_kernel(nullptr,"mykernel"));
    TS_ASSERT(mock.called_once());
    TS_ASSERT(clxx::create_kernel(nullptr,0) == (cl_kernel)0x1234);
#else
    TS_SKIP("create_kernel not implemented");
#endif
  }
  /** // doc: test__create_kernel__invalid_program() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_PROGRAM.
   */ // }}}
  void test__create_kernel__invalid_program( )
  {
#if CLXX_B5D_PROVIDES(create_kernel)
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_program>);
#else
    TS_SKIP("create_kernel not implemented");
#endif
  }
  /** // doc: test__create_kernel__invalid_program_executable() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_PROGRAM_EXECUTABLE.
   */ // }}}
  void test__create_kernel__invalid_program_executable( )
  {
#if CLXX_B5D_PROVIDES(create_kernel)
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_PROGRAM_EXECUTABLE);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_program_executable>);
#else
    TS_SKIP("create_kernel not implemented");
#endif
  }
  /** // doc: test__create_kernel__invalid_kernel_name() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_KERNEL_NAME.
   */ // }}}
  void test__create_kernel__invalid_kernel_name( )
  {
#if CLXX_B5D_PROVIDES(create_kernel)
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_KERNEL_NAME);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_kernel_name>);
#else
    TS_SKIP("create_kernel not implemented");
#endif
  }
  /** // doc: test__create_kernel__invalid_kernel_definition() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_KERNEL_DEFINITION.
   */ // }}}
  void test__create_kernel__invalid_kernel_definition( )
  {
#if CLXX_B5D_PROVIDES(create_kernel)
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_KERNEL_DEFINITION);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_kernel_definition>);
#else
    TS_SKIP("create_kernel not implemented");
#endif
  }
  /** // doc: test__create_kernel__invalid_value() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_kernel__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(create_kernel)
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("create_kernel not implemented");
#endif
  }
  /** // doc: test__create_kernel__out_of_resources() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_kernel__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(create_kernel)
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("create_kernel not implemented");
#endif
  }
  /** // doc: test__create_kernel__out_of_host_memory() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_kernel__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(create_kernel)
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("create_kernel not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FUNCTIONS_CREATE_KERNEL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
