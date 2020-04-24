
#include "SerialTransfer.h"
#include "AnimationController.h"

Buffer input_buffer;
SerialTransfer buffer_reader;
AnimationController *animation_controller;

void UpdateInputBuffer();

bool CLEAR_BUFFER = false;

void setup()
{
    Serial.begin(115200);
    buffer_reader.begin(Serial);
    animation_controller = new AnimationController();
    // input_buffer.buffer = &buffer_reader.rxBuff[1];

    // if (Set_Rx_Buffer(&buffer_reader.rxBuff[0]))
    // {
    //     Serial.write("Setting Default..\n");
    //     UpdateInputBuffer();
    //     animation_controller->HandleMessage(input_buffer);
    //     if (CLEAR_BUFFER)
    //     {
    //         memset(buffer_reader.rxBuff, 0, 254);
    //         CLEAR_BUFFER = false;
    //     }
    // }
    // else
    // {
    //     Serial.write("Couldn't get Default\n");
    // }
}

void loop()
{
    // if (buffer_reader.available())
    // {
    //     Serial.write("Reading Packet...");
    //     UpdateInputBuffer();
    //     animation_controller->HandleMessage(input_buffer);
    //     if (CLEAR_BUFFER)
    //     {
    //         memset(buffer_reader.rxBuff, 0, 254);
    //         CLEAR_BUFFER = false;
    //     }
    // }
    animation_controller->Update();
}

void UpdateInputBuffer()
{
    input_buffer.message_type = (MessageType)buffer_reader.rxBuff[0];
    input_buffer.buffer_length = buffer_reader.bytesRead - 1;
}