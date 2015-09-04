#! /bin/sh

set -e

SCRIPT=`readlink -f $0`;
SCRIPTDIR=`dirname ${SCRIPT}`;
TOPSRCDIR=`readlink -f "${SCRIPTDIR}/.."`

if [ $# -ge 1 ]; then
  if [ -f "${1}/include/CL/cl.h" ]; then
    CL_PATH="${1}/include/CL";
  elif [ -f "${1}/CL/cl.h" ]; then
    CL_PATH="${1}/CL";
  elif [ -f "${1}/cl.h" ]; then
    CL_PATH="${1}";
  fi
fi

if [ -z "${CL_PATH}" ] && [ ! -z "${CUDA_PATH}" ]; then
  CL_PATH="${CUDA_PATH}/include/CL";
fi

INCDIR="${TOPSRCDIR}/lib/OpenCL/include"

test -e "${INCDIR}/CL" && (echo "error: ${INCDIR}/CL already exists, aborting!" >&2; exit 1)
test -e "${INCDIR}" || mkdir -p "${INCDIR}"

echo "(cd "${INCDIR}" && ln -s "${CL_PATH}")"
      (cd "${INCDIR}" && ln -s "${CL_PATH}")
