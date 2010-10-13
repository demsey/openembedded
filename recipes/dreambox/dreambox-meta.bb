DESCRIPTION = "Base meta install package for Dreambox plugin meta packages"
SECTION = "base"
PRIORITY = "required"
LICENSE = "proprietary"
MAINTAINER = "Mladen Horvat <acid-burn@opendreambox.org>"
DEPENDS = "enigma2 enigma2-plugins enigma2-skins"
RDEPENDS = "enigma2-meta enigma2-plugins-meta enigma2-skins-meta"

PN = "dreambox-meta"
PV = "1.0"
PR = "r1"

ALLOW_EMPTY = 1
PACKAGES = "${PN}"

S = "${WORKDIR}"

PACKAGE_ARCH := "${MACHINE_ARCH}"
