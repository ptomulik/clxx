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

// clxx/cl/cl.h

/** // doc: clxx/cl/cl.h {{{
 * \file clxx/cl/cl.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_CL_H_INCLUDED
#define CLXX_CL_CL_H_INCLUDED

#include <clxx/config.h>

#include <CL/cl.h>
#include <CL/cl_ext.h>
#include <CL/cl_gl.h>
#if !CL_VERSION_2_0
# include <CL/cl_gl_ext.h>
#endif
#if CL_VERSION_1_2
# if !CLXX_WITHOUT_CL_EGL
#   include <CL/cl_egl.h>
# endif
# include <CL/cl_dx9_media_sharing.h>
#endif

#ifdef _WIN32
# include <CL/cl_d3d10.h>
# if CL_VERSION_1_2
#   include <CL/cl_d3d11.h>
# endif
#endif

#endif /* CLXX_CL_CL_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
