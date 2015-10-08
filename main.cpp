#include <SDL.h>

#include "Debug.h"
#include "Game.h"
#include "Graphics.h"
#include "Engine.h"


#include <iostream>
#include <string>

using std::cout;
using std::string;


int main(int argc, char** argv){

	debug.report("Starting Game: WIP");

	game.init();

	int lastTime = 0;
	float frameTimer = 0;

	// Main Game Loop
	while (game.running){

		const float FRAME_TIME = 1.0f / 60.0f;
		int dtMs = SDL_GetTicks() - lastTime;
		Engine::deltaTime = FRAME_TIME;
		frameTimer += dtMs / 1000.f;
		bool updated = false;

		// FPS CAP AT 60 DEVELOPED OGCAPSLOCK
		while (frameTimer >= FRAME_TIME){
			engine.events();
			game.run();
			frameTimer -= FRAME_TIME;
			updated = true;
		}

		if (updated){
			SDL_RenderClear(graphics.screen);
			game.display();
			SDL_RenderPresent(graphics.screen);
		}

		lastTime += dtMs;
		SDL_Delay(1);

	}

	game.cleanUp();

	return 0;
}