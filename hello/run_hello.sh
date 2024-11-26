#!/bin/bash

# Set the board type and port
BOARD="esp32:esp32:esp32s3:CDCOnBoot=cdc,UploadMode=cdc,UploadSpeed=115200"
PORT="/dev/ttyACM0" # Change to the correct port for your ESP32-S3
SKETCH="hello.ino"

# Compile the sketch
arduino-cli compile --fqbn $BOARD $SKETCH
if [ $? -ne 0 ]; then
  echo "Compilation failed!"
  exit 1
fi

# Upload the sketch
arduino-cli upload -v -p $PORT --fqbn $BOARD $SKETCH
if [ $? -eq 0 ]; then
  echo "Upload successful!"
else
  echo "Upload failed!"
  exit 1
fi

# Open the serial monitor
echo "Opening serial monitor at 115200 baud..."
arduino-cli monitor -p $PORT trace -c 115200
