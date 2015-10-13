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

script    = os.path.realpath(sys.argv[0])
scriptdir = os.path.dirname(script)
patchdir  = os.path.join(scriptdir, 'patches')
topsrcdir = os.path.realpath(os.path.join(scriptdir, '..'))


default_opencl_version = '2.0'
all_packages = ['cxxtest', 'opencl-hdr', 'opencl-ldr']

# Validate and return OpenCL version
def opencl_version_string(v):
    if not re.match(r'^1\.[0-2]|2\.0$', v):
        raise argparse.ArgumentTypeError("ill-formed or unsupported OpenCL version %r" % v)
    return v

parser = argparse.ArgumentParser(
        prog='download.py',
        description="""\
        This tool downloads predefined prerequisites (call it packages) for
        clxx project. You may cherry pick what packages are to be downloaded
        or simply download all (if you don't specify explicitly packages, all
        predefined packages are being downloaded). The downloaded stuff is
        placed in predefined subdirectories of the source tree such that they
        are later found automatically when the project is being built.
        """)

parser.add_argument('--quiet', action='store_true', help='do not print messages')
parser.add_argument('--clean', action='store_true', help='clean downloaded package(s)')

parser.add_argument(
        '--opencl-ver',
        type=opencl_version_string,
        default=default_opencl_version,
        metavar='VER',
        help='version of OpenCL headers/loader to be downloaded'
        )
parser.add_argument(
        '--opencl-hdr-ver',
        type=opencl_version_string,
        default=None,
        metavar='VER',
        help='version of OpenCL headers to be downloaded'
        )
parser.add_argument(
        '--opencl-ldr-ver',
        type=opencl_version_string,
        default=None,
        metavar='VER',
        help='version of OpenCL ICD loader to be downloaded'
        )
parser.add_argument(
        'packages',
        metavar='PKG',
        type=str,
        nargs='*', 
        default = all_packages,
        help='package to download (cxxtest, opencl-lib, opencl-hdr)'
        )

args = parser.parse_args()

def info(msg):
    if not args.quiet:
        sys.stdout.write("info: %s\n" % msg)

def warn(msg):
    if not args.quiet:
        sys.stderr.write("warning: %s\n" % msg)


def dload_patch(**kw):
    """Download python-patch by Anatoly Techtonik"""
    try: destdir = kw['destdir']
    except KeyError: destdir = os.path.join(scriptdir,'hoarder')
    dest = os.path.join(destdir, 'patch.py')
    url = "https://raw.githubusercontent.com/techtonik/python-patch/master/patch.py"
    info("downloading %r -> %r" % (url, dest))
    hoarder.urlretrieve(url, dest)
    return 0

try: import hoarder.patch
except ImportError:
    dload_patch()
    import hoarder.patch

def dload_cxxtest(**kw):
    """Download cxxtest framework"""

    try: clean = kw['clean']
    except KeyError: clean = False
    try: destdir = kw['destdir']
    except KeyError: destdir = os.path.join(topsrcdir, 'cxxtest')

    if clean:
        if os.path.exists(destdir):
            info('removing %r' % destdir)
            shutil.rmtree(destdir)
        return 0

    try: destdir_mode = kw['destdir_mode']
    except KeyError: destdir_mode = 0755

    if os.path.exists(destdir):
        warn("%r already exists, skipping cxxtest download!" % destdir)
        return 2

    info("creating %r" % destdir)
    os.makedirs(destdir, mode=destdir_mode)

    url = "https://github.com/CxxTest/cxxtest/archive/master.tar.gz"
    info("downloading cxxtest to %r" % destdir)
    hoarder.urluntar(url, path = destdir, strip_components = 1)
    return 0


