#
#	STLinux 2.2 kernel (2.6.17.14) for board stb7100ref with SH4 CPU
#	with patches for cuberevo devices
#

require linux-openstmstb-${STM_RELEASE}.inc

HOMEPAGE = "http://enigma2.sifteam.eu/index.php?dir=Enigma2%20developer%20zone/"

PR = "${INC_PR}.0"

FILESPATH_append = ":${FILE_DIRNAME}/linux-cuberevo/${STM_RELEASE}/${SRCREV}"

SRC_URI_append = "\
    file://linux-cuberevo_patches_stm22.patch;patch=1;pnum=1 \
    file://linux-cuberevo_fdma_stm22.patch;patch=1;pnum=1 \
    file://linux-cuberevo_i2c_stm22.patch;patch=1;pnum=1 \
    file://linux-cuberevo_rtl8201_stm22.patch;patch=1;pnum=1 \
    file://${MACHINE}_setup${SRCREVSTR}.patch;patch=1;pnum=1 \
    file://linux-${KV}-${SRCREV}_${MACHINE}.config \
    file://linux-fat_stm22.patch;patch=1;pnum=1 \
    file://linux-fuse_stm22.patch;patch=1;pnum=1 \
    file://linux-net_stm22.patch;patch=1;pnum=1 \
    file://linux-tune_stm22.patch;patch=1;pnum=1 \
    file://linux-usbwait123_stm22.patch;patch=1;pnum=1 \
    file://linux-jffs2-lzma_stm22.patch;patch=1;pnum=1 \
    file://linux-ftdi_sio.c_stm22.patch;patch=1;pnum=1 \
    "

do_configure_prepend() {
    oe_machinstall -m 0644 ${WORKDIR}/linux-${KV}-${SRCREV}_${MACHINE}.config ${S}/.config
}
