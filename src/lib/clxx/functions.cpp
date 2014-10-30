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
            // throw clerror_no<CL_DEVICE_NOT_FOUND>();
            break;
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
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
