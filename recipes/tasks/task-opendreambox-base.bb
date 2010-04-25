DESCRIPTION = "OpenDreambox: Base Task for the OpenDreambox Distribution"
SECTION = "opendreambox/base"
LICENSE = "MIT"
PR = "r5"

inherit task

#
# task-opendreambox-base
#
DESCRIPTION_${PN} = "OpenDreambox: Basesystem utilities"

OPENDREAMBOX_BASE_ESSENTIAL = "\
  autofs \
  base-files-doc \
  dreambox-bootlogo \
  dreambox-compat \
  dreambox-wdog \
  ${@base_contains('MACHINE', 'dm7025', '', 'dreambox-tpmd', d)} \
  dreambox-feed-configs \
  dreambox-keymaps \
  e2fsprogs-e2fsck \
  e2fsprogs-mke2fs \
  fakelocale \
  netkit-base \
  opkg-nogpg \
  timezones-alternative \
  tuxbox-common \
  util-linux-sfdisk \
  vsftpd \
  hdparm \
"

OPENDREAMBOX_BASE_RECOMMENDS = "\
  dropbear \
  dreambox-dccamd \
  sambaserver \
  zeroconf \
"

OPENDREAMBOX_BASE_OPTIONAL_RECOMMENDS = "\
  gdbserver \
  hddtemp \
  joe \
  mc \
  ncdu \
  ppp \
  smartmontools \
  avahi-daemon \
"

RDEPENDS_${PN} = "\
	${OPENDREAMBOX_BASE_ESSENTIAL} \
"

RRECOMMENDS_${PN} = "\
	${OPENDREAMBOX_BASE_RECOMMENDS} \
	${OPENDREAMBOX_BASE_OPTIONAL_RECOMMENDS} \
"

RRECOMMENDS_${PN}_dm7025 = "\
	${OPENDREAMBOX_BASE_RECOMMENDS} \
"
