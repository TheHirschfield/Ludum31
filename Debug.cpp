#include "Debug.h"
#include "Engine.h"
#include "Entity.h"
#include "Map.h"
#include "Player.h"
#include "Workshop.h"

int debugCount = 0;

Debug::Debug()
{
}
Debug::~Debug()
{
}

void Debug::report(string command){
	debugCount++;
	cout << debugCount << ": " << command << "\n";
}

void Debug::report(int command){
	debugCount++;
	cout << debugCount << ": " << command << "\n";
}

void Debug::report(float command){
	debugCount++;
	cout << debugCount << ": " << command << "\n";
}

void Debug::report(string command, string command2){
	debugCount++;
	cout << debugCount << ": " << command << command2 << "\n";
}

void Debug::report(string command, int command2){
	debugCount++;
	cout << debugCount << ": " << command << command2 << "\n";
}

void Debug::report(string command, string command2, string command3){
	debugCount++;
	cout << debugCount << ": " << command << command2 << command3 << "\n";
}

void Debug::report(string command, int command2, string command3){
	debugCount++;
	cout << debugCount << ": " << command << command2 << command3 << "\n";
}

void Debug::report(string command, int command2, int command3){

	cout << debugCount << ": " << command << command2 << " " << command3 << "\n";
}

void Debug::report(string command, int command2, int command3, int command4){
	debugCount++;
	cout << debugCount << ": " << command << command2 << command3 << command4 << "\n";
}

void Debug::checkCommands(){

	if(engine.keyF9){
		switch (mode){
		case true:
			mode = false;
			report("Debug Mode Now Off");
			break;
		case false:
			mode = true;
			report("Debug Mode Now On");
			break;
		}
	}

	if (engine.keyF8){

		report("The player Currently Has: ", player.currency);
	}

	if (engine.keyF7){

		for (int objectDebug = 0; objectDebug < 16; objectDebug++){

			if (map.objectType[objectDebug] != NULL){
				report("Object has Location On X: ", map.objectPosition[objectDebug]);

			}
		}
	}

	if (engine.keyF6){

		workshop.workshopHealth -= 950;
	}

	if (engine.keyF5){

		report("Added 50 To The Players Money");
		player.currency += 50;
	}


	if (engine.keyF4){
		report("Check Position Entity at: ", entity.positionEntityX[0]);
	}

}


Debug debug;