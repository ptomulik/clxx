// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/x10d/program_cached_ctor.hpp

/** // doc: clxx/x10d/program_cached_ctor.hpp {{{
 * \file clxx/x10d/program_cached_ctor.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_X10D_PROGRAM_CACHED_CTOR_HPP_INCLUDED
#define CLXX_X10D_PROGRAM_CACHED_CTOR_HPP_INCLUDED

#include <clxx/x10d/program_with_source_ctor.hpp>
#include <clxx/cl/context_fwd.hpp>
#include <clxx/common/program_sources.hpp>
#include <clxx/common/current_instance.hpp>
#include <clxx/common/config.hpp>
#include <string>
#include <locale>

namespace clxx {
/** // doc: program_cached_ctor {{{
 * \ingroup clxx_x10d
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

#endif /* CLXX_X10D_PROGRAM_CACHED_CTOR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
