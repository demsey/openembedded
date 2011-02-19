DESCRIPTION = "STM Frame Buffer driver"
SECTION = "kernel/modules"
LICENSE = "GPL"


SRCREV="0010"
SRCREV_MINOR="25"

# It should be fixed in openestmstb kernel bb files
MACHINE_KERNEL_PR_append = "${SRCREV}-${MACHINE}+${STM_RELEASE}+${SRCREV_pn-linux-${MACHINE}}-r0"

DEPENDS += "rpm2cpio-native"

RPM_SRC_FILE="stlinux23-host-${PN}-source-${PV}_${STM_RELEASE}_${SRCREV}-${SRCREV_MINOR}.src.rpm"

SRC_URI[rpmsource.md5sum] = "00ef88cb7a540d0c02c4d67c82fdf590"
SRC_URI[rpmsource.sha256sum] = "787bb960bc55d1fee9884741e599dde59041500b13fb9757f2e71a3e4032dd4c"

SRC_URI = "ftp://ftp.stlinux.com/pub/stlinux/2.3/updates/SRPMS/${RPM_SRC_FILE};name=rpmsource \
	file://stmfb_cross-compile_fix.patch;patch=1 \
	"

S = "${WORKDIR}/${PN}"

inherit module

addtask munge before do_patch after do_unpack

do_munge() {
	rpm="${WORKDIR}/${RPM_SRC_FILE}"
	tarbal="${PN}-${PV}_${STM_RELEASE}_${SRCREV}.tar.bz2"
	if [ -f "$rpm" ]; then
		cd "${WORKDIR}"
		rpm2cpio.pl $rpm | cpio -ivd $tarbal
		tar xjf "${WORKDIR}/${tarbal}" -C ${WORKDIR}
	fi
}

MODULES = "stmfb stmcore-display-stx7100 \
	stmvout stmcore-display-stx7109c3"

PACKAGES = "${PN} ${PN}-dev"

# Do it because standard oe_instal don't ship them
# Required for some others applications e.g. enigma2
do_install_append() {
	install -D -d ${D}${includedir}/linux/stm
	install -m 0644 ${S}/Linux/video/*.h ${D}${includedir}/linux
	install -m 0644 ${S}/Linux/include/linux/stm/* ${D}${includedir}/linux/stm
}

