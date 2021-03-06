DESCRIPTION = "python-elementary and python-blipapi based blip.pl client"
AUTHOR = "Sebastian Krzyszkowiak <seba.dos1@gmail.com>"
HOMEPAGE = "http://wiki.github.com/dos1/blipomoko"
LICENSE ?= "GPL"
RDEPENDS = "python-elementary python-dbus python-edbus python-ecore"
SECTION = "x11/applications"

SRC_URI = "git://github.com/dos1/blipomoko.git;protocol=http"
S = "${WORKDIR}/git"

PV = "0.0+gitr${SRCREV}"
PR = "r0"

inherit distutils

FILES_${PN} += "/usr/share/blipomoko"

