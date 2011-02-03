DESCRIPTION = "The Mercurial distributed SCM"
HOMEPAGE = "http://mercurial.selenic.com/"
SECTION = "console/utils"
LICENSE = "GPLv2"
DEPENDS = "python-native"
PR = "r0"

SRC_URI = "http://mercurial.selenic.com/release/mercurial-${PV}.tar.gz;name=src"

S = "${WORKDIR}/mercurial-${PV}"

inherit native

EXTRA_OEMAKE = "STAGING_LIBDIR=${STAGING_LIBDIR} STAGING_INCDIR=${STAGING_INCDIR} \
        BUILD_SYS=${BUILD_SYS} HOST_SYS=${HOST_SYS} PREFIX=${prefix}"

do_install () {
        oe_runmake -e install DESTDIR=${D} PREFIX=${prefix}
}
