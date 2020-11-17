#pragma once

#ifndef SOLAR_QUATERNION_H_
#define SOLAR_QUATERNION_H_

#include "../core.h"

namespace solar
{
	class SOLAR_API Quaternion
	{
	public:
		// Constructor and destructor
		Quaternion(double x = 0.0f, double y = 0.0f, double z = 0.0f, double w = 0.0f);
		~Quaternion();

		double x; // x value of quaternion
		double y; // y value of quaternion
		double z; // z value of quaternion
		double w; // w value of quaternion

		double Length(); // Length of the quaternion
		double Dot(Quaternion other); // Dot product of this quaternion and another quaternion
		Quaternion Normalized(); // Quaternion normalized so that its length is 1

#pragma region Operators
		Quaternion operator+(Quaternion other);
		Quaternion operator-(Quaternion other);
		Quaternion operator*(Quaternion other);

		Quaternion operator*(double other);
		Quaternion operator/(double other);
#pragma endregion

		static Quaternion Zero(); // (0.0f, 0.0f, 0.0f, 0.0f) quaternion
		static Quaternion Identity(); // (1.0f, 1.0f, 1.0f, 1.0f) quaternion

		static double Length(Quaternion a); // Length of a quaternion
		static double Dot(Quaternion a, Quaternion b); // Dot product of 2 quaternions
		static Quaternion Normalized(Quaternion a); // A quaternion normalized so that its length is 1
	};
} // namespace solar

#endif // !SOLAR_QUATERNION_H_