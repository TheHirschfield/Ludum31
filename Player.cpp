#include "Player.h"
#include "Graphics.h"
#include "Resources.h"
#include "Animation.h"
#include "Resources.h"
#include "Map.h"
#include "Engine.h"
#include "Debug.h"
#include "Entity.h"

bool shootAvailable = 0;
int shootTimer = 0;

SDL_Texture* currentWeapon = NULL;
int itemInHand = 0;

int currency = 0;

Player::Player()
{
}

Player::~Player()
{
}

void Player::changeHealth(int healthChange){

	health += healthChange;
}

void Player::actions(){

	//Action Bar Switching



	//Shooter Stuff
	if (shootTimer < 1 && shootAvailable == false){
		shootAvailable = true;
	}
	else{
		shootTimer--;
	}

	if (engine.key1){ // Main Gun
		currentWeapon = getRenderItem(0);
	}
	else if (engine.key2){ // Create Barriers
		currentWeapon = getRenderItem(1);
		itemInHand = 2;
	}
	else if (engine.key3){ // Create Turret
		currentWeapon = getRenderItem(2);
		itemInHand = 3;
	}
	//else if (engine.key4){
	//	currentWeapon = getRenderItem(3);
	//	itemInHand = 4;
	//}
	//else if (engine.key5){
	//	currentWeapon = getRenderItem(4);
	//	itemInHand = 5;
	//}
	//else if (engine.key6){
	//	currentWeapon = getRenderItem(5);
	//	itemInHand = 6;
	//}


}

void Player::render(){
	
	//Player Sprite
	if (animation.frame < 15){
		graphics.draw(33, 425, resources.playeridle1, graphics.screen);
		graphics.draw(33, 440, heldWeapon, graphics.screen);
	}
	else if(animation.frame < 30){
		graphics.draw(33, 425, resources.playeridle1, graphics.screen);
		graphics.draw(33, 440, heldWeapon, graphics.screen);
	}
	else if (animation.frame < 45){
		graphics.draw(33, 425, resources.playeridle1, graphics.screen);
		graphics.draw(33, 440, heldWeapon, graphics.screen);
	}
	else if (animation.frame < 61){
		graphics.draw(33, 425, resources.playeridle1, graphics.screen);
		graphics.draw(33, 440, heldWeapon, graphics.screen);
	}
	

		
	for (int actionBarStuff = 0; actionBarStuff < 7; actionBarStuff++){
		
		SDL_Texture* barItemImage = NULL;

		switch (inventory[actionBarStuff]){
		case DEBUG:
			break;
		case PEASHOOTER:
			barItemImage = resources.guiPeaShooter;
			break;
		case BLOCK:
			barItemImage = resources.guiBlock;
			break;
		case TURRET:
			barItemImage = resources.guiTurret;
			break;
		}

		graphics.draw(1056 + (74 * actionBarStuff ), 16 , barItemImage, graphics.screen);
	}
	//Action Bar
	graphics.draw(686, 10, resources.guiActionBar, graphics.screen);

	switch (itemInHand){
	case 1:
		graphics.draw(1052, 10, resources.guiHighlight, graphics.screen);
		break;
	case 2:
		if (currency <= 100){
			graphics.draw(1055 + 74, 10, resources.guiHighlightOff, graphics.screen);
		}
		else{
			graphics.draw(1055 + 74, 10, resources.guiHighlight, graphics.screen);
		}
		

		break;
	case 3:
		
		if (currency <= 350){
			graphics.draw(1055 + 74 + 74, 10, resources.guiHighlightOff, graphics.screen);
		}
		else{
			graphics.draw(1055 + 74 + 74, 10, resources.guiHighlight, graphics.screen);
		}
	
		break;
	}

	if (currency <= 100){
		graphics.draw(1055 + 74, 10, resources.guiAvailable, graphics.screen);
	}
	if (currency <= 350){
		graphics.draw(1055 + 74 + 74, 10, resources.guiAvailable, graphics.screen);
	}
	//graphics.draw(690, 10, resources.guiActionBarNum, graphics.screen);
}

SDL_Texture* Player::getRenderItem(int slot){

	SDL_Texture* inventorySlotGraphic = NULL;
	int slotToFind;

	switch (inventory[slot]){
	case DEBUG:
		inventorySlotGraphic = resources.guiDebug;
		heldWeapon = resources.guiDebug;
		itemInHand = 0;
		break;
	case PEASHOOTER:
		
	
		switch (typePeaShooter){
		case 1:
			inventorySlotGraphic = resources.guiPeaShooter;
			heldWeapon = resources.itemTier1Gun;
			break;
		case 2:
			inventorySlotGraphic = resources.guiPeaShooter2;
			heldWeapon = resources.itemTier2Gun;
			break;
		case 3:
			inventorySlotGraphic = resources.guiPeaShooter3;
			heldWeapon = resources.itemTier3Gun;
			break;
		}
			
		
		
		itemInHand = 1;
		break;

	case BLOCK:
		heldWeapon = resources.itemParcel;
		itemInHand = 2;
		break;
	case TURRET:
		inventorySlotGraphic = resources.guiTurret;
		heldWeapon = resources.itemController;
		itemInHand = 3;
		break;
	case CANDY_SHOWER:
		inventorySlotGraphic = resources.guiCandyShower;
		heldWeapon = resources.guiDebug;
		itemInHand = 4;
		break;
	case COAL_TA_PULT:
		inventorySlotGraphic = resources.guiCoaltaPult;
		heldWeapon = resources.guiDebug;
		itemInHand = 5;
		break;
	case PRESENT_BOMB:
		inventorySlotGraphic = resources.guiPresentBomb;
		heldWeapon = resources.guiDebug;
		itemInHand = 6;
		break;
	case SANTA_CARPET_BOMB:
		inventorySlotGraphic = resources.guiSantaBomb;
		heldWeapon = resources.guiDebug;
		itemInHand = 7;
		break;
	case ORBITAL_FRIENDSHIP_CANNON:
		inventorySlotGraphic = resources.guiOrbitalCanon;
		heldWeapon = resources.guiDebug;
		itemInHand = 8;
		break;
		
	}

	return inventorySlotGraphic;
}


Player player;