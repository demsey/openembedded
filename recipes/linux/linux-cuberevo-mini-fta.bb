#
#	STLinux 2.3 kernel (2.6.23.17) for board stb7100ref
#	with patches/configurtion for (Cuberevo 200HD)
#

DESCRIPTION = "Linux kernel for (Cuberevo 200HD)"

require linux-${STM_RELEASE}.inc
require linux-${STM_RELEASE}-openstmstb.inc
require linux-${STM_RELEASE}-cuberevo.inc
