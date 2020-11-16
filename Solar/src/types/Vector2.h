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

		double x = 0.0f; // a value of vector
		double y = 0.0f; // b value of vector

		double Length();	  // Length of the vector
		double Distance(Vector2 other); // Distance to another vector
		double Dot(Vector2 other); // Dot product of this vector and another vector
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

		static Vector2 Zero(); // (0.0f, 0.0f) vector
		static Vector2 Identity(); // (1.0f, 1.0f) vector

		static double Length(Vector2 a); // Length of a vector
		static double Distance(Vector2 a, Vector2 b); // Distance between 2 vectors
		static double Dot(Vector2 a, Vector2 b); // Dot product of 2 vectors
		static Vector2 Normalized(Vector2 a); // Vector normalized so that its length is 1
	};
} // namespace solar

#endif // !SOLAR_VECTOR2_H_