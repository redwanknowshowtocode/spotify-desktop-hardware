#include <TFT_eSPI.h>
TFT_eSPI tft;

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.drawString("Hello red", 20, 20, 4);
}

void loop() {
  uint16_t x, y;
  if (tft.getTouch(&x, &y)) {
    Serial.printf("touch %d,%d\n", x, y);
    tft.fillCircle(x, y, 3, TFT_GREEN);
  }
}