DESCRIPTION = "Policy based mounter that gives the ability to mount removable devices as a user"
HOMEPAGE = "http://pmount.alioth.debian.org/"
LICENSE = "GPLv2"
PR = "r1"

DEPENDS = "hal e2fsprogs-libs sysfsutils"
RDEPENDS_${PN}-hal = "${PN}"
RRECOMMENDS_${PN}-hal = "hal"

SRC_URI = "http://alioth.debian.org/frs/download.php/2624/${P}.tar.gz \
	   file://gettext.patch;patch=1 \
	   file://install.patch;patch=1 \
	  "

inherit autotools gettext

EXTRA_OECONF = "--enable-hal"

PACKAGES =+ "${PN}-hal"

FILES_${PN}-hal = "${bindir}/pmount-hal"

