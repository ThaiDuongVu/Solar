#pragma once

#include "../Core.h"

namespace Solar
{
	class SOLAR_API Quaternion
	{
	public:
		Quaternion(double x = 0.0f, double y = 0.0f, double z = 0.0f, double w = 0.0f);
		~Quaternion();

		double x;
		double y;
		double z;
		double w;

		double Length(); // Length of the quaternion
	};
};
