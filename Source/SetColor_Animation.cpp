#include "SetColor_Animation.h"

void SetColor_Animation::OnInit()
{
    CopyObjectFromRawBuffer(NewColor, sizeof(NewColor), 1);
    Serial.write("Setting NewColor in Set_Color Animation to");
    Serial.write(NewColor.B);
    Serial.write(NewColor.G);
    Serial.write(NewColor.R);
    Serial.write('\n');
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
    Serial.write("<-..Updating SetColor Animation...->\n");
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
    Serial.write("Recieved RAW Message");
    CopyObjectFromRawBuffer(NewColor, sizeof(NewColor), 0);
}
