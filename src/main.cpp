#include "dev/evo_flatdie.h"
#include "sys/evo_system.h"
#include <Arduino.h>
#include <FastLED.h>

using namespace evolutic;

#define LED_PIN 21 // Pin connected to the data input of the LED strip
#define LED_COUNT 40
#define BRIGHTNESS 16 // Set brightness (0-255)
#define LED_TYPE WS2812
#define COLOR_ORDER GRB
#define BP 22 // Pin for the button

#pragma error

CRGB gs_pLed[LED_COUNT];
FlatDie gs_pDice[5];

void setup() {
  evolutic::init();

  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(gs_pLed, LED_COUNT);
  FastLED.setBrightness(BRIGHTNESS);

  for (int i = 0; i < 5; ++i) {
    gs_pDice[i].init(&gs_pLed[i * 8]);
    gs_pDice[i].setValue(i + 1);
    gs_pDice[i].updateLed();
  }

  FastLED.show();
}

void loop() { FastLED.show(); }
