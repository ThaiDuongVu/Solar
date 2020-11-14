#include "mathf.h"
#include "glm.hpp"
#include "integer.hpp"
#include "gtx/integer.hpp"
#include "gtc/integer.hpp"

namespace solar
{
	double Mathf::Pi()
	{
		return 3.14159265358979;
	}

#pragma region Approximate
	static bool Approximate(float x, float y, float epsilon)
	{
		float difference = x - y;
		return (Mathf::Abs(difference) <= epsilon);
	}

	static bool Approximate(double x, double y, double epsilon)
	{
		double difference = x - y;
		return (Mathf::Abs(difference) <= epsilon);
	}
#pragma endregion

#pragma region Clamp
	int Mathf::Clamp(int value, int min_value, int max_value)
	{
		return glm::clamp(value, min_value, max_value);
	}

	float Mathf::Clamp(float value, float min_value, float max_value)
	{
		return glm::clamp(value, min_value, max_value);
	}

	double Mathf::Clamp(double value, double min_value, double max_value)
	{
		return glm::clamp(value, min_value, max_value);
	}
#pragma endregion

#pragma region Abs
	int Mathf::Abs(int value)
	{
		return glm::abs(value);
	}

	float Mathf::Abs(float value)
	{
		return glm::abs(value);
	}

	double Mathf::Abs(double value)
	{
		return glm::abs(value);
	}
#pragma endregion

#pragma region Ceiling
	float Mathf::Ceiling(float value)
	{
		return glm::ceil(value);
	}

	double Mathf::Ceiling(double value)
	{
		return glm::ceil(value);
	}
#pragma endregion

#pragma region Floor
	float Mathf::Floor(float value)
	{
		return glm::floor(value);
	}

	double Mathf::Floor(double value)
	{
		return glm::floor(value);
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
	float Mathf::Round(float value)
	{
		return glm::round(value);
	}

	double Mathf::Round(double value)
	{
		return glm::round(value);
	}
#pragma endregion

#pragma region Round Even
	float Mathf::RoundEven(float value)
	{
		return glm::roundEven(value);
	}

	double Mathf::RoundEven(double value)
	{
		return glm::roundEven(value);
	}
#pragma endregion

#pragma region Power
	double Mathf::Power(int base, int exponent)
	{
		return glm::pow(base, exponent);
	}

	double Mathf::Power(float base, float exponent)
	{
		return glm::pow(base, exponent);
	}

	double Mathf::Power(double base, double exponent)
	{
		return glm::pow(base, exponent);
	}
#pragma endregion

#pragma region Sqrt
	double Mathf::Sqrt(int value)
	{
		return glm::sqrt(value);
	}

	double Mathf::Sqrt(float value)
	{
		return glm::sqrt(value);
	}

	double Mathf::Sqrt(double value)
	{
		return glm::sqrt(value);
	}
#pragma endregion
} // namespace solar