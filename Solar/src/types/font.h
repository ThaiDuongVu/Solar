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
		Font(const char* path = "../../resources/font.ttf", int width = 0, int height = 48);
		~Font();

		const char* path_;

		int width_;
		int height_;
	};
} // namespace solar

#endif // !SOLAR_FONT_H_