#include "SetColor_Animation.h"

SetColor_Animation::SetColor_Animation()
{
}

SetColor_Animation::~SetColor_Animation()
{
}

void SetColor_Animation::setParameters()
{
    /*something like this: read parameters of size 4 bytes and set (HSV can be converted to RGB but not the other way around)
                                            color_type_ = myTransfer.rxBuff[0]
                                            if(color_type_ == ColorType::HSV)
                                            {
                                                rgb_new_color_.setHSV(myTransfer.rxBuff[1], myTransfer.rxBuff[2], myTransfer.rxBuff[3])
                                            }
                                            elseif(color_type_ == ColorType::RGB)
                                            {
                                                rgb_new_color_.setRGB(myTransfer.rxBuff[1], myTransfer.rxBuff[2], myTransfer.rxBuff[3])
                                            }
    */
}

void SetColor_Animation::onUpdate()
{
#if (!IS_LED_MATRIX)
    for (int i = 0; i < definitions::NUM_LEDS; i++)
    {
        leds_[i] = parameters_.rgb_new_color_;
    }
#endif
}