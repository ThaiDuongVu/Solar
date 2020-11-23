#include "text.h"
#include "../debug.h"
#include <ft2build.h>
#include FT_FREETYPE_H

namespace solar
{
	Text::Text(const char* text, Color color, Transform transform)
	{
		this->text_ = text;
		this->color_ = color;
		this->transform_ = transform;

		// Initialize FreeType library
		FT_Library ft;
		if (FT_Init_FreeType(&ft))
		{
			Debug::LogError("Failed to initialize FreeType");
			return;
		}
	}
	Text::~Text()
	{

	}

	void Text::Render()
	{
	}
} // namespace solar