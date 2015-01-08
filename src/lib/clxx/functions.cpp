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

/** // doc: clxx/functions.cpp {{{
 * \file clxx/functions.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
void
get_platform_ids( cl_uint num_entries,
                  cl_platform_id* platforms,
                  cl_uint* num_platforms )
{
  status_t s = static_cast<status_t>(
      T::clGetPlatformIDs(num_entries, platforms, num_platforms)
  );
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
void
get_platform_info(  cl_platform_id platform,
                    platform_info_t param_name,
                    size_t param_value_size,
                    void* param_value,
                    size_t* param_value_size_ret  )
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
    switch(s)
      {
        case status_t::invalid_platform:
          throw clerror_no<status_t::invalid_platform>();
        case status_t::invalid_value:
          throw clerror_no<status_t::invalid_value>();
        case status_t::out_of_host_memory:
          throw clerror_no<status_t::out_of_host_memory>();
        default:
          throw unexpected_clerror(s);
      }
  }
}
/* ------------------------------------------------------------------------ */
void
get_device_ids(cl_platform_id platform, device_type_t device_type,
               cl_uint num_entries, cl_device_id* devices, cl_uint* num_devices)
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
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_platform:
            throw clerror_no<status_t::invalid_platform>();
          case status_t::invalid_device_type:
            throw clerror_no<status_t::invalid_device_type>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::device_not_found:
            break; // not found, so we return "empty sequence"
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
void
get_device_info(  cl_device_id device,
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
      switch(s)
        {
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
cl_context
create_context(const cl_context_properties* properties, cl_uint num_devices,
               const cl_device_id* devices,
               void(*pfn_notify)(const char* errinfo, const void* private_info,
                                 size_t cb, void* user_data),
               void* user_data)
{
  cl_int s;
  cl_context ctx;
  ctx = T::clCreateContext(properties, num_devices, devices, pfn_notify, user_data, &s);
  if(is_error(static_cast<status_t>(s)))
    {
      switch(static_cast<status_t>(s))
        {
          case status_t::invalid_platform:
            throw clerror_no<status_t::invalid_platform>();
#if CL_VERSION_1_1
          case status_t::invalid_property:
            throw clerror_no<status_t::invalid_property>();
          case status_t::invalid_operation:
            throw clerror_no<status_t::invalid_operation>();
#endif
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::device_not_available:
            throw clerror_no<status_t::device_not_available>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
#if cl_khr_gl_sharing
          case status_t::invalid_gl_sharegroup_reference_khr:
            throw clerror_no<status_t::invalid_gl_sharegroup_reference_khr>();
#endif
#if cl_khr_dx9_media_sharing
          case status_t::invalid_dx9_media_adapter_khr:
            throw clerror_no<status_t::invalid_dx9_media_adapter_khr>();
#endif
#if cl_khr_d3d10_sharing
          case status_t::invalid_d3d10_device_khr:
            throw clerror_no<status_t::invalid_d3d10_device_khr>();
#endif
#if cl_khr_d3d11_sharing
          case status_t::invalid_d3d11_device_khr:
            throw clerror_no<status_t::invalid_d3d11_device_khr>();
#endif
          default:
            throw unexpected_clerror(static_cast<status_t>(s));
        }
    }

  return ctx;
}
/* ------------------------------------------------------------------------ */
cl_context
create_context_from_type(const cl_context_properties* properties,
               device_type_t device_type,
               void(*pfn_notify)(const char* errinfo, const void* private_info,
                                 size_t cb, void* user_data),
               void* user_data)
{
  cl_int s;
  cl_context ctx;
  ctx = T::clCreateContextFromType(
      properties,
      static_cast<cl_device_type>(device_type),
      pfn_notify,
      user_data,
      &s);

  if(is_error(static_cast<status_t>(s)))
    {
      switch(static_cast<status_t>(s))
        {
          case status_t::invalid_platform:
            throw clerror_no<status_t::invalid_platform>();
#if CL_VERSION_1_1
          case status_t::invalid_property:
            throw clerror_no<status_t::invalid_property>();
          case status_t::invalid_operation:
            throw clerror_no<status_t::invalid_operation>();
#endif
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_device_type:
            throw clerror_no<status_t::invalid_device_type>();
          case status_t::device_not_available:
            throw clerror_no<status_t::device_not_available>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::device_not_found:
            throw clerror_no<status_t::device_not_found>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
#if cl_khr_gl_sharing
          case status_t::invalid_gl_sharegroup_reference_khr:
            throw clerror_no<status_t::invalid_gl_sharegroup_reference_khr>();
#endif
#if cl_khr_dx9_media_sharing
          case status_t::invalid_dx9_media_adapter_khr:
            throw clerror_no<status_t::invalid_dx9_media_adapter_khr>();
#endif
#if cl_khr_d3d10_sharing
          case status_t::invalid_d3d10_device_khr:
            throw clerror_no<status_t::invalid_d3d10_device_khr>();
#endif
#if cl_khr_d3d11_sharing
          case status_t::invalid_d3d11_device_khr:
            throw clerror_no<status_t::invalid_d3d11_device_khr>();
#endif
          default:
            throw unexpected_clerror(static_cast<status_t>(s));
        }
    }

  return ctx;
}
/* ------------------------------------------------------------------------ */
void retain_context(cl_context context)
{
  status_t s = static_cast<status_t>(T::clRetainContext(context));
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
void release_context(cl_context context)
{
  status_t s = static_cast<status_t>(T::clReleaseContext(context));
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
void get_context_info(cl_context context, context_info_t param_name,
                      size_t param_value_size, void* param_value,
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
      switch(s)
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
#if HAVE_OPENCL_clCreateSubDevices
void create_sub_devices(cl_device_id in_device,
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
      switch(s)
        {
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::device_partition_failed:
            throw clerror_no<status_t::device_partition_failed>();
          case status_t::invalid_device_partition_count:
            throw clerror_no<status_t::invalid_device_partition_count>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
#endif // HAVE_OPENCL_clCreateSubDevices
/* ------------------------------------------------------------------------ */
#if HAVE_OPENCL_clRetainDevice
void retain_device(cl_device_id device)
{
  status_t s = static_cast<status_t>(T::clRetainDevice(device));
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
#endif // HAVE_OPENCL_clRetainDevice
/* ------------------------------------------------------------------------ */
#if HAVE_OPENCL_clReleaseDevice
void release_device(cl_device_id device)
{
  status_t s = static_cast<status_t>(T::clReleaseDevice(device));
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
#endif // HAVE_OPENCL_clReleaseDevice
/** // doc: create_program_with_source(...) {{{
 * \todo Write documentation
 */ // }}}
cl_program create_program_with_source(cl_context context,
                                      cl_uint count,
                                      const char** strings,
                                      const size_t* lengths)
{
  cl_int s;
  cl_program p;
  p = clCreateProgramWithSource(context, count, strings, lengths, &s);
  if(is_error(static_cast<status_t>(s)))
    {
      switch(static_cast<status_t>(s))
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(static_cast<status_t>(s));
        }
    }
  return p;
}
/* ------------------------------------------------------------------------ */
cl_program create_program_with_binary(cl_context context,
                                      cl_uint num_devices,
                                      const cl_device_id* device_list,
                                      const size_t* lengths,
                                      const unsigned char** binaries,
                                      cl_int* binary_status)
{
  cl_int s;
  cl_program p = clCreateProgramWithBinary(context, num_devices, device_list,
                                           lengths, binaries, binary_status,
                                           &s);
  if(is_error(static_cast<status_t>(s)))
    {
      switch(static_cast<status_t>(s))
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::invalid_binary:
            throw clerror_no<status_t::invalid_binary>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(static_cast<status_t>(s));
        }
    }
  return p;
}
#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
/* ------------------------------------------------------------------------ */
cl_program create_program_with_built_in_kernels(cl_context context,
                                                cl_uint num_devices,
                                                const cl_device_id* device_list,
                                                const char* kernel_names)
{
  cl_int s;
  cl_program p = clCreateProgramWithBuiltInKernels(context, num_devices,
                                                   device_list, kernel_names,
                                                   &s);
  if(is_error(static_cast<status_t>(s)))
    {
      switch(static_cast<status_t>(s))
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(static_cast<status_t>(s));
        }
    }
  return p;
}
#endif
/* ------------------------------------------------------------------------ */
void retain_program(cl_program program)
{
  status_t s = static_cast<status_t>(T::clRetainProgram(program));
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_program:
            throw clerror_no<status_t::invalid_program>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
void release_program(cl_program program)
{
  status_t s = static_cast<status_t>(T::clReleaseProgram(program));
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_program:
            throw clerror_no<status_t::invalid_program>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
