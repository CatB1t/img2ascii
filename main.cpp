#include <iostream>
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