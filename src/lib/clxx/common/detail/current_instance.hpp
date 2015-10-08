// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/detail/current_instance.hpp

/** // doc: clxx/common/detail/current_instance.hpp {{{
 * \file clxx/common/detail/current_instance.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMON_DETAIL_CURRENT_INSTANCE_HPP_INCLUDED
#define CLXX_COMMON_DETAIL_CURRENT_INSTANCE_HPP_INCLUDED

#include <clxx/common/current_instance.hpp>
#include <clxx/common/exceptions.hpp>
#include <type_traits>

namespace clxx { namespace detail {
/** \addtogroup clxx_util_current_instance
 * @{ */
/** // doc: current_instance {{{
 * \brief Template base for "current instance" classes
 *
 * This class may be used to implement a convenient device called
 * \ref clxx_util_current_instance "current instance". The current instance
 * is a smart reference which at any time points to one of the following:
 *
 * - a static instance, shared between threads, or
 * - a thread_local instance individual to the current thread, or,
 * - a user-provided instance (which may be static, thread_local, auto or
 *   whatever makes sense).
 *
 * Convenient APIs may be created using current instances as defaults for
 * common arguments. This shall further reduce applications' boilerplate. For
 * example, a function which loads a program from cache may be considered. It
 * may take a file name as first argument and search path as second. In typical
 * application there is little need to change the search path between calls, so
 * our first implementation could be:
 *
 * \code
 * void load_program(std::string const& name, std::string const& path = "/default/search/path")
 * {
 *   //....
 * }
 * \endcode
 *
 * However this is quite static, and we can't simply set in a single line the
 * search path for multiple consecutive calls to \c load_program(). Having
 * implemented a current instance class for the search path (let name it
 * \c current_path) we could implement more flexible and convenient variant of
 * the \c load_program():
 *
 * \snippet clxx/common/current_instance1.cpp LoadProgramFcn
 *
 * Now we may use it together with the current_path as follows:
 *
 * \code
 * // several calls to load_program(...)
 * // ....
 * current_path::get() = "/another/search/path";
 * // ....
 * // consecutive calls to load_program(...), the changed path is used here
 * \endcode
 *
 * The class \c current_path must be implemented. An easy way is to
 * use the \ref clxx::detail::current_instance "current_instance<>" template
 * as a base. A concrete example is presented below.
 *
 * \par Example
 *
 * Implementing current instance class to hold current search path
 *
 * \snippet clxx/common/current_instance1.cpp CurrentPathClass
 *
 * Having our current instance class implemented we may bind different
 * instances to it. In particular we may:
 *
 *  - bind the static instance (maintained internally by the class):
 *    \snippet clxx/common/current_instance1.cpp BindStaticInstance
 *  - bind the thread local instance (maintained internally by the class):
 *    \snippet clxx/common/current_instance1.cpp BindThreadInstance
 *  - bind a user provided instance:
 *    \snippet clxx/common/current_instance1.cpp BindUserInstance
 *
 *
 * The static instance is provided for single-threaded applications or for
 * multi-threaded applications that must have shared current instance.
 *
 * The thread-local instance is for multi-threaded applications which don't
 * have to share the current instance between threads. It's easier to implement
 * thread-safe applications with thread-local instances.
 *
 * \par Internal instances
 *
 * The \ref clxx::detail::current_instance "current_instance<>"
 * template maintains internally two instances of its underlying type:
 * the static (shared between threads) and the thread-local instance.
 * These instances are instantiated lazily with a technique used by
 * to implement singletons. The instances are constructed only on demand at
 * first access via the #get() static method. Calling #bind_static_instance(),
 * or #bind_thread_instance() does not cause any of them to be created,
 * until #get() is invoked. Each instance is constructed only once for the
 * current program (or for the current thread in case of the thread-local
 * instance).
 *
 * \par Initialization of internal instances
 *
 * The current instance class derived from
 * \ref clxx::detail::current_instance "current_instance<>" may
 * optionally implement methods that provide default values for the static
 * and thread-local instances. The methods are named:
 *
 * - \c default_static_instance(), and
 * - \c default_thread_instance().
 *
 * The following expressions, involving method names, must be valid for the
 * default values to be used:
 *
 * \code
 *   Value v(default_static_instance());
 *   Value v(default_thread_instance());
 * \endcode
 *
 * If a given method is not provided, or can't be used in the above expression,
 * the corresponding instance will be default-constructed.
 *
 * \tparam Derived
 *    Derived class that uses this one as a base. The
 *    \ref clxx::detail::current_instance "current_instance<>" template
 *    is supposed to be used as a base class in the
 *    <a href="https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern">CRTP pattern</a>.
 * \tparam Value
 *    Value type, the type of instances that will be referred by this
 *    instantiation.
 * \tparam Reference
 *    Reference type, the type returned by #get() method.
 * \tparam Pointer
 *    Pointer type, used to store addresses of user-provided instances.
 */ // }}}
template< typename Derived
        , typename Value
        , typename Reference = Value&
        , typename Pointer = Value*>
