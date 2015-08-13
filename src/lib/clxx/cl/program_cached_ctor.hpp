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
#include <clxx/common/config.hpp>
#include <string>
#include <locale>

namespace clxx {

enum class
singleton_storage_t
{
  none,
  global,
  thread
};

/** // doc: program_cached_ctor {{{
 * \todo Write documentation
 */ // }}}
class program_cached_ctor
  : public program_with_source_ctor
{
public:
  /** // doc: codecvt_type {{{
   * \todo Write documentation
   */ // }}}
  typedef std::codecvt<wchar_t, char, std::mbstate_t> codecvt_type;
  /** // doc: codecvt_result {{{
   * \todo Write documentation
   */ // }}}
  typedef std::codecvt_base::result codecvt_result;
public:
  /** // doc: use_current_search_path_storage() {{{
   * \brief Set current path pointer (returned by #get_current_path()) to the
   *        shared (among threads) singleton search path vector
   */ // }}}
  static void current_search_path_use_storage(singleton_storage_t storage);
  /** // doc: current_search_path_storage() {{{
   * \brief Set current path pointer (returned by #get_current_path()) to the
   *        shared (among threads) singleton search path vector
   */ // }}}
  static singleton_storage_t current_search_path_storage();
#ifdef CLXX_WINDOWS_API
  /** // doc: get_current_search_path() {{{
   * \todo Write documentation
   */ // }}}
  static codecvt_result get_current_search_path(std::string& out, codecvt_type const& cvt);
  /** // doc: get_current_search_path() {{{
   * \todo Write documentation
   */ // }}}
  static void get_current_search_path(std::wstring& out);
  /** // doc: set_current_search_path() {{{
   * \todo Write documentation
   */ // }}}
  static codecvt_result set_current_search_path(std::string const& in, codecvt_type const& cvt);
  /** // doc: set_current_search_path() {{{
   * \todo Write documentation
   */ // }}}
  static void set_current_search_path(std::wstring const& in);
#else
  /** // doc: get_current_search_path() {{{
   * \todo Write documentation
   */ // }}}
  static void get_current_search_path(std::string& out);
  /** // doc: get_current_search_path() {{{
   * \todo Write documentation
   */ // }}}
  static codecvt_result get_current_search_path(std::wstring& out, codecvt_type const& cvt);
  /** // doc: set_current_search_path() {{{
   * \todo Write documentation
   */ // }}}
  static void set_current_search_path(std::string const& in);
  /** // doc: set_current_search_path() {{{
   * \todo Write documentation
   */ // }}}
  static codecvt_result set_current_search_path(std::wstring const& in, codecvt_type const& cvt);
#endif
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
