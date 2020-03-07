#pragma once
#pragma message "Definitions.h is included"

namespace definitions
{
enum Animations
{
    VIZ_SCROLL,
    VIZ_BREATH,
    TWINKLE,
    BLINK
};

extern Animations DEFAULT_ANIMATION;

extern const int LED_PIN;
constexpr int NUM_LEDS = 100;
extern const char MAX_BRIGHTNESS; //LEDs should never go beyond this. Ranges from 0-255

#define IS_LED_MATRIX 0 // 0 translates to false, change to 1 if using an array or multiple strips of LEDs

#if (IS_LED_MATRIX)
constexpr int NUM_LEDS_COL = 0;
constexpr int NUM_LEDS_ROW = 0;
#endif

#define LED_TYPE WS2812B

} //namespace definitions
