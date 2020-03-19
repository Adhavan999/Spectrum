#include "Blink_Animation.h"

void Blink_Animation::setParameters()
{
    parameters_ = {1, 2, 3};
}

void Blink_Animation::onUpdate()
{
    if (parameters_.PA == 1)
    {
    }
}

Blink_Animation::Blink_Animation()
{
}

Blink_Animation::~Blink_Animation()
{
}
