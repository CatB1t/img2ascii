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

	void AppConfig::setConfig(const char* filepath, Palette palette)
	{
		this->filepath = filepath;
		this->palette = App::palettes[palette];
	}

	const string& AppConfig::getImageFilepath() const { return filepath; }

	const string& AppConfig::getPalette() const { return palette; }


}