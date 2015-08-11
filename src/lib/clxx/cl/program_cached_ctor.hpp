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
  /** // doc: create_default_search_paths() {{{
   * \todo Write documentation
   */ // }}}
  static std::vector<std::string> create_default_search_path();
  /** // doc: get_shared_search_paths() {{{
   * \brief Returns mutable reference to shared (among threads) singleton
   *        search path vector
   *
   * The instance is created first time the function is invoked and is
   * initialized with #create_default_search_path(). The initialization is
   * thread-safe according to C++11 standard, but further usage may lead to
   * race conditions if the access to shared path is not appropriately
   * synchronized by the application.
   */ // }}}
  static std::vector<std::string>& get_shared_search_path();
  /** // doc: get_local_search_paths() {{{
   * \brief Returns mutable reference to thread-local singleton search path
   *        vector
   *
   * The instance is created first time the function is invoked and is
   * initialized with #create_default_search_path().
   */ // }}}
  static std::vector<std::string>& get_local_search_path();
  /** // doc: get_current_search_paths() {{{
   * \brief Returns a mutable reference to current singleton instance of a
   *        search path vector
   *
   * The internal pointer used by #get_current_search_path() is maintained on
   * thread-local storage. It may point to either thread-local instance
   * (#get_local_search_path()) of search path vector or to the shared instance
   * (#get_shared_search_path()). By default it points to the shared instance.
   */ // }}}
  static std::vector<std::string>& get_current_search_path();
  /** // doc: use_shared_search_path() {{{
   * \brief Set current path pointer (returned by #get_current_path()) to the
   *        shared (among threads) singleton search path vector
   */ // }}}
  static void use_shared_search_path();
  /** // doc: use_local_search_path() {{{
   * \brief Set current path pointer (returned by #get_current_path()) to the
   *        thread-local singleton search path vector
   */ // }}}
  static void use_local_search_path();
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
