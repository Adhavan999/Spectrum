#pragma once

#include "Definitions.h"
#include "Animation.h"

class SetColor_Animation : public Animation
{
private:
    struct Parameters
    {
        enum ColorType
        {
            RGB,
            HSV
        } color_type_;
        union {
            CRGB rgb_new_color_;
        };

    } parameters_;

public:
    SetColor_Animation();
    ~SetColor_Animation() final;

    void setParameters() final;
    void onUpdate() final;
};
