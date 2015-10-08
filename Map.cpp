#include "Map.h"
#include "Debug.h"
#include "Graphics.h"
#include "Resources.h"
#include "Game.h"
#include "Player.h"
#include "Entity.h"
#include "Workshop.h"
#include "Animation.h"


Map::Map()
{

}
Map::~Map()
{
}


// Original Ludum Dare Engine Map Stuff
float objectHealth[16];
int objectPosition[16];

int mapTimer = 0;
int mapTimer2 = 0;
SDL_Texture* currentHealth = NULL;

void Map::run(){

	workshop.checkDamage();

	
	switch (entity.currentPhase){
		// WAVE 1
	case 1: 
		if (mapTimer == 150){
			entity.add(entity.SNOWMAN);
			mapTimer = 0;
		}
		if (entity.totalKills > 10){
			entity.currentPhase = 2;
			mapTimer = 0;
			mapTimer2 = 0;
		}
		break;
		// WAVE 2
	case 2:
		if (mapTimer == 150){
			entity.add(entity.SNOWMAN);
			mapTimer = 0;
		}
		if (mapTimer2 == 400){
			entity.add(entity.SNOWMAN2);
			mapTimer2 = 0;
		}
		if (entity.totalKills > 40){
			entity.currentPhase = 3;
			mapTimer = 0;
			mapTimer2 = 0;
		}
		break;
		// WAVE 3
	case 3:
		if (mapTimer == 120){
			entity.add(entity.SNOWMAN);
			mapTimer = 0;
		}
		if (mapTimer2 == 300){
			entity.add(entity.SNOWMAN2);
			mapTimer2 = 0;
		}
		if (entity.totalKills > 52){
			entity.currentPhase = 4;
			mapTimer = 0;
			mapTimer2 = 0;
		}
		break;
		// WAVE 4
	case 4:
		if (mapTimer == 110){
			entity.add(entity.SNOWMAN);
			mapTimer = 0;
		}
		if (mapTimer2 == 200){
			entity.add(entity.SNOWMAN2);
			mapTimer2 = 0;
		}
		if (entity.totalKills > 64){
			entity.currentPhase = 5;
			mapTimer = 0;
			mapTimer2 = 0;
		}
		break;
		// WAVE 5
	case 5:
		if (mapTimer == 100){
			entity.add(entity.SNOWMAN);
			mapTimer = 0;
		}
		if (mapTimer2 == 170){
			entity.add(entity.SNOWMAN2);
			mapTimer2 = 0;
		}
		if (entity.totalKills > 80){
			entity.currentPhase = 6;
			mapTimer = 0;
			mapTimer2 = 0;
		}
		break;
		// WAVE 6
	case 6:
		if (mapTimer == 90){
			entity.add(entity.SNOWMAN);
			mapTimer = 0;
		}
		if (mapTimer2 == 130){
			entity.add(entity.SNOWMAN2);
			mapTimer2 = 0;
		}
		if (entity.totalKills > 100){
			entity.currentPhase = 7;
			mapTimer = 0;
			mapTimer2 = 0;
		}
		break;
		// WAVE 7
	case 7:
		if (mapTimer == 80){
			entity.add(entity.SNOWMAN);
			mapTimer = 0;
		}
		if (mapTimer2 == 100){
			entity.add(entity.SNOWMAN2);
			mapTimer2 = 0;
		}
		if (entity.totalKills > 115){
			entity.currentPhase = 8;
			mapTimer = 0;
			mapTimer2 = 0;
		}
		break;
		// WAVE 8
	case 8:
		if (mapTimer == 70){
			entity.add(entity.SNOWMAN);
			mapTimer = 0;
		}
		if (mapTimer2 == 90){
			entity.add(entity.SNOWMAN2);
			mapTimer2 = 0;
		}

		break;
	}

	//Already Added on Map Section.
	for (int totalMobs = 0; totalMobs < 16; totalMobs++){
		int movementSpeed;
		
		
		if (entity.positionEntityType[totalMobs] != entity.NONE){
		
		switch (entity.positionEntityType[totalMobs]){
		case entity.NONE:
			break;
		case entity.SNOWMAN:
			movementSpeed = entity.SNOWMAN_SPEED;
			break;
		case entity.SNOWMAN2:
			movementSpeed = entity.SNOWMAN_SPEED;
			break;
		case entity.BOMB:
			movementSpeed = -2;
			break;
		}

		for (int objectFinder = 0; objectFinder < 16; objectFinder++){
	
			if (objectType[objectFinder] != DEBUG &&objectPosition[objectFinder] < entity.positionEntityX[totalMobs] && entity.positionEntityX[totalMobs] < objectPosition[objectFinder] + 32){

				if (entity.positionEntityType[totalMobs] == entity.SNOWMAN){
					movementSpeed = 0;
					objectHealth[objectFinder]--;		
				}				

				if (objectHealth[objectFinder] < 1){
					objectPosition[objectFinder] = 0;
					objectHealth[objectFinder] = 0;
					objectType[objectFinder] = DEBUG;
				}
			}
			
		}
		//Stops Entity From Moving!
		entity.positionEntityX[totalMobs] -= movementSpeed;
		
		//objectHealth[renderedObjects]
		}

	}

	mapTimer++;
	mapTimer2++;
	if (mapTimer == 600){
		mapTimer = 0;
	}
	if (mapTimer2 == 600){
		mapTimer2 = 0;
	}

}

