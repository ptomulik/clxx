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

/** // doc: clxx/functions.li.swg {{{
 * \file clxx/functions.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/functions.hpp>
%}

%include <clxx/exception_support.swg>

%throws_clerror(clxx::get_platform_ids(cl_uint, cl_platform_id *, cl_uint *));
%throws_clerror(clxx::get_platform_info(cl_platform_id, platform_info_t, size_t, void *, size_t *));
%throws_clerror(clxx::get_device_ids(cl_platform_id, device_type_t, cl_uint, cl_device_id *, cl_uint *));
%throws_clerror(clxx::get_device_info(cl_device_id, device_info_t, size_t, void *, size_t *));
%throws_clerror(clxx::create_context(const cl_context_properties *, cl_uint, const cl_device_id *, void(*)(const char *, const void *,size_t, void *), void *));
%throws_clerror(clxx::create_context_from_type(const cl_context_properties *, device_type_t, void(*)(const char *, const void *, size_t, void *), void *));
%throws_clerror(clxx::retain_context(cl_context));
%throws_clerror(clxx::release_context(cl_context));
%throws_clerror(clxx::get_context_info(cl_context, context_info_t, size_t, void *, size_t *));
%throws_clerror(clxx::create_sub_devices(cl_device_id, const cl_device_partition_property *, cl_uint, cl_device_id *, cl_uint *));
%throws_clerror(clxx::retain_device(cl_device_id));
%throws_clerror(clxx::release_device(cl_device_id));

%include <clxx/functions.hpp>


// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
