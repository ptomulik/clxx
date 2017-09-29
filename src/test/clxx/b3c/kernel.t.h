// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b3c/kernel.t.h

/** // doc: clxx/b3c/kernel.t.h {{{
 * \file clxx/b3c/kernel.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B3C_KERNEL_T_H_INCLUDED
#define CLXX_B3C_KERNEL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b3c/kernel.hpp>
#include <clxx/b3c/device.hpp>
#include <clxx/b3c/context.hpp>
#include <clxx/b3c/mem.hpp>
#include <clxx/b3c/program.hpp>
#include <clxx/b3c/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

namespace clxx { class kernel_test_suite; }

/** // doc: class clxx::kernel_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::kernel_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__default_ctor( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    kernel k;
    TS_ASSERT(!k.is_initialized());
    TS_ASSERT_EQUALS(k.get(), (cl_kernel)NULL);
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_1( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    kernel k((cl_kernel)0x1234);
    TS_ASSERT(k.is_initialized());
    TS_ASSERT_EQUALS(k.get(), (cl_kernel)0x1234);
    TS_ASSERT(mock1.called_once_with((cl_kernel)0x1234));
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_1__null_id() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_1__null_id( )
  {
    T::Dummy_clRetainKernel mock1(CL_INVALID_KERNEL);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(kernel((cl_kernel)NULL));
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_2( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Dummy_clCreateKernel mock3((cl_kernel)0x5678, CL_SUCCESS);
    T::Dummy_clRetainProgram mock4(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock5(CL_SUCCESS);

    program prog((cl_program)0x1234);
    kernel k(prog, "foo");

    TS_ASSERT(k.is_initialized());
    TS_ASSERT_EQUALS(k.get(), (cl_kernel)0x5678);
    TS_ASSERT(mock3.called_once());
    // mock1 not called because the class assumes the implicit retain performed
    // by clCreateKernelWithSource()
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__copy_ctor( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    kernel k1((cl_kernel)0x1234);
    kernel k2(k1);
    TS_ASSERT(k2.is_initialized());
    TS_ASSERT(mock1.called_twice());
    TS_ASSERT(mock2.never_called());
    TS_ASSERT_EQUALS(k2, kernel((cl_kernel)0x1234));
  }
  /** // doc: test__dtor__notnull() {{{
   * \todo Write documentation
   */ // }}}
  void test__dtor__notnull( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    {
      kernel k((cl_kernel)0x1234);
    }
    TS_ASSERT(mock2.called_once_with((cl_kernel)0x1234));
  }
  /** // doc: test__dtor__null() {{{
   * \todo Write documentation
   */ // }}}
  void test__dtor__null( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    {
      kernel k((cl_kernel)NULL);
    }
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__id() {{{
   * \todo Write documentation
   */ // }}}
  void test__id( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(kernel((cl_kernel)0x1234).get(), (cl_kernel)0x1234);
    TS_ASSERT_EQUALS(kernel((cl_kernel)NULL).get(), (cl_kernel)NULL);
  }
  /** // doc: test__chk_get() {{{
   * \todo Write documentation
   */ // }}}
  void test__chk_get( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(kernel((cl_kernel)0x1234).chk_get(), (cl_kernel)0x1234);
    TS_ASSERT_THROWS(kernel((cl_kernel)NULL).chk_get(), uninitialized_kernel_error);
  }
  /** // doc: test__assign__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign__1( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    kernel c1((cl_kernel)0x1234);
    kernel c2((cl_kernel)0x5678);
    TS_ASSERT(c1 != c2);
    c2.assign(c1);
    TS_ASSERT(mock1.called_three_times());
    TS_ASSERT(mock1.last_called_with((cl_kernel)0x1234));
    TS_ASSERT(mock2.called_once_with((cl_kernel)0x5678));
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test__assign__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign__2( )
  {
    kernel c1;
    kernel c2;
    {
      T::Dummy_clRetainKernel mock_clRetainKernel(CL_SUCCESS);
      T::Dummy_clReleaseKernel mock_clReleaseKernel(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(c2.assign(c1));
      TS_ASSERT(mock_clRetainKernel.never_called());
      TS_ASSERT(mock_clReleaseKernel.never_called());
    }
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test__assign__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign__3( )
  {
    T::Dummy_clRetainKernel mock_clRetainKernel(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock_clReleaseKernel(CL_SUCCESS);
    kernel c1;
    kernel c2((cl_kernel)0x1234);
    {
      T::Dummy_clRetainKernel mock_clRetainKernel2(CL_SUCCESS);
      T::Dummy_clReleaseKernel mock_clReleaseKernel2(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(c2.assign(c1));
      TS_ASSERT(mock_clRetainKernel2.never_called());
      TS_ASSERT(mock_clReleaseKernel2.called_once_with((cl_kernel)0x1234));
    }
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test__op_assign() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_assign( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    kernel p1((cl_kernel)0x1234);
    kernel p2((cl_kernel)0x5678);
    p1 = p2;
    TS_ASSERT_EQUALS(p1.get(), (cl_kernel)0x5678);
  }
  /** // doc: test__op_eq() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_eq( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    TS_ASSERT( (kernel((cl_kernel)0x1234) == kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)0x1234) == kernel((cl_kernel)0x5678)));
    TS_ASSERT(!(kernel((cl_kernel)0x5678) == kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)0x1234) == kernel((cl_kernel)NULL)));
    TS_ASSERT(!(kernel((cl_kernel)NULL)   == kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)NULL)   == kernel((cl_kernel)NULL)));
  }
  /** // doc: test__op_neq() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_neq( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    TS_ASSERT(!(kernel((cl_kernel)0x1234) != kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)0x1234) != kernel((cl_kernel)0x5678)));
    TS_ASSERT( (kernel((cl_kernel)0x5678) != kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)0x1234) != kernel((cl_kernel)NULL)));
    TS_ASSERT( (kernel((cl_kernel)NULL)   != kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)NULL)   != kernel((cl_kernel)NULL)));
  }
  /** // doc: test__op_lt() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_lt( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    TS_ASSERT(!(kernel((cl_kernel)0x1234) < kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)0x1234) < kernel((cl_kernel)0x5678)));
    TS_ASSERT(!(kernel((cl_kernel)0x5678) < kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)0x1234) < kernel((cl_kernel)NULL)));
    TS_ASSERT( (kernel((cl_kernel)NULL)   < kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)NULL)   < kernel((cl_kernel)NULL)));
  }
  /** // doc: test__op_gt() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_gt( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    TS_ASSERT(!(kernel((cl_kernel)0x1234) > kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)0x1234) > kernel((cl_kernel)0x5678)));
    TS_ASSERT( (kernel((cl_kernel)0x5678) > kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)0x1234) > kernel((cl_kernel)NULL)));
    TS_ASSERT(!(kernel((cl_kernel)NULL)   > kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)NULL)   > kernel((cl_kernel)NULL)));
  }
  /** // doc: test__op_le() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_le( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    TS_ASSERT( (kernel((cl_kernel)0x1234) <= kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)0x1234) <= kernel((cl_kernel)0x5678)));
    TS_ASSERT(!(kernel((cl_kernel)0x5678) <= kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)0x1234) <= kernel((cl_kernel)NULL)));
    TS_ASSERT( (kernel((cl_kernel)NULL)   <= kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)NULL)   <= kernel((cl_kernel)NULL)));
  }
  /** // doc: test__op_ge() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_ge( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    TS_ASSERT( (kernel((cl_kernel)0x1234) >= kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)0x1234) >= kernel((cl_kernel)0x5678)));
    TS_ASSERT( (kernel((cl_kernel)0x5678) >= kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)0x1234) >= kernel((cl_kernel)NULL)));
    TS_ASSERT(!(kernel((cl_kernel)NULL)   >= kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)NULL)   >= kernel((cl_kernel)NULL)));
  }
  /** // doc: test__get_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_info( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Dummy_clGetKernelInfo mock3(CL_SUCCESS);

    kernel k((cl_kernel)0x4321);
    k.get_info(kernel_info_t::context, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_CONTEXT);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (size_t*)0x5678);
  }
  /** // doc: test__get_info__uninitialized_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_info__uninitialized_kernel( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Dummy_clGetKernelInfo mock3(CL_SUCCESS);

    kernel k((cl_kernel)NULL);
    TS_ASSERT_THROWS(k.get_info(kernel_info_t::context, 0, nullptr, nullptr), uninitialized_kernel_error);
  }
  /** // doc: test__get_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_reference_count( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelInfo mock3([](cl_kernel,
                                          cl_kernel_info param_name,
                                          size_t param_value_size,
                                          void* param_value,
                                          size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_uint)CL_KERNEL_REFERENCE_COUNT) {
          if(param_value && param_value_size >= sizeof(cl_uint))
            *((cl_uint*)param_value) = 12u;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_uint);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);
    TS_ASSERT_EQUALS(k.get_reference_count(), 12u);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_REFERENCE_COUNT);
  }
  /** // doc: test__get_function_name() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_function_name( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelInfo mock3([](cl_kernel,
                                          cl_kernel_info param_name,
                                          size_t param_value_size,
                                          void* param_value,
                                          size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_uint)CL_KERNEL_FUNCTION_NAME) {
          if(param_value && param_value_size >= 13 * sizeof(char)) {
            std::strcpy((char*)param_value, "foo_function");
            ((char*)param_value)[12] = '\0';
          }
          if(param_value_size_ret)
            *param_value_size_ret = 13 * sizeof(char);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);
    std::string str = k.get_function_name();

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_FUNCTION_NAME);
    TS_ASSERT_EQUALS(str.size(), 12ul);
    TS_ASSERT_EQUALS(str, "foo_function");
  }
  /** // doc: test__get_num_args() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_num_args( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelInfo mock3([](cl_kernel,
                                          cl_kernel_info param_name,
                                          size_t param_value_size,
                                          void* param_value,
                                          size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_uint)CL_KERNEL_NUM_ARGS) {
          if(param_value && param_value_size >= sizeof(cl_uint))
            *((cl_uint*)param_value) = 12u;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_uint);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);
    TS_ASSERT_EQUALS(k.get_num_args(), 12u);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_NUM_ARGS);
  }
  /** // doc: test__get_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_context( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelInfo mock3([](cl_kernel,
                                          cl_kernel_info param_name,
                                          size_t param_value_size,
                                          void* param_value,
                                          size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_uint)CL_KERNEL_CONTEXT) {
          if(param_value && param_value_size >= sizeof(cl_context))
            *((cl_context*)param_value) = (cl_context)12;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_context);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);

    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);
    TS_ASSERT_EQUALS(k.get_context().get(), (cl_context)12);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_CONTEXT);
  }
  /** // doc: test__get_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelInfo mock3([](cl_kernel,
                                          cl_kernel_info param_name,
                                          size_t param_value_size,
                                          void* param_value,
                                          size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_uint)CL_KERNEL_PROGRAM) {
          if(param_value && param_value_size >= sizeof(cl_uint))
            *((cl_program*)param_value) = (cl_program)12;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_program);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);

    T::Dummy_clRetainProgram mock4(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock5(CL_SUCCESS);
    TS_ASSERT_EQUALS(k.get_program().get(), (cl_program)12);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_PROGRAM);
  }
  /** // doc: test__get_attributes() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_attributes( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelInfo mock3([](cl_kernel,
                                          cl_kernel_info param_name,
                                          size_t param_value_size,
                                          void* param_value,
                                          size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_uint)CL_KERNEL_ATTRIBUTES) {
          if(param_value && param_value_size >= 12 * sizeof(char)) {
            std::strcpy((char*)param_value, "attr1 attr2");
            ((char*)param_value)[11] = '\0';
          }
          if(param_value_size_ret)
            *param_value_size_ret = 12 * sizeof(char);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);
    std::string str = k.get_attributes();

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_ATTRIBUTES);
    TS_ASSERT_EQUALS(str.size(), 11);
    TS_ASSERT_EQUALS(str, "attr1 attr2");
#endif
  }
  /** // doc: test__get_arg_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_arg_info( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelArgInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Dummy_clGetKernelArgInfo mock3(CL_SUCCESS);

    kernel k((cl_kernel)0x4321);
    k.get_arg_info(0, kernel_arg_info_t::address_qualifier, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 0);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_ARG_ADDRESS_QUALIFIER);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), (size_t*)0x5678);
#endif
  }
  /** // doc: test__get_arg_address_qualifier() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_arg_address_qualifier( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelArgInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelArgInfo mock3([](cl_kernel,
                                            cl_uint arg_index,
                                            cl_kernel_arg_info param_name,
                                            size_t param_value_size,
                                            void* param_value,
                                            size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_KERNEL_ARG_ADDRESS_QUALIFIER) {
          if(param_value && param_value_size >= sizeof(cl_kernel_arg_address_qualifier)) {
            if(arg_index == 2)
              *((cl_kernel_arg_address_qualifier*)param_value) = (cl_kernel_arg_address_qualifier)CL_KERNEL_ARG_ADDRESS_LOCAL;
            else
              *((cl_kernel_arg_address_qualifier*)param_value) = (cl_kernel_arg_address_qualifier)CL_KERNEL_ARG_ADDRESS_GLOBAL;
          }
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_kernel_arg_address_qualifier);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);
    TS_ASSERT(k.get_arg_address_qualifier(2) == kernel_arg_address_qualifier_t::local);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_ARG_ADDRESS_QUALIFIER);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(cl_kernel_arg_address_qualifier));
#endif
  }
  /** // doc: test__get_arg_access_qualifier() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_arg_access_qualifier( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelArgInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelArgInfo mock3([](cl_kernel,
                                            cl_uint arg_index,
                                            cl_kernel_arg_info param_name,
                                            size_t param_value_size,
                                            void* param_value,
                                            size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_KERNEL_ARG_ACCESS_QUALIFIER) {
          if(param_value && param_value_size >= sizeof(cl_kernel_arg_access_qualifier)) {
            if(arg_index == 2)
              *((cl_kernel_arg_access_qualifier*)param_value) = (cl_kernel_arg_access_qualifier)CL_KERNEL_ARG_ACCESS_WRITE_ONLY;
            else
              *((cl_kernel_arg_access_qualifier*)param_value) = (cl_kernel_arg_access_qualifier)CL_KERNEL_ARG_ACCESS_READ_WRITE;
          }
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_kernel_arg_access_qualifier);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);
    TS_ASSERT(k.get_arg_access_qualifier(2) == kernel_arg_access_qualifier_t::write_only);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_ARG_ACCESS_QUALIFIER);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(cl_kernel_arg_access_qualifier));
#endif
  }
  /** // doc: test__get_arg_type_name() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_arg_type_name( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelArgInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelArgInfo mock3([](cl_kernel,
                                            cl_uint arg_index,
                                            cl_kernel_arg_info param_name,
                                            size_t param_value_size,
                                            void* param_value,
                                            size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_KERNEL_ARG_TYPE_NAME) {
          if(param_value && param_value_size >= 9 * sizeof(char)) {
            if(arg_index == 2)
              std::strcpy((char*)param_value, "arg2type");
            else
              std::strcpy((char*)param_value, "12345678");
            ((char*)param_value)[8] = '\0';
          }
          if(param_value_size_ret)
            *param_value_size_ret = 9 * sizeof(char);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);
    TS_ASSERT_EQUALS(k.get_arg_type_name(2), "arg2type");
    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_ARG_TYPE_NAME);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), 9 * sizeof(char));
#endif
  }
  /** // doc: test__get_arg_type_qualifier() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_arg_type_qualifier( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelArgInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelArgInfo mock3([](cl_kernel,
                                            cl_uint arg_index,
                                            cl_kernel_arg_info param_name,
                                            size_t param_value_size,
                                            void* param_value,
                                            size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_KERNEL_ARG_TYPE_QUALIFIER) {
          if(param_value && param_value_size >= sizeof(cl_kernel_arg_type_qualifier)) {
            if(arg_index == 2)
              *((cl_kernel_arg_type_qualifier*)param_value) = (cl_kernel_arg_type_qualifier)CL_KERNEL_ARG_TYPE_CONST;
            else
              *((cl_kernel_arg_type_qualifier*)param_value) = (cl_kernel_arg_type_qualifier)CL_KERNEL_ARG_TYPE_NONE;
          }
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_kernel_arg_type_qualifier);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);
    TS_ASSERT(k.get_arg_type_qualifier(2) == kernel_arg_type_qualifier_t::const_);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_ARG_TYPE_QUALIFIER);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(cl_kernel_arg_type_qualifier));
#endif
  }
  /** // doc: test__get_arg_name() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_arg_name( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelArgInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelArgInfo mock3([](cl_kernel,
                                            cl_uint arg_index,
                                            cl_kernel_arg_info param_name,
                                            size_t param_value_size,
                                            void* param_value,
                                            size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_KERNEL_ARG_NAME) {
          if(param_value && param_value_size >= 10 * sizeof(char)) {
            if(arg_index == 2)
              std::strcpy((char*)param_value, "argument2");
            else
              std::strcpy((char*)param_value, "123456789");
            ((char*)param_value)[9] = '\0';
          }
          if(param_value_size_ret)
            *param_value_size_ret = 10 * sizeof(char);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);
    TS_ASSERT_EQUALS(k.get_arg_name(2), "argument2");
    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_ARG_NAME);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), 10 * sizeof(char));
#endif
  }
  /** // doc: test__get_work_group_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_work_group_info( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Dummy_clGetKernelWorkGroupInfo mock3(CL_SUCCESS);

    kernel k((cl_kernel)0x4321);

#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);
#endif

    device d((cl_device_id)0x7654);

    k.get_work_group_info(d, kernel_work_group_info_t::work_group_size, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());

    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_work_group_info)CL_KERNEL_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), (size_t*)0x5678);
  }
  /** // doc: test__get_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_work_group_size( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelWorkGroupInfo mock3([](cl_kernel,
                                                   cl_device_id,
                                                   cl_kernel_work_group_info param_name,
                                                  size_t param_value_size,
                                                  void* param_value,
                                                  size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_KERNEL_WORK_GROUP_SIZE) {
          if(param_value && param_value_size >= sizeof(size_t))
            *((size_t*)param_value) = 123ul;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(size_t);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);

#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);
#endif

    device d((cl_device_id)0x7654);

    TS_ASSERT(k.get_work_group_size(d) == 123ul);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_work_group_info)CL_KERNEL_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(size_t));
  }
  /** // doc: test__get_compile_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_compile_work_group_size( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelWorkGroupInfo mock3([](cl_kernel,
                                                   cl_device_id,
                                                   cl_kernel_work_group_info param_name,
                                                   size_t param_value_size,
                                                   void* param_value,
                                                   size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_KERNEL_COMPILE_WORK_GROUP_SIZE) {
          if(param_value && param_value_size >= 3*sizeof(size_t)) {
            ((size_t*)param_value)[0] = 123ul;
            ((size_t*)param_value)[1] = 124ul;
            ((size_t*)param_value)[2] = 125ul;
          }
          if(param_value_size_ret)
            *param_value_size_ret = 3*sizeof(size_t);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);

#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);
#endif

    device d((cl_device_id)0x7654);

    size_t array[4] = {0};

    k.get_compile_work_group_size(array, d);

    TS_ASSERT_EQUALS(array[0], 123ul);
    TS_ASSERT_EQUALS(array[1], 124ul);
    TS_ASSERT_EQUALS(array[2], 125ul);
    TS_ASSERT_EQUALS(array[3], 0);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_work_group_info)CL_KERNEL_COMPILE_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), 3*sizeof(size_t));
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), array);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), static_cast<const void*>(nullptr));
  }
  /** // doc: test__get_local_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_local_mem_size( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelWorkGroupInfo mock3([](cl_kernel,
                                                   cl_device_id,
                                                   cl_kernel_work_group_info param_name,
                                                   size_t param_value_size,
                                                   void* param_value,
                                                   size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_KERNEL_LOCAL_MEM_SIZE) {
          if(param_value && param_value_size >= sizeof(cl_ulong))
            *((cl_ulong*)param_value) = 123ul;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_ulong);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);

#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);
#endif

    device d((cl_device_id)0x7654);

    TS_ASSERT(k.get_local_mem_size(d) == 123ul);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_work_group_info)CL_KERNEL_LOCAL_MEM_SIZE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(cl_ulong));
  }
  /** // doc: test__get_preferred_work_group_size_multiple() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_preferred_work_group_size_multiple( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelWorkGroupInfo mock3([](cl_kernel,
                                                   cl_device_id,
                                                   cl_kernel_work_group_info param_name,
                                                   size_t param_value_size,
                                                   void* param_value,
                                                   size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE) {
          if(param_value && param_value_size >= sizeof(size_t))
            *((size_t*)param_value) = 123ul;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(size_t);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);

#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);
#endif

    device d((cl_device_id)0x7654);

    TS_ASSERT(k.get_preferred_work_group_size_multiple(d) == 123ul);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_work_group_info)CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(size_t));
#endif
  }
  /** // doc: test__get_private_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_private_mem_size( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelWorkGroupInfo mock3([](cl_kernel,
                                                   cl_device_id,
                                                   cl_kernel_work_group_info param_name,
                                                   size_t param_value_size,
                                                   void* param_value,
                                                   size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_KERNEL_PRIVATE_MEM_SIZE) {
          if(param_value && param_value_size >= sizeof(cl_ulong))
            *((cl_ulong*)param_value) = 123ul;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_ulong);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);

#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);
#endif

    device d((cl_device_id)0x7654);

    TS_ASSERT(k.get_private_mem_size(d) == 123ul);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_work_group_info)CL_KERNEL_PRIVATE_MEM_SIZE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(cl_ulong));
#endif
  }
  /** // doc: test__get_global_work_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_global_work_size( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Pluggable_clGetKernelWorkGroupInfo mock3([](cl_kernel,
                                                   cl_device_id,
                                                   cl_kernel_work_group_info param_name,
                                                  size_t param_value_size,
                                                  void* param_value,
                                                  size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_KERNEL_GLOBAL_WORK_SIZE) {
          if(param_value && param_value_size >= 3 * sizeof(size_t)) {
            ((size_t*)param_value)[0] = 123ul;
            ((size_t*)param_value)[1] = 124ul;
            ((size_t*)param_value)[2] = 125ul;
          }
          if(param_value_size_ret)
            *param_value_size_ret = 3 * sizeof(size_t);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    kernel k((cl_kernel)0x4321);

#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);
#endif

    device d((cl_device_id)0x7654);

    size_t array[4] = {0};

    k.get_global_work_size(array, d);

    TS_ASSERT_EQUALS(array[0], 123);
    TS_ASSERT_EQUALS(array[1], 124);
    TS_ASSERT_EQUALS(array[2], 125);
    TS_ASSERT_EQUALS(array[3], 0);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_work_group_info)CL_KERNEL_GLOBAL_WORK_SIZE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), 3*sizeof(size_t));
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), array);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), static_cast<const void*>(nullptr));
#endif
  }
  /** // doc: test__set_arg_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_arg_1( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    T::Dummy_clSetKernelArg mock3(CL_SUCCESS);

    kernel k((cl_kernel)0x4321);

    k.set_arg(2, 7, (const void*)0x7654);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), 7);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), (const void*)0x7654);
  }
  /** // doc: test__set_arg_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_arg_2( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    T::Dummy_clSetKernelArg mock3(CL_SUCCESS);

    kernel k((cl_kernel)0x4321);

    T::Dummy_clRetainMemObject mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock5(CL_SUCCESS);
    mem m((cl_mem)0x1234);

    k.set_arg(2, m);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), sizeof(cl_mem));
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), &m);
  }
  /** // doc: test__set_arg_svm_pointer() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_arg_svm_pointer( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clSetKernelArgSVMPointer)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    T::Dummy_clSetKernelArgSVMPointer mock3(CL_SUCCESS);

    kernel k((cl_kernel)0x4321);

    k.set_arg_svm_pointer(2, (const void*)0x7654);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (const void*)0x7654);
#endif
  }
  /** // doc: test__set_exec_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_exec_info( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clSetKernelExecInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    T::Dummy_clSetKernelExecInfo mock3(CL_SUCCESS);

    kernel k((cl_kernel)0x4321);

    k.set_exec_info(kernel_exec_info_t::svm_ptrs, 7, (const void*)0x7654);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), CL_KERNEL_EXEC_INFO_SVM_PTRS);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), 7);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), (const void*)0x7654);
#endif
  }
};

#endif /* CLXX_B3C_KERNEL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
