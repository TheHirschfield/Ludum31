#pragma once
class Menu
{
public:
	int currentMenu;
	int currentOption;
	bool gameMenu;

	Menu();
	~Menu();
	
	void logic();
	void render();
};
extern Menu menu;