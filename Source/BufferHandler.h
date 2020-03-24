#pragma once

#include "Component.h"
#include "AnimationController.h"

namespace spectrum
{
class BufferHandler : public Component
{
private:
    AnimationController animation_controller_;

public:
    BufferHandler();
    ~BufferHandler() override;

    void onUpdate() override;
};
} // namespace spectrum