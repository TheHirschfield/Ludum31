#include "Workshop.h"
#include "Entity.h"
#include "Game.h"
#include "Graphics.h"
#include "Resources.h"
#include "Menu.h"
#include "Player.h"

int workshopHealth = 1000;

Workshop::Workshop()
{
}
Workshop::~Workshop()
{
}

int current_money_metre = 0;
SDL_Texture* workshopHealthBar = NULL;

void Workshop::checkDamage(){

	for (int totalMobsDamage = 0; totalMobsDamage < 16; totalMobsDamage++){
		if (entity.positionEntityX[totalMobsDamage] < 60 && entity.positionEntityType[totalMobsDamage] != entity.BOMB){
			
			switch (entity.positionEntityType[totalMobsDamage]){
			case entity.SNOWMAN:
				workshopHealth -= 10;
				entity.positionEntityX[totalMobsDamage] += 10;
				entity.hurt(totalMobsDamage, 30);
				break;
			case entity.SNOWMAN2:
				if (entity.positionEntitySpecialUsed[totalMobsDamage] == false){
					entity.add(entity.BOMB);
					entity.positionEntitySpecialUsed[totalMobsDamage] = true;
				}			
				//Drop The Bomb
				break;
			}
		}
		else if (entity.positionEntityX[totalMobsDamage] > 450 && entity.positionEntityType[totalMobsDamage] == entity.BOMB){

			workshopHealth -= 75;
			
			Mix_PlayChannel(-1, resources.soundBang, 0);
			
			entity.positionEntityType[totalMobsDamage] = entity.NONE;
			entity.positionEntityX[totalMobsDamage] = 0;
			entity.positionEntityHealth[totalMobsDamage] = 0;
		}

	}
	if (workshopHealth < 1){
		game.changeState(game.MAIN_MENU);
		menu.currentMenu = 3;

	}
}

void Workshop::render(){

	switch (game.state){
	case game.GAMEPLAY:
			graphics.draw(0, 275, resources.objectHouse, graphics.screen);
		
			
		//Money GUI
		graphics.draw(0, 90, resources.guiMoney0, graphics.screen);

		SDL_Rect moneyBar = { 6, 95, player.currency, 25 };
		SDL_SetRenderDrawColor(graphics.screen, 0xFF, 0xFF, 0x00, 0x00);
		if (moneyBar.w > 500){
			moneyBar.w = 500;
		}

		SDL_RenderFillRect(graphics.screen, &moneyBar);
		graphics.draw(0, 90, resources.guiMoneyOverlay, graphics.screen);
	
		//Health GUI
		graphics.draw(0, 10, resources.guiWHealth0, graphics.screen);

		SDL_Rect healthBar = { 6, 15, (308 * (workshopHealth/1000)), 35 };
		SDL_SetRenderDrawColor(graphics.screen, 0x00, 0xFF, 0x00, 0x00);
		SDL_RenderFillRect(graphics.screen, &healthBar);

		graphics.draw(0, 275, resources.objectHouse, graphics.screen);




		break;

	}

}


Workshop workshop;