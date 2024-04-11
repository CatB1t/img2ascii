#include <iostream>
#include <fstream>

#include "Image.h"
#include "AppConfig.h"

int main(int argc, char* argv[])
{
	App::AppConfig* config = App::AppConfig::parseArgs(argc, argv);
	if (!config)
		return -1;

	Image img = Image(config->getImageFilepath(), config->getPalette());
	if (config->getAsFile())
	{
		std::ofstream output_file;
		output_file.open("output.txt");
		output_file << img.convert();
		output_file.close();
	}
	else {
		std::cout << img.convert();
	}
	return 0;
}
