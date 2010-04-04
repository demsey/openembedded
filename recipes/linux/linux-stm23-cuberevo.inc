#
#	STLinux 2.3 kernel (2.6.23.17) for board stb7100ref with SH4 CPU
#	with patches for cuberevo devices
#

HOMEPAGE = "http://enigma2.sifteam.eu/index.php?dir=Enigma2%20developer%20zone/"

PR = "${INC_PR}.0"

FILESPATH_append = ":${FILE_DIRNAME}/linux-cuberevo/${STM_RELEASE}"

SRC_URI_append = "\
    file://cuberevo_patches_stlinux23_${STM_PR}.patch;patch=1;pnum=1 \
    file://cuberevo_rtl8201_stlinux23_${STM_PR}.patch;patch=1;pnum=1 \
    file://${MACHINE}_setup_stlinux23_${STM_PR}.patch;patch=1;pnum=1 \
    file://linux-sh4-${KV}-${STM_PR}_${MACHINE}.config \
    "

do_configure_prepend() {
    oe_machinstall -m 0644 ${WORKDIR}/linux-sh4-${KV}-${STM_PR}_${MACHINE}.config ${S}/.config
}
