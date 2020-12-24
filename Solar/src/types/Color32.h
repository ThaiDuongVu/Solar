#pragma once

#ifndef SOLAR_COLOR32_H_
#define SOLAR_COLOR32_H_

#include "../core.h"
#include "color.h"
#include <string>

namespace solar
{
	class SOLAR_API Color32
	{
	public:
		// Constructor
		Color32(unsigned int r = 0, unsigned int g = 0, unsigned int b = 0, unsigned int a = 255);
		// Destructor
		~Color32();

		// Red value
		unsigned int r = 0;
		// Green value
		unsigned int g = 0;
		// Blue value
		unsigned int b = 0;
		// Apha value
		unsigned int a = 255;

		// Convert this 32-bit Color type to Color type and clamp all values to be between 0 and 1
		Color Normalize();
		// Convert this color to string
		std::string ToString();

#pragma region Arithmetic Operators
		Color32 operator+(Color32 other);
		Color32 operator-(Color32 other);
		Color32 operator*(Color32 other);
		Color32 operator/(Color32 other);

		Color32 operator+=(Color32 other);
		Color32 operator-=(Color32 other);
		Color32 operator*=(Color32 other);
		Color32 operator/=(Color32 other);

		Color32 operator+(unsigned int other);
		Color32 operator-(unsigned int other);
		Color32 operator*(unsigned int other);
		Color32 operator/(unsigned int other);

		Color32 operator+=(unsigned int other);
		Color32 operator-=(unsigned int other);
		Color32 operator*=(unsigned int other);
		Color32 operator/=(unsigned int other);
#pragma endregion Peform arithmetic operations and return an UNCLAMPED color

#pragma region Logical Operators
		bool operator==(Color32 other);
		bool operator!=(Color32 other);
		bool operator>(Color32 other);
		bool operator>=(Color32 other);
		bool operator<(Color32 other);
		bool operator<=(Color32 other);
#pragma endregion

		// Convert a 32-bit Color type to Color type and clamp all values to be between 0 and 1
		static Color Normalize(Color32 color);
		// Convert a color to string
		static std::string ToString(Color32 color);

		// Handy default color values
		static Color32 Red();
		static Color32 Green();
		static Color32 Blue();
		static Color32 Yellow();
		static Color32 Pink();
		static Color32 Teal();
		static Color32 White();
		static Color32 Black();
	};
} // namespace solar

#endif // !SOLAR_COLOR32_H_