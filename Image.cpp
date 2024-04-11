#define DEBUG
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include "Image.h"

Image::Image(const char* path) :
	path(path)
{
	data = stbi_load(path, &width, &height, &channels, 0);
	if (!data)
		printf("Failed to load image from path %s", path);

	#ifdef DEBUG
		printf("Loaded image %s (%ix%ix%i).", path, width, height, channels);
	#endif
}

Image::~Image()
{
	stbi_image_free(data);
	data = nullptr;
}

std::string Image::convert()
{
	std::string ret = "";
	std::string palette = " .:-=+*#%@";

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			float pixelSum = 0;
			for (int k = 0; k < channels; ++k)
			{
				int ptr_pos = channels * (i * width + j) + k;
				pixelSum += data[ptr_pos] / 255.0f;
			}
			pixelSum /= channels;
			int pixelIndex = (int)(pixelSum * (palette.length() - 1));
			ret += palette[pixelIndex];
		}
		ret += "\n";
	}

	return ret;
}