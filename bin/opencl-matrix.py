#! /usr/bin/env python

# Copyright (c) 2015 by Pawel Tomulik <ptomulik@meil.pw.edu.pl>
# Licensed under MIT license (LICENSE.txt)

import argparse
import textwrap
import sys
import os
import re
import tempfile
import shutil
import subprocess
import platform
import glob
import hoarder
import json

script    = os.path.realpath(sys.argv[0])
scriptdir = os.path.dirname(script)
patchdir  = os.path.join(scriptdir, 'patches')
topsrcdir = os.path.realpath(os.path.join(scriptdir, '..'))

opencl_versions = [
        '1.0',
        '1.1',
        '1.2',
        '2.0',
        '2.1',
        '2.2'
]


parser = argparse.ArgumentParser(
        prog='opencl-matrix.py',
        description="""\
        Builds a matrix of availability of OpenCL functions in particular
        versions of the OpenCL standard. The information is extracted from
        header files for OpenCL 1.0, 1.1, etc..
        """)

parser.add_argument('--quiet', action='store_true', help='do not print messages')
parser.add_argument(
        '--cxx',
        type=str,
        default='gcc',
        metavar='CXX',
        help='select compiler'
        )
##parser.add_argument(
##        '--opencl-ver',
##        type=opencl_version_string,
##        default=default_opencl_version,
##        metavar='VER',
##        help='version of OpenCL headers/loader to be downloaded'
##        )
##
##parser.add_argument(
##        'packages',
##        metavar='PKG',
##        type=str,
##        nargs='*',
##        default = all_packages,
##        help='package to download (cxxtest, opencl-icd-ldr, opencl-hdr, scons, scons-arguments, scons-arguments-gnuinstall)'
##        )

args = parser.parse_args()

def info(msg, **kw):
    try: quiet = kw['quiet']
    except KeyError: quiet = False
    if not quiet:
        sys.stdout.write("info: %s\n" % msg)

def warn(msg, **kw):
    try: quiet = kw['quiet']
    except KeyError: quiet = False
    if not quiet:
        sys.stderr.write("warning: %s\n" % msg)

def dload_patch(**kw):
    """Download python-patch by Anatoly Techtonik"""
    try: destdir = kw['destdir']
    except KeyError: destdir = os.path.join(scriptdir,'hoarder')
    dest = os.path.join(destdir, 'patch.py')
    url = "https://raw.githubusercontent.com/techtonik/python-patch/master/patch.py"
    info("downloading '%s' -> '%s'" % (url, dest), **kw)
    hoarder.urlretrieve(url, dest)
    return 0

try: import hoarder.patch
except ImportError:
    dload_patch()
    import hoarder.patch

def dload_egl_hdr(**kw):
    """Download EGL header files"""
    try: clean = kw['clean']
    except KeyError: clean = False
    try: destdir = kw['destdir']
    except KeyError: destdir = os.path.join(topsrcdir, 'ext','EGL','include', 'EGL')

    destdir = os.path.split(destdir)[0]
    destdir_egl = os.path.join(destdir, 'EGL')
    destdir_khr = os.path.join(destdir, 'KHR')

    if clean:
        for d in (destdir_egl, destdir_khr):
            if os.path.exists(d):
                info("removing '%s'" % d, **kw)
                shutil.rmtree(d)
        return 0

    ver = None
    for k in ('egl_hdr_ver', 'egl_ver'):
        if ver is None:
            try: ver = kw[k]
            except KeyError: ver = None
    if ver is None:
        ver = default_egl_version

    try: destdir_mode = kw['destdir_mode']
    except KeyError: destdir_mode = 0755

    for d in (destdir_egl, destdir_khr):
        if os.path.exists(d):
            warn("'%s' already exists, skipping egl-hdr download!" % d, **kw)
            return 2

    for d in (destdir_egl, destdir_khr):
        info("creating '%s'" % d, **kw)
        os.makedirs(d, mode=destdir_mode)

    url_base = "https://www.khronos.org/registry/egl/api"
    if ver == '1.5':
        files = [   'EGL/egl.h',
                    'EGL/eglext.h',
                    'EGL/eglplatform.h',
                    'KHR/khrplatform.h' ]
    else:
        warn("unsupported EGL version '%s'" % ver, **kw)
        return 2

    for f in files:
        src = '/'.join([url_base, f])
        dst = os.path.join(destdir,os.path.join(*f.split('/')))
        info("downloading '%s' -> '%s'" % (src, dst), **kw)
        hoarder.urlretrieve(src, dst)

    return 0

