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

%{
#include <CL/cl.h>
%}

%import <clxx/config.h>
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
%ignore clSetPrintfCallback;
/* deprecated */
%ignore clEnqueueMarker;
%ignore clEnqueueWaitForEvents;
%ignore clEnqueueBarrier;
%ignore clUnloadCompiler;
%ignore clGetExtensionFunctionAddress;
%ignore clCreateImage2D;
%ignore clCreateImage3D;
%include <stdint.i>
%include <CL/cl_platform.h>
%include <CL/cl.h>
