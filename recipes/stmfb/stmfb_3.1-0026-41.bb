
require stmfb.inc

SRC_URI[stmfb.md5sum] = "2a147f090cc99e6cde1e267b8c077446"
SRC_URI[stmfb.sha256sum] = "6b2049055f9ee6e1c0f0a9372c7d14a63a4b382c76fc0ee14b4adf6256bbf75d"

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
