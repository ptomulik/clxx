// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_cached_ctor.cpp {{{
 * \file clxx/cl/program_cached_ctor.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_cached_ctor.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/common/config.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/common/detail/search_path.hpp>
#include <clxx/common/detail/locale.hpp>

namespace clxx { namespace {
/* ----------------------------------------------------------------------- */
std::vector<detail::path_string>
default_search_path()
{
  std::vector<detail::path_string> paths;
  const char* env;
#ifdef CLXX_WINDOWS_API  
  // TODO: implement default search path for windows
  (void)env;
#else
  if((env = std::getenv("HOME")) != nullptr)
    {
      paths.push_back(detail::path_join(std::vector<detail::path_string>{ env, ".clxx/program_cache" }));
      //paths.push_back(boost::algorithm::join(std::vector<std::string>{ env, ".clxx/program_cache" }, ":"));
    }
#endif
  if((env = std::getenv("CLXX_PROGRAM_CACHE_PATH")) != nullptr)
    {
      std::vector<detail::path_string> pieces;
      detail::search_path_prepend(paths, detail::search_path_split(pieces, env));
    }
  return paths;
}
/* ----------------------------------------------------------------------- */
std::vector<detail::path_string>&
global_search_path()
{
  static std::vector<detail::path_string> r(default_search_path());
  return r;
}
/* ----------------------------------------------------------------------- */
std::vector<detail::path_string>&
thread_search_path()
{
  thread_local std::vector<detail::path_string> r(global_search_path());
  return r;
}
/* ----------------------------------------------------------------------- */
thread_local clxx::singleton_storage_t _current_search_path_storage = clxx::singleton_storage_t::none;
/* ----------------------------------------------------------------------- */
std::vector<detail::path_string>&
current_search_path()
{
  switch(_current_search_path_storage)
    {
      default:
        _current_search_path_storage = clxx::singleton_storage_t::global;
      case clxx::singleton_storage_t::global:
        return global_search_path();
      case clxx::singleton_storage_t::thread:
        return thread_search_path();
    }
}
/* ----------------------------------------------------------------------- */
} } // end namespace clxx::{anonymous}

namespace clxx {
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
current_search_path_use_storage(singleton_storage_t storage)
{
  switch(storage)
    {
      case singleton_storage_t::global:
      case singleton_storage_t::thread:
        _current_search_path_storage = storage;
        break;
      default:
        throw invalid_argument_error();
    }
}
/* ----------------------------------------------------------------------- */
singleton_storage_t program_cached_ctor::
current_search_path_storage()
{
  return _current_search_path_storage;
}
#ifdef CLXX_WINDOWS_API
/* ----------------------------------------------------------------------- */
program_cached_ctor::codecvt_result  program_cached_ctor::
get_current_search_path(std::string& out, codecvt_type const& cvt)
{
  return detail::convert(detail::search_path_join(current_search_path()), out, cvt);
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
get_current_search_path(std::wstring& out)
{
  out = detail::search_path_join(current_search_path());
}
/* ----------------------------------------------------------------------- */
program_cached_ctor::codecvt_result  program_cached_ctor::
set_current_search_path(std::string const& in, codecvt_type const& cvt)
{
  std::wstring tmp;
  codecvt_result result = detail::convert(in, tmp, cvt);
  if(result == codecvt_result::ok)
    set_current_search_path(tmp);
  return result;
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
set_current_search_path(std::wstring const& in)
{
  detail::search_path_split(current_search_path(), in);
}
/* ----------------------------------------------------------------------- */
#else
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
get_current_search_path(std::string& out)
{
  out = detail::search_path_join(current_search_path());
}
/* ----------------------------------------------------------------------- */
program_cached_ctor::codecvt_result  program_cached_ctor::
get_current_search_path(std::wstring& out, codecvt_type const& cvt)
{
  return detail::convert(detail::search_path_join(current_search_path()), out, cvt);
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
set_current_search_path(std::string const& in)
{
  detail::search_path_split(current_search_path(), in);
}
/* ----------------------------------------------------------------------- */
program_cached_ctor::codecvt_result  program_cached_ctor::
set_current_search_path(std::wstring const& in, codecvt_type const& cvt)
{
  std::string tmp;
  codecvt_result result = detail::convert(in, tmp, cvt);
  if(result == codecvt_result::ok)
    set_current_search_path(tmp);
  return result;
}
/* ----------------------------------------------------------------------- */
#endif
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
