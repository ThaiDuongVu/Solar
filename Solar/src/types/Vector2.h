#pragma once

#ifndef SOLAR_VECTOR2_H_
#define SOLAR_VECTOR2_H_

#include "../core.h"

namespace solar
{
	class SOLAR_API Vector2
	{
	public:
		// Constructor and destructor
		Vector2(double x = 0.0f, double y = 0.0f);
		~Vector2();

		double x = 0.0f; // x value of vector
		double y = 0.0f; // y value of vector

		static Vector2 Zero(); // (0.0f, 0.0f) vector
		static Vector2 Identity(); // (1.0f, 1.0f) vector

		double Length();	  // Length of the vector
		Vector2 Normalized(); // Vector normalized so that its length is 1

#pragma region Operators
		Vector2 operator+(Vector2 other);
		Vector2 operator-(Vector2 other);
		Vector2 operator*(Vector2 other);
		Vector2 operator/(Vector2 other);

		Vector2 operator+(double other);
		Vector2 operator-(double other);
		Vector2 operator*(double other);
		Vector2 operator/(double other);
#pragma endregion
	};
} // namespace solar

#endif // !SOLAR_VECTOR2_H_