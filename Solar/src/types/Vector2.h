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
		// Constructor
		Vector2(double x = 0.0f, double y = 0.0f);
		// Destructor
		~Vector2();

		// x value of vector
		double x = 0.0f;
		// y value of vector
		double y = 0.0f;

		// Length of the vector
		double Length();
		// Distance from this vector to another vector
		double Distance(Vector2 other);
		// Dot product of this vector and another vector
		double Dot(Vector2 other);
		// Vector normalized so that its length is 1
		Vector2 Normalized();

		// Convert this vector to string
		std::string ToString();

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

		// (0.0f, 0.0f) vector
		static Vector2 Zero();
		// (1.0f, 1.0f) vector
		static Vector2 Identity();
		// (1.0f, 0.0f) vector
		static Vector2 UnitX();
		// (0.0f, 1.0f) vector
		static Vector2 UnitY();

		// Directional vectors
		static Vector2 Up();
		static Vector2 Down();
		static Vector2 Left();
		static Vector2 Right();

		// Length of a vector
		static double Length(Vector2 a);
		// Distance between 2 vectors
		static double Distance(Vector2 a, Vector2 b);
		// Dot product of 2 vectors
		static double Dot(Vector2 a, Vector2 b);
		// Vector normalized so that its length is 1
		static Vector2 Normalized(Vector2 a);

		// Convert a vector to string
		static std::string ToString(Vector2 a);
	};
} // namespace solar

#endif // !SOLAR_VECTOR2_H_