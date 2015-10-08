#pragma once

#include <SDL.h>
#include <SDL_mixer.h>

#include <iostream>
#include <string>

using std::string;

class Audio
{
public:
	Audio();
	~Audio();
	
	void init();
	void loadSound(string path);
	void playMusic(Mix_Music* musicPlay);
};

extern Audio audio;