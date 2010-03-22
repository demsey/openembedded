require linux-opendreambox.inc

SRCREV = "a2a48b5dca53784507da399a256895cc598a3c1f"
PR="r1"

RREPLACES_kernel = "kernel-2.6.18-7.1-dm500hd"
RCONFLICTS_kernel = "kernel-2.6.18-7.1-dm500hd"
RREPLACES_kernel-image = "kernel-image-2.6.18-7.1-dm500hd"
RCONFLICTS_kernel-image = "kernel-image-2.6.18-7.1-dm500hd"

SRC_URI += " http://trappist.elis.ugent.be/~mronsse/cdfs/download/cdfs-2.6.18.tar.bz2 \
	file://stblinux-2.6.18-cdfs.patch \
	file://linux-2.6.18-fix-mips-crosscompile.patch;patch=1 \
	file://linux-2.6.18-fix-proc-cputype.patch;patch=1 \
	file://linux-2.6.18-fix-serial.patch;patch=1"

do_configure_prepend() {
	oe_machinstall -m 0644 ${WORKDIR}/dm800_defconfig ${S}/.config
	if [ -d ${WORKDIR}/cdfs-${PV} ]; then
		mv ${WORKDIR}/cdfs-${PV} ${S}/fs/cdfs
		cd ${S} & patch -p1 < ${WORKDIR}/stblinux-2.6.18-cdfs.patch
	fi;
	oe_runmake oldconfig
}
