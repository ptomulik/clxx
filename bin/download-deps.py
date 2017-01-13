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
default_egl_version = '1.5'
all_packages = ['cxxtest', 'opencl-hdr', 'opencl-icd-ldr', 'swig', 'scons']
scons_versions = [ 'tip',
                   '2.4.0',
                   '2.3.6',
                   '2.3.5',
                   '2.3.4',
                   '2.3.3',
                   '2.3.2',
                   '2.3.1',
                   '2.3.0',
                   '2.2.0',
                   '2.1.0.final.0',
                   'tip' ]
default_scons_version = scons_versions[0]

# Validate and return OpenCL version
def opencl_version_string(v):
    if not re.match(r'^1\.[0-2]|2\.[0-2]$', v):
        raise argparse.ArgumentTypeError("ill-formed or unsupported OpenCL version %r" % v)
    return v

# Validate and return EGL version
def egl_version_string(v):
    if not re.match(r'^1\.[0-5]$', v):
        raise argparse.ArgumentTypeError("ill-formed or unsupported EGL version %r" % v)
    return v

# Validate and return SCons version
def scons_version_string(v):
    if v not in scons_versions:
        raise argparse.ArgumentTypeError("ill-formed or unsupported EGL version %r" % v)
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
        '--opencl-icd-ldr-ver',
        type=opencl_version_string,
        default=None,
        metavar='VER',
        help='version of OpenCL ICD loader to be downloaded'
        )

parser.add_argument(
        '--egl-ver',
        type=egl_version_string,
        default=default_egl_version,
        metavar='VER',
        help='version of OpenCL headers/loader to be downloaded'
        )
parser.add_argument(
        '--egl-hdr-ver',
        type=egl_version_string,
        default=None,
        metavar='VER',
        help='version of OpenCL headers to be downloaded'
        )

parser.add_argument(
        '--scons-ver',
        type=scons_version_string,
        default=default_scons_version,
        metavar='VER',
        help='version of scons to be downloaded'
        )

