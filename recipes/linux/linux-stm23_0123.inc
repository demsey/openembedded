#
#	STLinux 2.3 kernel (2.6.23.17_stm23_0123)
#

LICENSE = "GPL"
KV           = "${@bb.data.getVar('PV', d, 1).split('+')[0]}"
STM_RELEASE ?= "${@bb.data.getVar('PV', d, 1).split('+')[1]}"
STM_PR      ?= "${@bb.data.getVar('PV', d, 1).split('+')[2]}"
LOCAL_VERSION="_${STM_RELEASE}_${STM_PR}"

INC_PR = "r0"

FILESPATH = "${WORKDIR}/linux-${KV}-${STM_RELEASE}_${STM_PR}-patchset"


SRC_URI[kernel.md5sum] = "a0300a393ac91ce9c64bf31522b45e2e"
SRC_URI[kernel.sha256sum] = "62505e4ffe076478af9bbb358857f36c072c5a797030d615eda30cfab8379c53"
SRC_URI[patchset.md5sum] = "f35df463270ae27b57f36f1a2ac12de0"
SRC_URI[patchset.sha256sum] = "0f155a637eb2b8316b7ce178202fd34be56e775f3bc1013c24f7331081f63cd4"


SRC_URI = "${KERNELORG_MIRROR}/pub/linux/kernel/v2.6/linux-${KV}.tar.bz2;name=kernel \
       http://demsey.webpark.pl/openstmstb/kernel-patches/linux-${KV}-${STM_RELEASE}_${STM_PR}-patchset.tar.bz2;name=patchset \
#      file://linux-2.6.23.17-update.patch.bz2;patch=1;pnum=1 \
       file://linux-2.6.23.1-sh-wavefront.patch.bz2;patch=1;pnum=1 \
       file://linux-2.6.23.1-stm-20071101.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-stm-20071023-iounmap-fix.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-stm-20071023-pa-va-fix.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-stm-get_user_check.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-stm-20071023-mac_gmac-fix.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-stm-20071023-export-symbols.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-stm-20071023-usb-platform-fix.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-stm-20071023-hardware-RNG.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-stm-20071030-i2c-lirc-copro.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-stm-pmb-tlb-invalidate.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-stm-defconfigs.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-sh-new-binutils-fix.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-sh-cpu-cut.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-fix_pmb_mapping_usage_count.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-alsa-fixups.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-cb101-tidy.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-ilc-spinlock.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-harp-epld.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-pata-platform-flush.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-asc-non-default-console.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-mem-check.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-stm-20071030-flush-icache-range.patch;patch=1;pnum=1 \
       file://linux-2.6.23.1-stm-102-UDF_2.50.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0102-get_stack.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0102-kprobes.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0102-kptrace.patch;patch=1;pnum=1 \
#      file://linux-sh4-2.6.23.1-stm-nfs-writeback-race.patch   # Removed - in 2.6.23.13 now
       file://linux-sh4-2.6.23.1-stm-se-flag.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-stm-pmb_vtoa.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-stm-bpa2-kmalloc-move.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm-kgdb-2.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm-lttng-0.10-pre14.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-stm-32bit-initrd.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-stm-ssc-capabilities-fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-stm-spinlock-undepricate.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-sh-vmlinux-note.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-sh-uImage-fix.patch;patch=1;pnum=1 \
# kernel 104 released here
       file://linux-sh4-2.6.23.1_stm-mac_gmac-ttc.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23-smsc_pbase.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_mb411-pata-fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-stm23_fbcondecor.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-stm23_0104-flush_dcache.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-usb_bitstuffing_workaround.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-vmalloc-pgtable-sync-fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-sh_do_page_fault_sti.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-grb-typo.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-pmb-early-setup.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0104-sysconf-fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0104-eth_cb101_update.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0104-bpa2_init_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0104-stx7200-nand.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0104-usb_soft_reset.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-stasc-console-lower-irq-latency.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-lttng-immediate-schedstats.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1-fdma-resource-overrun.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0102_remove_old_alsa.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0102_fdma_fixes.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0102_registers_db.v1.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0104_new_alsa.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0104-7200_copro.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.1_stm23_0105-i2c-spi.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0105-bpa2_params.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0105-sh-rtc.patch;patch=1;pnum=1 \
# kernel 106 released here
       file://linux-sh4-2.6.23.13_stm23_0106_smsc911x_compilation_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0106_new_alsa.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0106_stasc-fdma.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0106-plat_enet_update.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0106-stx7111-mb618.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0106-mac-gmac_update.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0106-mb519-led-fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0106-pmb-unmap-fix-and-lock.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0106-stasc-misc-fixes.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0106-consistent-32bit-fixes.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0106-hms1-i2c1.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0106-stcoprocessor-32bit.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0106-stm-usb-module.patch;patch=1;pnum=1 \
# kernel 107 released here
       file://linux-sh4-2.6.23.14_stm23_0107-coproc-udev.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-new_alsa.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-calibrate_delay.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-fpu_error_fix.patch;patch=1;pnum=1 \
       file://linux-2.6.23.16-rtc-sh.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-lirc.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-sysconf_h_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-mb562_support.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-boards_harp_cleanup.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-coherent.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-mb618-epld.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-bpa2-zero-req.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-stasc-no-console.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-stpio-warning.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-mb618-defconfig-gmac.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-cb101se-defconfig.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0107-7200-ilc-demux.patch;patch=1;pnum=1 \
       file://linux-2.6.23_phy_pm.patch;patch=1;pnum=1 \
       file://linux-2.6.23_ste10xp_pm.patch;patch=1;pnum=1 \
       file://linux-2.6.23_smsc_phy.patch;patch=1;pnum=1 \
       file://linux-2.6.23_stmmac_timer.patch;patch=1;pnum=1 \
