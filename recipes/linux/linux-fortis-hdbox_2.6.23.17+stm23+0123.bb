#
#	STLinux 2.3 kernel (2.6.23.17) for board stb7100ref with CPU 0123
#	with patches/configurtion for Fortis FS-9200 (HDBox), Octagon SF-1008 HD PVR
#

DESCRIPTION = "Linux kernel for Fortis FS-9200 (HDBox), Octagon SF-1008 HD PVR"

STM_RELEASE = "${@bb.data.getVar('PV', d, 1).split('+')[1]}"
STM_PR      = "${@bb.data.getVar('PV', d, 1).split('+')[2]}"

require linux-${STM_RELEASE}_${STM_PR}.inc
require linux-${STM_RELEASE}-openstmstb.inc 

#HOMEPAGE = ""

PR = "${INC_PR}.0"

FILESPATH_append = ":${FILE_DIRNAME}/linux-fortis-hdbox/${STM_RELEASE}"

SRC_URI_append = "\
    file://fortis-hdbox_setup_stm23.diff;patch=1;pnum=1 \
    file://fortis-hdbox_dvb_core_stm23.patch;patch=1;pnum=1 \
    file://linux-sh4-${KV}-${STM_PR}_${MACHINE}.config \
    "

do_configure_prepend() {
    oe_machinstall -m 0644 ${WORKDIR}/linux-sh4-${KV}-${STM_PR}_${MACHINE}.config ${S}/.config
}
