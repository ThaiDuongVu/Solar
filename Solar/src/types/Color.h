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

		float r_ = 0.0f; // Red
		float g_ = 0.0f; // Green
		float b_ = 0.0f; // Blue
		float a_ = 1.0f; // Alpha

		Color Normalize(); // Clamp all values of this color_ to be between 0 and 1
		std::string ToString(); // Convert this color_ to string for debugging & printing

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

		static Color Normalize(Color color); // Clamp all values of a color_ to be between 0 and 1
		static std::string ToString(Color color); // Convert a color_ to string for debugging & printing
	};
} // namespace solar

#endif // !SOLAR_COLOR_H_