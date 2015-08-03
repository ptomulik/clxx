// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_with_source_ctor.hpp

/** // doc: clxx/cl/program_with_source_ctor.hpp {{{
 * \file clxx/cl/program_with_source_ctor.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_PROGRAM_WITH_SOURCE_CTOR_HPP_INCLUDED
#define CLXX_CL_PROGRAM_WITH_SOURCE_CTOR_HPP_INCLUDED

#include <clxx/cl/context_fwd.hpp>
#include <clxx/cl/program_fwd.hpp>
#include <clxx/common/program_sources.hpp>

namespace clxx {
/** // doc: program_with_source_ctor {{{
 * \todo Write documentation
 */ // }}}
class program_with_source_ctor
{
public:
  /** // doc: ~program_with_source_ctor() {{{
   * \brief Destructor
   */ // }}}
  virtual ~program_with_source_ctor();
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  virtual clxx::program operator()(clxx::context const& context, clxx::program_sources const& sources) const;
};
} // end namespace clxx

#endif /* CLXX_CL_PROGRAM_WITH_SOURCE_CTOR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
