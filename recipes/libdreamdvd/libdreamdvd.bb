# libdreamdvd.bb build file
DESCRIPTION="libdvdnav wrapper for dream multimedia stbs"
LICENSE = "GPL"
DEPENDS = "libdvdnav"
RDEPENDS = "libdvdnav"

SRCREV=""
SRCDATE="20101124"
BRANCH="${@base_contains('MACHINE', 'dm7025', '7025', 'master', d)}"

PR = "r0"
PV = "0.9+git${SRCDATE}"

SRC_URI="git://schwerkraft.elitedvb.net/libdreamdvd/libdreamdvd.git;protocol=git;branch=${BRANCH};tag=${SRCREV}"

CFLAGS_dm500hd_append = " -DHARDWARE_SUPPORT_LPCM"
CFLAGS_dm800se_append = " -DHARDWARE_SUPPORT_LPCM"
CFLAGS_dm7020hd_append = " -DHARDWARE_SUPPORT_LPCM"
CFLAGS_dm8000_append = " -DHARDWARE_SUPPORT_LPCM"
#CFLAGS_dm800_append = " -DHARDWARE_SUPPORT_LPCM"

S = "${WORKDIR}/git"

inherit autotools pkgconfig

do_stage() {
	autotools_stage_all
}
