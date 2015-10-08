#include "Engine.h"
#include "Game.h"
#include "Debug.h"

SDL_Event e;
const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
SDL_Point mousePosition;

float Engine::deltaTime;

int mouseX = 0;
int mouseY = 0;
int controlCooldown = 0;
int mouseCooldown = 0;

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::events(){

	controls();

	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			game.running = false;
		}
		mouseEvents();
	}

	if (mouseCooldown > 0){
		mouseCooldown--;
	}

}

void Engine::controls(){

	if (currentKeyStates[SDL_SCANCODE_W]){
		keyW = true;
	}
	else{
		keyW = false;
	}

	if (currentKeyStates[SDL_SCANCODE_A]){
		keyA = true;
	}
	else{
		keyA = false;
	}

	if (currentKeyStates[SDL_SCANCODE_S]){
		keyS = true;
	}
	else{
		keyS = false;
	}

	if (currentKeyStates[SDL_SCANCODE_D]){
		keyD = true;
	}
	else{
		keyD = false;
	}

	if (currentKeyStates[SDL_SCANCODE_E] && controlCooldown < 1){
		keyE = true;
		addCooldown(20);
	}
	else{
		keyE = false;
	}

	if (currentKeyStates[SDL_SCANCODE_RETURN] && controlCooldown < 1){
		keyReturn = true;
		addCooldown(20);
	}
	else{
		keyReturn = false;
	}

	if (currentKeyStates[SDL_SCANCODE_ESCAPE] && controlCooldown < 1){
		keyEsc = true;
		addCooldown(20);
	}
	else{
		keyEsc = false;
	}

	//Number Keys
	if (currentKeyStates[SDL_SCANCODE_1] && controlCooldown < 1){
		key1 = true;
		addCooldown(20);
	}
	else{
		key1 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_2] && controlCooldown < 1){
		key2 = true;
		addCooldown(20);
	}
	else{
		key2 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_3] && controlCooldown < 1){
		key3 = true;
		addCooldown(20);
	}
	else{
		key3 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_4] && controlCooldown < 1){
		key4 = true;
		addCooldown(20);
	}
	else{
		key4 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_5] && controlCooldown < 1){
		key5 = true;
		addCooldown(20);
	}
	else{
		key5 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_6] && controlCooldown < 1){
		key6 = true;
		addCooldown(20);
	}
	else{
		key6 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_7] && controlCooldown < 1){
		key7 = true;
		addCooldown(20);
	}
	else{
		key7 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_8] && controlCooldown < 1){
		key8 = true;
		addCooldown(20);
	}
	else{
		key8 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_9] && controlCooldown < 1){
		key9 = true;
		addCooldown(20);
	}
	else{
		key9 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_0] && controlCooldown < 1){
		key0 = true;
		addCooldown(20);
	}
	else{
		key0 = false;
	}

	//F Keys
	if (currentKeyStates[SDL_SCANCODE_F1] && controlCooldown < 1){
		keyF1 = true;
		addCooldown(60);
	}
	else{
		keyF1 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_F2] && controlCooldown < 1){
		keyF2 = true;
		addCooldown(60);
	}
	else{
		keyF2 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_F3] && controlCooldown < 1){
		keyF3 = true;
		addCooldown(60);
	}
	else{
		keyF3 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_F4] && controlCooldown < 1){
		keyF4 = true;
		addCooldown(60);
	}
	else{
		keyF4 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_F5] && controlCooldown < 1){
		keyF5 = true;
		addCooldown(60);
	}
	else{
		keyF5 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_F6] && controlCooldown < 1){
		keyF6 = true;
		addCooldown(60);
	}
	else{
		keyF6 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_F7] && controlCooldown < 1){
		keyF7 = true;
		addCooldown(60);
	}
	else{
		keyF7 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_F8] && controlCooldown < 1){
		keyF8 = true;
		addCooldown(60);
	}
	else{
		keyF8 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_F9] && controlCooldown < 1){
		keyF9 = true;
		addCooldown(60);
	}
	else{
		keyF9 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_F10] && controlCooldown < 1){
		keyF10 = true;
		addCooldown(60);
	}
	else{
		keyF10 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_F11] && controlCooldown < 1){
		keyF11 = true;
		addCooldown(60);
	}
	else{
		keyF11 = false;
	}
	if (currentKeyStates[SDL_SCANCODE_F12] && controlCooldown < 1){
		keyF12 = true;
		addCooldown(60);
	}
	else{
		keyF12 = false;
	}

	if (controlCooldown > 0){
		controlCooldown--;
	}

}

void Engine::mouseEvents(){

	mouseX = e.motion.x;
	mouseY = e.motion.y;
	mouseLeftClick = false;

	if (e.type == SDL_MOUSEBUTTONDOWN && mouseLeftClick == false){

		if (e.button.button == SDL_BUTTON_LEFT){
			mouseLeftClick = true;
			if (debug.mode){
				debug.report("Player Clicked: ", mouseX, mouseY);
			}
		}


	}
	else if (e.type == SDL_MOUSEBUTTONUP){
		mouseLeftClick = false;

	}

}

void Engine::addCooldown(int cooldown){
	controlCooldown = cooldown;
}

Engine engine;