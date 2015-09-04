#! /bin/sh

set -e

SCRIPT=`readlink -f $0`;
SCRIPTDIR=`dirname ${SCRIPT}`;
TOPSRCDIR=`readlink -f "${SCRIPTDIR}/.."`

if [ $# -ge 1 ]; then
  if [ -f "${1}" ]; then
    OPENCLDLL="$1";
  else
    OPENCLDLL=`which "$1"`;
  fi
fi

if [ -z "${OPENCLDLL}" ]; then
  OPENCLDLL=`which OpenCL.dll`;
fi


LIBDIR="${TOPSRCDIR}/lib/OpenCL/lib"

test -e "${LIBDIR}/OpenCL.dll" && (echo "error: ${LIBDIR}/OpenCL.dll already exists, aborting!" >&2; exit 1)
test -e "${LIBDIR}" || mkdir -p "${LIBDIR}"

echo "(cd "${LIBDIR}" && ln -s "${OPENCLDLL}" OpenCL.dll)"
      (cd "${LIBDIR}" && ln -s "${OPENCLDLL}" OpenCL.dll)
