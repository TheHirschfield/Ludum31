#include "Graphics.h"
#include "Resources.h"
#include "Debug.h"
#include "Game.h"
#include "Animation.h"

SDL_Window* window;
SDL_Renderer* screen;

int SCREEN_WIDTH = 1280;
int SCREEN_HEIGHT = 720;

Graphics::Graphics()
{
	SCREEN_WIDTH = 1280;
	SCREEN_HEIGHT = 720;
}
Graphics::~Graphics()
{
}

void Graphics::init(){
	resources.loadImages();
	animation.frame = 0;
}

SDL_Texture* Graphics::loadImage(string path){
	SDL_Texture *finalImage = nullptr;

	finalImage = IMG_LoadTexture(screen, path.c_str());
	if (finalImage == nullptr)
		debug.report("Failed to Load Image: ", path.c_str());
	else
		debug.report("Image Loaded: ", path.c_str());

	return finalImage;
}

void Graphics::draw(int x, int y, SDL_Texture* source, SDL_Renderer* destination){
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_QueryTexture(source, NULL, NULL, &offset.w, &offset.h);
	SDL_RenderCopy(destination, source, NULL, &offset);

	//	debug.report("Cool Cool");
}


Graphics graphics;