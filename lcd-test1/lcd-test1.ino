#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

#ifdef ADAFRUIT_HALLOWING
  #define TFT_CS        39 // Hallowing display control pins: chip select
  #define TFT_RST       37 // Display reset
  #define TFT_DC        38 // Display data/command select
  #define TFT_BACKLIGHT  7 // Display backlight pin
#else
  // For the breakout board, you can use any 2 or 3 pins.
  // These pins will also work for the 1.8" TFT shield.
  #define TFT_CS        10
  #define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         8
#endif


// For 1.44" and 1.8" TFT with ST7735 (including HalloWing) use:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // put your setup code here, to run once:

#ifdef ADAFRUIT_HALLOWING
  // HalloWing is a special case. It uses a ST7735R display just like the
  // breakout board, but the orientation and backlight control are different.
  tft.initR(INITR_HALLOWING);        // Initialize HalloWing-oriented screen
  pinMode(TFT_BACKLIGHT, OUTPUT);
  digitalWrite(TFT_BACKLIGHT, HIGH); // Backlight on
#else
  // Use this initializer if using a 1.8" TFT screen:
  tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab

  // OR use this initializer (uncomment) if using a 1.44" TFT:
  //tft.initR(INITR_144GREENTAB); // Init ST7735R chip, green tab
#endif

  // large block of text
  tft.fillScreen(ST7735_BLACK);

  
  testdrawtext("Hello LCD Test! ", ST7735_WHITE);
  delay(500);


  testdrawrects(ST7735_GREEN);
  delay(500);

  testdrawcircles(16, ST7735_BLUE);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void testdrawtext(char *text, uint16_t color) {
  tft.setCursor(10, 10);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}

void testdrawrects(uint16_t color) {
  tft.drawRect(10, 30, 20, 30, color);
}

void testdrawcircles(uint8_t radius, uint16_t color) {
  tft.drawCircle(60, 45, radius, color);
}
