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
    {EffectManager::EFFECT_SOLID_MAGENTA, 0, 1, 0},
    {EffectManager::EFFECT_SOLID_GREEN, 0, 1, 0},
    {EffectManager::EFFECT_SOLID_RED, 0, 1, 0},
    {EffectManager::EFFECT_TEST, 0, 0, 1},
    /*{EffectManager::EFFECT_THEATRE_CHASE_RED_SLOW, 0, 5, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_GREEN_SLOW, 0, 5, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_BLUE_SLOW, 0, 5, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_CYAN_SLOW, 0, 5, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_MAGENTA_SLOW, 0, 5, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_YELLOW_SLOW, 0, 5, 0},

    {EffectManager::EFFECT_THEATRE_CHASE_RAINBOW_FILL_SLOW, 0, 10, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_RAINBOW_FADE_SLOW, 0, 10, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_RAINBOW_EVEN_SLOW, 0, 10, 0},

    {EffectManager::EFFECT_RAINBOW_EVEN_FAST, 0, 30, 0},

    {EffectManager::EFFECT_THEATRE_CHASE_RED_FAST, 0, 5, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_GREEN_FAST, 0, 5, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_BLUE_FAST, 0, 5, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_CYAN_FAST, 0, 5, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_MAGENTA_FAST, 0, 5, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_YELLOW_FAST, 0, 5, 0},

    {EffectManager::EFFECT_THEATRE_CHASE_RAINBOW_FILL_FAST, 0, 10, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_RAINBOW_FADE_FAST, 0, 10, 0},
    {EffectManager::EFFECT_THEATRE_CHASE_RAINBOW_EVEN_FAST, 0, 10, 0},

    {EffectManager::EFFECT_RAINBOW_EVEN_FAST, 0, 30, 0},*/
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

    delay(LOOP_DELAY);
}
