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

// clxx/device_partition.hpp

/** // doc: clxx/device_partition.hpp {{{
 * \file clxx/device_partition.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_DEVICE_PARTITION_HPP_INCLUDED
#define CLXX_DEVICE_PARTITION_HPP_INCLUDED

#include <clxx/devices.hpp>
#include <clxx/device_partition_properties.hpp>

namespace clxx {

/** \ingroup clxx_platform_layer */
/** @{ */
#if HAVE_OPENCL_clCreateSubDevices
/** // doc: get_num_sub_devices() {{{
 * \todo Write documentation
 */ // }}}
cl_uint get_num_sub_devices(device const& in_device,
                            device_partition_properties const& properties);
/** // doc: get_sub_devices() {{{
 * \todo Write documentation
 */ // }}}
devices get_sub_devices(device const& in_device,
                        device_partition_properties const& properties);
#endif
/** @} */

} // end namespace clxx

#endif /* CLXX_DEVICE_PARTITION_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
