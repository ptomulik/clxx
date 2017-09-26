// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/detail/path.hpp

/** // doc: clxx/c4n/detail/path.hpp {{{
 * \file clxx/c4n/detail/path.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_C4N_DETAIL_PATH_HPP_INCLUDED
#define CLXX_C4N_DETAIL_PATH_HPP_INCLUDED

#include <string>
#include <boost/algorithm/string.hpp>
#include <clxx/c4n/config.hpp>

namespace clxx { namespace detail {
#ifdef CLXX_WINDOWS_API
typedef wchar_t path_char_t;
#else
/** // doc: path_char_t {{{
 * \todo Write documentation
 */ // }}}
typedef char path_char_t;
#endif
/** // doc: path_string {{{
 * \todo Write documentation
 */ // }}}
typedef std::basic_string<path_char_t> path_string;
/** // doc: path_delimiter() {{{
 * \todo Write documentation
 */ // }}}
constexpr path_char_t
path_delimiter() noexcept
{
#ifdef CLXX_WINDOWS_API
  return L'\\';
#else
  return '/';
#endif
}
/** // doc: path_delimiter_str() {{{
 * \todo Write documentation
 */ // }}}
constexpr const path_char_t*
path_delimiter_str()
{
#ifdef CLXX_WINDOWS_API
  return L"\\";
#else
  return "/";
#endif
}
/** // doc: is_path_delimiter() {{{
 * \todo Write documentation
 */ // }}}
constexpr bool
is_path_delimiter(path_char_t c) noexcept
{
#ifdef CLXX_WINDOWS_API
  return c == L'\\' || c == L'/';
#else
  return c == '/';
#endif
}
/** // doc: path_split() {{{
 * \todo Write documentation
 */ // }}}
template< typename SequenceT, typename RangeT >
inline SequenceT&
path_split(SequenceT& pieces, RangeT& input,
           boost::algorithm::token_compress_mode_type compress
           = boost::algorithm::token_compress_off)
{
  return boost::algorithm::split(pieces, input, is_path_delimiter, compress);
}
/** // doc: path_join() {{{
 * \todo Write documentation
 */ // }}}
template< typename SequenceT >
typename boost::range_value<SequenceT>::type
path_join(const SequenceT& pieces)
{
  return boost::algorithm::join(pieces, path_delimiter_str());
}
/** // doc: path_normalize() {{{
 * \todo Write documentation
 */ // }}}
template< typename SequenceT, typename RangeT >
typename boost::range_value<SequenceT>::type
path_normalize(SequenceT& pieces, RangeT& input)
{
  return path_join(path_split(pieces, input, boost::algorithm::token_compress_on));
}
} } // end namespace clxx::detail

#endif /* CLXX_C4N_DETAIL_PATH_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
