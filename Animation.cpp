#include "Animation.h"

int frame = 0;

Animation::Animation()
{
}
Animation::~Animation()
{
}

void Animation::loop(){

	frame++;

	if (frame > 60){
		frame = 1;
	}
}


Animation animation;