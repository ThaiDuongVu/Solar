#include "Mathf.h"
#include "glm.hpp"
#include <iostream>

namespace Solar
{
#pragma region Clamp
	int Mathf::Clamp(int& value, int minValue, int maxValue)
	{
		value = glm::clamp(value, minValue, maxValue);
		return value;
	}

	float Mathf::Clamp(float& value, float minValue, float maxValue)
	{
		value = glm::clamp(value, minValue, maxValue);
		return value;
	}

	double Mathf::Clamp(double& value, double minValue, double maxValue)
	{
		value = glm::clamp(value, minValue, maxValue);
		return value;
	}
#pragma endregion

#pragma region Abs
	int Mathf::Abs(int& value)
	{
		value = glm::abs(value);
		return value;
	}

	float Mathf::Abs(float& value)
	{
		value = glm::abs(value);
		return value;
	}

	double Mathf::Abs(double& value)
	{
		value = glm::abs(value);
		return value;
	}
#pragma endregion
}