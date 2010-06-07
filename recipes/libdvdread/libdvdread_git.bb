# libdvdread.bb build file
HOMEPAGE="http://git.debian-maintainers.org"
DESCRIPTION="DVD read multimeda library"
LICENSE = "GPL"

PV = "4.1.3+git"
PR = "r9"
# tag debian/4.1.3-9
SRCREV = "8d2745c6e61cbcf70112d5bb0d15685090e20af1"

SRC_URI = "git://git.debian-maintainers.org/git/daniel/libdvdread.git;protocol=git;branch=debian;tag=${SRCREV}"
S = "${WORKDIR}/git"

inherit autotools pkgconfig

EXTRA_OEMAKE = "DESTDIR=${D}"

do_munge() {
	for i in `ls debian/patches | grep ".patch" | sort -n`; do
		oenote "Applying debian patch '$i'";
		patch -p1 < debian/patches/$i;
	done;
}

addtask munge before do_compile after do_patch

do_install() {
	oe_runmake install
}

do_stage() {
	autotools_stage_all
	cat ${S}/misc/dvdread-config | sed -e "s,-I/usr/include,-I${STAGING_INCDIR}," \
				     | sed -e "s,-L/usr/lib,-L${STAGING_LIBDIR}," \
		> ${STAGING_BINDIR_CROSS}/dvdread-config
	chmod a+rx ${STAGING_BINDIR_CROSS}/dvdread-config
}

