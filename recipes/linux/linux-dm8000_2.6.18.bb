require linux-opendreambox-2.6.18.inc

PR="${PR_INC}.1"

SRC_URI += "\
	file://linux-2.6.18-disable-unneeded-uarts.patch;patch=1 \
	file://linux-2.6.18-dm8000-nand-smp-fix.patch;patch=1 \
"
