#pragma once
#pragma message "Twinkle_Animation is included"

#include "Animation.h"
#include "Definitions.h"

class Twinkle_Animation : public Animation
{
private:
    struct Parameters
    {
        int PA, PB, PC;
    } parameters_ = {5, 6, 7};

public:
    Twinkle_Animation();
    ~Twinkle_Animation() final;

    void setParameters() final;
    void onUpdate() final;
};
