#include "Resources.h"
#include "Graphics.h"
#include "Debug.h"


Resources::Resources()
{
}

Resources::~Resources()
{
}

void Resources::loadImages(){

	debug.report("Game is Starting to Load Image Resources: ");

	// Debug Images 
	testImage = graphics.loadImage("Assets/test.png");

	// Core Images
	coreLogo = graphics.loadImage("Assets/logo.png");

	// Menu Graphics
	menuBackground = graphics.loadImage("Assets/Game/Maps/background3.png");
	menuMainPlay = graphics.loadImage("Assets/Menu/playButton.png");
	menuMainInstructions = graphics.loadImage("Assets/Menu/playInstructions.png");
	menuMainOptions = graphics.loadImage("Assets/Menu/playOptions.png");
	menuMainExit = graphics.loadImage("Assets/Menu/playExit.png");
	menuMainGameOver = graphics.loadImage("Assets/Menu/GameOver.png");
	menuMainBack = graphics.loadImage("Assets/Menu/playBack.png");

	//Game Menu
	menuGameCore = graphics.loadImage("Assets/Menu/test.png");
	menuGameInstructions = graphics.loadImage("Assets/Menu/test.png");
	menuGameOptions = graphics.loadImage("Assets/Menu/credits.png");
	menuGameExit = graphics.loadImage("Assets/Menu/test.png");

	//Player
	playeridle1 = graphics.loadImage("Assets/Game/Player/player1.png");

	// Items
	itemTier1Gun = graphics.loadImage("Assets/Game/Items/tier2Gun.png");
	itemTier2Gun = graphics.loadImage("Assets/Game/Items/tier2Gun.png");
	itemTier3Gun = graphics.loadImage("Assets/Game/Items/tier2Gun.png");
	itemParcel = graphics.loadImage("Assets/Game/Items/parcel.png");
	itemController = graphics.loadImage("Assets/Game/Items/controller.png");

	//Item Effects
	itemTier1Effect = graphics.loadImage("Assets/Game/Effects/tier1Blast.png");

	// Entites
	entitySnowman = graphics.loadImage("Assets/Game/Entities/enemySnowman.png");
	entitySnowman2 = graphics.loadImage("Assets/Game/Entities/enemySnowPilot.png");
	entitybomb = graphics.loadImage("Assets/Game/Entities/DaBomb.png");

	//Map Backgrounds
	mapBackground1 = graphics.loadImage("Assets/Game/Maps/background4.png");
	mapBackground2 = graphics.loadImage("Assets/Game/Maps/background4.png");
	mapBackground3 = graphics.loadImage("Assets/Game/Maps/test.png");
	mapBackground4 = graphics.loadImage("Assets/Game/Maps/test.png");

	//GUI
	guiWaveNotification = graphics.loadImage("Assets/Game/GUI/notifications.png");
	guiHitMarker = graphics.loadImage("Assets/Game/Effects/hitMarker.png");

	guiMoney0 = graphics.loadImage("Assets/Game/GUI/Workshop/money0.png");
	guiMoneyOverlay = graphics.loadImage("Assets/Game/GUI/Workshop/moneyOverlay.png");

	//Action Bar
	guiActionBar = graphics.loadImage("Assets/Game/GUI/actionBar.png");
	guiActionBarNum = graphics.loadImage("Assets/Game/GUI/actionBarNum.png");
	guiHighlight = graphics.loadImage("Assets/Game/GUI/Items/selection.png");
	guiAvailable = graphics.loadImage("Assets/Game/GUI/Items/notAvailable.png");
	guiHighlightOff = graphics.loadImage("Assets/Game/GUI/Items/selectionNot.png");

	//GUI Objects
	guiDebug = graphics.loadImage("Assets/Game/GUI/Items/itemdebug.png");
	guiPeaShooter = graphics.loadImage("Assets/Game/GUI/Items/Gun.png");
	guiPeaShooter2 = graphics.loadImage("Assets/Game/GUI/Items/peaShooter2.png");
	guiPeaShooter3 = graphics.loadImage("Assets/Game/GUI/Items/peaShooter3.png");
	guiBlock = graphics.loadImage("Assets/Game/GUI/Items/Block.png");
	guiTurret = graphics.loadImage("Assets/Game/GUI/Items/Turret.png");
	guiCandyShower = graphics.loadImage("Assets/Game/GUI/Items/candyShower.png");
	guiCoaltaPult = graphics.loadImage("Assets/Game/GUI/Items/coaltaPult.png");
	guiPresentBomb = graphics.loadImage("Assets/Game/GUI/Items/presentBomb.png");
	guiSantaBomb = graphics.loadImage("Assets/Game/GUI/Items/santaBomb.png");
	guiOrbitalCanon = graphics.loadImage("Assets/Game/GUI/Items/orbitalCanon.png");

	guiWaveIncoming = graphics.loadImage("Assets/Game/GUI/Waves/waveInc.png");

	//GUI Health
	guiHealth100 = graphics.loadImage("Assets/Game/GUI/health100.png");
	guiHealth90 = graphics.loadImage("Assets/Game/GUI/health90.png");
	guiHealth80 = graphics.loadImage("Assets/Game/GUI/health80.png");
	guiHealth70 = graphics.loadImage("Assets/Game/GUI/health70.png");
	guiHealth60 = graphics.loadImage("Assets/Game/GUI/health60.png");
	guiHealth50 = graphics.loadImage("Assets/Game/GUI/health50.png");
	guiHealth40 = graphics.loadImage("Assets/Game/GUI/health40.png");
	guiHealth30 = graphics.loadImage("Assets/Game/GUI/health30.png");
	guiHealth20 = graphics.loadImage("Assets/Game/GUI/health20.png");
	guiHealth10 = graphics.loadImage("Assets/Game/GUI/health10.png");
	guiHealth0 = graphics.loadImage("Assets/Game/GUI/health0.png");

	//Workshop Health
	guiWHealth100 = graphics.loadImage("Assets/Game/GUI/Workshop/health100.png");
	guiWHealth90 = graphics.loadImage("Assets/Game/GUI/Workshop/health90.png");
	guiWHealth80 = graphics.loadImage("Assets/Game/GUI/Workshop/health80.png");
	guiWHealth70 = graphics.loadImage("Assets/Game/GUI/Workshop/health70.png");
	guiWHealth60 = graphics.loadImage("Assets/Game/GUI/Workshop/health60.png");
	guiWHealth50 = graphics.loadImage("Assets/Game/GUI/Workshop/health50.png");
	guiWHealth40 = graphics.loadImage("Assets/Game/GUI/Workshop/health40.png");
	guiWHealth30 = graphics.loadImage("Assets/Game/GUI/Workshop/health30.png");
	guiWHealth20 = graphics.loadImage("Assets/Game/GUI/Workshop/health20.png");
	guiWHealth10 = graphics.loadImage("Assets/Game/GUI/Workshop/health10.png");
	guiWHealth0 = graphics.loadImage("Assets/Game/GUI/Workshop/health0.png");


	//Objects
	objectHouse = graphics.loadImage("Assets/Game/Objects/objectWorkshop2.png");
	objectBarriers = graphics.loadImage("Assets/Game/Objects/objectBarrier.png");
	objectBarriers2 = graphics.loadImage("Assets/Game/Objects/objectBarrier2.png");
	objectBarriers3 = graphics.loadImage("Assets/Game/Objects/objectBarrier3.png");
	objectBarriersClear = graphics.loadImage("Assets/Game/Objects/objectBarrier3Clear.png");
	objectTree = graphics.loadImage("Assets/Game/Objects/tree1.png");
	objectCandyCane = graphics.loadImage("Assets/Game/Objects/candyCane.png");
	objectTurret = graphics.loadImage("Assets/Game/Objects/freedomCannon.png");
	objectTurretClear = graphics.loadImage("Assets/Game/Objects/freedomCannonClear.png");


	debug.report("Game Has Finished Loading Image Resources.");
}

void Resources::loadSounds(){
	debug.report("Game is Starting to Load Sound Resources: ");
		testSound = Mix_LoadWAV("Assets/Sounds/test.wav");
		soundHitMarker = Mix_LoadWAV("Assets/Sounds/hitMarker.wav");
		sounddeath = Mix_LoadWAV("Assets/Sounds/death.wav");
		soundsnowdeath = Mix_LoadWAV("Assets/Sounds/deathsnow.wav");
		
		soundBang = Mix_LoadWAV("Assets/Sounds/bang.wav");

		testMusic = Mix_LoadMUS("Assets/Sounds/music.ogg");
		testMusicPlz = Mix_LoadMUS("Assets/Sounds/nextLevel.ogg");
	debug.report("Game Has Finished Loading Sounds Resources.");
}

Resources resources;