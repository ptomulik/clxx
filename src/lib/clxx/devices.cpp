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

// clxx/devices.cpp

/** // doc: clxx/devices.cpp {{{
 * \file clxx/devices.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/devices.hpp>
#include <clxx/functions.hpp>

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
