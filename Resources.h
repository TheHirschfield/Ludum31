#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <iostream>
#include <string>

class Resources
{
public:

	Resources();
	~Resources();

	void loadImages();
	void loadSounds();

	// Debug Images
	SDL_Texture* testImage;

	// Core Graphics
	SDL_Texture* coreLogo;

	// Menu Graphics
	SDL_Texture* menuBackground;
	SDL_Texture* menuMainPlay;
	SDL_Texture* menuMainInstructions;
	SDL_Texture* menuMainOptions;
	SDL_Texture* menuMainExit;
	SDL_Texture* menuMainGameOver;
	SDL_Texture* menuMainBack;

		//Game Menu
		SDL_Texture* menuGameCore;
		SDL_Texture* menuGameInstructions;
		SDL_Texture* menuGameOptions;
		SDL_Texture* menuGameExit;

	
	//Player
	SDL_Texture* playeridle1;
	SDL_Texture* playeridle2;
	SDL_Texture* playeridle3;

	//Items
	SDL_Texture* itemTier1Gun;
	SDL_Texture* itemTier2Gun;
	SDL_Texture* itemTier3Gun;
	SDL_Texture* itemParcel;
	SDL_Texture* itemController;

	// Item Effects
	SDL_Texture* itemTier1Effect;
	SDL_Texture* itemTurretEffect;

	//Map Backgrounds
	SDL_Texture* mapBackground1;
	SDL_Texture* mapBackground2;
	SDL_Texture* mapBackground3;
	SDL_Texture* mapBackground4;

	//Entity
	SDL_Texture* entitySnowman;
	SDL_Texture* entitySnowman2;
	SDL_Texture* entitybomb;

	//GUI
	SDL_Texture* guiHealthPointOn;
	SDL_Texture* guiHealthPointOff;
	SDL_Texture* guiWaveNotification;
	SDL_Texture* guiHitMarker;

	SDL_Texture* guiMoney0;
	SDL_Texture* guiMoneyOverlay;

	// Action Bar
	SDL_Texture* guiActionBar;
	SDL_Texture* guiActionBarNum;
	SDL_Texture* guiHighlight;
	SDL_Texture* guiAvailable;
	SDL_Texture* guiHighlightOff;

	SDL_Texture* guiDebug;
	SDL_Texture* guiPeaShooter;
	SDL_Texture* guiPeaShooter2;
	SDL_Texture* guiPeaShooter3;
	SDL_Texture* guiBlock;
	SDL_Texture* guiTurret;
	SDL_Texture* guiFlameBoomerang;
	SDL_Texture* guiCandyShower;
	SDL_Texture* guiCoaltaPult;
	SDL_Texture* guiPresentBomb;
	SDL_Texture* guiSantaBomb;
	SDL_Texture* guiOrbitalCanon;

	SDL_Texture* guiWaveIncoming;


	//GUI Health
	SDL_Texture* guiHealth100;
	SDL_Texture* guiHealth90;
	SDL_Texture* guiHealth80;
	SDL_Texture* guiHealth70;
	SDL_Texture* guiHealth60;
	SDL_Texture* guiHealth50;
	SDL_Texture* guiHealth40;
	SDL_Texture* guiHealth30;
	SDL_Texture* guiHealth20;
	SDL_Texture* guiHealth10;
	SDL_Texture* guiHealth0;

	//Workshop Health
	SDL_Texture* guiWHealth100;
	SDL_Texture* guiWHealth90;
	SDL_Texture* guiWHealth80;
	SDL_Texture* guiWHealth70;
	SDL_Texture* guiWHealth60;
	SDL_Texture* guiWHealth50;
	SDL_Texture* guiWHealth40;
	SDL_Texture* guiWHealth30;
	SDL_Texture* guiWHealth20;
	SDL_Texture* guiWHealth10;
	SDL_Texture* guiWHealth0;

	//Objects
	SDL_Texture* objectHouse;
	SDL_Texture* objectBarriers;
	SDL_Texture* objectBarriers2;
	SDL_Texture* objectBarriers3;
	SDL_Texture* objectBarriersClear;
	SDL_Texture* objectTurret;
	SDL_Texture* objectTurretClear;
	SDL_Texture* objectTree;
	SDL_Texture* objectCandyCane;


	// Debug Sounds
	Mix_Chunk* testSound;
	Mix_Chunk* soundHitMarker;
	Mix_Chunk* soundBang;
	Mix_Chunk* sounddeath;
	Mix_Chunk* soundsnowdeath;

	// Debug Music
	Mix_Music* testMusic;
	Mix_Music* testMusicPlz;

};

extern Resources resources;