// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/release_program.t.h

/** // doc: clxx/b5d/cl_fcn/release_program.t.h {{{
 * \file clxx/b5d/cl_fcn/release_program.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_RELEASE_PROGRAM_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_RELEASE_PROGRAM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class release_program_test_suite; }

/** // doc: class clxx::release_program_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::release_program_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  release_program()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__release_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program( )
  {
#if CLXX_B5D_PROVIDES(release_program)
    T::Dummy_clReleaseProgram mock(CL_SUCCESS);
    release_program                ((cl_program)0x433);
    TS_ASSERT(mock.called_once_with((cl_program)0x433));
#else
    TS_SKIP("release_program not implemented");
#endif
  }
  /** // doc: test__release_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program__invalid_program( )
  {
#if CLXX_B5D_PROVIDES(release_program)
    T::Dummy_clReleaseProgram mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(release_program((cl_program)NULL),clerror_no<status_t::invalid_program>);
#else
    TS_SKIP("release_program not implemented");
#endif
  }
  /** // doc: test__release_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(release_program)
    T::Dummy_clReleaseProgram mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_program((cl_program)NULL),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("release_program not implemented");
#endif
  }
  /** // doc: test__release_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(release_program)
    T::Dummy_clReleaseProgram mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_program((cl_program)NULL),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("release_program not implemented");
#endif
  }
  /** // doc: test__release_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(release_program)
    T::Dummy_clReleaseProgram mock(-0x1234567);
    TS_ASSERT_THROWS(release_program((cl_program)NULL), unexpected_clerror);
#else
    TS_SKIP("release_program not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_RELEASE_PROGRAM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
