#!/bin/bash

PROJECT_DIR=$(git rev-parse --show-toplevel)
COMPILE_COMMANDS_FILE="$PROJECT_DIR/compile_commands.json"
SRC_FILE="$PROJECT_DIR/src/blink.cpp"

INCLUDE_DIRS=(
    "$HOME/.arduino15/packages/esp32/hardware/esp32/3.0.5/cores/esp32/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/freertos/FreeRTOS-Kernel/include"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/freertos/esp_additions/include/freertos"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/qio_qspi/include"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/freertos/esp_additions/arch/xtensa/include"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/freertos/FreeRTOS-Kernel/portable/xtensa/include"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/xtensa/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/xtensa/esp32/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/newlib/platform_include/"
    "$HOME/.arduino15/packages/esp32/tools/esp-x32/2302/xtensa-esp32-elf/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/esp_hw_support/include"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/soc/esp32/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/esp_common/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/esp_system/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/heap/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/esp_rom/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/hal/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/esp_timer/include"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/log/include"
    "$HOME/.arduino15/packages/esp32/hardware/esp32/3.0.5/variants/esp32"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/driver/gpio/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/driver/gptimer/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp-x32/2302/xtensa-esp32-elf/include/c++/12.2.0"
    "$HOME/.arduino15/packages/esp32/tools/esp-x32/2302/xtensa-esp32-elf/include/c++/12.2.0/xtensa-esp32-elf/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/lwip/lwip/src/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/lwip/port/include"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/freertos/esp_additions/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/lwip/port/freertos/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/lwip/port/esp32xx/include/"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/esp_netif/include"
    "$HOME/.arduino15/packages/esp32/tools/esp32-arduino-libs/idf-release_v5.1-33fbade6/esp32/include/esp_partition/include"
)

INCLUDE_FLAGS=""
for dir in "${INCLUDE_DIRS[@]}"; do
  INCLUDE_FLAGS+=" -I$dir"
done

INCLUDE_FLAGS+=" -D__GLIBC_USE=1"

rm -f "$COMPILE_COMMANDS_FILE"

cat <<EOL > "$COMPILE_COMMANDS_FILE"
[
  {
    "directory": "$PROJECT_DIR",
    "command": "g++ $INCLUDE_FLAGS -c $SRC_FILE -o blink.o",
    "file": "$SRC_FILE"
  }
]
EOL
