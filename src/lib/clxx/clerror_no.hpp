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
