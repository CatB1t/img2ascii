#pragma once

#include <map>
#include <string>

using std::map;
using std::string;
using std::string_view;

namespace App {
	enum Palette {
		Default,
		Binary
	};

	inline std::map<Palette, string> palettes {
		{Default, " .:-=+*#%@"},
		{Binary, "     @@@@@"},
	};

class AppConfig {
	private:
		static AppConfig* _singleton;
		string filepath;
		string palette;
		AppConfig();
	public:
		AppConfig(AppConfig& other) = delete;
		void operator=(const AppConfig& other) = delete;

		void setConfig(const char* filepath, Palette palette);
		const string& getImageFilepath() const;
		const string& getPalette() const;

		static AppConfig* getInstance();
	};
}
