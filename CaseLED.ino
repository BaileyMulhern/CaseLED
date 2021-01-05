//Include needed Libraries at beginning
#include <Arduino.h>
#include <FastLED.h> // FastLED library for WS2812 RGB Stick http://fastled.io/
#include "src/LedUtilities/ScriptManager.h"


// Interrupts on 2, 3
// PWM on 3, 5, 6, 9, 10, 11
#define LED_PIN         2
#define BRIGHTNESS      255
#define NUM_LEDS        72
#define LOOP_DELAY      1

CRGB leds[NUM_LEDS];

ScriptManager::ScriptElement script[] = {
    {EffectManager::THEATRE_CHASE, CRGB::Red, EffectManager::SLOW, 0, 5, 0},
    {EffectManager::THEATRE_CHASE, CRGB::Green, EffectManager::SLOW, 0, 5, 0},
    {EffectManager::THEATRE_CHASE, CRGB::Blue, EffectManager::SLOW, 0, 5, 0},
    {EffectManager::THEATRE_CHASE, CRGB::Cyan, EffectManager::SLOW, 0, 5, 0},
    {EffectManager::THEATRE_CHASE, CRGB::Magenta, EffectManager::SLOW, 0, 5, 0},
    {EffectManager::THEATRE_CHASE, CRGB::Yellow, EffectManager::SLOW, 0, 5, 0},

    {EffectManager::RAINBOW_FADE, CRGB::Red, EffectManager::SLOW, 0, 30, 0},

    {EffectManager::THEATRE_CHASE, CRGB::Red, EffectManager::FAST, 0, 5, 0},
    {EffectManager::THEATRE_CHASE, CRGB::Green, EffectManager::FAST, 0, 5, 0},
    {EffectManager::THEATRE_CHASE, CRGB::Blue, EffectManager::FAST, 0, 5, 0},
    {EffectManager::THEATRE_CHASE, CRGB::Cyan, EffectManager::FAST, 0, 5, 0},
    {EffectManager::THEATRE_CHASE, CRGB::Magenta, EffectManager::FAST, 0, 5, 0},
    {EffectManager::THEATRE_CHASE, CRGB::Yellow, EffectManager::FAST, 0, 5, 0},

    {EffectManager::RAINBOW_EVEN, CRGB::Red, EffectManager::FAST, 0, 30, 0},
};

ScriptManager scriptManager(leds, NUM_LEDS);

uint8_t length = sizeof(script) / sizeof(script[0]);

void setup(void)
{
    pinMode(LED_PIN, OUTPUT);

    FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);

    FastLED.setBrightness(BRIGHTNESS);

    scriptManager.loadScript(script, length);
    
    Serial.begin(115200);
    Serial.println(length);
}

void loop(void)
{
    scriptManager.runScript();

    FastLED.show();
}
