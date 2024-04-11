#pragma once

#include <map>
#include <functional>
#include <string>

using std::map, std::function;
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
		bool as_file = false;

		map<string, function<void(AppConfig*)>> commands
		{
			{"--binary", setPaletteAsBinary},
			{"--asfile", setAsFile}
		};
		AppConfig();

		static void setAsFile(AppConfig* cfg) { cfg->as_file = true; };
		static void setPaletteAsBinary(AppConfig* cfg) { cfg->palette = palettes[Binary]; };

	public:
		AppConfig(AppConfig& other) = delete;
		void operator=(const AppConfig& other) = delete;

		void setConfig(const char* filepath, Palette palette);
		const string& getImageFilepath() const;
		const string& getPalette() const;

		static AppConfig* getInstance();
		static AppConfig* parseArgs(int argc, char* argv[]);
	};
}
