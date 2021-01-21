//Include needed Libraries at beginning
#include <Arduino.h>
#include <FastLED.h> // FastLED library for WS2812 RGB Stick http://fastled.io/
#include "src/LedUtilities/LedUtilities.h"


// Interrupts on 2, 3
// PWM on 3, 5, 6, 9, 10, 11
#define LED_PIN         2
#define BRIGHTNESS      255
#define HUE_MAX			255
#define NUM_LEDS        72
#define LOOP_DELAY      1

CRGBArray<NUM_LEDS> leds;
Strip strip(&leds, false, true, true);
EffectManager effect_manager(&strip);
ScriptManager script_manager(&strip);

ScriptElement script[] = {
	{WIPE, (5 * Timer::ONE_SECOND), false},
	{CONFETTI, (5 * Timer::ONE_SECOND), false},
	{FADE, (5 * Timer::ONE_SECOND), false},
	{FIRE, (5 * Timer::ONE_SECOND), false},
};

uint8_t length = sizeof(script) / sizeof(script[0]);

void setup(void)
{
    pinMode(LED_PIN, OUTPUT);

    FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, leds.size());

    FastLED.setBrightness(BRIGHTNESS);

    script_manager.loadScript(script, length);
    Serial.begin(115200);
}

void loop(void)
{
    script_manager.runScript();

    FastLED.show();
}
