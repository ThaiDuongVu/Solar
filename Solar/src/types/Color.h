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
		// Constructor
		Color(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f);
		// Destructor
		~Color();

		// Red value
		float r = 0.0f;
		// Green value
		float g = 0.0f;
		// Blue value
		float b = 0.0f;
		// Alpha value
		float a = 1.0f;

		// Clamp all values of this color to be between 0 and 1
		Color Normalize();
		// Convert this color to string
		std::string ToString();

#pragma region Arithmetic Operators
		Color operator+(Color other);
		Color operator-(Color other);
		Color operator*(Color other);
		Color operator/(Color other);

		Color operator+=(Color other);
		Color operator-=(Color other);
		Color operator*=(Color other);
		Color operator/=(Color other);

		Color operator+(float other);
		Color operator-(float other);
		Color operator*(float other);
		Color operator/(float other);

		Color operator+=(float other);
		Color operator-=(float other);
		Color operator*=(float other);
		Color operator/=(float other);
#pragma endregion Peform arithmetic operations and return an UNCLAMPED color

#pragma region Logical Operators
		bool operator==(Color other);
		bool operator!=(Color other);
		bool operator>(Color other);
		bool operator>=(Color other);
		bool operator<(Color other);
		bool operator<=(Color other);
#pragma endregion

		// Clamp all values of a color to be between 0 and 1
		static Color Normalize(Color color);
		// Convert a color to string
		static std::string ToString(Color color);

		// Handy default color values
		static Color Red();
		static Color Green();
		static Color Blue();
		static Color Yellow();
		static Color Pink();
		static Color Teal();
		static Color White();
		static Color Black();
	};
} // namespace solar

#endif // !SOLAR_COLOR_H_