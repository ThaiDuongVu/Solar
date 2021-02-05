#pragma once

#ifndef SOLAR_COLOR32_H_
#define SOLAR_COLOR32_H_

#include "../core.h"
#include "color.h"
#include <string>

namespace Solar
{
	class SOLAR_API Color32
	{
	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="r">Initial red value</param>
		/// <param name="g">Initial green value</param>
		/// <param name="b">Initial blue value</param>
		/// <param name="a">Initial alpha value</param>
		Color32(unsigned int r = 0, unsigned int g = 0, unsigned int b = 0, unsigned int a = 255);
		/// <summary>
		/// Destructor.
		/// </summary>
		~Color32();

		/// <summary>
		/// Red value.
		/// </summary>
		unsigned int r = 0;
		/// <summary>
		/// Green value.
		/// </summary>
		unsigned int g = 0;
		/// <summary>
		/// Blue value.
		/// </summary>
		unsigned int b = 0;
		/// <summary>
		/// Apha value.
		/// </summary>
		unsigned int a = 255;

		/// <summary>
		/// Convert this 32-bit Color type to Color type and clamp all values to be between 0 and 1.
		/// </summary>
		/// <returns>Normalized color</returns>
		Color Normalize();
		/// <summary>
		/// Convert this color to string.
		/// </summary>
		/// <returns>Color in string format</returns>
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

		/// <summary>
		/// Convert a 32-bit Color type to Color type and clamp all values to be between 0 and 1.
		/// </summary>
		/// <param name="color">Color to normalize</param>
		/// <returns>Normalized color</returns>
		static Color Normalize(Color32 color);
		/// <summary>
		/// Convert a color to string.
		/// </summary>
		/// <param name="color">Color to convert</param>
		/// <returns>Color in string format</returns>
		static std::string ToString(Color32 color);

		// Some handy default color values

		static Color32 Red();
		static Color32 Green();
		static Color32 Blue();
		static Color32 Yellow();
		static Color32 Pink();
		static Color32 Teal();
		static Color32 White();
		static Color32 Black();
	};
} // namespace Solar

#endif // !SOLAR_COLOR32_H_