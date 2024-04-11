#include <regex>
#include "AppConfig.h"

namespace App {

	AppConfig::AppConfig() {}

	AppConfig* AppConfig::_singleton = nullptr;

	AppConfig* AppConfig::getInstance()
	{
		if (!_singleton)
			_singleton = new AppConfig();
		return _singleton;
	}

	AppConfig* AppConfig::parseArgs(int argc, char* argv[])
	{
		using std::string;
		if (argc < 2)
		{
			printf("Missing image filepath. Use 'img2ascii sample.png'");
			return nullptr;
		}

		AppConfig* config = AppConfig::getInstance();
		config->setConfig(argv[1], Default);

		using std::regex, std::regex_match;
		regex r("^((?:-)([a-zA-Z])|(?:--)([a-zA-Z]{2,}))$");

		int p = 2;
		while (p < argc) 
		{
			if (regex_match(argv[p], r))
			{
				if (config->commands.find(argv[p]) != config->commands.end())
				{ 
					config->commands.at(argv[p])(config);
				}
				else {
					printf("%s is not a valid option\n", argv[p]);
					return nullptr;
				}
			}
			else {
				printf("Unknown argument %s.\n", argv[p]);
			}
			p += 1;
		}

		return config;
	}

	void AppConfig::setConfig(const char* filepath, Palette palette)
	{
		this->filepath = filepath;
		this->palette = App::palettes[palette];
	}

	const string& AppConfig::getImageFilepath() const { return filepath; }
	const string& AppConfig::getPalette() const { return palette; }
	bool AppConfig::getAsFile() const { return as_file; }


}