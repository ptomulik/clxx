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

test -e "${INCDIR}/CL" || mkdir -p "${INCDIR}/CL"

for F in "${CL_PATH}"/*.h; do
  H=`basename "${F}"`;
  if [ -e "${INCDIR}/CL/${H}" ]; then
    echo "${INCDIR}/CL/${H} already exists, skipping.";
  else
    echo "(cd "${INCDIR}/CL/" && ln -s "${CL_PATH}/${H}")"
          (cd "${INCDIR}/CL/" && ln -s "${CL_PATH}/${H}")
  fi
done
