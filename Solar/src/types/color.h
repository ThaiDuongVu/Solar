#pragma once

#ifndef SOLAR_COLOR_H_
#define SOLAR_COLOR_H_

#include "../core.h"
#include <string>

namespace Solar
{
	class SOLAR_API Color
	{
	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="r">Initial red value</param>
		/// <param name="g">Initial green value</param>
		/// <param name="b">Initial blue value</param>
		/// <param name="a">Initial alpha value</param>
		Color(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f);
		/// <summary>
		/// Destructor.
		/// </summary>
		~Color();

		/// <summary>
		/// Red value.
		/// </summary>
		float r = 0.0f;
		/// <summary>
		/// Green value.
		/// </summary>
		float g = 0.0f;
		/// <summary>
		/// Blue value
		/// </summary>
		float b = 0.0f;
		/// <summary>
		/// Alpha value.
		/// </summary>
		float a = 1.0f;

		/// <summary>
		/// Clamp all values of this color to be between 0 and 1.
		/// </summary>
		/// <returns>Normalized color</returns>
		Color Normalize();
		/// <summary>
		/// Convert this color to string.
		/// </summary>
		/// <returns>Color in string format</returns>
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

		/// <summary>
		/// Clamp all values of a color to be between 0 and 1.
		/// </summary>
		/// <param name="color">Color to normalize</param>
		/// <returns>Normalized color</returns>
		static Color Normalize(Color color);
		/// <summary>
		/// Convert a color to string.
		/// </summary>
		/// <param name="color">Color to convert</param>
		/// <returns>Color in string format</returns>
		static std::string ToString(Color color);

		// Some handy default color values

		static Color Red();
		static Color Green();
		static Color Blue();
		static Color Yellow();
		static Color Pink();
		static Color Teal();
		static Color White();
		static Color Black();
	};
} // namespace Solar

#endif // !SOLAR_COLOR_H_