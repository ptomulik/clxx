// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_with_source_ctor.cpp {{{
 * \file clxx/cl/program_with_source_ctor.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_with_source_ctor.hpp>
#include <clxx/cl/program.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
program_with_source_ctor::
~program_with_source_ctor()
{
}
/* ----------------------------------------------------------------------- */
clxx::program program_with_source_ctor::
operator()(clxx::context const& context, clxx::program_sources const& sources) const
{
  return clxx::program(context, sources);
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
