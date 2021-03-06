SECTION = "libs"
DESCRIPTION = "GNU multiprecision arithmetic library"
HOMEPAGE = "http://www.swox.com/gmp/"
LICENSE = "GPL LGPL"

SRC_URI = "ftp://ftp.gnu.org/gnu/gmp/gmp-${PV}.tar.bz2 \
	   file://configure.patch;patch=1 \
	   file://amd64.patch;patch=1"

inherit autotools 

ARM_INSTRUCTION_SET = "arm"

acpaths = ""

do_stage () {
	autotools_stage_all
}
