// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/current_instance.hpp

/** // doc: clxx/common/current_instance.hpp {{{
 * \file clxx/common/current_instance.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMON_CURRENT_INSTANCE_HPP_INCLUDED
#define CLXX_COMMON_CURRENT_INSTANCE_HPP_INCLUDED

namespace clxx {
/** \ingroup clxx_common_util_current_instance
 * @{ */
/** // doc: current_instance_binding_t {{{
 * \brief Possible bindings for \ref clxx::detail::current_instance "detail::current_instance<>"
 */ // }}}
enum class
current_instance_binding_t
{
  none,             ///< Nothing is bound
  static_instance,  ///< Internally maintained static instance is bound
  thread_instance,  ///< Internally maintained thread-local instance is bound
  custom_instance   ///< User-supplied instance is bound
};
/** // doc: current_instance_default_binding() {{{
 * \brief Default \ref clxx::detail::current_instance "current_instance<>"
 *        binding type
 *
 * Note, that the setting is a thread-local singleton variable, so each thread
 * has its own independent copy.
 */ // }}}
inline current_instance_binding_t&
current_instance_default_binding()
{
  thread_local current_instance_binding_t binding
             = current_instance_binding_t::static_instance;
  return binding;
}
/** // doc: current_instance_default_binding() {{{
 * \brief Resets the default binding type for
 *        \ref clxx::detail::current_instance "current_instance<>" classes
 *
 * Alters only classes that were not used before the call to
 * #current_instance_default_to_static_instance(). It sets the default policy for current
 * thread only.
 *
 * \code
 * b11 = current_instance1::binding();
 * current_instance_reset_default_binding();
 * b12 = current_instance1::binding();  // unaltered
 * b21 = current_instance2::binding();  // possibly altered
 * \endcode
 */ // }}}
inline void
current_instance_reset_default_binding()
{
  current_instance_default_binding() = current_instance_binding_t::static_instance;
}
/** // doc: current_instance_default_to_static_instance() {{{
 * \brief Sets static instance as a default for
 *        \ref clxx::detail::current_instance "current_instance<>" classes
 *
 * Alters only classes that were not used before the call to
 * #current_instance_default_to_static_instance(). It sets the default policy for current
 * thread only.
 *
 * \code
 * b11 = current_instance1::binding();
 * current_instance_default_to_static_instance();
 * b12 = current_instance1::binding();  // unaltered
 * b21 = current_instance2::binding();  // altered
 * \endcode
 */ // }}}
inline void
current_instance_default_to_static_instance()
{
  current_instance_default_binding() = current_instance_binding_t::static_instance;
}
/** // doc: current_instance_default_binding() {{{
 * \brief Sets thread-local instance as a default for
 *        \ref clxx::detail::current_instance "current_instance<>" classes
 *
 * Alters only classes that were not used before the call to
 * #current_instance_default_to_static_instance(). It sets the default policy for current
 * thread only.
 *
 * \code
 * b11 = current_instance1::binding();
 * current_instance_default_to_thread_instance();
 * b12 = current_instance1::binding();  // unaltered
 * b21 = current_instance2::binding();  // altered
 * \endcode
 */ // }}}
inline void
current_instance_default_to_thread_instance()
{
  current_instance_default_binding() = current_instance_binding_t::thread_instance;
}
/** @} */
} // end namespace clxx

#endif /* CLXX_COMMON_CURRENT_INSTANCE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
