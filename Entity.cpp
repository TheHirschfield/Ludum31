#include "Entity.h"
#include "Animation.h"
#include "Graphics.h"
#include "Game.h"
#include "Resources.h"
#include "Debug.h"
#include "Engine.h"
#include "Player.h"
#include "Audio.h"
#include "Map.h"

int maxEntities = 0;

int currentPhase = 0; 

int placementX = 0;
int placementY = 0;

int buttonWidth = 0;
int buttonHeight = 0;

int totalKills = 0;

int objectCreateTimer = 0;

SDL_Texture* entityHealth = NULL;
int healthSnowman = 0;

int snowmanTakeDamage = 30;
int weaponMultiplier = 0;

int turretCooldown = 0;

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::add(mob_type_t mob){
	
	
	// Check the Next Avaliable Array Slot
	for (int totalMobs = 0; totalMobs < 16; totalMobs++){

		if (positionEntityType[totalMobs] == NONE){
			positionEntityType[totalMobs] = mob;
			if (positionEntityType[totalMobs] != BOMB){
				positionEntityX[totalMobs] = 1280;
			}
			else{
				positionEntityX[totalMobs] = 340;
			}
			
			positionEntityHealth[totalMobs] = 100;

			//debug.report("Added New Entity at: ", positionEntityX[totalMobs]);
			totalMobs = 17;
		}

	}

	// Add The Required Entity Inside, set positions to the start and add health
}

void Entity::reset(){

	SNOWMAN_SPEED = 1;
	SNOWMAN_ATTACK_POWER = 10;

	for (int totalMobs = 0; totalMobs < 16; totalMobs++){

		positionEntityType[totalMobs] = NONE;
		positionEntityX[totalMobs] = 0;
		positionEntityHealth[totalMobs] = 0;
		positionEntityDamageTimer[totalMobs] = 0;


		}
	}

void Entity::render(){
	int mobBarHeight;
	int mobPosY;

	for (int totalMobs = 0; totalMobs < 16; totalMobs++){

		if (positionEntityType[totalMobs] != NONE){

			switch (positionEntityType[totalMobs]){
			case SNOWMAN:
				graphics.draw(positionEntityX[totalMobs], 570, resources.entitySnowman, graphics.screen);
				placementX = positionEntityX[totalMobs];
				placementY = 570-4;
				buttonWidth = 76;
				buttonHeight = 96;

				break;
			case SNOWMAN2:
				graphics.draw(positionEntityX[totalMobs], 300, resources.entitySnowman2, graphics.screen);
				placementX = positionEntityX[totalMobs];
				placementY = 300;
				buttonWidth = 128;
				buttonHeight = 64;
				break;
			case BOMB:
				graphics.draw(40, positionEntityX[totalMobs], resources.entitybomb, graphics.screen);
				placementX = 40;
				placementY = positionEntityX[totalMobs];
				buttonWidth = 128;
				buttonHeight = 64;
				break;
			}

			

			if (positionEntityHealth[totalMobs] > 0 && positionEntityType[totalMobs] != BOMB){
				
				switch(positionEntityType[totalMobs]){
				case SNOWMAN:
					mobBarHeight = 540;
					
					break;
				case SNOWMAN2:
					mobBarHeight = 200;
					break;

				}

					SDL_Rect healthBarMob = { positionEntityX[totalMobs] + 9, mobBarHeight + 4, (48 * (positionEntityHealth[totalMobs] / 100)), 7 };
					SDL_SetRenderDrawColor(graphics.screen, 0xFF, 0x00, 0x00, 0xFF);
					SDL_RenderFillRect(graphics.screen, &healthBarMob);

					graphics.draw(positionEntityX[totalMobs], mobBarHeight, resources.guiHealth0, graphics.screen);
			
			
			}
		}
		if (player.itemInHand == 1){

			//Collison
			if (engine.mouseX > placementX &&
				engine.mouseX < placementX + buttonWidth &&
				engine.mouseY > placementY &&
				engine.mouseY < placementY + buttonHeight &&
				engine.mouseLeftClick == true && player.shootAvailable){

				switch (map.currentMapID){
				case 1:
					snowmanTakeDamage = 40;
					break;
				case 2:
					switch (player.itemInHand){
					case 0:
						break;
					case 1:
						snowmanTakeDamage = 20;
						break;
					}
					break;
				}

				switch (positionEntityType[totalMobs]){
				case SNOWMAN:

					player.currency += 10;
					hurt(totalMobs, snowmanTakeDamage);

					player.shootAvailable = false;

					switch (player.typePeaShooter){
					case 1:
						player.shootTimer = 20;
						break;
					case 2:
						player.shootTimer = 14;
						break;
					case 3:
						player.shootTimer = 8;
						break;
					}



					Mix_PlayChannel(-1, resources.soundHitMarker, 0);
					animation.weaponGraphicTimer = 20;
					break;

				case SNOWMAN2:

					player.currency += 15;
					hurt(totalMobs, snowmanTakeDamage);

					player.shootAvailable = false;

					switch (player.typePeaShooter){
					case 1:
						player.shootTimer = 20;
						break;
					case 2:
						player.shootTimer = 14;
						break;
					case 3:
						player.shootTimer = 8;
						break;
					}


					Mix_PlayChannel(-1, resources.soundHitMarker, 0);
					animation.weaponGraphicTimer = 20;
					break;

				}
				animation.hitGraphicTimer = 20;
			}

		}
		
		if (positionEntityType[totalMobs] == SNOWMAN2 && entity.positionEntityX[totalMobs] < -120){

			positionEntityType[totalMobs] = NONE;
			entity.positionEntityHealth[totalMobs] = 0;
			entity.positionEntityX[totalMobs] = 0;
			entity.positionEntitySpecialUsed[totalMobs] = false;
			
		}

		}

		if (animation.weaponGraphicTimer > 0){
			graphics.draw(98, 480, resources.itemTier1Effect, graphics.screen);
			animation.weaponGraphicTimer--;
		}
		switch (player.itemInHand){
		case 2:
			if (engine.mouseY > 400 && objectCreateTimer < 1 && player.currency == 100 ){
				graphics.draw(engine.mouseX, 610, resources.objectBarriersClear, graphics.screen);
			}
			break;
		case 3:
			if (engine.mouseY > 400 && objectCreateTimer < 1 && player.currency == 350){
				graphics.draw(engine.mouseX, 620, resources.objectTurretClear, graphics.screen);
			}
			break;
		}
	}



