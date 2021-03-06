def gnome_verdir(v):
	import re
	m = re.match("^([0-9]+)\.([0-9]+)", v)
	return "%s.%s" % (m.group(1), m.group(2))

SECTION ?= "x11/gnome"
SRC_URI = "${GNOME_MIRROR}/${BPN}/${@gnome_verdir("${PV}")}/${BPN}-${PV}.tar.bz2;name=archive"

DEPENDS += "gnome-common"

FILES_${PN} += "${datadir}/application-registry  \
	${datadir}/mime-info \
	${datadir}/mime/packages \	
	${datadir}/mime/application \
	${datadir}/gnome-2.0"

inherit autotools gtk-icon-cache pkgconfig gconf mime

AUTOTOOLS_STAGE_PKGCONFIG = "1"

gnome_stage_includes() {
	autotools_stage_includes
}

do_install_append() {
	rm -rf ${D}${localstatedir}/lib/scrollkeeper/*
	rm -rf ${D}${localstatedir}/scrollkeeper/*
	rm -f ${D}${datadir}/applications/*.cache
}

