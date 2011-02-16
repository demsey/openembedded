#!/bin/sh

/usr/bin/showiframe /boot/backdrop.mvi

cd /home/root

if [ -f /usr/lib/libpassthrough.so ]
	LD_PRELOAD="/usr/lib/libopen.so.0.0 /usr/lib/libpassthrough.so" /usr/bin/enigma2
else
	LD_PRELOAD=/usr/lib/libopen.so.0.0 /usr/bin/enigma2
fi

# enigma2 exit codes:
#
# 0 - restart enigma
# 1 - halt
# 2 - reboot
#
# >128 signal

ret=$?
case $ret in
	1)
		/sbin/halt
		;;
	2)
		/sbin/reboot
		;;
	4)
		/sbin/rmmod lcd
		/usr/sbin/fpupgrade --upgrade 2>&1 | tee /home/root/fpupgrade.log
		sleep 1;
		/sbin/rmmod fp
		/sbin/modprobe fp
		/sbin/reboot
		;;
	*)
		;;
esac
