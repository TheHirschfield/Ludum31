#include "GUI.h"
#include "Game.h"
#include "Graphics.h"
#include "Resources.h"
#include "Engine.h"
#include "Menu.h"
#include "Debug.h"
#include "Map.h"
#include "Workshop.h"
#include "Animation.h"

GUI::GUI()
{
}
GUI::~GUI()
{
}

void GUI::addButton(menu_buttons_t name, int placementX, int placementY){

	SDL_Texture* newButton = NULL;
	int buttonWidth, buttonHeight;

	switch (name){
	case PLAY:
		newButton = resources.menuMainPlay;
		buttonWidth = 200;
		buttonHeight = 64;
		break;
	case INSTRUCTIONS:
		newButton = resources.menuMainInstructions;
		buttonWidth = 200;
		buttonHeight = 64;
		break;
	case OPTIONS:
		newButton = resources.menuMainOptions;
		buttonWidth = 200;
		buttonHeight = 64;
		break;
	case EXIT:
		newButton = resources.menuMainExit;
		buttonWidth = 200;
		buttonHeight = 64;
		break;
	case GAME_MENU:
		//	newButton = resources.uiMenuSave;
		buttonWidth = 128;
		buttonHeight = 24;
		break;
	case BACK:
		newButton = resources.menuMainBack;
		buttonWidth = 200;
		buttonHeight = 64;
		break;
	}

	graphics.draw(placementX, placementY, newButton, graphics.screen);

	if (engine.mouseX > placementX &&
		engine.mouseX < placementX + buttonWidth &&
		engine.mouseY > placementY &&
		engine.mouseY < placementY + buttonHeight &&
		engine.mouseLeftClick == true){
		switch (name){
		case PLAY:

			game.changeState(game.GAMEPLAY);
			map.load(1);
			workshop.workshopHealth = 1000;
			engine.mouseLeftClick = false;
			break;
		case INSTRUCTIONS:
			menu.currentMenu = 1;
			break;
		case OPTIONS:
			menu.currentMenu = 2;
			break;
		case EXIT:
			game.running = false;
			break;
		case GAME_MENU:
			
			break;
		case BACK:
			menu.currentMenu = 0;
			break;
			buttonAvailiable = true;
			engine.mouseLeftClick = false;
		}
	}
}

void GUI::render(){
	
	if (animation.hitGraphicTimer > 0){

		graphics.draw(engine.mouseX - 16, engine.mouseY - 16, resources.guiHitMarker, graphics.screen);

		animation.hitGraphicTimer--;
	}
}

GUI gui;