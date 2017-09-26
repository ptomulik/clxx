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
  ('clBuildProgram', 'CL/cl.h', 'build_program'),
  ('clCloneKernel', 'CL/cl.h', 'clone_kernel'),
  ('clCompileProgram', 'CL/cl.h', 'compile_program'),
  ('clCreateBuffer', 'CL/cl.h', 'create_buffer'),
  ('clCreateCommandQueue', 'CL/cl.h', 'create_command_queue'),
  ('clCreateCommandQueueWithProperties', 'CL/cl.h', 'create_command_queue_with_properties'),
  ('clCreateContext', 'CL/cl.h', 'create_context'),
  ('clCreateContextFromType', 'CL/cl.h', 'create_context_from_type'),
  ('clCreateImage', 'CL/cl.h', 'create_image'),
  ('clCreateImage2D', 'CL/cl.h', 'create_image_2d'),
  ('clCreateImage3D', 'CL/cl.h', 'create_image_3d'),
  ('clCreateKernel', 'CL/cl.h', 'create_kernel'),
  ('clCreateKernelsInProgram', 'CL/cl.h', 'create_kernels_in_program'),
  ('clCreatePipe', 'CL/cl.h', 'create_pipe'),
  ('clCreateProgramWithBinary', 'CL/cl.h', 'create_program_with_binary'),
  ('clCreateProgramWithBuiltInKernels', 'CL/cl.h', 'create_program_with_built_in_kernels'),
  ('clCreateProgramWithIL', 'CL/cl.h', 'create_program_with_il'),
  ('clCreateProgramWithSource', 'CL/cl.h', 'create_program_with_source'),
  ('clCreateSampler', 'CL/cl.h', 'create_sampler'),
  ('clCreateSamplerWithProperties', 'CL/cl.h', 'create_sampler_with_properties'),
  ('clCreateSubBuffer', 'CL/cl.h', 'create_sub_buffer'),
  ('clCreateSubDevices', 'CL/cl.h', 'create_sub_devices'),
  ('clCreateUserEvent', 'CL/cl.h', 'create_user_event'),
  ('clEnqueueBarrier', 'CL/cl.h', 'enqueue_barrier'),
  ('clEnqueueBarrierWithWaitList', 'CL/cl.h', 'enqueue_barrier_with_wait_list'),
  ('clEnqueueCopyBuffer', 'CL/cl.h', 'enqueue_copy_buffer'),
  ('clEnqueueCopyBufferRect', 'CL/cl.h', 'enqueue_copy_buffer_rect'),
  ('clEnqueueCopyBufferToImage', 'CL/cl.h', 'enqueue_copy_buffer_to_image'),
  ('clEnqueueCopyImage', 'CL/cl.h', 'enqueue_copy_image'),
  ('clEnqueueCopyImageToBuffer', 'CL/cl.h', 'enqueue_copy_image_to_buffer'),
  ('clEnqueueFillBuffer', 'CL/cl.h', 'enqueue_fill_buffer'),
  ('clEnqueueFillImage', 'CL/cl.h', 'enqueue_fill_image'),
  ('clEnqueueMapBuffer', 'CL/cl.h', 'enqueue_map_buffer'),
  ('clEnqueueMapImage', 'CL/cl.h', 'enqueue_map_image'),
  ('clEnqueueMarker', 'CL/cl.h', 'enqueue_marker'),
  ('clEnqueueMarkerWithWaitList', 'CL/cl.h', 'enqueue_marker_with_wait_list'),
  ('clEnqueueMigrateMemObjects', 'CL/cl.h', 'enqueue_migrate_mem_objects'),
  ('clEnqueueNativeKernel', 'CL/cl.h', 'enqueue_native_kernel'),
  ('clEnqueueNDRangeKernel', 'CL/cl.h', 'enqueue_ndrange_kernel'),
  ('clEnqueueReadBuffer', 'CL/cl.h', 'enqueue_read_buffer'),
  ('clEnqueueReadBufferRect', 'CL/cl.h', 'enqueue_read_buffer_rect'),
  ('clEnqueueReadImage', 'CL/cl.h', 'enqueue_read_image'),
  ('clEnqueueSVMFree', 'CL/cl.h', 'enqueue_svm_free'),
  ('clEnqueueSVMMap', 'CL/cl.h', 'enqueue_svm_map'),
  ('clEnqueueSVMMemcpy', 'CL/cl.h', 'enqueue_svm_memcpy'),
  ('clEnqueueSVMMemFill', 'CL/cl.h', 'enqueue_svm_mem_fill'),
  ('clEnqueueSVMMigrateMem', 'CL/cl.h', 'enqueue_svm_migrate_mem'),
  ('clEnqueueSVMUnmap', 'CL/cl.h', 'enqueue_svm_unmap'),
  ('clEnqueueTask', 'CL/cl.h', 'enqueue_task'),
  ('clEnqueueUnmapMemObject', 'CL/cl.h', 'enqueue_unmap_mem_object'),
  ('clEnqueueWaitForEvents', 'CL/cl.h', 'enqueue_wait_for_events'),
  ('clEnqueueWriteBuffer', 'CL/cl.h', 'enqueue_write_buffer'),
  ('clEnqueueWriteBufferRect', 'CL/cl.h', 'enqueue_write_buffer_rect'),
  ('clEnqueueWriteImage', 'CL/cl.h', 'enqueue_write_image'),
  ('clFinish', 'CL/cl.h', 'finish'),
  ('clFlush', 'CL/cl.h', 'flush'),
  ('clGetCommandQueueInfo', 'CL/cl.h', 'get_command_queue_info'),
  ('clGetContextInfo', 'CL/cl.h', 'get_context_info'),
  ('clGetDeviceAndHostTimer', 'CL/cl.h', 'get_device_and_host_timer'),
  ('clGetDeviceIDs', 'CL/cl.h', 'get_device_ids'),
  ('clGetDeviceInfo', 'CL/cl.h', 'get_device_info'),
  ('clGetEventInfo', 'CL/cl.h', 'get_event_info'),
  ('clGetEventProfilingInfo', 'CL/cl.h', 'get_event_profiling_info'),
  ('clGetExtensionFunctionAddress', 'CL/cl.h', 'get_extension_function_address'),
  ('clGetExtensionFunctionAddressForPlatform', 'CL/cl.h', 'get_extension_function_address_for_platform'),
  ('clGetHostTimer', 'CL/cl.h', 'get_host_timer'),
  ('clGetImageInfo', 'CL/cl.h', 'get_image_info'),
  ('clGetKernelArgInfo', 'CL/cl.h', 'get_kernel_arg_info'),
  ('clGetKernelInfo', 'CL/cl.h', 'get_kernel_info'),
  ('clGetKernelSubGroupInfo', 'CL/cl.h', 'get_kernel_sub_group_info'),
  ('clGetKernelWorkGroupInfo', 'CL/cl.h', 'get_kernel_work_group_info'),
  ('clGetMemObjectInfo', 'CL/cl.h', 'get_mem_object_info'),
  ('clGetPipeInfo', 'CL/cl.h', 'get_pipe_info'),
  ('clGetPlatformIDs', 'CL/cl.h', 'get_platform_ids'),
  ('clGetPlatformInfo', 'CL/cl.h', 'get_platform_info'),
  ('clGetProgramBuildInfo', 'CL/cl.h', 'get_program_build_info'),
  ('clGetProgramInfo', 'CL/cl.h', 'get_program_info'),
  ('clGetSamplerInfo', 'CL/cl.h', 'get_sampler_info'),
  ('clGetSupportedImageFormats', 'CL/cl.h', 'get_supported_image_formats'),
  ('clLinkProgram', 'CL/cl.h', 'link_program'),
  ('clReleaseCommandQueue', 'CL/cl.h', 'release_command_queue'),
  ('clReleaseContext', 'CL/cl.h', 'release_context'),
  ('clReleaseDevice', 'CL/cl.h', 'release_device'),
  ('clReleaseEvent', 'CL/cl.h', 'release_event'),
  ('clReleaseKernel', 'CL/cl.h', 'release_kernel'),
  ('clReleaseMemObject', 'CL/cl.h', 'release_mem_object'),
  ('clReleaseProgram', 'CL/cl.h', 'release_program'),
  ('clReleaseSampler', 'CL/cl.h', 'release_sampler'),
  ('clRetainCommandQueue', 'CL/cl.h', 'retain_command_queue'),
  ('clRetainContext', 'CL/cl.h', 'retain_context'),
  ('clRetainDevice', 'CL/cl.h', 'retain_device'),
  ('clRetainEvent', 'CL/cl.h', 'retain_event'),
  ('clRetainKernel', 'CL/cl.h', 'retain_kernel'),
  ('clRetainMemObject', 'CL/cl.h', 'retain_mem_object'),
  ('clRetainProgram', 'CL/cl.h', 'retain_program'),
  ('clRetainSampler', 'CL/cl.h', 'retain_sampler'),
  ('clSetCommandQueueProperty', 'CL/cl.h', 'set_command_queue_property'),
  ('clSetDefaultDeviceCommandQueue', 'CL/cl.h', 'set_default_device_command_queue'),
  ('clSetEventCallback', 'CL/cl.h', 'set_event_callback'),
  ('clSetKernelArg', 'CL/cl.h', 'set_kernel_arg'),
  ('clSetKernelArgSVMPointer', 'CL/cl.h', 'set_kernel_arg_svm_pointer'),
  ('clSetKernelExecInfo', 'CL/cl.h', 'set_kernel_exec_info'),
  ('clSetMemObjectDestructorCallback', 'CL/cl.h', 'set_mem_object_destructor_callback'),
  ('clSetProgramReleaseCallback', 'CL/cl.h', 'set_program_release_callback'),
  ('clSetProgramSpecializationConstant', 'CL/cl.h', 'set_program_specialization_constant'),
  ('clSetUserEventStatus', 'CL/cl.h', 'set_user_event_status'),
  ('clSVMAlloc', 'CL/cl.h', 'svm_alloc'),
  ('clSVMFree', 'CL/cl.h', 'svm_free'),
  ('clUnloadCompiler', 'CL/cl.h', 'unload_compiler'),
  ('clUnloadPlatformCompiler', 'CL/cl.h', 'unload_platform_compiler'),
  ('clWaitForEvents', 'CL/cl.h', 'wait_for_events'),
]

