#pragma once

#include "../Core.h"

namespace Solar
{
	class SOLAR_API Color
	{
	public:
		// Constructor and destructor
		Color(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f);
		~Color();

		float r = 0.0f;
		float g = 0.0f;
		float b = 0.0f;
		float a = 1.0f;

		Color Normalize();

	private:
		void Clamp(float& value); // Limit the color range to 0-255
	};
};

