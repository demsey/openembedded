#
#	STLinux 2.2 kernel (2.6.17.14) for board stb7100ref with SH4 CPU
#	with common patches for stm based Set-Top-Boxes
#

require linux-${STM_RELEASE}.inc

PR = "${INC_PR}.0"

FILESPATH_append = ":${FILE_DIRNAME}/linux-openstmstb/${STM_RELEASE}:${FILE_DIRNAME}/linux-openstmstb/${STM_RELEASE}/${SRCREV}"
SRCREVSTR = "_p${SRCREV}"

SRC_URI_append = "\
    file://linux-nosquashfs3.1_stm22.patch;patch=1;pnum=1 \
    file://linux-squashfs3.0_stm22.patch;patch=1;pnum=1 \
    file://linux-squashfs3.0_lzma_stm22.patch;patch=1;pnum=1 \
    file://linux-mini_fo_stm22.patch;patch=1;pnum=1 \
    file://linux-do-printk_stm22.patch;patch=1;pnum=1 \
    file://linux-ufs922_ktime_stm22.patch;patch=1;pnum=1 \
    file://linux-ufs922_hrtimer_stm22.patch;patch=1;pnum=1 \
    file://linux-ufs922_linuxdvb_stm22.patch;patch=1;pnum=1 \
    file://linux-ufs922_sound_stm22.patch;patch=1;pnum=1 \
    file://linux-ufs922_copo_stm22.patch;patch=1;pnum=1 \
    file://linux-ufs922_stm-dma_stm22.patch;patch=1;pnum=1 \
    file://linux-sched_stm22.patch;patch=1;pnum=1 \
    file://linux-timer_stm22.patch;patch=1;pnum=1 \
#   file://linux-cmdline_printk_stm22.patch;patch=1;pnum=1 \
    file://linux-strcpy_stm22.patch;patch=1;pnum=1 \
    "

do_configure_prepend() {
        rm ${S}/localversion-sh
        echo ${LOCAL_VERSION} > ${S}/localversion-stm
}

