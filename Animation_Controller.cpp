#include "Animation_Controller.h"

Animation_Controller::Animation_Controller()
	: current_animation_(getAnimation(definitions::DEFAULT_ANIMATION))
{
}

Animation_Controller::~Animation_Controller()
{
	delete Animation_Controller::current_animation_;
}

Animation *Animation_Controller::getAnimation(definitions::Animations new_animation)
{
	switch (new_animation)
	{
	case definitions::Animations::TWINKLE:
		return (new Twinkle_Animation);
		break;

	case definitions::Animations::BLINK:
		return (new Blink_Animation);
		break;

	case definitions::Animations::SET_COLOR:
		return (new SetColor_Animation);
		break;

	default:
		//Add some exception here
		return (NULL);
		break;
	}
	return NULL;
}

void Animation_Controller::setAnimation(definitions::Animations new_animation)
{
	delete current_animation_;
	current_animation_ = getAnimation(new_animation);
}

void Animation_Controller::setParameters()
{
	current_animation_->setParameters();
}

void Animation_Controller::updateAnimation()
{
	current_animation_->onUpdate();
}