#include <iostream>

#include "Image.h"
#include "AppConfig.h"

int main(int argc, char* argv[])
{
	App::AppConfig* config = App::AppConfig::parseArgs(argc, argv);
	if (!config)
		return -1;
	Image img = Image(config->getImageFilepath(), config->getPalette());
	std::cout << img.convert();
	return 0;
}
