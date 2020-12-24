#pragma once

#ifndef SOLAR_FONT_H_
#define SOLAR_FONT_H_

#include "../core.h"
#include "../debug.h"

namespace solar
{
	class SOLAR_API Font
	{
	public:
		// Constructor
		Font(const char* path = "./resources/font.ttf", int width = 0, int height = 48);
		// Destructor
		~Font();

		// Path to font
		const char* path;

		// Font width
		int width;
		// Font height
		int height;
	};
} // namespace solar

#endif // !SOLAR_FONT_H_