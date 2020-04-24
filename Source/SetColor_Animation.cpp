#include "SetColor_Animation.h"

void SetColor_Animation::OnInit()
{
    CopyObjectFromRawBuffer(NewColor, sizeof(NewColor), 1);

    for (int i = 0; i < leds_y_length_ * leds_x_length_; i++)
    {
        leds_[i].b = NewColor.B;
        leds_[i].g = NewColor.G;
        leds_[i].r = NewColor.R;
    }
    FastLED.show();
}

void SetColor_Animation::Update()
{
    for (int i = 0; i < leds_y_length_ * leds_x_length_; i++)
    {
        leds_[i].b = NewColor.B;
        leds_[i].g = NewColor.G;
        leds_[i].r = NewColor.R;
    }
    FastLED.show();
}

void SetColor_Animation::OnInputUpdate()
{
    CopyObjectFromRawBuffer(NewColor, sizeof(NewColor), 0);
}
