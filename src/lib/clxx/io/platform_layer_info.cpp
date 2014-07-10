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

// clxx/io/platform_layer_info.cpp

/** // doc: clxx/io/platform_layer_info.cpp {{{
 * @file clxx/io/platform_layer_info.cpp
 * @todo Write documentation
 */ // }}}
#include <ostream>

template<typename _Traits>
static std::basic_ostream<wchar_t, _Traits>&
operator << ( std::basic_ostream<wchar_t, _Traits>& os
            , std::string const& s)
{
  return os << s.c_str();
}

#include <clxx/io/platform_layer_info_impl.hpp>

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , clxx::platform_layer_info const& info)
{
  return clxx::io::write(os, info);
}

#include <string>

//
// Instantiations:
//
namespace clxx { namespace io {

template std::basic_ostream<char> &
write( std::basic_ostream<char> &
     , clxx::platform_layer_info const&
     , int );

template std::basic_ostream<wchar_t> &
write( std::basic_ostream<wchar_t> &
     , clxx::platform_layer_info const&
     , int );

} } // end namespace clxx::io

template std::basic_ostream<char> &
operator << ( std::basic_ostream<char> & os
            , clxx::platform_layer_info const& info );
template std::basic_ostream<wchar_t> &
operator << ( std::basic_ostream<wchar_t> & os
            , clxx::platform_layer_info const& info );

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
