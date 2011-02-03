DESCRIPTION = "An HTTP library implementation in C"
SECTION = "x11/gnome/libs"
LICENSE = "GPL"
DEPENDS = "libproxy glib-2.0 gnutls libxml2 sqlite3 gnome-keyring"
DEPENDS_opendreambox = "glib-2.0 gnutls libxml2 sqlite3"

#inherit gnome
inherit autotools

AUTOTOOLS_STAGE_PKGCONFIG = "1"

SRC_URI = "${GNOME_MIRROR}/libsoup/${@'.'.join((bb.data.getVar('PV', d, 1)).split('.')[:2])}/libsoup-${PV}.tar.bz2"
S = "${WORKDIR}/libsoup-${PV}"

EXTRA_OECONF_opendreambox += "--without-gnome"
#the following is needed for dm800 .. i dont know why...
SRC_URI_append_opendreambox = " file://libsoup-libz-hack.patch;patch=1;pnum=1"

PACKAGES =+ "libsoup-gnome"
FILES_libsoup-gnome = "${libdir}/libsoup-gnome*.so.*"
FILES_${PN} = "${libdir}/libsoup-2*.so.*"
FILES_${PN}-dev = "${includedir}/ ${libdir}/"
FILES_${PN}-doc = "${datadir}/"
