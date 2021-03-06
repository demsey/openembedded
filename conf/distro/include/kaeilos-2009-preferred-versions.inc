#@--------------------------------------------------------------------
#@FILE: conf/distro/include/kaeilos-2009-preferred-versions.inc
#@TYPE: Distribution
#@NAME: KaeilOS(R) - http://www.kaeilos.com
#@DESCRIPTION: KaeilOS Linux Distribution preferred version
#@MAINTAINER: Marco Cavallini <m.cavallini@koansoftware.com>
#@VERSION: 20-01-2010
#
# KaeilOS is a registered trade mark of KOAN - Bergamo - Italia
# Product website : http://www.KaeilOS.com 
#@--------------------------------------------------------------------

PREFERRED_VERSION_autoconf = "2.63"
PREFERRED_VERSION_autoconf-native = "2.63"
PREFERRED_VERSION_automake-native = "1.10.2"
PREFERRED_VERSION_busybox 	= "1.13.2"
PREFERRED_VERSION_cairo		= "1.8.8"
PREFERRED_VERSION_dbus 		= "1.2.3"
PREFERRED_VERSION_dropbear      = "0.51"
PREFERRED_VERSION_fontconfig	= "2.6.0"
PREFERRED_VERSION_glib-2.0 	= "2.22.1"
PREFERRED_VERSION_glib-2.0-native = "2.22.1"
PREFERRED_VERSION_glibmm = "2.22.1"
PREFERRED_VERSION_glproto	= "1.4.9"
PREFERRED_VERSION_gst-pulse 	= "0.9.7"
PREFERRED_VERSION_gtk+		= "2.18.3"
PREFERRED_VERSION_gtkmm		= "2.18.1"
PREFERRED_VERSION_hal		= "0.5.13"
PREFERRED_VERSION_libgemwidget	= "1.0"
PREFERRED_VERSION_libgpephone	= "0.4"
PREFERRED_VERSION_libsdl-x11	= "1.2.14"
PREFERRED_VERSION_libtool 	= "2.2.6a"
PREFERRED_VERSION_libtool-native = "2.2.6a"
PREFERRED_VERSION_libtool-cross	= "2.2.6a"
PREFERRED_VERSION_libtool-sdk	= "2.2.6a"
PREFERRED_VERSION_mesa          = "7.6"
PREFERRED_VERSION_mesa-dri      = "7.6"
PREFERRED_VERSION_mesa-xlib     = "7.6"
PREFERRED_VERSION_mplayer       = "0.0+1.0rc2+svnr30165"
PREFERRED_VERSION_pango 	= "1.24.4"
PREFERRED_VERSION_pixman	= "0.16.2"
PREFERRED_VERSION_pkgconfig	= "0.23"
PREFERRED_VERSION_pkgconfig-native = "0.23"
PREFERRED_VERSION_pulseaudio 	= "0.9.15"
PREFERRED_VERSION_python = "2.6.2"
PREFERRED_VERSION_samba		= "3.3.9"
PREFERRED_VERSION_tiff 		= "3.8.2+4.0.0beta2"

KAEILOS_WX_VERSION ?= "2.8.10"
PREFERRED_VERSION_wxwidgets = "${KAEILOS_WX_VERSION}"

KAEILOS_QT_VERSION ?= "4.6.0"
PREFERRED_VERSION_qt4-tools-native = "${KAEILOS_QT_VERSION}"
PREFERRED_VERSION_qt4-tools-sdk = "${KAEILOS_QT_VERSION}"
PREFERRED_VERSION_qt4-embedded = "${KAEILOS_QT_VERSION}"
PREFERRED_VERSION_qt4-embedded-gles = "${KAEILOS_QT_VERSION}"
PREFERRED_VERSION_qt4-x11-free = "${KAEILOS_QT_VERSION}"
PREFERRED_VERSION_qt4-x11-free-gles = "${KAEILOS_QT_VERSION}"

PREFERRED_VERSION_udev 		= "141"
UDEV_GE_141 = "1"

PREFERRED_VERSION_usbutils = "0.82"
PREFERRED_VERSION_wpa-supplicant = "0.6.9"
PREFERRED_VERSION_xserver-kdrive = "1.4.0.90"

# Use latest version available
#PREFERRED_VERSION_util-macros-native = "1.4.1"
#PREFERRED_VERSION_util-macros = "1.4.1"
#PREFERRED_VERSION_xserver-xorg = "1.7.3"
#PREFERRED_VERSION_xf86-video-xgi = "1.5.1"

#
# meta-moblin package SRCREVs
#
SRCREV_pn-bickley ?= "de9431b7c6040bc3731157c05947159ad2c7a0a9"
SRCREV_pn-json-glib ?= "930fdf4c4dff1f5310a946c2a9f5b6860f7c8ba8"
SRCREV_pn-libccss ?= "92bc59e1d39302c8be500d53cb5dd8b05c2e4a15"
SRCREV_pn-libgdbus ?= "aeab6e3c0185b271ca343b439470491b99cc587f"
SRCREV_pn-librest ?= "14d35103d9649dc1e10c3e9ac2c690b3165c8184"
SRCREV_pn-moblin-menus ?= "e1d63681739dd16195d005b3cf15752df294bd3c"
SRCREV_pn-mojito ?= "0542c4b0e26c0e3b69c5ad1fa1898dc276fb9f48"
SRCREV_pn-mozilla-headless-services ?= "c7873654894af6c7c6c01194d6185db46667b81f"
SRCREV_pn-mutter ?= "aff4cf110307e149d3497d20543cde27b9699758"
SRCREV_pn-twitter-glib ?= "849bec29292df88590e0b2898b50b9b8d766817e"
SRCREV_pn-xf86-video-psb ?= "b6b3bba06fe5a3fe0b1bd6e31a7369dd83812bab"



