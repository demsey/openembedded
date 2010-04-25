require linux-libc-headers.inc

INHIBIT_DEFAULT_DEPS = "1"
DEPENDS += "unifdef-native"
PR = "r1"

SRC_URI = "${KERNELORG_MIRROR}/pub/linux/kernel/v2.6/linux-${PV}.tar.bz2;name=kernel \
           file://unifdef.patch;patch=1"

SRC_URI_append_arm = " file://procinfo.h"

STM_RELEASE_openstmstb = "stm23"
STM_PR_openstmstb      = "0123"

FILESPATH_append_openstmstb = ":${WORKDIR}/linux-${PV}-${STM_RELEASE}_${STM_PR}-patchset"

SRC_URI[kernel.md5sum] = "a0300a393ac91ce9c64bf31522b45e2e"
SRC_URI[kernel.sha256sum] = "62505e4ffe076478af9bbb358857f36c072c5a797030d615eda30cfab8379c53"
SRC_URI[patchset.md5sum] = "f35df463270ae27b57f36f1a2ac12de0"
SRC_URI[patchset.sha256sum] = "0f155a637eb2b8316b7ce178202fd34be56e775f3bc1013c24f7331081f63cd4"

SRC_URI_append_openstmstb = " \
		http://demsey.webpark.pl/openstmstb/kernel-patches/linux-${PV}-${STM_RELEASE}_${STM_PR}-patchset.tar.bz2;name=patchset \
		file://linux-2.6.23.1-sh-wavefront.patch.bz2;patch=1 \
		file://linux-2.6.23.1-stm-20071101.patch;patch=1 \
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
	        avr32*)   ARCH=avr32 ;;
                bfin*)    ARCH=blackfin ;;
	esac
}

do_configure() {
	set_arch
	oe_runmake allnoconfig ARCH=$ARCH
}

do_compile () {
}

do_install() {
	set_arch
	oe_runmake headers_install INSTALL_HDR_PATH=${D}${exec_prefix} ARCH=$ARCH
}

do_install_append_arm() {
	cp ${WORKDIR}/procinfo.h ${D}${includedir}/asm/
}

STAGE_TEMP="${WORKDIR}/temp-staging"

do_stage () {
	set_arch
	rm -rf ${STAGE_TEMP}
	mkdir -p ${STAGE_TEMP}
	oe_runmake headers_install INSTALL_HDR_PATH=${STAGE_TEMP}${exec_prefix} ARCH=$ARCH
	if [ "$ARCH" = "arm" ]; then
		cp ${WORKDIR}/procinfo.h ${STAGE_TEMP}${includedir}/asm/
	fi
	if [ "${DISTRO}" = "openstmstb" ]; then
		cp ${S}/include/asm-${ARCH}/cachectl.h ${STAGE_TEMP}${includedir}/asm/
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

