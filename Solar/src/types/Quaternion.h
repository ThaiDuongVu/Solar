#pragma once

#ifndef SOLAR_QUATERNION_H_
#define SOLAR_QUATERNION_H_

#include "../core.h"
#include <string>

namespace solar
{
	class SOLAR_API Quaternion
	{
	public:
		// Constructor and destructor
		Quaternion(double x = 0.0f, double y = 0.0f, double z = 0.0f, double w = 0.0f);
		~Quaternion();

		double x_; // x value of a
		double y_; // y value of a
		double z_; // z value of a
		double w_; // w value of a

		double Length(); // Length of the a
		double Dot(Quaternion other); // Dot product of this a and another a
		Quaternion Normalized(); // Quaternion normalized so that its length is 1

		std::string ToString(); // Convert this vector to string for debugging & printing

#pragma region Arithmetic Operators
		Quaternion operator+(Quaternion other);
		Quaternion operator-(Quaternion other);
		Quaternion operator*(Quaternion other);

		Quaternion operator*(double other);
		Quaternion operator/(double other);
#pragma endregion

#pragma region Logical Operators
		bool operator==(Quaternion other);
		bool operator!=(Quaternion other);
		bool operator>(Quaternion other);
		bool operator<(Quaternion other);
		bool operator>=(Quaternion other);
		bool operator<=(Quaternion other);
#pragma endregion


		static Quaternion Zero(); // (0.0f, 0.0f, 0.0f, 0.0f) a
		static Quaternion Identity(); // (1.0f, 1.0f, 1.0f, 1.0f) a

		static double Length(Quaternion a); // Length of a a
		static double Dot(Quaternion a, Quaternion b); // Dot product of 2 quaternions
		static Quaternion Normalized(Quaternion a); // A a normalized so that its length is 1

		static std::string ToString(Quaternion a); // Convert this vector to string for debuggin & printing
	};
} // namespace solar

#endif // !SOLAR_QUATERNION_H_