void Map::render(){
	
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

	graphics.draw(1100, 402, resources.objectCandyCane, graphics.screen);
	
	for ( int renderedObjects = 0; renderedObjects < 16; renderedObjects++)
	{
		if (objectHealth[renderedObjects] != 0){
			
			int objectHealthShow;

			switch (objectType[renderedObjects]){
			case DEBUG:
				graphics.draw(objectPosition[renderedObjects], 620, resources.testImage, graphics.screen);
				break;
			case BARRIER1:
				graphics.draw(objectPosition[renderedObjects], 600, resources.objectBarriers, graphics.screen);
				objectHealthShow = 200;
				break;
			case BARRIER2:
				graphics.draw(objectPosition[renderedObjects], 600, resources.objectBarriers2, graphics.screen);
				objectHealthShow = 200;
				break;
			case BARRIER3:
				graphics.draw(objectPosition[renderedObjects], 610, resources.objectBarriers3, graphics.screen);
				objectHealthShow = 200;
				break;
			case TURRET:
				graphics.draw(objectPosition[renderedObjects], 620, resources.objectTurret, graphics.screen);
				objectHealthShow = 100;
				break;
			}
			
			SDL_Rect healthBar = { objectPosition[renderedObjects]+9, 584, (48 * (objectHealth[renderedObjects] / objectHealthShow)), 7 };
			SDL_SetRenderDrawColor(graphics.screen, 0xFF, 0xFF, 0x00, 0x00);
			SDL_RenderFillRect(graphics.screen, &healthBar);
			
			graphics.draw(objectPosition[renderedObjects], 580, resources.guiHealth0, graphics.screen);
		
		}
	}
}


void Map::load(int id){

	//Core Resets
	mapTimer = 0;
	player.shootAvailable = true;
	player.shootTimer = 0;

	//Entity Resets
	entity.reset();
	entityCount = 0; 


	switch (id){
	case 1:

		entity.createObject(BARRIER3, 150);

		entity.maxEntities = 2000;

		entity.currentPhase = 1;

		player.damageWeapons[1] = 50;
		player.typePeaShooter = 1;
		entity.SNOWMAN_SPEED = 2;
		player.inventory[0] = { player.PEASHOOTER};
		player.inventory[1] = { player.BLOCK };
		player.inventory[2] = { player.TURRET };
		player.heldWeapon = resources.itemTier1Gun;
		player.currentWeapon = resources.itemTier1Gun;
		break;
	
		
	}

	animation.waveGraphicTimer = 120;
	player.itemInHand = 1;

	currentMapID = id;
}



Map map;