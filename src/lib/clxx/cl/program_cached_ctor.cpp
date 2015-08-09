// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_cached_ctor.cpp {{{
 * \file clxx/cl/program_cached_ctor.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_cached_ctor.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/common/sha1.hpp>
#include <boost/locale.hpp>
#include <unordered_set>

namespace clxx {
clxx::program program_cached_ctor::
operator()(clxx::context const& context, clxx::program_sources const& sources) const
{
  return this->program_with_source_ctor::operator()(context, sources);
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
