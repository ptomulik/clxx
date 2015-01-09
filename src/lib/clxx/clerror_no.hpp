// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/clerror_no.hpp

/** // doc: clxx/clerror_no.hpp {{{
 * \file clxx/clerror_no.hpp
 * \brief Provides the clxx::clerror_no template class.
 */ // }}}
#ifndef CLXX_CLERROR_NO_HPP_INCLUDED
#define CLXX_CLERROR_NO_HPP_INCLUDED

#include <clxx/clerror_base.hpp>

namespace clxx {

/** // doc: clerror_no {{{
 * \ingroup clxx_exceptions
 * \brief Template class for all exceptions that result from OpenCL errors.
 *
 * OpenCL functions used to return error codes whenever an error occured. The
 * %clxx wrappers turn these error codes into exceptions and throw exceptions
 * instead of returning error codes. This template is used to generate
 * exception classes based on the OpenCL error codes (status_t values
 * actually).
 *
 * \tparam Code error code as returned by an OpenCL function.
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
template <status_t Code>
  struct clerror_no
    : public clerror_base<Code>
  {
  };

} // end namespace clxx

#endif /* CLXX_CLERROR_NO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
