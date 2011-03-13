
require stmfb.inc

SRC_URI[stmfb.md5sum] = "07bb1d3661760c3a353c959fbf0999ca"
SRC_URI[stmfb.sha256sum] = "a2e6e2d28cc38fc15d261b89d0095a9597e5c448f5de3566159e4feaf6baf301"

STM_RELEASE = "stm23"

# Version specific patches 

SRC_URI_append_openstmstb = " \
	file://stmfb_${PV_MAJOR}-${PV_MINOR}_tdt_hacks.patch;patch=1;pnum=1 \
	file://stmfb_${PV_MAJOR}-${PV_MINOR}_ext_blt.patch;patch=1;pnum=1 \
	file://stmfb_${PV_MAJOR}-${PV_MINOR}_${MACHINE}_configure.patch;patch=1;pnum=1 \
	"

SRC_URI_append_cuberevo-mini-fta = " \
        file://stmfb_${PV_MAJOR}-${PV_MINOR}_ext-clock.patch;patch=1;pnum=1 \
        "
SRC_URI_append_cuberevo-250hd = " \
        file://stmfb_${PV_MAJOR}-${PV_MINOR}_ext-clock.patch;patch=1;pnum=1 \
        "

STMFB_EXTRA_CONF_append_cuberevo-mini-fta = " -DUSE_EXT_CLK"
STMFB_EXTRA_CONF_append_cuberevo-250hd    = " -DUSE_EXT_CLK"
