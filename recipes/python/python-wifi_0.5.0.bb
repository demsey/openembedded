DESCRIPTION = "Fusil is a Python library used to write fuzzing programs."
HOMEPAGE = "http://fusil.hachoir.org/"
SECTION = "devel/python"
LICENSE = "GPLv2"
SRCNAME = "python-wifi"

SRC_URI = "http://download.berlios.de/pythonwifi/${SRCNAME}-${PV}.tar.bz2"
S = "${WORKDIR}/${SRCNAME}-${PV}"

inherit setuptools

RDEPENDS_${PN} = "\
  python-ctypes \
  python-datetime \
"



