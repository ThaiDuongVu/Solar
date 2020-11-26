#include "font.h"

namespace solar
{
	Font::Font(const char* path, int width, int height)
	{
		this->path_ = path;

		this->width_ = width;
		this->height_ = height;
	}
	Font::~Font()
	{

	}
} // namespace solar
