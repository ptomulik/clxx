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

/** // doc: clxx/device_partition_property_.swg {{{
 * \file clxx/device_partition_property_.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/device_partition_property.hpp>
%}

%include <clxx/exception_support.swg>

%define %throws_as_device_partition_property_setter(decl)
%exception decl {
  try { $action }
  %catch_value_access_error
  %catch_badalloc
  %catch_exception
}
%enddef

%define %throws_as_device_partition_property_getter(decl)
%exception decl {
  try { $action }
  %catch_value_access_error
  %catch_exception
}
%enddef

%throws_as_device_partition_property_setter(clxx::device_partition_property::device_partition_property(clxx::device_partition_property_t, clxx::device_partition_counts const&));
%throws_as_device_partition_property_setter(clxx::device_partition_property::device_partition_property(cl_device_partition_property, clxx::device_partition_counts const&));
%throws_as_device_partition_property_getter(clxx::device_partition_property::value() const);
%throws_as_device_partition_property_getter(clxx::device_partition_property::value(size_t) const);
%throws_as_device_partition_property_getter(clxx::device_partition_property::values() const);
%throws_as_device_partition_property_setter(clxx::device_partition_property::set_value(cl_device_partition_property));
%throws_as_device_partition_property_setter(clxx::device_partition_property::set_values(clxx::device_partition_counts const&));
%throws_badalloc(clxx::device_partition_property::read(cl_device_partition_property const *));

%throws_badalloc(clxx::make_device_partition_propety);
%throws_badalloc(clxx::device_partition_equally(unsigned int));
%throws_badalloc(clxx::device_partition_by_counts(clxx::device_partition_counts const&));
%throws_badalloc(clxx::device_partition_by_affinity_domain(clxx::affinity_domain_t));

%include <clxx/device_partition_property.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
