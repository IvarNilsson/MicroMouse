BOLD=$(tput bold)
UNDERLINE=$(tput smul)
RESET=$(tput sgr0)

echo #new line
echo "${BOLD}--- Begin compile and flash ${UNDERLINE}$1${RESET}"
echo #new line

# remove old dir if cancled before rm last time
if [ -d "run" ]; then
    rm -r run/
    rmdir run
fi

# make temp dir for project to be run
mkdir run
mkdir run/$1

# add project file
cp src/$1.cpp run/$1
mv run/$1/$1.cpp run/$1/$1.ino

# add second file if exists
if ! [ -z "$2" ]; then
    cp src/$2.cpp run/$1
fi

arduino-cli compile --fqbn esp32:esp32:esp32 run/$1/$1.ino --build-property build.partitions=min_spiffs --build-property upload.maximum_size=1966080
arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 run/$1/$1.ino

#arduino-cli compile --fqbn esp32:esp32:esp32s3 run/$1/$1.ino --build-property build.partitions=min_spiffs --build-property upload.maximum_size=1966080
#arduino-cli upload -p /dev/ttyACM0 --fqbn esp32:esp32:esp32s3 run/$1/$1.ino

#rm -rf run/*
#rmdir run

echo #new line
echo "${BOLD}--- Done programing ${UNDERLINE}$1${RESET}"

echo #new line
echo "${BOLD}--- Starting Serial Monitor${RESET}"
echo "${BOLD}---------------------------${RESET}"
echo #new line
echo #new line

stty -F /dev/ttyUSB0 raw 115200
cat /dev/ttyUSB0
