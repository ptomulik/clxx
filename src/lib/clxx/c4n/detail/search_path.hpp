// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/detail/search_path.hpp

/** // doc: clxx/c4n/detail/search_path.hpp {{{
 * \file clxx/c4n/detail/search_path.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_C4N_DETAIL_SEARCH_PATH_HPP_INCLUDED
#define CLXX_C4N_DETAIL_SEARCH_PATH_HPP_INCLUDED

#include <clxx/c4n/detail/path.hpp>
#include <clxx/c4n/config.hpp>

namespace clxx { namespace detail {
/** // doc: search_path_delimiter() {{{
 * \brief Returns search path delimiter used on current platform
 *
 * The search path delimiter is a signle character, which separates consecutive
 * paths in a search path string.
 */ // }}}
constexpr path_char_t
search_path_delimiter() noexcept
{
#ifdef CLXX_WINDOWS_API
  return L';';
#else
  return ':';
#endif
}
/** // doc: search_path_delimiter_str() {{{
 * \brief Returns search path delimiter as a (single-char) C string
 */ // }}}
constexpr const path_char_t*
search_path_delimiter_str() noexcept
{
#ifdef CLXX_WINDOWS_API
  return L";";
#else
  return ":";
#endif
}
/** // doc: is_search_path_delimiter() {{{
 * \brief Returns \c true if \p c is a search patch delimiter character
 */ // }}}
constexpr bool
is_search_path_delimiter(path_char_t c) noexcept
{
  return c == search_path_delimiter();
}
/** // doc: path_split() {{{
 * \brief Split search path string into a vector of separated paths. Uses
 *        search path delimiter (see #is_search_path_delimiter()).
 */ // }}}
template< typename SequenceT, typename RangeT >
SequenceT&
search_path_split(SequenceT& pieces, RangeT& input,
                  boost::algorithm::token_compress_mode_type compress
                  = boost::algorithm::token_compress_off)
{
  return boost::algorithm::split(pieces, input, is_search_path_delimiter, compress);
}
/** // doc: path_join() {{{
 * \brief Join \p pieces (path strings) to return single search path string.
 *        Uses search path delimiter (see #search_path_delimiter_str())
 */ // }}}
template< typename SequenceT >
typename boost::range_value<SequenceT>::type
search_path_join(const SequenceT& pieces)
{
  return boost::algorithm::join(pieces, search_path_delimiter_str());
}
} } // end namespace clxx::detail

#endif /* CLXX_C4N_DETAIL_SEARCH_PATH_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