void Entity::hurt(int id, int hurtAmount){
	positionEntityHealth[id] -= hurtAmount;

	if (positionEntityHealth[id] < 1){
		if (positionEntityType[id] == SNOWMAN2){
			Mix_PlayChannel(-1, resources.sounddeath, 0);
		}
		else if (positionEntityType[id] == SNOWMAN){
			Mix_PlayChannel(-1, resources.soundsnowdeath, 0);
		}
		
		positionEntityType[id] = NONE;
		positionEntityHealth[id] = 0;
		positionEntityX[id] = 0;
		
		totalKills++;
	}
}

void Entity::calculate(){

	

	//Turret Stuff
	for (int objectFinder = 0; objectFinder < 16; objectFinder++){
		if (map.objectType[objectFinder] == map.TURRET){
			
			for (int totalMobsAwareness = 0; totalMobsAwareness < 16; totalMobsAwareness++){
				
				if (map.objectPosition[objectFinder] < entity.positionEntityX[totalMobsAwareness] && entity.positionEntityX[totalMobsAwareness] < map.objectPosition[objectFinder] + 256 && turretCooldown < 1 && positionEntityType[totalMobsAwareness] != SNOWMAN2){
					positionEntityHealth[totalMobsAwareness] -= 15;
					turretCooldown = 20;
					Mix_PlayChannel(-1, resources.soundHitMarker, 0);
					if (entity.positionEntityHealth[totalMobsAwareness] < 1){

						if (positionEntityType[totalMobsAwareness] == SNOWMAN2){
							Mix_PlayChannel(-1, resources.sounddeath, 0);
						}
						else if (positionEntityType[totalMobsAwareness] == SNOWMAN){
							Mix_PlayChannel(-1, resources.soundsnowdeath, 0);
						}

						entity.positionEntityType[totalMobsAwareness] = NONE;
						entity.positionEntityX[totalMobsAwareness] = 0;
						entity.positionEntityHealth[totalMobsAwareness] = 0;
						totalKills++;
					}
					
				}

			}

		}
	}

	turretCooldown--;


	if (player.itemInHand == 2){

		if (engine.mouseLeftClick && objectCreateTimer < 1){

			for (int objectPlaceCheck = 0; objectPlaceCheck < 16; objectPlaceCheck++){

				if (engine.mouseX > map.objectPosition[objectPlaceCheck] &&
					engine.mouseX < map.objectPosition[objectPlaceCheck] + 32){
				}
				else{			
					createObject(map.BARRIER3, engine.mouseX);
					objectCreateTimer = 120;
				}

			}
			
			player.itemInHand = 1;
			player.heldWeapon = resources.itemTier2Gun;
			player.currentWeapon = resources.itemTier2Gun;
			player.currentWeapon = player.getRenderItem(0);
			
		}

	}
	if (player.itemInHand == 3){


		if (engine.mouseLeftClick && objectCreateTimer < 1){

			for (int objectPlaceCheck = 0; objectPlaceCheck < 16; objectPlaceCheck++){

				if (engine.mouseX > map.objectPosition[objectPlaceCheck] &&
					engine.mouseX < map.objectPosition[objectPlaceCheck] + 32){
				}
				else{
					createObject(map.TURRET, engine.mouseX);
					objectCreateTimer = 120;
				}

			}
			
				player.itemInHand = 1;
				player.heldWeapon = resources.itemTier2Gun;
				player.currentWeapon = resources.itemTier2Gun;
				player.currentWeapon = player.getRenderItem(0);

		}

	}

	if (objectCreateTimer > 0){
		objectCreateTimer--;
	}

}


bool Entity::createObject(Map::object_type_t type, int positionX){



	for (int totalObjects = 0; totalObjects < 16; totalObjects++){

		if (map.objectType[totalObjects] == NONE && objectCreateTimer < 1){
			
			//switch
			switch (type){
			
			case map.BARRIER3:
				if (player.currency >= 100){
					map.objectType[totalObjects] = map.BARRIER3;
					map.objectPosition[totalObjects] = positionX;
					map.objectHealth[totalObjects] = 200;
					player.currency -= 100;
				}
				break;
			
			case map.TURRET:
				if (player.currency >= 350){
					map.objectType[totalObjects] = map.TURRET;
					map.objectPosition[totalObjects] = positionX;
					map.objectHealth[totalObjects] = 100;
					player.currency -= 350;
				}
				break;
			}


			totalObjects = 16;
			debug.report("Added New Object at: ", positionX);
			objectCreateTimer = 120;
			return true;
		}

	}
	return false;
}

Entity entity;