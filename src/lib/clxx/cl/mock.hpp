/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE
 */

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

#include <CL/cl.h>
#include <cxxtest/Mock.h>


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

CXXTEST_MOCK_GLOBAL(cl_int, clRetainContext,
  (cl_context context),
  (context)
);

CXXTEST_MOCK_GLOBAL(cl_int, clReleaseContext,
  (cl_context context),
  (context)
);

CXXTEST_MOCK_GLOBAL(cl_int, clGetProgramInfo,
  ( cl_program program, cl_program_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( program, param_name, param_value_size, param_value, param_value_size_ret)
);

CXXTEST_MOCK_GLOBAL(cl_int, clRetainProgram, (cl_program program), (program));
CXXTEST_MOCK_GLOBAL(cl_int, clReleaseProgram, (cl_program program), (program));

#include <clxx/cl/mocks/newton.hpp>
#include <clxx/cl/mocks/corner.hpp>

#endif /* CLXX_CL_MOCK_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
