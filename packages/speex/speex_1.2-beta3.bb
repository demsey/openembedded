DESCRIPTION = "Speex is an Open Source/Free Software patent-free audio compression format designed for speech."
SECTION = "libs"
LICENSE = "BSD"
HOMEPAGE = "http://www.speex.org"
DEPENDS = "libogg"
PR = "r0"

SRC_URI = "http://downloads.us.xiph.org/releases/speex/speex-1.2beta3.tar.gz"
S = "${WORKDIR}/${PN}-1.2beta3"

PARALLEL_MAKE = ""

inherit autotools pkgconfig

LEAD_SONAME = "libspeex.so"

# Some interesting options are:
#
#	--enable-arm4-asm
#	--enable-arm5e-asm
#       --enable-blackfin-asm
#	--enable-fixed-point
#       --disable-float-api --disable-vbr (must disable-vbr if disable-float-api)
#

EXTRA_OECONF_append_openmn = " --enable-arm5e-asm --enable-fixed-point --disable-float-api --disable-vbr "
EXTRA_OECONF_append_amsdelta = " --enable-arm4-asm --enable-fixed-point --disable-float-api --diable-vbr "
EXTRA_OECONF_append_bfin = " --enable-blackfin-asm --enable-fixed-point --disable-float-api --diable-vbr "
EXTRA_OECONF_append_arm = " --enable-fixed-point --disable-float-api --disable-vbr "
EXTRA_OECONF_append_dht-walnut = " --enable-fixed-point --disable-float-api --disable-vbr "

do_configure_append() {
	sed -i s/"^OGG_CFLAGS.*$"/"OGG_CFLAGS = "/g Makefile */Makefile */*/Makefile
	sed -i s/"^OGG_LIBS.*$"/"OGG_LIBS = -logg"/g Makefile */Makefile */*/Makefile
	perl -pi -e 's:\s*-I/usr/include$::g' Makefile */Makefile */*/Makefile
}

do_stage() {
	oe_libinstall -C libspeex -so libspeex ${STAGING_LIBDIR}
	install -d ${STAGING_INCDIR}/speex
	install -m 0644 include/speex/*.h ${STAGING_INCDIR}/speex
	install -m 0644 speex.m4 ${STAGING_DATADIR}/aclocal/
}