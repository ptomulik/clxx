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

// clxx/cl/devices.cpp

/** // doc: clxx/cl/devices.cpp {{{
 * \file clxx/cl/devices.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/devices.hpp>
#include <clxx/cl/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx {

/* ------------------------------------------------------------------------ */
cl_uint
get_num_devices(cl_platform_id platform, device_type_t device_type)
{
  cl_uint num_devices = 0;
  get_device_ids(platform, device_type, 0, NULL, &num_devices);
  return num_devices;
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
std::vector<cl_device_id>
get_device_ids(cl_platform_id platform, device_type_t device_type)
{
  std::vector<cl_device_id> ids(get_num_devices(platform, device_type));
  if(ids.size() > 0)
    get_device_ids(platform, device_type, ids.size(), &ids[0], NULL);
  return ids;
}
/* ------------------------------------------------------------------------ */
devices
get_devices(cl_platform_id platform, device_type_t device_type)

{
  return make_devices(get_device_ids(platform, device_type));
}
/* ------------------------------------------------------------------------ */
devices
get_devices(platform const& platform, device_type_t device_type)

{
  return get_devices(platform.id(), device_type);
}
/* ------------------------------------------------------------------------ */
devices
make_devices(std::vector<cl_device_id> const& ids)
{
  return devices(ids.begin(), ids.end());
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
