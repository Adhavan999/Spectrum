#pragma once
#include "Animation.h"

class SetColor_Animation : public Animation
{
public:
    struct NewColor
    {
        uint8_t R, G, B;
    } NewColor;

    SetColor_Animation(CRGB *first_led, uint16_t x_length, uint16_t y_length) : Animation(first_led, x_length, y_length)
    {
        NewColor.B = 0;
        NewColor.G = 0;
        NewColor.R = 255;
    }

    void OnInputUpdate() override;
    void OnInit() override;
    void Update() override;

private:
};