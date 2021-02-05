#include "mathf.h"
#include "glm.hpp"
#include "integer.hpp"
#include "gtx/integer.hpp"
#include "gtc/integer.hpp"

namespace Solar
{
	double Mathf::Pi()
	{
		return 3.14159265358979;
	}

#pragma region Approximate
	bool Mathf::Approximate(double x, double y, double epsilon)
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

#pragma region Trigonometric
	double Mathf::Cos(double angle)
	{
		return glm::cos(angle);
	}
	double Mathf::Sin(double angle)
	{
		return glm::sin(angle);
	}
	double Mathf::Tan(double angle)
	{
		return glm::tan(angle);
	}

	double Mathf::Acos(double value)
	{
		return glm::acos(value);
	}
	double Mathf::Asin(double value)
	{
		return glm::asin(value);
	}
	double Mathf::Atan(double value)
	{
		return glm::atan(value);
	}

	double Mathf::Cosh(double angle)
	{
		return glm::cosh(angle);
	}
	double Mathf::Sinh(double angle)
	{
		return glm::sinh(angle);
	}
	double Mathf::Tanh(double angle)
	{
		return glm::tanh(angle);
	}

	double Mathf::Acosh(double value)
	{
		return glm::acosh(value);
	}
	double Mathf::Asinh(double value)
	{
		return glm::asinh(value);
	}
	double Mathf::Atanh(double value)
	{
		return glm::atanh(value);
	}
#pragma endregion

#pragma region Conversion
	double Mathf::RadianToDegree(double value)
	{
		return glm::degrees(value);
	}

	double Mathf::DegreeToRadian(double value)
	{
		return glm::radians(value);
	}
#pragma endregion

#pragma region Random
	double Mathf::Random(double min, double max)
	{
		unsigned int seed = (unsigned int)std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine engine(seed);
		std::uniform_real_distribution<double> uniform_double(min, max);

		return uniform_double(engine);
	}
	int Mathf::Random(int min, int max)
	{
		unsigned int seed = (unsigned int)std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine engine(seed);
		std::uniform_int_distribution<int> uniform_int(min, max);

		return uniform_int(engine);
	}
#pragma endregion

} // namespace Solar