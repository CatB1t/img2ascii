#pragma once

#include <string>

using std::string;

class Image {
private:
	string path;
	string palette;
	int width = 0, height = 0, channels = 0;
	unsigned char* data = nullptr;
public:
	Image(string path, string palette);
	~Image();

	string convert();
};
