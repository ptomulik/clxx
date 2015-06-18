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

#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
CXXTEST_MOCK_GLOBAL(cl_int, clCreateSubDevices,
  ( cl_device_id in_device, const cl_device_partition_property* properties,
    cl_uint num_devices, cl_device_id* out_devices, cl_uint* num_devices_ret),
  ( in_device, properties, num_devices, out_devices, num_devices_ret)
);
#endif
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
CXXTEST_MOCK_GLOBAL(cl_int, clRetainDevice, (cl_device_id device), (device));
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
CXXTEST_MOCK_GLOBAL(cl_int, clReleaseDevice, (cl_device_id device), (device));
#endif

#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING
CXXTEST_MOCK_GLOBAL(cl_command_queue, clCreateCommandQueue,
  ( cl_context context, cl_device_id device,
    cl_command_queue_properties properties, cl_int* errcode_ret ),
  ( context, device, properties, errcode_ret )
);
CLXX_DIAGNOSTIC_POP
#endif

#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
CXXTEST_MOCK_GLOBAL(cl_command_queue, clCreateCommandQueueWithProperties,
  ( cl_context context, cl_device_id device,
    const cl_queue_properties* properties, cl_int* errcode_ret ),
  ( context, device, properties, errcode_ret )
);
#endif

CXXTEST_MOCK_GLOBAL(cl_int, clRetainCommandQueue,
                    (cl_command_queue command_queue), (command_queue));
CXXTEST_MOCK_GLOBAL(cl_int, clReleaseCommandQueue,
                    (cl_command_queue command_queue), (command_queue));

