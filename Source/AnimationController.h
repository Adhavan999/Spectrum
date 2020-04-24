#pragma once
#include "animations.h"
#include "defs.h"
#include <EEPROM.h>

class AnimationController
{
public:
    const uint16_t leds_x_length_ = NUM_X_LEDS;
    const uint16_t leds_y_length_ = NUM_Y_LEDS;
    CRGB leds_[NUM_Y_LEDS * NUM_X_LEDS];

    Animation *current_animation_ = nullptr;

    AnimationController();
    ~AnimationController();

    Buffer ReadLastBufferFromMemory();
    void HandleMessage(Buffer buffer);
    bool SetCurrentAnimation(Buffer buffer);

    void Update();
};

static bool Set_Rx_Buffer(uint8_t *start_of_Rx_buffer)
{
    for (int i = 0; i < 254; i++)
    {
        start_of_Rx_buffer[i] = EEPROM.read(i);
    }
    if ((MessageType)start_of_Rx_buffer[0] == MessageType::NEW_ANIMATION)
    {
        return true;
    }
    else
    {
        return false;
    }
}
static void Set_EEPROM_Buffer(uint8_t *start_of_Rx_buffer)
{
    for (int i = 0; i < 254; i++)
    {
        EEPROM.write(i, start_of_Rx_buffer[i]);
    }
}