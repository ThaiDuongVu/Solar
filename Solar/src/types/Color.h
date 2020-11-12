#pragma once

#ifndef SOLAR_COLOR_H_
#define SOLAR_COLOR_H_

#include "../core.h"

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

		Color Normalize();
	};
} // namespace solar

#endif // !SOLAR_COLOR_H_