def dload_opencl_hdr(**kw):
    """Download OpenCL header files"""

    try: clean = kw['clean']
    except KeyError: clean = False
    try: destdir = kw['destdir']
    except KeyError: destdir = os.path.join(topsrcdir, 'ext','OpenCL','include','CL')

    if clean:
        if os.path.exists(destdir):
            info("removing '%s'" % destdir, **kw)
            shutil.rmtree(destdir)
        return 0

    ver = None
    for k in ('opencl_hdr_ver', 'opencl_ver'):
        if ver is None:
            try: ver = kw[k]
            except KeyError: ver = None
    if ver is None:
        warn('OpenCL version not given, aborting!', **kw)
        return 1

    try: destdir_mode = kw['destdir_mode']
    except KeyError: destdir_mode = 0755

    if os.path.exists(destdir):
        warn("'%s' already exists, skipping opencl-hdr download!" % destdir, **kw)
        return 2

    info("creating '%s'" % destdir, **kw)
    os.makedirs(destdir, mode=destdir_mode)

    #url_base = "https://www.khronos.org/registry/cl/api/%s" % ver
    url_base = "https://raw.githubusercontent.com/KhronosGroup/OpenCL-Headers/opencl%s" % ''.join(ver.split('.'))
    patchfile = None
    if ver == '1.0':
        files = [   'cl.h',
                    'cl.hpp',
                    'cl_d3d10.h',
                    'cl_ext.h',
                    'cl_gl.h',
                    'cl_gl_ext.h',
                    'cl_platform.h',
                    'opencl.h'  ]
    elif ver == '1.1':
        files = [   'cl.h',
                    'cl.hpp',
                    'cl_d3d10.h',
                    'cl_ext.h',
                    'cl_gl.h',
                    'cl_gl_ext.h',
                    'cl_platform.h',
                    'opencl.h'  ]
    elif ver == '1.2':
        files = [   'cl.h',
                    'cl_d3d10.h',
                    'cl_d3d11.h',
                    'cl_dx9_media_sharing.h',
                    'cl_egl.h',
                    'cl_ext.h',
                    'cl_gl.h',
                    'cl_gl_ext.h',
                    'cl_platform.h',
                    'opencl.h'  ]
    elif ver == '2.0':
        files = [   'cl.h',
                    'cl_d3d10.h',
                    'cl_d3d11.h',
                    'cl_dx9_media_sharing.h',
                    'cl_egl.h',
                    'cl_ext.h',
                    'cl_gl.h',
                    'cl_gl_ext.h',
                    'cl_platform.h',
                    'opencl.h' ]
        patchfile = 'opencl-hdr-2.0.patch'
    elif ver == '2.1':
        files = [   'cl.h',
                    'cl_d3d10.h',
                    'cl_d3d11.h',
                    'cl_dx9_media_sharing.h',
                    'cl_dx9_media_sharing_intel.h',
                    'cl_egl.h',
                    'cl_ext.h',
                    'cl_ext_intel.h',
                    'cl_gl.h',
                    'cl_gl_ext.h',
                    'cl_platform.h',
                    'cl_via_api_media_sharing_intel.h',
                    'opencl.h' ]
    elif ver == '2.2':
        url_base = "https://github.com/KhronosGroup/OpenCL-Headers/raw/master/opencl22/CL"
        files = [   'cl.h',
                    'cl_d3d10.h',
                    'cl_d3d11.h',
                    'cl_dx9_media_sharing.h',
                    'cl_dx9_media_sharing_intel.h',
                    'cl_egl.h',
                    'cl_ext.h',
                    'cl_ext_intel.h',
                    'cl_gl.h',
                    'cl_gl_ext.h',
                    'cl_platform.h',
                    'cl_via_api_media_sharing_intel.h',
                    'opencl.h' ]
    else:
        warn("unsupported OpenCL version '%s'" % ver, **kw)
        return 2

    for f in files:
        src = '/'.join([url_base, f])
        dst = os.path.join(destdir,f)
        info("downloading '%s' -> '%s'" % (src, dst), **kw)
        hoarder.urlretrieve(src, dst)

    if patchfile:
        patchfile = os.path.join(patchdir, patchfile)
        info("reading patch file '%s'" % patchfile, **kw)
        patch = hoarder.patch.fromfile(patchfile)
        info("applying patch '%s'" % patchfile, **kw)
        patch.apply(strip=1, root=destdir)

    return 0

