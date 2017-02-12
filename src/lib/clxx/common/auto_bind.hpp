// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/auto_bind.hpp

/** // doc: clxx/common/auto_bind.hpp {{{
 * \file clxx/common/auto_bind.hpp
 * \brief Provides the clxx::auto_bind class
 *
 * This file contains definition of clxx::auto_bind class which helps to work
 * with \ref clxx::detail::current_instance "current_instance".
 */ // }}}
#ifndef CLXX_COMMON_AUTO_BIND_HPP_INCLUDED
#define CLXX_COMMON_AUTO_BIND_HPP_INCLUDED

#include <clxx/common/current_instance.hpp>

namespace clxx {
/** \addtogroup clxx_util_current_instance
 * @{ */
/** // doc: auto_bind {{{
 * \brief Allows to temporarily bind user instance to a
 *        \ref clxx::detail::current_instance "current_instance" class
 *
 * Using RAII pattern the object allows to bind user supplied instance to
 * a \ref clxx::detail::current_instance "current_instance" class. The original
 * bind is restored at the end of current scope (or, more generally, at the
 * \ref clxx::auto_bind "auto_bind" destruction).
 *
 * \par Example
 *
 * Having the current_path class:
 * \snippet clxx/common/auto_bind1.cpp CurrentPathClass
 * and the following function
 * \snippet clxx/common/auto_bind1.cpp LoadProgramFcn
 * we may use the \ref clxx::auto_bind "auto_bind" utility as follows
 * \snippet clxx/common/auto_bind1.cpp ExampleCore
 *
 * The output from this example is the following
 * \snippet clxx/common/auto_bind1.cpp Output
 *
 * \tparam CurrentInstance
 *    The CurrentInstance class assiciated with this particular instantiation
 *    of the \ref clxx::auto_bind "auto_bind<>" template.
 */ // }}}
template< typename CurrentInstance >
class auto_bind
{
public:
  /** // doc: value_type {{{
   * \brief Value type referred by the current instance
   */ // }}}
  typedef typename CurrentInstance::value_type value_type;
  /** // doc: reference {{{
   * \brief Reference type for the underlying value
   */ // }}}
  typedef typename CurrentInstance::reference reference;
  /** // doc: pointer {{{
   * \brief Pointer type for the underlying value
   */ // }}}
  typedef typename CurrentInstance::pointer pointer;
  /** // doc: auto_bind() {{{
   * \brief Binds the user-provided instance \p obj to the current instance clas
   */ // }}}
  auto_bind(reference obj)
    : _custom_instance(obj),
      _saved_binding(current_instance_binding_t::none),
      _saved_pointer(nullptr)
  {
    bind();
  }
  /** // doc: ~auto_bind() {{{
   * \brief Unbinds the previously bound instance
   */ // }}}
  ~auto_bind()
  {
    unbind();
  }
  /** // doc: auto_bind() {{{
   * \brief Object is non-default-constructible
   */ // }}}
  auto_bind() = delete;
  /** // doc: auto_bind(auto_bind const&) {{{
   * \brief Object is non-copy-constructible
   */ // }}}
  auto_bind(auto_bind const&) = delete;
  /** // doc: operator=() {{{
   * \brief Object is non-copy-assignable
   */ // }}}
  void operator=(auto_bind const&) = delete;
private:
  void bind()
  {
    _saved_binding = CurrentInstance::binding();
    if(_saved_binding == current_instance_binding_t::custom_instance)
      _saved_pointer = &CurrentInstance::get();
    CurrentInstance::bind_custom_instance(_custom_instance);
  }
  void unbind() noexcept
  {
    switch(_saved_binding)
      {
        case current_instance_binding_t::static_instance:
          CurrentInstance::bind_static_instance();
          break;
        case current_instance_binding_t::thread_instance:
          CurrentInstance::bind_thread_instance();
          break;
        case current_instance_binding_t::custom_instance:
          CurrentInstance::bind_custom_instance(*_saved_pointer);
          break;
        default:
          break;
      }
    // prevent from unbinding twice by this object...
    _saved_binding = current_instance_binding_t::none;
  }
private:
  reference                   _custom_instance;
  current_instance_binding_t  _saved_binding;
  pointer                     _saved_pointer;
};
/** @} */
} // end namespace clxx

#endif /* CLXX_COMMON_AUTO_BIND_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
