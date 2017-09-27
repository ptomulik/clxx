// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/unload_compiler.t.h

/** // doc: clxx/b5d/functions/unload_compiler.t.h {{{
 * \file clxx/b5d/functions/unload_compiler.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_UNLOAD_COMPILER_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_UNLOAD_COMPILER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class unload_compiler_test_suite; }

/** // doc: class clxx::unload_compiler_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::unload_compiler_test_suite : public CxxTest::TestSuite
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
#if CLXX_B5D_PROVIDES(unload_compiler)
    T::Dummy_clUnloadCompiler mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(unload_compiler());
    TS_ASSERT(mock.called_once_with());
#else
    TS_SKIP("unload_compiler not implemented");
#endif
  }
  void test__unload_compiler__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(unload_compiler)
    T::Dummy_clUnloadCompiler mock(-0x1234567);
    TS_ASSERT_THROWS(unload_compiler(), unexpected_clerror);
#else
    TS_SKIP("unload_compiler not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_UNLOAD_COMPILER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
