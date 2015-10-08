#pragma once
class Animation
{
public:

	int frame;

	int weaponGraphicTimer;
	int waveGraphicTimer;
	int hitGraphicTimer;

	Animation();
	~Animation();

	void loop();

};

extern Animation animation;