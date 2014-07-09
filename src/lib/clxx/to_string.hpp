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

// clxx/to_string.hpp

/** // doc: clxx/to_string.hpp {{{
 * \file clxx/to_string.hpp
 * \brief Conversions of several types of data to string
 *
 * This header implements overloaded std::to_string for several types defined
 * in clxx.
 */ // }}}
#ifndef CLXX_TO_STRING_HPP_INCLUDED
#define CLXX_TO_STRING_HPP_INCLUDED

#include <clxx/types.hpp>
#include <clxx/enum2name.hpp>
#include <clxx/enum2hex.hpp>
#include <string>

namespace clxx {

template<typename E>
std::string enum_to_name_or_hex(E x)
{
  char const* name = clxx::enum2name(x);
  return name ? std::string(name) : enum2hex(x);
}

} // end namespace clxx

namespace std {

/** // doc: to_string(clxx::status_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::status_t x)
{ return clxx::enum2hex(x); }

} // end namespace std

#endif /* CLXX_TO_STRING_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
