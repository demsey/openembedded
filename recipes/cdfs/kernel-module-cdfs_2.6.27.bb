DESCRIPTION = "CDfs filesystem"
HOMEPAGE = "http://users.elis.ugent.be/~mronsse/cdfs/"
SECTION = "kernel/modules"
LICENSE = "GPL"

inherit module

PACKAGES = "${PN}"
PR = "r0"
S="${WORKDIR}/cdfs-${PV}"

SRC_URI = " \
	http://users.elis.ugent.be/~mronsse/cdfs/download/cdfs-${PV}.tar.bz2 \
	file://0001-Fix-compile-error-with-linux-2.6.32.patch;patch=1 \
"

do_install() {
	unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
	oe_runmake -C "${STAGING_KERNEL_DIR}" DEPMOD=echo INSTALL_MOD_PATH="${D}" SUBDIRS="${S}" ${MODULE_MAKE_FLAGS} modules_install
}

