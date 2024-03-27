#include <Arduino.h>
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 2
#define LED_BRIGHTNESS 64
#define DELAY_MS 500

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  
#define DATA_PIN 1

// Define the array of leds
CRGB leds[NUM_LEDS];

// Define an array of colors to cycle through
#define NUM_COLORS 4
CRGB colors[NUM_COLORS] = {CRGB::White, CRGB::Red, CRGB::Green, CRGB::Blue};

void setup() { 
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
    FastLED.setBrightness(LED_BRIGHTNESS);
}

void loop() { 
  for(int j=0; j<NUM_COLORS; j++) {
    for(int i=0; i<NUM_LEDS; i++) {
    // Turn the LED on, then pause
    leds[i] = colors[j];
    FastLED.show();
    delay(DELAY_MS);
    // Now turn the LED off, then pause
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(DELAY_MS);
    }
  }
}