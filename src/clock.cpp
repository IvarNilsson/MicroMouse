#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

const uint16_t SCREEN_WIDTH = 128;  // OLED display width, in pixels
const uint16_t SCREEN_HEIGHT = 64;  // OLED display height, in pixels

#define SHOCK_PIN 5

#define I2C_SDA 48
#define I2C_SCL 47

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

const uint8_t BASE_CHAR_WIDTH = 5;
const uint8_t BASE_CHAR_HEIGHT = 7;

const uint8_t CHAR_SIZE = 5;
const uint16_t CHAR_WIDTH = BASE_CHAR_WIDTH * CHAR_SIZE;
const uint16_t CHAR_HEIGHT = BASE_CHAR_HEIGHT * CHAR_SIZE;

const int16_t BORDER = 4;
const int16_t SPACE = 4;
const int16_t NEGATIVE_SPACE_BEFORE = 7;
const int16_t NEGATIVE_SPACE_AFTER = 6;

const int16_t CHAR_Y = (SCREEN_HEIGHT - CHAR_HEIGHT) / 2;
const int16_t CHAR1_X = BORDER;
const int16_t CHAR2_X = BORDER + CHAR_WIDTH + SPACE;
const int16_t CHAR3_X = BORDER + 2 * CHAR_WIDTH + SPACE - NEGATIVE_SPACE_BEFORE;
const int16_t CHAR4_X = BORDER + 3 * CHAR_WIDTH + SPACE -
                        NEGATIVE_SPACE_BEFORE - NEGATIVE_SPACE_AFTER;
const int16_t CHAR5_X = BORDER + 4 * CHAR_WIDTH + 2 * SPACE -
                        NEGATIVE_SPACE_BEFORE - NEGATIVE_SPACE_AFTER;

static const unsigned char PROGMEM test_bitmap[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(SHOCK_PIN, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  // display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Hello world!!");
  display.display();
  delay(1500);
  display.clearDisplay();
  Serial.println("START 0");

  // Serial.println(2 * BORDER + 5 * CHAR_WIDTH + 2 * SPACE -
  //                NEGATIVE_SPACE_BEFORE - NEGATIVE_SPACE_AFTER);
}

void loop() {
  // CLOCK:
  uint8_t shock_value = digitalRead(SHOCK_PIN);
  if (shock_value == 1) {
    display.drawChar(CHAR3_X, CHAR_Y, ':', 1, 0, CHAR_SIZE);
    display.drawChar(CHAR1_X, CHAR_Y, '2', 1, 0, CHAR_SIZE);
    display.drawChar(CHAR2_X, CHAR_Y, '3', 1, 0, CHAR_SIZE);
    display.drawChar(CHAR4_X, CHAR_Y, '5', 1, 0, CHAR_SIZE);
    display.drawChar(CHAR5_X, CHAR_Y, '9', 1, 0, CHAR_SIZE);
  }

  // BORDER:
  display.drawRoundRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 10, 1);

  // display.drawBitmap(0, 0, test_bitmap, 128, 4, 1);
  display.display();
  delay(200);
  display.clearDisplay();
}
