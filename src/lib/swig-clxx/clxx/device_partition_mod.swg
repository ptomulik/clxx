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

/** // doc: swig/clxx/device_partition_mod.swg {{{
 * \file swig/clxx/device_partition_mod.swg
 * \todo Write documentation
 */ // }}}

%import <clxx/swig_config.swg>

%include <std_vector.i>
%include <std_string.i>

%import <clxx/cl/opencl1_0.i>
%import <clxx/exception_mod.i>
%import <clxx/platform_mod.i>
%import <clxx/types_mod.i>

%{
#include <clxx/cl/opencl_mod.hpp>
#include <clxx/exception_mod.hpp>
#include <clxx/platform_mod.hpp>
#include <clxx/types_mod.hpp>

#include <clxx/device_partition_property.hpp>
#include <clxx/device_partition_properties.hpp>
#include <clxx/device_partition.hpp>
%}

%include <clxx/device_partition_property.swg>
%include <clxx/device_partition_properties_.swg>
%include <clxx/device_partition.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
