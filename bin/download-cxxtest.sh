#! /bin/sh

# This script downloads the most recent commit of cxxtest from
# github.com. All the files land to cxxtest/ directory in the
# top source dir. This is a special location, where the scons
# cxxtest tool will look for the cxxtest installation. 
#
# The script does not download anything if the cxxtest file or
# directory already exists. To refresh the installation, remove
# cxxtest directory.

set -e

SCRIPT=`readlink -f $0`;
SCRIPTDIR=`dirname ${SCRIPT}`;
TOPSRCDIR=`readlink -f "${SCRIPTDIR}/.."`

URL="https://github.com/CxxTest/cxxtest/archive/master.tar.gz"
TGT="${TOPSRCDIR}/cxxtest"

if [ -w "${TGT}" ]; then
  echo "${TGT} already exists, skipping!" >&2;
  exit 0;
fi
mkdir "${TGT}"
echo "(cd "${TGT}" && wget --quiet "${URL}" -O - | tar -zxf - --strip-components=1)"
      (cd "${TGT}" && wget --quiet "${URL}" -O - | tar -zxf - --strip-components=1)
