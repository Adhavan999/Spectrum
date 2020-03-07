#include "Blink_Animation.h"

void Blink_Animation::SetParameters()
{
    m_parameters_ = {1, 2, 3};
}

void Blink_Animation::OnUpdate()
{
    if (m_parameters_.PA == 1)
    {
    }
}

Blink_Animation::Blink_Animation()
{
}

Blink_Animation::~Blink_Animation()
{
}
