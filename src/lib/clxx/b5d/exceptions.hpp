// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/exceptions.hpp

/** // doc: clxx/b5d/exceptions.hpp {{{
 * \file clxx/b5d/exceptions.hpp
 * \brief Defines exceptions thrown by the b5d functions.
 */ // }}}
#ifndef CLXX_B5D_EXCEPTIONS_HPP_INCLUDED
#define CLXX_B5D_EXCEPTIONS_HPP_INCLUDED

#include <clxx/c4n/exception.hpp>
#include <clxx/c4n/exception_base.hpp>
#include <clxx/b5d/types.hpp>
#include <clxx/b5d/detail/clerror_stdexcept.hpp>
#include <clxx/b5d/detail/enum2cstr.hpp>
#include <clxx/b5d/detail/to_string.hpp>

#include <string>
#include <stdexcept>

namespace clxx {

/** // doc: clerror {{{
 * \ingroup clxx_common_exceptions
 * \brief Base class for all clxx exceptions originating from OpenCL errors.
 *
 * If OpenCL returns an error code, the clxx library throws one of the
 * clxx::clerror_no exceptions. The clxx::clerror is a base class for all the
 * clxx::clerror_no exceptions originating from errors returned by OpenCL
 * functions.
 */ // }}}
struct clerror
  : public exception
  {
    /** // doc: code() {{{
     * \brief Return error code for this exception.
     *
     * There shall be a plenty of derived classes - one for each OpenCL error
     * code (see \ref status_t). This method returns the error code of the
     * particular derived class.
     *
     * \return error code for a particular error.
     *
     * \note This method must be implemented in a derived class.
     */ // }}}
    virtual status_t code() const noexcept = 0;
  };

/** // clerror_base {{{
 * \ingroup clxx_common_exceptions
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
         , class StdExcept = typename detail::clerror_stdexcept<Code>::type
         , class StdCtorArg = typename detail::std_except_ctor_arg<StdExcept>::type >
  struct clerror_base
    : public exception_base<clerror, StdExcept, StdCtorArg>
  {
  };

/** // doc: clerror_base<Code, StdExcept, detail::std_except_no_ctor_arg_tag> {{{
 * \ingroup clxx_common_exceptions
 * \brief Partial specialization of the clerror_base template for exceptions
 *    based on standard exceptions with immutable error messages
 */ // }}}
template < status_t Code, class StdExcept>
  struct clerror_base<Code, StdExcept, detail::std_except_no_ctor_arg_tag>
    : public exception_base<clerror, StdExcept, detail::std_except_no_ctor_arg_tag>
  {
    /** // doc: static_code {{{
     * \brief OpenCL error code represented by this exception
     */ // }}}
    static constexpr status_t static_code = Code;
    /** // doc: static_what {{{
     * \brief Error message for the OpenCL error represented by this class
     */ // }}}
    static constexpr char const* static_what = detail::enum2cstr(Code);
    static_assert(static_what != nullptr, "");
    /** // doc: code() {{{
     * \brief Returns OpenCL error code represented by this exception
     */ // }}}
    status_t code() const noexcept { return Code; }
    /** // doc: what() {{{
     * \brief Return the error message for this exception
     */ // }}}
    char const* what() const noexcept { return static_what; }
  };

/** // doc: clerror_base<Code, StdExcept, detail::std_except_xstring_ctor_arg_tag> {{{
 * \ingroup clxx_common_exceptions
 * \brief Partial specialization for exceptions with mutable messages.
 */ // }}}
template < status_t Code, class StdExcept>
  struct clerror_base<Code, StdExcept, detail::std_except_xstring_ctor_arg_tag>
    : public exception_base<clerror, StdExcept, detail::std_except_xstring_ctor_arg_tag>
  {
    /** // doc: static_code {{{
     * \brief OpenCL error code represented by this exception
     */ // }}}
    static constexpr status_t static_code = Code;
    /** // doc: static_what {{{
     * \brief Error message for the OpenCL error represented by this class
     */ // }}}
    static constexpr char const* static_what = detail::enum2cstr(Code);
    static_assert(static_what != nullptr, "");
    /** // doc: clerror_base() {{{
     * \brief Default constructor
     *
     * Passes the default message string to the underlying standard exception.
     */ // }}}
    clerror_base()
      : exception_base<clerror, StdExcept, detail::std_except_xstring_ctor_arg_tag>(static_what)
    { }
    /** // doc: clerror_base(std::string const&) {{{
     * \brief Constructor
     *
     * Passes the default message string to the underlying standard exception.
     */ // }}}
    clerror_base(std::string const& what_arg)
      : exception_base<clerror, StdExcept, detail::std_except_xstring_ctor_arg_tag>(what_arg)
    { }
    /** // doc: clerror_base(std::string const&) {{{
     * \brief Constructor
     *
     * Passes the default message string to the underlying standard exception.
     */ // }}}
    clerror_base(char const* what_arg)
      : exception_base<clerror, StdExcept, detail::std_except_xstring_ctor_arg_tag>(what_arg)
    { }
    /** // doc: code() {{{
     * \brief Returns OpenCL error code represented by this exception.
     *
     * \returns the value of static_code
     */ // }}}
    status_t code() const noexcept { return Code; }
  };

/** // doc: clerror_base<Code, StdExcept, char const*> {{{
 * \ingroup clxx_common_exceptions
 * \brief Partial specialization for exceptions with mutable messages.
 */ // }}}
template < status_t Code, class StdExcept>
  struct clerror_base<Code, StdExcept, char const*>
    : public exception_base<clerror, StdExcept, char const*>
  {
    /** // doc: static_code {{{
     * \brief OpenCL error code represented by this exception
     */ // }}}
    static constexpr status_t static_code = Code;
    /** // doc: static_what {{{
     * \brief Error message for the OpenCL error represented by this class
     */ // }}}
    static constexpr char const* static_what = detail::enum2cstr(Code);
    static_assert(static_what != nullptr, "");
    /** // doc: clerror_base() {{{
     * \brief Default constructor
     *
     * Passes the default message string to the underlying standard exception.
     */ // }}}
    clerror_base()
      : exception_base<clerror, StdExcept, char const*>(static_what)
    { }
    /** // doc: clerror_base(std::string const&) {{{
     * \brief Constructor
     *
     * Passes the default message string to the underlying standard exception.
     */ // }}}
    clerror_base(char const* what_arg)
      : exception_base<clerror, StdExcept, detail::std_except_xstring_ctor_arg_tag>(what_arg)
    { }
    /** // doc: code() {{{
     * \brief Returns OpenCL error code represented by this exception.
     *
     * \returns the value of static_code
     */ // }}}
    status_t code() const noexcept { return Code; }
  };

/** // doc: clerror_no {{{
 * \ingroup clxx_common_exceptions
 * \brief Template class for all exceptions that result from OpenCL errors.
 *
 * OpenCL functions used to return error codes whenever an error occured. The
 * %clxx wrappers turn these error codes into exceptions and throw exceptions
 * instead of returning error codes. This template is used to generate
 * exception classes based on the OpenCL error codes (status_t values
 * actually).
 *
 * \tparam Code error code as returned by an OpenCL function.
 * \tparam StdExcept standard exception base class
 * \tparam StdCtorArg determines what (extra) constructors the standard
 *         exception base class has
 *
 * **Example**:
 * \code
 *   cl_uint n;
 *   status_t s = static_cast<status_t>(clGetPlatformIDs(0,NULL,&n));
 *   if(is_error(s))
 *     {
 *       switch(s)
 *         {
 *           case status_t::invalid_value:
 *             throw clerror_no<status_t::invalid_value>();
 *           case status_t::invalid_platform:
 *             throw clerror_no<status_t::invalid_platform>();
 *           default:
 *             throw unexpected_clerror(s);
 *         }
 *     }
 * \endcode
 */ // }}}
template < status_t Code
         , class StdExcept = typename detail::clerror_stdexcept<Code>::type
         , class StdCtorArg = typename detail::std_except_ctor_arg<StdExcept>::type >
  struct clerror_no;
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template <status_t Code, class StdExcept>
  struct clerror_no<Code, StdExcept, detail::std_except_no_ctor_arg_tag>
    : public clerror_base<Code,StdExcept, detail::std_except_no_ctor_arg_tag>
  {
    typedef clerror_base<Code,StdExcept, detail::std_except_no_ctor_arg_tag> Base;
    clerror_no() : Base() { }
  };
template <status_t Code, class StdExcept>
  struct clerror_no<Code, StdExcept, detail::std_except_xstring_ctor_arg_tag>
    : public clerror_base<Code, StdExcept, detail::std_except_xstring_ctor_arg_tag>
  {
    typedef clerror_base<Code,StdExcept, detail::std_except_xstring_ctor_arg_tag> Base;
    clerror_no() : Base() { }
    explicit clerror_no(std::string const& what_arg) : Base(what_arg) { }
    explicit clerror_no(char const* what_arg) : Base(what_arg) { }
  };
/** \endcond **/

/** // doc: unexpected_clerror {{{
 * \ingroup clxx_common_exceptions
 * \brief An exception when an OpenCL function returns error code that is unknown to clxx
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
      : Base(std::string("unexpected OpenCL error: ") + clxx::to_string(c))
      , _code(c)
    { }
    /** // doc: unexpected_clerror() {{{
     * \brief Constructor
     */ // }}}
    unexpected_clerror(status_t c, std::string const& what_arg) noexcept
      : Base(what_arg),
        _code(c)
    { }
    /** // doc: unexpected_clerror() {{{
     * \brief Constructor
     */ // }}}
    unexpected_clerror(status_t c, char const* what_arg) noexcept
      : Base(what_arg),
        _code(c)
    { }
    /** // doc: code() {{{
     * \brief Returns the OpenCL error code encapsulated in the exception
     * \returns The OpenCL error code
     */ // }}}
    status_t code() const noexcept
    { return this->_code; }
  private:
    status_t _code;
  protected:
    unexpected_clerror();
  };
/** \endcond */
} // end namespace clxx

#endif /* CLXX_B5D_EXCEPTIONS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
