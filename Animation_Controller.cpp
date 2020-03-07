#include "Animation_Controller.h"

Animation *Animation_Controller::GetAnimation(definitions::Animations new_animation)
{
	switch (new_animation)
	{
	case definitions::Animations::TWINKLE:
		return (new Twinkle_Animation);
		break;

	case definitions::Animations::BLINK:
		return (new Blink_Animation);
		break;

	default:
		//Add some exception here
		return (NULL);
		break;
	}
	return NULL;
}

Animation_Controller::Animation_Controller()
	: current_animation_(GetAnimation(definitions::DEFAULT_ANIMATION))
{
}

Animation_Controller::~Animation_Controller()
{
	delete Animation_Controller::current_animation_;
}

void Animation_Controller::SetAnimation(definitions::Animations new_animation)
{
	delete current_animation_;
	current_animation_ = GetAnimation(new_animation);
}

void Animation_Controller::SetParameters()
{
	current_animation_->SetParameters();
}

void Animation_Controller::UpdateAnimation()
{
	current_animation_->OnUpdate();
}