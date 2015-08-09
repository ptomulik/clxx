// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/path.hpp

/** // doc: clxx/common/path.hpp {{{
 * \file clxx/common/path.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMON_PATH_HPP_INCLUDED
#define CLXX_COMMON_PATH_HPP_INCLUDED

#include <string>
#include <clxx/common/config.hpp>

namespace clxx {
/** // doc: path_separator() {{{
 * \brief Returns the preferred path separator for the current operating system
 */ // }}}
constexpr char
path_separator()
{
#ifdef CLXX_WINDOWS_API
  return '\\';
#else
  return '/';
#endif
}
/** // doc: path_join() {{{
 * \brief Join two strings using #path_separator() to form a new path
 *
 * \param p1
 *    First string.
 * \param p2
 *    Second string.
 * \returns
 *    A string with the result of concatenation.
 */ // }}}
inline std::string
path_join(std::string const& p1, std::string const& p2)
{
  std::string path(p1);
  constexpr char sep = path_separator();
  if(!p2.empty())
    {
      while(!path.empty() && path.back() == sep)
        {
          path.erase(path.end()-1);
        }
      if(!p1.empty() && p2.front() != sep)
        path += sep;
    }
  path += p2;
  return path;
}
} // end namespace clxx

#endif /* CLXX_COMMON_PATH_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
