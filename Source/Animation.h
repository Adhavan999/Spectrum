#pragma once
namespace spectrum
{
class AnimationController;
class Animation
{
private:
    Animation();

public:
    virtual ~Animation();

    void delayAnimation(unsigned long delay, AnimationController &current_controller);
};

} // namespace spectrum