parser.add_argument(
        '--scons-from-bitbucket', action='store_true',
        help='download scons from bitbucket.org instead of from sourceforge'
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

def dload_cxxtest(**kw):
    """Download cxxtest framework"""

    try: clean = kw['clean']
    except KeyError: clean = False
    try: destdir = kw['destdir']
    except KeyError: destdir = os.path.join(topsrcdir, 'ext', 'cxxtest')

    if clean:
        if os.path.exists(destdir):
            info("removing '%s'" % destdir, **kw)
            shutil.rmtree(destdir)
        return 0

    try: destdir_mode = kw['destdir_mode']
    except KeyError: destdir_mode = 0755

    if os.path.exists(destdir):
        warn("'%s' already exists, skipping cxxtest download!" % destdir, **kw)
        return 2

    info("creating '%s'" % destdir, **kw)
    os.makedirs(destdir, mode=destdir_mode)

    url = "https://github.com/CxxTest/cxxtest/archive/master.tar.gz"
    info("downloading cxxtest to '%s'" % destdir, **kw)
    hoarder.urluntar(url, path = destdir, strip_components = 1)
    return 0

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
        ver = default_opencl_version

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
        patchfile = 'opencl-hdr-2.0.patch'
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

def dload_opencl_icd_ldr(**kw):
    """Download and build OpenCL ICD loader (libOpenCL.so)

    This requires 'cmake' and 'make' to be installed"""

    try: clean = kw['clean']
    except KeyError: clean = False
    try: destdir = kw['destdir']
    except KeyError: destdir = os.path.join(topsrcdir, 'ext','OpenCL','lib')

    if clean:
        if os.path.exists(destdir):
            info("removing '%s'" % destdir, **kw)
            shutil.rmtree(destdir)
        return 0


    ver = None
    for k in ('opencl_icd_ldr_ver', 'opencl_ver'):
        if ver is None:
            try: ver = kw[k]
            except KeyError: ver = None
    if ver is None:
        ver = default_opencl_version

    try: destdir_mode = kw['destdir_mode']
    except KeyError: destdir_mode = 0755

    if os.path.exists(destdir):
        warn("'%s' already exists, skipping opencl-icd-ldr download!" % destdir, **kw)
        return 2

    patchfile = None
##    if ver == '1.0' or ver == '1.1':
##        warn("ICD loader for OpenCL %s can't be downloaded, sorry" % ver, **kw)
##        return 2
##    elif ver == '1.2':
##        url = "https://www.khronos.org/registry/cl/specs/opencl-icd-1.2.11.0.tgz"
##        patchfile = 'opencl-icd-loader-1.2.11.0.patch'
##    elif ver == '2.0':
##        url = "http://www.khronos.org/registry/cl/icd/2.0/opengl-icd-2.0.5.0.tgz"
##        patchfile = 'opencl-icd-loader-2.0.5.0.patch'
##    else:
##        warn("unsupported OpenCL version '%s', skipping opencl-icd-ldr download" % ver, **kw)
##        return 2
    url = 'https://github.com/KhronosGroup/OpenCL-ICD-Loader/archive/master.tar.gz'

    tmpdir = tempfile.mkdtemp()
    info("created '%s'" % tmpdir, **kw)

    info("downloading '%s' to '%s'" % (url,tmpdir), **kw)
    hoarder.urluntar(url, path=tmpdir, strip_components=1)
    # OpenCL headers must be downloaded separately, they're not included in ICD loader's tarball
    dload_opencl_hdr(opencl_hdr_ver=ver, destdir=os.path.join(tmpdir,'inc','CL'))
    # EGL headers are required to build OpenCL ICD loader (at least on Windows)
    dload_egl_hdr(egl_hdr_ver=default_egl_version, destdir=os.path.join(tmpdir, 'inc', 'EGL'))

    if patchfile:
        patchfile = os.path.join(patchdir, patchfile)
        info("reading patch file '%s'" % patchfile, **kw)
        patch = hoarder.patch.fromfile(patchfile)
        info("applying patch '%s'" % patchfile, **kw)
        patch.apply(strip=1, root=tmpdir)

    env = os.environ.copy()
    sysname = platform.system()
    if sysname == 'Linux':
        build_cmd = ['make']
        env['CFLAGS'] = '-Wno-deprecated-declarations -Wno-implicit-function-declaration'
        files = ['bin/libOpenCL.so*']
    elif sysname == 'Windows':
        vsnumbers = ['100', '110', '120', '130', '140']
        build_cmd = [os.path.join(tmpdir, 'build_using_cmake.bat')]
        files = ['bin/OpenCL.dll']
        # %VS90COMNTOOLS% is used by the build_using_cmake.bat, but these days
        # it's rather %VS140COMNTOOLS% (VS 14.0) or such
        try: env['VS90COMNTOOLS']
        except KeyError:
            for vsnum in reversed(vsnumbers):
                try: vspath = env['VS%sCOMNTOOLS' % vsnum]
                except KeyError: pass
                else:
                    if os.path.exists(os.path.join(vspath,'vsvars32.bat')):
                        env['VS90COMNTOOLS'] = vspath
                        break
    elif sysname.startswith('CYGWIN'):
        build_cmd = ['make']
        env['CMAKE_LEGACY_CYGWIN_WIN32'] = '1'
        env['CFLAGS'] = '-mwin32 -Wno-deprecated-declarations -Wno-implicit-function-declaration'
        files = [ 'bin/cygOpenCL-?.dll', 'libOpenCL.dll.a' ]
    else:
        warn('unsupported operating system "%s", aborting opencl-icd-ldr build' % sysname, **kw)
        info("removing '%s'" % tmpdir, **kw)
        shutil.rmtree(tmpdir)
        return 2

    info("building OpenCL ICD loader", **kw)
    p = subprocess.Popen(build_cmd, env = env, cwd = tmpdir)
    err = p.wait()
    if err != 0:
        cmdline = subprocess.list2cmdline(build_cmd)
        warn('%s returned error code %d, aborting opencl-icd-ldr build' % (cmdline, err), **kw)
        info("removing '%s'" % tmpdir, **kw)
        shutil.rmtree(tmpdir)
        return err

    info("creating '%s'" % destdir, **kw)
    os.makedirs(destdir, mode=destdir_mode)

    for fglob in files:
        for src in glob.glob(os.path.join(tmpdir, fglob)):
            fname = os.path.basename(src)
            dst = os.path.join(destdir, fname)
            info("copy '%s' '%s'" %(src, dst), **kw)
            if os.path.islink(src):
                linkto = os.readlink(src)
                os.symlink(linkto, dst)
            else:
                shutil.copy(src, dst)

    info("removing '%s'" % tmpdir, **kw)
    shutil.rmtree(tmpdir)
    return 0

def dload_swig(**kw):
    try: clean = kw['clean']
    except KeyError: clean = False
    try: destdir = kw['destdir']
    except KeyError: destdir = os.path.join(topsrcdir, 'ext', 'swig')

    if clean:
        if os.path.exists(destdir):
            info("removing '%s'" % destdir, **kw)
            shutil.rmtree(destdir)
        return 0

    try: destdir_mode = kw['destdir_mode']
    except KeyError: destdir_mode = 0755

    if os.path.exists(destdir):
        warn("'%s' already exists, skipping swig download!" % destdir, **kw)
        return 2

    tmpdir = tempfile.mkdtemp()
    info("created '%s'" % tmpdir, **kw)

    url = "https://github.com/ptomulik/swig/archive/ptomulik-latest.tar.gz"
    info("downloading '%s' to '%s'" % (url,tmpdir), **kw)
    hoarder.urluntar(url, path=tmpdir, strip_components=1)

    env = os.environ.copy()

    # FIXME: what about Windows? (PowerShell script?)
    # FIXME: what about required swig deps (yodl,...)
    info("building swig", **kw)
    commands = [
        ['./autogen.sh'],
        ['./configure', '--prefix=%s' % destdir ],
        ['make'],
        ['make', 'install']
    ]
    for build_cmd in commands:
        p = subprocess.Popen(build_cmd, env = env, cwd = tmpdir)
        err = p.wait()
        if err != 0:
            cmdline = subprocess.list2cmdline(build_cmd)
            warn('%s returned error code %d, aborting opencl-icd-ldr build' % (cmdline, err), **kw)
            info("removing '%s'" % tmpdir, **kw)
            shutil.rmtree(tmpdir)
            return err

    info("removing '%s'" % tmpdir, **kw)
    shutil.rmtree(tmpdir)
    return 0

def dload_scons(**kw):
    try: clean = kw['clean']
    except KeyError: clean = False
    try: destdir = kw['destdir']
    except KeyError: destdir = os.path.join(topsrcdir, 'ext', 'scons')

    if clean:
        if os.path.exists(destdir):
            info("removing '%s'" % destdir, **kw)
            shutil.rmtree(destdir)
        return 0

    ver = default_scons_version
    try: ver = kw['scons_ver']
    except KeyError: pass

    from_bitbucket = False
    try: from_bitbucket = kw['scons_from_bitbucket']
    except KeyError: pass

    if not from_bitbucket:
        from_bitbucket = (ver == 'tip')

    try: destdir_mode = kw['destdir_mode']
    except KeyError: destdir_mode = 0755

    if os.path.exists(destdir):
        warn("'%s' already exists, skipping scons download!" % destdir, **kw)
        return 2

    info("creating '%s'" % destdir, **kw)
    os.makedirs(destdir, mode=destdir_mode)

    if not from_bitbucket:
        url = "http://sourceforge.net/projects/scons/files/scons/%(ver)s/scons-%(ver)s.tar.gz/download" % locals()
        info("downloading '%s' to '%s'" % (url,destdir), **kw)
        hoarder.urluntar(url, path=destdir, strip_components=1)
    else:
        if ver is None: ver = 'tip'
        url = "https://bitbucket.org/scons/scons/get/%s.tar.gz" % ver

        tmpdir = tempfile.mkdtemp()
        info("created '%s'" % tmpdir, **kw)

        info("downloading '%s' to '%s'" % (url,tmpdir), **kw)
        hoarder.urluntar(url, path=tmpdir, strip_components=1)

        for f in ['script', 'engine']:
            src = os.path.join(tmpdir,'src', f)
            dst = os.path.join(destdir, f)
            info("copytree '%s' -> '%s'" % (src, dst), **kw)
            shutil.copytree(src, dst)

        info("removing '%s'" % tmpdir, **kw)
        shutil.rmtree(tmpdir)
    return 0

for pkg in args.packages:
    if pkg.lower() == 'cxxtest':
        dload_cxxtest(**vars(args))
    elif pkg.lower() == 'opencl-hdr':
        dload_opencl_hdr(**vars(args))
        dload_egl_hdr(**vars(args))
    elif pkg.lower() == 'opencl-icd-ldr':
        dload_opencl_icd_ldr(**vars(args))
    elif pkg.lower() == 'swig':
        dload_swig(**vars(args))
    elif pkg.lower() == 'scons':
        dload_scons(**vars(args))
    else:
        warn("unsupported package name: %r, skipping!" % pkg, **vars(args))

# Local Variables:
# # tab-width:4
# # indent-tabs-mode:nil
# # End:
# vim: set syntax=python expandtab tabstop=4 shiftwidth=4:
