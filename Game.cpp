#include "Game.h"
#include "Engine.h"
#include "Debug.h"
#include "Graphics.h"
#include "Resources.h"
#include "Audio.h"
#include "Map.h"
#include "Menu.h"
#include "Entity.h"
#include "Animation.h"
#include "GUI.h"
#include "Player.h"
#include "Workshop.h"

int running = 0;

Game::Game()
{
}
Game::~Game()
{
}

void Game::init(){

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0){
		debug.report("SDL Had Problems Initiazing");
	}
	else{

		IMG_Init(IMG_INIT_PNG);
		debug.report("SDL Sucessfully Initiazing");
		debug.mode = false;

		graphics.window = SDL_CreateWindow("Santa's Last Stand", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, graphics.SCREEN_WIDTH, graphics.SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		graphics.screen = SDL_CreateRenderer(graphics.window, -1, SDL_RENDERER_ACCELERATED);

		graphics.init();
		audio.init();
		state = MAIN_MENU;

		//audio.playMusic(resources.testMusic);
		running = true;
		debug.report("Game Loop Is Now Running");
	}
}

void Game::run(){

	switch (state){

	case 0:

		break;
	case 1:
		
		break;
	case 2:
		player.actions();
		map.run();
		entity.calculate();
		break;
	}
	if (Mix_PlayingMusic() == 0){
		audio.playMusic(resources.testMusic);
	}

	debug.checkCommands();
}


void Game::display(){

	switch (state){

	case 0: // Loading Up
		graphics.draw(100, 100, resources.testImage, graphics.screen);
		break;
	case 1: // Menu
		menu.render();

		/*if (debug.mode){
			graphics.draw(100, 100, resources.testImage, graphics.screen);
		}*/
		break;
	case 2: // Gameplay

		map.render();
		player.render();
		workshop.render();
		
		entity.render();
		gui.render();

		if (debug.mode){ graphics.draw(1216, 0, resources.testImage, graphics.screen); }
		break;
	}

	animation.loop();
}

void Game::changeState(state_current_t newState){
	state = newState;
}

int Game::getState(){

	return state;
}

void Game::cleanUp(){

	SDL_DestroyWindow(graphics.window);
	graphics.window = NULL;
	SDL_Quit();
}

Game game;