def try_compile(message, **kw):
    cxx = kw.get('cxx', 'gcc')
    cflags = kw.get('cflags', [])
    incpath = kw.get('incpath', [])
    outfile = kw.get('outfile', os.path.join(tmpdir, 'a.o'))
    code = kw.get('code', '\n')
    for ip in incpath:
        cflags = list(cflags) + ['-I', ip]
    env = os.environ.copy()
    #build_cmd = "%s -c -o %s -x c %s -" % (cxx, outfile, ' '.join(cflags))
    build_cmd = [cxx, '-c', '-o', outfile, '-x', 'c' ] + cflags + ['-']
    p = subprocess.Popen(build_cmd, env = env, cwd = tmpdir, stdin=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines = True)
    p.stdin.write(code)
    p.stdin.close()
    err = p.wait()
    cmdline = subprocess.list2cmdline(build_cmd)
    if err != 0:
        ok = 'no'
    else:
        ok = 'yes'
    info("%s... %s" % (message, ok), **kw)
    logfile = kw.get('logfile', os.path.join(tmpdir, 'opencl-matrix.log'))
    with open(logfile, 'a+') as fd:
        fd.write("%s... %s\n" % (message, ok))
        fd.write("%s\n" % cmdline)
        fd.write(p.stderr.read())
        fd.write("%s\n" % re.sub(r'^', r'| ', code, flags=re.M))
    return err


tmpdir = tempfile.mkdtemp()
info("created '%s'" % tmpdir, **vars(args))

fcn_matrix = []

# Download all versions of OpenCL headers
for ver in opencl_versions:
    destdir = os.path.join(tmpdir, 'include', 'OpenCL', ver, 'CL')
    dload_opencl_hdr(destdir = destdir, opencl_ver = ver)

