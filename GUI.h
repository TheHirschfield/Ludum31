#pragma once
class GUI
{
public:

	enum menu_buttons_t { PLAY, INSTRUCTIONS, OPTIONS, EXIT, GAME_MENU, BACK};
	bool buttonAvailiable;

	GUI();
	~GUI();

	void logic();
	void render();
	void addButton(menu_buttons_t name, int placementX, int placementY);
};
extern GUI gui;
