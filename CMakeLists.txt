# Set the path to your Arduino toolchain file
set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)

# Minimum CMake version required
cmake_minimum_required(VERSION 3.13)

# Project name and supported languages
project(MicroMouse C CXX)

# Set the default board and port
set(ARDUINO_DEFAULT_BOARD esp32dev)  # Change to your specific board
set(ARDUINO_DEFAULT_PORT /dev/ttyUSB0)  # Change to your specific port

# Specify the source files
set(SOURCES
    src/blink.cpp
    # Add other source files here...
)

# Generate the Arduino firmware
generate_arduino_firmware(MicroMouse SRCS ${SOURCES})
