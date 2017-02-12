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
 * \ingroup clxx_runtime
 * \brief Thread-local reference to "current" \ref clxx::runtime "runtime"
 *
 * The current runtime is a reference pointing to a distinguished
 * \ref clxx::runtime "runtime" object. The \ref clxx::current_runtime "current_runtime"
 * is a specialization of the \ref clxx::current_instance "current_instance"
 * for the \ref clxx::runtime "runtime" class.
 *
 * Quick guide:
 *
 * - use \ref current_runtime::get() to retrieve the current runtime reference,
 * - use \ref current_runtime::bind_static_instance() to bind shared
 *   \ref clxx::runtime "runtime" (shared between threads) to the current
 *   runtime reference,
 * - use \ref current_runtime::bind_thread_instance() to bind thread local
 *   \ref clxx::runtime "runtime" to the current runtime reference,
 * - use \ref current_runtime::bind_custom_instance() to bind user-provided
 *   runtime object to the current runtime reference,
 * - use \ref current_runtime::binding() to check what is currently bound to
 *   the current runtime reference.
 *
 */ // }}}
class current_runtime
  : public detail::current_instance<current_runtime, runtime>
{ };
} // end namespace clxx


#endif /* CLXX_CL_CURRENT_RUNTIME_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
