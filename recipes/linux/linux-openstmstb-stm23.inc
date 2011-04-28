#
#	STLinux 2.3 kernel (2.6.23.17) for board stb7100ref with SH4 CPU
#	with common patches for stm based Set-Top-Boxes
#

require linux-${STM_RELEASE}.inc

PR = "${INC_PR}.0"

FILESPATH_append = ":${FILE_DIRNAME}/linux-openstmstb/${STM_RELEASE}:${FILE_DIRNAME}/linux-openstmstb/${STM_RELEASE}/${SRCREV}"
SRCREVSTR = "${@base_conditional('SRCREV', '0119', '', '_${SRCREV}', d)}"

SRC_URI_append = "\
    file://linuxdvb_stm23${SRCREVSTR}.patch;patch=1;pnum=1 \
    file://time_stlinux23${SRCREVSTR}.diff;patch=1;pnum=1 \
    file://cpp_stm23${SRCREVSTR}.patch;patch=1;pnum=1 \
    file://mtd_stm23${SRCREVSTR}.patch;patch=1;pnum=1 \
#   file://cmdline_printk_stm23${SRCREVSTR}.patch;patch=1;pnum=1 \
    file://sound_stm23${SRCREVSTR}.diff;patch=1;pnum=1 \
    file://linux-sh4-asm_mov_0xffffff_stm23${SRCREVSTR}.patch;patch=1;pnum=1;minrev=0123 \
    file://linux-mini_fo_stm23.patch;patch=1;pnum=1 \
    "

