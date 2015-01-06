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

/** // doc: clxx/devices.li.i {{{
 * \file clxx/devices.li.i
 * \todo Write documentation
 */ // }}}

%include <std_vector.i>
%include <clxx/exception_support.swg>

%import <clxx/types.i>
%import <clxx/std/string.i>
%import <clxx/device_query.i>
%import <clxx/device_info.i>
%import <clxx/platforms.i>

%{
#include <clxx/types.i.hpp>
#include <clxx/std/string.i.hpp>
#include <clxx/device_query.i.hpp>
#include <clxx/device_info.i.hpp>
#include <clxx/platforms.i.hpp>
%}

%include <clxx/device.swg>
%include <clxx/devices.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
