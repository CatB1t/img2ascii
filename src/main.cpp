#include <iostream>
#include <regex>
#include <map>

#include "Image.h"
#include "AppConfig.h"

int main()
{
	App::AppConfig* config = App::AppConfig::getInstance();
	config->setConfig("sample.png", App::Palette::Default);
	Image img = Image(config->getImageFilepath(), config->getPalette());
	std::cout << img.convert();
	return 0;
}

/*
int main(int argc, char* argv[])
{

	std::map<std::string, std::string> commands;
	commands.insert(std::make_pair<std::string, std::string>("--help", "Help!"));
	commands.insert(std::make_pair<std::string, std::string>("-h", "Help!"));
	commands.insert(std::make_pair<std::string, std::string>("-m", "mask!"));
	commands.insert(std::make_pair<std::string, std::string>("--mask", "mask!"));

	std::map<std::string, std::string> argument;
	argument.insert(std::make_pair<std::string, std::string>("-o", "output!"));
	argument.insert(std::make_pair<std::string, std::string>("--output", "output!"));

	using std::regex, std::regex_match;
	regex r("^((?:-)([a-zA-Z])|(?:--)([a-zA-Z]{2,}))$");
	int p = 1;
	std::cout << argc << "\n";
	while (p < argc) {
		std::cout << std::boolalpha;
		std::cout << argv[p] << "\n";
		if (regex_match(argv[p], r))
		{
			if (commands.find(argv[p]) != commands.end())
			{ 
				std::cout << "You asking for command: " << commands.at(argv[p]) << "\n";
				p += 1;
				continue;
			}

			if (argument.find(argv[p]) != argument.end())
			{ 
				std::cout << "You asking for argument: " << argument.at(argv[p]) << "\n";

				if (p + 1 >= argc)
				{
					std::cout << "Missing argument value";
					break;
				}
				else {
					std::cout << "You entered value for argument: " << argv[p + 1];
				}
				p += 2;
				continue;
			}
		}
		else {
			std::cout << "You entered an invalid value!\n";
		}
		p += 1;
	}
	return 0;
}
*/
