#include "SetColor_Animation.h"

SetColor_Animation::SetColor_Animation(/* args */)
{
}

SetColor_Animation::~SetColor_Animation()
{
}

void SetColor_Animation::setParameters()
{
    /*read parameters of size 4 bytes and set (HSV can be converted to RGB but not the other way around)
                                            color_type_ = myTransfer.rxBuff[0]
                                            if(color_type_ == ColorType::HSV)
                                            {
                                                myTransfer.rxObj(hsv_new_color_, sizeof(new_color_), 1);
                                                parameters_.
                                            }
                                            elseif(color_type_ == ColorType::RGB)
                                            {
                                                myTransfer.rxObj(rgb_new_color_, sizeof(new_color_), 1);
                                            }
    */
}

void SetColor_Animation::onUpdate()
{
    parameters_.rgb_new_color_ =
#if (!IS_LED_MATRIX)
        for (int i = 0; i < NUM_LEDS; i++)
    {
        leds_[i] = ;
    }
#endif
}
