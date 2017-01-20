#!/bin/bash

SCRIPTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
TPLDIR="${SCRIPTDIR}/TEMPLATE"
TARGETDIR="${SCRIPTDIR}/$1"

if [[ -z "$1" ]] ; then
    echo -e "Project name required as input parameter. Exiting."
    exit 1
fi

if [[ ! -d "${TPLDIR}" ]] ; then
    echo -e "Template folder not existing. Exiting."
    exit 2
fi

if [[ -d "${TARGETDIR}" ]] ; then
    echo -e "Target directory already existing. Exiting."
    exit 3
fi

# Copy the template project into a new directory
cp -r "${TPLDIR}" "${TARGETDIR}"

# Update the project information
sed -i -- 's/app-template/'"$1"'/' "${TARGETDIR}/Makefile"

exit 0
