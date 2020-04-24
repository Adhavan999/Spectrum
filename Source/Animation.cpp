#include "Animation.h"

Animation::Animation(CRGB *first_led, uint16_t x_length, uint16_t y_length)
    : leds_(first_led), leds_x_length_(x_length), leds_y_length_(y_length)
{
}