CXXTEST_MOCK_GLOBAL(cl_int, clGetCommandQueueInfo,
  ( cl_command_queue command_queue, cl_command_queue_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( command_queue, param_name, param_value_size, param_value, param_value_size_ret)
);

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

#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
CXXTEST_MOCK_GLOBAL(cl_program, clCreateProgramWithBuiltInKernels,
  ( cl_context context, cl_uint num_devices, const cl_device_id* device_list,
    const char* kernel_names, cl_int* errcode_ret),
  ( context, num_devices, device_list, kernel_names, errcode_ret )
);
#endif

CXXTEST_MOCK_GLOBAL(cl_int, clRetainProgram, (cl_program program), (program));
CXXTEST_MOCK_GLOBAL(cl_int, clReleaseProgram, (cl_program program), (program));

CXXTEST_MOCK_GLOBAL(cl_int, clBuildProgram,
  ( cl_program program, cl_uint num_devices, const cl_device_id* device_list,
    const char* options, void (CL_CALLBACK* pfn_notify)(cl_program, void*),
    void* user_data ),
  ( program, num_devices, device_list, options, pfn_notify, user_data )
);

#if CLXX_OPENCL_ALLOWED(clCompileProgram)
CXXTEST_MOCK_GLOBAL(cl_int, clCompileProgram,
  ( cl_program program, cl_uint num_devices, const cl_device_id* device_list,
    const char* options, cl_uint num_input_headers, const cl_program* input_headers,
    const char** header_include_names, void (CL_CALLBACK* pfn_notify)(cl_program, void*),
    void* user_data ),
  ( program, num_devices, device_list, options, num_input_headers,
    input_headers, header_include_names, pfn_notify, user_data )
);
#endif

#if CLXX_OPENCL_ALLOWED(clLinkProgram)
CXXTEST_MOCK_GLOBAL(cl_program, clLinkProgram,
  ( cl_context context, cl_uint num_devices, const cl_device_id* device_list,
    const char* options, cl_uint num_input_programs, const cl_program* input_programs,
    void (CL_CALLBACK* pfn_notify)(cl_program, void*), void* user_data,
    cl_int* errcode_ret ),
  ( context, num_devices, device_list, options, num_input_programs,
    input_programs, pfn_notify, user_data, errcode_ret )
);
#endif

#if CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
CXXTEST_MOCK_GLOBAL(cl_int, clUnloadPlatformCompiler, (cl_platform_id platform), (platform));
#endif

CXXTEST_MOCK_GLOBAL(cl_int, clGetProgramInfo,
  ( cl_program program, cl_program_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( program, param_name, param_value_size, param_value, param_value_size_ret)
);

CXXTEST_MOCK_GLOBAL(cl_int, clGetProgramBuildInfo,
  ( cl_program program, cl_device_id device, cl_program_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( program, device, param_name, param_value_size, param_value, param_value_size_ret)
);

CXXTEST_MOCK_GLOBAL(cl_kernel, clCreateKernel,
  ( cl_program program, const char* kernel_name, cl_int* errcode_ret),
  ( program, kernel_name, errcode_ret )
);
CXXTEST_MOCK_GLOBAL(cl_int, clCreateKernelsInProgram,
  ( cl_program program, cl_uint num_kernels, cl_kernel* kernels, cl_uint* num_kernels_ret),
  ( program, num_kernels, kernels, num_kernels_ret )
);

CXXTEST_MOCK_GLOBAL(cl_int, clGetKernelInfo,
  ( cl_kernel kernel, cl_kernel_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( kernel, param_name, param_value_size, param_value, param_value_size_ret)
);

#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
CXXTEST_MOCK_GLOBAL(cl_int, clGetKernelArgInfo,
  ( cl_kernel kernel, cl_uint arg_index, cl_kernel_arg_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( kernel, arg_index, param_name, param_value_size, param_value, param_value_size_ret)
);
#endif

CXXTEST_MOCK_GLOBAL(cl_int, clGetKernelWorkGroupInfo,
  ( cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( kernel, device, param_name, param_value_size, param_value, param_value_size_ret)
);

CXXTEST_MOCK_GLOBAL(cl_int, clRetainKernel, (cl_kernel kernel), (kernel));
CXXTEST_MOCK_GLOBAL(cl_int, clReleaseKernel, (cl_kernel kernel), (kernel));

CXXTEST_MOCK_GLOBAL(cl_int, clSetKernelArg,
  ( cl_kernel kernel, cl_uint arg_index, size_t arg_size, const void* arg_value),
  ( kernel, arg_index, arg_size, arg_value )
);

#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
CXXTEST_MOCK_GLOBAL(cl_int, clSetKernelArgSVMPointer,
  ( cl_kernel kernel, cl_uint arg_index, const void* arg_value),
  ( kernel, arg_index, arg_value )
);
#endif
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
CXXTEST_MOCK_GLOBAL(cl_int, clSetKernelExecInfo,
  ( cl_kernel kernel, cl_kernel_exec_info param_name, size_t param_value_size, const void* param_value),
  ( kernel, param_name, param_value_size, param_value )
);
#endif
CXXTEST_MOCK_GLOBAL(cl_int, clEnqueueNDRangeKernel,
  ( cl_command_queue command_queue, cl_kernel kernel, cl_uint work_dim,
    const size_t* global_work_offset, const size_t* global_work_size,
    const size_t* local_work_size, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event),
  ( command_queue, kernel, work_dim, global_work_offset, global_work_size,
    local_work_size, num_events_in_wait_list, event_wait_list, event)
);
CXXTEST_MOCK_GLOBAL(cl_int, clEnqueueNativeKernel,
  ( cl_command_queue command_queue, void (CL_CALLBACK* user_func)(void*),
    void* args, size_t cb_args, cl_uint num_mem_objects, const cl_mem* mem_list,
    const void** args_mem_loc, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event),
  ( command_queue, user_func, args, cb_args, num_mem_objects, mem_list,
    args_mem_loc, num_events_in_wait_list, event_wait_list, event )
);

#if CLXX_OPENCL_ALLOWED(clCreateUserEvent)
CXXTEST_MOCK_GLOBAL(cl_event, clCreateUserEvent,
  ( cl_context context, cl_int* errcode_ret ),
  ( context, errcode_ret )
);
#endif
#if CLXX_OPENCL_ALLOWED(clSetUserEventStatus)
CXXTEST_MOCK_GLOBAL(cl_int, clSetUserEventStatus,
  ( cl_event event, cl_int execution_status ),
  ( event, execution_status )
);
#endif
CXXTEST_MOCK_GLOBAL(cl_int, clWaitForEvents,
  ( cl_uint num_events, const cl_event *event_list),
  ( num_events, event_list )
);
CXXTEST_MOCK_GLOBAL(cl_int, clGetEventInfo,
  ( cl_event event, cl_event_info param_name, size_t param_value_size,
    void* param_value, size_t* param_value_size_ret),
  ( event, param_name, param_value_size, param_value, param_value_size_ret )
);
CXXTEST_MOCK_GLOBAL(cl_int, clSetEventCallback,
  ( cl_event event, cl_int command_exec_callback_type,
    void(CL_CALLBACK *pfn_event_notify)(cl_event, cl_int, void*),
    void* user_data ),
  ( event, command_exec_callback_type, pfn_event_notify, user_data )
);
CXXTEST_MOCK_GLOBAL(cl_int, clRetainEvent, (cl_event event), (event));
CXXTEST_MOCK_GLOBAL(cl_int, clReleaseEvent, (cl_event event), (event));
/** \endcond */

#include <clxx/cl/mocks/newton.hpp>
#include <clxx/cl/mocks/dummy.hpp>

#endif /* CLXX_CL_MOCK_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
