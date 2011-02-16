DESCRIPTION = "Dreambox TS/M2TS audio passthrough helper lib"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "proprietary"
MAINTAINER = "Andreas Monzner <andreas.monzner@multimedia-labs.de>"

PV = "0.1"
PR = "r0"

SRC_URI = "http://sources.dreamboxupdate.com/download/7020/libpassthrough-${PV}-${MACHINE}.so"

do_install() {
	install -d ${D}${libdir}
	install -m 0755 ${WORKDIR}/libpassthrough-${PV}-${MACHINE}.so ${D}${libdir}/libpassthrough.so
}

RPROVIDES += "libpassthrough"

PACKAGE_ARCH := "${MACHINE_ARCH}"
FILES_${PN} = "/"
