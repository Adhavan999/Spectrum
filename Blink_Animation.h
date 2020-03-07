#pragma once
#pragma message "Blink_Animation is included"

#include "Animation.h"

class Blink_Animation : public Animation
{
private:
    struct Parameters
    {
        int PA, PB, PC;
    } m_parameters_ = {5, 6, 7};

public:
    Blink_Animation();
    ~Blink_Animation() final;

    void OnUpdate() final;
    void SetParameters() final;
};