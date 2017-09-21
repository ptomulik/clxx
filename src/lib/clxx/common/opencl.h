// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/opencl.h

/** // doc: clxx/common/opencl.h {{{
 * \file clxx/common/opencl.h
 * \brief Includes standard \c CL/cl.h header and additional extension headers
 *        available at the compile time
 *
 *  The following additional headers are included if available
 *
 *    - \c CL/cl_ext.h
 *    - \c CL/cl_gl.h
 *    - \c CL/cl_gl_ext.h
 *    - \c CL/cl_egl.h
 *    - \c CL/cl_dx9_media_sharing.h
 *    - \c CL/cl_d3d10.h
 *    - \c CL/cl_d3d11.h
 */ // }}}
#ifndef CLXX_COMMON_OPENCL_H_INCLUDED
#define CLXX_COMMON_OPENCL_H_INCLUDED

#include <clxx/common/config.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_COMMENT_WARNING
#if defined(__CYGWIN__)
# define CLXX_UNDEF_WIN32 1
# define _WIN32 1
#endif
#include <CL/cl.h>
#if defined(CLXX_UNDEF_WIN32)
# undef _WIN32
# undef CLXX_UNDEF_WIN32
#endif
CLXX_DIAGNOSTIC_POP

/////////////////////////////////////////////////////////////////////////////
// The following prevents usage of clxx development headers without the
// required version of CL/cl.h.
/////////////////////////////////////////////////////////////////////////////
#if defined(CLXX_CL_H_VERSION_1_0) && !defined(CL_VERSION_1_0)
# error "clxx must be compiled with CL/cl.h version at least 1.0"
#endif
#if defined(CLXX_CL_H_VERSION_1_1) && !defined(CL_VERSION_1_1)
# error "clxx must be compiled with CL/cl.h version at least 1.1"
#endif
#if defined(CLXX_CL_H_VERSION_1_2) && !defined(CL_VERSION_1_2)
# error "clxx must be compiled with CL/cl.h version at least 1.2"
#endif
#if defined(CLXX_CL_H_VERSION_2_0) && !defined(CL_VERSION_2_0)
# error "clxx must be compiled with CL/cl.h version at least 2.0"
#endif
#if defined(CLXX_CL_H_VERSION_2_1) && !defined(CL_VERSION_2_1)
# error "clxx must be compiled with CL/cl.h version at least 2.0"
#endif

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_COMMENT_WARNING
#include <CL/cl_ext.h>
#include <CL/cl_gl.h>
#if !CLXX_CL_H_VERSION_2_0
# include <CL/cl_gl_ext.h>
#endif
#if CLXX_CL_H_VERSION_1_2
# if !CLXX_WITHOUT_CL_EGL
#   include <CL/cl_egl.h>
# endif
# include <CL/cl_dx9_media_sharing.h>
# ifdef _WIN32
#   include <dxvahd.h> // IDXVAHD_Device is defined here...
# endif
#endif

#ifdef _WIN32
# include <d3d10_1.h>
# include <CL/cl_d3d10.h>
# if CLXX_CL_H_VERSION_1_2
#   include <CL/cl_d3d11.h>
# endif
#endif
CLXX_DIAGNOSTIC_POP

#endif /* CLXX_COMMON_OPENCL_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