cl_h_functions = [
  ('clBuildProgram', 'clBuildProgram((cl_program)NULL,(cl_uint)0u,(const cl_device_id*)NULL,(const char*)NULL, (void(CL_CALLBACK*)(cl_program,void*))NULL,(void*)NULL)', 'CL/cl.h'),
  ('clCloneKernel', 'clCloneKernel((cl_kernel)NULL,(cl_int*)NULL)', 'CL/cl.h'),
##  ('clCompileProgram', 'clCompileProgram(???)', 'CL/cl.h'),
##  ('clCreateBuffer', 'clCreateBuffer(???)', 'CL/cl.h'),
##  ('clCreateCommandQueue', 'clCreateCommandQueue(???)', 'CL/cl.h'),
##  ('clCreateCommandQueueWithProperties', 'clCreateCommandQueueWithProperties(???)', 'CL/cl.h'),
##  ('clCreateContext', 'clCreateContext(???)', 'CL/cl.h'),
##  ('clCreateContextFromType', 'clCreateContextFromType(???)', 'CL/cl.h'),
##  ('clCreateFromGLBuffer', 'clCreateFromGLBuffer(???)', 'CL/cl.h'),
##  ('clCreateFromGLRenderbuffer', 'clCreateFromGLRenderbuffer(???)', 'CL/cl.h'),
##  ('clCreateFromGLTexture', 'clCreateFromGLTexture(???)', 'CL/cl.h'),
##  ('clCreateFromGLTexture2D', 'clCreateFromGLTexture2D(???)', 'CL/cl.h'),
##  ('clCreateFromGLTexture3D', 'clCreateFromGLTexture3D(???)', 'CL/cl.h'),
##  ('clCreateImage', 'clCreateImage(???)', 'CL/cl.h'),
##  ('clCreateImage2D', 'clCreateImage2D(???)', 'CL/cl.h'),
##  ('clCreateImage3D', 'clCreateImage3D(???)', 'CL/cl.h'),
##  ('clCreateKernel', 'clCreateKernel(???)', 'CL/cl.h'),
##  ('clCreateKernelsInProgram', 'clCreateKernelsInProgram(???)', 'CL/cl.h'),
##  ('clCreatePipe', 'clCreatePipe(???)', 'CL/cl.h'),
##  ('clCreateProgramWithBinary', 'clCreateProgramWithBinary(???)', 'CL/cl.h'),
##  ('clCreateProgramWithBuiltInKernels', 'clCreateProgramWithBuiltInKernels(???)', 'CL/cl.h'),
##  ('clCreateProgramWithIL', 'clCreateProgramWithIL(???)', 'CL/cl.h'),
##  ('clCreateProgramWithSource', 'clCreateProgramWithSource(???)', 'CL/cl.h'),
##  ('clCreateSampler', 'clCreateSampler(???)', 'CL/cl.h'),
##  ('clCreateSamplerWithProperties', 'clCreateSamplerWithProperties(???)', 'CL/cl.h'),
##  ('clCreateSubBuffer', 'clCreateSubBuffer(???)', 'CL/cl.h'),
##  ('clCreateSubDevices', 'clCreateSubDevices(???)', 'CL/cl.h'),
##  ('clCreateUserEvent', 'clCreateUserEvent(???)', 'CL/cl.h'),
##  ('clEnqueueAcquireGLObjects', 'clEnqueueAcquireGLObjects(???)', 'CL/cl.h'),
##  ('clEnqueueBarrier', 'clEnqueueBarrier(???)', 'CL/cl.h'),
##  ('clEnqueueBarrierWithWaitList', 'clEnqueueBarrierWithWaitList(???)', 'CL/cl.h'),
##  ('clEnqueueCopyBuffer', 'clEnqueueCopyBuffer(???)', 'CL/cl.h'),
##  ('clEnqueueCopyBufferRect', 'clEnqueueCopyBufferRect(???)', 'CL/cl.h'),
##  ('clEnqueueCopyBufferToImage', 'clEnqueueCopyBufferToImage(???)', 'CL/cl.h'),
##  ('clEnqueueCopyImage', 'clEnqueueCopyImage(???)', 'CL/cl.h'),
##  ('clEnqueueCopyImageToBuffer', 'clEnqueueCopyImageToBuffer(???)', 'CL/cl.h'),
##  ('clEnqueueFillBuffer', 'clEnqueueFillBuffer(???)', 'CL/cl.h'),
##  ('clEnqueueFillImage', 'clEnqueueFillImage(???)', 'CL/cl.h'),
##  ('clEnqueueMapBuffer', 'clEnqueueMapBuffer(???)', 'CL/cl.h'),
##  ('clEnqueueMapImage', 'clEnqueueMapImage(???)', 'CL/cl.h'),
##  ('clEnqueueMarker', 'clEnqueueMarker(???)', 'CL/cl.h'),
##  ('clEnqueueMarkerWithWaitList', 'clEnqueueMarkerWithWaitList(???)', 'CL/cl.h'),
##  ('clEnqueueMigrateMemObjects', 'clEnqueueMigrateMemObjects(???)', 'CL/cl.h'),
##  ('clEnqueueNativeKernel', 'clEnqueueNativeKernel(???)', 'CL/cl.h'),
##  ('clEnqueueNDRangeKernel', 'clEnqueueNDRangeKernel(???)', 'CL/cl.h'),
##  ('clEnqueueReadBuffer', 'clEnqueueReadBuffer(???)', 'CL/cl.h'),
##  ('clEnqueueReadBufferRect', 'clEnqueueReadBufferRect(???)', 'CL/cl.h'),
##  ('clEnqueueReadImage', 'clEnqueueReadImage(???)', 'CL/cl.h'),
##  ('clEnqueueReleaseGLObjects', 'clEnqueueReleaseGLObjects(???)', 'CL/cl.h'),
##  ('clEnqueueSVMFree', 'clEnqueueSVMFree(???)', 'CL/cl.h'),
##  ('clEnqueueSVMMap', 'clEnqueueSVMMap(???)', 'CL/cl.h'),
##  ('clEnqueueSVMMemcpy', 'clEnqueueSVMMemcpy(???)', 'CL/cl.h'),
##  ('clEnqueueSVMMemFill', 'clEnqueueSVMMemFill(???)', 'CL/cl.h'),
##  ('clEnqueueSVMMigrateMem', 'clEnqueueSVMMigrateMem(???)', 'CL/cl.h'),
##  ('clEnqueueSVMUnmap', 'clEnqueueSVMUnmap(???)', 'CL/cl.h'),
##  ('clEnqueueTask', 'clEnqueueTask(???)', 'CL/cl.h'),
##  ('clEnqueueUnmapMemObject', 'clEnqueueUnmapMemObject(???)', 'CL/cl.h'),
##  ('clEnqueueWaitForEvents', 'clEnqueueWaitForEvents(???)', 'CL/cl.h'),
##  ('clEnqueueWriteBuffer', 'clEnqueueWriteBuffer(???)', 'CL/cl.h'),
##  ('clEnqueueWriteBufferRect', 'clEnqueueWriteBufferRect(???)', 'CL/cl.h'),
##  ('clEnqueueWriteImage', 'clEnqueueWriteImage(???)', 'CL/cl.h'),
##  ('clFinish', 'clFinish(???)', 'CL/cl.h'),
##  ('clFlush', 'clFlush(???)', 'CL/cl.h'),
##  ('clGetCommandQueueInfo', 'clGetCommandQueueInfo(???)', 'CL/cl.h'),
##  ('clGetContextInfo', 'clGetContextInfo(???)', 'CL/cl.h'),
##  ('clGetDeviceAndHostTimer', 'clGetDeviceAndHostTimer(???)', 'CL/cl.h'),
##  ('clGetDeviceIDs', 'clGetDeviceIDs(???)', 'CL/cl.h'),
##  ('clGetDeviceInfo', 'clGetDeviceInfo(???)', 'CL/cl.h'),
##  ('clGetEventInfo', 'clGetEventInfo(???)', 'CL/cl.h'),
##  ('clGetEventProfilingInfo', 'clGetEventProfilingInfo(???)', 'CL/cl.h'),
##  ('clGetExtensionFunctionAddress', 'clGetExtensionFunctionAddress(???)', 'CL/cl.h'),
##  ('clGetExtensionFunctionAddressForPlatform', 'clGetExtensionFunctionAddressForPlatform(???)', 'CL/cl.h'),
##  ('clGetGLObjectInfo', 'clGetGLObjectInfo(???)', 'CL/cl.h'),
##  ('clGetGLTextureInfo', 'clGetGLTextureInfo(???)', 'CL/cl.h'),
##  ('clGetHostTimer', 'clGetHostTimer(???)', 'CL/cl.h'),
##  ('clGetImageInfo', 'clGetImageInfo(???)', 'CL/cl.h'),
##  ('clGetKernelArgInfo', 'clGetKernelArgInfo(???)', 'CL/cl.h'),
##  ('clGetKernelInfo', 'clGetKernelInfo(???)', 'CL/cl.h'),
##  ('clGetKernelSubGroupInfo', 'clGetKernelSubGroupInfo(???)', 'CL/cl.h'),
##  ('clGetKernelWorkGroupInfo', 'clGetKernelWorkGroupInfo(???)', 'CL/cl.h'),
##  ('clGetMemObjectInfo', 'clGetMemObjectInfo(???)', 'CL/cl.h'),
##  ('clGetPipeInfo', 'clGetPipeInfo(???)', 'CL/cl.h'),
##  ('clGetPlatformIDs', 'clGetPlatformIDs(???)', 'CL/cl.h'),
##  ('clGetPlatformInfo', 'clGetPlatformInfo(???)', 'CL/cl.h'),
##  ('clGetProgramBuildInfo', 'clGetProgramBuildInfo(???)', 'CL/cl.h'),
##  ('clGetProgramInfo', 'clGetProgramInfo(???)', 'CL/cl.h'),
##  ('clGetSamplerInfo', 'clGetSamplerInfo(???)', 'CL/cl.h'),
##  ('clGetSupportedImageFormats', 'clGetSupportedImageFormats(???)', 'CL/cl.h'),
##  ('clLinkProgram', 'clLinkProgram(???)', 'CL/cl.h'),
##  ('clReleaseCommandQueue', 'clReleaseCommandQueue(???)', 'CL/cl.h'),
##  ('clReleaseContext', 'clReleaseContext(???)', 'CL/cl.h'),
##  ('clReleaseDevice', 'clReleaseDevice(???)', 'CL/cl.h'),
##  ('clReleaseEvent', 'clReleaseEvent(???)', 'CL/cl.h'),
##  ('clReleaseKernel', 'clReleaseKernel(???)', 'CL/cl.h'),
##  ('clReleaseMemObject', 'clReleaseMemObject(???)', 'CL/cl.h'),
##  ('clReleaseProgram', 'clReleaseProgram(???)', 'CL/cl.h'),
##  ('clReleaseSampler', 'clReleaseSampler(???)', 'CL/cl.h'),
##  ('clRetainCommandQueue', 'clRetainCommandQueue(???)', 'CL/cl.h'),
##  ('clRetainContext', 'clRetainContext(???)', 'CL/cl.h'),
##  ('clRetainDevice', 'clRetainDevice(???)', 'CL/cl.h'),
##  ('clRetainEvent', 'clRetainEvent(???)', 'CL/cl.h'),
##  ('clRetainKernel', 'clRetainKernel(???)', 'CL/cl.h'),
##  ('clRetainMemObject', 'clRetainMemObject(???)', 'CL/cl.h'),
##  ('clRetainProgram', 'clRetainProgram(???)', 'CL/cl.h'),
##  ('clRetainSampler', 'clRetainSampler(???)', 'CL/cl.h'),
##  ('clSetCommandQueueProperty', 'clSetCommandQueueProperty(???)', 'CL/cl.h'),
##  ('clSetDefaultDeviceCommandQueue', 'clSetDefaultDeviceCommandQueue(???)', 'CL/cl.h'),
##  ('clSetEventCallback', 'clSetEventCallback(???)', 'CL/cl.h'),
##  ('clSetKernelArg', 'clSetKernelArg(???)', 'CL/cl.h'),
##  ('clSetKernelArgSVMPointer', 'clSetKernelArgSVMPointer(???)', 'CL/cl.h'),
##  ('clSetKernelExecInfo', 'clSetKernelExecInfo(???)', 'CL/cl.h'),
##  ('clSetMemObjectDestructorCallback', 'clSetMemObjectDestructorCallback(???)', 'CL/cl.h'),
##  ('clSetProgramReleaseCallback', 'clSetProgramReleaseCallback(???)', 'CL/cl.h'),
##  ('clSetProgramSpecializationConstant', 'clSetProgramSpecializationConstant(???)', 'CL/cl.h'),
##  ('clSetUserEventStatus', 'clSetUserEventStatus(???)', 'CL/cl.h'),
##  ('clSVMAlloc', 'clSVMAlloc(???)', 'CL/cl.h'),
##  ('clSVMFree', 'clSVMFree(???)', 'CL/cl.h'),
##  ('clUnloadCompiler', 'clUnloadCompiler(???)', 'CL/cl.h'),
##  ('clUnloadPlatformCompiler', 'clUnloadPlatformCompiler(???)', 'CL/cl.h'),
##  ('clWaitForEvents', 'clWaitForEvents(???)', 'CL/cl.h'),
]