def dload_opencl_hdr(**kw):
    """Download OpenCL header files"""
    try: clean = kw['clean']
    except KeyError: clean = False
    try: destdir = kw['destdir']
    except KeyError: destdir = os.path.join(topsrcdir, 'lib','OpenCL','include','CL')

    if clean:
        if os.path.exists(destdir):
            info('removing %r' % destdir)
            shutil.rmtree(destdir)
        return 0

    ver = None
    for k in ('opencl_hdr_ver', 'opencl_ver'):
        if ver is None:
            try: ver = kw[k]
            except KeyError: ver = None

    try: destdir_mode = kw['destdir_mode']
    except KeyError: destdir_mode = 0755

    if os.path.exists(destdir):
        warn("%r already exists, skipping opencl-hdr download!" % destdir)
        return 2

    info("creating %r" % destdir)
    os.makedirs(destdir, mode=destdir_mode)

    url_base = "https://www.khronos.org/registry/cl/api/%s" % ver
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
        files = [   'cl.hpp',
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
        files = [   'opencl.h',
                    'cl_platform.h',
                    'cl.h',
                    'cl_ext.h',
                    'cl_egl.h',
                    'cl_dx9_media_sharing.h',
                    'cl_d3d10.h',
                    'cl_d3d11.h',
                    'cl_gl.h',
                    'cl_gl_ext.h',
                    'cl2.hpp'   ]
    else:
        warn('unsupported OpenCL version %r' % ver)
        return 2

    info("starting downloads from %r" % url_base)
    for f in files:
        url = url_base + f
        info('downloading %r -> %r' % (f, os.path.join(destdir,f)))

    return 0

def dload_opencl_ldr(**kw):
    """Download and build OpenCL ICD loader (libOpenCL.so)

    This requires 'cmake' and 'make' to be installed"""

    try: clean = kw['clean']
    except KeyError: clean = False
    try: destdir = kw['destdir']
    except KeyError: destdir = os.path.join(topsrcdir, 'lib','OpenCL','lib')

    if clean:
        if os.path.exists(destdir):
            info('removing %r' % destdir)
            shutil.rmtree(destdir)
        return 0


    ver = None
    for k in ('opencl_ldr_ver', 'opencl_ver'):
        if ver is None:
            try: ver = kw[k]
            except KeyError: ver = None

    try: destdir_mode = kw['destdir_mode']
    except KeyError: destdir_mode = 0755

    if os.path.exists(destdir):
        warn("%r already exists, skipping opencl-ldr download!" % destdir)
        return 2

    patchfile = None
    if ver == '1.0' or ver == '1.1':
        warn("ICD loader for OpenCL %s can't be downloaded, sorry" % ver)
        return 2
    elif ver == '1.2':
        url = "https://www.khronos.org/registry/cl/specs/opencl-icd-1.2.11.0.tgz"
        patchfile = 'opencl-icd-loader-1.2.11.0.patch'
    elif ver == '2.0':
        url = "http://www.khronos.org/registry/cl/icd/2.0/opengl-icd-2.0.5.0.tgz"
        patchfile = 'opencl-icd-loader-2.0.5.0.patch'
    else:
        warn("unsupported OpenCL version %r, skipping opencl-ldr download" % ver)
        return 2

    tmpdir = tempfile.mkdtemp()
    info("created %r" % tmpdir)

    info("downloading %r to %r" % (url,tmpdir))
    hoarder.urluntar(url, path=tmpdir, strip_components=1)
    dload_opencl_hdr(opencl_hdr_ver=ver, destdir=os.path.join(tmpdir,'CL'))

    if patchfile:
        patchfile = os.path.join(patchdir, patchfile)
        info('reading patch file %r' % patchfile)
        patch = hoarder.patch.fromfile(patchfile)
        info('applying patch %r' % patchfile)
        patch.apply(strip=1, root=tmpdir)

    env = os.environ.copy()
    sysname = platform.system()
    if sysname == 'Linux':
        build_cmd = ['make']
        env['CFLAGS'] = '-Wno-deprecated-declarations -Wno-implicit-function-declaration'
        files = ['bin/libOpenCL.so*']
##    elif sysname == 'Windows':
##        pass
    elif sysname.startswith('CYGWIN'):
        build_cmd = ['make']
        env['CMAKE_LEGACY_CYGWIN_WIN32'] = '1'
        env['CFLAGS'] = '-mwin32 -Wno-deprecated-declarations -Wno-implicit-function-declaration'
        files = [ 'bin/cygOpenCL-?.dll', 'libOpenCL.dll.a' ]
    else:
        warn('unsupported operating sysname %r, aborting opencl-ldr build' % sysname)
        info("removing %r" % tmpdir)
        shutil.rmtree(tmpdir)
        return 2

    p = subprocess.Popen(build_cmd, env = env, cwd = tmpdir)
    err = p.wait()
    if err != 0:
        cmdline = subprocess.list2cmdline(build_cmd)
        warn('%r returned error code %r, aborting opencl-ldr build' % (cmdline, err))
        info("removing %r" % tmpdir)
        shutil.rmtree(tmpdir)
        return err
        
    info("creating %r" % destdir)
    os.makedirs(destdir, mode=0755)

    for fglob in files:
        for src in glob.glob(os.path.join(tmpdir, fglob)):
            fname = os.path.basename(src)
            dst = os.path.join(destdir, fname)
            info('copy %r %r' %(src, dst))
            if os.path.islink(src):
                linkto = os.readlink(src)
                os.symlink(linkto, dst)
            else:
                shutil.copy(src, dst)

    info("removing %r" % tmpdir)
    shutil.rmtree(tmpdir)
    return 0


for pkg in args.packages:
    if pkg.lower() == 'cxxtest':
        dload_cxxtest(**vars(args))
    elif pkg.lower() == 'opencl-hdr':
        dload_opencl_hdr(**vars(args))
    elif pkg.lower() == 'opencl-ldr':
        dload_opencl_ldr(**vars(args))
    else:
        warn("unsupported package name: %r, skipping!" % pkg)

# Local Variables:
# # tab-width:4
# # indent-tabs-mode:nil
# # End:
# vim: set syntax=python expandtab tabstop=4 shiftwidth=4:
