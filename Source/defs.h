#pragma once

enum class MessageType : uint8_t
{
    RAW = 0,
    NEW_ANIMATION = 1
};

struct Buffer
{
    MessageType message_type;
    uint8_t buffer_length;
    uint8_t *buffer;
};