# kernel 108 released here
       file://linux-sh4-2.6.23.14_stm23_0108-7111-sh4-clk.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0108-coherent-unmap.patch;patch=1;pnum=1 \
# kernel 109 released here
       file://linux-sh4-2.6.23.16_stm23_0109-i2c_bus_numbering_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0109-gpio_implementation.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0109-mb520_mb618_gpio_support.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0109-uImage-32bit.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16-0109-smsc_32bit.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16-0109-0109-mova_align_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16-0109-stmmac_sw-timer.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0109-mb671_support.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16-0109-i2c_update.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.13_stm23_0109-spi_integrate_subsys.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0109-stm-gpio-interrupts.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0109-raw_writesl-st40-300-bug-workaround.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.14_stm23_0107-7111-ext-irq.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0109-stx7105-mb680.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0109-stx7111-missing-interrupts.patch;patch=1;pnum=1 \
# kernel 110 released here
       file://linux-sh4-2.6.23.16_stm23_0110-boards_cleanup.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0110-new_alsa.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0110_stmmac_stats.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0110-emi_cleanup.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0110-stx7200_irq_cleanup.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0110-stx7200_pata_support.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0110-epld_cleanup.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0110-smsc_911x_platformization.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0110-daughter_boards.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0110-stem_info.patch;patch=1;pnum=1 \
# kernel 111 released here
       file://linux-sh4-2.6.23.16_stm23_0110-i2c-robustness-fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0110-db641.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0110-mb588.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0110-db679.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0111-pio_fixes.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0111-bpa2_memory-robustness.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0111-alsa_continuous_rates.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0111-RNG-update.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0111-RNG-devrandom.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0111-mb442_flash_fixes.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112-lirc-scd.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0111-stx7105-interrupts-fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0111-stx7105-stx7111-ilc-fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0111-7200_module_clock.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0111-stx7105-stx7200c2-sata.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0111-stx7105-stmmac-pbl.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0111-ilc-set_type.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0111-mb705.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0111-mb519-defconfig-usb.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0111-fdma_error_handling_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0111-fdma_get_residue_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0111-alsa_fdma_irq_fixes.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0111-mb671_on-board_phy_rmii.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0111-disable_initrd_defaults_in_empty_zero_page.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0111-stx7105-pwm.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0111-stx7105-usb-routing.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0111-stx7105-fdma.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0111-stx7105-pata-stem.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0111-stx7105-clocks-fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_lan91C111-phy_powerup.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.16_stm23_0111_gmac_mc-wol_fix.patch;patch=1;pnum=1 \
# kernel 112 released here
       file://linux-sh4-2.6.23.17_stm23_0112-stx7200c2_usb_oc_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112-mb671_update.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112-cb102.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0113-wireless_update.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112-phy_pm_wake.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112-stmmac-wol_selection.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112.i2c_repstart_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112-mb519_ssc1_i2c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112-stm-usb-wrapper-update.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112-stx7141-mb628.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112-mb602.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112-mb618-epld-update.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112-mb680-led-fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112-st-init-memory-tidyup.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0112-stm-coprocessor-tidyup.patch;patch=1;pnum=1 \
# kernel 113 released here
#      file://linux-sh4-2.6.23.17_stm23_0113-stmmac-mdio-tidyup.patch # Removed in 0116
       file://linux-sh4-2.6.23.17_stm23_0113.i2c_clockstretch_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0113-sh-denorm-conversion.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0113-bpa2_more_info.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0113-sh-tmu_NO_HZ_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0113-sh-oprofile-callgraphs.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0113-cfi_probe.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0113-stm-cpufreq.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0113-stm-hardwired-ssc-i2c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0113-alsa_7200c2_pcmreader1_fix.patch;patch=1;pnum=1 \
# Kernel 114 released here
       file://linux-sh4-2.6.23.17_stm23_0114-stm-gpio-disable_irq_nosync.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0114-stb710x-stx7111-intc-priorities.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0114-stx7141-include-delay.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0114-stm-dma_mask.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0114-mii-remove-spurious-pin.patch;patch=1;pnum=1 \
# Kernel 115 released here
       file://linux-sh4-2.6.23.17_stm23_0115_cond_resched.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-stem_mb519_mb671_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-alsa_7200c2_pcmreader_underruns_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-alsa_procfs_beautyfication.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-alsa_converters_rework.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-alsa_assertions_unification.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-alsa_readers_names_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-alsa_stx7141_support.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-mb628_phy_reset_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115_tmu2.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115_stmmac_tmu2.patch;patch=1;pnum=1 \
       file://linux-2.6.git-32c1da70810017a98aa6c431a5494a302b6b9a30.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115.i2c_arbitration_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-alsa_xrun_handling_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-alsa_stx7105_support.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-alsa_players_names_unification.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-alsa_8_pcm_devices_limit_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-alsa_iec958_channel_status_bits_update.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-alsa_epld_converter.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-alsa_mb628_support.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-mm_init_no_memset.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-sh-signal-recheck.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-stasc-remove-set-termios-loop.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-7105_lircd_support.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-7141_lircd_support.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-7141_usb_overcurrent_fix.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-fb_find_mode_interlaced.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-coproc-boot.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-support-hdref.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-stmmac_no_phy.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.17_stm23_0115-new_coproc_support.patch;patch=1;pnum=1 \
