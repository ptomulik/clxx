// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/b5d/functions.cpp {{{
 * \file clxx/b5d/functions.cpp
 * \brief Implements thin wrappers for OpenCL functions
 */ // }}}
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

namespace clxx {
static void _throw_clerror_no(status_t s)
{
  switch(s)
    {
      case status_t::device_not_found:
        throw clerror_no<status_t::device_not_found>();
      case status_t::device_not_available:
        throw clerror_no<status_t::device_not_available>();
      case status_t::compiler_not_available:
        throw clerror_no<status_t::compiler_not_available>();
      case status_t::mem_object_allocation_failure:
        throw clerror_no<status_t::mem_object_allocation_failure>();
      case status_t::out_of_resources:
        throw clerror_no<status_t::out_of_resources>();
      case status_t::out_of_host_memory:
        throw clerror_no<status_t::out_of_host_memory>();
      case status_t::profiling_info_not_available:
        throw clerror_no<status_t::profiling_info_not_available>();
      case status_t::mem_copy_overlap:
        throw clerror_no<status_t::mem_copy_overlap>();
      case status_t::image_format_mismatch:
        throw clerror_no<status_t::image_format_mismatch>();
      case status_t::image_format_not_supported:
        throw clerror_no<status_t::image_format_not_supported>();
      case status_t::build_program_failure:
        throw clerror_no<status_t::build_program_failure>();
      case status_t::map_failure:
        throw clerror_no<status_t::map_failure>();
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
      case status_t::misaligned_sub_buffer_offset:
        throw clerror_no<status_t::misaligned_sub_buffer_offset>();
      case status_t::exec_status_error_for_events_in_wait_list:
        throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>();
#endif
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
      case status_t::compile_program_failure:
        throw clerror_no<status_t::compile_program_failure>();
      case status_t::linker_not_available:
        throw clerror_no<status_t::linker_not_available>();
      case status_t::link_program_failure:
        throw clerror_no<status_t::link_program_failure>();
      case status_t::device_partition_failed:
        throw clerror_no<status_t::device_partition_failed>();
      case status_t::kernel_arg_info_not_available:
        throw clerror_no<status_t::kernel_arg_info_not_available>();
#endif
      case status_t::invalid_value:
        throw clerror_no<status_t::invalid_value>();
      case status_t::invalid_device_type:
        throw clerror_no<status_t::invalid_device_type>();
      case status_t::invalid_platform:
        throw clerror_no<status_t::invalid_platform>();
      case status_t::invalid_device:
        throw clerror_no<status_t::invalid_device>();
      case status_t::invalid_context:
        throw clerror_no<status_t::invalid_context>();
      case status_t::invalid_queue_properties:
        throw clerror_no<status_t::invalid_queue_properties>();
      case status_t::invalid_command_queue:
        throw clerror_no<status_t::invalid_command_queue>();
      case status_t::invalid_host_ptr:
        throw clerror_no<status_t::invalid_host_ptr>();
      case status_t::invalid_mem_object:
        throw clerror_no<status_t::invalid_mem_object>();
      case status_t::invalid_image_format_descriptor:
        throw clerror_no<status_t::invalid_image_format_descriptor>();
      case status_t::invalid_image_size:
        throw clerror_no<status_t::invalid_image_size>();
      case status_t::invalid_sampler:
        throw clerror_no<status_t::invalid_sampler>();
      case status_t::invalid_binary:
        throw clerror_no<status_t::invalid_binary>();
      case status_t::invalid_build_options:
        throw clerror_no<status_t::invalid_build_options>();
      case status_t::invalid_program:
        throw clerror_no<status_t::invalid_program>();
      case status_t::invalid_program_executable:
        throw clerror_no<status_t::invalid_program_executable>();
      case status_t::invalid_kernel_name:
        throw clerror_no<status_t::invalid_kernel_name>();
      case status_t::invalid_kernel_definition:
        throw clerror_no<status_t::invalid_kernel_definition>();
      case status_t::invalid_kernel:
        throw clerror_no<status_t::invalid_kernel>();
      case status_t::invalid_arg_index:
        throw clerror_no<status_t::invalid_arg_index>();
      case status_t::invalid_arg_value:
        throw clerror_no<status_t::invalid_arg_value>();
      case status_t::invalid_arg_size:
        throw clerror_no<status_t::invalid_arg_size>();
      case status_t::invalid_kernel_args:
        throw clerror_no<status_t::invalid_kernel_args>();
      case status_t::invalid_work_dimension:
        throw clerror_no<status_t::invalid_work_dimension>();
      case status_t::invalid_work_group_size:
        throw clerror_no<status_t::invalid_work_group_size>();
      case status_t::invalid_work_item_size:
        throw clerror_no<status_t::invalid_work_item_size>();
      case status_t::invalid_global_offset:
        throw clerror_no<status_t::invalid_global_offset>();
      case status_t::invalid_event_wait_list:
        throw clerror_no<status_t::invalid_event_wait_list>();
      case status_t::invalid_event:
        throw clerror_no<status_t::invalid_event>();
      case status_t::invalid_operation:
        throw clerror_no<status_t::invalid_operation>();
      case status_t::invalid_gl_object:
        throw clerror_no<status_t::invalid_gl_object>();
      case status_t::invalid_buffer_size:
        throw clerror_no<status_t::invalid_buffer_size>();
      case status_t::invalid_mip_level:
        throw clerror_no<status_t::invalid_mip_level>();
      case status_t::invalid_global_work_size:
        throw clerror_no<status_t::invalid_global_work_size>();
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
      case status_t::invalid_property:
        throw clerror_no<status_t::invalid_property>();
#endif
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
      case status_t::invalid_image_descriptor:
        throw clerror_no<status_t::invalid_image_descriptor>();
      case status_t::invalid_compiler_options:
        throw clerror_no<status_t::invalid_compiler_options>();
      case status_t::invalid_linker_options:
        throw clerror_no<status_t::invalid_linker_options>();
      case status_t::invalid_device_partition_count:
        throw clerror_no<status_t::invalid_device_partition_count>();
#endif
#if CLXX_B5D_OPENCL_CL_H_VERSION_2_0
      case status_t::invalid_pipe_size:
        throw clerror_no<status_t::invalid_pipe_size>();
      case status_t::invalid_device_queue:
        throw clerror_no<status_t::invalid_device_queue>();
#endif
    //
    // codes defined by OpenCL extensions
    //
#if cl_khr_icd
      case status_t::platform_not_found_khr:
        throw clerror_no<status_t::platform_not_found_khr>();
#endif
#if cl_ext_device_fission
      case status_t::device_partition_failed_ext:
        throw clerror_no<status_t::device_partition_failed_ext>();
      case status_t::invalid_partition_count_ext:
        throw clerror_no<status_t::invalid_partition_count_ext>();
      case status_t::invalid_partition_name_ext:
        throw clerror_no<status_t::invalid_partition_name_ext>();
#endif
#if cl_khr_gl_sharing
      case status_t::invalid_gl_sharegroup_reference_khr:
        throw clerror_no<status_t::invalid_gl_sharegroup_reference_khr>();
#endif
#if cl_khr_dx9_media_sharing
      case status_t::invalid_dx9_media_adapter_khr:
        throw clerror_no<status_t::invalid_dx9_media_adapter_khr>();
      case status_t::invalid_dx9_media_surface_khr:
        throw clerror_no<status_t::invalid_dx9_media_surface_khr>();
      case status_t::dx9_media_surface_already_acquired_khr:
        throw clerror_no<status_t::dx9_media_surface_already_acquired_khr>();
      case status_t::dx9_media_surface_not_acquired_khr:
        throw clerror_no<status_t::dx9_media_surface_not_acquired_khr>();
#endif
#if cl_khr_d3d10_sharing
      case status_t::invalid_d3d10_device_khr:
        throw clerror_no<status_t::invalid_d3d10_device_khr>();
      case status_t::invalid_d3d10_resource_khr:
        throw clerror_no<status_t::invalid_d3d10_resource_khr>();
      case status_t::d3d10_resource_already_acquired_khr:
        throw clerror_no<status_t::d3d10_resource_already_acquired_khr>();
      case status_t::d3d10_resource_not_acquired_khr:
        throw clerror_no<status_t::d3d10_resource_not_acquired_khr>();
#endif
#if cl_khr_d3d11_sharing
      case status_t::invalid_d3d11_device_khr:
        throw clerror_no<status_t::invalid_d3d11_device_khr>();
      case status_t::invalid_d3d11_resource_khr:
        throw clerror_no<status_t::invalid_d3d11_resource_khr>();
      case status_t::d3d11_resource_already_acquired_khr:
        throw clerror_no<status_t::d3d11_resource_already_acquired_khr>();
      case status_t::d3d11_resource_not_acquired_khr:
        throw clerror_no<status_t::d3d11_resource_not_acquired_khr>();
#endif
      default:
        throw unexpected_clerror(s);
    }
}
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(build_program)
void
build_program(cl_program program,
              cl_uint num_devices,
              const cl_device_id* device_list,
              const char* options,
              void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
              void* user_data)
{
  status_t s = static_cast<status_t>(
    T::clBuildProgram(
      program,
      num_devices,
      device_list,
      options,
      pfn_notify,
      user_data
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(clone_kernel)
cl_kernel
clone_kernel(cl_kernel source_kernel)
{
  cl_int s = CL_SUCCESS;
  cl_kernel kern;
  kern = T::clCloneKernel(source_kernel, &s);
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return kern;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(compile_program)
void
compile_program(cl_program program,
                cl_uint num_devices,
                const cl_device_id* device_list,
                const char* options,
                cl_uint num_input_headers,
                const cl_program* input_headers,
                const char** header_include_names,
                void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
                void* user_data)
{
  status_t s = static_cast<status_t>(
    T::clCompileProgram(
      program,
      num_devices,
      device_list,
      options,
      num_input_headers,
      input_headers,
      header_include_names,
      pfn_notify,
      user_data
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_buffer)
cl_mem
create_buffer(cl_context context,
              mem_flags_t flags,
              size_t size,
              void* host_ptr)
{
  cl_int s = CL_SUCCESS;
  cl_mem m = T::clCreateBuffer(
      context,
      static_cast<cl_mem_flags>(flags),
      size,
      host_ptr,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return m;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_command_queue)
cl_command_queue
create_command_queue(cl_context context,
                     cl_device_id device,
                     command_queue_properties_t properties)
{
  cl_int s = CL_SUCCESS;
  cl_command_queue queue;
  queue = T::clCreateCommandQueue(context, device, static_cast<cl_command_queue_properties>(properties), &s);
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }

  return queue;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_command_queue_with_properties)
cl_command_queue
create_command_queue_with_properties(cl_context context,
                                     cl_device_id device,
                                     const cl_queue_properties* properties)
{
  cl_int s = CL_SUCCESS;
  cl_command_queue queue;
  queue = T::clCreateCommandQueueWithProperties(context, device, properties, &s);
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }

  return queue;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_context)
cl_context
create_context(const cl_context_properties* properties,
               cl_uint num_devices,
               const cl_device_id* devices,
               void(CL_CALLBACK *pfn_notify)(const char* errinfo,
                                 const void* private_info,
                                 size_t cb,
                                 void* user_data),
               void* user_data)
{
  cl_int s = CL_SUCCESS;
  cl_context ctx;
  ctx = T::clCreateContext(properties, num_devices, devices, pfn_notify, user_data, &s);
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }

  return ctx;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_context_from_type)
cl_context
create_context_from_type(const cl_context_properties* properties,
                         device_type_t device_type,
                         void(CL_CALLBACK *pfn_notify)(const char* errinfo,
                                           const void* private_info,
                                           size_t cb,
                                           void* user_data),
                         void* user_data)
{
  cl_int s = CL_SUCCESS;
  cl_context ctx;
  ctx = T::clCreateContextFromType(
      properties,
      static_cast<cl_device_type>(device_type),
      pfn_notify,
      user_data,
      &s);

  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }

  return ctx;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_image)
cl_mem
create_image(cl_context context,
             mem_flags_t flags,
             const cl_image_format *image_format,
             const cl_image_desc *image_desc,
             void *host_ptr)
{
  cl_int s = CL_SUCCESS;
  cl_mem result = T::clCreateImage(
      context,
      static_cast<cl_mem_flags>(flags),
      image_format,
      image_desc,
      host_ptr,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return result;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_image_2d)
cl_mem
create_image_2d(cl_context context,
                mem_flags_t flags,
                const cl_image_format *image_format,
                size_t image_width, size_t image_height,
                size_t image_row_pitch, void *host_ptr)
{
  cl_int s = CL_SUCCESS;
  cl_mem result = T::clCreateImage2D(
      context,
      static_cast<cl_mem_flags>(flags),
      image_format,
      image_width,
      image_height,
      image_row_pitch,
      host_ptr,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return result;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_image_3d)
cl_mem
create_image_3d(cl_context context,
                mem_flags_t flags,
                const cl_image_format *image_format,
                size_t image_width, size_t image_height,
                size_t image_depth, size_t image_row_pitch,
                size_t image_slice_pitch, void *host_ptr)
{
  cl_int s = CL_SUCCESS;
  cl_mem result = T::clCreateImage3D(
      context,
      static_cast<cl_mem_flags>(flags),
      image_format,
      image_width,
      image_height,
      image_depth,
      image_row_pitch,
      image_slice_pitch,
      host_ptr,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return result;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_kernel)
cl_kernel
create_kernel(cl_program program,
              const char* kernel_name)
{
  cl_int s = CL_SUCCESS;
  cl_kernel kern;
  kern = T::clCreateKernel(program, kernel_name, &s);
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return kern;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_kernels_in_program)
void
create_kernels_in_program(cl_program program,
                          cl_uint num_kernels,
                          cl_kernel* kernels,
                          cl_uint* num_kernels_ret)
{
  status_t s = static_cast<status_t>(
      T::clCreateKernelsInProgram(
        program,
        num_kernels,
        kernels,
        num_kernels_ret
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_pipe)
cl_mem
create_pipe(cl_context context,
            mem_flags_t flags,
            cl_uint pipe_packet_size,
            cl_uint pipe_max_packets,
            const cl_pipe_properties* properties)
{
  cl_int s = CL_SUCCESS;
  cl_mem result = T::clCreatePipe(
      context,
      static_cast<cl_mem_flags>(flags),
      pipe_packet_size,
      pipe_max_packets,
      properties,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return result;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_program_with_binary)
cl_program
create_program_with_binary(cl_context context,
                           cl_uint num_devices,
                           const cl_device_id* device_list,
                           const size_t* lengths,
                           const unsigned char** binaries,
                           cl_int* binary_status)
{
  cl_int s = CL_SUCCESS;
  cl_program p = T::clCreateProgramWithBinary(
      context,
      num_devices,
      device_list,
      lengths,
      binaries,
      binary_status,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return p;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_program_with_built_in_kernels)
cl_program
create_program_with_built_in_kernels(cl_context context,
                                     cl_uint num_devices,
                                     const cl_device_id* device_list,
                                     const char* kernel_names)
{
  cl_int s = CL_SUCCESS;
  cl_program p = T::clCreateProgramWithBuiltInKernels(
      context,
      num_devices,
      device_list,
      kernel_names,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return p;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_program_with_il)
cl_program
create_program_with_il(cl_context context,
                       const void* il,
                       size_t length)
{
  cl_int s = CL_SUCCESS;
  cl_program p = T::clCreateProgramWithIL(
      context,
      il,
      length,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return p;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_program_with_source)
cl_program
create_program_with_source(cl_context context,
                           cl_uint count,
                           const char** strings,
                           const size_t* lengths)
{
  cl_int s = CL_SUCCESS;
  cl_program p;
  p = T::clCreateProgramWithSource(context, count, strings, lengths, &s);
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return p;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_sampler)
cl_sampler
create_sampler(cl_context context,
               cl_bool normalized_coords,
               addressing_mode_t addressing_mode,
               filter_mode_t filter_mode)
{
  cl_int s = CL_SUCCESS;
  cl_sampler m = T::clCreateSampler(
      context,
      normalized_coords,
      static_cast<cl_addressing_mode>(addressing_mode),
      static_cast<cl_filter_mode>(filter_mode),
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return m;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_sampler_with_properties)
cl_sampler
create_sampler_with_properties(cl_context context,
                               const cl_sampler_properties* sampler_properties)
{
  cl_int s = CL_SUCCESS;
  cl_sampler m = T::clCreateSamplerWithProperties(
      context,
      sampler_properties,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return m;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_sub_buffer)
cl_mem
create_sub_buffer(cl_mem buffer, mem_flags_t flags,
                  buffer_create_type_t buffer_create_type,
                  const void* buffer_create_info)
{
  cl_int s = CL_SUCCESS;
  cl_mem m = T::clCreateSubBuffer(
      buffer,
      static_cast<cl_mem_flags>(flags),
      static_cast<cl_buffer_create_type>(buffer_create_type),
      buffer_create_info,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return m;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_sub_devices)
void
create_sub_devices(cl_device_id in_device,
                   const cl_device_partition_property* properties,
                   cl_uint num_devices,
                   cl_device_id* out_devices,
                   cl_uint *num_devices_ret)
{
  status_t s = static_cast<status_t>(
      T::clCreateSubDevices(
        in_device,
        properties,
        num_devices,
        out_devices,
        num_devices_ret
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(create_user_event)
cl_event
create_user_event(cl_context context)
{
  cl_int s = CL_SUCCESS;
  cl_event event = T::clCreateUserEvent(context, &s);
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return event;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_barrier)
void
enqueue_barrier(cl_command_queue command_queue)
{
  status_t s = static_cast<status_t>(T::clEnqueueBarrier(command_queue));
  if(is_error(s))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_barrier_with_wait_list)
void
enqueue_barrier_with_wait_list(cl_command_queue command_queue,
                               cl_uint num_events_in_wait_list,
                               const cl_event* event_wait_list,
                               cl_event* event)
{
  status_t s = static_cast<status_t>(
      T::clEnqueueBarrierWithWaitList(command_queue,
                                      num_events_in_wait_list,
                                      event_wait_list,
                                      event)
  );
  if(is_error(s))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_copy_buffer)
void
enqueue_copy_buffer( cl_command_queue command_queue, cl_mem src_buffer,
                     cl_mem dst_buffer, size_t src_offset, size_t dst_offset,
                     size_t size, cl_uint num_events_in_wait_list,
                     const cl_event* event_wait_list, cl_event* event )
{
  status_t s = static_cast<status_t>(
      T::clEnqueueCopyBuffer(
        command_queue,
        src_buffer,
        dst_buffer,
        src_offset,
        dst_offset,
        size,
        num_events_in_wait_list,
        event_wait_list,
        event
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_copy_buffer_rect)
void
enqueue_copy_buffer_rect(cl_command_queue command_queue,
                    cl_mem src_buffer,
                    cl_mem dst_buffer,
                    const size_t* src_origin,
                    const size_t* dst_origin,
                    const size_t* region,
                    size_t src_row_pitch,
                    size_t src_slice_pitch,
                    size_t dst_row_pitch,
                    size_t dst_slice_pitch,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event)
{
  status_t s = static_cast<status_t>(
      T::clEnqueueCopyBufferRect(
        command_queue,
        src_buffer,
        dst_buffer,
        src_origin,
        dst_origin,
        region,
        src_row_pitch,
        src_slice_pitch,
        dst_row_pitch,
        dst_slice_pitch,
        num_events_in_wait_list,
        event_wait_list,
        event
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_copy_buffer_to_image)
void
enqueue_copy_buffer_to_image(cl_command_queue command_queue,
                             cl_mem src_image,
                             cl_mem dst_buffer,
                             size_t src_offset,
                             const size_t* src_origin,
                             const size_t* region,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueCopyBufferToImage(
      command_queue,
      src_image,
      dst_buffer,
      src_offset,
      src_origin,
      region,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_copy_image)
void
enqueue_copy_image(cl_command_queue command_queue,
                   cl_mem src_image,
                   cl_mem dst_image,
                   const size_t* src_origin,
                   const size_t* dst_origin,
                   const size_t* region,
                   cl_uint num_events_in_wait_list,
                   const cl_event* event_wait_list,
                   cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueCopyImage(
      command_queue,
      src_image,
      dst_image,
      src_origin,
      dst_origin,
      region,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_copy_image_to_buffer)
void
enqueue_copy_image_to_buffer(cl_command_queue command_queue,
                             cl_mem src_image,
                             cl_mem dst_buffer,
                             const size_t* src_origin,
                             const size_t* region,
                             size_t dst_offset,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueCopyImageToBuffer(
      command_queue,
      src_image,
      dst_buffer,
      src_origin,
      region,
      dst_offset,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_fill_buffer)
void
enqueue_fill_buffer(cl_command_queue command_queue,
                    cl_mem buffer,
                    const void* pattern,
                    size_t pattern_size,
                    size_t offset,
                    size_t size,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueFillBuffer(
      command_queue,
      buffer,
      pattern,
      pattern_size,
      offset,
      size,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
void
enqueue_fill_image(cl_command_queue command_queue,
                    cl_mem image,
                    const void* fill_color,
                    const size_t* origin,
                    const size_t* region,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueFillImage(
      command_queue,
      image,
      fill_color,
      origin,
      region,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_map_buffer)
void*
enqueue_map_buffer( cl_command_queue command_queue, cl_mem buffer,
                    cl_bool blocking_map, map_flags_t map_flags,
                    size_t offset, size_t size, cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list, cl_event* event)
{
  cl_int s = CL_SUCCESS;
  void* result = T::clEnqueueMapBuffer(
      command_queue,
      buffer,
      blocking_map,
      static_cast<cl_map_flags>(map_flags),
      offset,
      size,
      num_events_in_wait_list,
      event_wait_list,
      event,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return result;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_map_image)
void*
enqueue_map_image(cl_command_queue command_queue,
                  cl_mem image,
                  cl_bool blocking_map,
                  map_flags_t map_flags,
                  const size_t* origin,
                  const size_t* region,
                  size_t* image_row_pitch,
                  size_t* image_slice_pitch,
                  cl_uint num_events_in_wait_list,
                  const cl_event* event_wait_list,
                  cl_event* event)
{
  cl_int s = CL_SUCCESS;
  void* result = T::clEnqueueMapImage(
      command_queue,
      image,
      blocking_map,
      static_cast<cl_map_flags>(map_flags),
      origin,
      region,
      image_row_pitch,
      image_slice_pitch,
      num_events_in_wait_list,
      event_wait_list,
      event,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return result;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_marker)
void
enqueue_marker(cl_command_queue command_queue,
               cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueMarker(
      command_queue,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_marker_with_wait_list)
void
enqueue_marker_with_wait_list(cl_command_queue command_queue,
                              cl_uint num_events_in_wait_list,
                              const cl_event* event_wait_list,
                              cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueMarkerWithWaitList(
      command_queue,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_migrate_mem_objects)
void
enqueue_migrate_mem_objects(cl_command_queue command_queue,
                            cl_uint num_mem_objects,
                            const cl_mem* mem_objects,
                            mem_migration_flags_t flags,
                            cl_uint num_events_in_wait_list,
                            const cl_event* event_wait_list,
                            cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueMigrateMemObjects(
      command_queue,
      num_mem_objects,
      mem_objects,
      static_cast<cl_mem_migration_flags>(flags),
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_native_kernel)
void
enqueue_native_kernel( cl_command_queue command_queue,
                       void (CL_CALLBACK* user_func)(void*),
                       void* args,
                       size_t cb_args,
                       cl_uint num_mem_objects,
                       const cl_mem* mem_list,
                       const void** args_mem_loc,
                       cl_uint num_events_in_wait_list,
                       const cl_event* event_wait_list,
                       cl_event* event)
{
  status_t s = static_cast<status_t>(
      T::clEnqueueNativeKernel(
        command_queue,
        user_func,
        args,
        cb_args,
        num_mem_objects,
        mem_list,
        args_mem_loc,
        num_events_in_wait_list,
        event_wait_list, event
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
void
enqueue_ndrange_kernel( cl_command_queue command_queue,
                         cl_kernel kernel,
                         cl_uint work_dim,
                         const size_t* global_work_offset,
                         const size_t* global_work_size,
                         const size_t* local_work_size,
                         cl_uint num_events_in_wait_list,
                         const cl_event* event_wait_list,
                         cl_event* event)
{
  status_t s = static_cast<status_t>(
      T::clEnqueueNDRangeKernel(
        command_queue,
        kernel,
        work_dim,
        global_work_offset,
        global_work_size,
        local_work_size,
        num_events_in_wait_list,
        event_wait_list,
        event
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_read_buffer)
void
enqueue_read_buffer( cl_command_queue command_queue, cl_mem buffer,
                     cl_bool blocking_read, size_t offset, size_t size,
                     void* ptr, cl_uint num_events_in_wait_list,
                     const cl_event* event_wait_list, cl_event* event )
{
  status_t s = static_cast<status_t>(
      T::clEnqueueReadBuffer(
        command_queue,
        buffer,
        blocking_read,
        offset,
        size,
        ptr,
        num_events_in_wait_list,
        event_wait_list,
        event
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_read_buffer_rect)
void
enqueue_read_buffer_rect(cl_command_queue command_queue,
                         cl_mem buffer,
                         cl_bool blocking_read,
                         const size_t* buffer_origin,
                         const size_t* host_origin,
                         const size_t* region,
                         size_t buffer_row_pitch,
                         size_t buffer_slice_pitch,
                         size_t host_row_pitch,
                         size_t host_slice_pitch,
                         void* ptr,
                         cl_uint num_events_in_wait_list,
                         const cl_event* event_wait_list,
                         cl_event* event)
{
  status_t s = static_cast<status_t>(
      T::clEnqueueReadBufferRect(
        command_queue,
        buffer,
        blocking_read,
        buffer_origin,
        host_origin,
        region,
        buffer_row_pitch,
        buffer_slice_pitch,
        host_row_pitch,
        host_slice_pitch,
        ptr,
        num_events_in_wait_list,
        event_wait_list,
        event
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_read_image)
void
enqueue_read_image(cl_command_queue command_queue,
                   cl_mem image,
                   cl_bool blocking_read,
                   const size_t* origin,
                   const size_t* region,
                   size_t row_pitch,
                   size_t slice_pitch,
                   void* ptr,
                   cl_uint num_events_in_wait_list,
                   const cl_event* event_wait_list,
                   cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueReadImage(
      command_queue,
      image,
      blocking_read,
      origin,
      region,
      row_pitch,
      slice_pitch,
      ptr,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_svm_free)
void
enqueue_svm_free(cl_command_queue command_queue,
                 cl_uint num_svm_pointers,
                 void* svm_pointers[],
                 void (CL_CALLBACK* pfn_free_func)(cl_command_queue queue,
                                                   cl_uint num_svm_pointers,
                                                   void *svm_pointers[],
                                                   void *user_data),
                 void* user_data,
                 cl_uint num_events_in_wait_list,
                 const cl_event* event_wait_list,
                 cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueSVMFree(
      command_queue,
      num_svm_pointers,
      svm_pointers,
      pfn_free_func,
      user_data,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_svm_map)
void
enqueue_svm_map(cl_command_queue command_queue,
                cl_bool blocking_map,
                map_flags_t map_flags,
                void* svm_ptr,
                size_t size,
                cl_uint num_events_in_wait_list,
                const cl_event* event_wait_list,
                cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueSVMMap(
      command_queue,
      blocking_map,
      static_cast<cl_map_flags>(map_flags),
      svm_ptr,
      size,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_svm_mem_fill)
void
enqueue_svm_mem_fill(cl_command_queue command_queue,
                     void* svm_ptr,
                     const void* pattern,
                     size_t pattern_size,
                     size_t size,
                     cl_uint num_events_in_wait_list,
                     const cl_event* event_wait_list,
                     cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueSVMMemFill(
      command_queue,
      svm_ptr,
      pattern,
      pattern_size,
      size,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_svm_memcpy)
void
enqueue_svm_memcpy(cl_command_queue command_queue,
                   cl_bool blocking_copy,
                   void* dst_ptr,
                   const void* src_ptr,
                   size_t size,
                   cl_uint num_events_in_wait_list,
                   const cl_event* event_wait_list,
                   cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueSVMMemcpy(
      command_queue,
      blocking_copy,
      dst_ptr,
      src_ptr,
      size,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_svm_migrate_mem)
void
enqueue_svm_migrate_mem(cl_command_queue command_queue,
                        cl_uint num_svm_pointers,
                        const void **svm_pointers,
                        const size_t *sizes,
                        mem_migration_flags_t flags,
                        cl_uint num_events_in_wait_list,
                        const cl_event* event_wait_list,
                        cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueSVMMigrateMem(
      command_queue,
      num_svm_pointers,
      svm_pointers,
      sizes,
      static_cast<cl_mem_migration_flags>(flags),
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_svm_unmap)
void
enqueue_svm_unmap(cl_command_queue command_queue,
                  void* svm_ptr,
                  cl_uint num_events_in_wait_list,
                  const cl_event* event_wait_list,
                  cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueSVMUnmap(
      command_queue,
      svm_ptr,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_task)
void
enqueue_task(cl_command_queue command_queue,
             cl_kernel kernel,
             cl_uint num_events_in_wait_list,
             const cl_event* event_wait_list,
             cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueTask(
      command_queue,
      kernel,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_unmap_mem_object)
void
enqueue_unmap_mem_object(cl_command_queue command_queue,
                         cl_mem memobj,
                         void* mapped_ptr,
                         cl_uint num_events_in_wait_list,
                         const cl_event* event_wait_list,
                         cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueUnmapMemObject(
      command_queue,
      memobj,
      mapped_ptr,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_wait_for_events)
void
enqueue_wait_for_events(cl_command_queue command_queue,
                        cl_uint num_events,
                        const cl_event* event_list)
{
  status_t s = static_cast<status_t>(
      T::clEnqueueWaitForEvents(
        command_queue,
        num_events,
        event_list
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_write_buffer)
void
enqueue_write_buffer( cl_command_queue command_queue, cl_mem buffer,
                      cl_bool blocking_write, size_t offset, size_t size,
                      const void* ptr, cl_uint num_events_in_wait_list,
                      const cl_event* event_wait_list, cl_event* event )
{
  status_t s = static_cast<status_t>(
      T::clEnqueueWriteBuffer(
        command_queue,
        buffer,
        blocking_write,
        offset,
        size,
        ptr,
        num_events_in_wait_list,
        event_wait_list,
        event
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
void
enqueue_write_buffer_rect(cl_command_queue command_queue,
                          cl_mem buffer,
                          cl_bool blocking_write,
                          const size_t* buffer_origin,
                          const size_t* host_origin,
                          const size_t* region,
                          size_t buffer_row_pitch,
                          size_t buffer_slice_pitch,
                          size_t host_row_pitch,
                          size_t host_slice_pitch,
                          const void* ptr,
                          cl_uint num_events_in_wait_list,
                          const cl_event* event_wait_list,
                          cl_event* event)
{
  status_t s = static_cast<status_t>(
      T::clEnqueueWriteBufferRect(
        command_queue,
        buffer,
        blocking_write,
        buffer_origin,
        host_origin,
        region,
        buffer_row_pitch,
        buffer_slice_pitch,
        host_row_pitch,
        host_slice_pitch,
        ptr,
        num_events_in_wait_list,
        event_wait_list,
        event
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(enqueue_write_image)
void
enqueue_write_image(cl_command_queue command_queue,
                    cl_mem image,
                    cl_bool blocking_write,
                    const size_t* origin,
                    const size_t* region,
                    size_t input_row_pitch,
                    size_t input_slice_pitch,
                    const void* ptr,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event)
{
  status_t s = static_cast<status_t>(
    T::clEnqueueWriteImage(
      command_queue,
      image,
      blocking_write,
      origin,
      region,
      input_row_pitch,
      input_slice_pitch,
      ptr,
      num_events_in_wait_list,
      event_wait_list,
      event
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(finish)
void
finish(cl_command_queue command_queue)
{
  status_t s = static_cast<status_t>(T::clFinish(command_queue));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(flush)
void
flush(cl_command_queue command_queue)
{
  status_t s = static_cast<status_t>(T::clFlush(command_queue));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_command_queue_info)
void
get_command_queue_info(cl_command_queue command_queue,
                       command_queue_info_t param_name,
                       size_t param_value_size,
                       void* param_value,
                       size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
    T::clGetCommandQueueInfo(
      command_queue,
      static_cast<cl_command_queue_info>(param_name),
      param_value_size,
      param_value,
      param_value_size_ret
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_context_info)
void
get_context_info(cl_context context,
                 context_info_t param_name,
                 size_t param_value_size,
                 void* param_value,
                 size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
    T::clGetContextInfo(
      context,
      static_cast<cl_context_info>(param_name),
      param_value_size,
      param_value,
      param_value_size_ret
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_device_and_host_timer)
void
get_device_and_host_timer(cl_device_id device,
                          cl_ulong* device_timestamp,
                          cl_ulong* host_timestamp)
{
  status_t s = static_cast<status_t>(
    T::clGetDeviceAndHostTimer(
      device,
      device_timestamp,
      host_timestamp
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_device_ids)
void
get_device_ids(cl_platform_id platform,
               device_type_t device_type,
               cl_uint num_entries,
               cl_device_id* devices,
               cl_uint* num_devices)
{
  status_t s = static_cast<status_t>(
    T::clGetDeviceIDs(
      platform,
      static_cast<cl_device_type>(device_type),
      num_entries,
      devices,
      num_devices
    )
  );
  if(is_error(s) && s != status_t::device_not_found)
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_device_info)
void
get_device_info(cl_device_id device,
                device_info_t param_name,
                size_t param_value_size,
                void* param_value,
                size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetDeviceInfo(
        device,
        static_cast<cl_device_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
     )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
void
#if CLXX_B5D_PROVIDES(get_event_info)
get_event_info(cl_event event, event_info_t param_name,
               size_t param_value_size, void* param_value,
               size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetEventInfo(event,
                        static_cast<cl_event_info>(param_name),
                        param_value_size,
                        param_value,
                        param_value_size_ret)
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_event_profiling_info)
void
get_event_profiling_info(cl_event event,
                         profiling_info_t param_name,
                         size_t param_value_size, void* param_value,
                         size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetEventProfilingInfo(
        event,
        static_cast<cl_profiling_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
     )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_extension_function_address)
void*
get_extension_function_address(const char* funcname)
{
  return T::clGetExtensionFunctionAddress(funcname);
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_extension_function_address_for_platform)
void*
get_extension_function_address_for_platform(cl_platform_id platform,
                                            const char* funcname)
{
  return T::clGetExtensionFunctionAddressForPlatform(platform, funcname);
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_host_timer)
void
get_host_timer(cl_device_id device,
               cl_ulong* host_timestamp)
{
  status_t s = static_cast<status_t>(
    T::clGetHostTimer(
      device,
      host_timestamp
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_image_info)
void
get_image_info(cl_mem image,
               image_info_t param_name,
               size_t param_value_size, void* param_value,
               size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetImageInfo(
        image,
        static_cast<cl_image_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
     )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_kernel_arg_info)
void
get_kernel_arg_info(cl_kernel kernel,
                    cl_uint arg_index,
                    kernel_arg_info_t param_name,
                    size_t param_value_size, void* param_value,
                    size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetKernelArgInfo(
        kernel,
        arg_index,
        static_cast<cl_kernel_arg_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_kernel_info)
void
get_kernel_info(cl_kernel kernel,
                kernel_info_t param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetKernelInfo(
        kernel,
        static_cast<cl_kernel_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
     )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_kernel_sub_group_info)
void
get_kernel_sub_group_info(cl_kernel kernel,
                          cl_device_id device,
                          kernel_sub_group_info_t param_name,
                          size_t input_value_size, const void* input_value,
                          size_t param_value_size, void* param_value,
                          size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetKernelSubGroupInfo(
        kernel,
        device,
        static_cast<cl_kernel_sub_group_info>(param_name),
        input_value_size,
        input_value,
        param_value_size,
        param_value,
        param_value_size_ret
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_kernel_work_group_info)
void
get_kernel_work_group_info(cl_kernel kernel,
                           cl_device_id device,
                           kernel_work_group_info_t param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetKernelWorkGroupInfo(
        kernel,
        device,
        static_cast<cl_kernel_work_group_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_mem_object_info)
void
get_mem_object_info(cl_mem memobj,
                    mem_info_t param_name,
                    size_t param_value_size, void* param_value,
                    size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetMemObjectInfo(
        memobj,
        static_cast<cl_mem_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
     )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_pipe_info)
void
get_pipe_info(cl_mem pipe,
              pipe_info_t param_name,
              size_t param_value_size, void* param_value,
              size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetPipeInfo(
        pipe,
        static_cast<cl_pipe_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
     )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_platform_ids)
void
get_platform_ids(cl_uint num_entries,
                 cl_platform_id* platforms,
                 cl_uint* num_platforms)
{
  status_t s = static_cast<status_t>(
      T::clGetPlatformIDs(num_entries, platforms, num_platforms)
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_platform_info)
void
get_platform_info(cl_platform_id platform,
                  platform_info_t param_name,
                  size_t param_value_size,
                  void* param_value,
                  size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetPlatformInfo( platform,
                            static_cast<cl_platform_info>(param_name),
                            param_value_size,
                            param_value,
                            param_value_size_ret )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_program_build_info)
void
get_program_build_info(cl_program program,
                       cl_device_id device,
                       program_build_info_t param_name,
                       size_t param_value_size,
                       void* param_value,
                       size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetProgramBuildInfo(
        program,
        device,
        static_cast<cl_program_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
     )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_program_info)
void
get_program_info(cl_program program,
                 program_info_t param_name,
                 size_t param_value_size,
                 void* param_value,
                 size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetProgramInfo(
        program,
        static_cast<cl_program_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
     )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_sampler_info)
void
get_sampler_info(cl_sampler sampler,
                 sampler_info_t param_name,
                 size_t param_value_size,
                 void* param_value,
                 size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetSamplerInfo(
        sampler,
        static_cast<cl_sampler_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
     )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(get_supported_image_formats)
void
get_supported_image_formats(cl_context context,
                            mem_flags_t flags,
                            mem_object_type_t image_type,
                            cl_uint num_entries,
                            cl_image_format* image_formats,
                            cl_uint* num_image_formats)
{
  status_t s = static_cast<status_t>(
    T::clGetSupportedImageFormats(
      context,
      static_cast<cl_mem_flags>(flags),
      static_cast<cl_mem_object_type>(image_type),
      num_entries,
      image_formats,
      num_image_formats
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(link_program)
cl_program
link_program(cl_context context,
             cl_uint num_devices,
             const cl_device_id* device_list,
             const char* options,
             cl_uint num_input_programs,
             const cl_program* input_programs,
             void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
             void* user_data)
{

  cl_int s = CL_SUCCESS;
  cl_program p = T::clLinkProgram(
      context,
      num_devices,
      device_list,
      options,
      num_input_programs,
      input_programs,
      pfn_notify,
      user_data,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return p;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(release_command_queue)
void
release_command_queue(cl_command_queue command_queue)
{
  status_t s = static_cast<status_t>(T::clReleaseCommandQueue(command_queue));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(release_context)
void
release_context(cl_context context)
{
  status_t s = static_cast<status_t>(T::clReleaseContext(context));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(release_device)
void
release_device(cl_device_id device)
{
  status_t s = static_cast<status_t>(T::clReleaseDevice(device));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(release_event)
void
release_event(cl_event event)
{
  status_t s = static_cast<status_t>(T::clReleaseEvent(event));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(release_kernel)
void
release_kernel(cl_kernel kernel)
{
  status_t s = static_cast<status_t>(T::clReleaseKernel(kernel));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(release_mem_object)
void
release_mem_object(cl_mem memobj)
{
  status_t s = static_cast<status_t>(T::clReleaseMemObject(memobj));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(release_program)
void
release_program(cl_program program)
{
  status_t s = static_cast<status_t>(T::clReleaseProgram(program));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(release_sampler)
void
release_sampler(cl_sampler sampler)
{
  status_t s = static_cast<status_t>(T::clReleaseSampler(sampler));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(retain_command_queue)
void
retain_command_queue(cl_command_queue command_queue)
{
  status_t s = static_cast<status_t>(T::clRetainCommandQueue(command_queue));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(retain_context)
void
retain_context(cl_context context)
{
  status_t s = static_cast<status_t>(T::clRetainContext(context));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(retain_device)
void
retain_device(cl_device_id device)
{
  status_t s = static_cast<status_t>(T::clRetainDevice(device));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(retain_event)
void
retain_event(cl_event event)
{
  status_t s = static_cast<status_t>(T::clRetainEvent(event));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(retain_kernel)
void
retain_kernel(cl_kernel kernel)
{
  status_t s = static_cast<status_t>(T::clRetainKernel(kernel));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(retain_mem_object)
void
retain_mem_object(cl_mem memobj)
{
  status_t s = static_cast<status_t>(T::clRetainMemObject(memobj));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(retain_program)
void
retain_program(cl_program program)
{
  status_t s = static_cast<status_t>(T::clRetainProgram(program));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(retain_sampler)
void
retain_sampler(cl_sampler sampler)
{
  status_t s = static_cast<status_t>(T::clRetainSampler(sampler));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(set_command_queue_property)
void
set_command_queue_property(cl_command_queue command_queue,
                           command_queue_properties_t properties,
                           cl_bool enable,
                           cl_command_queue_properties* old_properties)
{
  status_t s = static_cast<status_t>(
      T::clSetCommandQueueProperty(command_queue,
                                   static_cast<cl_command_queue_properties>(properties),
                                   enable,
                                   old_properties)
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(set_default_device_command_queue)
void
set_default_device_command_queue(cl_context context,
                                 cl_device_id device,
                                 cl_command_queue command_queue)
{
  status_t s = static_cast<status_t>(
      T::clSetDefaultDeviceCommandQueue(context, device, command_queue)
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(set_event_callback)
void
set_event_callback(cl_event event, cl_int command_exec_callback_type,
                   void(CL_CALLBACK*pfn_event_notify)(cl_event, cl_int, void*),
                   void* user_data)
{
  status_t s = static_cast<status_t>(
      T::clSetEventCallback(event,
                            command_exec_callback_type,
                            pfn_event_notify,
                            user_data)
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(set_kernel_arg)
void
set_kernel_arg(cl_kernel kernel,
               cl_uint arg_index,
               size_t arg_size,
               const void* arg_value)
{
  status_t s = static_cast<status_t>(
      T::clSetKernelArg(
        kernel,
        arg_index,
        arg_size,
        arg_value
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(set_kernel_arg_svm_pointer)
void
set_kernel_arg_svm_pointer(cl_kernel kernel,
                           cl_uint arg_index,
                           const void* arg_value)
{
  status_t s = static_cast<status_t>(
      T::clSetKernelArgSVMPointer(
        kernel,
        arg_index,
        arg_value
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(set_kernel_exec_info)
void
set_kernel_exec_info(cl_kernel kernel,
                     kernel_exec_info_t param_name,
                     size_t param_value_size,
                     const void* param_value)
{
  status_t s = static_cast<status_t>(
      T::clSetKernelExecInfo(
        kernel,
        static_cast<cl_kernel_exec_info>(param_name),
        param_value_size,
        param_value
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(set_mem_object_destructor_callback)
void
set_mem_object_destructor_callback(cl_mem memobj,
                                   void (CL_CALLBACK* pfn_notify)(cl_mem, void*),
                                   void* user_data)
{
  status_t s = static_cast<status_t>(
      T::clSetMemObjectDestructorCallback(memobj, pfn_notify, user_data)
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(set_user_event_status)
void
set_user_event_status(cl_event event, cl_int execution_status)
{
  status_t s = static_cast<status_t>(
      T::clSetUserEventStatus(event, execution_status)
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(svm_alloc)
void*
svm_alloc(cl_context context,
          svm_mem_flags_t flags,
          size_t size,
          cl_uint alignment)
{
  return T::clSVMAlloc(context, static_cast<cl_svm_mem_flags>(flags), size, alignment);
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(svm_free)
void
svm_free(cl_context context,
         void* svm_pointer)
{
  T::clSVMFree(context, svm_pointer);
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(unload_compiler)
void
unload_compiler()
{
  status_t s = static_cast<status_t>(T::clUnloadCompiler());
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(unload_platform_compiler)
void
unload_platform_compiler(cl_platform_id platform)
{
  status_t s = static_cast<status_t>(T::clUnloadPlatformCompiler(platform));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_B5D_PROVIDES(wait_for_events)
void
wait_for_events(cl_uint num_events, const cl_event* event_list)
{
  status_t s = static_cast<status_t>(
      T::clWaitForEvents(num_events, event_list)
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
} // end namespace clxx
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4: