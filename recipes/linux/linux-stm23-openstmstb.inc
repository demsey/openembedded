#
#	STLinux 2.3 kernel (2.6.23.17) for board stb7100ref with SH4 CPU
#	with common patches for stm based Set-Top-Boxes
#

PR = "${INC_PR}.0"

FILESPATH_append = ":${FILE_DIRNAME}/linux-stm23-openstmstb:${FILE_DIRNAME}/linux-stm23-openstmstb/${STM_PR}"

SRC_URI_append = "\
    file://linuxdvb_stm23_${STM_PR}.patch;patch=1;pnum=1 \
    file://time_stlinux23_${STM_PR}.diff;patch=1;pnum=1 \
    file://cpp_stm23_${STM_PR}.patch;patch=1;pnum=1 \
    file://mtd_stm23_${STM_PR}.patch;patch=1;pnum=1 \
#   file://cmdline_printk_stm23_${STM_PR}.patch;patch=1;pnum=1 \
    file://sound_stm23_${STM_PR}.diff;patch=1;pnum=1 \
    file://linux-sh4-asm_mov_0xffffff_stm23_0123.patch;patch=1;pnum=1 \
    "

