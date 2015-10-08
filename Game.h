#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <iostream>
#include <string>


class Game
{
public:

	enum state_current_t { STARTUP, MAIN_MENU, GAMEPLAY, GAMEPLAY_LOCKED, CREDITS };

	bool running;

	state_current_t state;

	Game();
	~Game();

	void init();

	void run();
	void display();

	void changeState(state_current_t newState);
	int getState();

	void cleanUp();


};

extern Game game;