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

namespace clxx {
/** // doc: program_cached_ctor {{{
 * \todo Write documentation
 */ // }}}
class program_cached_ctor
  : public program_with_source_ctor
{
private:
  static thread_local std::vector<std::string> _default_cache_search_paths;
  std::vector<std::string> _cache_search_paths;
public:
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
