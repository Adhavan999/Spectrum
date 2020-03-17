#pragma once
#pragma message "Animation.h is included"

#include "Definitions.h"
#include "FastLED.h"
#include "SerialTransfer.h"

class Animation
{
private:
protected:
    static CRGB leds_[definitions::NUM_LEDS]; //using CRGB because CRGB can take CHSV values but not the other way around

public:
    Animation();
    virtual ~Animation();

    virtual void setParameters() = 0;
    virtual void onUpdate() = 0;
};
