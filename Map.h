#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <vector>

class Map
{
public:
	
	int currentMapID;
	
	Map();
	~Map();

	// Original Ludum Dare Engine Map Stuff

	int mapTimer;

	enum object_type_t { DEBUG, BARRIER1, BARRIER2, BARRIER3, TURRET, TREE };

	//Entity 
	int entityCount;


	// Object Lives
	object_type_t objectType[16];
	float objectHealth[16];
	int objectPosition[16];
	
	void run();
	void render();
	void load(int id);
	bool checkSecure();

};

extern Map map;