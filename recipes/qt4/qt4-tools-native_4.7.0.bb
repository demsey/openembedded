DEFAULT_PREFERENCE = "-1"
DEFAULT_PREFERENCE_opendreambox = "1"

require qt4-tools-native.inc
LICENSE = "LGPLv2.1 GPLv3"

DEPENDS += "libxau-native libxdmcp-native"

PR = "${INC_PR}.0"

SRC_URI = "ftp://ftp.trolltech.com/qt/source/qt-everywhere-opensource-src-${PV}.tar.gz \
           file://configure-lflags.patch;patch=1 \
           file://fix.xlib-test.libs.patch;patch=1 \
           file://qt-config.patch;patch=1 \
           file://g++.conf \
           file://linux.conf"
S = "${WORKDIR}/qt-everywhere-opensource-src-${PV}"

EXTRA_OECONF += " -no-fast -silent -no-rpath"

TOBUILD := "src/tools/bootstrap ${TOBUILD}"