# Kernel 116 released here
       file://linux-sh4-2.6.23.y_stm23_0116-22bd0c754ddc001ac2e087af5acc5874c91639fc.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-9d18f04d847f8ff894d1b30357a2b983ddc85f74.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-1ec6daa4d071e58e29ec9c4933b29a3a02922284.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-d7d8cbbc8f02840ce0ca10df506e279f4f7ed142.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-b385da232fb288a96e7f5ec669d2146b7d60d5b5.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-5a2ba2ed702c8f93eeb15776b010aa4eb5869f49.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-ddc7fb91b383f69793950e82635165d611115e4e.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-f6a4abfa50e2bf25c844a0260cc88682e657af26.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-201866e97553f73830f4f7a8bf4132d18995a61a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-9edc2904383c97b8ec67798a02e052cf0c4eb055.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-50f9bff09071d51d326cdd16d97af5e2ff188653.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-ecae17e83723b34c8e0e23db347aed867c1ffe78.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-520988dd65c66d0f0c5a96459b8b62e22a34a595.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-a1dd0bb0a9e270d9393a9141a3c93a02819bc5af.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-13521020505fec6789207a8a1144c0f0225da94c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-77ffded36d4c7fea9107023df29d0a8a2edf92e9.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-c8cb308a1fb89ee5549ff0bb10482f5119f424e3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-2e751785cff6ad8030d85a99ed4ace17be5e6a01.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-9c86ca8ffaa1a536b0a92406eced73379e73832b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-ddb739a87b015e98a8d7cbc6250da832235262d8.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-7a1dee0a66fb5485a980d186571ebd79626d34c5.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-4607ab148f5178079aee95adad90d36ee304b05a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-0f18cf507178fdc9f2684d944847a459195c3a27.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-824ca24f84c01c2fc073c1a08a567f4aebf9f070.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-d4dc8bd7af3a25785b8b1a6d4418010c7f38ec7d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-ed3710517fd935537059543f808c343079708ec8.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-ed1a68a40e17b31feb733ae3dd38a979265eb9b2.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-e5cce8d4dad6f2314fc6fe0020a5641ea29e81da.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-16c9a925fa3308d3945584ea1f05597a96bd9b11.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-a1a3cea00349b4f80b8ebfed195ee960c6ab426d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-8753045dc393b3a640a4ac739fbf074732e691c4.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-476aaa1160119e5fbf6ce4a67657892cde379fb0.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-4d15b6a8ad35ae375c2cc7030d0ae00dc179ea51.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-5a17e8901abad550b33b382cc955d0b404edf45d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-9c5d76b643d3e59f3208fdaa096c92f0a7a58ed0.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-e209f7d5f9edb43432d29d437eda0e8df24746e6.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-4636a80e942dfb914d9bf2fbbd0fd9aff5cc770b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-c12f93aa81037e37d51980a54564e627a16d7134.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-5b614b5b8952c5187087ceecadb431460c457ef3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-144bf274aa1194cb6609feaad420287346ecbf5e.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-e22c71c9ffa42d5f57646e457e746fc4d013cddd.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-02c632cb481bb885c20299ef39d54ec991f2f8ce.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-5ce43b2db9c31f3d29fc0953b15fa211b649aca3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-5d3ac1d1319e29ad168954267ed3f2389dec286b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-48a0b8b0f726b02d57b9f45282b6c20532cfd959.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-cd2d2c1a2e99a5178dfaad07482002a3e0339556.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-82c4b34630fda065b47a083734b6fa51a07aaafc.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-fec77380323c63209e7174e24e8bf40002da56d3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-877e42fb3eca8b317bc5c2a807c4554a696a7662.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-a2428725518a326abfe4ac236298f1a778b7c823.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-e23034f3c14b9fd5d5a26754c7c657b985b1dfa9.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-3ff72b71c6cd775ba50033e77701b965112fa1b9.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-389e9eb9644452d5d88f5d48553a61b15e93fb75.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-75014d5e2c0b2528833ed6d9edcfc1c113589c18.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-69dc3171284ae9c54d3932a5e8d5d8bb0d63a44c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-6ee593201d2e786a63dbe9a501850a3d6de6b83a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-e79aba996b524d8c487ae3778281b02c37ed9b1b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0116-522f25af3379f559652a11ff67d05d190ca24483.patch;patch=1;pnum=1 \
