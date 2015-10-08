#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::string;

class Debug
{
public:

	Debug();
	~Debug();

	bool mode;

	void report(string command);
	void report(int command);
	void report(float command);
	void report(string command, int command2);
	void report(string command, string command2);
	void report(string command, int command2, string command3);
	void report(string command, string command2, string command3);
	void report(string command, int command2, int command3);
	void report(string command, int command2, int command3, int command4);

	void checkCommands();

};

extern Debug debug;