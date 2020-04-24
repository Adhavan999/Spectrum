#pragma once

#include "SetColor_Animation.h"

enum class AnimationName : uint8_t
{
    SET_COLOR = 0
};

#define LED_TYPE WS2812B
#define DATA_PIN 3
#define NUM_X_LEDS 5
#define NUM_Y_LEDS 1