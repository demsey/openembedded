DESCRIPTION = "Library for decoding dts audio to wav"
LICENSE = "GPL"
SECTION = "libs"
PRIORITY = "optional"
PR = "r1"

inherit autotools pkgconfig

SRC_URI = "http://download.videolan.org/pub/videolan/libdca/0.0.5/libdca-0.0.5.tar.bz2 \
	file://r83-mark-tables-as-static-constants.patch;patch=1 \
	file://r84-normalisation-factor-sqrt2+output-bias.patch;patch=1 \
	file://r87-sanity-check-for-subframes-and-prim_channels.patch;patch=1 \
	file://r88-fix-random-crashes-caused-by-invalid-32-bit-shifts.patch;patch=1 \
	file://r89-avoid-crashing-with-invalid-frames.patch;patch=1 \
"

S = "${WORKDIR}/${PN}-${PV}"

EXTRA_OECONF = " --with-gnu-ld"

PACKAGES =+ "dcadec dcadec-doc"

FILES_${PN} = " ${libdir}/libdca.s* "
FILES_${PN}-dev = " ${includedir}/*.h ${libdir}/libdca.* ${libdir}/pkgconfig/* "
FILES_${PN}-dbg += " ${libdir}/.debug/*"
FILES_dcadec = " ${bindir}/* "
FILES_dcadec-dbg += " ${bindir}/.debug/* "
FILES_dcadec-doc = " ${mandir}/man1/* "

do_stage() {
	autotools_stage_all
}

# use single precision is enough and speedups the libdca about 10-15%
do_patchfloat() {
	sed -i -e 's/double/sample_t/g' ${S}/libdca/*.h
	sed -i -e 's/double/sample_t/g' ${S}/libdca/*.c
}

addtask patchfloat after do_patch before do_configure
