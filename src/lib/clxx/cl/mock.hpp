// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/mock.hpp

/** // doc: clxx/cl/mock.hpp {{{
 * \file clxx/cl/mock.hpp
 *
 * \brief CxxTest mocks for OpenCL functions.
 *
 * This file declares OpenCL mocks for CxxTest-based unit tests. Particular
 * implementations are provided by headers found in clxx/cl/mocks/ directory.
 */ // }}}
#ifndef CLXX_CL_MOCK_HPP_INCLUDED
#define CLXX_CL_MOCK_HPP_INCLUDED

#include <clxx/cl/cl.h>
#include <cxxtest/Mock.h>

/** \cond SHOW_IGNORED_COMPOUNDS */
CXXTEST_MOCK_GLOBAL(cl_int, clGetPlatformIDs,
  (cl_uint num_entries, cl_platform_id* platforms, cl_uint *num_platforms),
  (num_entries, platforms, num_platforms)
);

CXXTEST_MOCK_GLOBAL(cl_int, clGetPlatformInfo,
  ( cl_platform_id platform, cl_platform_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( platform, param_name, param_value_size, param_value, param_value_size_ret)
);

CXXTEST_MOCK_GLOBAL(cl_int, clGetDeviceIDs,
  (cl_platform_id platform, cl_device_type device_type, cl_uint num_entries,
   cl_device_id* devices, cl_uint *num_devices),
  (platform, device_type, num_entries, devices, num_devices)
);

CXXTEST_MOCK_GLOBAL(cl_int, clGetDeviceInfo,
  ( cl_device_id device, cl_device_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( device, param_name, param_value_size, param_value, param_value_size_ret)
);

CXXTEST_MOCK_GLOBAL(cl_context, clCreateContext,
  ( const cl_context_properties *properties, cl_uint num_devices,
    const cl_device_id* devices,
    void (*pfn_notify)( const char* errinfo, const void* private_info,
                        size_t cb, void *user_data ),
    void *user_data,
    cl_int* errcode_ret ),
  ( properties, num_devices, devices, pfn_notify, user_data, errcode_ret)
);

CXXTEST_MOCK_GLOBAL(cl_context, clCreateContextFromType,
  ( const cl_context_properties *properties, const cl_device_type device_type,
    void (*pfn_notify)( const char* errinfo, const void* private_info,
                        size_t cb, void *user_data ),
    void *user_data,
    cl_int* errcode_ret ),
  ( properties, device_type, pfn_notify, user_data, errcode_ret)
);

CXXTEST_MOCK_GLOBAL(cl_int, clGetContextInfo,
  ( cl_context context, cl_context_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( context, param_name, param_value_size, param_value, param_value_size_ret)
);

CXXTEST_MOCK_GLOBAL(cl_int, clRetainContext,(cl_context context),(context));
CXXTEST_MOCK_GLOBAL(cl_int, clReleaseContext,(cl_context context),(context));

#if HAVE_OPENCL_clCreateSubDevices
CXXTEST_MOCK_GLOBAL(cl_int, clCreateSubDevices,
  ( cl_device_id in_device, const cl_device_partition_property* properties,
    cl_uint num_devices, cl_device_id* out_devices, cl_uint* num_devices_ret),
  ( in_device, properties, num_devices, out_devices, num_devices_ret)
);
#endif
#if HAVE_OPENCL_clRetainDevice
CXXTEST_MOCK_GLOBAL(cl_int, clRetainDevice, (cl_device_id device), (device));
#endif
#if HAVE_OPENCL_clReleaseDevice
CXXTEST_MOCK_GLOBAL(cl_int, clReleaseDevice, (cl_device_id device), (device));
#endif

CXXTEST_MOCK_GLOBAL(cl_program, clCreateProgramWithSource,
  ( cl_context context, cl_uint count, const char** strings,
    const size_t* lengths, cl_int* errcode_ret),
  ( context, count, strings, lengths, errcode_ret )
);

CXXTEST_MOCK_GLOBAL(cl_program, clCreateProgramWithBinary,
  ( cl_context context, cl_uint num_devices, const cl_device_id* device_list,
    const size_t* lengths, const unsigned char** binaries,
    cl_int* binary_status, cl_int* errcode_ret),
  ( context, num_devices, device_list, lengths, binaries, binary_status,
    errcode_ret)
);

#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
CXXTEST_MOCK_GLOBAL(cl_program, clCreateProgramWithBuiltInKernels,
  ( cl_context context, cl_uint num_devices, const cl_device_id* device_list,
    const char* kernel_names, cl_int* errcode_ret),
  ( context, num_devices, device_list, kernel_names, errcode_ret )
);
#endif

CXXTEST_MOCK_GLOBAL(cl_int, clRetainProgram, (cl_program program), (program));
CXXTEST_MOCK_GLOBAL(cl_int, clReleaseProgram, (cl_program program), (program));

CXXTEST_MOCK_GLOBAL(cl_int, clGetProgramInfo,
  ( cl_program program, cl_program_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( program, param_name, param_value_size, param_value, param_value_size_ret)
);
/** \endcond */

#include <clxx/cl/mocks/newton.hpp>
#include <clxx/cl/mocks/dummy.hpp>

#endif /* CLXX_CL_MOCK_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