# Kernel 117 released here
       file://linux-sh4-2.6.23.y_stm23_0117-81692519d8964e1a2e3b4cc9c2b881a6253224da.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-10e7b424d3002fb2be202d09239af89d3fc60238.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-15158cb82e29626c564bc972f478cdcc8f7c32f3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-ff41d480962b611acf96b827d6d79be49b17483c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-172b863c8a8dfdcbe8450db781e7f7571fd28808.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-ea397adab4d455d4d3de28d34ebcf7a3ed135b02.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-1a259888ebf8d31a1c97f2764a8ed8b1373c9597.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-51d0cbdf8772e94b580d529de2318b7e0ac15b84.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-a0b70ce73faa90d53376e88e4d17d72df605bf40.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-e29ff4f772b5782fbdcc201f9b5779fa482d5ddc.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-33e570ce49ee9023888b4ad4365bff75a397f36d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-2f19e82c045e54f62446dee07a258046abb24092.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-c5d2cf3c3b621a878784c612df6507aa8f6c5616.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-b8e5b22b364b2fd75776eb8bc00a679044265489.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-aba6995e75007a5798ef72e5097820b91effc023.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-3c4f533935ce1c55c54cee662d6915b3de8bccb2.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-f332ae19b06c8a915e5c6308d1792781ef927bfe.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-fef80fa3307febd1e00e735894651157ef2d65f3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-68eca7eeb87c9ca7dc47f366d0a8e5d5d2b1a390.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-b2238c81565f86202e5d7776a714af0b53425abf.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-a070e0eb7c24e202381d5b1fef0f2a90d2a9cf5a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-d2b1a7bfb25c42fa4eaab1d018224179f428f1a2.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-5de859c9c8f57588fb8e8991f9cc136a7238e66d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-781ec37d84371842fcc58c14a56ba22f23993d02.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-0a121f6e7f717c2805d467fe0e8492dc24c82f51.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-50edb4f56b91d185752f784f288e646b51383bfa.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-f4f0769c6637ccc60f8fb01424ed53848a2eb15b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-cfdb3adbc30dad1e9c3646a1b8721347baf14d2d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-7e9faec4c1feb903c15c926c30e4fa4b1d4d6fd6.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-32b0bd6231f5ebe590f9f47539cdf3d277633434.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-4e283fece4967c3cf9322c99a3ce990a490f30e6.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-af4805b4b00d2b7c0dfbf2e5a61537d18271ce71.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-c3a56822e39c8752d3347dde3e989f43bfa1a0fa.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-75a1606168267bb14e3a19e1f4cd180e429bb162.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-6c795a762444293b461e44ae734cd5cb81cec095.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-a47240626dce0af92e041b07de6d507aa9a28f47.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-9240e61a4cb139398dd0cf1522927d08ea28e220.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-b9b9109cbac292a1485df6290d6ad2416cd7e16e.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-c0a6b35ebdc5d87fda0fb2650dd1ce75008f1179.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-1e6ac72a6c5925fce0c712ee909ca3f3708517c6.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-b3dcbc0d349e0325fef19c8a10974d3c15047eaf.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-721e3060cc29087bc24753d75b1e4abf297ddf34.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-f3946308f144f978ee096ee83d4ae7860b0e6a42.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-d2d3accfad6a94736f8a820426b61069626200b4.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-ec7ab16f2750e81e2620f82abbff4abbcbd2bd03.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-916f97b0e408fdb50ed58beb9daa3b2d347f1daf.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-ea5d031da1a46834143aee16d319a4ecbe206c5f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-1d00dc3e5306e9a201f3f6ea409135188240d000.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-2f8da9fe2c700dc7f111a51b6607089dc4f87ca1.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-400020eca1d255c81414b26446d8fe24e7c060b6.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-c5695ab36da2204f7f0fc681407fa978d8c90e9f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-2045fd59e3d25cdd66bcc1566fda8973884713f9.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-521af899e6d4205060ed5054d0ee65e7594a27b4.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-a63f1018e474e7eae8ed28dd9109ff4b2a9b0613.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-032dd4242f540c351465b3790232c053e74e76fc.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-32bfe413ca2bb31765b4c022b738731ccc19667b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-3977e00cfde5bd1ef9af20c8dae845b7afa674de.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-create-localversion-stm.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0117-29bbdbf4f674f5a2ec998e93d88b86c869f90d51.patch;patch=1;pnum=1 \
# Kernel 118 released here
       file://linux-sh4-2.6.23.y_stm23_0118-c9d2f578d147004552d4ed39c0f6aab6e92cf322.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-b64916024341eb951066b821a8201edefff2cc46.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-ed153ee37347e284b32be63d3eb6418afdac0b61.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-b46d82df85bd1e53f30565bdde8f5def41bd72e3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-d706c4670cac0bc692b03416180e74c3380d81b0.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-5abd735fb5479a860b68c86dfaec0a8eef18647b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-7eef2a1af3a2657bc3b12fcbec79c6d9ab30bf85.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-3eb4a7001878c71e3ee688b2aac4b69c677b2a0c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-cfee8b36f722cab3cc377bdb18646cb055b31d73.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-4ab0894caa11b224ad78205831a77ecd1be5e510.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-1211652a26253263ae12655f2a6a8dd370d83520.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-418fed16662af1b0994a0160ee2f7faa1a9d8961.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-82728c1b0d7e0eb80ad7a5c5e7ca77516f88fef2.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-9eb9c43702a2df2e46e688a3883a37cb1f3ba09a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-0701aa5ec99f29fc985f2250a422767716f1265b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-ac116c73ee9cd7b463c632251c15e8e173cde8e9.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-d1429c6c124e781e7a1e16d352382fe87ba9aacc.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-aff57cfd7e6ea410bccc57f492378e4d8dff55c8.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-50d3a215b37c62113a213d10976247227e6cc4c6.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-59395800f317a58aeeee5e99c6a1f383c93486ad.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-904f25e7eb3c5e3f4960ddd262642a2919a25fc5.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-9c8b2e623fbf5a8e27c4209a52edbdd74bcc2540.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-ef43b32bd57162a86809380f8221c5f625699ca8.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-34a943c9ab6d745727700af773af3ead19adb164.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-21ca836799c8cbd2c7ab2376e7668264afffbf93.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-411f36cd2a7b05c98a1686227aef218144bbd4dc.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-57144b201d5d18d3d9aedb3bd20db9c3b2d96151.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-d0917a4457e5433069263eee2959cb4250cf1554.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-89658dc6fead39edaa90b128b0eb4c8929917d15.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-4508722fa1d12771d58f93cd959843abb5ced91c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-cecdc99f2c02a02c9e86fc9c74dfad3241482a11.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-67d0d4c77d4a556885279662e927efc4aec673ba.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-3a4a32fd19e04124e39216641939fa3f8b657b17.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-90de7e048bada2b191a5436160d0d0e8eb1af7d9.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-9aa408b495373e3720a7e961137b14c1d73e1b8a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-568441ffaf3a04a17545d6878a492fe7829b8ccb.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-ef94c338fbafd2afce6ac51fa55cf06e00e3ca11.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-a3ab77da8e19c279cd0e22718336c76b5ab500f0.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-d4f3ae67335ca591255e77e1a64001f9811b3b86.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-b37d5bbe15ef324a1b26109da111b89d989f8f3e.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-80592a0448241ac0b380d8aaa364b929235e4175.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-55cf06d46793aa16492f3f8571bc4f16225b4641.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-911e4000157a3b328695e1e1817ee3715cf35203.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-8bfb203a3cffa6dfaac875dcbe910e855e8e7d57.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-16c525d891ce979fa924867d30427c0e6c4a4749.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-6279ea32d7b42882306494c1497ae0c22b0f5104.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-6b6112f6e1518f23fd4e7ee95ac4952eb2351de2.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-de787220800c8772a5a1bbf646c6b98c17a9420d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-4ff205dc590a9c948e1002a5006b1620eff78aa4.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-ea521c973c4bff06979003d87c2cdeef6375ed05.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-fab4a728b97e866793257ac6debf285e68882301.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-8c5f4c964aac7ec2a781c0683a4b1e9261ac832e.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-6555a4a3b2e86dccd28a1d5577688ac3878faa11.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-f4d94cecc87194ee4dd4705f6ad762909e583edd.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-e1a8d221baf3b688da702cb4f462214f1ce1e7c6.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-efb8a524daae7e1279d111081f94af5b273f9055.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-895c52b1ba20b93cb2e33a6019fa2f514062e003.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0118-ed18271e063fcaba6da3e92268ad5866c2ac8de9.patch;patch=1;pnum=1 \
