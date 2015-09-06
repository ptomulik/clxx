#! /bin/sh

set -e

SCRIPT=`readlink -f $0`;
SCRIPTDIR=`dirname ${SCRIPT}`;

"${SCRIPTDIR}/download-cxxtest.sh"
"${SCRIPTDIR}/download-opencl-headers.sh" $@
"${SCRIPTDIR}/download-opencl-icd-loader.sh" $@
