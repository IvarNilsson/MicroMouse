BOLD=$(tput bold)
UNDERLINE=$(tput smul)
RESET=$(tput sgr0)

echo #new line
echo "${BOLD}--- Begin compile and flash ${UNDERLINE}$1${RESET}"
echo #new line

# remove old dir
if [ -d "run" ]; then
    rm -r run
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

BOARD="esp32:esp32:esp32"
#BOARD="esp32:esp32:esp32s3:CDCOnBoot=cdc"
PORT="/dev/ttyUSB0" 
#PORT="/dev/ttyACM0" 

arduino-cli compile --fqbn $BOARD run/$1/$1.ino
arduino-cli upload -p $PORT --fqbn $BOARD run/$1/$1.ino

#rm -rf run/*
#rmdir run
echo #new line
echo "${BOLD}--- Done programing ${UNDERLINE}$1${RESET}"

echo #new line
echo "${BOLD}--- Starting Serial Monitor ---${RESET}"
echo "${BOLD}-------------------------------${RESET}"
echo #new line
echo #new line

# open serial monitor (use --log-level for more info about boot sequence)
arduino-cli monitor -p $PORT trace -c 115200
