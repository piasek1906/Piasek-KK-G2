#!/system/bin/sh

# Kernel Tuning by Piasek1906.

# enable force fast charge on USB to charge faster
echo "1" > /sys/kernel/fast_charge/force_fast_charge;
chmod 444 /sys/kernel/fast_charge/force_fast_charge;

# make sure we own the device nodes
chown system /sys/devices/system/cpu/cpufreq/ondemand/sampling_rate
chown system /sys/devices/system/cpu/cpufreq/ondemand/sampling_down_factor
chown system /sys/devices/system/cpu/cpufreq/ondemand/io_is_busy
chown system /sys/devices/system/cpu/cpufreq/ondemand/powersave_bias
chown system /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq
chown system /sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq
chown root.system /sys/devices/system/cpu/cpu1/online
chown root.system /sys/devices/system/cpu/cpu2/online
chown root.system /sys/devices/system/cpu/cpu3/online
chmod 664 /sys/devices/system/cpu/cpu1/online
chmod 664 /sys/devices/system/cpu/cpu2/online
chmod 664 /sys/devices/system/cpu/cpu3/online

chmod -R 0700 /data/property

# disable debugging on modules, adming can enable any time.
echo "0" > /sys/module/kernel/parameters/initcall_debug;
echo "0" > /sys/module/alarm/parameters/debug_mask;
echo "0" > /sys/module/alarm_dev/parameters/debug_mask;
echo "0" > /sys/module/binder/parameters/debug_mask;
echo "0" > /sys/module/xt_qtaguid/parameters/debug_mask;

#for no_debug in $(find /sys/ -name *debug*); do
#	echo "0" > "$no_debug";
#done;

# CPU tuning
echo 2 > /sys/module/lpm_resources/enable_low_power/l2
echo 1 > /sys/module/lpm_resources/enable_low_power/pxo
echo 1 > /sys/module/lpm_resources/enable_low_power/vdd_dig
echo 1 > /sys/module/lpm_resources/enable_low_power/vdd_mem
echo 1 > /sys/module/msm_pm/modes/cpu0/power_collapse/suspend_enabled
echo 1 > /sys/module/msm_pm/modes/cpu1/power_collapse/suspend_enabled
echo 1 > /sys/module/msm_pm/modes/cpu2/power_collapse/suspend_enabled
echo 1 > /sys/module/msm_pm/modes/cpu3/power_collapse/suspend_enabled
echo 1 > /sys/module/msm_pm/modes/cpu0/power_collapse/idle_enabled
echo 0 > /sys/module/msm_pm/modes/cpu0/retention/idle_enabled
echo 0 > /sys/module/msm_pm/modes/cpu1/retention/idle_enabled
echo 0 > /sys/module/msm_pm/modes/cpu2/retention/idle_enabled
echo 0 > /sys/module/msm_pm/modes/cpu3/retention/idle_enabled
echo 0 > /sys/module/msm_thermal/core_control/enabled
echo 1 > /sys/devices/system/cpu/cpu1/online
echo 1 > /sys/devices/system/cpu/cpu2/online
echo 1 > /sys/devices/system/cpu/cpu3/online
echo "intelliactive" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
echo "intelliactive" > /sys/devices/system/cpu/cpu1/cpufreq/scaling_governor
echo "intelliactive" > /sys/devices/system/cpu/cpu2/cpufreq/scaling_governor
echo "intelliactive" > /sys/devices/system/cpu/cpu3/cpufreq/scaling_governor

