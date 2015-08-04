// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_cached_ctor.cpp {{{
 * \file clxx/cl/program_cached_ctor.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_cached_ctor.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/common/sha1.hpp>
#include <boost/locale.hpp>
#include <unordered_set>

namespace clxx {
/* ----------------------------------------------------------------------- */
constexpr program_cached_ctor::path_wchar_t
_pathsep() noexcept
{
#ifdef _WIN32
  return L';';
#else
  return L':';
#endif
}
/* ----------------------------------------------------------------------- */
static void
_add_path(program_cached_ctor::path_set_t& path_set,
          program_cached_ctor::path_wstring_t const& wpath)
{
  std::unordered_set<program_cached_ctor::path_wstring_t> unique_paths(path_set.cbegin(), path_set.cend());
  for(size_t beg = 0ul, end; beg < wpath.size(); beg = end + (end < wpath.size()))
    {
      end = wpath.find(_pathsep(), beg);
      if(beg < end)
        {
          program_cached_ctor::path_wstring_t s { wpath.substr(beg, end-beg) };
          if(unique_paths.find(s) == unique_paths.end())
            {
              unique_paths.insert(s);
              path_set.push_back(s);
            }
        }
    }
}
/* ----------------------------------------------------------------------- */
static void 
_remove_path(program_cached_ctor::path_set_t& path_set,
             program_cached_ctor::path_wstring_t const& wpath)
{
  for(size_t beg = 0ul, end; beg < wpath.size(); beg = end + (end < wpath.size()))
    {
      end = wpath.find(_pathsep(), beg);
      if(end == beg) break;
      program_cached_ctor::path_wstring_t s { wpath.substr(beg, end-beg) };
      path_set.erase(std::remove(path_set.begin(), path_set.end(), s), path_set.end());
    }
}
/* ----------------------------------------------------------------------- */
static program_cached_ctor::path_wstring_t
_get_path(program_cached_ctor::path_set_t const& path_set)
{
  program_cached_ctor::path_wstring_t wpath;
  auto it = path_set.cbegin();
  if(it != path_set.cend())
    {
      wpath.append(*it);
      for(++it; it != path_set.cend(); ++it)
        {
          wpath += _pathsep();
          wpath.append(*it);
        }
    }
  return wpath;
}
#if 0
/* ----------------------------------------------------------------------- */
static program_cached_ctor::path_wstring_t
_search_in_path_set(program_cached_ctor::path_set_t const& path_set,
                    program_cached_ctor::path_wstring_t const& wpath)
{
}
#endif
/* ----------------------------------------------------------------------- */
thread_local program_cached_ctor::path_set_t program_cached_ctor::_default_cache_path;
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
append_default_cache_wpath(path_wstring_t const& wpath)
{
  _add_path(_default_cache_path, wpath);
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
append_default_cache_path(std::string const& path, std::string const& charset)
{
  using boost::locale::conv::to_utf;
  append_default_cache_wpath(to_utf<path_wchar_t>(path, charset) );
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
append_default_cache_path(std::string const& path, std::locale const& locale)
{
  using boost::locale::conv::to_utf;
  append_default_cache_wpath(to_utf<path_wchar_t>(path, locale) );
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
remove_default_cache_wpath(path_wstring_t const& wpath)
{
  _remove_path(_default_cache_path, wpath);
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
remove_default_cache_path(std::string const& path, std::string const& charset)
{
  using boost::locale::conv::to_utf;
  remove_default_cache_wpath(to_utf<path_wchar_t>(path, charset) );
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
remove_default_cache_path(std::string const& path, std::locale const& locale)
{
  using boost::locale::conv::to_utf;
  remove_default_cache_wpath(to_utf<path_wchar_t>(path, locale) );
}
/* ----------------------------------------------------------------------- */
program_cached_ctor::path_wstring_t program_cached_ctor::
get_default_cache_wpath()
{
  return _get_path(_default_cache_path);
}
/* ----------------------------------------------------------------------- */
std::string program_cached_ctor::
get_default_cache_path(std::string const& charset)
{
  using boost::locale::conv::from_utf;
  return from_utf(get_default_cache_wpath(), charset);
}
/* ----------------------------------------------------------------------- */
std::string program_cached_ctor::
get_default_cache_path(std::locale const& locale)
{
  using boost::locale::conv::from_utf;
  return from_utf(get_default_cache_wpath(), locale);
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
clear_default_cache_path()
{
}
/* ----------------------------------------------------------------------- */
clxx::program program_cached_ctor::
operator()(clxx::context const& context, clxx::program_sources const& sources) const
{
  return this->program_with_source_ctor::operator()(context, sources);
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
