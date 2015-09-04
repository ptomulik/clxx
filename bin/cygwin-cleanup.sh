#! /bin/sh

set -e

SCRIPT=`readlink -f $0`;
SCRIPTDIR=`dirname ${SCRIPT}`;

"${SCRIPTDIR}/remove-cxxtest.sh"
"${SCRIPTDIR}/remove-opencl-headers.sh"
"${SCRIPTDIR}/remove-opencl-dll.sh"
