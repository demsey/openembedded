#
#	STLinux 2.2 kernel (2.6.17.14) for board stb7100ref
#	with patches/configurtion for Katherine UFS 910
#

require linux-openstmstb-${STM_RELEASE}.inc 

#HOMEPAGE = ""

PR = "${INC_PR}.0"

FILESPATH_append = ":${FILE_DIRNAME}/linux-ufs910/${STM_RELEASE}"

SRC_URI_append = "\
    file://linux-ufs910_smsc_stm22.patch;patch=1;pnum=1 \
    file://linux-ufs910_i2c_stm22.patch;patch=1;pnum=1 \
    file://linux-ufs910_setup_stm22.patch;patch=1;pnum=1 \
    file://linux-fat_stm22.patch;pnum=1 \
    file://linux-fuse_stm22.patch;pnum=1 \
    file://linux-net_stm22.patch;pnum=1 \
    file://linux-tune_stm22.patch;pnum=1 \
    file://linux-usbwait123_stm22.patch;pnum=1 \
    file://linux-jffs2-lzma_stm22.patch;pnum=1 \
    file://linux-ftdi_sio.c_stm22.patch;pnum=1 \
    file://linux-ufs910_stboards_stm22.patch;patch=1;pnum=1 \
    file://linux-${KV}-${SRCREV}_${MACHINE}.config \
    "

do_configure_prepend() {
    oe_machinstall -m 0644 ${WORKDIR}/linux-${KV}-${SRCREV}_${MACHINE}.config ${S}/.config
}
