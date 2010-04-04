# cuberevo-sh4.inc

MACHINE_FEATURES += "alsa pci wifi"

#PREFERRED_VERSION_linux-libc-headers = "2.6.23.17"
PREFERRED_PROVIDER_task-opendreambox-dvbapi = "task-opendreambox-dvbapi3"
PREFERRED_PROVIDER_task-opendreambox-ui = "task-opendreambox-enigma2"

TARGET_ARCH = "sh4"
#TARGET_FPU = "soft"
PACKAGE_ARCH = ${TARGET_ARCH}
MACHINE_ARCH = "sh4"

require conf/machine/include/cuberevo.inc
