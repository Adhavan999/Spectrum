#include "AnimationController.h"

extern bool CLEAR_BUFFER;

AnimationController::AnimationController()
{
    FastLED.addLeds<LED_TYPE, DATA_PIN, RGB>(leds_, leds_x_length_ * leds_y_length_);
}

AnimationController::~AnimationController()
{
    delete current_animation_;
    delete leds_;
}

void AnimationController::HandleMessage(Buffer buffer)
{
    //TODO: Implement error handling
    switch (buffer.message_type)
    {
    case MessageType::RAW:
    {

        current_animation_->raw_buffer_size_ = buffer.buffer_length;
        current_animation_->OnInputUpdate();
    }
    break;

    case MessageType::NEW_ANIMATION:
    {
        Set_EEPROM_Buffer(buffer.buffer - 1);
        SetCurrentAnimation(buffer);
    }
    break;

    default:
    {
        Serial.write("MessageType not recognizable.\n");
    }
    break;
    }
}

bool AnimationController::SetCurrentAnimation(Buffer buffer)
{
    switch ((AnimationName)buffer.buffer[0])
    {
    case AnimationName::SET_COLOR:
    {
        delete current_animation_;
        current_animation_ = new SetColor_Animation(leds_, leds_x_length_, leds_y_length_);
        Serial.write("Creating new SET_COLOR animation.\n");
    }
    break;

    default:
    {
        //TODO: Implement some sort of error message send back
        return false;
    }
    break;
    }

    current_animation_->raw_buffer_ = &(buffer.buffer[0]);
    current_animation_->raw_buffer_size_ = 0;
    current_animation_->OnInit();
    CLEAR_BUFFER = true;
    return true;
}

void AnimationController::Update()
{
    // if (current_animation_ != nullptr)
    // {
    //     current_animation_->Update();
    // }
    for (int i = 0; i < leds_x_length_ * leds_y_length_; i++)
    {
        leds_[i] = CRGB::BlueViolet;
    }
    FastLED.show();
}