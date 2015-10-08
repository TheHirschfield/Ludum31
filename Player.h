#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Player
{
public:

	SDL_Texture* currentWeapon;
	SDL_Texture* heldWeapon;

	int locationX;
	int locationY;

	int speed;
	int health;

	int currency;

	enum player_inventory_t { DEBUG, PEASHOOTER, BLOCK , TURRET, CANDY_SHOWER, COAL_TA_PULT, PRESENT_BOMB, SANTA_CARPET_BOMB, ORBITAL_FRIENDSHIP_CANNON };

	player_inventory_t inventory[8];

	int typePeaShooter;

	bool shootAvailable;
	int shootTimer;

	int damageWeapons[8];

	int itemInHand;

	Player();
	~Player();

	void render();
	void actions();
	void changeHealth(int healthChange);

	SDL_Texture* getRenderItem(int slot);
};

extern Player player;