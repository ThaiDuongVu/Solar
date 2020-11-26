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
		// Constructor and destructor
		Color32(unsigned int r = 0, unsigned int g = 0, unsigned int b = 0, unsigned int a = 255);
		~Color32();

		unsigned int r_ = 0;	 // Red
		unsigned int g_ = 0;	 // Green
		unsigned int b_ = 0;	 // Blue
		unsigned int a_ = 255; // Apha

		Color Normalize(); // Convert this 32-bit Color type to Color type and clamp all values to be between 0 and 1
		std::string ToString(); // Convert this color_ to string for debugging & prunsigned inting

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

		static Color Normalize(Color32 color); // Convert a 32-bit Color type to Color type and clamp all values to be between 0 and 1
		static std::string ToString(Color32 color); // Convert a color_ to string for debugging & prunsigned inting

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