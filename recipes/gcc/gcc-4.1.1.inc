require gcc-common.inc

DEPENDS = "mpfr gmp"

INC_PR = "r1"

SRC_URI = "${GNU_MIRROR}/gcc/gcc-${PV}/gcc-${PV}.tar.bz2 \
	file://100-uclibc-conf.patch;patch=1 \
	file://110-arm-eabi.patch;patch=1 \
	file://200-uclibc-locale.patch;patch=1 \
	file://300-libstdc++-pic.patch;patch=1 \
	file://301-missing-execinfo_h.patch;patch=1 \
	file://302-c99-snprintf.patch;patch=1 \
	file://303-c99-complex-ugly-hack.patch;patch=1 \
	file://304-index_macro.patch;patch=1 \
	file://602-sdk-libstdc++-includes.patch;patch=1 \
	file://740-sh-pr24836.patch;patch=1 \
	file://800-arm-bigendian.patch;patch=1 \
	file://801-arm-bigendian-eabi.patch;patch=1 \
	file://arm-nolibfloat.patch;patch=1 \
	file://arm-softfloat.patch;patch=1 \
	file://gcc41-configure.in.patch;patch=1 \
	file://arm-thumb.patch;patch=1 \
	file://arm-thumb-cache.patch;patch=1 \
	file://cse.patch;patch=1 \
	file://zecke-xgcc-cpp.patch;patch=1 \
	file://unbreak-armv4t.patch;patch=1 \
        file://fix-ICE-in-arm_unwind_emit_set.diff;patch=1 \
        file://gcc-4.1.1-pr13685-1.patch;patch=1 \
        file://gcc-ignore-cache.patch;patch=1 \
        file://gcc-4.1.1-e300cx.patch;patch=1 \
        file://pr34130.patch;patch=1 \
	file://sed-fixinc-backslash.patch;patch=1 \
	"

SRC_URI_append_sh3  = " file://sh3-installfix-fixheaders.patch;patch=1 "

FILESPATH_append_sh4 = ":${FILE_DIRNAME}/gcc-4.1.1/stm22"

SRC_URI_append_sh4  = " file://sh_unwind.patch;patch=1 \
			file://cppdefault_cross.patch;patch=1 \
			file://gcc-4.1.1-st40r2-4.0.1.patch;patch=1 \
			file://gcc-4.1.1-st40r2-4.0.1-no-cbranchdi.patch;patch=1 \
			file://gcc-4.1.1-cross_search_paths-sh4.patch;patch=1 \
			file://gcc-4.1.1-recursive_inline_fix.patch;patch=1 \
			file://gcc-4.1.1-linux-multilib-fix.patch;patch=1 \
			file://gcc-4.1.1-PR27781-fix.patch;patch=1 \
			file://gcc-4.1.1-regmove-fix-20061130.patch;patch=1 \
		      "

#This is a dirty hack to get gcc 4.1.1 to compile for glibc AND uclibc on ppc
#the patch that is need it to get gcc support soft-floats with glibc, makes gcc fail with uclibc
#SRC_URI_append_linux = " file://ppc-gcc-41-20060515.patch;patch=1 \
#                         file://ppc-sfp-long-double-gcc411-7.patch;patch=1 "

# Language Overrides
FORTRAN = ""
JAVA = ""

EXTRA_OECONF_BASE = "--disable-libssp --disable-libmudflap"

STM_RELEASE_openstmstb = "23"

do_configure_prepend_openstmstb () {
    sed -i  -e '/VERSUFFIX/s,".*"," (STMicroelectronics/Linux Base ${PV}-${STM_RELEASE} prepared by ${DISTRO_NAME} ${PR})",' \
        -e '/bug_report_url/s,".*","<URL:https://bugzilla.stlinux.com>",' \
        ${S}/gcc/version.c
}