# Kernel 119 released here
       file://linux-sh4-2.6.23.y_stm23_0119-f10519a37c6a8d1041077ec1cc0a8eb49f81b543.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-90a9151e8093de452b9246c9b8fae9ef3292d0ff.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-7cd409dd8581255ac8a88648f2892b0fa8d9e23c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-60200e0075e2f3abbd741db8c89ba80941311644.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-f522d9d62f1c66e01c4f4156cc5446f4666d580e.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-09f1294b0ad3f35fe33660189f13b065a2ee76e7.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-1d945b373e34904ee2aab1075e75cddeed9b0a5f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-cd0b1d8543b7534ffbb5a9e2ddb1e1ec5e303942.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-e8559a4c974d4c541baea130701c551a041c0a4c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-4be2c7f44bfdc52e8d38ce60a54dec2bdabe4fbe.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-f6329da30af904795cdcc2453b1c50cd4ca77930.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-c5b7cb77735ffb2af1dd92941cce95966c00779b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-96b67bab47ba1ab27e121b07b7cbdcabe7b2e6f2.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-a9e399a0fa7dac68d2a6320a76ace77f6e488741.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-0d31b49f88279d5ebf9df5fd161998d70684f76f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-a258fceb7c7bd1d909a98035462e65e4e4352df6.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-598ba5dfdd0353b0cad91023c3024f9b4b9b817f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-011a05247133c63d8a2a7d125ffac905cc39682c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-fecf1f0fe98e93f2be7edf3f3e7e7825ad0a4d46.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-658b50d614dba874528b1888ac5326bc470bba5c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-be927effd506ab476714b8ba23ee0d546eb07cec.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-e9526569ccb9cf3e4b4e2c4aa6a5a777fcdc5336.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-da33c6cceb5f029c8a3e0dc12e2b3348b001202f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-54a92ac812cf4dca840660e44c3b532ba3133509.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-a701d43e940f6f38e74f7bbe55d221aa9a6a2596.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-3f7642536abf98f92520a6ef89a63c53bcdbab93.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-7c6bde8536c594763ad850873041b2c3d4bf758d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-903ce26036cd0ec0ce31bbade286667b655fad78.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-36c6544f3b180fb7874431677fbac109351be5ac.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-789ebc1cfb307afaef99d36a6fd59e304944afb0.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-50f6ae4fb7ea9bd43cc07b4ad10909e47db2f1c3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-1d62faefc7e83a568ed9e3010e54db08628c17b3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-bcdcbeeb93ec963cb5e6b4125e97aaa655223008.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-9f43adf411cd03bab865039045953a87adbd61d9.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-7944b39716bb0bfb252ce648be01f729954a6674.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-8d2664db1c1967848356b9082ce0e7b0796d3e61.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-d3f4d4306ea6095f5b1bef67a51d0be8f4447bec.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-b2756f2303b4dc88e1c354654ee6f4e16e989d7c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-8346571b3f3e8ff2b949e2149d6983e2860c9d6f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-dfc3225e607b353e3cfb3bbb61f905942421537c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-6e0782f30d52d441d9e1b8eae67cc534abb92a73.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-d22450d7b5173ef373e691dbb20ea3db50e31505.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-3f4b1754fe77941f0073cc1ffd6cd9c61589e8a3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-8742f52ddab140c378f8f0b26d4a1e5ef11ecf16.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-41356c142bc556b5a295bb7e6ed3c619cb8cfd1a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-d172b7fea7f48839e0e2fed53735788084c23947.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-33002caf48ba49ab3024c572e3e986ab72a72c46.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-f775a6d40e4812ce9f97af7b589cb8e26c3275e3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-6473e9972626750d9d52ea32f2864a8e74b92dbf.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-41d004a7c4dd1d8552fb36f49e2b99642d7b904c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-9b8127a16b66aeeda78b7170b3ee3c254b54ed3e.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-297ec82ddcd8111f8947c86b4f00907ae42742d8.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-63321886237f13b208b557381c5ea880849c5e4a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-99750f045f9747761225165221f0572d4e7d399d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-8d041d967f4eaf61efe325a7aa32c2acd5dafeaf.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-3bbd35ebf4dfd4080d1a1095377ff365346c787d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-963287c074dddcf0b2accc2b2619192c44037a36.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-e560f50128d10110ecc6281bfe397569675ce501.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-f65633b21f5b16e55e78fd035160fc999fd3758f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-bef03e8f105aced533c3a409fb4c56d1a5be5d21.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-68baaa3e1640acd75b004b87f8e650df29690543.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-bc45797add0b552d51dd585c0b0160392f56a89e.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-ab95ff1c01df7414c4e7f6e95c1a1d9c0a584a81.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-2835a2232631f91b4b6c78221a9c392471eef387.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-0b7221e6b7bd8e8275864a1e0b21da7914536440.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-40f0c05d41ce95b0a42a1160a875f904613877f1.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-a4a167b5d2e4bfd8d3cb192c7dd2c6ce05d6b82c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-e6fd3c8036036b129044a9f414a7c0e4e6a96958.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-9507152a4e3464df420565d2a79a861e4e5836a6.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-bd2360cba25e06d13045c468b7c78a79298af56f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-b96e9976fa44dd6422dad9e401904df75e6b7313.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-6657ed3733cf90c9d2cef64181294c15692af650.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-2a7d622fefb08618a39720e7951188de3c194e55.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-90c22355d216925844a7351acf7fd552c1fcdd3f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-249f66d9d50cd601276ee9d083ce9000fb814f6f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-32c85990d0ead2eb0280862cd5fd5d838125c33d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-08dc890393bf642a26e31b9c39d939092da9903a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-dec62cd920161a792dcd563b8955c4ecd771d041.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-f23a469a0f0adac1005784308de8bb17681ab6af.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-710959b0b575d98372dbd4584f94b3c01de819cd.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-289e1d61ae854db26d629027f9a7f0df859c504e.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-62dd72f1c54dfe9bcd3b88345c820eb2aeaed79c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-97149fa4cacf48d50ff52ea2830a022a68df68be.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-a2c8d0a18a9f18e808362963e3d62c1a6f8db47f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-2b6b9eac04dc0f750747da27c9f874171068824a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-529fc1d0860787779b66cd57674aabcb747f2236.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-5626908bc0b95326b479fce87d1df1eb908d9d75.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-69a830d2f8e4c15e308e76ef701a6d2811ce8c95.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-1c82be2709b72507cb62ede7ef1209219a6809ff.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-da16dd6a213fdfeacf54c83bd9ae12175e12741b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-58f2b81fba1aea32cdae4e19771fe9feb5bca89c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-4564a747e1b9ea38efa992d59e5bd184e2d3b931.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-8bb17c169d55ee5e821e9b12d60c06f3e0645a60.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-9fbcf2d676cbe6c827df6fcb02a04b0b9f19ef89.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-78699c389632449a6baac94702ad7c211c12a4b9.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-404a4b73435857e37a6e5824b4e1b24e97a30200.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-eb1dfc5c5487d18d2230ed29b456623f1c7ad2f1.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-3d6b27d508b29922382bf767e1e2919118cb742d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-29d4dbb2ad6be07069fa79e4202602f412b373c0.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-d69a17ca391de6e136dc79b543348fb7cd5c5864.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-b0d8f1b32f6675d9a5f823f8205ae2196e84abbe.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-5dcb55ee8cf1e2b8dfeefd90bfca248921adf269.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-2dd1950922bd57cbe0424d363b98954793fbc484.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-f11669650ca808a6836a86c5640de928e6bcc1d3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-a5a3bec4f186c20631aa3ba400037216ebcd181d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-e004646100323a8c0561707bd287bf27a077469e.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-bda12fc59abe8edc746847f45287ebb1fbe1f0f5.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-b871e1f34e05cb41a0bc91c47b249448ecfd9f7b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-26f43c90d0a1990257a99e54b147850307d26256.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-6c1ffdf5dbe8998c1cf639b2d2043aac6df9c177.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-b7af73a27799085083575b96560bc5b8a0e2531b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-bc4f637f0357f8286be3f698bd0b227b9f4ea6a1.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-7016b2f83790858d67295298229713c031349ef0.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-f90b7cb606154cd056c87844c3dc80882ae14aa0.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-d5841e9c3cfeacabc230af0a75692516f8a21365.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-411f98f83d241b311fe8bac5a734ca686036020a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-3be4aa0d84ddb201ec0944a0032022e2336147f2.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-8333daeebc73f306a5343c45d4ab96a5db02b192.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-a905870d68575cbf77d74508441f9bc363540242.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-20e46ec2de42bd6a8fb4ee27569cac3ba3a33b78.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-c465b86820d3cbcb4eef69b89ee0411883fbda0f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-d9e21986d47c6a238b11dd83c04eafe507d9f500.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-c370d82495b4634c0796e6fd9f291049a3ced391.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-d2333634477fe7fc54318c6f61c3b0c5605729fb.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-7079862029b0c8b4874ef250ffe5f9aaac48cc09.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-15ea34224e7e3ebd6025aab4a01e963095c350c0.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-d594b3bab5ca6d25d0d5a0152dbfc2701a1936cd.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-a83539449a2a8c15758be073a949cb752f0185c9.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-af39019a0d214a8e708a1bcfc13cb757d34cd176.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-eded421b8bd35a160e4cad537b2227fece61c03d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-57c732915ac48f8719773ac2335dc64c999cf9d4.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-38165abb4e8e4e5176b4385710b1bbbf288af89d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-983786d8cb4d6d85048c16be6685bb4118c4af3f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-5da8bb2db910a9e98d79bf0b910537b7cf574111.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0119-align_with_git.patch;patch=1;pnum=1 \
