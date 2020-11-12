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
	};
} // namespace solar

#endif // !SOLAR_QUATERNION_H_