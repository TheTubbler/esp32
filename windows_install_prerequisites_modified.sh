#!/bin/bash
#
# Setup script to configure an MSYS2 environment for Espressif IoT Development Framework (ESP-IDF).
# See docs/windows-setup.rst for details.
#
# Modifications:
#
# • Removed all instances of --noconfirm in pacman, so that the  user get some control
# • Changed TOOLCHIAN_ZIP to https://dl.espressif.com/dl/xtensa-esp32-elf-win32-1.22.0-61-gab8375a-5.2.0.zip
#   for the new toolchain. This is expected to become updated in the official scipt file also shortly.
# • Added check for toolchain version, which also lets the user select whether to reinstall or upgrade it,
#   optionally.
# • Changed to python2 and pip2
#

if [ "$OSTYPE" != "msys" ]; then
  echo "This setup script expects to be run from an MSYS2 environment on Windows."
  exit 1
fi
if ! [ -x /bin/pacman ]; then
  echo "This setup script expects to use the pacman package manager from MSYS2."
  exit 1
fi

# if update-core still exists, run it to get the latest core MSYS2 system
# (which no longer needs or includes update-core!)
#
# If this step runs, it will require a full restart of MSYS2 before it
# can continue.
[ -x /usr/bin/update-core ] && /usr/bin/update-core

# set -e

pacman -Syu
pacman -S gettext-devel gcc git make ncurses-devel flex bison gperf vim mingw-w64-i686-python2-pip unzip

# python2 -m pip install --upgrade pip
python2 -m ensurepip
pip2 install --upgrade setuptools --upgrade pip
pip2 install pyserial

# Select to install toolchain
TOOLCHAIN_DIR="/opt/xtensa-esp32-elf"
TOOLCHAIN_GCC="${TOOLCHAIN_DIR}/bin/xtensa-esp32-elf-gcc"
LATEST_TOOLCHAIN_VERSION="5.2.0"
CURRENT_TOOLCHAIN_VERSION="0"
DO_INSTALL_TOOLCHAIN="false"

if [[ -x /opt/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc ]] ; then
    CURRENT_TOOLCHAIN_VERSION=$(${TOOLCHAIN_GCC} --version | head -n 1 | awk 'NF>1{print $NF}')
    if [[ "${LATEST_TOOLCHAIN_VERSION}" = "${CURRENT_TOOLCHAIN_VERSION}" ]] ; then
        read -p "Toolchain is latest version (${LATEST_TOOLCHAIN_VERSION}). Reinstall? [y/N] " YN
        case $YN in
            [Yy]* ) DO_INSTALL_TOOLCHAIN="true" ;;
            * )     DO_INSTALL_TOOLCHAIN="false" ;;
        esac
    else
        read -p "Toolchain is not newest version (${CURRENT_TOOLCHAIN_VERSION}). Upgrade to ${LATEST_TOOLCHAIN_VERSION}? [Y/n] " YN
        case $YN in
            [Nn]* ) DO_INSTALL_TOOLCHAIN="false" ;;
            * )     DO_INSTALL_TOOLCHAIN="true" ;;
        esac
    fi
else
    read -p "Toolchain is not installed. Install? [Y/n] " YN
    case $YN in
        [Nn]* ) DO_INSTALL_TOOLCHAIN="false" ;;
        * )     DO_INSTALL_TOOLCHAIN="true" ;;
    esac
fi

# TODO: automatically download precompiled toolchain, unpack at /opt/xtensa-esp32-elf/
TOOLCHAIN_ZIP=https://dl.espressif.com/dl/xtensa-esp32-elf-win32-1.22.0-61-gab8375a-5.2.0.zip
if [[ "${DO_INSTALL_TOOLCHAIN}" = "true" ]] ; then
    if [[ "${CURRENT_TOOLCHAIN_VERSION}" != "0" ]] ; then
        mv "${TOOLCHAIN_DIR}" "${TOOLCHAIN_DIR}_${CURRENT_TOOLCHAIN_VERSION}"
    fi
    echo "Downloading precompiled toolchain ${TOOLCHAIN_ZIP}..."
    cd ~
    curl -LO --retry 10 http://dl.espressif.com/dl/${TOOLCHAIN_ZIP}
    cd /opt
    unzip ~/${TOOLCHAIN_ZIP}
    rm ~/${TOOLCHAIN_ZIP}

    cat > /etc/profile.d/esp32_toolchain.sh << EOF
    export PATH="$PATH:/opt/xtensa-esp32-elf/bin"
EOF
fi

# clean up pacman packages to save some disk space
pacman -R unzip
pacman -Scc

echo "************************************************"
echo "MSYS2 environment is now ready to use ESP-IDF."
echo "Run 'source /etc/profile' to add the toolchain to"
echo "your path. Execute 'msys_shell.cmd' to launch an"
echo "MSYS terminal."
echo
echo "Once ESP-IDF is downloaded/checked out, set the"
echo "environment variable IDF_PATH in /etc/profile to"
echo "point to the directory."
echo "************************************************"
echo
