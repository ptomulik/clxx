// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/current_runtime.hpp

/** // doc: clxx/cl/current_runtime.hpp {{{
 * \file clxx/cl/current_runtime.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_CURRENT_RUNTIME_HPP_INCLUDED
#define CLXX_CL_CURRENT_RUNTIME_HPP_INCLUDED

#include <clxx/cl/runtime.hpp>
#include <clxx/common/current_instance.hpp>
#include <clxx/common/detail/current_instance.hpp>

namespace clxx {
/** // doc: current_runtime {{{
 * \todo Write documentation
 */ // }}}
class current_runtime
  : public detail::current_instance<current_runtime, runtime>
{ };
} // end namespace clxx


#endif /* CLXX_CL_CURRENT_RUNTIME_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
