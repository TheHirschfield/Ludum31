#pragma once

#include "Map.h"

class Entity
{
public:


	enum mob_type_t { NONE, SNOWMAN, SNOWMAN2, BOMB};

	mob_type_t positionEntityType[16];
	int positionEntityX[16];
	float positionEntityHealth[16];
	int positionEntityDamageTimer[16];
	bool positionEntitySpecialUsed[16];
	//int positionEntitySpeed[16];

	int healthSnowman;

	int maxEntities;

	int currentPhase;

	int totalKills;

	int weaponMultiplier;

	int SNOWMAN_SPEED;
	int SNOWMAN_ATTACK_POWER;

	Entity();
	~Entity();


	void reset();
	void add(mob_type_t mob);
	void render();
	void calculate();

	bool createObject(Map::object_type_t type, int positionX);

	//Gameplayer Mechanics
	void hurt(int id, int hurtAmount);

};
extern Entity entity;