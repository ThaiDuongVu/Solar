#include "font.h"

namespace Solar
{
	Font::Font(const char* path, int width, int height)
	{
		this->path = path;

		this->width = width;
		this->height = height;
	}
	Font::~Font()
	{

	}
} // namespace Solar
