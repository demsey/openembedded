#
#	STLinux 2.3 kernel (2.6.23.17) for board stb7100ref with CPU 0123
#	with patches/configurtion for ABCom IPBOX 900HD, Sezam 901HD, VIZYON-810HD
#

DESCRIPTION = "Linux kernel for ABCom IPBOX 900HD, Sezam 901HD, VIZYON-810HD"

STM_RELEASE = "${@bb.data.getVar('PV', d, 1).split('+')[1]}"
STM_PR      = "${@bb.data.getVar('PV', d, 1).split('+')[2]}"

require linux-${STM_RELEASE}_${STM_PR}.inc
require linux-${STM_RELEASE}-openstmstb.inc
require linux-${STM_RELEASE}-cuberevo.inc
