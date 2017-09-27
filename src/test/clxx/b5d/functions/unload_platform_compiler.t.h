// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/unload_platform_compiler.t.h

/** // doc: clxx/b5d/functions/unload_platform_compiler.t.h {{{
 * \file clxx/b5d/functions/unload_platform_compiler.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_UNLOAD_PLATFORM_COMPILER_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_UNLOAD_PLATFORM_COMPILER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class unload_platform_compiler_test_suite; }

/** // doc: class clxx::unload_platform_compiler_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::unload_platform_compiler_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  unload_platform_compiler()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__unload_platform_compiler() {{{
   * \todo Write documentation
   */ // }}}
  void test__unload_platform_compiler( )
  {
#if CLXX_B5D_PROVIDES(unload_platform_compiler)
    T::Dummy_clUnloadPlatformCompiler mock(CL_SUCCESS);
    unload_platform_compiler       ((cl_platform_id)0x937);
    TS_ASSERT(mock.called_once_with((cl_platform_id)0x937));
#else
    TS_SKIP("unload_platform_compiler not implemented");
#endif
  }
  /** // doc: test__unload_platform_compiler__invalid_platform() {{{
   * \todo Write documentation
   */ // }}}
  void test__unload_platform_compiler__invalid_platform( )
  {
#if CLXX_B5D_PROVIDES(unload_platform_compiler)
    T::Dummy_clUnloadPlatformCompiler mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(unload_platform_compiler((cl_platform_id)NULL),clerror_no<status_t::invalid_platform>);
#else
    TS_SKIP("unload_platform_compiler not implemented");
#endif
  }
  /** // doc: test__unload_platform_compiler__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__unload_platform_compiler__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(unload_platform_compiler)
    T::Dummy_clUnloadPlatformCompiler mock(-0x1234567);
    TS_ASSERT_THROWS(unload_platform_compiler((cl_platform_id)NULL), unexpected_clerror);
#else
    TS_SKIP("unload_platform_compiler not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_UNLOAD_PLATFORM_COMPILER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
