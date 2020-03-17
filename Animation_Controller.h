#pragma once
#pragma message "Animation_Controller.h is included"

#include "Animation.h"
#include "Twinkle_Animation.h"
#include "Blink_Animation.h"

class Animation_Controller
{
private:
	Animation *current_animation_;
	Animation *getAnimation(definitions::Animations);

public:
	Animation_Controller();
	~Animation_Controller();

	void setAnimation(definitions::Animations);
	void setParameters();
	void updateAnimation();
};
