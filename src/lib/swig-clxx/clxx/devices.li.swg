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

/** // doc: clxx/devices.li.swg {{{
 * \file clxx/devices.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/devices.hpp>
%}

//%include <clxx/device.swg>
//%include <clxx/platform.swg>
%include <std_vector.i>
%template() std::vector<cl_device_id>; // used by get_device_ids();
%template(devices) std::vector<clxx::device>;
%ignore clxx::devices;

%include <clxx/exception_support.swg>

%throws_clerror(clxx::get_num_devices(cl_platform_id, clxx::device_type_t));
%throws_clerror_badalloc(clxx::get_device_ids(cl_platform_id, clxx::device_type_t));
%throws_clerror_badalloc(clxx::get_devices(cl_platform_id, clxx::device_type_t));
%throws_clerror_badalloc(clxx::get_devices(clxx::platform const&, clxx::device_type_t));
%throws_badalloc(clxx::make_devices(std::vector<cl_device_id> const&));

%include <clxx/devices.hpp>


// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