# Kernel 120 released here
       file://linux-sh4-2.6.23.y_stm23_0120-708f306485766215cee302ceecf42f47fe864719.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0120-e5c806486349249d3f0a750a1a729554026677a8.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0120-d935a31efd41eaa00ae4b25838475be896ecac53.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0120-497fcbad3e404d5e27c79dfbc3e85fcdaa6a4d34.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0120-1b42c1734b75b9f83f52ccbec3cffd7ae8bbd85f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0120-704fa1c694af2cbb925e742459bd86ce9330b297.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0120-10058df50ec65d3831aeef19031d03d5fd61ff27.patch;patch=1;pnum=1 \
# Kernel 121 released here
       file://linux-sh4-2.6.23.y_stm23_0121-e80dbf2a65f357c609468852a12cfade64d0c16a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-7cd45c8a60d28086f4a5f85d79acefa6bc54f697.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-4655cc2cce3ff0215e179577eac4705084b14bbd.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-d0020266ad5e19b4a3f150a6f57f239412d3e207.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-19c5963aba7e0dfd3b7dbc857d38125c88c20c36.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-360508860c551243fa40f482a7183ff15aad93d2.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-bea531c93ef43403ee678ad9bda74fc3d4817a7c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-8278341b974dd5d3be16ba9155e1295cd6f5e8af.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-a82aafb6c08048675d1222f6a18c26176fefb45c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-77fce0e5f807d97a5ab24b03fbd2beaf6685bd78.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-dc0de827189232f631504b1f820d3d2590fa599f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-e27842db4350cf31f21561496b8489b80f8daff9.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-ff6c57b93a92266ea07898cc59e54b2d68d67dc9.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-a9088542f4858a72099f18be632ad66881b65b7e.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-4564c44936c4e6ffd745e11cfa90eed8380c9d6f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-e8a88fc9a890656c324d0100ac3b631050952691.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-50d427416d9259aa9efa0da84892c25a10c7e203.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-1fb81e11e02a50a5fbf89dd6aca16c94374d6933.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-a989c1410b67e39c7c4fee26d1a124591dceb401.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-a2e7a2ecfe22fd413b7c256a55328bca3f528e63.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-16d306d156558d6eb6d2819da10d0763bba9f8ac.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-07b8ac9c795afcc9eedc040c66b4dc8c5839ba48.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-7222e85c9caf5fd13f2c895dcd8a3dcb2b6df073.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-bf2443df15982daff2f515d0f55a84c437547063.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-6d9f795b18b991b987d29187a40ea5f3f4275b09.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-9e4d2874690eabac8c4b1a4909044d728aa2095d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-47302bc332b0523ba40e700983343061b6818628.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-e7230bd0b91627d51b28a679baf3ac5e81fadcf0.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-33806d4f8804a5ec8a6718b08dfdf5c57b7e29eb.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-a3d844a14a599496946418bd4af0ed01d3200309.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-8e94377cf5402c3b51a64fefba47246de288554a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-b6b12551e6a5aea3d6a529d97d3cd23afb6b7a36.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-3c21040a06ef083e9b41baf0ca37c3ab3d960ebd.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-fe7ad744cc4cf0fd889f0a424a89100aae46eefe.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-dcb9bc305772743c23afc2413c5b095a51cf6cfc.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-fbaf95278b6cd8103d7653a38fc9525969a4b77f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-f7177066d52079adf428b0f57921e222f3a8bdd8.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-8bedfe200f9d622ef194099da516ebc41e34e07a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-e71a24405d0c0601d3fa220d519ef30d598b88a5.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-087e1ba27ac37a2eed71d3e5fb3b69f4e57fd51b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-e85059bda7588c597fc67ee79ded7a4c7ac8690f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-66cf4915a2cc8d9e1330b3a72ab80a096f3fa013.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-648915a65fe3d4fd7cbff35042b24c6c26fbb08b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-c59639e4a056778830c0f39da38d26205a520fec.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-059c8f1aabb59d52e61f1bd0a78d55fede7001e6.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-3312cf9ac673c429d03fe873f3fa5a3f1e18b990.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-0cb25311ecb889b3fddd88d5af690720283c8d22.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-1dff11554f0b491895ff9110793376c2ec89b19d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-c91c17283181235bcb89ec3a5a4623d3e8c3084b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-ddd9ca205ccb1719c96728757985470060298a4c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-402d5361fc912178c181c57f6f3f22da27719fc2.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-d3dacfedc543525ea50ce15177de9b4b07542770.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-1aa27951e5f06c5f041e06af79927dc301e4a1ef.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-5dea60679b291a895c0aa7b9339a3582665de4ce.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-1073d4d217a149f92ae86f7c29223fb6f2b1afd3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-52dd0e9185cab0149baf21272303ece67c5ce99c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-414a373b7a585b87a1acc8a8938f61683cc1ff63.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0121-b744bfb8378d7c8e16dad6d5fbe4ff95a9b57023.patch;patch=1;pnum=1 \
