// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/mocks/cl.hpp

/** // doc: clxx/b5d/mocks/cl.hpp {{{
 * \file clxx/b5d/mocks/cl.hpp
 *
 * \brief CxxTest mocks for OpenCL functions from CL/cl.h.
 *
 * This file declares OpenCL mocks for CxxTest-based unit tests. Particular
 * implementations are provided by headers found in clxx/b5d/mocks/cl/ directory.
 */ // }}}
#ifndef CLXX_B5D_MOCKS_CL_HPP_INCLUDED
#define CLXX_B5D_MOCKS_CL_HPP_INCLUDED

#include <clxx/common/opencl.h>
#include <clxx/b5d/config.hpp>
#include <cxxtest/Mock.h>

/** \cond SHOW_IGNORED_COMPOUNDS */
#if CLXX_B5D_OPENCL_PROVIDES(clBuildProgram)
CXXTEST_MOCK_GLOBAL(cl_int,
  clBuildProgram,
  ( cl_program program, cl_uint num_devices, const cl_device_id* device_list,
    const char* options, void (CL_CALLBACK* pfn_notify)(cl_program, void*),
    void* user_data ),
  ( program, num_devices, device_list, options, pfn_notify, user_data )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCloneKernel)
CXXTEST_MOCK_GLOBAL(cl_kernel,
  clCloneKernel,
  (cl_kernel source_kernel, cl_int* errcode_ret),
  (source_kernel, errcode_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCompileProgram)
CXXTEST_MOCK_GLOBAL(cl_int,
  clCompileProgram,
  ( cl_program program, cl_uint num_devices, const cl_device_id* device_list,
    const char* options, cl_uint num_input_headers, const cl_program* input_headers,
    const char** header_include_names, void (CL_CALLBACK* pfn_notify)(cl_program, void*),
    void* user_data ),
  ( program, num_devices, device_list, options, num_input_headers,
    input_headers, header_include_names, pfn_notify, user_data )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateBuffer)
CXXTEST_MOCK_GLOBAL(cl_mem,
  clCreateBuffer,
  ( cl_context context, cl_mem_flags flags, size_t size, void* host_ptr,
    cl_int* errcode_ret ),
  ( context, flags, size, host_ptr, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateCommandQueue)
CXXTEST_MOCK_GLOBAL(cl_command_queue,
  clCreateCommandQueue,
  ( cl_context context, cl_device_id device,
    cl_command_queue_properties properties, cl_int* errcode_ret ),
  ( context, device, properties, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateCommandQueueWithProperties)
CXXTEST_MOCK_GLOBAL(cl_command_queue,
  clCreateCommandQueueWithProperties,
  ( cl_context context, cl_device_id device,
    const cl_queue_properties* properties, cl_int* errcode_ret ),
  ( context, device, properties, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateContext)
CXXTEST_MOCK_GLOBAL(cl_context,
  clCreateContext,
  ( const cl_context_properties *properties, cl_uint num_devices,
    const cl_device_id* devices,
    void (CL_CALLBACK *pfn_notify)( const char* errinfo, const void* private_info,
                        size_t cb, void *user_data ),
    void *user_data,
    cl_int* errcode_ret ),
  ( properties, num_devices, devices, pfn_notify, user_data, errcode_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateContextFromType)
CXXTEST_MOCK_GLOBAL(cl_context,
  clCreateContextFromType,
  ( const cl_context_properties *properties, const cl_device_type device_type,
    void (CL_CALLBACK *pfn_notify)( const char* errinfo, const void* private_info,
                        size_t cb, void *user_data ),
    void *user_data,
    cl_int* errcode_ret ),
  ( properties, device_type, pfn_notify, user_data, errcode_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateImage)
CXXTEST_MOCK_GLOBAL(cl_mem,
  clCreateImage,
  ( cl_context context, cl_mem_flags flags, const cl_image_format* image_format,
    const cl_image_desc* image_desc, void* host_ptr, cl_int* errcode_ret ),
  ( context, flags, image_format, image_desc, host_ptr, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateImage2D)
CXXTEST_MOCK_GLOBAL(cl_mem,
  clCreateImage2D,
  ( cl_context context, cl_mem_flags flags, const cl_image_format* image_format,
    size_t image_width, size_t image_height, size_t image_row_pitch,
    void* host_ptr, cl_int* errcode_ret ),
  ( context, flags, image_format, image_width, image_height, image_row_pitch,
    host_ptr, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateImage3D)
CXXTEST_MOCK_GLOBAL(cl_mem,
  clCreateImage3D,
  ( cl_context context, cl_mem_flags flags, const cl_image_format* image_format,
    size_t image_width, size_t image_height, size_t image_depth,
    size_t image_row_pitch, size_t image_slice_pitch, void* host_ptr,
    cl_int* errcode_ret ),
  ( context, flags, image_format, image_width, image_height, image_depth,
    image_row_pitch, image_slice_pitch, host_ptr, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateKernel)
CXXTEST_MOCK_GLOBAL(cl_kernel,
  clCreateKernel,
  ( cl_program program, const char* kernel_name, cl_int* errcode_ret),
  ( program, kernel_name, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateKernelsInProgram)
CXXTEST_MOCK_GLOBAL(cl_int,
  clCreateKernelsInProgram,
  ( cl_program program, cl_uint num_kernels, cl_kernel* kernels, cl_uint* num_kernels_ret),
  ( program, num_kernels, kernels, num_kernels_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreatePipe)
CXXTEST_MOCK_GLOBAL(cl_mem,
  clCreatePipe,
  ( cl_context context, cl_mem_flags flags, cl_uint pipe_packet_size,
    cl_uint pipe_max_packets, const cl_pipe_properties* properties,
    cl_int* errcode_ret),
  ( context, flags, pipe_packet_size, pipe_max_packets, properties, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateProgramWithBinary)
CXXTEST_MOCK_GLOBAL(cl_program,
  clCreateProgramWithBinary,
  ( cl_context context, cl_uint num_devices, const cl_device_id* device_list,
    const size_t* lengths, const unsigned char** binaries,
    cl_int* binary_status, cl_int* errcode_ret),
  ( context, num_devices, device_list, lengths, binaries, binary_status,
    errcode_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateProgramWithBuiltInKernels)
CXXTEST_MOCK_GLOBAL(cl_program,
  clCreateProgramWithBuiltInKernels,
  ( cl_context context, cl_uint num_devices, const cl_device_id* device_list,
    const char* kernel_names, cl_int* errcode_ret),
  ( context, num_devices, device_list, kernel_names, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateProgramWithIL)
CXXTEST_MOCK_GLOBAL(cl_program,
  clCreateProgramWithIL,
  ( cl_context context, const void* il, size_t length, cl_int* errcode_ret),
  ( context, il, length, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateProgramWithSource)
CXXTEST_MOCK_GLOBAL(cl_program,
  clCreateProgramWithSource,
  ( cl_context context, cl_uint count, const char** strings,
    const size_t* lengths, cl_int* errcode_ret),
  ( context, count, strings, lengths, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateSampler)
CXXTEST_MOCK_GLOBAL(cl_sampler,
  clCreateSampler,
  ( cl_context context, cl_bool normalized_coords,
    cl_addressing_mode addressing_mode, cl_filter_mode filter_mode,
    cl_int* errcode_ret ),
  ( context, normalized_coords, addressing_mode, filter_mode, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateSamplerWithProperties)
CXXTEST_MOCK_GLOBAL(cl_sampler,
  clCreateSamplerWithProperties,
  ( cl_context context, const cl_sampler_properties* sampler_properties,
    cl_int* errcode_ret ),
  ( context, sampler_properties, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateSubBuffer)
CXXTEST_MOCK_GLOBAL(cl_mem,
  clCreateSubBuffer,
  ( cl_mem buffer, cl_mem_flags flags, cl_buffer_create_type buffer_create_type,
    const void* buffer_create_info, cl_int* errcode_ret ),
  ( buffer, flags, buffer_create_type, buffer_create_info, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateSubDevices)
CXXTEST_MOCK_GLOBAL(cl_int,
  clCreateSubDevices,
  ( cl_device_id in_device, const cl_device_partition_property* properties,
    cl_uint num_devices, cl_device_id* out_devices, cl_uint* num_devices_ret),
  ( in_device, properties, num_devices, out_devices, num_devices_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clCreateUserEvent)
CXXTEST_MOCK_GLOBAL(cl_event,
  clCreateUserEvent,
  ( cl_context context, cl_int* errcode_ret ),
  ( context, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueBarrier)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueBarrier,
  ( cl_command_queue command_queue),
  ( command_queue )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueBarrierWithWaitList)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueBarrierWithWaitList,
  ( cl_command_queue command_queue, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event ),
  ( command_queue, num_events_in_wait_list, event_wait_list, event )
);
#endif


#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyBuffer)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueCopyBuffer,
  ( cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer,
    size_t src_offset, size_t dst_offset, size_t size,
    cl_uint num_events_in_wait_list, const cl_event* event_wait_list,
    cl_event* event ),
  ( command_queue, src_buffer, dst_buffer, src_offset, dst_offset, size,
    num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyBufferRect)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueCopyBufferRect,
  ( cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer,
    const size_t* src_origin, const size_t* dst_origin, const size_t* region,
    size_t src_row_pitch, size_t src_slice_pitch, size_t dst_row_pitch,
    size_t dst_slice_pitch, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event ),
  ( command_queue, src_buffer, dst_buffer, src_origin, dst_origin, region,
    src_row_pitch, src_slice_pitch, dst_row_pitch, dst_slice_pitch,
    num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyBufferToImage)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueCopyBufferToImage,
  ( cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_image,
    size_t src_offset, const size_t* dst_origin, const size_t* region,
    cl_uint num_events_in_wait_list, const cl_event* event_wait_list,
    cl_event* event ),
  ( command_queue, src_buffer, dst_image, src_offset, dst_origin, region,
    num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyImage)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueCopyImage,
  ( cl_command_queue command_queue, cl_mem src_image, cl_mem dst_image,
    const size_t* src_origin, const size_t* dst_origin, const size_t* region,
    cl_uint num_events_in_wait_list, const cl_event* event_wait_list,
    cl_event* event ),
  ( command_queue, src_image, dst_image, src_origin, dst_origin, region,
    num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyImageToBuffer)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueCopyImageToBuffer,
  ( cl_command_queue command_queue, cl_mem src_image, cl_mem dst_buffer,
    const size_t* src_origin, const size_t* region, size_t dst_offset,
    cl_uint num_events_in_wait_list, const cl_event* event_wait_list,
    cl_event* event ),
  ( command_queue, src_image, dst_buffer, src_origin, region, dst_offset,
    num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueFillBuffer)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueFillBuffer,
  ( cl_command_queue command_queue, cl_mem buffer, const void *pattern,
    size_t pattern_size, size_t offset, size_t size,
    cl_uint num_events_in_wait_list, const cl_event* event_wait_list,
    cl_event* event),
  ( command_queue, buffer, pattern, pattern_size, offset, size,
    num_events_in_wait_list, event_wait_list, event)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueFillImage)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueFillImage,
  ( cl_command_queue command_queue, cl_mem image, const void *fill_color,
    const size_t* origin, const size_t* region, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event),
  ( command_queue, image, fill_color, origin, region, num_events_in_wait_list,
    event_wait_list, event)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMapBuffer)
CXXTEST_MOCK_GLOBAL(void*,
  clEnqueueMapBuffer,
  ( cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_map,
    cl_map_flags map_flags, size_t offset, size_t size,
    cl_uint num_events_in_wait_list, const cl_event* event_wait_list,
    cl_event* event, cl_int* errcode_ret ),
  ( command_queue, buffer, blocking_map, map_flags, offset, size,
    num_events_in_wait_list, event_wait_list, event, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMapImage)
CXXTEST_MOCK_GLOBAL(void*,
  clEnqueueMapImage,
  ( cl_command_queue command_queue, cl_mem image, cl_bool blocking_map,
    cl_map_flags map_flags, const size_t* origin, const size_t* region,
    size_t* image_row_pitch, size_t* image_slice_pitch,
    cl_uint num_events_in_wait_list, const cl_event* event_wait_list,
    cl_event* event, cl_int* errcode_ret ),
  ( command_queue, image, blocking_map, map_flags, origin, region,
    image_row_pitch, image_slice_pitch, num_events_in_wait_list,
    event_wait_list, event, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMarker)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueMarker,
  ( cl_command_queue command_queue, cl_event* event ),
  ( command_queue, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMarkerWithWaitList)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueMarkerWithWaitList,
  ( cl_command_queue command_queue, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event ),
  ( command_queue, num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMigrateMemObjects)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueMigrateMemObjects,
  ( cl_command_queue command_queue, cl_uint num_mem_objects,
    const cl_mem* mem_objects, cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list, const cl_event* event_wait_list,
    cl_event* event ),
  ( command_queue, num_mem_objects, mem_objects, flags,
    num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueNativeKernel)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueNativeKernel,
  ( cl_command_queue command_queue, void (CL_CALLBACK* user_func)(void*),
    void* args, size_t cb_args, cl_uint num_mem_objects, const cl_mem* mem_list,
    const void** args_mem_loc, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event),
  ( command_queue, user_func, args, cb_args, num_mem_objects, mem_list,
    args_mem_loc, num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueNDRangeKernel)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueNDRangeKernel,
  ( cl_command_queue command_queue, cl_kernel kernel, cl_uint work_dim,
    const size_t* global_work_offset, const size_t* global_work_size,
    const size_t* local_work_size, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event),
  ( command_queue, kernel, work_dim, global_work_offset, global_work_size,
    local_work_size, num_events_in_wait_list, event_wait_list, event)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueReadBuffer)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueReadBuffer,
  ( cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read,
    size_t offset, size_t size, void* ptr, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event),
  ( command_queue, buffer, blocking_read, offset, size, ptr,
    num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueReadBufferRect)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueReadBufferRect,
  ( cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read,
    const size_t* buffer_origin, const size_t* host_origin, const size_t* region,
    size_t buffer_row_pitch, size_t buffer_splice_pitch, size_t host_row_pitch,
    size_t host_slice_pitch, void* ptr, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event),
  ( command_queue, buffer, blocking_read, buffer_origin, host_origin, region,
    buffer_row_pitch, buffer_splice_pitch, host_row_pitch, host_slice_pitch,
    ptr, num_events_in_wait_list, event_wait_list, event)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueReadImage)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueReadImage,
  ( cl_command_queue command_queue, cl_mem image, cl_bool blocking_read,
    const size_t* origin, const size_t* region, size_t row_pitch,
    size_t slice_pitch, void* ptr, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event ),
  ( command_queue, image, blocking_read, origin, region, row_pitch,
    slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMFree)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueSVMFree,
  ( cl_command_queue command_queue, cl_uint num_svm_pointers,
    void* svm_pointers[], void(CL_CALLBACK* pfn_free_func)(cl_command_queue,
                                                           cl_uint,
                                                           void*[],
                                                           void*),
    void* user_data, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event ),
  ( command_queue, num_svm_pointers, svm_pointers, pfn_free_func, user_data,
    num_events_in_wait_list, event_wait_list, event)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMMap)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueSVMMap,
  ( cl_command_queue command_queue, cl_bool blocking_map, cl_map_flags map_flags,
    void* svm_ptr, size_t size, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event ),
  ( command_queue, blocking_map, map_flags, svm_ptr, size,
    num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMMemFill)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueSVMMemFill,
  ( cl_command_queue command_queue, void* svm_ptr, const void* pattern,
    size_t pattern_size, size_t size, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event ),
  ( command_queue, svm_ptr, pattern, pattern_size, size,
    num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMMemcpy)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueSVMMemcpy,
  ( cl_command_queue command_queue, cl_bool blocking_copy, void* dst_ptr,
    const void* src_ptr, size_t size, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event ),
  ( command_queue, blocking_copy, dst_ptr, src_ptr, size,
    num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMMigrateMem)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueSVMMigrateMem,
  ( cl_command_queue command_queue, cl_uint num_svm_pointers,
    const void** svm_pointers, const size_t* sizes,
    cl_mem_migration_flags flags, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event ),
  ( command_queue, num_svm_pointers, svm_pointers, sizes, flags,
    num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMUnmap)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueSVMUnmap,
  ( cl_command_queue command_queue, void* svm_ptr,
    cl_uint num_events_in_wait_list, const cl_event* event_wait_list,
    cl_event* event ),
  ( command_queue, svm_ptr, num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueTask)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueTask,
  ( cl_command_queue command_queue, cl_kernel kernel,
    cl_uint num_events_in_wait_list, const cl_event* event_wait_list,
    cl_event* event ),
  ( command_queue, kernel, num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueUnmapMemObject)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueUnmapMemObject,
  ( cl_command_queue command_queue, cl_mem memobj, void* mapped_ptr,
    cl_uint num_events_in_wait_list, const cl_event* event_wait_list,
    cl_event* event ),
  ( command_queue, memobj, mapped_ptr, num_events_in_wait_list,
    event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueWaitForEvents)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueWaitForEvents,
  ( cl_command_queue command_queue, cl_uint num_events,
    const cl_event* event_list),
  ( command_queue, num_events, event_list )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueWriteBuffer)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueWriteBuffer,
  ( cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write,
    size_t offset, size_t size, const void* ptr, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event),
  ( command_queue, buffer, blocking_write, offset, size, ptr,
    num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueWriteBufferRect)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueWriteBufferRect,
  ( cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write,
    const size_t* buffer_origin, const size_t* host_origin, const size_t* region,
    size_t buffer_row_pitch, size_t buffer_splice_pitch, size_t host_row_pitch,
    size_t host_slice_pitch, const void* ptr, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event),
  ( command_queue, buffer, blocking_write, buffer_origin, host_origin, region,
    buffer_row_pitch, buffer_splice_pitch, host_row_pitch, host_slice_pitch,
    ptr, num_events_in_wait_list, event_wait_list, event)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueWriteImage)
CXXTEST_MOCK_GLOBAL(cl_int,
  clEnqueueWriteImage,
  ( cl_command_queue command_queue, cl_mem image, cl_bool blocking_write,
    const size_t* origin, const size_t* region, size_t input_row_pitch,
    size_t input_slice_pitch, const void* ptr, cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list, cl_event* event ),
  ( command_queue, image, blocking_write, origin, region, input_row_pitch,
    input_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clFinish)
CXXTEST_MOCK_GLOBAL(cl_int,
  clFinish,
  (cl_command_queue command_queue),
  (command_queue)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clFlush)
CXXTEST_MOCK_GLOBAL(cl_int,
  clFlush,
  (cl_command_queue command_queue),
  (command_queue)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetCommandQueueInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetCommandQueueInfo,
  ( cl_command_queue command_queue, cl_command_queue_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( command_queue, param_name, param_value_size, param_value, param_value_size_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetContextInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetContextInfo,
  ( cl_context context, cl_context_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( context, param_name, param_value_size, param_value, param_value_size_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetDeviceAndHostTimer)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetDeviceAndHostTimer,
  ( cl_device_id device, cl_ulong* device_timestamp, cl_ulong* host_timestamp ),
  ( device, device_timestamp, host_timestamp )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetDeviceIDs)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetDeviceIDs,
  (cl_platform_id platform, cl_device_type device_type, cl_uint num_entries,
   cl_device_id* devices, cl_uint *num_devices),
  (platform, device_type, num_entries, devices, num_devices)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetDeviceInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetDeviceInfo,
  ( cl_device_id device, cl_device_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( device, param_name, param_value_size, param_value, param_value_size_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetEventInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetEventInfo,
  ( cl_event event, cl_event_info param_name, size_t param_value_size,
    void* param_value, size_t* param_value_size_ret),
  ( event, param_name, param_value_size, param_value, param_value_size_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetEventProfilingInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetEventProfilingInfo,
  (cl_event event, cl_profiling_info param_name, size_t param_value_size,
   void* param_value, size_t* param_value_size_ret),
  (event, param_name, param_value_size, param_value, param_value_size_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetExtensionFunctionAddress)
CXXTEST_MOCK_GLOBAL(void*,
  clGetExtensionFunctionAddress,
  ( const char* funcname ),
  ( funcname )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetExtensionFunctionAddressForPlatform)
CXXTEST_MOCK_GLOBAL(void*,
  clGetExtensionFunctionAddressForPlatform,
  ( cl_platform_id platform, const char* funcname ),
  ( platform, funcname )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetHostTimer)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetHostTimer,
  ( cl_device_id device, cl_ulong* host_timestamp ),
  ( device, host_timestamp )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetImageInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetImageInfo,
  ( cl_mem image, cl_image_info param_name, size_t param_value_size,
    void* param_value, size_t* param_value_size_ret),
  ( image, param_name, param_value_size, param_value, param_value_size_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelArgInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetKernelArgInfo,
  ( cl_kernel kernel, cl_uint arg_index, cl_kernel_arg_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( kernel, arg_index, param_name, param_value_size, param_value, param_value_size_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetKernelInfo,
  ( cl_kernel kernel, cl_kernel_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( kernel, param_name, param_value_size, param_value, param_value_size_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelSubGroupInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetKernelSubGroupInfo,
  ( cl_kernel kernel, cl_device_id device, cl_kernel_sub_group_info param_name,
    size_t input_value_size, const void* input_value, size_t param_value_size,
    void* param_value, size_t* param_value_size_ret),
  ( kernel, device, param_name, input_value_size, input_value,
    param_value_size, param_value, param_value_size_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelWorkGroupInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetKernelWorkGroupInfo,
  ( cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( kernel, device, param_name, param_value_size, param_value, param_value_size_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetMemObjectInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetMemObjectInfo,
  ( cl_mem memobj, cl_mem_info param_name, size_t param_value_size,
    void* param_value, size_t* param_value_size_ret),
  ( memobj, param_name, param_value_size, param_value, param_value_size_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetPipeInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetPipeInfo,
  ( cl_mem pipe, cl_pipe_info param_name, size_t param_value_size,
    void* param_value, size_t* param_value_size_ret),
  ( pipe, param_name, param_value_size, param_value, param_value_size_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetPlatformIDs)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetPlatformIDs,
  (cl_uint num_entries, cl_platform_id* platforms, cl_uint *num_platforms),
  (num_entries, platforms, num_platforms)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetPlatformInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetPlatformInfo,
  ( cl_platform_id platform, cl_platform_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( platform, param_name, param_value_size, param_value, param_value_size_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetProgramBuildInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetProgramBuildInfo,
  ( cl_program program, cl_device_id device, cl_program_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( program, device, param_name, param_value_size, param_value, param_value_size_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetProgramInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetProgramInfo,
  ( cl_program program, cl_program_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( program, param_name, param_value_size, param_value, param_value_size_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetSamplerInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetSamplerInfo,
  ( cl_sampler sampler, cl_sampler_info param_name,
    size_t param_value_size, void* param_value, size_t* param_value_size_ret),
  ( sampler, param_name, param_value_size, param_value, param_value_size_ret)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clGetSupportedImageFormats)
CXXTEST_MOCK_GLOBAL(cl_int,
  clGetSupportedImageFormats,
  ( cl_context context, cl_mem_flags flags, cl_mem_object_type image_type,
    cl_uint num_entries, cl_image_format* image_formats,
    cl_uint* num_image_formats),
  ( context, flags, image_type, num_entries, image_formats, num_image_formats)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clLinkProgram)
CXXTEST_MOCK_GLOBAL(cl_program,
  clLinkProgram,
  ( cl_context context, cl_uint num_devices, const cl_device_id* device_list,
    const char* options, cl_uint num_input_programs, const cl_program* input_programs,
    void (CL_CALLBACK* pfn_notify)(cl_program, void*), void* user_data,
    cl_int* errcode_ret ),
  ( context, num_devices, device_list, options, num_input_programs,
    input_programs, pfn_notify, user_data, errcode_ret )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clReleaseCommandQueue)
CXXTEST_MOCK_GLOBAL(cl_int,
  clReleaseCommandQueue,
  (cl_command_queue command_queue), (command_queue)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clReleaseContext)
CXXTEST_MOCK_GLOBAL(cl_int,
  clReleaseContext,
  (cl_context context),
  (context)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
CXXTEST_MOCK_GLOBAL(cl_int,
  clReleaseDevice,
  (cl_device_id device),
  (device));
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clReleaseEvent)
CXXTEST_MOCK_GLOBAL(cl_int,
  clReleaseEvent,
  (cl_event event),
  (event)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clReleaseKernel)
CXXTEST_MOCK_GLOBAL(cl_int,
  clReleaseKernel,
  (cl_kernel kernel),
  (kernel)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clReleaseMemObject)
CXXTEST_MOCK_GLOBAL(cl_int,
  clReleaseMemObject,
  (cl_mem memobj),
  (memobj)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clReleaseProgram)
CXXTEST_MOCK_GLOBAL(cl_int,
  clReleaseProgram,
  (cl_program program),
  (program)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clReleaseSampler)
CXXTEST_MOCK_GLOBAL(cl_int,
  clReleaseSampler,
  (cl_sampler sampler),
  (sampler)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clRetainCommandQueue)
CXXTEST_MOCK_GLOBAL(cl_int,
  clRetainCommandQueue,
  (cl_command_queue command_queue), (command_queue)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clRetainContext)
CXXTEST_MOCK_GLOBAL(cl_int,
  clRetainContext,
  (cl_context context),
  (context)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
CXXTEST_MOCK_GLOBAL(cl_int,
  clRetainDevice,
  (cl_device_id device),
  (device));
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clRetainEvent)
CXXTEST_MOCK_GLOBAL(cl_int,
  clRetainEvent,
  (cl_event event),
  (event)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clRetainKernel)
CXXTEST_MOCK_GLOBAL(cl_int,
  clRetainKernel,
  (cl_kernel kernel),
  (kernel)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clRetainMemObject)
CXXTEST_MOCK_GLOBAL(cl_int,
  clRetainMemObject,
  (cl_mem memobj),
  (memobj)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clRetainProgram)
CXXTEST_MOCK_GLOBAL(cl_int,
  clRetainProgram,
  (cl_program program),
  (program)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clRetainSampler)
CXXTEST_MOCK_GLOBAL(cl_int,
  clRetainSampler,
  (cl_sampler sampler),
  (sampler)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clSetCommandQueueProperty)
CXXTEST_MOCK_GLOBAL(cl_int,
  clSetCommandQueueProperty,
  ( cl_command_queue command_queue, cl_command_queue_properties properties,
    cl_bool enable, cl_command_queue_properties* old_properties ),
  ( command_queue, properties, enable, old_properties)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clSetDefaultDeviceCommandQueue)
CXXTEST_MOCK_GLOBAL(cl_int,
  clSetDefaultDeviceCommandQueue,
  ( cl_context context, cl_device_id device, cl_command_queue command_queue ),
  ( context, device, command_queue )
);
#endif


#if CLXX_B5D_OPENCL_PROVIDES(clSetEventCallback)
CXXTEST_MOCK_GLOBAL(cl_int,
  clSetEventCallback,
  ( cl_event event, cl_int command_exec_callback_type,
    void(CL_CALLBACK *pfn_event_notify)(cl_event, cl_int, void*),
    void* user_data ),
  ( event, command_exec_callback_type, pfn_event_notify, user_data )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clSetKernelArg)
CXXTEST_MOCK_GLOBAL(cl_int,
  clSetKernelArg,
  ( cl_kernel kernel, cl_uint arg_index, size_t arg_size, const void* arg_value),
  ( kernel, arg_index, arg_size, arg_value )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clSetKernelArgSVMPointer)
CXXTEST_MOCK_GLOBAL(cl_int,
  clSetKernelArgSVMPointer,
  ( cl_kernel kernel, cl_uint arg_index, const void* arg_value),
  ( kernel, arg_index, arg_value )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clSetKernelExecInfo)
CXXTEST_MOCK_GLOBAL(cl_int,
  clSetKernelExecInfo,
  ( cl_kernel kernel, cl_kernel_exec_info param_name, size_t param_value_size, const void* param_value),
  ( kernel, param_name, param_value_size, param_value )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clSetMemObjectDestructorCallback)
CXXTEST_MOCK_GLOBAL(cl_int,
  clSetMemObjectDestructorCallback,
  (cl_mem memobj, void(CL_CALLBACK* pfn_notify)(cl_mem, void*), void* user_data),
  (memobj, pfn_notify, user_data)
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clSetUserEventStatus)
CXXTEST_MOCK_GLOBAL(cl_int,
  clSetUserEventStatus,
  ( cl_event event, cl_int execution_status ),
  ( event, execution_status )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clSVMAlloc)
CXXTEST_MOCK_GLOBAL(void*,
  clSVMAlloc,
  ( cl_context context, cl_svm_mem_flags flags, size_t size, cl_uint alignment ),
  ( context, flags, size, alignment )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clSVMFree)
CXXTEST_MOCK_VOID_GLOBAL(
  clSVMFree,
  ( cl_context context, void* svm_pointer ),
  ( context, svm_pointer )
);
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clUnloadCompiler)
CXXTEST_MOCK_GLOBAL(cl_int,
  clUnloadCompiler, (), ());
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clUnloadPlatformCompiler)
CXXTEST_MOCK_GLOBAL(cl_int,
  clUnloadPlatformCompiler, (cl_platform_id platform), (platform));
#endif

#if CLXX_B5D_OPENCL_PROVIDES(clWaitForEvents)
CXXTEST_MOCK_GLOBAL(cl_int,
  clWaitForEvents,
  ( cl_uint num_events, const cl_event *event_list),
  ( num_events, event_list )
);
#endif
/** \endcond */

#include <clxx/b5d/mocks/cl/dummy.hpp>

#endif /* CLXX_B5D_MOCKS_CL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
