#pragma once
#include <FastLED.h>

class Animation
{

public:
    const uint8_t *raw_buffer_;
    uint8_t raw_buffer_size_ = 0;

    CRGB *leds_;
    const uint16_t leds_x_length_;
    const uint16_t leds_y_length_;

    virtual void OnInit() = 0;
    virtual void Update() = 0;
    virtual void OnInputUpdate() = 0;

    template <typename T>
    bool CopyObjectFromRawBuffer(T &val, uint8_t len, uint8_t index = 0)
    {
        if (index < (253 - len + 1))
        {
            uint8_t *ptr = (uint8_t *)&val;

            for (byte i = index; i < (len + index); i++)
            {
                *ptr = raw_buffer_[i];
                ptr++;
            }

            return true;
        }

        return false;
    }

    Animation(CRGB *first_led, uint16_t x_length, uint16_t y_length);

    virtual ~Animation()
    {
    }
};