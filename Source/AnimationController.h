#pragma once
#include "Core.h"
#include "Component.h"
#include "Animation.h"

namespace spectrum
{
class AnimationController : public Component
{
private:
    enum class State
    {
        ANIMATE,
        CHANGE_ANIMATION,
        DO_NOTHING
    };
    static State current_state_;
    static Animation *current_animation_;
    friend void Animation::delayAnimation(unsigned long, AnimationController &);

public:
    AnimationController();
    ~AnimationController() override;

    void onUpdate() override;

    void changeAnimation();
};

void Animation::delayAnimation(unsigned long m_delay, AnimationController &m_current_controller)
{
    m_current_controller.current_state_ = AnimationController::State::DO_NOTHING;
    uint32_t start = millis();

    while (start + m_delay > millis())
    {
        Core::instance().onUpdate();
    }
    m_current_controller.current_state_ = AnimationController::State::ANIMATE;
}

} // namespace spectrum