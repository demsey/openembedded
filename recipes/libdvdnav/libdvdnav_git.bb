# libdvdnav.bb build file
HOMEPAGE="http://git.debian-maintainers.org/"
DESCRIPTION="DVD navigation multimeda library"
LICENSE = "GPL"
DEPENDS = "libdvdread"
RDEPENDS = "libdvdread"

PV = "4.1.3+git"
PR = "r8"

#debian/4.1.3-7
SRCREV="850e513d4fea29b40879378b13003cd677e5214b"

EXTRA_OECONF = "--with-dvdread-prefix=${STAGING_LIBDIR}/.."

SRC_URI = "git://git.debian-maintainers.org/git/daniel/libdvdnav.git;protocol=git;branch=debian \
	file://dvdnav-fix-random-shuffle-titles.patch;patch=1;pnum=1"

S = "${WORKDIR}/git"

inherit autotools pkgconfig

do_munge() {
	for i in `ls debian/patches | grep ".patch" | sort -n`; do
		oenote "Applying debian patch '$i'";
		patch -p1 < debian/patches/$i;
	done;
}

addtask munge before do_compile after do_patch

do_stage() {
	autotools_stage_all
}
