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

/** // doc: swig/clxx/context_properties_.swg {{{
 * \file swig/clxx/context_properties_.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/context_properties.hpp>
%}
%include <std_vector.i>
%template (context_properties) std::vector<clxx::context_property>;

%include <clxx/exception_support.swg>

%exception clxx::context_properties_fill_array(clxx::context_properties const&, cl_context_properties *, size_t) {
  try { $action }
  %catch_invalid_argument_error
  %catch_not_enough_space_error
  %catch_exception
}
%exception clxx::context_properties_parse_array(clxx::context_properties&, cl_context_properties const *) {
  try { $action }
  %catch_invalid_argument_error
  %catch_badalloc
  %catch_exception
}
%throws_badalloc(clxx::operator&(context_property const&, context_property const&));
%throws_badalloc(clxx::operator&(context_properties const&, context_property const&))
%throws_badalloc(clxx::operator&(context_property const&, context_properties const&));
%throws_badalloc(clxx::operator&(context_properties const&, context_properties const&));
%throws_badalloc(clxx::make_context_properties);

%include <clxx/context_properties.hpp>

namespace clxx {
  inline context_properties make_context_properties(context_property const&);
  inline context_properties make_context_properties(context_property const&, context_property const&);
  inline context_properties make_context_properties(context_property const&, context_property const&, context_property const&);
  inline context_properties make_context_properties(context_property const&, context_property const&, context_property const&, context_property const&);

  inline context_properties make_context_properties(platform const&);
  inline context_properties make_context_properties(platform const&, context_property const&);
  inline context_properties make_context_properties(platform const&, context_property const&, context_property const&);
  inline context_properties make_context_properties(platform const&, context_property const&, context_property const&, context_property const&);

  inline context_properties make_context_properties(context_properties const&);
  inline context_properties make_context_properties(context_properties const&, context_property const&);
  inline context_properties make_context_properties(context_properties const&, context_property const&, context_property const&);
  inline context_properties make_context_properties(context_properties const&, context_property const&, context_property const&, context_property const&);

  inline context_properties make_context_properties(platform const&, context_properties const&);
};

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
