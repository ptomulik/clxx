// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/get_extension_function_address.t.h

/** // doc: clxx/cl/functions/get_extension_function_address.t.h {{{
 * \file clxx/cl/functions/get_extension_function_address.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_GET_EXTENSION_FUNCTION_ADDRESS_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_GET_EXTENSION_FUNCTION_ADDRESS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_get_extension_function_address_test_suite; }

/** // doc: class clxx::functions_get_extension_function_address_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_get_extension_function_address_test_suite : public CxxTest::TestSuite
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
#if CLXX_OPENCL_ALLOWED(clGetExtensionFunctionAddress)
    T::Dummy_clGetExtensionFunctionAddress mock((void*)0x4321);
    TS_ASSERT(get_extension_function_address((const char*)0x1234) == (void*)0x4321);
    TS_ASSERT(mock.called_once_with((const char*)0x1234));
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_GET_EXTENSION_FUNCTION_ADDRESS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
