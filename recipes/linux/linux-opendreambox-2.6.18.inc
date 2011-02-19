require linux-opendreambox.inc

SRCREV = "c59d7210272be29e3850aca3abbff76443f65d6f-fixed"
PR_INC = "r10"

RREPLACES_kernel = "kernel-2.6.18-7.1-${MACHINE}"
RCONFLICTS_kernel = "kernel-2.6.18-7.1-${MACHINE}"
RREPLACES_kernel-image = "kernel-image-2.6.18-7.1-${MACHINE}"
RCONFLICTS_kernel-image = "kernel-image-2.6.18-7.1-${MACHINE}"

SRC_URI += " http://trappist.elis.ugent.be/~mronsse/cdfs/download/cdfs-2.6.18.tar.bz2 \
	file://stblinux-2.6.18-cdfs.patch \
	file://linux-2.6.18-fix-mips-crosscompile.patch;patch=1 \
	file://linux-2.6.18-fix-proc-cputype.patch;patch=1 \
	file://dvb-api-2.6.18-5.3.patch;patch=1 \
	file://linux-2.6.18-dvb-core-headers-20100904.patch;patch=1 \
	file://linux-2.6.18-dvb-frontends-headers-20100904.patch;patch=1 \
	file://stblinux-2.6.18-use-default-stack-size.patch;patch=1 \
"

do_configure_prepend() {
	if [ -d ${WORKDIR}/cdfs-${PV} ]; then
		mv ${WORKDIR}/cdfs-${PV} ${S}/fs/cdfs
		cd ${S} & patch -p1 < ${WORKDIR}/stblinux-2.6.18-cdfs.patch
	fi;
}
