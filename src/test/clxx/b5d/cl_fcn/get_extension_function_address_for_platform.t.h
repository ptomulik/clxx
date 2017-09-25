// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/get_extension_function_address_for_platform.t.h

/** // doc: clxx/b5d/cl_fcn/get_extension_function_address_for_platform.t.h {{{
 * \file clxx/b5d/cl_fcn/get_extension_function_address_for_platform.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_GET_EXTENSION_FUNCTION_ADDRESS_FOR_PLATFORM_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_GET_EXTENSION_FUNCTION_ADDRESS_FOR_PLATFORM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class get_extension_function_address_for_platform_test_suite; }

/** // doc: class clxx::get_extension_function_address_for_platform_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::get_extension_function_address_for_platform_test_suite : public CxxTest::TestSuite
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
#if CLXX_B5D_PROVIDES(get_extension_function_address_for_platform)
    T::Dummy_clGetExtensionFunctionAddressForPlatform mock((void*)0x4321);
    TS_ASSERT(get_extension_function_address_for_platform((cl_platform_id)0x7654,(const char*)0x1234) == (void*)0x4321);
    TS_ASSERT(mock.called_once_with((cl_platform_id)0x7654, (const char*)0x1234));
#else
    TS_SKIP("get_extension_function_address_for_platform not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_GET_EXTENSION_FUNCTION_ADDRESS_FOR_PLATFORM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
