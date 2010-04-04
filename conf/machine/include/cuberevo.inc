# cuberevo.inc

EXTRA_IMAGEDEPENDS += "dreambox-secondstage dreambox-buildimage-native"

GLIBC_ADDONS ?= "ports,nptl,libidn"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "dreambox-dvb-modules"
MACHINE_FEATURES += "kernel26 usbhost"
DISTRO_FEATURES ?= ""

OLDEST_KERNEL = "2.6.17"

PREFERRED_PROVIDER_virtual/kernel = "linux-${MACHINE}"


