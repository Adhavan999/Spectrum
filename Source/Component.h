#pragma once

namespace spectrum
{
class Component
{
private:
protected:
    enum class BufferType : byte
    {
        CHANGE_ANIMATION,   //Indicates a command to change the current animation. Remaining buffer is used to indicate which Animation and parameters of it.
        ANIMAION_BUFFER,    //Indicating the rest of the buffer is raw data meant to be used by the animation. Ex: Audio visualization, etc.
        GET_CURRENT_STATUS, //Send back Version number, config details and current Animation playing
        PERFORM_COMMAND     //To perform a Arduino command. Ex: Powering off, Reseting config, etc.
    };

    struct Buffer
    {
        BufferType message_state_; //The state of message recieved
        uint8_t message_size_;     //Size of the buffer - sizeof(BufferType). The size of the buffer minus the message_state_ byte.

        union {
            uint8_t raw_[255]; //Actual buffer. Buffer is static array.
        };
    };
    static Buffer buffer_;

public:
    Component();
    virtual ~Component();

    virtual void onUpdate() = 0;
};
} // namespace spectrum