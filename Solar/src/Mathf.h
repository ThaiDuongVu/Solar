#pragma once

#include "Core.h"

namespace Solar
{
	class SOLAR_API Mathf
	{
	public:
		static int Clamp(int& value, int minValue, int maxValue);
		static float Clamp(float& value, float minValue, float maxValue);
		static double Clamp(double& value, double minValue, double maxValue);

		static int Abs(int& value);
		static float Abs(float& value);
		static double Abs(double& value);
	};
};

