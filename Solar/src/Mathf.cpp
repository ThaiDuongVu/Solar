#include "mathf.h"
#include "glm.hpp"
#include "integer.hpp"
#include "gtx/integer.hpp"
#include "gtc/integer.hpp"

namespace solar
{
#pragma region Clamp
	int Mathf::Clamp(int &value, int min_value, int max_value)
	{
		value = glm::clamp(value, min_value, max_value);
		return value;
	}

	float Mathf::Clamp(float &value, float min_value, float max_value)
	{
		value = glm::clamp(value, min_value, max_value);
		return value;
	}

	double Mathf::Clamp(double &value, double min_value, double max_value)
	{
		value = glm::clamp(value, min_value, max_value);
		return value;
	}
#pragma endregion

#pragma region Abs
	int Mathf::Abs(int &value)
	{
		value = glm::abs(value);
		return value;
	}

	float Mathf::Abs(float &value)
	{
		value = glm::abs(value);
		return value;
	}

	double Mathf::Abs(double &value)
	{
		value = glm::abs(value);
		return value;
	}
#pragma endregion

#pragma region Ceiling
	float Mathf::Ceiling(float &value)
	{
		value = glm::ceil(value);
		return value;
	}

	double Mathf::Ceiling(double &value)
	{
		value = glm::ceil(value);
		return value;
	}
#pragma endregion

#pragma region Floor
	float Mathf::Floor(float &value)
	{
		return 0.0f;
	}

	double Mathf::Floor(double &value)
	{
		return 0.0;
	}
#pragma endregion

#pragma region Min
	int Mathf::Min(int x, int y)
	{
		return glm::min(x, y);
	}

	float Mathf::Min(float x, float y)
	{
		return glm::min(x, y);
	}

	double Mathf::Min(double x, double y)
	{
		return glm::min(x, y);
	}
#pragma endregion

#pragma region Max
	int Mathf::Max(int x, int y)
	{
		return glm::max(x, y);
	}

	float Mathf::Max(float x, float y)
	{
		return glm::max(x, y);
	}

	double Mathf::Max(double x, double y)
	{
		return glm::max(x, y);
	}
#pragma endregion

#pragma region Mod
	int Mathf::Mod(int x, int y)
	{
		return glm::mod(x, y);
	}

	float Mathf::Mod(float x, float y)
	{
		return glm::mod(x, y);
	}

	double Mathf::Mod(double x, double y)
	{
		return glm::mod(x, y);
	}
#pragma endregion

#pragma region Round
	float Mathf::Round(float &value)
	{
		value = glm::round(value);
		return value;
	}

	double Mathf::Round(double &value)
	{
		value = glm::round(value);
		return value;
	}
#pragma endregion

#pragma region Round Even
	float Mathf::RoundEven(float &value)
	{
		value = glm::roundEven(value);
		return value;
	}

	double Mathf::RoundEven(double &value)
	{
		value = glm::roundEven(value);
		return value;
	}
#pragma endregion
} // namespace solar