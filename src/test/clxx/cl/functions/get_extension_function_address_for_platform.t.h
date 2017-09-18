// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/get_extension_function_address_for_platform.t.h

/** // doc: clxx/cl/functions/get_extension_function_address_for_platform.t.h {{{
 * \file clxx/cl/functions/get_extension_function_address_for_platform.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_GET_EXTENSION_FUNCTION_ADDRESS_FOR_PLATFORM_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_GET_EXTENSION_FUNCTION_ADDRESS_FOR_PLATFORM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_get_extension_function_address_for_platform_test_suite; }

/** // doc: class clxx::functions_get_extension_function_address_for_platform_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_get_extension_function_address_for_platform_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_extension_function_address_for_platform()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_extension_function_address_for_platform() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_extension_function_address_for_platform( )
  {
#if CLXX_OPENCL_ALLOWED(clGetExtensionFunctionAddressForPlatform)
    T::Dummy_clGetExtensionFunctionAddressForPlatform mock((void*)0x4321);
    TS_ASSERT(get_extension_function_address_for_platform((cl_platform_id)0x7654,(const char*)0x1234) == (void*)0x4321);
    TS_ASSERT(mock.called_once_with((cl_platform_id)0x7654, (const char*)0x1234));
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_GET_EXTENSION_FUNCTION_ADDRESS_FOR_PLATFORM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