# kernel 122 released here
       file://linux-sh4-2.6.23.y_stm23_0122-e15e648461fa1f3bddba490f8b5239f552038a1f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-1c14261a97f45dcb5e989ee968078110611d2fb3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-09a9b20fd77761a9effbc7b312f2d97beb360531.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-b7d92cc122edb069a0a1caa951fd498fad5a43f8.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-af9b8c0497cbbbe54619214cde938cf76f15cc20.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-4c66519c2372e876e477f103be26b59e3773407f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-5984c95b94057c3b5b072158525cac6d5feef175.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-f5a6466b1fb453141b551808f0751ccef7a61912.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-b62d3ee47f3ad6ad204926cf513f588c5fc2e558.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-d87f273b42548a0dd90de61b968913836fcb09fd.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-c727f70d79106022ee23232e4628a75c552da4b2.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-56e9cb618517588b37c7cda3ec72c6c2f8c5fec1.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-39fe697d91da7d7e4fbd189e092c8cca3373f833.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-529c74f0bd23a9e5aabf9458295c65f73ea02d0c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-4994963fd24cd11b2ad06f3471a3a45579192d7d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-7d452c830749bb5565141c6d4266fd4a12a02116.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-b18cf3b1d6ea1a1ae2077e835d5c972facac5dfe.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-2f1e36aae73ec0ecf76a8e5b95e5d90ab28e5ba8.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-a3b4f276313ef3b02f987e8bdb45b85bb4a55d99.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-02e4077bfcb13769f5fadb0019497435b910af25.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-f0dd93affe86d3af210caba602d5d2610a724369.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-abb371395460c133a7b48f489b7f78324e19b221.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-27c9701f0b74bbb269bd81a9a0901a48bfcde36b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-2e4439583739c10bd5b828324e1160a6477c3ba7.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-efa00bb213284618279295845fda937cd9214d6c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-e29319232957cbf0b8783f993945da39ea28bb86.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-1647cc9c7d7cda712d9bc1c29b567c7f3c9ca4a5.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-b9e484341c181ddfa5c297207c42bd67b98275b3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-a86a7a624d7e28435e91aee7e0c7b1a9418f6082.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-b07e220632d37a3646253cf8f71de51f4cb3ef90.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-4d98ae0a57c3b847a1a8a23847e2148b10b1ad85.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-09cdc7e673ee97fa1940d5e7c7effec75f0d7a12.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-5f05821f0e03cd7553d3ea1d3d08bfe4945b805f.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-2bde0b4f33e5c44bba31b7df9e5643c336c0555d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-114450dd1514aba583e701e9e5a12a177ea1fb3c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-4b7e714aaa565950586c80794c10dc49dff70eef.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-b8d79d4c696383efbbbaeb1ffdb69717f84fbf9d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-b4284565cab43a7f5775492d6735d41765ace913.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-cd63ceee4f53fe1098b3e7a137b2be8cfb80fc21.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-85ee52962e56243fd348cd1dede602662449ad5d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-c45b9bd5b046e7682f71a219b3b0839b0b16e470.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-6212de822302182a8a9cec2f018a24337ff238e5.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-346036c88afaa14abc81536fbc4d45b47c45551c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-fcd325da20cbde58aad1270c9ca0d5c14e26323d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-8326bceb3ce86709487b667069e533d812a39eaf.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-b80c921c3571eebdb47b5906499ea7b67a56a8cb.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-fdbb9201c2cf7fad3ffadbdb40cfde12174227e9.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-d38d8a12c6a3bda25cf86ff2921f47843e12ef19.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-c7b9d55e8269cf2d732bd3deb9fd8ac4e78fc358.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-710deed06914cfdca3592323ffc0095e015e940d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-1faa3411c31a5b48d41023f4f527bb63e20c017c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-bb39fb5d26df4b303bac15fe0329e47b3c9373f1.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-02e825b50366d7e03b658b7f46283f0eb6208314.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-7677f784da5128da9831b88ac37d1c2875affa1a.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-988c29f58691e6432ce29d338a224c30152aa647.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-f0c71b570d455b06c838bd92b64916602ee35380.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-513990e2b16dbd190ab6472bbafe3eeba5a7c50c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-8a716b1c9ef8b9ff836c482714cec6dfa2a9fbbb.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-bce885e363998f32027453864e8ce1cf17ce4712.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-cc96481e3cb5a43f930eb1b59fe5bc5f12b8a941.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-7dfdb5b8b217384f3affd7b8121a2a121290a54b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-f3fdb280e3d9245f3cc8329304b34b6e9bac5515.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-9935871b6c316a9b294e7df1ce0a0c626f1affc6.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-10078750c00095c3088910fbf1890ea65780530d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-159b78e7fad160b3722c75a7972023624c0f594b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-070f618f61a0d60e43576dc0f0ec906dcd15c08b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-712c1661f7d802f939b1f11fc8ec56a9a360c07c.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-91b003f2ff20954a02614834af36757212cdafa3.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-cb7ed228d0e22b991835f8c92bca80a5c0768a7d.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-fdee6ee852042b7204e42ce8e928a95060ec472e.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-ac4a259c396e32f7f06015c802b0f98bebafa95e.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-94946c3b65d8bd14d6c749a1a40b458ca59bf94b.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-53d2524441ee5bf2d00b49bcf3035621f4425591.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-c45abe6750cc48cf6265386cc7461be2c6a092ca.patch;patch=1;pnum=1 \
       file://linux-sh4-2.6.23.y_stm23_0122-10d211cebd56665192f9bf0071656e6db41d85fe.patch;patch=1;pnum=1 \