resultdict = dict()
logfile = os.path.join(tmpdir, 'opencl-matrix.log')
info('writting log to %s' % logfile, **vars(args))

for fcnent in cl_h_functions:
    (fcn, call, hdr) = fcnent
    code = """#include <%(hdr)s>
int main(int argc, char* argv[]) {
  (void)argc;
  (void)argv;
  %(call)s;
  return 0;
}""" % {'fcn' : fcn, 'call' : call, 'hdr' : hdr}
    resultdict[fcn] = {'fcn' : fcn, 'hdr' : hdr, 'call' : call, 'matrix' : dict()}
    for ver in opencl_versions:
        incpath = os.path.join(tmpdir, 'include', 'OpenCL', ver)
        outfile = os.path.join(tmpdir, '%s_%s.o' % (fcn, ver))
        cflagseq = [ ('-Wall','-Wno-deprecated','-pedantic','-Werror'),
                     ('-Wall','-pedantic','-Werror') ]
        msgseq =   [ "checking for possibly deprecated %s in %s (OpenCL %s)" % (fcn, hdr, ver),
                     "checking for non-deprecated %s in %s (OpenCL %s)" % (fcn, hdr, ver) ]
        errlist = []
        for i in range(len(cflagseq)):
            cflags = cflagseq[i]
            message = msgseq[i]
            err = try_compile( message,
                               outfile=outfile,
                               code=code,
                               incpath=[incpath],
                               cflags=cflags,
                               logfile=logfile,
                               **vars(args))
            errlist.append(err)
        if errlist[0] != 0:
            resultdict[fcn]['matrix'][ver] = '-'
        elif errlist[1] != 0:
            resultdict[fcn]['matrix'][ver] = 'd'
        else:
            resultdict[fcn]['matrix'][ver] = '+'

print(json.dumps(resultdict))

# Local Variables:
# # tab-width:4
# # indent-tabs-mode:nil
# # End:
# vim: set syntax=python expandtab tabstop=4 shiftwidth=4:
