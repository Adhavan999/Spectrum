#include "Definitions.h"
#include "Animation_Controller.h"

Animation_Controller animation_controller;

void setup()
{
    animation_controller.setParameters();
}

void loop()
{
    animation_controller.updateAnimation();
}
