#! /bin/sh

set -e

SCRIPT=`readlink -f $0`;
SCRIPTDIR=`dirname ${SCRIPT}`;

"${SCRIPTDIR}/download-cxxtest.sh"
"${SCRIPTDIR}/symlink-opencl-headers.sh"
"${SCRIPTDIR}/symlink-opencl-dll.sh"
