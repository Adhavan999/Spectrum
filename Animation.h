#pragma once
#pragma message "Animation.h is included"

#include "Definitions.h"
#include "FastLED.h"

class Animation
{
private:
protected:
    static CHSV leds_[definitions::NUM_LEDS];

public:
    Animation();
    virtual ~Animation();

    virtual void SetParameters() = 0;
    virtual void OnUpdate() = 0;
};
