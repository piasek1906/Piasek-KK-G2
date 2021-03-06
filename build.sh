#!/bin/bash
build=/home/piasek/android/LG_G2
kernel="Piasek-KK"
version="0.5.1"
rom="LG"
ramdisk=ramdisk
toolchain=/home/piasek/android/toolchain/bin
toolchain2="arm-LG-linux-gnueabi-"
kerneltype="zImage"
jobcount="-j4"
base=0x00000000
pagesize=2048
ramdisk_offset=0x05000000
tags_offset=0x04800000
cmdline="console=ttyHSL0,115200,n8 androidboot.hardware=g2 user_debug=31 msm_rtb.filter=0x0 mdss_mdp.panel=1:dsi:0:qcom,mdss_dsi_g2_lgd_cmd"

			export ARCH=arm
			export CCOMPILE=$CROSS_COMPILE
			export CROSS_COMPILE=arm-LG-linux-gnueabi- 
			export PATH=$PATH:/home/piasek/android/toolchain/bin

echo " Piasek Kernel Install: "
echo "__________ __                     __     "
echo "\______   \__|____    _____ ____ |  | __ "
echo " |     ___/  \__  \  / ___// __ \|  |/ / "
echo " |    |   |  |/ __ \_\___\ \ ___/|    <  "
echo " |____|   |__(____  /____  >\___ >__|_ \ "
echo "                  \/     \/     \/    \/ "
echo "D802 Variant"

		variant="d802"
		config="d802_piasek_defconfig"
		ramdisk=ramdisk/d802.lz4
		
# Begin commands
rm -rf out
mkdir out
mkdir out/tmp
echo "Checking for build..."
if [ -f ozip/boot.img ]; then
	read -p "Previous build found, clean working directory..(y/n)? : " cchoice
	case "$cchoice" in
		y|Y )
			export ARCH=arm
			export CCOMPILE=$CROSS_COMPILE
			export CROSS_COMPILE=arm-LG-linux-gnueabi- 
			export PATH=$PATH:/home/piasek/android/toolchain/bin
			rm -rf ozip/{system,boot.img}
			rm -rf arch/arm/boot/"$kerneltype"
			mkdir -p ozip/system/lib/modules
			make clean && make mrproper
			echo "Working directory cleaned...";;
		n|N )
			exit 0;;
		* )
			echo "Invalid...";;
	esac
	read -p "Begin build now..(y/n)? : " dchoice
	case "$dchoice" in
		y|Y)
			make "$config"
			make "$jobcount"
			exit 0;;
		n|N )
			exit 0;;
		* )
			echo "Invalid...";;
	esac
fi
if [ -f arch/arm/boot/"$kerneltype" ]; then
	cp arch/arm/boot/"$kerneltype" out
	rm -rf ozip/system
	mkdir -p ozip/system/lib/modules
	find . -name "*.ko" -exec cp {} ozip/system/lib/modules \;
else
	echo "Nothing has been made..."
	read -p "Clean working directory..(y/n)? : " achoice
	case "$achoice" in
		y|Y )
			export ARCH=arm
			export CROSS_COMPILE=$toolchain/"$toolchain2"
			rm -rf ozip/{system,boot.img}
			rm -rf arch/arm/boot/"$kerneltype"
			mkdir -p ozip/system/lib/modules
			make clean && make mrproper
			echo "Working directory cleaned...";;
		n|N )
			exit 0;;
		* )
			echo "Invalid...";;
	esac
	read -p "Begin build now..(y/n)? : " bchoice
	case "$bchoice" in
		y|Y)
			make "$config"
			make "$jobcount"
			exit 0;;
		n|N )
			exit 0;;
		* )
			echo "Invalid...";;
	esac
fi

if [ -f $ramdisk ]; then
	echo "Using prebuilt ramdisk..."
else
	echo "No ramdisk found..."
	exit 0;
fi

echo "Making DT.img..."
if [ -f arch/arm/boot/$kerneltype ]; then
	dtbTool -s 2048 -o out/dt.img arch/arm/boot/
else
	echo "No build found..."
	exit 0;
fi	

echo "Making boot.img..."
if [ -f arch/arm/boot/"$kerneltype" ]; then
	mkbootimg_dtb --kernel out/"$kerneltype" --ramdisk $ramdisk --cmdline "$cmdline" --base $base --pagesize $pagesize --ramdisk_offset $ramdisk_offset --tags_offset $tags_offset --dt out/dt.img -o ozip/boot.img
else
	echo "No build found..."
	exit 0;
fi

echo "Zipping..."
cd ozip
zip -r ../"$kernel"-$version-"$rom"_"$variant".zip .
mv ../"$kernel"-$version-"$rom"_"$variant".zip $build
cd ..
rm -rf out
echo "Done..."
