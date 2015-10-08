#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Workshop
{
public:

	float workshopHealth;

	Workshop();
	~Workshop();

	void checkDamage();
	void render();

};

extern Workshop workshop;