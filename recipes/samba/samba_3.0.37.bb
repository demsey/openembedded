require samba.inc
require samba-basic.inc

SRC_URI += "file://configure.patch;patch=1 \
            file://kernel-oplocks.patch;patch=1 \
            "
SRC_URI_append_linux-uclibc        = "file://uclibc-strlcpy-strlcat.patch;patch=1"
SRC_URI_append_linux-uclibceabi = "file://uclibc-strlcpy-strlcat.patch;patch=1"

PE_opendreambox = "4"
PR = "r0"

EXTRA_OECONF += "\
	SMB_BUILD_CC_NEGATIVE_ENUM_VALUES=yes \
	"

