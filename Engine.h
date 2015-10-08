#pragma once
class Engine
{
public:

	static float deltaTime;

	//Mouse 
	int mouseX;
	int mouseY;
	int mouseLeftClick;
	int mouseCooldown;

	// Movement Commands
	bool keyW;
	bool keyA;
	bool keyS;
	bool keyD;

	//Other Player Commands
	bool keyE;

	//GUI Interation
	bool keyReturn;
	bool keyEsc;

	bool key1;
	bool key2;
	bool key3;
	bool key4;
	bool key5;
	bool key6;
	bool key7;
	bool key8;
	bool key9;
	bool key0;

	bool keyF1;
	bool keyF2;
	bool keyF3;
	bool keyF4;
	bool keyF5;
	bool keyF6;
	bool keyF7;
	bool keyF8;
	bool keyF9;
	bool keyF10;
	bool keyF11;
	bool keyF12;

	Engine();
	~Engine();

	void events();
	void controls();
	void mouseEvents();

	void addCooldown(int cooldown);

};

extern Engine engine;