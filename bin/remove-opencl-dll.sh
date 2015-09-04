#! /bin/sh

set -e

SCRIPT=`readlink -f $0`;
SCRIPTDIR=`dirname ${SCRIPT}`;
TOPSRCDIR=`readlink -f "${SCRIPTDIR}/.."`

LIBDIR="${TOPSRCDIR}/lib/OpenCL/lib"

if [ -h "${LIBDIR}/OpenCL.dll" ]; then
  echo "unlink "${LIBDIR}/OpenCL.dll""
        unlink "${LIBDIR}/OpenCL.dll"
elif [ -e "${LIBDIR}/OpenCL.dll" ]; then
  echo "rm -r "${LIBDIR}/OpenCL.dll""
        rm -r "${LIBDIR}/OpenCL.dll"
fi
