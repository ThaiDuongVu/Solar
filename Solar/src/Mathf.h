#pragma once

#ifndef SOLAR_MATHF_H_
#define SOLAR_MATHF_H_

#include "core.h"

namespace solar
{
	class SOLAR_API Mathf
	{
	public:
#pragma region Clamp
		static int Clamp(int &value, int min_value, int max_value);
		static float Clamp(float &value, float min_value, float max_value);
		static double Clamp(double &value, double min_value, double max_value);
#pragma endregion // Clamp a value to a range

#pragma region Abs
		static int Abs(int &value);
		static float Abs(float &value);
		static double Abs(double &value);
#pragma endregion // Return only positive values (absolute values)

#pragma region Ceiling
		static float Ceiling(float &value);
		static double Ceiling(double &value);
#pragma endregion // Return ceiling of a floating point value

#pragma region Floor
		static float Floor(float &value);
		static double Floor(double &value);
#pragma endregion //  Return floor of a floating point value

#pragma region Min
		static int Min(int x, int y);
		static float Min(float x, float y);
		static double Min(double x, double y);
#pragma endregion // Return minimum value from 2 numbers

#pragma region Max
		static int Max(int x, int y);
		static float Max(float x, float y);
		static double Max(double x, double y);
#pragma endregion // Return maximum value from 2 numbers

#pragma region Mod
		static int Mod(int x, int y);
		static float Mod(float x, float y);
		static double Mod(double x, double y);
#pragma endregion // Perform modulus operation

#pragma region Round
		static float Round(float &value);
		static double Round(double &value);
#pragma endregion // Round floating point number to nearest integer

#pragma region Round Even
		static float RoundEven(float &value);
		static double RoundEven(double &value);
#pragma endregion // Round floating point number to nearest even integer
	};
} // namespace solar

#endif // !SOLAR_MATHF_H_
