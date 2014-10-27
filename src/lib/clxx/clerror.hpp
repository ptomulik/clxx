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

// clxx/clerror.hpp

/** // doc: clxx/clerror.hpp {{{
 * \file clxx/clerror.hpp
 * \brief Provides clxx::clerror class.
 */ // }}}
#ifndef CLXX_CLERROR_HPP_INCLUDED
#define CLXX_CLERROR_HPP_INCLUDED

#include <clxx/exception.hpp>
#include <clxx/types.hpp>

namespace clxx {

/** // doc: clerror {{{
 * \ingroup clxx_exceptions
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

} // end namespace clxx

#endif /* CLXX_CLERROR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
