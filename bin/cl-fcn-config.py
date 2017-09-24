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

versions_to_check = [
        '1.0',
        '1.1',
        '1.2',
        '2.0',
        '2.1',
        '2.2'
]

cl_h_functions = [
  ('clBuildProgram', 'CL/cl.h'),
  ('clCloneKernel', 'CL/cl.h'),
  ('clCompileProgram', 'CL/cl.h'),
  ('clCreateBuffer', 'CL/cl.h'),
  ('clCreateCommandQueue', 'CL/cl.h'),
  ('clCreateCommandQueueWithProperties', 'CL/cl.h'),
  ('clCreateContext', 'CL/cl.h'),
  ('clCreateContextFromType', 'CL/cl.h'),
  ('clCreateImage', 'CL/cl.h'),
  ('clCreateImage2D', 'CL/cl.h'),
  ('clCreateImage3D', 'CL/cl.h'),
  ('clCreateKernel', 'CL/cl.h'),
  ('clCreateKernelsInProgram', 'CL/cl.h'),
  ('clCreatePipe', 'CL/cl.h'),
  ('clCreateProgramWithBinary', 'CL/cl.h'),
  ('clCreateProgramWithBuiltInKernels', 'CL/cl.h'),
  ('clCreateProgramWithIL', 'CL/cl.h'),
  ('clCreateProgramWithSource', 'CL/cl.h'),
  ('clCreateSampler', 'CL/cl.h'),
  ('clCreateSamplerWithProperties', 'CL/cl.h'),
  ('clCreateSubBuffer', 'CL/cl.h'),
  ('clCreateSubDevices', 'CL/cl.h'),
  ('clCreateUserEvent', 'CL/cl.h'),
  ('clEnqueueBarrier', 'CL/cl.h'),
  ('clEnqueueBarrierWithWaitList', 'CL/cl.h'),
  ('clEnqueueCopyBuffer', 'CL/cl.h'),
  ('clEnqueueCopyBufferRect', 'CL/cl.h'),
  ('clEnqueueCopyBufferToImage', 'CL/cl.h'),
  ('clEnqueueCopyImage', 'CL/cl.h'),
  ('clEnqueueCopyImageToBuffer', 'CL/cl.h'),
  ('clEnqueueFillBuffer', 'CL/cl.h'),
  ('clEnqueueFillImage', 'CL/cl.h'),
  ('clEnqueueMapBuffer', 'CL/cl.h'),
  ('clEnqueueMapImage', 'CL/cl.h'),
  ('clEnqueueMarker', 'CL/cl.h'),
  ('clEnqueueMarkerWithWaitList', 'CL/cl.h'),
  ('clEnqueueMigrateMemObjects', 'CL/cl.h'),
  ('clEnqueueNativeKernel', 'CL/cl.h'),
  ('clEnqueueNDRangeKernel', 'CL/cl.h'),
  ('clEnqueueReadBuffer', 'CL/cl.h'),
  ('clEnqueueReadBufferRect', 'CL/cl.h'),
  ('clEnqueueReadImage', 'CL/cl.h'),
  ('clEnqueueSVMFree', 'CL/cl.h'),
  ('clEnqueueSVMMap', 'CL/cl.h'),
  ('clEnqueueSVMMemcpy', 'CL/cl.h'),
  ('clEnqueueSVMMemFill', 'CL/cl.h'),
  ('clEnqueueSVMMigrateMem', 'CL/cl.h'),
  ('clEnqueueSVMUnmap', 'CL/cl.h'),
  ('clEnqueueTask', 'CL/cl.h'),
  ('clEnqueueUnmapMemObject', 'CL/cl.h'),
  ('clEnqueueWaitForEvents', 'CL/cl.h'),
  ('clEnqueueWriteBuffer', 'CL/cl.h'),
  ('clEnqueueWriteBufferRect', 'CL/cl.h'),
  ('clEnqueueWriteImage', 'CL/cl.h'),
  ('clFinish', 'CL/cl.h'),
  ('clFlush', 'CL/cl.h'),
  ('clGetCommandQueueInfo', 'CL/cl.h'),
  ('clGetContextInfo', 'CL/cl.h'),
  ('clGetDeviceAndHostTimer', 'CL/cl.h'),
  ('clGetDeviceIDs', 'CL/cl.h'),
  ('clGetDeviceInfo', 'CL/cl.h'),
  ('clGetEventInfo', 'CL/cl.h'),
  ('clGetEventProfilingInfo', 'CL/cl.h'),
  ('clGetExtensionFunctionAddress', 'CL/cl.h'),
  ('clGetExtensionFunctionAddressForPlatform', 'CL/cl.h'),
  ('clGetHostTimer', 'CL/cl.h'),
  ('clGetImageInfo', 'CL/cl.h'),
  ('clGetKernelArgInfo', 'CL/cl.h'),
  ('clGetKernelInfo', 'CL/cl.h'),
  ('clGetKernelSubGroupInfo', 'CL/cl.h'),
  ('clGetKernelWorkGroupInfo', 'CL/cl.h'),
  ('clGetMemObjectInfo', 'CL/cl.h'),
  ('clGetPipeInfo', 'CL/cl.h'),
  ('clGetPlatformIDs', 'CL/cl.h'),
  ('clGetPlatformInfo', 'CL/cl.h'),
  ('clGetProgramBuildInfo', 'CL/cl.h'),
  ('clGetProgramInfo', 'CL/cl.h'),
  ('clGetSamplerInfo', 'CL/cl.h'),
  ('clGetSupportedImageFormats', 'CL/cl.h'),
  ('clLinkProgram', 'CL/cl.h'),
  ('clReleaseCommandQueue', 'CL/cl.h'),
  ('clReleaseContext', 'CL/cl.h'),
  ('clReleaseDevice', 'CL/cl.h'),
  ('clReleaseEvent', 'CL/cl.h'),
  ('clReleaseKernel', 'CL/cl.h'),
  ('clReleaseMemObject', 'CL/cl.h'),
  ('clReleaseProgram', 'CL/cl.h'),
  ('clReleaseSampler', 'CL/cl.h'),
  ('clRetainCommandQueue', 'CL/cl.h'),
  ('clRetainContext', 'CL/cl.h'),
  ('clRetainDevice', 'CL/cl.h'),
  ('clRetainEvent', 'CL/cl.h'),
  ('clRetainKernel', 'CL/cl.h'),
  ('clRetainMemObject', 'CL/cl.h'),
  ('clRetainProgram', 'CL/cl.h'),
  ('clRetainSampler', 'CL/cl.h'),
  ('clSetCommandQueueProperty', 'CL/cl.h'),
  ('clSetDefaultDeviceCommandQueue', 'CL/cl.h'),
  ('clSetEventCallback', 'CL/cl.h'),
  ('clSetKernelArg', 'CL/cl.h'),
  ('clSetKernelArgSVMPointer', 'CL/cl.h'),
  ('clSetKernelExecInfo', 'CL/cl.h'),
  ('clSetMemObjectDestructorCallback', 'CL/cl.h'),
  ('clSetProgramReleaseCallback', 'CL/cl.h'),
  ('clSetProgramSpecializationConstant', 'CL/cl.h'),
  ('clSetUserEventStatus', 'CL/cl.h'),
  ('clSVMAlloc', 'CL/cl.h'),
  ('clSVMFree', 'CL/cl.h'),
  ('clUnloadCompiler', 'CL/cl.h'),
  ('clUnloadPlatformCompiler', 'CL/cl.h'),
  ('clWaitForEvents', 'CL/cl.h'),
]

