#
#	STLinux 2.3 kernel (2.6.23.17) for board stb7100ref
#	with patches/configurtion for ABCom IPBOX 910HD, Sezam 902HD, MADTEK HD 3000L, VIZYON-820HD PVR
#

DESCRIPTION = "Linux kernel for ABCom IPBOX 910HD, Sezam 902HD, MADTEK HD 3000L, VIZYON-820HD PVR"

require linux-${STM_RELEASE}.inc
require linux-${STM_RELEASE}-openstmstb.inc 
require linux-${STM_RELEASE}-cuberevo.inc 
