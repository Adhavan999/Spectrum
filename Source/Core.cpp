#include "Core.h"

namespace spectrum
{

Core::Core()
{
}

void Core::onInit()
{
    delete configuration_, buffer_handler_, buffer_reader_;
    configuration_ = new Configuration();
    buffer_reader_ = new BufferReader();   //Reads incoming packet from stream and updates buffer_
    buffer_handler_ = new BufferHandler(); //Handles the buffer message and performs animations using it's AnimationController
}

void Core::onUpdate()
{
    buffer_reader_->onUpdate();
    buffer_handler_->onUpdate();
}

Core &Core::instance()
{
    // Forgive me for this heinous crime.
    static Core *instance_ = new Core();
    return *instance_;
}
} // namespace spectrum