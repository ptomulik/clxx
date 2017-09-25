// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b3c/exceptions.hpp

/** // doc: clxx/b3c/exceptions.hpp {{{
 * \file clxx/b3c/exceptions.hpp
 * \brief Defines several exceptions used across clxx project
 */ // }}}
#ifndef CLXX_B3C_EXCEPTIONS_HPP_INCLUDED
#define CLXX_B3C_EXCEPTIONS_HPP_INCLUDED

#include <clxx/common/exception.hpp>
#include <clxx/common/exception_base.hpp>
#include <string>

namespace clxx {
/** // doc: uninitialized_command_queue_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception being thrown when a user tries to operate on an
 *        uninitialized \ref clxx::command_queue "command_queue" object
 */ // }}}
struct uninitialized_command_queue_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_command_queue_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_command_queue_error() noexcept
      : Base("attempted to use uninitialized command_queue object")
    { }
    /** // doc: uninitialized_command_queue_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_command_queue_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_command_queue_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_command_queue_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_context_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception being thrown when a user tries to operate on an
 *        uninitialized \ref clxx::context "context" object
 */ // }}}
struct uninitialized_context_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_context_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_context_error() noexcept
      : Base("attempted to use uninitialized context object")
    { }
    /** // doc: uninitialized_context_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_context_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_context_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_context_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_device_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception thrown when a user tries to operate on an uninitialized
 *        \ref clxx::device "device" object
 */ // }}}
struct uninitialized_device_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_device_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_device_error() noexcept
      : Base("attempted to use uninitialized device object")
    { }
    /** // doc: uninitialized_device_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_device_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_device_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_device_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_event_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception being thrown when a user tries to operate on an
 *        uninitialized \ref clxx::event "event" object
 */ // }}}
struct uninitialized_event_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_event_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_event_error() noexcept
      : Base("attempted to use uninitialized event object")
    { }
    /** // doc: uninitialized_event_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_event_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_event_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_event_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_kernel_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception being thrown when a user tries to operate on an
 *        uninitialized \ref clxx::kernel "kernel" object
 */ // }}}
struct uninitialized_kernel_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_kernel_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_kernel_error() noexcept
      : Base("attempted to use uninitialized kernel object")
    { }
    /** // doc: uninitialized_kernel_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_kernel_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_kernel_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_kernel_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_mem_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception being thrown when a user tries to operate on an
 *        uninitialized \ref clxx::mem "mem" object
 */ // }}}
struct uninitialized_mem_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_mem_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_mem_error() noexcept
      : Base("attempted to use uninitialized memory object")
    { }
    /** // doc: uninitialized_mem_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_mem_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_mem_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_mem_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_platform_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception thrown when user tries to operate on an uninitialized
 *        \ref clxx::platform "platform" object
 */ // }}}
struct uninitialized_platform_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_platform_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_platform_error() noexcept
      : Base("attempted to use uninitialized platform object")
    { }
    /** // doc: uninitialized_platform_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_platform_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_platform_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_platform_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_program_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception being thrown when a user tries to operate on an
 *        uninitialized \ref clxx::program "program" object
 */ // }}}
struct uninitialized_program_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_program_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_program_error() noexcept
      : Base("attempted to use uninitialized program object")
    { }
    /** // doc: uninitialized_program_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_program_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_program_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_program_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_sampler_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception being thrown when a user tries to operate on an
 *        uninitialized \ref clxx::sampler "sampler" object
 */ // }}}
struct uninitialized_sampler_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_sampler_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_sampler_error() noexcept
      : Base("attempted to use uninitialized sampler object")
    { }
    /** // doc: uninitialized_sampler_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_sampler_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_sampler_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_sampler_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_value_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception begin thrown when a user tries to access a value which
 *        was not initialized
 *
 * This is used mainly by the \ref clxx::platform_info "platform_info" and
 * \ref clxx::device_info "device_info" object, which contain attributes that
 * may have a value but may also be in uninitialized state.
 */ // }}}
struct uninitialized_value_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_value_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_value_error() noexcept
      : Base("attempted to access uninitialized value")
    { }
    /** // doc: uninitialized_value_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_value_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_value_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_value_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: value_access_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception being thrown when there is an error in a value access
 *        logic
 *
 *  This is used, for example, by a \ref clxx::device_partition_property
 *  "device_partition_property". If, for example, it is of a non-sequence type
 *  and user tries to access its value as a sequence, then the
 *  #value_access_error is thrown.
 */ // }}}
struct value_access_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: value_access_error() {{{
     * \brief Default constructor
     */ // }}}
    value_access_error() noexcept
      : Base("attempted to access value in a wrong way")
    { }
    /** // doc: value_access_error() {{{
     * \brief Constructor
     */ // }}}
    value_access_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: value_access_error() {{{
     * \brief Constructor
     */ // }}}
    value_access_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };

/** // doc: uninitialized_cl_object_error {{{
 * \ingroup clxx_common_exceptions
 * \brief Return the exception type for an uninitialized OpenCL object
 *
 * The returned type is, for example, \ref clxx::uninitialized_command_queue_error
 * "clxx::uninitialized_command_queue_error" for \c cl_command_queue,
 * \ref clxx::uninitialized_context_error "uninitialized_context_error" for
 * \c cl_context, and so forth.
 *
 * \par Example
 * \code
 *    typedef uninitialized_cl_object_error<cl_device_id>::type E;
 * \endcode
 */ // }}}
template< typename Handle >
  struct uninitialized_cl_object_error;

/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
#define CLXX_SPECIALIZE_uninitialized_cl_object_error(ClObjT, ErrT) \
template<> \
  struct uninitialized_cl_object_error<ClObjT> \
  { typedef ErrT type; }

CLXX_SPECIALIZE_uninitialized_cl_object_error(cl_command_queue, uninitialized_command_queue_error);
CLXX_SPECIALIZE_uninitialized_cl_object_error(cl_context, uninitialized_context_error);
CLXX_SPECIALIZE_uninitialized_cl_object_error(cl_device_id, uninitialized_device_error);
CLXX_SPECIALIZE_uninitialized_cl_object_error(cl_event, uninitialized_event_error);
CLXX_SPECIALIZE_uninitialized_cl_object_error(cl_kernel, uninitialized_kernel_error);
CLXX_SPECIALIZE_uninitialized_cl_object_error(cl_mem, uninitialized_mem_error);
CLXX_SPECIALIZE_uninitialized_cl_object_error(cl_platform_id, uninitialized_platform_error);
CLXX_SPECIALIZE_uninitialized_cl_object_error(cl_program, uninitialized_program_error);
CLXX_SPECIALIZE_uninitialized_cl_object_error(cl_sampler, uninitialized_sampler_error);
/** \endcond */
} // end namespace clxx

#endif /* CLXX_B3C_EXCEPTIONS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
