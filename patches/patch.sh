echo $1
rootdirectory="$PWD"
# ---------------------------------

dirs="hardware/interfaces system/sepolicy"
#dirs=""

for dir in $dirs ; do
	cd $rootdirectory
	cd $dir
	echo "Applying $dir patches..."
	git apply $rootdirectory/device/htc/htc_v36bml_dugl/patches/$dir/*.patch
	echo " "
done

# -----------------------------------
echo "Changing to build directory..."
cd $rootdirectory