cl_gl_h_functions = [
  ('clCreateFromGLBuffer', 'CL/cl_gl.h'),
  ('clCreateFromGLRenderbuffer', 'CL/cl_gl.h'),
  ('clCreateFromGLTexture', 'CL/cl_gl.h'),
  ('clCreateFromGLTexture2D', 'CL/cl_gl.h'),
  ('clCreateFromGLTexture3D', 'CL/cl_gl.h'),
  ('clEnqueueAcquireGLObjects', 'CL/cl_gl.h'),
  ('clEnqueueReleaseGLObjects', 'CL/cl_gl.h'),
  ('clGetGLContextInfoKHR', 'CL/cl_gl.h'),
  ('clGetGLObjectInfo', 'CL/cl_gl.h'),
  ('clGetGLTextureInfo', 'CL/cl_gl.h'),
]

functions_to_check = cl_h_functions + cl_gl_h_functions


parser = argparse.ArgumentParser(
        prog='cl-fcn-config.py',
        description="""\
        Builds a matrix of availability of OpenCL functions in particular
        versions of the OpenCL standard. The information is extracted from
        header files for OpenCL 1.0, 1.1, etc..
        """)
parser.add_argument('--quiet', '-q',
        action='store_true',
        help='do not print messages'
        )
parser.add_argument(
        '--cxx',
        type=str,
        default='gcc',
        metavar='CXX',
        help='select compiler'
        )
