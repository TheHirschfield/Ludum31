#include "Options.h"
#include "Debug.h"

Options::Options()
{
}
Options::~Options()
{
}

void Options::read(){
	debug.report("Ludum Dare 23 is Reading Options: ");

	string optionsLine;
	std::ifstream optionsFile("options.txt");

	while (!optionsFile.eof()){
		getline(optionsFile, optionsLine);
		std::string temp = "";

		if (optionsLine[0] == '#'){
			debug.report("Pick Uped On #");
		}
		else if (optionsLine[0] == '1'){
			
		}
		else if (optionsLine[0] == '2')
		{
			
		}
		else if (optionsLine[0] == '3')
		{
			
		}


	}
	debug.report("Ludum Dare 23 Finished Reading Options!");

}