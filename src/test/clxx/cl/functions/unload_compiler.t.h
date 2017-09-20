// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/unload_compiler.t.h

/** // doc: clxx/cl/functions/unload_compiler.t.h {{{
 * \file clxx/cl/functions/unload_compiler.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_UNLOAD_COMPILER_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_UNLOAD_COMPILER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_unload_compiler_test_suite; }

/** // doc: class clxx::functions_unload_compiler_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_unload_compiler_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  unload_compiler()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__unload_compiler() {{{
   * \todo Write documentation
   */ // }}}
  void test__unload_compiler( )
  {
#if CLXX_OPENCL_ALLOWED(clUnloadCompiler)
    T::Dummy_clUnloadCompiler mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(unload_compiler());
    TS_ASSERT(mock.called_once_with());
#endif // CLXX_OPENCL_ALLOWED(clUnloadCompiler)
  }
  void test__unload_compiler__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clUnloadCompiler)
    T::Dummy_clUnloadCompiler mock(-0x1234567);
    TS_ASSERT_THROWS(unload_compiler(), unexpected_clerror);
#endif // CLXX_OPENCL_ALLOWED(clUnloadCompiler)
  }
};

#endif /* CLXX_CL_FUNCTIONS_UNLOAD_COMPILER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