parser.add_argument(
        '--output', '-o',
        type=str,
        default='-',
        metavar='FILE',
        help='save result to FILE'
        )
parser.add_argument(
        '--log', '-l',
        type=str,
        metavar='FILE',
        help='save log to FILE'
        )
parser.add_argument(
        '--format', '-F',
        default='json',
        choices=('json', 'csv', 'html', 'cpp'),
        metavar='TYPE',
        help='select output format'
        )
parser.add_argument(
        '--tmpdir', '-d',
        type=str,
        metavar='DIR',
        help='use DIR to store temporary files'
        )
parser.add_argument(
        '--reuse', '-r',
        action='store_true',
        help='reuse previously downloaded files stored under --tmpdir'
        )
parser.add_argument(
        'input',
        metavar='FILE',
        type=str,
        nargs='?',
        help='json file from previous run'
        )
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

def get_logfile(**kw):
    logfile = kw.get('log', default_logfile)
    if logfile is None:
        logfile = default_logfile
    return logfile

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
    logfile = get_logfile(**kw)
    with open(logfile, 'a+') as fd:
        fd.write("%s... %s\n" % (message, ok))
        fd.write("%s\n" % cmdline)
        fd.write(p.stderr.read())
        fd.write("%s\n" % re.sub(r'^', r'| ', code, flags=re.M))
    return err

def check_result(resultdict, **kw):
    for key in sorted(resultdict.keys(), lambda x,y : cmp(x.lower(),y.lower())):
        entry = resultdict[key]
        matrix = entry['matrix']
        if '+' not in matrix.values() and 'd' not in matrix.values():
            warn("%s not found in any version of %s" % (entry['fcn'], entry['hdr']))

def prepare_csv_output(resultdict, **kw):
    outputlist = [ ':'.join(['Function', 'Header'] + versions_to_check) ]
    for key in sorted(resultdict.keys(), lambda x,y : cmp(x.lower(),y.lower())):
        entry = resultdict[key]
        matrix = entry['matrix']
        outputlist.append( ':'.join( [entry['fcn'], entry['hdr']] + [matrix[v] for v in versions_to_check] ) )
    return '\n'.join(outputlist)

def prepare_html_output(resultdict, **kw):
    outputlist = []
    outputlist.append( '<table class="cl-function-matrix">')
    outputlist.append( '  <tr>')
    outputlist.append( '    <th>Function</th>')
    outputlist.append( '    <th>Header</th>')
    outputlist.extend(['    <th>%s</th>' % v for v in versions_to_check])
    outputlist.append( '  </tr>')
    for key in sorted(resultdict.keys(), lambda x,y : cmp(x.lower(),y.lower())):
        entry = resultdict[key]
        matrix = entry['matrix']
        outputlist.append( '  <tr>')
        outputlist.append( '    <td class="cl-function">%s</th>' % entry['fcn'])
        outputlist.append( '    <td class="cl-header">%s</th>' % entry['hdr'])
        outputlist.extend(['    <td class="cl-check">%s</td>' % matrix[v] for v in versions_to_check])
        outputlist.append( '  </tr>')
    outputlist.append('</table>')
    return '\n'.join(outputlist)