# Kernel 123 released here
       "

S = "${WORKDIR}/stblinux-${KV}"

inherit kernel

FILES_kernel-image = "/boot/uImage* /boot/autoexec.bat"

export OS = "Linux"
KERNEL_IMAGETYPE = "uImage"
#KERNEL_IMAGE_SYMLINK_NAME = "${KERNEL_IMAGETYPE}"
KERNEL_OBJECT_SUFFIX = "ko"

PKG_kernel-image = "kernel-image-${@bb.data.getVar('KERNEL_VERSION',d,1).replace('_','+')}"
PKG_kernel-base = "kernel-${@bb.data.getVar('KERNEL_VERSION',d,1).replace('_','+')}"
ALLOW_EMPTY_kernel = "0"
ALLOW_EMPTY_kernel-base = "0"
ALLOW_EMPTY_kernel-modules = "0"

do_munge() {
    mv ${WORKDIR}/linux-${KV} ${WORKDIR}/stblinux-${KV}
    if [ -d ${S}/drivers/sound ]; then
        rm -R ${S}/drivers/sound;
    fi;
}

addtask munge before do_patch after do_unpack

do_configure() {
    oe_runmake oldconfig
}

do_install_append () {
    install -d ${D}/boot
    install -m 0755 vmlinux ${D}/boot/vmlinux
    echo "/flash/bootlogo.elf" > ${D}/boot/autoexec.bat
}

do_uboot_mkimage() {
}

pkg_preinst_kernel-image () {
    [ -d /proc/stb ] && mount -o rw,remount /boot
    true
}

pkg_postinst_kernel-image () {
    [ -d /proc/stb ] && mount -o ro,remount /boot
    true
}

pkg_prerm_kernel-image () {
    [ -d /proc/stb ] && mount -o rw,remount /boot
    true
}

pkg_postrm_kernel-image () {
    [ -d /proc/stb ] && mount -o ro,remount /boot
    true
}

