#include "Core.h"
using namespace spectrum;

void setup()
{
    Core::instance().onInit();
}

void loop()
{
    Core::instance().onUpdate();
}
