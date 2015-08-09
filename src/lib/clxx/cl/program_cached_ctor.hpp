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
#include <string>
#include <vector>
#include <locale>

namespace clxx {
/** // doc: program_cached_ctor {{{
 * \todo Write documentation
 */ // }}}
class program_cached_ctor
  : public program_with_source_ctor
{
private:
  static thread_local std::vector<std::string>* _current_search_path;
public:
  /** // doc: get_default_search_paths() {{{
   * \todo Write documentation
   */ // }}}
  static std::vector<std::string> get_default_search_path();
  /** // doc: get_shared_search_paths() {{{
   * \todo Write documentation
   */ // }}}
  static std::vector<std::string>& get_shared_search_path();
  /** // doc: get_current_search_paths() {{{
   * \todo Write documentation
   */ // }}}
  static std::vector<std::string>& get_current_search_path();
  /** // doc: get_local_search_paths() {{{
   * \todo Write documentation
   */ // }}}
  static std::vector<std::string>& get_local_search_path();
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
