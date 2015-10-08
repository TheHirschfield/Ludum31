#pragma once

#include <SDL.h>

#include <iostream>
#include <string>

using std::string;

class Graphics
{
public:

	SDL_Window* window;
	SDL_Renderer* screen;

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;


	Graphics();
	~Graphics();

	void init();

	SDL_Texture* loadImage(string path);
	void draw(int x, int y, SDL_Texture* source, SDL_Renderer* destination);

};

extern Graphics graphics;