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
		Color32(int r = 0, int g = 0, int b = 0, int a = 255);
		~Color32();

		int r_ = 0;	 // Red
		int g_ = 0;	 // Green
		int b_ = 0;	 // Blue
		int a_ = 255; // Apha

		Color Normalize(); // Convert this 32-bit Color type to Color type and clamp all values to be between 0 and 1
		std::string ToString(); // Convert this color_ to string for debugging & printing

#pragma region Arithmetic Operators
		Color32 operator+(Color32 other);
		Color32 operator-(Color32 other);
		Color32 operator*(Color32 other);
		Color32 operator/(Color32 other);
			 
		Color32 operator+=(Color32 other);
		Color32 operator-=(Color32 other);
		Color32 operator*=(Color32 other);
		Color32 operator/=(Color32 other);
			 
		Color32 operator+(int other);
		Color32 operator-(int other);
		Color32 operator*(int other);
		Color32 operator/(int other);
			 
		Color32 operator+=(int other);
		Color32 operator-=(int other);
		Color32 operator*=(int other);
		Color32 operator/=(int other);
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
		static std::string ToString(Color32 color); // Convert a color_ to string for debugging & printing
	};
} // namespace solar

#endif // !SOLAR_COLOR32_H_