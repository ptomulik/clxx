#! /bin/sh

set -e

if [ $# -ge 1 ]; then
  case $1 in
    1\.[0-2]|2\.0)
        VER=$1
        ;;
    *)
        echo "error: invalid OpenCL version: '$1'" >&2;
        exit 1;
        ;;
  esac
else
  VER="2.0"
fi

SCRIPT=`readlink -f $0`;
SCRIPTDIR=`dirname ${SCRIPT}`;
TOPSRCDIR=`readlink -f "${SCRIPTDIR}/.."`

URL="https://github.com/CxxTest/cxxtest/archive/master.tar.gz"
TGT="${TOPSRCDIR}/lib/OpenCL/include/CL"

if [ -e "${TGT}" ]; then
  echo "warning: ${TGT} already exists" >&2;
  echo "warning: skipping the cxxtest download" >&2;
  exit 2;
fi

mkdir -p "${TGT}";
case $VER in
  1\.0) (cd "${TGT}" && \
    wget https://www.khronos.org/registry/cl/api/1.0/cl.h && \
    wget https://www.khronos.org/registry/cl/api/1.1/cl.hpp && \
    wget https://www.khronos.org/registry/cl/api/1.0/cl_d3d10.h && \
    wget https://www.khronos.org/registry/cl/api/1.0/cl_ext.h && \
    wget https://www.khronos.org/registry/cl/api/1.0/cl_gl.h && \
    wget https://www.khronos.org/registry/cl/api/1.0/cl_gl_ext.h && \
    wget https://www.khronos.org/registry/cl/api/1.0/cl_platform.h && \
    wget https://www.khronos.org/registry/cl/api/1.0/opencl.h)
        ;;
  1\.1) (cd "${TGT}" && \
    wget https://www.khronos.org/registry/cl/api/1.1/cl.h && \
    wget https://www.khronos.org/registry/cl/api/1.1/cl.hpp && \
    wget https://www.khronos.org/registry/cl/api/1.1/cl_d3d10.h && \
    wget https://www.khronos.org/registry/cl/api/1.1/cl_ext.h && \
    wget https://www.khronos.org/registry/cl/api/1.1/cl_gl.h && \
    wget https://www.khronos.org/registry/cl/api/1.1/cl_gl_ext.h && \
    wget https://www.khronos.org/registry/cl/api/1.1/cl_platform.h && \
    wget https://www.khronos.org/registry/cl/api/1.1/opencl.h)
        ;;
  1\.2) (cd "${TGT}" && \
    wget https://www.khronos.org/registry/cl/api/1.2/cl.h && \
    wget https://www.khronos.org/registry/cl/api/1.2/cl.hpp && \
    wget https://www.khronos.org/registry/cl/api/1.2/cl_d3d10.h && \
    wget https://www.khronos.org/registry/cl/api/1.2/cl_d3d11.h && \
    wget https://www.khronos.org/registry/cl/api/1.2/cl_dx9_media_sharing.h && \
    wget https://www.khronos.org/registry/cl/api/1.2/cl_egl.h && \
    wget https://www.khronos.org/registry/cl/api/1.2/cl_ext.h && \
    wget https://www.khronos.org/registry/cl/api/1.2/cl_gl.h && \
    wget https://www.khronos.org/registry/cl/api/1.2/cl_gl_ext.h && \
    wget https://www.khronos.org/registry/cl/api/1.2/cl_platform.h && \
    wget https://www.khronos.org/registry/cl/api/1.2/opencl.h)
        ;;
  2\.0) (cd "${TGT}" && \
    wget https://www.khronos.org/registry/cl/api/2.0/opencl.h && \
    wget https://www.khronos.org/registry/cl/api/2.0/cl_platform.h && \
    wget https://www.khronos.org/registry/cl/api/2.0/cl.h && \
    wget https://www.khronos.org/registry/cl/api/2.0/cl_ext.h && \
    wget https://www.khronos.org/registry/cl/api/2.0/cl_egl.h && \
    wget https://www.khronos.org/registry/cl/api/2.0/cl_dx9_media_sharing.h && \
    wget https://www.khronos.org/registry/cl/api/2.0/cl_d3d10.h && \
    wget https://www.khronos.org/registry/cl/api/2.0/cl_d3d11.h && \
    wget https://www.khronos.org/registry/cl/api/2.0/cl_gl.h && \
    wget https://www.khronos.org/registry/cl/api/2.0/cl_gl_ext.h && \
    wget https://www.khronos.org/registry/cl/api/2.0/cl2.hpp)
    ;;
esac