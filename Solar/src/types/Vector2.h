#pragma once

#ifndef SOLAR_VECTOR2_H_
#define SOLAR_VECTOR2_H_

#include "../core.h"
#include <string>

namespace Solar
{
	class SOLAR_API Vector2
	{
	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="x">Initial vector x</param>
		/// <param name="y">Initial vector y</param>
		Vector2(double x = 0.0f, double y = 0.0f);
		
		/// <summary>
		/// Destructor.
		/// </summary>
		~Vector2();

		/// <summary>
		/// x value of vector.
		/// </summary>
		double x = 0.0f;
		/// <summary>
		/// y value of vector.
		/// </summary>
		double y = 0.0f;

		/// <summary>
		/// Translating this vector with another vector.
		/// </summary>
		void Translate(Vector2 difference);
		/// <summary>
		/// Translating this vector with 2 doubles.
		/// </summary>
		void Translate(double difference_x, double difference_y);

		/// <summary>
		/// Length of the vector.
		/// </summary>
		/// <returns>Length of current vector</returns>
		double Length();
		/// <summary>
		/// Distance from this vector to another vector.
		/// </summary>
		/// <param name="other">Other vector to calculate</param>
		/// <returns>Distance between 2 vectors</returns>
		double Distance(Vector2 other);
		/// <summary>
		/// Dot product of this vector and another vector.
		/// </summary>
		/// <param name="other">Other vector to calculate</param>
		/// <returns>Dot product of 2 vectors</returns>
		double Dot(Vector2 other);
		/// <summary>
		/// Vector normalized so that its length is 1.
		/// </summary>
		/// <returns>Normalized vector</returns>
		Vector2 Normalized();

		/// <summary>
		/// Convert this vector to string.
		/// </summary>
		/// <returns>Vector in string format</returns>
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

		/// <summary>
		/// (0.0f, 0.0f) vector.
		/// </summary>
		/// <returns>Vector zero</returns>
		static Vector2 Zero();
		/// <summary>
		/// (1.0f, 1.0f) vector.
		/// </summary>
		/// <returns>Identity vector</returns>
		static Vector2 Identity();
		/// <summary>
		/// (1.0f, 0.0f) vector.
		/// </summary>
		/// <returns>Unit x vector</returns>
		static Vector2 UnitX();
		/// <summary>
		/// (0.0f, 1.0f) vector.
		/// </summary>
		/// <returns>Unit y vector</returns>
		static Vector2 UnitY();

		/// <summary>
		/// Up direction vector.
		/// </summary>
		/// <returns>Up vector</returns>
		static Vector2 Up();
		/// <summary>
		/// Down direction vector.
		/// </summary>
		/// <returns>Down vector</returns>
		static Vector2 Down();
		/// <summary>
		/// Left direction vector.
		/// </summary>
		/// <returns>Left vector</returns>
		static Vector2 Left();
		/// <summary>
		/// Right direction vector.
		/// </summary>
		/// <returns>Right vector</returns>
		static Vector2 Right();

		/// <summary>
		/// Translating vector a with another vector.
		/// </summary>
		static void Translate(Vector2 a, Vector2 difference);
		/// <summary>
		/// Translating vector a with 2 doubles.
		/// </summary>
		static void Translate(Vector2 a, double difference_x, double difference_y);

		/// <summary>
		/// Length of a vector.
		/// </summary>
		/// <param name="a">Vector to calculate</param>
		/// <returns>Vector length</returns>
		static double Length(Vector2 a);
		/// <summary>
		/// Distance between 2 vectors.
		/// </summary>
		/// <param name="a">First vector</param>
		/// <param name="b">Second vector</param>
		/// <returns>Distance between 1st and 2nd vectors</returns>
		static double Distance(Vector2 a, Vector2 b);
		/// <summary>
		/// Dot product of 2 vectors.
		/// </summary>
		/// <param name="a">First vector</param>
		/// <param name="b">Second vector</param>
		/// <returns>Dot product of 1st and 2nd vectors</returns>
		static double Dot(Vector2 a, Vector2 b);
		/// <summary>
		/// Vector normalized so that its length is 1.
		/// </summary>
		/// <param name="a">Vector to calculate</param>
		/// <returns>Normalized vector</returns>
		static Vector2 Normalized(Vector2 a);

		/// <summary>
		/// Convert a vector to string.
		/// </summary>
		/// <param name="a">Vector to convert</param>
		/// <returns>Vector in string format</returns>
		static std::string ToString(Vector2 a);
	};
} // namespace Solar

#endif // !SOLAR_VECTOR2_H_