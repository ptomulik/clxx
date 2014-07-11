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

// clxx/util/std_except_ctor_arg.hpp

#include <stdexcept>

/** // doc: clxx/util/std_except_ctor_arg.hpp {{{
 * \file clxx/util/std_except_ctor_arg.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_UTIL_STD_EXCEPT_CTOR_ARG_HPP_INCLUDED
#define CLXX_UTIL_STD_EXCEPT_CTOR_ARG_HPP_INCLUDED

namespace clxx {
/** // doc: std_except_no_ctor_arg_tag {{{
 * \brief A tag denoting that certain standard exception has no constructor
 *        accepting an argument other than the copy constructor.
 */ // }}}
struct std_except_no_ctor_arg_tag {};
/** // doc: std_except_ctor_arg {{{
 * \brief Determine how to construct a given standard exception.
 *
 * There are two kinds of standard exceptions:
 *
 * - those taking a message string as an argument to constructor, and
 * - those having only the default (and copy) constructor.
 *
 * An example of exception from the first group (with mutable message) is the
 * \c std::runtime_error. An example of the later (with fixed message)
 * is the \c std::bad_alloc. One feature which distinguishes one standard
 * exceptions from others is thus the additional constructor which takes the
 * message string as an argument.
 *
 * The std_except_ctor_arg metafunction determines whether we should construct
 * given standard exception using the extra constructor taking an argument or
 * rather shall we use the default constructor. For exceptions taking an
 * argument, the metafunction returns the type of the argument we shall use.
 *
 * **Example**:
 * \code
 * #include <clxx/util/std_except_ctor_arg.hpp>
 *
 * template<class StdExcept, class CtorArg = typename std_except_ctor_arg<StdExcept>::type>
 *   struct my_except 
 *    : public StdExcept
 *   { 
 *     my_except(CtorArg arg) : StdExcept(arg) { }
 *     // ...
 *   };
 *
 * template < class StdExcept >
 *   struct my_except<StdExcept, std_except_no_ctor_arg_tag >
 *    : public StdExcept
 *   {
 *     my_except() : StdExcept() { }
 *     // ...
 *   };
 *
 * \endcode
 */ // }}}
template<class ExcpClass>
struct std_except_ctor_arg { };
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<>
struct std_except_ctor_arg< std::exception >
  { typedef std_except_no_ctor_arg_tag type; };
template<>
struct std_except_ctor_arg< std::bad_exception >
  { typedef std_except_no_ctor_arg_tag type; };
template<>
struct std_except_ctor_arg< std::logic_error >
  { typedef char const* type; };
template<>
struct std_except_ctor_arg< std::domain_error >
  { typedef char const* type; };
template<>
struct std_except_ctor_arg< std::invalid_argument >
  { typedef char const* type; };
template<>
struct std_except_ctor_arg< std::length_error >
  { typedef char const* type; };
template<>
struct std_except_ctor_arg< std::out_of_range >
  { typedef char const* type; };
template<>
struct std_except_ctor_arg< std::runtime_error >
  { typedef char const* type; };
template<>
struct std_except_ctor_arg< std::range_error >
  { typedef char const* type; };
template<>
struct std_except_ctor_arg< std::overflow_error >
  { typedef char const* type; };
template<>
struct std_except_ctor_arg< std::underflow_error >
  { typedef char const* type; };
template<>
struct std_except_ctor_arg< std::bad_alloc>
  { typedef std_except_no_ctor_arg_tag type; };
/** \endcond */
} // end namespace clxx

#endif /* CLXX_UTIL_STD_EXCEPT_CTOR_ARG_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