def prepare_cpp_output(resultdict, **kw):
    outputlist = []
    outputlist.append(r'// @COPYRIGHT@')
    outputlist.append(r'// Licensed under MIT license (LICENSE.txt)')
    outputlist.append(r'')
    outputlist.append(r'// clxx/b5d/cl_fcn_config.hpp')
    outputlist.append(r'')
    outputlist.append(r'/** // doc: clxx/b5d/cl_fcn_config.hpp {{{')
    outputlist.append(r'* \file clxx/b5d/cl_fcn_config.hpp')
    outputlist.append(r'* \todo Write documentation for clxx/b5d/cl_fcn_config.hpp')
    outputlist.append(r'*/ // }}}')
    outputlist.append(r'#ifndef CLXX_B5D_CL_FCN_CONFIG_HPP_INCLUDED')
    outputlist.append(r'#define CLXX_B5D_CL_FCN_CONFIG_HPP_INCLUDED')
    outputlist.append(r'')
    outputlist.append(r'#include <clxx/b5d/config_params.hpp>')
    outputlist.append(r'')
    outputlist.append(r'/* !!!!!!!!!!!!!!!!!!!!!!!!! WARNING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */')
    outputlist.append(r'/*    FILE GENERATED WITH bin/cl-fcn-config.py. DO NOT MODIFY    */')
    outputlist.append(r'/* !!!!!!!!!!!!!!!!!!!!!!!!! WARNING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */')
    outputlist.append(r'')
    exists = []
    exists_ge = { v : [] for v in versions_to_check }
    exists_lt = { v : [] for v in versions_to_check }
    deprec_ge = { v : [] for v in versions_to_check }

    for key in sorted(resultdict.keys(), lambda x,y : cmp(x.lower(),y.lower())):
        entry = resultdict[key]
        fcn = entry['fcn']
        matrix = entry['matrix']
        missing = [v for v in versions_to_check if matrix[v] == '-']
        existing = [v for v in versions_to_check if matrix[v] != '-' ]
        deprecated = [v for v in versions_to_check if matrix[v] == 'd']
        if len(existing) == len(versions_to_check):
            exists.append(fcn)
        elif missing[-1].split('.') < existing[0].split('.'):
            exists_ge[existing[0]].append(fcn)
        else:
            exists_lt[missing[0]].append(fcn)
        if deprecated:
            deprec_ge[deprecated[0]].append(fcn)

    for fcn in exists:
        hdr = resultdict[fcn]['hdr']
        outputlist.append('#define CLXX_B5D_OPENCL_DECLARES_%s 1 /* %s */' % (fcn,hdr))

    for ver in versions_to_check:
        versuffix = ver.replace('.', '_')
        if exists_ge[ver] or deprec_ge[ver] or exists_lt[ver]:
            outputlist.append('')
            outputlist.append('#if CLXX_B5D_OPENCL_CL_H_VERSION_%s /* OpenCL >= %s */' % (versuffix, ver))
            for fcn in exists_ge[ver]:
                hdr = resultdict[fcn]['hdr']
                outputlist.append('# define CLXX_B5D_OPENCL_DECLARES_%s 1 /* %s */' % (fcn, hdr))
            for fcn in deprec_ge[ver]:
                hdr = resultdict[fcn]['hdr']
                outputlist.append('# define CLXX_B5D_OPENCL_DEPRECATES_%s 1 /* %s */' % (fcn,hdr))
            outputlist.append('#else /* OpenCL < %s */' % ver)
            for fcn in exists_lt[ver]:
                hdr = resultdict[fcn]['hdr']
                outputlist.append('# define CLXX_B5D_OPENCL_DECLARES_%s 1 /* %s */' % (fcn,hdr))
            outputlist.append('#endif /* CLXX_B5D_OPENCL_CL_H_VERSION_%s */' % versuffix)
    for key in sorted(resultdict.keys(), lambda x,y: cmp(x.lower(), y.lower())):
        entry = resultdict[key]
        fcn = entry['fcn']
        outputlist.append('')
        outputlist.append('/* Auto-deprecation for %s */' % fcn)
        outputlist.append('#if CLXX_B5D_OPENCL_DEPRECATES_%s' % fcn)
        outputlist.append('# define CLXX_B5D_PREFIX_DEPRECATED_%s CLXX_B5D_DEPRECATION_PREFIX' % fcn)
        outputlist.append('# define CLXX_B5D_SUFFIX_DEPRECATED_%s CLXX_B5D_DEPRECATION_SUFFIX' %fcn)
        outputlist.append('#else')
        outputlist.append('# define CLXX_B5D_PREFIX_DEPRECATED_%s' % fcn)
        outputlist.append('# define CLXX_B5D_SUFFIX_DEPRECATED_%s' % fcn)
        outputlist.append('#endif')
    outputlist.append(r'')
    outputlist.append(r'#endif /* CLXX_B5D_CL_FCN_CONFIG_HPP_INCLUDED */')
    outputlist.append(r'// vim: set expandtab tabstop=2 shiftwidth=2:')
    outputlist.append(r'// vim: set foldmethod=marker foldcolumn=4:')
    return '\n'.join(outputlist)


