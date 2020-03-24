#pragma once
#include "BufferReader.h"
#include "BufferHandler.h"
#include "Configuration.h"

namespace spectrum
{
class Core
{
private:
    static BufferHandler *buffer_handler_;
    static BufferReader *buffer_reader_;

public:
    Configuration *configuration_;

    Core();
    ~Core();

    void onInit();
    void onUpdate();

    static Core &instance();
};
} // namespace spectrum