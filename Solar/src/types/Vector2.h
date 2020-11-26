#pragma once

#ifndef SOLAR_VECTOR2_H_
#define SOLAR_VECTOR2_H_

#include "../core.h"
#include <string>

namespace solar
{
	class SOLAR_API Vector2
	{
	public:
		// Constructor and destructor
		Vector2(double x = 0.0f, double y = 0.0f);
		~Vector2();

		double x_ = 0.0f; // x value of vector
		double y_ = 0.0f; // y value of vector

		double Length();	  // Length of the vector
		double Distance(Vector2 other); // Distance to another vector
		double Dot(Vector2 other); // Dot product of this vector and another vector
		Vector2 Normalized(); // Vector normalized so that its length is 1

		std::string ToString(); // Convert this vector to string for debugging & printing

#pragma region Arithmetic Operators
		Vector2 operator+(Vector2 other);
		Vector2 operator-(Vector2 other);
		Vector2 operator*(Vector2 other);
		Vector2 operator/(Vector2 other);

		Vector2 operator+=(Vector2 other);
		Vector2 operator-=(Vector2 other);
		Vector2 operator*=(Vector2 other);
		Vector2 operator/=(Vector2 other);

		Vector2 operator+(double other);
		Vector2 operator-(double other);
		Vector2 operator*(double other);
		Vector2 operator/(double other);

		Vector2 operator+=(double other);
		Vector2 operator-=(double other);
		Vector2 operator*=(double other);
		Vector2 operator/=(double other);
#pragma endregion

#pragma region Logical Operators
		bool operator==(Vector2 other);
		bool operator!=(Vector2 other);
		bool operator>(Vector2 other);
		bool operator<(Vector2 other);
		bool operator>=(Vector2 other);
		bool operator<=(Vector2 other);
#pragma endregion

		static Vector2 Zero(); // (0.0f, 0.0f) vector
		static Vector2 Identity(); // (1.0f, 1.0f) vector
		static Vector2 UnitX(); // (1.0f, 0.0f) vector
		static Vector2 UnitY(); // (0.0f, 1.0f) vector

		static double Length(Vector2 a); // Length of a vector
		static double Distance(Vector2 a, Vector2 b); // Distance between 2 vectors
		static double Dot(Vector2 a, Vector2 b); // Dot product of 2 vectors
		static Vector2 Normalized(Vector2 a); // Vector normalized so that its length is 1

		static std::string ToString(Vector2 a); // Convert a vector to string for debugging & printing
	};
} // namespace solar

#endif // !SOLAR_VECTOR2_H_