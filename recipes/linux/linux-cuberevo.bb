#
#	STLinux 2.3 kernel (2.6.23.17) for board stb7100ref
#	with patches/configurtion for ABCom IPBOX 9000HD, Sezam 9100HD PVR, MADTEK HD 4000L, VIZYON-8000HD PVR
#

DESCRIPTION = "Linux kernel for ABCom IPBOX 9000HD, Sezam 9100HD PVR, MADTEK HD 4000L, VIZYON-8000HD PVR"

require linux-${STM_RELEASE}.inc
require linux-${STM_RELEASE}-openstmstb.inc
require linux-${STM_RELEASE}-cuberevo.inc
