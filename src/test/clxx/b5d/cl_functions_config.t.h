// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_functions_config.t.h

/** // doc: clxx/b5d/cl_functions_config.t.h {{{
 * \file clxx/b5d/cl_functions_config.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FUNCTIONS_CONFIG_T_H_INCLUDED
#define CLXX_B5D_CL_FUNCTIONS_CONFIG_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_functions_config.hpp>

namespace clxx { class cl_functions_config_test_suite; }

/** // doc: class clxx::cl_functions_config_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::cl_functions_config_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__cl_functions_config__common() {{{
   * \todo Write documentation
   */ // }}}
  void test__cl_functions_config__common( )
  {
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clBuildProgram, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_build_program, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateBuffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_buffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateCommandQueue, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_command_queue, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateContext, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_context, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateContextFromType, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_context_from_type, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateFromGLBuffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_from_gl_buffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateFromGLRenderbuffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_from_gl_renderbuffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateFromGLTexture2D, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_from_gl_texture_2d, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateFromGLTexture3D, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_from_gl_texture_3d, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateImage2D, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_image_2d, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateImage3D, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_image_3d, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateKernel, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_kernel, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateKernelsInProgram, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_kernels_in_program, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateProgramWithBinary, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_program_with_binary, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateProgramWithSource, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_program_with_source, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateSampler, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_sampler, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueAcquireGLObjects, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_acquire_gl_objects, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueBarrier, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_barrier, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueCopyBuffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_copy_buffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueCopyBufferToImage, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_copy_buffer_to_image, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueCopyImage, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_copy_image, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueCopyImageToBuffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_copy_image_to_buffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueMapBuffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_map_buffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueMapImage, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_map_image, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueMarker, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_marker, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueNativeKernel, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_native_kernel, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueNDRangeKernel, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_ndrange_kernel, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueReadBuffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_read_buffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueReadImage, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_read_image, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueReleaseGLObjects, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_release_gl_objects, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueTask, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_task, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueUnmapMemObject, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_unmap_mem_object, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueWaitForEvents, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_wait_for_events, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueWriteBuffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_write_buffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueWriteImage, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_write_image, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clFinish, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_finish, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clFlush, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_flush, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetCommandQueueInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_command_queue_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetContextInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_context_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetDeviceIDs, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_device_ids, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetDeviceInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_device_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetEventInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_event_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetEventProfilingInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_event_profiling_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetExtensionFunctionAddress, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_extension_function_address, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetGLContextInfoKHR, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_gl_context_info_khr, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetGLObjectInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_gl_object_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetGLTextureInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_gl_texture_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetImageInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_image_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetKernelInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_kernel_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetKernelWorkGroupInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_kernel_work_group_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetMemObjectInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_mem_object_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetPlatformIDs, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_platform_ids, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetPlatformInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_platform_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetProgramBuildInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_program_build_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetProgramInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_program_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetSamplerInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_sampler_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetSupportedImageFormats, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_supported_image_formats, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clReleaseCommandQueue, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_release_command_queue, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clReleaseContext, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_release_context, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clReleaseEvent, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_release_event, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clReleaseKernel, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_release_kernel, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clReleaseMemObject, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_release_mem_object, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clReleaseProgram, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_release_program, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clReleaseSampler, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_release_sampler, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clRetainCommandQueue, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_retain_command_queue, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clRetainContext, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_retain_context, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clRetainEvent, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_retain_event, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clRetainKernel, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_retain_kernel, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clRetainMemObject, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_retain_mem_object, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clRetainProgram, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_retain_program, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clRetainSampler, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_retain_sampler, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clSetKernelArg, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_set_kernel_arg, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clUnloadCompiler, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_unload_compiler, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clWaitForEvents, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_wait_for_events, 1);
  }

  /** // doc: test__cl_functions_config__version_1_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__cl_functions_config__version_1_1( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1 /* OpenCL >= 1.1 */
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateSubBuffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_sub_buffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateUserEvent, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_user_event, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueCopyBufferRect, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_copy_buffer_rect, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueReadBufferRect, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_read_buffer_rect, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueWriteBufferRect, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_write_buffer_rect, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clSetEventCallback, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_set_event_callback, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clSetMemObjectDestructorCallback, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_set_mem_object_destructor_callback, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clSetUserEventStatus, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_set_user_event_status, 1);
#else /* OpenCL < 1.1 */
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clSetCommandQueueProperty, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_set_command_queue_property, 1);
#endif /* CLXX_B5D_OPENCL_CL_H_VERSION_1_1 */
  }

  /** // doc: test__cl_functions_config__version_1_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__cl_functions_config__version_1_2( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2 /* OpenCL >= 1.2 */
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCompileProgram, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_compile_program, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateFromGLTexture, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_from_gl_texture, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateImage, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_image, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateProgramWithBuiltInKernels, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_program_with_built_in_kernels, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateSubDevices, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_sub_devices, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueBarrierWithWaitList, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_barrier_with_wait_list, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueFillBuffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_fill_buffer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueFillImage, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_fill_image, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueMarkerWithWaitList, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_marker_with_wait_list, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueMigrateMemObjects, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_migrate_mem_objects, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetExtensionFunctionAddressForPlatform, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_extension_function_address_for_platform, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetKernelArgInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_kernel_arg_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clLinkProgram, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_link_program, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clReleaseDevice, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_release_device, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clRetainDevice, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_retain_device, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clUnloadPlatformCompiler, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_unload_platform_compiler, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DEPRECATES_clCreateFromGLTexture2D, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_DEPRECATES_create_from_gl_texture_2d, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DEPRECATES_clCreateFromGLTexture3D, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_DEPRECATES_create_from_gl_texture_3d, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DEPRECATES_clCreateImage2D, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_DEPRECATES_create_image_2d, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DEPRECATES_clCreateImage3D, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_DEPRECATES_create_image_3d, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DEPRECATES_clEnqueueBarrier, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_DEPRECATES_enqueue_barrier, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DEPRECATES_clEnqueueMarker, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_DEPRECATES_enqueue_marker, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DEPRECATES_clEnqueueWaitForEvents, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_DEPRECATES_enqueue_wait_for_events, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DEPRECATES_clGetExtensionFunctionAddress, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_DEPRECATES_get_extension_function_address, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DEPRECATES_clUnloadCompiler, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_DEPRECATES_unload_compiler, 1);
#else /* OpenCL < 1.2 */
#endif /* CLXX_B5D_OPENCL_CL_H_VERSION_1_2 */
  }

  /** // doc: test__cl_functions_config__version_2_0() {{{
   * \todo Write documentation
   */ // }}}
  void test__cl_functions_config__version_2_0( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_2_0 /* OpenCL >= 2.0 */
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateCommandQueueWithProperties, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_command_queue_with_properties, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreatePipe, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_pipe, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateSamplerWithProperties, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_sampler_with_properties, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueSVMFree, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_svm_free, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueSVMMap, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_svm_map, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueSVMMemcpy, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_svm_memcpy, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueSVMMemFill, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_svm_mem_fill, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueSVMUnmap, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_svm_unmap, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetPipeInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_pipe_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clSetKernelArgSVMPointer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_set_kernel_arg_svm_pointer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clSetKernelExecInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_set_kernel_exec_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clSVMAlloc, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_svm_alloc, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clSVMFree, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_svm_free, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DEPRECATES_clCreateCommandQueue, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_DEPRECATES_create_command_queue, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DEPRECATES_clCreateSampler, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_DEPRECATES_create_sampler, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DEPRECATES_clEnqueueTask, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_DEPRECATES_enqueue_task, 1);
#else /* OpenCL < 2.0 */
#endif /* CLXX_B5D_OPENCL_CL_H_VERSION_2_0 */
  }

  /** // doc: test__cl_functions_config__version_2_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__cl_functions_config__version_2_1( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_2_1 /* OpenCL >= 2.1 */
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCloneKernel, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_clone_kernel, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clCreateProgramWithIL, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_create_program_with_il, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clEnqueueSVMMigrateMem, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_enqueue_svm_migrate_mem, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetDeviceAndHostTimer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_device_and_host_timer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetHostTimer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_host_timer, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clGetKernelSubGroupInfo, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_get_kernel_sub_group_info, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clSetDefaultDeviceCommandQueue, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_set_default_device_command_queue, 1);
#else /* OpenCL < 2.1 */
#endif /* CLXX_B5D_OPENCL_CL_H_VERSION_2_1 */
  }

  /** // doc: test__cl_functions_config__version_2_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__cl_functions_config__version_2_2( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_2_2 /* OpenCL >= 2.2 */
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clSetProgramReleaseCallback, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_set_program_release_callback, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_OPENCL_DECLARES_clSetProgramSpecializationConstant, 1);
    TS_ASSERT_EQUALS(CLXX_B5D_PROVIDES_set_program_specialization_constant, 1);
#else /* OpenCL < 2.2 */
#endif /* CLXX_B5D_OPENCL_CL_H_VERSION_2_2 */
  }

};

#endif /* CLXX_B5D_CL_FUNCTIONS_CONFIG_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
