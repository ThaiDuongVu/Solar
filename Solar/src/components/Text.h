#pragma once

#ifndef SOLAR_TEXT_H_
#define SOLAR_TEXT_H_

#include "../core.h"
#include "../types/color.h"
#include "../types/color32.h"
#include "../types/transform.h"
#include <string>

namespace solar
{
	class SOLAR_API Text
	{
	public:
		// Constructor & destrutor
		Text(const char* text = "", Color color = Color(255, 255, 255, 255), Transform transform = Transform::Default());
		~Text();

		const char* text_ = ""; // Text string
		Color color_; // Text color_
		Color32 color_32_; // Text color_ (32-bit)
		Transform transform_; // Text transform_

		void Render(); // Render text_ on screen
	};
} // namespace solar

#endif // !SOLAR_TEXT_H_