cl_gl_h_functions = [
  ('clCreateFromGLBuffer', 'CL/cl_gl.h', 'create_from_gl_buffer'),
  ('clCreateFromGLRenderbuffer', 'CL/cl_gl.h', 'create_from_gl_renderbuffer'),
  ('clCreateFromGLTexture', 'CL/cl_gl.h', 'create_from_gl_texture'),
  ('clCreateFromGLTexture2D', 'CL/cl_gl.h', 'create_from_gl_texture_2d'),
  ('clCreateFromGLTexture3D', 'CL/cl_gl.h', 'create_from_gl_texture_3d'),
  ('clEnqueueAcquireGLObjects', 'CL/cl_gl.h', 'enqueue_acquire_gl_objects'),
  ('clEnqueueReleaseGLObjects', 'CL/cl_gl.h', 'enqueue_release_gl_objects'),
  ('clGetGLContextInfoKHR', 'CL/cl_gl.h', 'get_gl_context_info_khr'),
  ('clGetGLObjectInfo', 'CL/cl_gl.h', 'get_gl_object_info'),
  ('clGetGLTextureInfo', 'CL/cl_gl.h', 'get_gl_texture_info'),
]

functions_to_check = cl_h_functions + cl_gl_h_functions


parser = argparse.ArgumentParser(
        prog='cl-functions-config.py',
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
    outputlist = [ ':'.join(['Function', 'Header', 'CLXX Function'] + versions_to_check) ]
    for key in sorted(resultdict.keys(), lambda x,y : cmp(x.lower(),y.lower())):
        entry = resultdict[key]
        matrix = entry['matrix']
        outputlist.append( ':'.join( [entry['fcn'], entry['hdr'], entry['clxxfcn']] + [matrix[v] for v in versions_to_check] ) )
    return '\n'.join(outputlist)

def prepare_html_output(resultdict, **kw):
    outputlist = []
    outputlist.append( '<table class="cl-function-matrix">')
    outputlist.append( '  <tr>')
    outputlist.append( '    <th>Function</th>')
    outputlist.append( '    <th>Header</th>')
    outputlist.append( '    <th>CLXX Function</th>')
    outputlist.extend(['    <th>%s</th>' % v for v in versions_to_check])
    outputlist.append( '  </tr>')
    for key in sorted(resultdict.keys(), lambda x,y : cmp(x.lower(),y.lower())):
        entry = resultdict[key]
        matrix = entry['matrix']
        outputlist.append( '  <tr>')
        outputlist.append( '    <td class="cl-function">%s</th>' % entry['fcn'])
        outputlist.append( '    <td class="cl-header">%s</th>' % entry['hdr'])
        outputlist.append( '    <td class="cl-function">%s</th>' % entry['clxxfcn'])
        outputlist.extend(['    <td class="cl-check">%s</td>' % matrix[v] for v in versions_to_check])
        outputlist.append( '  </tr>')
    outputlist.append('</table>')
    return '\n'.join(outputlist)

def prepare_cpp_output(resultdict, **kw):
    outputlist = []
    outputlist.append(r'// @COPYRIGHT@')
    outputlist.append(r'// Licensed under MIT license (LICENSE.txt)')
    outputlist.append(r'')
    outputlist.append(r'// clxx/b5d/cl_functions_config.hpp')
    outputlist.append(r'')
    outputlist.append(r'/** // doc: clxx/b5d/cl_functions_config.hpp {{{')
    outputlist.append(r'* \file clxx/b5d/cl_functions_config.hpp')
    outputlist.append(r'* \todo Write documentation for clxx/b5d/cl_functions_config.hpp')
    outputlist.append(r'*/ // }}}')
    outputlist.append(r'#ifndef CLXX_B5D_CL_FUNCTIONS_CONFIG_HPP_INCLUDED')
    outputlist.append(r'#define CLXX_B5D_CL_FUNCTIONS_CONFIG_HPP_INCLUDED')
    outputlist.append(r'')
    outputlist.append(r'#include <clxx/b5d/cl_config_params.hpp>')
    outputlist.append(r'')
    outputlist.append(r'/* !!!!!!!!!!!!!!!!!!!!!!!!! WARNING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */')
    outputlist.append(r'/*    FILE GENERATED WITH bin/cl-functions-config.py. DO NOT MODIFY    */')
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
        clxxfcn = resultdict[fcn]['clxxfcn']
        outputlist.append('#define CLXX_B5D_OPENCL_DECLARES_%s 1 /* %s */' % (fcn,hdr))
        outputlist.append('#define CLXX_B5D_PROVIDES_%s 1' % clxxfcn)

    for ver in versions_to_check:
        versuffix = ver.replace('.', '_')
        if exists_ge[ver] or deprec_ge[ver] or exists_lt[ver]:
            outputlist.append('')
            outputlist.append('#if CLXX_B5D_OPENCL_CL_H_VERSION_%s /* OpenCL >= %s */' % (versuffix, ver))
            for fcn in exists_ge[ver]:
                hdr = resultdict[fcn]['hdr']
                clxxfcn =  resultdict[fcn]['clxxfcn']
                outputlist.append('# define CLXX_B5D_OPENCL_DECLARES_%s 1 /* %s */' % (fcn, hdr))
                outputlist.append('# define CLXX_B5D_PROVIDES_%s 1' % clxxfcn)
            for fcn in deprec_ge[ver]:
                hdr = resultdict[fcn]['hdr']
                clxxfcn =  resultdict[fcn]['clxxfcn']
                outputlist.append('# define CLXX_B5D_OPENCL_DEPRECATES_%s 1 /* %s */' % (fcn,hdr))
                outputlist.append('# define CLXX_B5D_DEPRECATES_%s 1' % clxxfcn)
            outputlist.append('#else /* OpenCL < %s */' % ver)
            for fcn in exists_lt[ver]:
                hdr = resultdict[fcn]['hdr']
                clxxfcn =  resultdict[fcn]['clxxfcn']
                outputlist.append('# define CLXX_B5D_OPENCL_DECLARES_%s 1 /* %s */' % (fcn,hdr))
                outputlist.append('# define CLXX_B5D_PROVIDES_%s 1' % clxxfcn)
            outputlist.append('#endif /* CLXX_B5D_OPENCL_CL_H_VERSION_%s */' % versuffix)
    for key in sorted(resultdict.keys(), lambda x,y: cmp(x.lower(), y.lower())):
        entry = resultdict[key]
        clxxfcn = entry['clxxfcn']
        outputlist.append('')
        outputlist.append('/* Auto-deprecation for %s */' % clxxfcn)
        outputlist.append('#if CLXX_B5D_DEPRECATES_%s' % clxxfcn)
        outputlist.append('# define CLXX_B5D_PREFIX_DEPRECATED_%s CLXX_B5D_DEPRECATION_PREFIX' % clxxfcn)
        outputlist.append('# define CLXX_B5D_SUFFIX_DEPRECATED_%s CLXX_B5D_DEPRECATION_SUFFIX' % clxxfcn)
        outputlist.append('#else')
        outputlist.append('# define CLXX_B5D_PREFIX_DEPRECATED_%s' % clxxfcn)
        outputlist.append('# define CLXX_B5D_SUFFIX_DEPRECATED_%s' % clxxfcn)
        outputlist.append('#endif')
    outputlist.append(r'')
    outputlist.append(r'#endif /* CLXX_B5D_CL_FUNCTIONS_CONFIG_HPP_INCLUDED */')
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
default_logfile = os.path.join(tmpdir, 'cl-functions-config.log')

jsoninput = vars(args).get('input')
if not jsoninput:
    if not reuse:
        # Download all versions of OpenCL headers
        for ver in versions_to_check:
            destdir = os.path.join(tmpdir, 'include', 'OpenCL', ver, 'CL')
            dload_opencl_hdr(destdir = destdir, opencl_ver = ver)

    resultdict = dict()

    for fcnent in functions_to_check:
        (fcn, hdr, clxxfcn) = fcnent
        code = """#include <%(hdr)s>
    int main(int argc, char* argv[]) {
      (void)argc;
      (void)argv;
      (void)%(fcn)s;
      return 0;
    }""" % {'fcn' : fcn, 'hdr' : hdr, 'clxxfcn' : clxxfcn}
        resultdict[fcn] = {'fcn' : fcn, 'hdr' : hdr, 'clxxfcn' : clxxfcn, 'matrix' : dict()}
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
