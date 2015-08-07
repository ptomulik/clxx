// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/search_path.hpp

/** // doc: clxx/cl/search_path.hpp {{{
 * \file clxx/cl/search_path.hpp
 * \brief Utility functions that implement a simple "search path" logic
 */ // }}}
#ifndef CLXX_COMMON_SEARCH_PATH_HPP_INCLUDED
#define CLXX_COMMON_SEARCH_PATH_HPP_INCLUDED

#if 0
#include <string>
#include <vector>
#include <unordered_set>
#include <boost/locale.hpp>
#endif
#include <algorithm>
#include <clxx/common/config.hpp>

namespace clxx {
#if 0
/** // doc: basic_search_path {{{
 * \brief A generic string template used to implement search path &mdash; an
 *        alias for std::basic_string
 */ // }}}
template< class CharT,
          class Traits = std::char_traits<CharT>,
          class Allocator = std::allocator<CharT> >
using basic_search_path = std::basic_string<CharT, Traits, Allocator>;
/** // doc: search_path {{{
 * \brief An 8-byte string used to hold path name (assumed to be a utf8-encoded string)
 */ // }}}
typedef basic_search_path<char> search_path;
/** // doc: u8search_path {{{
 * \brief 8-bit string used to hold path name (assumed to be a utf8-encoded string)
 */ // }}}
typedef basic_search_path<char> u8search_path;
/** // doc: u32search_path {{{
 * \brief 32-bit string used to hold path name (assumed to be a utf32-encoded string)
 */ // }}}
typedef basic_search_path<char32_t> u32search_path;
/** // doc: basic_search_paths {{{
 * \brief A generic vector of search paths used to implement a sequence of paths to be looked-up
 */ // }}}
template< class CharT,
          class Alloc = std::allocator< basic_search_path<CharT> > >
using basic_search_paths = std::vector<basic_search_path<CharT>, Alloc>;
/** // doc: u8search_paths {{{
 * \todo Write documentation
 */ // }}}
typedef basic_search_paths<char> u8search_paths;
/** // doc: u8search_paths {{{
 * \todo Write documentation
 */ // }}}
typedef basic_search_paths<char32_t> u32search_paths;
#endif
/** // doc: search_path_separator {{{
 * \todo Write documentation
 */ // }}}
constexpr char32_t
search_path_separator() noexcept
{
#ifdef CLXX_WINDOWS_API
  return U';';
#else
  return U':';
#endif
}
/** // doc: search_path_split() {{{
 * \todo Write documentation
 */ // }}}
template<typename ToUTF, typename FromUTF>
std::vector<std::string>
inline search_path_split(std::string const& str, ToUTF to_utf, FromUTF from_utf)
{
  std::u32string u32str(to_utf(str));
  std::vector<std::string> paths;
  paths.reserve(1 + std::count(u32str.begin(), u32str.end(), search_path_separator()));
  for(size_t beg = 0ul, end; beg < u32str.size(); beg = end + (end < u32str.size()))
    {
      end = u32str.find(search_path_separator(), beg);
      if(beg < end)
        paths.push_back(from_utf(u32str.substr(beg, end - beg)));
    }
  return paths;
}
#if 0
/** // doc: search_path_split_u32() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharOut>
basic_search_paths<CharOut>
search_path_split_u32(u32search_path const& str)
{
  using boost::locale::conv::utf_to_utf;
  basic_search_paths<CharOut> paths;
  paths.reserve(1 + std::count(str.begin(), str.end(), search_path_separator()));
  for(size_t beg = 0ul, end; beg < str.size(); beg = end + (end < str.size()))
    {
      end = str.find(search_path_separator(), beg);
      if(beg < end)
        paths.push_back(utf_to_utf<CharOut>(str.substr(beg, end - beg)));
    }
  return paths;
}
/** // doc: search_path_split() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharOut, typename CharIn>
basic_search_paths<CharOut>
search_path_split(basic_search_path<CharIn> const& str)
{
  using boost::locale::conv::utf_to_utf;
  return search_path_split_u32<CharOut>(utf_to_utf<char32_t>(str));
}
/** // doc: search_path_split() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharOut, typename CharIn>
basic_search_paths<CharOut>
search_path_split(CharIn const* str)
{
  using boost::locale::conv::utf_to_utf;
  return search_path_split_u32<CharOut>(utf_to_utf<char32_t>(str));
}
/** // doc: search_path_join_u32() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharIn>
basic_search_path<char32_t>
search_path_join_u32(basic_search_paths<CharIn> const& paths)
{
  using boost::locale::conv::utf_to_utf;
  basic_search_path<char32_t> str;
  auto it = paths.cbegin();
  if(it != paths.cend())
    {
      for(str += utf_to_utf<char32_t>(*it++); it != paths.cend(); ++it)
        {
          str += search_path_separator();
          str += utf_to_utf<char32_t>(*it);
        }
    }
  return str;
}
/** // doc: search_path_join() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharOut, typename CharIn>
basic_search_path<CharOut>
search_path_join(basic_search_paths<CharIn> const& paths)
{
  using boost::locale::conv::utf_to_utf;
  return utf_to_utf<CharOut>(search_path_join_u32(paths));
}
/** // doc: search_path_unique() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT>
basic_search_paths<CharT>
search_path_unique(basic_search_paths<CharT> const& paths,
                   basic_search_paths<CharT> const& exclude 
                    = basic_search_paths<CharT>())
{
  std::unordered_set<basic_search_path<CharT> > set(exclude.cbegin(), exclude.cend());
  basic_search_paths<CharT> result;
  for(basic_search_path<CharT> const& path : paths)
    {
      if(set.find(path) == set.end())
        {
          set.insert(path);
          result.push_back(path);
        }
    }
  return result;
}
/** // doc: search_path_append() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT, typename CharIn>
basic_search_paths<CharT>&
search_path_append(basic_search_paths<CharT>& paths,
                   basic_search_path<CharIn> const& str)
{
  basic_search_paths<CharT> tmp( search_path_split<CharT>(str) );
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_append() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT, typename CharIn>
basic_search_paths<CharT>&
search_path_append(basic_search_paths<CharT>& paths, CharIn const* str)
{
  return search_path_append(paths, basic_search_path<CharIn>(str));
}
/** // doc: search_path_prepend() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT, typename CharIn>
basic_search_paths<CharT>&
search_path_prepend(basic_search_paths<CharT>& paths,
                    basic_search_path<CharIn> const& str)
{
  basic_search_paths<CharT> tmp( search_path_split<CharT>(str) );
  std::swap(tmp, paths);
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_prepend() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT, typename CharIn>
basic_search_paths<CharT>&
search_path_prepend(basic_search_paths<CharT>& paths, CharIn const* str)
{
  return search_path_prepend(paths, basic_search_path<CharIn>(str));
}
/** // doc: search_path_append_unique() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT, typename CharIn>
basic_search_paths<CharT>&
search_path_append_unique(basic_search_paths<CharT>& paths,
                          basic_search_path<CharIn> const& str)
{
  basic_search_paths<CharT> tmp( search_path_unique(search_path_split<CharT>(str), paths) );
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_append_unique() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT, typename CharIn>
basic_search_paths<CharT>&
search_path_append_unique(basic_search_paths<CharT>& paths, CharIn const* str)
{
  return search_path_append_unique(paths, basic_search_path<CharIn>(str));
}
/** // doc: search_path_prepend_unique() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT, typename CharIn>
basic_search_paths<CharT>&
search_path_prepend_unique(basic_search_paths<CharT>& paths,
                    basic_search_path<CharIn> const& str)
{
  basic_search_paths<CharT> tmp( search_path_unique(search_path_split<CharT>(str), paths) );
  std::swap(tmp, paths);
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_prepend_unique() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT, typename CharIn>
basic_search_paths<CharT>&
search_path_prepend_unique(basic_search_paths<CharT>& paths, CharIn const* str)
{
  return search_path_prepend_unique(paths, basic_search_path<CharIn>(str));
}
/** // doc: search_path_erase() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT, typename CharIn>
basic_search_paths<CharT>&
search_path_erase(basic_search_paths<CharT>& paths, basic_search_path<CharIn> const& str)
{
  basic_search_paths<CharT> seq(search_path_split<CharT>(str));
  std::unordered_set< basic_search_path<CharT> > set(seq.cbegin(), seq.cend());
  auto f = [set](basic_search_path<CharT> const& s) { return set.find(s) != set.end(); };
  paths.erase(std::remove_if(paths.begin(), paths.end(), f), paths.end());
  return paths;
}
/** // doc: search_path_erase() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT, typename CharIn>
basic_search_paths<CharT>&
search_path_erase(basic_search_paths<CharT>& paths, CharIn const* str)
{
  return search_path_erase(paths, basic_search_path<CharIn>(str));
}
/** // doc: search_path_find_file() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT>
std::basic_string<CharT>
search_path_lookup(basic_search_paths<CharT> const& paths,
                   std::basic_string<CharT> const& file)
{
  // TODO: implement???
  (void)paths;
  (void)file;
}
#endif
} // end namespace clxx

#endif /* CLXX_COMMON_SEARCH_PATH_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
