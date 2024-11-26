
void setup() {
  Serial.begin(115200);
  while (!Serial) {
    // Wait for the serial port to initialize
  }
  Serial.println("Hello, World! From ESP32-S3");
}

void loop() {
  Serial.println("Hello, World! IVAR :)");
  delay(1000);
}
