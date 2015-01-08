/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE
 */

// clxx/exceptions.hpp

/** // doc: clxx/exceptions.hpp {{{
 * \file clxx/exceptions.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_EXCEPTIONS_HPP_INCLUDED
#define CLXX_EXCEPTIONS_HPP_INCLUDED

#include <clxx/exception_base.hpp>
#include <clxx/clerror_no.hpp>
#include <clxx/util/to_string.hpp>
#include <clxx/types.hpp>
#include <string>

namespace clxx {
/** // doc: invalid_argument_error {{{
 * \todo Write documentation
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
  };
/** // doc: length_error {{{
 * \todo Write documentation
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
  };
/** // doc: not_enough_space_error {{{
 * \todo Write documentation
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
  };
/** // doc: uninitialized_platform_error {{{
 * \todo Write documentation
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
      : Base("attempted to use uninitialized clxx::platform object")
    { }
  };
/** // doc: uninitialized_device_error {{{
 * \todo Write documentation
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
      : Base("attempted to use uninitialized clxx::device object")
    { }
  };
/** // doc: uninitialized_context_error {{{
 * \todo Write documentation
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
      : Base("attempted to use uninitialized clxx::context object")
    { }
  };
/** // doc: uninitialized_value_error {{{
 * \todo Write documentation
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
  };
/** // doc: value_access_error {{{
 * \todo Write documentation
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
  };
/** // doc: invalid_key_error {{{
 * \todo Write documentation
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
    /** // doc: invalid_key_error(char const*) {{{
     * \brief Default constructor
     */ // }}}
    invalid_key_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: unexpected_clerror {{{
 * \todo Write documentation
 */ // }}}
struct unexpected_clerror
    : public exception_base<clxx::clerror, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::clerror, std::logic_error> Base;
    /** // doc: unexpected_clerror() {{{
     * \brief Default constructor
     */ // }}}
    unexpected_clerror(status_t c) noexcept
      : Base((std::string("unexpected OpenCL error: ") + std::to_string(c)).c_str())
      , _code(c)
    { }
    /** // doc: code() {{{
     * \todo Write documentation
     */ // }}}
    status_t code() const noexcept
    { return this->_code; }
  private:
    /** // doc: _code {{{
     * \todo Write documentation
     */ // }}}
    status_t _code;
  protected:
    unexpected_clerror();
  };
} // end namespace clxx

#endif /* CLXX_EXCEPTIONS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
