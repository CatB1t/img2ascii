#pragma once

#include <string>

class Image {
private:
	std::string path;
	int width = 0, height = 0, channels = 0;
	unsigned char* data = nullptr;
public:
	Image(const char* path);
	~Image();

	std::string convert();
};
