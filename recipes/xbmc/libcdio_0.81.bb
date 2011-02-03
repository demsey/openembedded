DESCRIPTION = "The GNU Compact Disc Input and Control library (libcdio) contains a library for CD-ROM and CD image access."
LICENSE = "GPL"
PR = "r1"
DEPENDS_opendreambox = "libcddb"

SRC_URI = "http://ftp.gnu.org/gnu/libcdio/libcdio-${PV}.tar.gz"
SRC_URI_append_opendreambox = " file://libcdio-0.81-add-cdtextinfo.patch;patch=1"

inherit autotools

EXTRA_OECONF = " ac_cv_member_struct_tm_tm_gmtoff=no"

FILES_${PN} = "${bindir}/*"

python populate_packages_prepend () {
	glibdir = bb.data.expand('${libdir}', d)
	do_split_packages(d, glibdir, '^lib(.*)\.so\.*', 'lib%s', 'gstreamer %s library', extra_depends='', allow_links=True)
}



