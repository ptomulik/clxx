#! /bin/sh

set -e

SCRIPT=`readlink -f $0`;
SCRIPTDIR=`dirname ${SCRIPT}`;
TOPSRCDIR=`readlink -f "${SCRIPTDIR}/.."`

INCDIR="${TOPSRCDIR}/lib/OpenCL/include"

if [ -h "${INCDIR}/CL" ]; then
  echo "unlink "${INCDIR}/CL""
        unlink "${INCDIR}/CL"
elif [ -e "${INCDIR}/CL" ]; then
  echo "rm -rf "${INCDIR}/CL""
        rm -rf "${INCDIR}/CL"
fi