class current_instance
{
public:
  /** // doc: value_type {{{
   * \brief Value type referred by the current instance
   */ // }}}
  typedef Value value_type;
  /** // doc: reference {{{
   * \brief Reference type returned by #get()
   */ // }}}
  typedef Reference reference;
  /** // doc: pointer {{{
   * \brief Pointer type used to store addresses of user-provided instances
   */ // }}}
  typedef Pointer pointer;
private:
  // Checks if T::default_static_instance() may be used to initialize the
  // value_type.
  template<typename T>
  class has_default_static_instance
  {
    template <typename C> static long test(...);
    template <typename C> static char test( decltype(value_type(C::default_static_instance()), int()) );
  public:
    constexpr static bool value = (sizeof(test<T>(0)) == sizeof(char));
  };
  // Checks if T::default_thread_instance() may be used to initialize the
  // value_type.
  template<typename T>
  class has_default_thread_instance
  {
    template <typename C> static long test(...);
    template <typename C> static char test( decltype(value_type(C::default_thread_instance()), int()) );
  public:
    constexpr static bool value = (sizeof(test<T>(0)) == sizeof(char));
  };
  template<typename D = Derived>
  static typename
  std::enable_if<has_default_static_instance<D>::value, reference>::type
  static_instance()
  {
    static value_type obj(D::default_static_instance());
    return obj;
  }
  template<typename D = Derived>
  static typename
  std::enable_if<!has_default_static_instance<D>::value, reference>::type
  static_instance()
  {
    static value_type obj;
    return obj;
  }
  template<typename D = Derived>
  static typename
  std::enable_if<has_default_thread_instance<D>::value, reference>::type
  thread_instance()
  {
    thread_local value_type obj(D::default_thread_instance());
    return obj;
  }
  template<typename D = Derived>
  static typename
  std::enable_if<!has_default_thread_instance<D>::value, reference>::type
  thread_instance()
  {
    thread_local value_type obj;
    return obj;
  }
public:
  /** // doc: binding() {{{
   * \brief Tell what the current instance refers to currently
   *
   * \par Side Effect
   *
   * If the object was not explicitly bound or if it was previously reset with
   * reset_binding(), then binding() initializes its binding to a value
   * returned by \ref clxx::current_instance_default_binding() "current_instance_default_binding()".
   *
   * \returns
   *  Current binding
   */ // }}}
  static clxx::current_instance_binding_t
  binding() noexcept
  {
    if(_binding == clxx::current_instance_binding_t::none)
      _binding = current_instance_default_binding();
    return _binding;
  }
  /** // doc: get() {{{
   * \brief Return reference to current instance
   *
   * Call to this method may initialize the internally maintained static
   * instance (if currently bound) or may initialize the thread-local instance
   * (if currently bound).
   *
   * \returns Reference to current instance
   *
   * \throw clxx::internal_error()
   *    if binding() returns an invalid value
   *
   * May also throw exceptions originating from constructors of Value and
   * from Derived::default_static_instance(), Derived::default_thread_instance().
   */ // }}}
  static reference
  get()
  {
    switch(binding())
      {
        case clxx::current_instance_binding_t::static_instance:
          return static_instance();
        case clxx::current_instance_binding_t::thread_instance:
          return thread_instance();
        case clxx::current_instance_binding_t::custom_instance:
          return *_custom_instance;
        default:
          throw clxx::internal_error();
      }
  }
  /** // doc: bind_static_instance() {{{
   * \brief Bind the internally maintained static instance
   */ // }}}
  static void
  bind_static_instance() noexcept
  {
    _binding = current_instance_binding_t::static_instance;
  }
  /** // doc: bind_thread_instance() {{{
   * \brief Bind the internally maintained thread-local instance
   */ // }}}
  static void
  bind_thread_instance() noexcept
  {
    _binding = current_instance_binding_t::thread_instance;
  }
  /** // doc: bind_custom_instance() {{{
   * \brief Bind custom instance provided by user
   *
   * \param ref The instance to bind 
   */ // }}}
  static void
  bind_custom_instance(reference ref) noexcept
  {
    _binding = current_instance_binding_t::custom_instance;
    _custom_instance = &ref;
  }
  /** // doc: reset_binding() {{{
   * \brief Resets current instance binding to its default state
   */ // }}}
  static void
  reset_binding() noexcept
  {
    _binding = current_instance_binding_t::none;
  }
private:
  static thread_local clxx::current_instance_binding_t _binding;
  static thread_local pointer _custom_instance;
};

template< typename Derived, typename Value, typename Reference, typename Pointer >
thread_local clxx::current_instance_binding_t
current_instance<Derived, Value, Reference, Pointer>::
_binding = clxx::current_instance_binding_t::none;

template< typename Derived, typename Value, typename Reference, typename Pointer >
thread_local Pointer
current_instance<Derived, Value, Reference, Pointer>::
_custom_instance = nullptr;
/** @} */
} } // end namespace clxx

#endif /* CLXX_COMMON_DETAIL_CURRENT_INSTANCE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