def output_result(resultdict, **kw):
    format = kw.get('format', 'json')
    if format == 'csv':
        output = prepare_csv_output(resultdict, **kw)
    elif format == 'html':
        output = prepare_html_output(resultdict, **kw)
    elif format == 'cpp':
        output = prepare_cpp_output(resultdict, **kw)
    else:
        output = json.dumps(resultdict)

    outfile = kw.get('output', '-')
    if outfile == '-':
            sys.stdout.write("%s\n" % output)
    else:
        with open(outfile, 'w') as fd:
            fd.write("%s\n" % output)
        info('wrote output to %s' % outfile, **kw)

tmpdir = vars(args).get('tmpdir')
reuse = vars(args).get('reuse')
if tmpdir:
    info("using directory '%s'" % tmpdir, **vars(args))
    if not os.path.exists(tmpdir):
        if reuse:
            warn("can't reuse empty directory, leaving", **vars(args))
            exit(1)
        info("creating directory '%s'" % tmpdir, **vars(args))
        os.makedirs(destdir, mode=0755)
else:
    if reuse:
        warn("can't reuse empty directory, leaving", **vars(args))
        exit(1)
    tmpdir = tempfile.mkdtemp()
    info("created '%s'" % tmpdir, **vars(args))
default_logfile = os.path.join(tmpdir, 'cl-fcn-config.log')

jsoninput = vars(args).get('input')
if not jsoninput:
    if not reuse:
        # Download all versions of OpenCL headers
        for ver in versions_to_check:
            destdir = os.path.join(tmpdir, 'include', 'OpenCL', ver, 'CL')
            dload_opencl_hdr(destdir = destdir, opencl_ver = ver)

    resultdict = dict()

    for fcnent in functions_to_check:
        (fcn, hdr) = fcnent
        code = """#include <%(hdr)s>
    int main(int argc, char* argv[]) {
      (void)argc;
      (void)argv;
      (void)%(fcn)s;
      return 0;
    }""" % {'fcn' : fcn, 'hdr' : hdr}
        resultdict[fcn] = {'fcn' : fcn, 'hdr' : hdr, 'matrix' : dict()}
        for ver in versions_to_check:
            incpath = os.path.join(tmpdir, 'include', 'OpenCL', ver)
            outfile = os.path.join(tmpdir, '%s_%s.o' % (fcn, ver))
            cflagseq = [ ('-Wno-deprecated-declarations', '-Werror'),
                         ('-Wdeprecated-declarations', '-Werror') ]
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
                                   **vars(args))
                errlist.append(err)
            if errlist[0] != 0:
                resultdict[fcn]['matrix'][ver] = '-'
            elif errlist[1] != 0:
                resultdict[fcn]['matrix'][ver] = 'd'
            else:
                resultdict[fcn]['matrix'][ver] = '+'
else:
    with open(jsoninput, 'r') as fd:
        resultdict = json.loads(fd.read())

check_result(resultdict, **vars(args))
output_result(resultdict, **vars(args))
info('wrote log to %s' % get_logfile(**vars(args)), **vars(args))
info('downloaded files left in "%s"' % tmpdir, **vars(args))

# Local Variables:
# # tab-width:4
# # indent-tabs-mode:nil
# # End:
# vim: set syntax=python expandtab tabstop=4 shiftwidth=4:
