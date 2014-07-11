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

// clxx/cl/devices.hpp

/** // doc: clxx/cl/devices.hpp {{{
 * \file clxx/cl/devices.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_DEVICES_HPP_INCLUDED
#define CLXX_CL_DEVICES_HPP_INCLUDED

#include <clxx/cl/device.hpp>
#include <clxx/cl/platform.hpp>
#include <clxx/types.hpp>

namespace clxx {


/** // doc: devices {{{
 * \ingroup clxx_platform_layer
 * \brief Collection of clxx::device objects.
 */ // }}}
typedef std::vector<device> devices;

/** \ingroup clxx_platform_layer */
/** @{ */
/** // doc: get_num_devices() {{{
 * \todo Write documentation
 */ // }}}
cl_uint get_num_devices(cl_platform_id platform, device_type_t device_type);
/** // doc: get_device_ids() {{{
 * \todo Write documentation
 */ // }}}
void get_device_ids(cl_platform_id platform, device_type_t device_type,
                    cl_uint num_entries, cl_device_id* devices,
                    cl_uint* num_devices);
/** // doc: get_device_ids() {{{
 * \todo Write documentation
 */ // }}}
std::vector<cl_device_id>
get_device_ids(cl_platform_id platform,
               device_type_t device_type = device_type_t::all);
/** // doc: get_devices() {{{
 * \todo Write documentation
 */ // }}}
devices
get_devices(cl_platform_id platform,
            device_type_t device_type = device_type_t::all);
/** // doc: get_devices() {{{
 * \todo Write documentation
 */ // }}}
devices
get_devices(platform const& platform,
            device_type_t device_type = device_type_t::all);
/** // {{{ doc: make_devices(ids)
 * \todo Write documentation
 *
 * In case of error, this function throws an exception defined by
 * CLXX_EXCEPTION(Bad_Alloc).
 */ // }}}
devices
make_devices(std::vector<cl_device_id> const& ids);
/** @} */

} // end namespace clxx

#endif /* CLXX_DEVICES_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
