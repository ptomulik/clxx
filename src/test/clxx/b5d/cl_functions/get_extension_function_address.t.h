// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_functions/get_extension_function_address.t.h

/** // doc: clxx/b5d/cl_functions/get_extension_function_address.t.h {{{
 * \file clxx/b5d/cl_functions/get_extension_function_address.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FUNCTIONS_GET_EXTENSION_FUNCTION_ADDRESS_T_H_INCLUDED
#define CLXX_B5D_CL_FUNCTIONS_GET_EXTENSION_FUNCTION_ADDRESS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_functions.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class get_extension_function_address_test_suite; }

/** // doc: class clxx::get_extension_function_address_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::get_extension_function_address_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_extension_function_address()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_extension_function_address() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_extension_function_address( )
  {
#if CLXX_B5D_PROVIDES(get_extension_function_address)
    T::Dummy_clGetExtensionFunctionAddress mock((void*)0x4321);
    TS_ASSERT(get_extension_function_address((const char*)0x1234) == (void*)0x4321);
    TS_ASSERT(mock.called_once_with((const char*)0x1234));
#else
    TS_SKIP("get_extension_function_address not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FUNCTIONS_GET_EXTENSION_FUNCTION_ADDRESS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
