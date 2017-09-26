// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/exceptions.hpp

/** // doc: clxx/c4n/exceptions.hpp {{{
 * \file clxx/c4n/exceptions.hpp
 * \brief Defines several exceptions used across clxx project
 */ // }}}
#ifndef CLXX_C4N_EXCEPTIONS_HPP_INCLUDED
#define CLXX_C4N_EXCEPTIONS_HPP_INCLUDED

#include <clxx/c4n/exception.hpp>
#include <clxx/c4n/exception_base.hpp>
#include <string>

namespace clxx {

/** // doc: internal_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception thrown when a user tries to operate on an uninitialized
 *        \ref clxx::device "device" object
 */ // }}}
struct internal_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: internal_error() {{{
     * \brief Default constructor
     */ // }}}
    internal_error() noexcept
      : Base("internal error")
    { }
    /** // doc: internal_error() {{{
     * \brief Constructor
     */ // }}}
    internal_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: internal_error() {{{
     * \brief Constructor
     */ // }}}
    internal_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: invalid_argument_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception thrown when an invalid argument is provided to a function
 */ // }}}
struct invalid_argument_error
    : public exception_base<clxx::exception, std::invalid_argument>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::invalid_argument> Base;
    /** // doc: invalid_argument_error() {{{
     * \brief Default constructor
     */ // }}}
    invalid_argument_error() noexcept
      : Base("invalid argument")
    { }
    /** // doc: invalid_argument_error() {{{
     * \brief Constructor
     */ // }}}
    invalid_argument_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: invalid_argument_error() {{{
     * \brief Constructor
     */ // }}}
    invalid_argument_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: length_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception thrown when a sequence of invalid length is provided as an argument to a function
 */ // }}}
struct length_error
    : public exception_base<clxx::exception, std::length_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::length_error> Base;
    /** // doc: length_error() {{{
     * \brief Default constructor
     */ // }}}
    length_error() noexcept
      : Base("length error")
    { }
    /** // doc: length_error() {{{
     * \brief Constructor
     */ // }}}
    length_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: length_error() {{{
     * \brief Constructor
     */ // }}}
    length_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: out_of_range_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception thrown when a value provided to a function is out of allowed range
 */ // }}}
struct out_of_range_error
    : public exception_base<clxx::exception, std::out_of_range>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::out_of_range> Base;
    /** // doc: out_of_range_error() {{{
     * \brief Default constructor
     */ // }}}
    out_of_range_error() noexcept
      : Base("out_of_range error")
    { }
    /** // doc: out_of_range_error() {{{
     * \brief Constructor
     */ // }}}
    out_of_range_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: out_of_range_error() {{{
     * \brief Constructor
     */ // }}}
    out_of_range_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: not_enough_space_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception thrown when a user-defined storage is not sufficient to
 *        contain data provided by function caller
 */ // }}}
struct not_enough_space_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: not_enough_space_error() {{{
     * \brief Default constructor
     */ // }}}
    not_enough_space_error() noexcept
      : Base("not enough space")
    { }
    /** // doc: not_enough_space_error() {{{
     * \brief Constructor
     */ // }}}
    not_enough_space_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: not_enough_space_error() {{{
     * \brief Constructor
     */ // }}}
    not_enough_space_error(char const* what_arg) noexcept
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
/** // doc: invalid_index_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception being thrown when index to an array is out of range
 */ // }}}
struct invalid_index_error
    : public exception_base<clxx::exception, std::out_of_range>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::out_of_range> Base;
    /** // doc: invalid_index_error() {{{
     * \brief Default constructor
     */ // }}}
    invalid_index_error() noexcept
      : Base("invalid index")
    { }
    /** // doc: invalid_index_error() {{{
     * \brief Constructor
     */ // }}}
    invalid_index_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: invalid_index_error() {{{
     * \brief Constructor
     */ // }}}
    invalid_index_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: invalid_key_error {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception being thrown when an inexistent key is used to lookup a map
 */ // }}}
struct invalid_key_error
    : public exception_base<clxx::exception, std::out_of_range>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::out_of_range> Base;
    /** // doc: invalid_key_error() {{{
     * \brief Default constructor
     */ // }}}
    invalid_key_error() noexcept
      : Base("invalid key")
    { }
    /** // doc: invalid_key_error() {{{
     * \brief Constructor
     */ // }}}
    invalid_key_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: invalid_key_error() {{{
     * \brief Constructor
     */ // }}}
    invalid_key_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
} // end namespace clxx

#endif /* CLXX_C4N_EXCEPTIONS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
