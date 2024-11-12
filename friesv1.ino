#include <Adafruit_NeoPixel.h>

#define PIN 6  // Pin connected to the data input of the LED strip
#define NUMPIXELS 300  // Total number of pixels (replace this with the actual number of LEDs)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Define the LED ranges for each word
// Replace light_min and light_max with actual values
int WE_min = 130;  // First LED for "WE"
int WE_max = 185;  // Last LED for "WE"

int WANT_min = 60;  // First LED for "WANT"
int WANT_max = 127;  // Last LED for "WANT"

int FRIES_min = 1;  // First LED for "FRIES"
int FRIES_max = 57;  // Last LED for "FRIES"

int fryColor_min = 190; // First LED for fry light
int fryColor_max = 300; // Last LED for fry light

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

    // Set the last group (200-300) to yellow at 25% brightness
  setYellowStaticLEDs();
}

void loop() {
  // Loop through "WE", "WANT", and "FRIES" three times
  for (int i = 0; i < 3; i++) {
    lightUpWord(WE_min, WE_max, strip.Color(255, 0, 0), 1000);  // Red for "WE"
    delay(500);
    lightUpWord(WANT_min, WANT_max, strip.Color(255, 0, 0), 1000);  // Red for "WANT"
    delay(500);
    lightUpWord(FRIES_min, FRIES_max, strip.Color(255, 0, 0), 1000);  // Red for "FRIES"
    delay(500);
  }
  
  // Light up all words 3 times for 2 seconds each
  for (int i = 0; i < 3; i++) {
    lightUpAllWords();
    delay(2000);  // Leave all words lit for 2 seconds
    strip.clear();  // Turn off all lights
    strip.show();
    delay(500);  // Small delay between each full light-up
  }
}

// Function to light up a word based on LED range
void lightUpWord(int start, int end, uint32_t color, int delayTime) {
  for (int i = start; i <= end; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
  delay(delayTime);
  strip.clear();  // Turn off the word after displaying
  strip.show();
}

// Function to light up all the words
void lightUpAllWords() {
  // Light up "WE"
  for (int i = WE_min; i <= WE_max; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));  // Red for "WE"
  }
  
  // Light up "WANT"
  for (int i = WANT_min; i <= WANT_max; i++) {
    strip.setPixelColor(i, strip.Color(255, 255, 255));  // White for "WANT"
  }
  
  // Light up "FRIES"
  for (int i = FRIES_min; i <= FRIES_max; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));  // Red for "FRIES"
  }
  
  strip.show();
}

void setYellowStaticLEDs() {
  // Set LEDs from 200-300 to yellow at 25% brightness
  uint32_t yellow = strip.Color(255 / 4, 255 / 4, 0); // 25% brightness yellow
  for (int i = fryColor_min; i < fryColor_max; i++) {
    strip.setPixelColor(i, yellow);
  }
  strip.show();
}
