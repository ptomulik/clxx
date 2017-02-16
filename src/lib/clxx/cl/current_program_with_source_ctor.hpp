// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/current_program_with_source_ctor.hpp

/** // doc: clxx/cl/current_program_with_source_ctor.hpp {{{
 * \file clxx/cl/current_program_with_source_ctor.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_CURRENT_PROGRAM_CTOR_HPP_INCLUDED
#define CLXX_CL_CURRENT_PROGRAM_CTOR_HPP_INCLUDED

#include <clxx/cl/program_with_source_ctor.hpp>
#include <clxx/cl/program_cached_ctor.hpp>
#include <clxx/common/current_instance.hpp>
#include <clxx/common/detail/current_instance.hpp>

namespace clxx {
/** // doc: current_program_with_source_ctor {{{
 * \ingroup clxx_program_with_source_ctor
 * \brief Thread-local reference to "current" \ref clxx::program_with_source_ctor "program_with_source_ctor"
 *
 * The current program_with_source_ctor is a reference pointing to a distinguished
 * \ref clxx::program_with_source_ctor "program_with_source_ctor" object. The \ref clxx::current_program_with_source_ctor "current_program_with_source_ctor"
 * is a specialization of the \ref clxx::detail::current_instance "current_instance"
 * for the \ref clxx::program_with_source_ctor "program_with_source_ctor" class.
 *
 * Quick guide:
 *
 * - use \ref current_program_with_source_ctor::get() to retrieve the current program_with_source_ctor reference,
 * - use \ref current_program_with_source_ctor::bind_static_instance() to bind shared
 *   \ref clxx::program_with_source_ctor "program_with_source_ctor" (shared between threads) to the current
 *   program_with_source_ctor reference,
 * - use \ref current_program_with_source_ctor::bind_thread_instance() to bind thread local
 *   \ref clxx::program_with_source_ctor "program_with_source_ctor" to the current program_with_source_ctor reference,
 * - use \ref current_program_with_source_ctor::bind_custom_instance() to bind user-provided
 *   program_with_source_ctor object to the current program_with_source_ctor reference,
 * - use \ref current_program_with_source_ctor::binding() to check what is currently bound to
 *   the current program_with_source_ctor reference.
 *
 */ // }}}
class current_program_with_source_ctor
  : public detail::current_instance<current_program_with_source_ctor, program_with_source_ctor>
{
  static clxx::program_cached_ctor default_static_instance() { return clxx::program_cached_ctor(); }
  static clxx::program_cached_ctor default_thread_instance() { return clxx::program_cached_ctor(); }
};
} // end namespace clxx

#endif /* CLXX_CL_CURRENT_PROGRAM_CTOR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
