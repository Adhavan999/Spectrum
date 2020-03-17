#pragma once
#pragma message "Definitions.h is included"

namespace definitions
{
enum Animations
{
    TWINKLE,
    BLINK,
    SET_COLOR
};

extern Animations DEFAULT_ANIMATION;

extern const int LED_PIN;
extern const char MAX_BRIGHTNESS; //LEDs should never go beyond this. Ranges from 0-255

#define IS_LED_MATRIX 0 // 0 translates to false, change to 1 if using an array or multiple strips of LEDs

#if (IS_LED_MATRIX)
constexpr int NUM_LEDS_COL = 0;
constexpr int NUM_LEDS_ROW = 0;
#endif

#if (!IS_LED_MATRIX)
constexpr int NUM_LEDS = 100;
#endif

#define LED_TYPE WS2812B

} //namespace definitions
