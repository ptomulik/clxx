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

/** // doc: clxx/shared_ptr.swg {{{
 * \file clxx/shared_ptr.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/shared_ptr.hpp>
%}

// NOTE: clxx/shared_ptr.hpp uses alias template, which is not yet supported
//       by swig, so we replace the clxx::shared_ptr alias with
//       CLXX_SHARED_PTR macro defined here
//%include <clxx/shared_ptr.hpp>
%include <boost_shared_ptr.i>

#define CLXX_SHARED_PTR(__t) boost::shared_ptr<__t>

// CLXX_DECL_CLASS_SHARED_PTR1(__ns1,__klass)
// Having __ns1::__klass create wrappers for its shared_ptr, such that
// the following objects will be available to target language:
//
// * <__klass>_ptr        (shared_ptr<__ns1::__klass>)
// * const_<__klass>_ptr  (shared_ptr<__ns1::__klass const>)
//
%define CLXX_DECL_CLASS_SHARED_PTR1(__ns1,__klass)
%shared_ptr(__ns1::__klass);
namespace __ns1 {
  typedef CLXX_SHARED_PTR(__ns1::__klass) __klass ## _ptr;
  typedef CLXX_SHARED_PTR(__ns1::__klass const) const_ ## __klass ## _ptr;
}
//%template(__klass ## _ptr) CLXX_SHARED_PTR(__ns1::__klass ## _ptr);
//%template(const_ ## __klass ## _ptr) CLXX_SHARED_PTR(__ns1::__klass ## _ptr const);
%enddef

// CLXX_DECL_CLASS_SHARED_PTR2(__ns1,__ns2,__klass)
// Having __ns1::__ns2::__klass create wrappers for its shared_ptr, such that
// the following objects will be available to target language:
//
// * <__klass>_ptr        (shared_ptr<__ns1::__ns2::__klass>)
// * const_<__klass>_ptr  (shared_ptr<__ns1::__ns2::__klass const>)
//
%define CLXX_DECL_CLASS_SHARED_PTR2(__ns1,__ns2,__klass)
%shared_ptr(__ns1::__ns2::__klass);
namespace __ns1 { namespace __ns2 {
  typedef CLXX_SHARED_PTR(__ns1::__ns2::__klass) __klass ## _ptr;
  typedef CLXX_SHARED_PTR(__ns1::__ns2::__klass const) const_ ## __klass ## _ptr;
} }
//%template(__klass ## _ptr) CLXX_SHARED_PTR(__ns1::__ns2::__klass ## _ptr);
//%template(const_ ## __klass ## _ptr) CLXX_SHARED_PTR(__ns1::__ns2::__klass ## _ptr const);
%enddef

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
