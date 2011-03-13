DESCRIPTION = "STM Frame Buffer driver"
SECTION = "kernel/modules"
LICENSE = "GPL"

inherit module

PV_MAJOR = "${@bb.data.getVar('PV',d,1).split('-')[0]}"
PV_MINOR = "${@bb.data.getVar('PV',d,1).split('-')[1]}"
PV_MICRO = "${@bb.data.getVar('PV',d,1).split('-')[2]}"

SRCREV = "${PV_MINOR}"

# It should be fixed in openestmstb kernel bb files
MACHINE_KERNEL_PR_append = "${MACHINE}+${STM_RELEASE}+${SRCREV_pn-linux-${MACHINE}}-r0"

DEPENDS += "rpm2cpio-native"

FILESPATH_append = ":${FILE_DIRNAME}/${PN}-${PV_MAJOR}:${FILE_DIRNAME}/${PN}-${PV_MAJOR}/${PV_MINOR}"

RPM_SRC_FILE = "stlinux23-host-${PN}-source-${PV_MAJOR}_${STM_RELEASE}_${PV_MINOR}-${PV_MICRO}.src.rpm"

# For enabling overriding if needed
STM_PATH ?= "ftp://ftp.stlinux.com/pub/stlinux/2.3/updates/SRPMS"

SRC_URI = "${STM_PATH}/${RPM_SRC_FILE};name=${PN}"

S = "${WORKDIR}/${PN}"
# Inside of stmfb-3.1 tarbals name is more detailed
S_append = "${@base_conditional("PV_MAJOR", "3.0", "", "-${PV_MAJOR}_${STM_RELEASE}_${PV_MINOR}", d)}"


SRC_URI_append = " \
	file://stmfb_cross-compile_fix.patch;patch=1;pnum=1;maxrev=0020 \
	"

addtask munge before do_patch after do_unpack

# Set boxtype
STMFB_EXTRA_CONF ?= "-DCONFIG_${@'${MACHINE}'.upper().replace('-','_')}"

do_munge() {
	rpm="${WORKDIR}/${RPM_SRC_FILE}"
	tarbal="${PN}-${PV_MAJOR}_${STM_RELEASE}_${PV_MINOR}.tar.bz2"
	if [ -f "$rpm" ]; then
		cd "${WORKDIR}"
		rpm2cpio.pl $rpm | cpio -ivd $tarbal
		tar xjf "${WORKDIR}/${tarbal}" -C ${WORKDIR}
	fi

	# Set extra parameters
	mf="stm/coredisplay/Makefile"
	if [ -f "${S}/Linux/${mf}" ]; then
	  mf="${S}/Linux/${mf}"
	elif [ -f "${S}/linux/drivers/${mf}" ]; then
	  mf="${S}/linux/drivers/${mf}"
	fi
	sed -i "s/ -DINSERT_EXTRA_CXXFLAGS_HERE/ ${STMFB_EXTRA_CONF}/g" "${mf}"
}

MODULES = "stmfb stmcore-display-stx7100 \
	stmvout stmcore-display-stx7109c3"

PACKAGES = "${PN} ${PN}-dev"

# Do it because standard oe_instal don't ship them
# Required for some others applications e.g. enigma2
do_install_append() {
	install -D -d ${D}${includedir}/linux/stm
	if [ -d ${S}/Linux/video ]; then
		install -m 0644 ${S}/Linux/video/*.h ${D}${includedir}/linux
	elif [ -d ${S}/linux/drivers/video ]; then
		install -m 0644 ${S}/linux/drivers/video/*.h ${D}${includedir}/linux
	fi
	if [ -d ${S}/Linux/include/linux/stm ]; then
		install -m 0644 ${S}/Linux/include/linux/stm/* ${D}${includedir}/linux/stm
	elif [ -d ${S}/linux/include/linux/stm ]; then
		install -m 0644 ${S}/linux/include/linux/stm/* ${D}${includedir}/linux/stm
	fi
}

