require linux-libc-headers.inc

INHIBIT_DEFAULT_DEPS = "1"
DEPENDS += "unifdef-native"
PR = "r0"

SRC_URI[kernel.md5sum] = "e721b38e8827f74ca517f5ad617c1db7"
SRC_URI[kernel.sha256sum] = "2497fdf7751ac51a4505e816ca85ecb21f86fb8504850759db637d07cdf6b8f3"

SRC_URI = "${KERNELORG_MIRROR}/pub/linux/kernel/v2.6/linux-${PV}.tar.bz2;name=kernel \
#           file://arm-syscall-define.patch;patch=1 \
	"

S = "${WORKDIR}/linux-${PV}"

set_arch() {
	case ${TARGET_ARCH} in
		alpha*)   ARCH=alpha ;;
		arm*)     ARCH=arm ;;
		cris*)    ARCH=cris ;;
		hppa*)    ARCH=parisc ;;
		i*86*)    ARCH=i386 ;;
		ia64*)    ARCH=ia64 ;;
		mips*)    ARCH=mips ;;
		m68k*)    ARCH=m68k ;;
		powerpc*) ARCH=powerpc ;;
		s390*)    ARCH=s390 ;;
		sh*)      ARCH=sh ;;
		sparc64*) ARCH=sparc64 ;;
		sparc*)   ARCH=sparc ;;
		x86_64*)  ARCH=x86_64 ;;
	esac
}

do_configure() {
	set_arch
	oe_runmake defconfig ARCH=${ARCH}
        cp -pPR "include/asm-$ARCH" "include/asm"
        if test "$ARCH" = "arm"; then
                cp -pPR include/asm/arch-ebsa285 include/asm/arch
        elif test "$ARCH" = "sh"; then
                cp -pPR include/asm/cpu-${TARGET_ARCH} include/asm/cpu || die "unable to create include/asm/cpu"
        fi
	echo '#define LINUX_VERSION_CODE 132625' >> include/linux/version.h
	echo '#define KERNEL_VERSION(a,b,c) (((a) << 16) + ((b) << 8) + (c))' >> include/linux/version.h
	# Add UTS_RELEASE to version.h. UTS_RELEASE was moved from version.h to 
	# utsrelease.h in order to avoid recompiling a kernel every time a localversion
	# changed. Since the our headers are static and we're not compiling an 
	# actual kernel, re-adding UTS_RELEASE does't hurt, and it allows uclibc to 
	# compile with kernel headers that work with EABI on ARM
	echo '#define UTS_RELEASE "2.6.17"' >> include/linux/version.h
}

do_compile () {
}

do_install() {
	set_arch
        install -d ${D}${includedir}
        cp -pfLR include/linux ${D}${includedir}/
        cp -pfLR include/asm-${ARCH} ${D}${includedir}/
        cp -pfLR include/asm-generic ${D}${includedir}/
}

do_install_append_arm() {
	cp include/asm-arm/procinfo.h ${D}${includedir}/asm
}

STAGE_TEMP="${WORKDIR}/temp-staging"

do_stage () {
	rm -rf ${STAGE_TEMP}
	install -d ${STAGE_TEMP}${exec_prefix}/include/
	cp -pfLR include/linux ${STAGE_TEMP}${exec_prefix}/include/
	cp -pfLR include/asm ${STAGE_TEMP}${exec_prefix}/include/
	cp -pfLR include/asm-generic ${STAGE_TEMP}${exec_prefix}/include/
	cp -pfLR include/scsi ${STAGE_TEMP}${exec_prefix}/include/
	if [ "${ARCH}" == "arm" ]; then
		cp include/asm-arm/procinfo.h ${STAGE_TEMP}${includedir}/asm
	fi
	install -d ${STAGING_INCDIR}
	install -d ${CROSS_DIR}/${TARGET_SYS}/include
	for x in linux asm asm-generic scsi; do
		rm -rf ${STAGING_INCDIR}/$x;
		cp -pfLR ${STAGE_TEMP}${includedir}/$x ${STAGING_INCDIR}/
		rm -rf ${CROSS_DIR}/${TARGET_SYS}/include/$x;
		cp -pfLR ${STAGE_TEMP}${includedir}/$x ${CROSS_DIR}/${TARGET_SYS}/include/
	done
}

do_stage_append_nylon () {
	cp -pPR include/asm-${ARCH}/* ${STAGING_INCDIR}/asm/
	cp -pPR include/asm-${ARCH}/* ${CROSS_DIR}/${TARGET_SYS}/include/asm/
	cp -pPR include/linux/* ${STAGING_INCDIR}/linux/
	cp -pPR include/linux/* ${CROSS_DIR}/${TARGET_SYS}/include/linux/
}

