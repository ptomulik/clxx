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
#include <cstdlib>
#include <clxx/common/path.hpp>
#include <clxx/common/config.hpp>

namespace clxx {
/** \addtogroup clxx_util_search_path
 * @{ */
/** // doc: search_path {{{
 * \brief Typedef for search path string
 */ // }}}
typedef std::string search_path;
/** // doc: search_path {{{
 * \brief Typedef for search path strings
 */ // }}}
typedef std::vector<search_path> search_paths;
/** // doc: search_path_delimiter {{{
 * \brief Returns delimiter character used to split/join search path strings
 *
 * The returned character is OS-dependent. It will be <tt>':'</tt> on most
 * POSIX systems but, for example, <tt>';'</tt> on Windows.
 *
 * \returns
 *    The delimiter character
 */ // }}}
constexpr char
search_path_delimiter() noexcept
{
#ifdef CLXX_WINDOWS_API
  return ';';
#else
  return ':';
#endif
}
/** // doc: search_path_split_impl() {{{
 * \brief Implements the core of the #search_path_split()
 *
 * Internally, the function uses provided \c std::istream object \p is to
 * perform the operation. That way, the caller may provide \c std::istream
 * instance with custom locale imbued, or so.
 *
 * \param paths
 *    A mutable vector of search paths where the new search paths will be
 *    appended.
 * \param is
 *    Input stream used to perform the splitting operation.
 */ // }}}
inline void
search_path_split_impl(search_paths& paths, std::istream& is)
{
  constexpr char delim = search_path_delimiter();
  search_path path;
  while(!is.eof())
    {
      std::getline(is, path, delim);
      paths.push_back(path);
    }
}
/** // doc: search_path_split() {{{
 * \brief Splits search path string onto separate path strings
 *
 * This function just splits the input string \p str at the search path
 * delimiter (see #search_path_delimiter()) and returns the resultant 
 * vector of strings. The implementation uses \c std::stringstream with
 * unchanged locale to split the string.
 *
 * \param str
 *    The string to be split onto separate string. It should contain zero
 *    or more substrings (paths) separated by search path delimiter.
 *
 * \returns
 *    A vector of string resulting from spliting the \p str
 *
 * \par Example
 * This example is for POSIX system, on Windows use <tt>';'</tt> in place of
 * <tt>':'</tt>.
 * \code
 *    search_paths paths;
 *    paths = search_path_split("");              // -> {}
 *    paths = search_path_split(":");             // -> {"",""}
 *    paths = search_path_split("foo:");          // -> {"foo",""}
 *    paths = search_path_split(":bar");          // -> {"","bar"}
 *    paths = search_path_split("foo:bar");       // -> {"foo","bar"}
 * \endcode
 */ // }}}
inline search_paths
search_path_split(search_path const& str)
{
  search_paths paths;
  if(!str.empty())
    {
      std::stringstream ss(str);
      search_path_split_impl(paths, ss);
    }
  return paths;
}
/** // doc: search_path_split() {{{
 * \brief Splits search path string onto separate path strings
 *
 * This overloaded function works essentially same way as
 * \ref clxx::search_path_split(search_path const&), except that it allows to
 * provide a custom locale.
 *
 * \param path
 *    The path string to be split,
 * \param loc
 *    The locale object to be used when manipulating strings.
 *
 * \returns
 *    A vector of string resulting from spliting the \p str
 */ // }}}
inline search_paths
search_path_split(search_path const& str, std::locale const& loc)
{
  search_paths paths;
  if(!str.empty())
    {
      std::stringstream ss(str);
      ss.imbue(loc);
      search_path_split_impl(paths, ss);
    }
  return paths;
}
/** // doc: search_path_join_impl() {{{
 * \brief Implements internals of the #search_path_join() function
 *
 * Internally, the function uses provided \c std::ostream object \p os to
 * perform the operation. That way, the caller may provide \c std::ostream
 * instance with custom locale imbued, or so.
 *
 * \param os
 *    A mutable reference to \c std::ostream object used to implement the
 *    operation.
 * \param paths
 *    A vector of search paths that are to be joined.
 */ // }}}
inline void
search_path_join_impl(std::ostream& os, search_paths const& paths)
{
  if(!paths.empty())
    {
      const char delim = search_path_delimiter();
      auto it = paths.begin();
      os << *it++;
      while(it != paths.end())
        os << delim << *it++;
    }
}
/** // doc: search_path_join() {{{
 * \brief Join multiple search path strings using search path delimiter
 *
 * \param paths
 *    A vector of search paths to be joined
 *
 * \returns
 *    The resultant string.
 *
 * \par Example
 * This example is for POSIX system, on Windows use <tt>';'</tt> in place of
 * <tt>':'</tt>.
 * \code
 *    search_path str;
 *    str = search_path_join({});              // -> ""
 *    str = search_path_join({"", ""});        // -> ":"
 *    str = search_path_join({"foo",""});      // -> "foo:"
 *    str = search_path_join({"","bar");       // -> ":bar"
 *    str = search_path_join({"foo","bar"});   // -> "foo:bar"
 * \endcode
 */ // }}}
inline search_path
search_path_join(search_paths const& paths)
{
  std::stringstream ss;
  search_path_join_impl(ss, paths);
  return ss.str();
}
/** // doc: search_path_join() {{{
 * \brief Join multiple search path strings using search path delimiter
 *
 * This overloaded function works essentially same way as
 * \ref clxx::search_path_split(search_paths const&), except that it allows to
 * provide a custom locale object.
 *
 * \param paths
 *    The paths strings to be joined
 * \param loc
 *    The locale object to be used when manipulating strings
 *
 * \returns
 *    The resultant string.
 */ // }}}
inline search_path
search_path_join(search_paths const& paths, std::locale const& loc)
{
  std::stringstream ss;
  ss.imbue(loc);
  search_path_join_impl(ss, paths);
  return ss.str();
}
/** // doc: search_path_unique() {{{
 * \brief Remove repeating strings from the \p paths
 *
 * After this operation, each string that appeared in \p paths, appears in the
 * resultant strings at most once. Strings provided in \p exclude are excluded
 * from the resultant strings. First occurrence of a given string determines 
 * its position in the resultant strings.
 *
 * \param paths
 *    Input strings,
 * \param exclude
 *    Additional strings that will be excluded from the resultant strings.
 *
 * \returns
 *    Result of the filtering
 *
 * \par Example
 * \code
 *  search_paths paths{ "/foo1/bar1", "/foo2/bar2", "/foo1/bar1", "/foo3/bar3" };
 *  search_paths result(search_path_unique(paths, search_paths{ "/foo3/bar3" }));
 *
 *  assert(result.size() == 2ul);
 *  assert(result[0] == "/foo1/bar1");
 *  assert(result[1] == "/foo2/bar2");
 * \endcode
 */ // }}}
inline search_paths
search_path_unique(search_paths const& paths,
                   search_paths const& exclude = search_paths())
{
  std::unordered_set<search_path> set(exclude.cbegin(), exclude.cend());
  search_paths result;
  for(search_path const& path : paths)
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
 * \brief Append to path strings
 * 
 * \param paths
 *    Reference to mutable vector of path strings. This vector will be modified
 *    by the function,
 * \param newpaths
 *    A path strings to be appended to the \p paths.
 *
 * \returns
 *    Mutable reference to (modified) \p paths
 *
 * \par Example
 * \code
 *  search_paths paths{ "/foo1/bar1", "/foo2/bar2" };
 *  search_paths& result = search_path_append(paths, {"/foo3/bar3","/foo4/bar4"});
 *
 *  assert(&result == &paths);
 *  assert(result.size() == 4ul);
 *  assert(result[0] == "/foo1/bar1");
 *  assert(result[1] == "/foo2/bar2");
 *  assert(result[2] == "/foo3/bar3");
 *  assert(result[3] == "/foo4/bar4");
 * \endcode
 *
 */ // }}}
inline search_paths&
search_path_append(search_paths& paths, search_paths const& newpaths)
{
  paths.insert(paths.end(), newpaths.begin(), newpaths.end());
  return paths;
}
/** // doc: search_path_prepend() {{{
 * \brief Prepend to path strings
 * 
 * \param paths
 *    Reference to mutable vector of path strings. This vector will be modified
 *    by the function,
 * \param newpaths
 *    A path strings to be prepended to the \p paths.
 *
 * \returns
 *    Mutable reference to (modified) \p paths
 *
 * \par Example
 * \code
 *  search_paths paths{ "/foo1/bar1", "/foo2/bar2" };
 *  search_paths& result = search_path_prepend(paths, {"/foo3/bar3","/foo4/bar4"});
 *
 *  assert(&result == &paths);
 *  assert(result.size() == 4ul);
 *  assert(result[0] == "/foo3/bar3");
 *  assert(result[1] == "/foo4/bar4");
 *  assert(result[2] == "/foo1/bar1");
 *  assert(result[3] == "/foo2/bar2");
 * \endcode
 *
 */ // }}}
inline search_paths&
search_path_prepend(search_paths& paths, search_paths const& newpaths)
{
  search_paths tmp( newpaths );
  std::swap(tmp, paths);
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_append_unique() {{{
 * \brief Append unique strings to path strings
 *
 * Appends new path strings from \p newpaths that are not present in \p paths.
 * If a string path appears several times in \p newpaths, it will be appended
 * at most once.
 *
 * \param paths
 *    Reference to mutable vector of path strings. This vector will be modified
 *    by the function,
 * \param newpaths
 *    A candidate strings to be appended to the \p paths.
 *
 * \returns
 *    Mutable reference to (modified) \p paths.
 *
 * \par Example
 * \code
 *  search_paths paths{ "/foo1/bar1", "/foo2/bar2" };
 *  search_paths& result = search_path_append_unique(paths, {"/foo3/bar3", "/foo2/bar2", "/foo3/bar3"});
 *
 *  assert(&result == &paths);
 *  assert(result.size() == 3ul);
 *  assert(result[0] == "/foo1/bar1");
 *  assert(result[1] == "/foo2/bar2");
 *  assert(result[2] == "/foo3/bar3");
 * \endcode
 */ // }}}
inline search_paths&
search_path_append_unique(search_paths& paths, search_paths const& newpaths)
{
  search_paths tmp( search_path_unique(newpaths, paths) );
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_prepend_unique() {{{
 * \brief Prepend unique strings to path strings
 *
 * Prepends new path strings from \p newpaths that are not present in \p paths.
 * If a string appears several times in \p newpaths, it will be prepended
 * at most once.
 *
 * \param paths
 *    Reference to mutable vector of path strings. This vector will be modified
 *    by the function,
 * \param newpaths
 *    A candidate strings to be prepended to the \p paths.
 *
 * \returns
 *    Mutable reference to (modified) \p paths.
 *
 * \par Example
 * \code
 *  search_paths paths{ "/foo1/bar1", "/foo2/bar2" };
 *  search_paths& result = search_path_prepend_unique(paths, {"/foo3/bar3", "/foo2/bar2", "/foo3/bar3"});
 *
 *  assert(&result == &paths);
 *  assert(result.size() == 3ul);
 *  assert(result[0] == "/foo3/bar3");
 *  assert(result[1] == "/foo1/bar1");
 *  assert(result[2] == "/foo2/bar2");
 * \endcode
 */ // }}}
inline search_paths&
search_path_prepend_unique(search_paths& paths, search_paths const& newpaths)
{
  search_paths tmp( search_path_unique(newpaths, paths) );
  std::swap(tmp, paths);
  paths.insert(paths.end(), tmp.begin(), tmp.end());
  return paths;
}
/** // doc: search_path_erase_set() {{{
 * \brief Remove from \p paths all the occurrences of strings listed in \p rm
 *
 * \param paths
 *    Reference to mutable vector of path strings. This vector will be modified
 *    by the function,
 * \param rm
 *    An unordered set of strings to be removed from \p paths.
 *
 * \returns
 *    Mutable reference to (modified) \p paths.
 */ // }}}
inline search_paths&
search_path_erase_set(search_paths& paths, std::unordered_set<search_path> const& rm)
{
  auto f = [rm](search_path const& s) { return rm.find(s) != rm.end(); };
  paths.erase(std::remove_if(paths.begin(), paths.end(), f), paths.end());
  return paths;
}
/** // doc: search_path_erase() {{{
 * \brief Remove from \p paths all the occurrences of strings listed in \p rm
 *
 * \param paths
 *    Reference to mutable vector of path strings. This vector will be modified
 *    by the function,
 * \param rm
 *    A vector of path strings to be removed from \p paths.
 *
 * \returns
 *    Mutable reference to (modified) \p paths.
 *
 * \par Example
 * \code
 *  search_paths paths{ "/foo1/bar1", "/foo2/bar2", "/foo3/bar3", "/foo2/bar2", "/foo4/bar4"};
 *  search_paths const& pref = search_path_erase(paths, { "/foo2/bar2", "/foo4/bar4" });
 *  assert(&pref == &paths);
 *  assert(paths.size() == 2ul);
 *  assert(paths[0] == "/foo1/bar1");
 *  assert(paths[1] == "/foo3/bar3");
 * \endcode
 */ // }}}
inline search_paths&
search_path_erase(search_paths& paths, search_paths const& rm)
{
  std::unordered_set<search_path> set(rm.cbegin(), rm.cend());
  return search_path_erase_set(paths,set);
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
/** @} */
} // end namespace clxx

#endif /* CLXX_COMMON_SEARCH_PATH_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
