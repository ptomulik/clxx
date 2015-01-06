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

/** // doc: swig/clxx/context.li.swg {{{
 * \file swig/clxx/context.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/context.hpp>
%}

%include <clxx/exception_support.swg>

%define %throws_as_context_get_pod_info(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_context_error
  %catch_clerror
  %catch_exception
}
%enddef

%define %throws_as_context_get_vec_info(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_context_error
  %catch_clerror
  %catch_badalloc
  %catch_exception
}
%enddef

%define %throws_uninitialized_context(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_context_error
  %catch_exception
}
%enddef

%define %throws_as_context_ctor1(decl)
%exception decl {
  try { $action }
  %catch_invalid_argument_error
  %catch_not_enough_space_error
  %catch_badalloc
  %catch_exception
}
%enddef

%throws_as_context_ctor1(clxx::context::context(clxx::context_properties const&, clxx::devices const&, void(*)(const char *, const void*, size_t, void *), void *));
%throws_as_context_ctor1(clxx::context::context(clxx::context_properties const&, clxx::device_type_t, void(*)(const char *, const void*, size_t, void *), void *));
%throws_uninitialized_context(clxx::context::context(clxx::context const&));
%throws_as_context_get_pod_info(clxx::context::get_info(clxx::context_info_t, size_t, void *, size_t *) const);
%throws_uninitialized_context(clxx::context::get_valid_ctx() const);
%throws_uninitialized_context(clxx::context::operator=(clxx::context const&));
%throws_uninitialized_context(clxx::context::assign(context const&));
%throws_as_context_get_pod_info(clxx::context::get_reference_count() const);
%throws_as_context_get_pod_info(clxx::context::get_num_devices() const);
%throws_as_context_get_vec_info(clxx::context::get_devices() const);
%throws_as_context_get_vec_info(clxx::context::get_properties() const);


%include <clxx/context.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
