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

namespace clxx {
/* ----------------------------------------------------------------------- */
constexpr program_cached_ctor::wide_char_t
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
_add_path(program_cached_ctor::path_set_t& path_set, std::wstring const& wpath)
{
  for(size_t beg = 0ul, end; beg < wpath.size(); beg = end+1)
    {
      end = wpath.find(_pathsep(), beg);
      program_cached_ctor::wide_string_t s { wpath.substr(beg, end-beg) };
      if(!s.empty())
        {
          path_set.insert(s);
        }
    }
}
/* ----------------------------------------------------------------------- */
static size_t
_remove_path(program_cached_ctor::path_set_t& path_set, std::wstring const& wpath)
{
  size_t n = 0ul;
  for(size_t beg = 0ul, end; beg < wpath.size(); beg = end+1)
    {
      end = wpath.find(_pathsep(), beg);
      program_cached_ctor::wide_string_t s { wpath.substr(beg, end-beg) };
      if(!s.empty())
        {
          n += path_set.erase(s);
        }
    }
  return n;
}
/* ----------------------------------------------------------------------- */
thread_local program_cached_ctor::path_set_t program_cached_ctor::_default_cache_path;
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
add_default_cache_path(std::wstring const& wpath)
{
  _add_path(_default_cache_path, wpath);
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
add_default_cache_path(std::string const& path, std::string const& charset)
{
  using boost::locale::conv::to_utf;
  add_default_cache_path(to_utf<wide_char_t>(path, charset) );
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
add_default_cache_path(std::string const& path, std::locale const& locale)
{
  using boost::locale::conv::to_utf;
  add_default_cache_path(to_utf<wide_char_t>(path, locale) );
}
/* ----------------------------------------------------------------------- */
size_t program_cached_ctor::
remove_default_cache_path(std::wstring const& wpath)
{
  return _remove_path(_default_cache_path, wpath);
}
/* ----------------------------------------------------------------------- */
size_t program_cached_ctor::
remove_default_cache_path(std::string const& path, std::string const& charset)
{
  using boost::locale::conv::to_utf;
  return _default_cache_path.erase(to_utf<wide_char_t>(path, charset) );
}
/* ----------------------------------------------------------------------- */
size_t program_cached_ctor::
remove_default_cache_path(std::string const& path, std::locale const& locale)
{
  using boost::locale::conv::to_utf;
  return _default_cache_path.erase(to_utf<wide_char_t>(path, locale) );
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
clear_default_cache_path()
{
  _default_cache_path.clear();
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
