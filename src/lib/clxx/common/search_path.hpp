// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/search_path.hpp

/** // doc: clxx/common/search_path.hpp {{{
 * \file clxx/common/search_path.hpp
 * \brief Utility functions that implement a simple "search path" logic
 */ // }}}
#ifndef CLXX_COMMON_SEARCH_PATH_HPP_INCLUDED
#define CLXX_COMMON_SEARCH_PATH_HPP_INCLUDED

#include <sstream>
#include <unordered_set>
#include <algorithm>
#include <clxx/common/config.hpp>

namespace clxx {
/** // doc: search_path_separator {{{
 * \todo Write documentation
 */ // }}}
constexpr char
search_path_separator() noexcept
{
#ifdef CLXX_WINDOWS_API
  return ';';
#else
  return ':';
#endif
}
/** // doc: search_path_split_impl() {{{
 * \todo Write documentation
 */ // }}}
inline void
search_path_split_impl(std::vector<std::string>& paths, std::istream& is)
{
  constexpr char sep = search_path_separator();
  std::string path;
  while(!is.eof())
    {
      std::getline(is, path, sep);
      paths.push_back(path);
    }
}
/** // doc: search_path_split() {{{
 * \todo Write documentation
 */ // }}}
inline std::vector<std::string>
search_path_split(std::string const& str)
{
  std::vector<std::string> paths;
  if(!str.empty())
    {
      std::stringstream ss(str);
      search_path_split_impl(paths, ss);
    }
  return paths;
}
/** // doc: search_path_split() {{{
 * \todo Write documentation
 */ // }}}
inline std::vector<std::string>
search_path_split(std::string const& str, std::locale const& loc)
{
  std::vector<std::string> paths;
  if(!str.empty())
    {
      std::stringstream ss(str);
      ss.imbue(loc);
      search_path_split_impl(paths, ss);
    }
  return paths;
}
/** // doc: search_path_join_impl() {{{
 * \todo Write documentation
 */ // }}}
inline void
search_path_join_impl(std::ostream& os, std::vector<std::string> const& paths)
{
  if(!paths.empty())
    {
      const char sep = search_path_separator();
      auto it = paths.begin();
      os << *it++;
      while(it != paths.end())
        os << sep << *it++;
    }
}
/** // doc: search_path_join() {{{
 * \todo Write documentation
 */ // }}}
inline std::string
search_path_join(std::vector<std::string> const& paths)
{
  std::stringstream ss;
  search_path_join_impl(ss, paths);
  return ss.str();
}
/** // doc: search_path_join() {{{
 * \todo Write documentation
 */ // }}}
inline std::string
search_path_join(std::vector<std::string> const& paths, std::locale const& loc)
{
  std::stringstream ss;
  ss.imbue(loc);
  search_path_join_impl(ss, paths);
  return ss.str();
}
/** // doc: search_path_unique() {{{
 * \todo Write documentation
 */ // }}}
inline std::vector<std::string>
search_path_unique(std::vector<std::string> const& paths,
                   std::vector<std::string> const& exclude
                    = std::vector<std::string>())
{
  std::unordered_set<std::string> set(exclude.cbegin(), exclude.cend());
  std::vector<std::string> result;
  for(std::string const& path : paths)
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
inline std::vector<std::string>&
search_path_append(std::vector<std::string>& paths,
                   std::string const& str)
{
  std::vector<std::string> tmp( search_path_split(str) );
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_append() {{{
 * \todo Write documentation
 */ // }}}
inline std::vector<std::string>&
search_path_append(std::vector<std::string>& paths,
                   std::string const& str,
                   std::locale const& loc)
{
  std::vector<std::string> tmp( search_path_split(str, loc) );
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_prepend() {{{
 * \todo Write documentation
 */ // }}}
inline std::vector<std::string>&
search_path_prepend(std::vector<std::string>& paths,
                    std::string const& str)
{
  std::vector<std::string> tmp( search_path_split(str) );
  std::swap(tmp, paths);
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_prepend() {{{
 * \todo Write documentation
 */ // }}}
inline std::vector<std::string>&
search_path_prepend(std::vector<std::string>& paths,
                    std::string const& str,
                    std::locale const& loc)
{
  std::vector<std::string> tmp( search_path_split(str, loc) );
  std::swap(tmp, paths);
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_append_unique() {{{
 * \todo Write documentation
 */ // }}}
inline std::vector<std::string>&
search_path_append_unique(std::vector<std::string>& paths,
                          std::string const& str)
{
  std::vector<std::string> tmp( search_path_unique(search_path_split(str), paths) );
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_append_unique() {{{
 * \todo Write documentation
 */ // }}}
inline std::vector<std::string>&
search_path_append_unique(std::vector<std::string>& paths,
                          std::string const& str,
                          std::locale const& loc)
{
  std::vector<std::string> tmp( search_path_unique(search_path_split(str, loc), paths) );
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_prepend_unique() {{{
 * \todo Write documentation
 */ // }}}
inline std::vector<std::string>&
search_path_prepend_unique(std::vector<std::string>& paths,
                          std::string const& str)
{
  std::vector<std::string> tmp( search_path_unique(search_path_split(str), paths) );
  std::swap(tmp, paths);
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_prepend_unique() {{{
 * \todo Write documentation
 */ // }}}
inline std::vector<std::string>&
search_path_prepend_unique(std::vector<std::string>& paths,
                          std::string const& str,
                          std::locale const& loc)
{
  std::vector<std::string> tmp( search_path_unique(search_path_split(str, loc), paths) );
  std::swap(tmp, paths);
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_erase() {{{
 * \todo Write documentation
 */ // }}}
inline std::vector<std::string>&
search_path_erase(std::vector<std::string>& paths, std::string const& str)
{
  std::vector<std::string> seq(search_path_split(str));
  std::unordered_set<std::string> set(seq.cbegin(), seq.cend());
  auto f = [set](std::string const& s) { return set.find(s) != set.end(); };
  paths.erase(std::remove_if(paths.begin(), paths.end(), f), paths.end());
  return paths;
}
/** // doc: search_path_erase() {{{
 * \todo Write documentation
 */ // }}}
inline std::vector<std::string>&
search_path_erase(std::vector<std::string>& paths,
                  std::string const& str,
                  std::locale const& loc)
{
  std::vector<std::string> seq(search_path_split(str, loc));
  std::unordered_set<std::string> set(seq.cbegin(), seq.cend());
  auto f = [set](std::string const& s) { return set.find(s) != set.end(); };
  paths.erase(std::remove_if(paths.begin(), paths.end(), f), paths.end());
  return paths;
}
#if 0
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
