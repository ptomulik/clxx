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
TMPDIR=`mktemp -d`

TGT="${TOPSRCDIR}/lib/OpenCL/lib"

case $VER in
  1\.0) (echo "ICD for OpenCL 1.0 can't be downloaded, sorry" >&2; rm -rf "${TMPDIR}"; exit 1)
    ;;
  1\.1) (echo "ICD for OpenCL 1.1 can't be downloaded, sorry" >&2; rm -rf "${TMPDIR}"; exit 1)
    ;;
  1\.2) (cd "${TMPDIR}" && \
    echo "Downloading files to \"${TMPDIR}\"... "
    wget -nv https://www.khronos.org/registry/cl/specs/opencl-icd-1.2.11.0.tgz && \
    tar -zxf opencl-icd-1.2.11.0.tgz && \
    cd icd && patch -p1 < "${SCRIPTDIR}/opencl-icd-loader-1.2.11.0.patch" && \
    cd inc && mkdir CL && cd CL && \
    wget -nv https://www.khronos.org/registry/cl/api/1.2/cl.h && \
    wget -nv https://www.khronos.org/registry/cl/api/1.2/cl.hpp && \
    wget -nv https://www.khronos.org/registry/cl/api/1.2/cl_d3d10.h && \
    wget -nv https://www.khronos.org/registry/cl/api/1.2/cl_d3d11.h && \
    wget -nv https://www.khronos.org/registry/cl/api/1.2/cl_dx9_media_sharing.h && \
    wget -nv https://www.khronos.org/registry/cl/api/1.2/cl_egl.h && \
    wget -nv https://www.khronos.org/registry/cl/api/1.2/cl_ext.h && \
    wget -nv https://www.khronos.org/registry/cl/api/1.2/cl_gl.h && \
    wget -nv https://www.khronos.org/registry/cl/api/1.2/cl_gl_ext.h && \
    wget -nv https://www.khronos.org/registry/cl/api/1.2/cl_platform.h && \
    wget -nv https://www.khronos.org/registry/cl/api/1.2/opencl.h)
    ;;
  2\.0) (cd "${TMPDIR}" && \
    echo "Downloading files to \"${TMPDIR}\"... "
    wget -nv http://www.khronos.org/registry/cl/icd/2.0/opengl-icd-2.0.5.0.tgz && \
    tar -zxf opengl-icd-2.0.5.0.tgz && \
    cd icd && patch -p1 < "${SCRIPTDIR}/opencl-icd-loader-2.0.5.0.patch" && \
    cd inc && mkdir CL && cd CL && \
    wget -nv https://www.khronos.org/registry/cl/api/2.0/opencl.h && \
    wget -nv https://www.khronos.org/registry/cl/api/2.0/cl_platform.h && \
    wget -nv https://www.khronos.org/registry/cl/api/2.0/cl.h && \
    wget -nv https://www.khronos.org/registry/cl/api/2.0/cl_ext.h && \
    wget -nv https://www.khronos.org/registry/cl/api/2.0/cl_egl.h && \
    wget -nv https://www.khronos.org/registry/cl/api/2.0/cl_dx9_media_sharing.h && \
    wget -nv https://www.khronos.org/registry/cl/api/2.0/cl_d3d10.h && \
    wget -nv https://www.khronos.org/registry/cl/api/2.0/cl_d3d11.h && \
    wget -nv https://www.khronos.org/registry/cl/api/2.0/cl_gl.h && \
    wget -nv https://www.khronos.org/registry/cl/api/2.0/cl_gl_ext.h && \
    wget -nv https://www.khronos.org/registry/cl/api/2.0/cl2.hpp)
    ;;
esac

PLATFORM=`uname -s`
#  Build in temporary directory
case "$PLATFORM" in
  CYGWIN*)
    echo "Building in \"${TMPDIR}\""
    (cd "${TMPDIR}/icd" && CMAKE_LEGACY_CYGWIN_WIN32=1 CFLAGS="-mwin32 -Wno-deprecated-declarations" cmake . && make)
    ;;
  Linux)
    echo "Building in \"${TMPDIR}\""
    (cd "${TMPDIR}/icd" && CFLAGS="-Wno-deprecated-declarations" cmake . && make)
    ;;
  *)
    echo "error: unsupported platform: `uname -s`" >&2;
    exit 1;
    ;;
esac

if [ -e "${TGT}" ]; then
  echo "${TGT} already exists, skipping!" >&2;
  exit 0;
fi
mkdir -p "${TGT}";

#  Copy to TGT
case "${PLATFORM}" in
  CYGWIN*)
    cp "${TMPDIR}"/icd/bin/cygOpenCL-?.dll "${TGT}/";
    cp "${TMPDIR}"/icd/libOpenCL.dll.a "${TGT}/";
    ;;
  Linux)
    cp "${TMPDIR}"/icd/bin/libOpenCL.so* "${TGT}/";
    ;;
  *)
    echo "error: unsupported platform: `uname -s`" >&2;
    exit 1;
    ;;
esac
rm -rf "${TMPDIR}";
