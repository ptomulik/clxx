// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/detail/search_path.hpp

/** // doc: clxx/common/detail/search_path.hpp {{{
 * \file clxx/common/detail/search_path.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMON_DETAIL_SEARCH_PATH_HPP_INCLUDED
#define CLXX_COMMON_DETAIL_SEARCH_PATH_HPP_INCLUDED

#include <clxx/common/detail/path.hpp>

namespace clxx { namespace detail {
/** // doc: search_path_delimiter() {{{
 * \todo Write documentation
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
 * \todo Write documentation
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
 * \todo Write documentation
 */ // }}}
constexpr bool
is_search_path_delimiter(path_char_t c) noexcept
{
  return c == search_path_delimiter();
}
/** // doc: path_split() {{{
 * \todo Write documentation
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
 * \todo Write documentation
 */ // }}}
template< typename SequenceT >
typename boost::range_value<SequenceT>::type
search_path_join(const SequenceT& pieces)
{
  return boost::algorithm::join(pieces, search_path_delimiter_str());
}
/** // doc: search_path_prepend() {{{
 * \todo Write documentation
 */ // }}}
template< typename SequenceT1, typename SequenceT2 >
SequenceT1&
search_path_prepend(SequenceT1& p1, SequenceT2 const& p2)
{
  p1.insert(p1.begin(), p2.begin(), p2.end());
  return p1;
}
} } // end namespace clxx::detail

#endif /* CLXX_COMMON_DETAIL_SEARCH_PATH_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
