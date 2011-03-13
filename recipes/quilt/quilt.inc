DESCRIPTION = "Tool to work with series of patches."
HOMEPAGE = "http://savannah.nongnu.org/projects/quilt/"
SECTION = "devel"
LICENSE = "GPL"

SRC_URI = "http://download.savannah.gnu.org/releases/quilt/quilt-${PV}.tar.gz \
           file://patch_2.6.1_version.patch;patch=1 \
           file://install.patch;patch=1"

S = "${WORKDIR}/quilt-${PV}"
