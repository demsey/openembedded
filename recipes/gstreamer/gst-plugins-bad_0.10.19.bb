require gst-plugins.inc

PR = "${INC_PR}.1"

do_configure_prepend() {
    sed -i -e s:docs::g Makefile.am
}

DEPENDS += "gst-plugins-base"

EXTRA_OECONF_opendreambox += "--disable-apexsink --disable-dvdnav --disable-cdaudio --disable-mpeg2enc --disable-mplex"

SRC_URI_append_opendreambox += " file://mpegpsdemux_speedup.diff;patch=1;pnum=0 \
				 file://mpegtsdemux_fix_ac3_detection.diff;patch=1;pnum=0 \
				 file://aacparse-fix-rank.diff;patch=1;pnum=1"

RCONFLICTS_gst-plugin-mpegdemux = "gst-plugin-fluendo-mpegdemux"
RREPLACES_gst-plugin-mpegdemux = "gst-plugin-fluendo-mpegdemux"
