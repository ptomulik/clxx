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

/** // doc: clxx/exception_support.swg {{{
 * \file clxx/exception_support.swg
 * \todo Write documentation
 */ // }}}

%include <exception.i>
%include <clxx/clerror_support.swg>

%{
#define SWIG_Clxx_MemoryError(e) SWIG_exception(SWIG_MemoryError, (e).what())
#define SWIG_Clxx_IOError(e) SWIG_exception(SWIG_MemoryError, (e).what())
#define SWIG_Clxx_RuntimeError(e) SWIG_exception(SWIG_RuntimeError, (e).what())
#define SWIG_Clxx_IndexError(e) SWIG_exception(SWIG_MemoryError, (e).what())
#define SWIG_Clxx_TypeError(e) SWIG_exception(SWIG_MemoryError, (e).what())
#define SWIG_Clxx_DivisionByZeroError(e) SWIG_exception(SWIG_MemoryError, (e).what())
#define SWIG_Clxx_OverflowError(e) SWIG_exception(SWIG_MemoryError, (e).what())
#define SWIG_Clxx_SyntaxError(e) SWIG_exception(SWIG_MemoryError, (e).what())
#define SWIG_Clxx_ValueError(e) SWIG_exception(SWIG_ValueError, (e).what())
#define SWIG_Clxx_SystemError(e) SWIG_exception(SWIG_MemoryError, (e).what())
%}

//
// Macros that define how we catch particular exceptions
//

// standard exceptions
#define %catch_exception catch(std::exception const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_badalloc catch(std::bad_alloc const& e) { SWIG_Clxx_MemoryError(e); }

// clxx::clerror
#define %catch_clerror catch(clxx::clerror const& e) { SWIG_Clxx_clerror(e); }

// stuff frim clxx/exceptions.hpp
#define %catch_invalid_argument_error catch(clxx::invalid_argument_error const& e) { SWIG_Clxx_ValueError(e); }
#define %catch_length_error catch(clxx::length_error const& e) { SWIG_Clxx_ValueError(e); }
#define %catch_not_enough_space_error catch(clxx::not_enough_space_error const& e) { SWIG_Clxx_ValueError(e); }
#define %catch_uninitialized_platform_error catch(clxx::uninitialized_platform_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_uninitialized_device_error catch(clxx::uninitialized_device_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_uninitialized_context_error catch(clxx::uninitialized_context_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_uninitialized_value_error catch(clxx::uninitialized_value_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_value_access_error catch(clxx::value_access_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_unexpected_clerror catch(clxx::unexpected_clerror const& e) { SWIG_Clxx_clerror(e); }

//
// Macros for most commonly used exception specifications
//

%define %throws_clerror(decl)
%exception decl {
  try { $action }
  %catch_clerror
  %catch_exception
}
%enddef

%define %throws_badalloc(decl)
%exception decl {
  try { $action }
  %catch_badalloc
  %catch_exception
}
%enddef

%define %throws_clerror_badalloc(decl)
%exception decl {
  try { $action }
  %catch_clerror
  %catch_badalloc
  %catch_exception
}
%enddef


// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
