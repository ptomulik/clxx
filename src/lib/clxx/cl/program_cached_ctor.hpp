// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_cached_ctor.hpp

/** // doc: clxx/cl/program_cached_ctor.hpp {{{
 * \file clxx/cl/program_cached_ctor.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_PROGRAM_CACHED_CTOR_HPP_INCLUDED
#define CLXX_CL_PROGRAM_CACHED_CTOR_HPP_INCLUDED

#include <clxx/cl/program_with_source_ctor.hpp>
#include <clxx/cl/context_fwd.hpp>
#include <clxx/common/program_sources.hpp>
#include <clxx/common/shared_ptr.hpp>
#include <string>
#include <set>
#include <locale>

namespace clxx {
/** // doc: program_cached_ctor {{{
 * \todo Write documentation
 */ // }}}
class program_cached_ctor
  : public program_with_source_ctor
{
public:
  typedef wchar_t wide_char_t;
  typedef std::basic_string<wide_char_t> wide_string_t;
  typedef std::set<wide_string_t> path_set_t;
private:
  static thread_local path_set_t _default_cache_path;
  path_set_t _cache_path;
public:
  /** // doc: add_default_cache_path() {{{
   * \todo Write documentation
   */ // }}}
  static void add_default_cache_path(std::wstring const& wpath);
  /** // doc: add_default_cache_path() {{{
   * \todo Write documentation
   */ // }}}
  static void add_default_cache_path(std::string const& path,
                                     std::string const& charset = "UTF-8");
  /** // doc: add_default_cache_path() {{{
   * \todo Write documentation
   */ // }}}
  static void add_default_cache_path(std::string const& path,
                                     std::locale const& locale = std::locale());
  /** // doc: remove_default_cache_path() {{{
   * \todo Write documentation
   */ // }}}
  static size_t remove_default_cache_path(std::wstring const& wpath);
  /** // doc: remove_default_cache_path() {{{
   * \todo Write documentation
   */ // }}}
  static size_t remove_default_cache_path(std::string const& path,
                                          std::string const& charset = "UTF-8");
  /** // doc: remove_default_cache_path() {{{
   * \todo Write documentation
   */ // }}}
  static size_t remove_default_cache_path(std::string const& path,
                                          std::locale const& locale = std::locale());
  /** // doc: clear_default_cache_path() {{{
   * \todo Write documentation
   */ // }}}
  static void clear_default_cache_path();
public:
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  virtual clxx::program operator()(clxx::context const& context,
                                   clxx::program_sources const& sources) const;
};
} // end namespace clxx

#endif /* CLXX_CL_PROGRAM_CACHED_CTOR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
