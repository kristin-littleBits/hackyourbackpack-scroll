/***
  * Hack Your Backpack
  * Example Code - Scrolling Text
  * Based on Adafruit_NeoMatrix example "matrixtest"
  * Modified by Kristin Salomon (kristin.salomon@littlebits.cc)
  * Last updated: September 9, 2015
  ***/

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>


#define MATRIX_PIN    1
#define MATRIX_WIDTH  8
#define MATRIX_HEIGHT 8

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);
  

const uint16_t colors[] = {
  matrix.Color(200, 100, 220), // purple
  matrix.Color(0, 0, 255), // blue
  matrix.Color(0, 255, 0), // green
  matrix.Color(255, 140, 0), // orange
  matrix.Color(224, 17, 95) // pink
 };

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(30);
  matrix.setTextColor(colors[0]);
}

int x = matrix.width();
int pass = 0;
int numColors = sizeof(colors)/sizeof(uint16_t);

void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(F("#HackYourBackpack"));
  if(--x < -100) {
    x = matrix.width();
    if(++pass >= numColors) pass = 0;
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  delay(100);
}
