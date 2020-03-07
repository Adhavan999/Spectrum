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
    } m_parameters_ = {5, 6, 7};

public:
    void SetParameters() final;
    void OnUpdate() final;
    Twinkle_Animation();
    ~Twinkle_Animation() final;
};
