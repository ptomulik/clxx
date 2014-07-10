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

// clxx/io/platform_query.cpp

/** // doc: clxx/io/platform_query.cpp {{{
 * @file clxx/io/platform_query.cpp
 * @todo Write documentation
 */ // }}}
#include <clxx/io/platform_query.hpp>
#include <clxx/io/autosep.hpp>
#include <ostream>
#include <string>

template<typename _Traits>
static std::basic_ostream<wchar_t, _Traits>&
operator << ( std::basic_ostream<wchar_t, _Traits>& os
            , std::string const& s)
{
  return os << s.c_str();
}

/* Name-pointer pair */
struct Npp
{
  const char* name;
  bool (clxx::platform_query::*ptr) () const;
};
#define NPP(name) { #name, &clxx::platform_query::name ## _selected}

static Npp npps[] =
{
  NPP(id)
, NPP(profile)
, NPP(version)
, NPP(name)
, NPP(vendor)
, NPP(extensions)
};

namespace clxx { namespace io {

template <class Ostream> Ostream&
write(Ostream& os, clxx::platform_query const& query, int ind)
{
  autosep_<const char*> as("\n");
  std::string pre(ind, ' ');
  for(int i=0; i<(int)(sizeof(npps)/sizeof(*npps));++i) {
    if((query.*(npps[i].ptr))())
      os << as << pre << npps[i].name;
  }
  return os;
}

template <class Ostream> Ostream&
write(Ostream& os, clxx::platform_query const& query)
{
  return write(os, query, 0);
}

} } // end namespace clxx::io

template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , clxx::platform_query const& query)
{
  return clxx::io::write(os, query);
}

// Instantiate our operator for several types.
template std::basic_ostream<char>&
operator << ( std::basic_ostream<char>& os
            , clxx::platform_query const& query );
template std::basic_ostream<wchar_t>&
operator << ( std::basic_ostream<wchar_t>& os
            , clxx::platform_query const& query );

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
