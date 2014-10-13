/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE
 */
/** // \defgroup clxx_platform_layer {{{
 * \defgroup clxx_platform_layer OpenCL platform layer
 *
 * This module defines c++ wrappers around *OpenCL platform layer* described by
 * the OpenCL specification under chapter 4 "The OpenCL Platform Layer". Most
 * of the functionalities is exposed in object oriented way, some calls are
 * simplified. OpenCL errors are turned-out into %clxx exceptions
 * (see \ref clxx_exceptions). The API defined by this module is type-safe.
 *
 * The %clxx API for OpenCL platform layer defines the following core classes:
 *   - clxx::platform,
 *   - clxx::device,
 *
 * The whole OpenCL platform layer (all locally available OpenCL platforms and
 * devices) is represented by
 *   - clxx::platform_layer
 *
 * object. There is also a number of free-standing functions such as
 *   - clxx::get_num_platforms,
 *   - clxx::get_platforms,
 *   - clxx::get_num_devices,
 *   - clxx::get_devices.
 *
 * The clxx::platform object is used to query information from a single OpenCL
 * platform. The clxx::device is used to do the same with an OpenCL device. The
 * clxx::platform and clxx::device objects are lightweight. The only data
 * encapsulated by clxx::platform is a \c cl_platform_id identifier, and the
 * clxx::device encapsulates its \c cl_device_id identifier (both are just
 * pointers).
 *
 * A collection of clxx::platform objects representing locally available OpenCL
 * platforms may be retrieved with clxx::get_platforms(), for example:
 *
 * \code
 *  clxx::platforms ps(clxx::get_platforms());
 * \endcode
 *
 * Similarly, a collection of clxx::device objects representing devices
 * comprising given OpenCL platform may be retrieved with clxx::get_devices(),
 * for example:
 *
 * \code
 *  clxx::devices ds(clxx::get_devices(ps[0]));
 * \endcode
 *
 */ // }}}
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
