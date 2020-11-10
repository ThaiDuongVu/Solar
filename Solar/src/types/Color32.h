#pragma once

#include "../Core.h"
#include "Color.h"

namespace Solar
{
	class SOLAR_API Color32
	{
	public:
		// Constructor and destructor
		Color32(int r = 0, int g = 0, int b = 0, int a = 255);
		~Color32();

		int r = 0;
		int g = 0;
		int b = 0;
		int a = 255;

		Color Normalize(); // Convert 32-bit type to Color type
	};
};

