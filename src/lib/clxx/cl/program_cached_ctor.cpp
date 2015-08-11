// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_cached_ctor.cpp {{{
 * \file clxx/cl/program_cached_ctor.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_cached_ctor.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/common/search_path.hpp>
//#include <clxx/common/detail/sha1.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
thread_local std::vector<std::string>* program_cached_ctor::
_current_search_path = nullptr;
/* ----------------------------------------------------------------------- */
std::vector<std::string> program_cached_ctor::
create_default_search_path()
{
  std::vector<std::string> paths;
  const char* env;
#ifdef CLXX_WINDOWS_API  
  // TODO: implement default search path for windows
#else
  if((env = std::getenv("HOME")) != nullptr)
    {
      paths.push_back(path_join(env,".clxx/program_cache"));
    }
#endif
  if((env = std::getenv("CLXX_PROGRAM_CACHE_PATH")) != nullptr)
    {
      search_path_prepend(paths, search_path_split(env));
    }
  return paths;
}
/* ----------------------------------------------------------------------- */
std::vector<std::string>& program_cached_ctor::
get_shared_search_path()
{
  static std::vector<std::string> r(create_default_search_path());
  return r;
}
/* ----------------------------------------------------------------------- */
std::vector<std::string>& program_cached_ctor::
get_local_search_path()
{
  thread_local std::vector<std::string> r(create_default_search_path());
  return r;
}
/* ----------------------------------------------------------------------- */
std::vector<std::string>& program_cached_ctor::
get_current_search_path()
{
  if(!_current_search_path)
    _current_search_path = &get_shared_search_path();
  return *_current_search_path;
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
use_shared_search_path()
{
  _current_search_path = &get_shared_search_path();
}
/* ----------------------------------------------------------------------- */
void program_cached_ctor::
use_local_search_path()
{
  _current_search_path = &get_local_search_path();
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