# intelliactive Governor Settings
echo 30000 > /sys/devices/system/cpu/cpufreq/intelliactive/above_hispeed_delay
echo 1 > /sys/devices/system/cpu/cpufreq/intelliactive/boostpulse
echo 80000 > /sys/devices/system/cpu/cpufreq/intelliactive/boostpulse_duration
echo 90 > /sys/devices/system/cpu/cpufreq/intelliactive/go_hispeed_load
echo 1267200 > /sys/devices/system/cpu/cpufreq/intelliactive/hispeed_freq
echo 1 > /sys/devices/system/cpu/cpufreq/intelliactive/io_is_busy
echo 40000 > /sys/devices/system/cpu/cpufreq/intelliactive/min_sample_time
echo 60000 > /sys/devices/system/cpu/cpufreq/intelliactive/sampling_down_factor
echo 960000 > /sys/devices/system/cpu/cpufreq/intelliactive/sync_freq
echo 90 > /sys/devices/system/cpu/cpufreq/intelliactive/target_loads
echo 10000 > /sys/devices/system/cpu/cpufreq/intelliactive/timer_rate
echo 30000 > /sys/devices/system/cpu/cpufreq/intelliactive/timer_slack
echo 960000 > /sys/devices/system/cpu/cpufreq/intelliactive/up_threshold_any_cpu_freq
echo 65 > /sys/devices/system/cpu/cpufreq/intelliactive/up_threshold_any_cpu_load

# TCP Congestion
echo "westwood" > /proc/sys/net/ipv4/tcp_congestion_control

# set sync frequencies
#echo 960000 > /sys/devices/system/cpu/cpufreq/ondemand/optimal_freq
#echo 960000 > /sys/devices/system/cpu/cpufreq/ondemand/sync_freq
#echo 960000 > /sys/devices/system/cpu/cpufreq/ondemand/optimal_max_freq

# set minimum frequencies
echo 96000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq
echo 96000 > /sys/devices/system/cpu/cpu1/cpufreq/scaling_min_freq
echo 96000 > /sys/devices/system/cpu/cpu2/cpufreq/scaling_min_freq
echo 96000 > /sys/devices/system/cpu/cpu3/cpufreq/scaling_min_freq

# CPU Max Frequency
echo "2265600" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq
echo "2265600" > /sys/devices/system/cpu/cpu1/cpufreq/scaling_max_freq
echo "2265600" > /sys/devices/system/cpu/cpu2/cpufreq/scaling_max_freq
echo "2265600" > /sys/devices/system/cpu/cpu3/cpufreq/scaling_max_freq

# set grid steps for Ondemand
echo 7 > /sys/devices/system/cpu/cpufreq/ondemand/middle_grid_step
echo 40 > /sys/devices/system/cpu/cpufreq/ondemand/middle_grid_load
echo 14 > /sys/devices/system/cpu/cpufreq/ondemand/high_grid_step
echo 50 > /sys/devices/system/cpu/cpufreq/ondemand/high_grid_load

#echo 0 > /sys/module/msm_thermal/core_control/enabled
#echo 1 > /dev/cpuctl/apps/cpu.notify_on_migrate

# Tweak some VM settings for system smoothness
echo 40 > /proc/sys/vm/dirty_background_ratio
echo 60 > /proc/sys/vm/dirty_ratio

# set ondemand GPU governor as default
#echo ondemand > /sys/devices/fdb00000.qcom,kgsl-3d0/kgsl/kgsl-3d0/pwrscale/trustzone/governor

# set default readahead
echo 2048 > /sys/block/mmcblk0/bdi/read_ahead_kb

# GPU Max Frequency
echo "450000000" > /sys/devices/fdb00000.qcom,kgsl-3d0/kgsl/kgsl-3d0/max_gpuclk

# GPU Governor
echo "msm-adreno-tz" > /sys/devices/fdb00000.qcom,kgsl-3d0/devfreq/fdb00000.qcom,kgsl-3d0/governor

# make sure our max gpu clock is set via sysfs
#echo 450000000 > /sys/class/kgsl/kgsl-3d0/max_gpuclk

# Init.d support
if [ -d /system/etc/init.d ]; then
	chmod 755 /system/etc/init.d/*;
	run-parts /system/etc/init.d/;
fi;
