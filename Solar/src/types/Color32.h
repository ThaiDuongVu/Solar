#pragma once

#ifndef SOLAR_COLOR32_H_
#define SOLAR_COLOR32_H_

#include "../core.h"
#include "color.h"

namespace solar
{
	class SOLAR_API Color32
	{
	public:
		// Constructor and destructor
		Color32(int r = 0, int g = 0, int b = 0, int a = 255);
		~Color32();

		int r = 0;	 // Red
		int g = 0;	 // Green
		int b = 0;	 // Blue
		int a = 255; // Apha

		Color Normalize(); // Convert 32-bit type to Color type
	};
} // namespace solar

#endif // !SOLAR_COLOR32_H_