// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/detail/locale.hpp

/** // doc: clxx/common/detail/locale.hpp {{{
 * \file clxx/common/detail/locale.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMON_DETAIL_LOCALE_HPP_INCLUDED
#define CLXX_COMMON_DETAIL_LOCALE_HPP_INCLUDED

#include <locale>
#include <string>

namespace clxx { namespace detail {
/** // doc: convert() {{{
 * \todo Write documentation
 */ // }}}
inline std::codecvt_base::result
convert(std::string const& in, std::wstring& out,
        std::codecvt<wchar_t, char, std::mbstate_t> const& cvt)
{
  if(in.empty())
    {
      out.clear();
      return std::codecvt_base::ok;
    }

  std::mbstate_t mb = std::mbstate_t();

  out.resize(4 + in.size(), L'\0');

  const char* from_beg = &in[0];
  const char* from_end = from_beg + in.size();
  const char* from_nxt;
  wchar_t* to_beg = &out[0];
  wchar_t* to_end = to_beg + out.size();
  wchar_t* to_nxt;

  std::codecvt_base::result result;
  result = cvt.in(mb, from_beg, from_end, from_nxt, to_beg, to_end, to_nxt);
  switch(result)
    {
      case std::codecvt_base::noconv:
        out.resize(from_end - from_beg, L'\0');
        for(size_t i = 0ul; i != in.size(); ++i)
          out[i] = static_cast<wchar_t>(in[i]);
        result = std::codecvt_base::ok;
        break;
      case std::codecvt_base::ok:
        out.resize(to_nxt - to_beg);
        break;
      default:
        break;
    }
  return result;
}
/** // doc: convert() {{{
 * \todo Write documentation
 */ // }}}
inline std::codecvt_base::result
convert(std::wstring const& in, std::string& out,
        std::codecvt<wchar_t, char, std::mbstate_t> const& cvt)
{
  if(in.empty())
    {
      out.clear();
      return std::codecvt_base::ok;
    }

  std::mbstate_t mb = std::mbstate_t();

  out.resize(4 + in.size() * cvt.max_length(), '\0');

  const wchar_t* from_beg = &in[0];
  const wchar_t* from_end = from_beg + in.size();
  const wchar_t* from_nxt;
  char* to_beg = &out[0];
  char* to_end = to_beg + out.size();
  char* to_nxt;

  std::codecvt_base::result result;
  result = cvt.out(mb, from_beg, from_end, from_nxt, to_beg, to_end, to_nxt);
  switch(result)
    {
      case std::codecvt_base::noconv:
        out.resize(from_end - from_beg, L'\0');
        for(size_t i = 0ul; i != in.size(); ++i)
          out[i] = static_cast<char>(in[i]);
        result = std::codecvt_base::ok;
        break;
      case std::codecvt_base::ok:
        out.resize(to_nxt - to_beg);
        break;
      default:
        break;
    }

  return result;
}
} } // end namespace clxx::detail

#endif /* CLXX_COMMON_DETAIL_LOCALE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
