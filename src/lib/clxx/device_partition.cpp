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

// clxx/device_partition.cpp

/** // doc: clxx/device_partition.cpp {{{
 * \file clxx/device_partition.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/device_partition.hpp>
#include <clxx/functions.hpp>
#include <boost/shared_array.hpp>

namespace clxx {
#if HAVE_OPENCL_clCreateSubDevices
/* ------------------------------------------------------------------------ */
static void
_create_sub_devices(cl_device_id in_device,
                    device_partition_properties const& properties,
                    cl_uint num_devices,
                    cl_device_id *out_devices,
                    cl_uint *num_devices_ret)
{
  const size_t array_size = device_partition_properties_array_size(properties);
  boost::shared_array<cl_device_partition_property> array(new cl_device_partition_property[array_size]);
  device_partition_properties_fill_array(properties, array.get(), array_size);
  create_sub_devices(in_device, array.get(), num_devices, out_devices, num_devices_ret);
}
/* ------------------------------------------------------------------------ */
cl_uint
get_num_sub_devices(device const& in_device, device_partition_properties const& properties)
{
  cl_uint num_devices = 0;
  _create_sub_devices(in_device.get_valid_id(), properties, 0, nullptr, &num_devices);
  return num_devices;
}
/* ------------------------------------------------------------------------ */
devices
get_sub_devices(device const& in_device, device_partition_properties const& properties)
{
  std::vector<cl_device_id> ids(get_num_sub_devices(in_device, properties));
  if(ids.size() > 0)
    _create_sub_devices(in_device.get_valid_id(), properties, ids.size(), &ids[0], NULL);
  return make_devices(ids);
}
/* ------------------------------------------------------------------------ */
#endif // HAVE_OPENCL_clCreateSubDevices
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
