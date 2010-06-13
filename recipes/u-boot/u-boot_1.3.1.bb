require u-boot.inc

DEFAULT_PREFERENCE = "-1"

PR = "r1"

FILESPATH_append_openstmstb = ":${WORKDIR}/stm"

SRC_URI[patchset.md5sum] = "3fae511b42a604358b2aa36b78e2e270"
SRC_URI[patchset.sha256sum] = "cfd615fff49eab12c2533d2133904a5e1cb43a7e8d29340f310354c79e1e63c9"

SRC_URI = "ftp://ftp.denx.de/pub/u-boot/u-boot-${PV}.tar.bz2 \
           file://mpc8313e-rdb-autoboot.patch;patch=1 \
           file://mpc8313e-rdb-mtdparts.patch;patch=1 \
           file://mpc8313e-rdb-nand.patch;patch=1"


SRC_URI_append_openstmstb = "\
	${CVS_TARBALL_STASH}u-boot/u-boot_${PV}-stm24-47-patchset.tar.bz2;name=patchset \
	file://u-boot-1.3.1-stm-20080319.patch.gz;patch=1 \
	file://u-boot-1.3.1-sha1-header-fix.patch;patch=1 \
	file://u-boot-1.3.1-stmmac_fix.patch;patch=1 \
	file://u-boot-1.3.1_stm23_0034-20080610.patch.gz;patch=1 \
	file://u-boot-1.3.1_stm23_0036-20080801.patch.gz;patch=1 \
	file://u-boot-1.3.1_stm23_0038-20081014.patch.gz;patch=1 \
	file://u-boot-1.3.1_stm23_0043.patch;patch=1 \
	file://u-boot-1.3.1_stm23_0044.patch;patch=1 \
	file://u-boot-1.3.1_stm23_0045.patch;patch=1 \
	file://u-boot-1.3.1_stm23_0046.patch;patch=1 \
	file://u-boot-1.3.1_stm23_0046-fs-fix.patch;patch=1 \
	"

SRC_URI_append_ufs910 = "\
	file://ufs910/u-boot-1.3.1_stm23_0046-ufs910.patch;patch=1 \
	file://ufs910/u-boot-1.3.1_stm23_0046-ufs910-lzma.patch;patch=1 \
	file://ufs910/u-boot-1.3.1_stm23_0046-ufs910-bootmenu.patch;patch=1 \
	file://ufs910/u-boot-1.3.1_stm23_0046-ufs910-findfs.patch;patch=1 \
	file://ufs910/u-boot-1.3.1_stm23_0046-ufs910-mini.patch;patch=1 \
	"