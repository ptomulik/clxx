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

// clxx/clerror_base.hpp

/** // doc: clxx/clerror_base.hpp {{{
 * \file clxx/clerror_base.hpp
 * \brief Provides the clxx::clerror_base template class.
 */ // }}}
#ifndef CLXXERROR_NO_BASE_HPP_INCLUDED
#define CLXXERROR_NO_BASE_HPP_INCLUDED

#include <clxx/clerror.hpp>
#include <clxx/exception_base.hpp>
#include <clxx/util/std_except_ctor_arg.hpp>
#include <clxx/util/clerror_stdexcept.hpp>
#include <clxx/util/enum2cstr.hpp>

namespace clxx {

/** \ingroup clxx_exceptions */
/** @{ */
/** // clerror_base {{{
 * \brief Base class for clxx::clerror_no exceptions.
 *
 * \tparam Code error code for the particular exception,
 * \tparam StdExcept underlying standard exception class. For all the OpenCL
 *         codes sane defaults are provided,
 * \tparam StdCtorArg type of the argument that has to be passed to the
 *         underlying standard exception constructor. For most standard
 *         exceptions sane defaults are provided.
 *
 * This template simplifies creation of the clxx::clerror_no exceptions.
 * Just create an empty class, put clxx::clerror_base as its base and it's
 * done. A code pattern for generating clerror_no exceptions is:
 *
 * \code
 * template<status_t Code>
 *   struct clerror_no
 *     : public clerror_base<code>
 *   {
 *   };
 * \endcode
 *
 * The class adds the clxx::clerror and an appropriate standard exception class
 * as a bases for the exception being created. It also implementes the code()
 * and adds the logic for initializing/retrieving the exception message.
 */ // }}}
template < status_t Code
         , class StdExcept = typename clerror_stdexcept<Code>::type
         , class StdCtorArg = typename std_except_ctor_arg<StdExcept>::type >
  struct clerror_base
    : public exception_base<clerror, StdExcept, StdCtorArg>
  {
  };

/** // doc: clerror_base<Code, StdExcept, std_except_no_ctor_arg_tag> {{{
 * \todo Write documentation
 */ // }}}
template < status_t Code, class StdExcept>
  struct clerror_base<Code, StdExcept, std_except_no_ctor_arg_tag>
    : public exception_base<clerror, StdExcept, std_except_no_ctor_arg_tag>
  {
    /** // doc: static_code {{{
     * \todo Write documentation
     */ // }}}
    static constexpr status_t static_code = Code;
    /** // doc: static_what {{{
     * \todo Write documentation
     */ // }}}
    static constexpr char const* static_what = enum2cstr(Code);
    static_assert(static_what != nullptr, "");
    /** // doc: code() {{{
     * \todo Write documentation
     */ // }}}
    status_t code() const noexcept { return Code; }
    /** // doc: what() {{{
     * \todo Write documentation
     */ // }}}
    char const* what() const noexcept { return static_what; }
  };

/** // doc: clerror_base<Code, StdExcept, char const*> {{{
 * \brief Partial specialization for exceptions with mutable messages.
 */ // }}}
template < status_t Code, class StdExcept>
  struct clerror_base<Code, StdExcept, char const*>
    : public exception_base<clerror, StdExcept, char const*>
  {
    /** // doc: static_code {{{
     * \todo Write documentation
     */ // }}}
    static constexpr status_t static_code = Code;
    /** // doc: static_what {{{
     * \todo Write documentation
     */ // }}}
    static constexpr char const* static_what = enum2cstr(Code);
    static_assert(static_what != nullptr, "");
    /** // doc: clerror_base() {{{
     * \brief Default constructor
     *
     * Passes the default message string to the underlying standard exception.
     */ // }}}
    clerror_base()
      : exception_base<clerror, StdExcept, char const*>(static_what)
    { }
    /** // doc: code() {{{
     * \todo Write documentation
     */ // }}}
    status_t code() const noexcept { return Code; }
  };
/** @} */

} // end namespace clxx

#endif /* CLXXERROR_NO_BASE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
