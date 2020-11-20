#pragma once

#ifndef SOLAR_COLOR_H_
#define SOLAR_COLOR_H_

#include "../core.h"
#include <string>

namespace solar
{
	class SOLAR_API Color
	{
	public:
		// Constructor and destructor
		Color(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f);
		~Color();

		float r = 0.0f; // Red
		float g = 0.0f; // Green
		float b = 0.0f; // Blue
		float a = 1.0f; // Alpha

		Color Normalize(); // Clamp all values of this color to be between 0 and 1
		std::string ToString(); // Convert this color to string for debugging & printing

		static Color Normalize(Color color); // Clamp all values of a color to be between 0 and 1
		static std::string ToString(Color color); // Convert a color to string for debugging & printing
	};
} // namespace solar

#endif // !SOLAR_COLOR_H_