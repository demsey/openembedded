require ffmpeg.inc

LICENSE = "LGPLv2.1+"

DEPENDS += "schroedinger libgsm"

PE = "1"
PR = "r0"

DEFAULT_PREFERENCE = "1"

SRC_URI = "http://ffmpeg.org/releases/ffmpeg-${PV}.tar.bz2"

FULL_OPTIMIZATION_armv7a = "-fexpensive-optimizations  -ftree-vectorize -fomit-frame-pointer -O4 -ffast-math"
BUILD_OPTIMIZATION = "${FULL_OPTIMIZATION}"

EXTRA_FFCONF_armv7a = "--cpu=cortex-a8"
EXTRA_FFCONF_mipsel = "--arch=mips"
EXTRA_FFCONF ?= ""

EXTRA_OECONF = " \
        --enable-shared \
        --enable-pthreads \
        --disable-stripping \
        --cross-prefix=${TARGET_PREFIX} \
        --prefix=${prefix}/ \
        --enable-libgsm \
        --enable-libmp3lame \
        --enable-libschroedinger \
        --enable-libtheora  \
        --enable-libvorbis \
        --enable-swscale \
        --arch=${TARGET_ARCH} \
        --enable-cross-compile \
        --extra-cflags="${TARGET_CFLAGS} ${HOST_CC_ARCH}${TOOLCHAIN_OPTIONS}" \
        --extra-ldflags="${TARGET_LDFLAGS}" \
	--target-os=linux \
        ${EXTRA_FFCONF} \
"

do_configure() {
	./configure ${EXTRA_OECONF}
}

