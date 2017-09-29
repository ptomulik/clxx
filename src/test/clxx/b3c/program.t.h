// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b3c/program.t.h

/** // doc: clxx/b3c/program.t.h {{{
 * \file clxx/b3c/program.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B3C_PROGRAM_T_H_INCLUDED
#define CLXX_B3C_PROGRAM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b3c/program.hpp>
#include <clxx/b3c/context.hpp>
#include <clxx/b3c/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

namespace clxx { class program_test_suite; }

/** // doc: class clxx::program_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::program_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__default_ctor( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    program p;
    TS_ASSERT(!p.is_initialized());
    TS_ASSERT_EQUALS(p.get(), (cl_program)NULL);
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_1( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    program p((cl_program)0x1234);
    TS_ASSERT(p.is_initialized());
    TS_ASSERT_EQUALS(p.get(), (cl_program)0x1234);
    TS_ASSERT(mock1.called_once_with((cl_program)0x1234));
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_ctor_1__null_id() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_1__null_id( )
  {
    T::Dummy_clRetainProgram mock1(CL_INVALID_PROGRAM);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(program((cl_program)NULL));
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_2( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clCreateProgramWithSource mock3((cl_program)0x5678, CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);

    context ctx((cl_context)0x1234);
    program_sources srcs({"src1;", "src2;"});
    program p(ctx, srcs);

    TS_ASSERT(p.is_initialized());
    TS_ASSERT_EQUALS(p.get(), (cl_program)0x5678);
    TS_ASSERT(mock3.called_once());
    // mock1 not called because the class assumes the implicit retain performed
    // by clCreateProgramWithSource()
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_ctor_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_3( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clCreateProgramWithBinary mock3((cl_program)0x5678, CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);

    context ctx((cl_context)0x1234);
    devices devs({ device((cl_device_id)0x123), device((cl_device_id)0x456) });
    program_binaries bins({ program_binary({1,2}), program_binary({3,4,5}) });
    std::vector<status_t> stats;

    program p(ctx, devs, bins, stats);

    TS_ASSERT(p.is_initialized());
    TS_ASSERT_EQUALS(p.get(), (cl_program)0x5678);
    TS_ASSERT(mock3.called_once());
    // mock1 not called because the class assumes the implicit retain performed
    // by clCreateProgramWithSource()
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
    TS_ASSERT_EQUALS(stats.size(), 2);
  }
  /** // doc: test_ctor_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_4( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clCreateProgramWithBinary mock3((cl_program)0x5678, CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);

    context ctx((cl_context)0x1234);
    devices devs({ device((cl_device_id)0x123), device((cl_device_id)0x456) });
    program_binaries bins({ program_binary({1,2}), program_binary({3,4,5}) });

    program p(ctx, devs, bins);

    TS_ASSERT(p.is_initialized());
    TS_ASSERT_EQUALS(p.get(), (cl_program)0x5678);
    TS_ASSERT(mock3.called_once());
    // mock1 not called because the class assumes the implicit retain performed
    // by clCreateProgramWithBinary()
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_ctor_5() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_5( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clCreateProgramWithBuiltInKernels)
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clCreateProgramWithBuiltInKernels mock3((cl_program)0x5678, CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);

    context ctx((cl_context)0x1234);
    devices devs({ device((cl_device_id)0x123), device((cl_device_id)0x456) });
    std::string kerns("kern1 kern2");

    program p(ctx, devs, kerns);

    TS_ASSERT(p.is_initialized());
    TS_ASSERT_EQUALS(p.get(), (cl_program)0x5678);
    TS_ASSERT(mock3.called_once());
    // mock1 not called because the class assumes the implicit retain performed
    // by clCreateProgramWithBuiltinKernels()
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
#endif
  }
  /** // doc: test_copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_copy_ctor( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    program p1((cl_program)0x1234);
    program p2(p1);
    TS_ASSERT(p2.is_initialized());
    TS_ASSERT(mock1.called_twice());
    TS_ASSERT(mock2.never_called());
    TS_ASSERT_EQUALS(p2, program((cl_program)0x1234));
  }
  /** // doc: test_dtor__notnull() {{{
   * \todo Write documentation
   */ // }}}
  void test_dtor__notnull( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    {
      program p((cl_program)0x1234);
    }
    TS_ASSERT(mock2.called_once_with((cl_program)0x1234));
  }
  /** // doc: test_dtor__null() {{{
   * \todo Write documentation
   */ // }}}
  void test_dtor__null( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    {
      program p((cl_program)NULL);
    }
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_id() {{{
   * \todo Write documentation
   */ // }}}
  void test_id( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(program((cl_program)0x1234).get(), (cl_program)0x1234);
    TS_ASSERT_EQUALS(program((cl_program)NULL).get(), (cl_program)NULL);
  }
  /** // doc: test_chk_get() {{{
   * \todo Write documentation
   */ // }}}
  void test_chk_get( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(program((cl_program)0x1234).chk_get(), (cl_program)0x1234);
    TS_ASSERT_THROWS(program((cl_program)NULL).chk_get(), uninitialized_program_error);
  }
  /** // doc: test__assign__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign__1( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    program c1((cl_program)0x1234);
    program c2((cl_program)0x5678);
    TS_ASSERT(c1 != c2);
    c2.assign(c1);
    TS_ASSERT(mock1.called_three_times());
    TS_ASSERT(mock1.last_called_with((cl_program)0x1234));
    TS_ASSERT(mock2.called_once_with((cl_program)0x5678));
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test__assign__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign__2( )
  {
    program c1;
    program c2;
    {
      T::Dummy_clRetainProgram mock_clRetainProgram(CL_SUCCESS);
      T::Dummy_clReleaseProgram mock_clReleaseProgram(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(c2.assign(c1));
      TS_ASSERT(mock_clRetainProgram.never_called());
      TS_ASSERT(mock_clReleaseProgram.never_called());
    }
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test__assign__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign__3( )
  {
    T::Dummy_clRetainProgram mock_clRetainProgram(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock_clReleaseProgram(CL_SUCCESS);
    program c1;
    program c2((cl_program)0x1234);
    {
      T::Dummy_clRetainProgram mock_clRetainProgram2(CL_SUCCESS);
      T::Dummy_clReleaseProgram mock_clReleaseProgram2(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(c2.assign(c1));
      TS_ASSERT(mock_clRetainProgram2.never_called());
      TS_ASSERT(mock_clReleaseProgram2.called_once_with((cl_program)0x1234));
    }
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test_op_assign() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_assign( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    program p1((cl_program)0x1234);
    program p2((cl_program)0x5678);
    p1 = p2;
    TS_ASSERT_EQUALS(p1.get(), (cl_program)0x5678);
  }
  /** // doc: test_op_eq() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_eq( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    TS_ASSERT( (program((cl_program)0x1234) == program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)0x1234) == program((cl_program)0x5678)));
    TS_ASSERT(!(program((cl_program)0x5678) == program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)0x1234) == program((cl_program)NULL)));
    TS_ASSERT(!(program((cl_program)NULL)   == program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)NULL)   == program((cl_program)NULL)));
  }
  /** // doc: test_op_neq() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_neq( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    TS_ASSERT(!(program((cl_program)0x1234) != program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)0x1234) != program((cl_program)0x5678)));
    TS_ASSERT( (program((cl_program)0x5678) != program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)0x1234) != program((cl_program)NULL)));
    TS_ASSERT( (program((cl_program)NULL)   != program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)NULL)   != program((cl_program)NULL)));
  }
  /** // doc: test_op_lt() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_lt( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    TS_ASSERT(!(program((cl_program)0x1234) < program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)0x1234) < program((cl_program)0x5678)));
    TS_ASSERT(!(program((cl_program)0x5678) < program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)0x1234) < program((cl_program)NULL)));
    TS_ASSERT( (program((cl_program)NULL)   < program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)NULL)   < program((cl_program)NULL)));
  }
  /** // doc: test_op_gt() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_gt( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    TS_ASSERT(!(program((cl_program)0x1234) > program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)0x1234) > program((cl_program)0x5678)));
    TS_ASSERT( (program((cl_program)0x5678) > program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)0x1234) > program((cl_program)NULL)));
    TS_ASSERT(!(program((cl_program)NULL)   > program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)NULL)   > program((cl_program)NULL)));
  }
  /** // doc: test_op_le() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_le( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    TS_ASSERT( (program((cl_program)0x1234) <= program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)0x1234) <= program((cl_program)0x5678)));
    TS_ASSERT(!(program((cl_program)0x5678) <= program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)0x1234) <= program((cl_program)NULL)));
    TS_ASSERT( (program((cl_program)NULL)   <= program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)NULL)   <= program((cl_program)NULL)));
  }
  /** // doc: test_op_ge() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_ge( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    TS_ASSERT( (program((cl_program)0x1234) >= program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)0x1234) >= program((cl_program)0x5678)));
    TS_ASSERT( (program((cl_program)0x5678) >= program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)0x1234) >= program((cl_program)NULL)));
    TS_ASSERT(!(program((cl_program)NULL)   >= program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)NULL)   >= program((cl_program)NULL)));
  }
  /** // doc: test_get_info() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_info( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clGetProgramInfo mock3(CL_SUCCESS);

    program p((cl_program)0x4321);
    p.get_info(program_info_t::context, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_program)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_CONTEXT);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (size_t*)0x5678);
  }
  /** // doc: test_get_info__uninitialized_program() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_info__uninitialized_program( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clGetProgramInfo mock3(CL_SUCCESS);

    program p((cl_program)NULL);
    TS_ASSERT_THROWS(p.get_info(program_info_t::context, 0, nullptr, nullptr), uninitialized_program_error);
  }
  /** // doc: test_get_build_info() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_build_info( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clGetProgramBuildInfo mock3(CL_SUCCESS);

    program p((cl_program)0x4321);
    p.get_build_info(device((cl_device_id)0x8765), program_build_info_t::status, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_program)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x8765);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_uint)CL_PROGRAM_BUILD_STATUS);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), (size_t*)0x5678);
  }
  /** // doc: test_get_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_reference_count( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Pluggable_clGetProgramInfo mock3([](cl_program,
                                           cl_program_info param_name,
                                           size_t param_value_size,
                                           void* param_value,
                                           size_t* param_value_size_ret) -> cl_int {
      if(param_name == CL_PROGRAM_REFERENCE_COUNT) {
        if(param_value && param_value_size >= sizeof(cl_uint))
          *((cl_uint*)param_value) = 12u;
        if(param_value_size_ret)
          *param_value_size_ret = sizeof(cl_uint);
        return CL_SUCCESS;
      } else {
        return CL_INVALID_VALUE;
      }
    });

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_reference_count(), 12u);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_REFERENCE_COUNT);
  }
  /** // doc: test_get_context() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_context( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);
    T::Pluggable_clGetProgramInfo mock3([](cl_program,
                                           cl_program_info param_name,
                                           size_t param_value_size,
                                           void* param_value,
                                           size_t* param_value_size_ret) -> cl_int {
      if(param_name == CL_PROGRAM_CONTEXT) {
        if(param_value && param_value_size >= sizeof(cl_context))
          *((cl_context*)param_value) = (cl_context)0x123;
        if(param_value_size_ret)
          *param_value_size_ret = sizeof(cl_context);
        return CL_SUCCESS;
      } else {
        return CL_INVALID_VALUE;
      }
    });

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_context(), context((cl_context)0x123));

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_CONTEXT);
  }
  /** // doc: test_get_num_devices() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_num_devices( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Pluggable_clGetProgramInfo mock3([](cl_program,
                                           cl_program_info param_name,
                                           size_t param_value_size,
                                           void* param_value,
                                           size_t* param_value_size_ret) -> cl_int {
      if(param_name == CL_PROGRAM_NUM_DEVICES) {
        if(param_value && param_value_size >= sizeof(cl_uint))
          *((cl_uint*)param_value) = 12u;
        if(param_value_size_ret)
          *param_value_size_ret = sizeof(cl_uint);
        return CL_SUCCESS;
      } else {
        return CL_INVALID_VALUE;
      }
    });

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_num_devices(), 12ul);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_NUM_DEVICES);
  }
  /** // doc: test_get_devices() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_devices( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Pluggable_clGetProgramInfo mock3([](cl_program,
                                           cl_program_info param_name,
                                           size_t param_value_size,
                                           void* param_value,
                                           size_t* param_value_size_ret) -> cl_int {
      if(param_name == CL_PROGRAM_DEVICES) {
        if(param_value) {
          if(param_value_size >= 1 * sizeof(cl_device_id)) ((cl_device_id*)param_value)[0] = (cl_device_id)0x123;
          if(param_value_size >= 2 * sizeof(cl_device_id)) ((cl_device_id*)param_value)[1] = (cl_device_id)0x456;
          if(param_value_size >= 3 * sizeof(cl_device_id)) ((cl_device_id*)param_value)[2] = (cl_device_id)0x789;
          if(param_value_size_ret)
            *param_value_size_ret = std::min(3*sizeof(cl_device_id), param_value_size);
        } else if(param_value_size_ret) {
          *param_value_size_ret = 3 * sizeof(cl_device_id);
        }
        return CL_SUCCESS;
      } else {
        return CL_INVALID_VALUE;
      }
    });

    program p((cl_program)0x4321);
    devices ds(p.get_devices());

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_DEVICES);
    TS_ASSERT_EQUALS(ds.size(), 3);
    TS_ASSERT_EQUALS(ds[0].get(), (cl_device_id)0x123);
    TS_ASSERT_EQUALS(ds[1].get(), (cl_device_id)0x456);
    TS_ASSERT_EQUALS(ds[2].get(), (cl_device_id)0x789);
  }
  /** // doc: test_get_source() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_source( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Pluggable_clGetProgramInfo mock3([](cl_program,
                                           cl_program_info param_name,
                                           size_t param_value_size,
                                           void* param_value,
                                           size_t* param_value_size_ret) -> cl_int {
      if(param_name == CL_PROGRAM_SOURCE) {
        if(param_value && param_value_size >= 4 * sizeof(char)) {
          std::strcpy((char*)param_value, "foo");
          ((char*)param_value)[3] = '\0';
        }
        if(param_value_size_ret)
          *param_value_size_ret = 4 * sizeof(char);
        return CL_SUCCESS;
      } else {
        return CL_INVALID_VALUE;
      }
    });

    program p((cl_program)0x4321);
    program_source src(p.get_source());

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_SOURCE);
    TS_ASSERT_EQUALS(src.size(), 3);
    TS_ASSERT_EQUALS(src, "foo");
  }
  /** // doc: test_get_binary_sizes() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_binary_sizes( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Pluggable_clGetProgramInfo mock3([](cl_program,
                                           cl_program_info param_name,
                                           size_t param_value_size,
                                           void* param_value,
                                           size_t* param_value_size_ret) -> cl_int {
      if(param_name == CL_PROGRAM_BINARY_SIZES) {
        if(param_value) {
          if(param_value_size >= 1 * sizeof(size_t)) ((size_t*)param_value)[0] = 0x123ul;
          if(param_value_size >= 2 * sizeof(size_t)) ((size_t*)param_value)[1] = 0x456ul;
          if(param_value_size >= 3 * sizeof(size_t)) ((size_t*)param_value)[2] = 0x789ul;
          if(param_value_size_ret)
            *param_value_size_ret = std::min(3*sizeof(size_t), param_value_size);
        } else if(param_value_size_ret) {
          *param_value_size_ret = 3 * sizeof(size_t);
        }
        return CL_SUCCESS;
      } else {
        return CL_INVALID_VALUE;
      }
    });

    program p((cl_program)0x4321);
    std::vector<size_t> sizes(p.get_binary_sizes());

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_BINARY_SIZES);
    TS_ASSERT_EQUALS(sizes.size(), 3);
    TS_ASSERT_EQUALS(sizes[0], 0x123ul);
    TS_ASSERT_EQUALS(sizes[1], 0x456ul);
    TS_ASSERT_EQUALS(sizes[2], 0x789ul);
  }
  /** // doc: test_get_binaries() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_binaries( )
  {
    TS_ASSERT(true); // no idea ATM how to mock and test it
  }
  /** // doc: test_get_num_kernels() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_num_kernels( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Pluggable_clGetProgramInfo mock3([](cl_program,
                                           cl_program_info param_name,
                                           size_t param_value_size,
                                           void* param_value,
                                           size_t* param_value_size_ret) -> cl_int {
      if(param_name == CL_PROGRAM_NUM_KERNELS) {
        if(param_value && param_value_size >= sizeof(size_t))
          *((size_t*)param_value) = 3ul;
        if(param_value_size_ret)
          *param_value_size_ret = sizeof(size_t);
        return CL_SUCCESS;
      } else {
        return CL_INVALID_VALUE;
      }
    });

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_num_kernels(), 3ul);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_NUM_KERNELS);
#endif
  }
  /** // doc: test_get_kernel_names() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_kernel_names( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Pluggable_clGetProgramInfo mock3([](cl_program,
                                           cl_program_info param_name,
                                           size_t param_value_size,
                                           void* param_value,
                                           size_t* param_value_size_ret) -> cl_int {
      if(param_name == CL_PROGRAM_KERNEL_NAMES) {
        if(param_value && param_value_size >= 8 * sizeof(char)) {
          std::strcpy((char*)param_value, "foo bar");
          ((char*)param_value)[7] = '\0';
        }
        if(param_value_size_ret)
          *param_value_size_ret = 8 * sizeof(char);
        return CL_SUCCESS;
      } else {
        return CL_INVALID_VALUE;
      }
    });

    program p((cl_program)0x4321);
    std::string kerns(p.get_kernel_names());

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_KERNEL_NAMES);
    TS_ASSERT_EQUALS(kerns, "foo bar");
#endif
  }
  /** // doc: test_get_build_status() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_build_status( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Pluggable_clGetProgramBuildInfo mock3([](cl_program,
                                                cl_device_id,
                                                cl_program_build_info param_name,
                                                size_t param_value_size,
                                                void* param_value,
                                                size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_PROGRAM_BUILD_STATUS) {
          if(param_value && param_value_size >= sizeof(cl_build_status))
            *((cl_build_status*)param_value) = (cl_build_status)CL_BUILD_IN_PROGRESS;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_build_status);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_build_status(device((cl_device_id)0x1234)), build_status_t::in_progress);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_build_status)CL_PROGRAM_BUILD_STATUS);
  }
  /** // doc: test_get_build_options() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_build_options( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Pluggable_clGetProgramBuildInfo mock3([](cl_program,
                                                cl_device_id,
                                                cl_program_build_info param_name,
                                                size_t param_value_size,
                                                void* param_value,
                                                size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_PROGRAM_BUILD_OPTIONS) {
          if(param_value && param_value_size >= 20 * sizeof(char)) {
            std::strcpy((char*)param_value, "--option1 --option2");
            ((char*)param_value)[19] = '\0';
          }
          if(param_value_size_ret)
            *param_value_size_ret = 20 * sizeof(char);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_build_options(device((cl_device_id)0x1234)), "--option1 --option2");

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_uint)CL_PROGRAM_BUILD_OPTIONS);
  }
  /** // doc: test_get_build_log() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_build_log( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Pluggable_clGetProgramBuildInfo mock3([](cl_program,
                                                cl_device_id,
                                                cl_program_build_info param_name,
                                                size_t param_value_size,
                                                void* param_value,
                                                size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_PROGRAM_BUILD_LOG) {
          if(param_value && param_value_size >= 15 * sizeof(char)) {
            std::strcpy((char*)param_value, "blah blah blah");
            ((char*)param_value)[14] = '\0';
          }
          if(param_value_size_ret)
            *param_value_size_ret = 15 * sizeof(char);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_build_log(device((cl_device_id)0x1234)), "blah blah blah");

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_uint)CL_PROGRAM_BUILD_LOG);
  }
  /** // doc: test_get_binary_type() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_binary_type( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Pluggable_clGetProgramBuildInfo mock3([](cl_program,
                                                cl_device_id,
                                                cl_program_build_info param_name,
                                                size_t param_value_size,
                                                void* param_value,
                                                size_t* param_value_size_ret) -> cl_int {
        if(param_name == CL_PROGRAM_BINARY_TYPE) {
          if(param_value && param_value_size >= sizeof(cl_program_binary_type))
            *((cl_program_binary_type*)param_value) = (cl_program_binary_type)CL_PROGRAM_BINARY_TYPE_LIBRARY;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_program_binary_type);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_binary_type(device((cl_device_id)0x1234)), program_binary_type_t::library);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_build_status)CL_PROGRAM_BINARY_TYPE);
#endif
  }
};

#endif /* CLXX_B3C_PROGRAM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
