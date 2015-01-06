/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE
 */

%import <clxx/config.h>

#if HAVE_OPENCL_CL_H_VERSION_1_2

%{
#include <CL/cl.h>
%}

/* XXX: This is necessary for "stdint.i" to choose proper declaration of intptr_t
 *      which is used in turn by CL/cl.h */
#ifdef CLXX_ARCH_64BIT
#  define SWIGWORDSIZE64
#else
#  define SWIGWORDSIZE32
#endif
#define __attribute__(x)
#define __extension__
/* not usable */
// present in 1.0 and 1.1 but not in 1.2
%ignore clSetCommandQueueProperty;
// present in 1.1 but not in 1.2
%ignore clCreateSubDevicesEXT;
%ignore clReleaseDeviceEXT;
%ignore clRetainDeviceEXT;
//
%include <stdint.i>
%include <CL/cl_platform.h>
%include <CL/cl.h>

#endif

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
