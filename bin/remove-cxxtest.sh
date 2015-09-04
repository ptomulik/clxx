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

TGT="${TOPSRCDIR}/cxxtest"

if [ -e "${TGT}" ]; then
  echo "rm -r "${TGT}""
        rm -r "${TGT}"
fi
