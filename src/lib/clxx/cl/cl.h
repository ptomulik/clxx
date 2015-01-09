// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

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
