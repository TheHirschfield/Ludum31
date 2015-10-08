#include "Menu.h"
#include "Game.h"
#include "Resources.h"
#include "Graphics.h"
#include "GUI.h"

Menu::Menu()
{
}
Menu::~Menu()
{
}

int currentMenu = 0;
bool gameMenu = 0;
int currentOption = 1;

void Menu::render(){

	switch (game.state){
	case 0:
		break;
	case 1: //Actual Main Menu + Other Menus (Credits/Options)

		switch (currentMenu){
		case 0: // Home Menu
			
			graphics.draw(0, 0, resources.mapBackground2, graphics.screen);

			graphics.draw(200, 404, resources.objectTree, graphics.screen);
			graphics.draw(300, 402, resources.objectTree, graphics.screen);
			graphics.draw(400, 402, resources.objectTree, graphics.screen);
			graphics.draw(500, 402, resources.objectTree, graphics.screen);
			graphics.draw(600, 405, resources.objectTree, graphics.screen);
			graphics.draw(700, 408, resources.objectTree, graphics.screen);
			graphics.draw(800, 410, resources.objectTree, graphics.screen);
			graphics.draw(900, 406, resources.objectTree, graphics.screen);
			graphics.draw(1000, 406, resources.objectTree, graphics.screen);
			graphics.draw(0, 275, resources.objectHouse, graphics.screen);
			graphics.draw(1100, 402, resources.objectCandyCane, graphics.screen);
			
			graphics.draw(0, 20, resources.coreLogo, graphics.screen);
			gui.addButton(gui.PLAY, 1050, 50);
			gui.addButton(gui.OPTIONS, 1050, 150);
			gui.addButton(gui.EXIT, 1050, 250);
			break;
		case 1: // Instructions
			graphics.draw(0, 0, resources.menuMainInstructions, graphics.screen);
			gui.addButton(gui.BACK, 20, 500);
			break;
		case 2: // Options
			graphics.draw(0, 0, resources.menuGameOptions, graphics.screen);
			gui.addButton(gui.BACK, 900, 570);
			break;
		case 3: // Game Over
			graphics.draw(0, 0, resources.menuMainGameOver, graphics.screen);
			gui.addButton(gui.BACK, 20, 500);
			break;
		}

		break;
	case 2: // Gameplay Menu
		if (gameMenu){


		}

		break;
	case 3:

		break;

	}


}

Menu menu;