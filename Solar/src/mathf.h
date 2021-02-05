#pragma once

#ifndef SOLAR_MATHF_H_
#define SOLAR_MATHF_H_

#include "core.h"
#include <random>
#include <chrono>

namespace Solar
{
	class SOLAR_API Mathf
	{
	public:
		/// <summary>
		/// Returns the Holy Number.
		/// </summary>
		/// <returns>The Holy Number</returns>
		static double Pi();

#pragma region Approximate
		/// <summary>
		/// Compare two floating point values and check if they are similar.
		/// </summary>
		/// <param name="x">First value</param>
		/// <param name="y">Second value</param>
		/// <param name="epsilon">How approximate the comparison is</param>
		/// <returns>Whether to approximation is correct</returns>
		static bool Approximate(double x, double y, double epsilon = 0.01f);
#pragma endregion

#pragma region Clamp
		/// <summary>
		/// Limit a value to a range.
		/// </summary>
		/// <param name="value">Value to clamp</param>
		/// <param name="min_value">Minimum value</param>
		/// <param name="max_value">Maximum value</param>
		/// <returns>The clamped value</returns>
		static int Clamp(int value, int min_value, int max_value);
		/// <summary>
		/// Limit a value to a range.
		/// </summary>
		/// <param name="value">Value to clamp</param>
		/// <param name="min_value">Minimum value</param>
		/// <param name="max_value">Maximum value</param>
		/// <returns>The clamped value</returns>
		static float Clamp(float value, float min_value, float max_value);
		/// <summary>
		/// Limit a value to a range.
		/// </summary>
		/// <param name="value">Value to clamp</param>
		/// <param name="min_value">Minimum value</param>
		/// <param name="max_value">Maximum value</param>
		/// <returns>The clamped value</returns>
		static double Clamp(double value, double min_value, double max_value);
#pragma endregion

#pragma region Abs
		/// <summary>
		/// Return ceiling of a floating point value.
		/// </summary>
		/// <param name="value">Value to be absoluted</param>
		/// <returns>The absolute value</returns>
		static int Abs(int value);
		/// <summary>
		/// Return ceiling of a floating point value.
		/// </summary>
		/// <param name="value">Value to be absoluted</param>
		/// <returns>The absolute value</returns>
		static float Abs(float value);
		/// <summary>
		/// Return ceiling of a floating point value.
		/// </summary>
		/// <param name="value">Value to be absoluted</param>
		/// <returns>The absolute value</returns>
		static double Abs(double value);
#pragma endregion

#pragma region Ceiling
		/// <summary>
		/// Return ceiling of a floating point value.
		/// </summary>
		/// <param name="value">Floating point value to ceil</param>
		/// <returns>Ceiled value</returns>
		static float Ceiling(float value);
		/// <summary>
		/// Return ceiling of a floating point value.
		/// </summary>
		/// <param name="value">Floating point value to ceil</param>
		/// <returns>Ceiled value</returns>
		static double Ceiling(double value);
#pragma endregion

#pragma region Floor
		/// <summary>
		/// Return floor of a floating point value.
		/// </summary>
		/// <param name="value">Floating point value to floor</param>
		/// <returns>Floored value</returns>
		static float Floor(float value);
		/// <summary>
		/// Return floor of a floating point value.
		/// </summary>
		/// <param name="value">Floating point value to floor</param>
		/// <returns>Floored value</returns>
		static double Floor(double value);
#pragma endregion

#pragma region Min
		/// <summary>
		/// Return minimum value of 2 numbers.
		/// </summary>
		/// <param name="x">First number</param>
		/// <param name="y">Second number</param>
		/// <returns>Minimum value</returns>
		static int Min(int x, int y);
		/// <summary>
		/// Return minimum value of 2 numbers.
		/// </summary>
		/// <param name="x">First number</param>
		/// <param name="y">Second number</param>
		/// <returns>Minimum value</returns>
		static float Min(float x, float y);
		/// <summary>
		/// Return minimum value of 2 numbers.
		/// </summary>
		/// <param name="x">First number</param>
		/// <param name="y">Second number</param>
		/// <returns>Minimum value</returns>
		static double Min(double x, double y);
#pragma endregion

#pragma region Max
		/// <summary>
		/// Return maximum value of 2 numbers.
		/// </summary>
		/// <param name="x">First number</param>
		/// <param name="y">Second number</param>
		/// <returns>Maximum value</returns>
		static int Max(int x, int y);
		/// <summary>
		/// Return maximum value of 2 numbers.
		/// </summary>
		/// <param name="x">First number</param>
		/// <param name="y">Second number</param>
		/// <returns>Maximum value</returns>
		static float Max(float x, float y);
		/// <summary>
		/// Return maximum value of 2 numbers.
		/// </summary>
		/// <param name="x">First number</param>
		/// <param name="y">Second number</param>
		/// <returns>Maximum value</returns>
		static double Max(double x, double y);
#pragma endregion

#pragma region Mod
		/// <summary>
		/// Perform modulus operation.
		/// </summary>
		/// <param name="x">The dividend</param>
		/// <param name="y">The divisor</param>
		/// <returns>The remainder of x / y</returns>
		static int Mod(int x, int y);
		/// <summary>
		/// Perform modulus operation.
		/// </summary>
		/// <param name="x">The dividend</param>
		/// <param name="y">The divisor</param>
		/// <returns>The remainder of x / y</returns>
		static float Mod(float x, float y);
		/// <summary>
		/// Perform modulus operation.
		/// </summary>
		/// <param name="x">The dividend</param>
		/// <param name="y">The divisor</param>
		/// <returns>The remainder of x / y</returns>
		static double Mod(double x, double y);
#pragma endregion

#pragma region Round
		/// <summary>
		/// Round a floating point number to nearest integer.
		/// </summary>
		/// <param name="value">Value to round</param>
		/// <returns>Rounded value</returns>
		static float Round(float value);
		/// <summary>
		/// Round a floating point number to nearest integer.
		/// </summary>
		/// <param name="value">Value to round</param>
		/// <returns>Rounded value</returns>
		static double Round(double value);
#pragma endregion

#pragma region Round Even
		/// <summary>
		/// Round a floating point number to nearest even integer.
		/// </summary>
		/// <param name="value">Value to round</param>
		/// <returns>Rounded value</returns>
		static float RoundEven(float value);
		/// <summary>
		/// Round a floating point number to nearest even integer.
		/// </summary>
		/// <param name="value">Value to round</param>
		/// <returns>Rounded value</returns>
		static double RoundEven(double value);
#pragma endregion

#pragma region Power
		/// <summary>
		/// Return base to the power of exponent.
		/// </summary>
		/// <param name="base">Base</param>
		/// <param name="exponent">Exponent</param>
		/// <returns>base^exponent</returns>
		static double Power(int base, int exponent);
		/// <summary>
		/// Return base to the power of exponent.
		/// </summary>
		/// <param name="base">Base</param>
		/// <param name="exponent">Exponent</param>
		/// <returns>base^exponent</returns>
		static double Power(float base, float exponent);
		/// <summary>
		/// Return base to the power of exponent.
		/// </summary>
		/// <param name="base">Base</param>
		/// <param name="exponent">Exponent</param>
		/// <returns>base^exponent</returns>
		static double Power(double base, double exponent);
#pragma endregion

#pragma region Sqrt
		/// <summary>
		/// Return square root of a value.
		/// </summary>
		/// <param name="value">Value to square root</param>
		/// <returns>Square rooted value</returns>
		static double Sqrt(int value);
		/// <summary>
		/// Return square root of a value.
		/// </summary>
		/// <param name="value">Value to square root</param>
		/// <returns>Square rooted value</returns>
		static double Sqrt(float value);
		/// <summary>
		/// Return square root of a value.
		/// </summary>
		/// <param name="value">Value to square root</param>
		/// <returns>Square rooted value</returns>
		static double Sqrt(double value);
#pragma endregion

		// TODO (Duong): Implement log functions
#pragma region Log

#pragma endregion Return the logarithm of a value in a base

#pragma region Trigonometric
		/// <summary>
		/// Returns cosine of an angle.
		/// </summary>
		/// <param name="angle">Angle in radian</param>
		/// <returns>The cosine of angle</returns>
		static double Cos(double angle);
		/// <summary>
		/// Returns sine of an angle.
		/// </summary>
		/// <param name="angle">Angle in radian</param>
		/// <returns>The sine of angle</returns>
		static double Sin(double angle);
		/// <summary>
		/// Returns tangent of an angle.
		/// </summary>
		/// <param name="angle">Angle in radian</param>
		/// <returns>The tangent of angle</returns>
		static double Tan(double angle);

		/// <summary>
		/// Returns arg-cosine angle of a value.
		/// </summary>
		/// <param name="value">Value</param>
		/// <returns>The arg-cosine angle of a value in radian</returns>
		static double Acos(double value);
		/// <summary>
		/// Returns arg-sine angle of a value.
		/// </summary>
		/// <param name="value">Value</param>
		/// <returns>The arg-sine angle of a value in radian</returns>
		static double Asin(double value);
		/// <summary>
		/// Returns arg-tangent angle of a value.
		/// </summary>
		/// <param name="value">Value</param>
		/// <returns>The arg-tangent angle of a value in radian</returns>
		static double Atan(double value);

		/// <summary>
		/// Returns hyperbolic cosine of an angle.
		/// </summary>
		/// <param name="angle">Angle in radian</param>
		/// <returns>The hyperbolic cosine of angle</returns>
		static double Cosh(double angle);
		/// <summary>
		/// Returns hyperbolic sine of an angle.
		/// </summary>
		/// <param name="angle">Angle in radian</param>
		/// <returns>The hyperbolic sine of angle</returns>
		static double Sinh(double angle);
		/// <summary>
		/// Returns hyperbolic tangent of an angle.
		/// </summary>
		/// <param name="angle">Angle in radian</param>
		/// <returns>The hyperbolic tangent of angle</returns>
		static double Tanh(double angle);

		/// <summary>
		/// Returns hyperbolic arg-cosine angle of a value.
		/// </summary>
		/// <param name="value">Value</param>
		/// <returns>The hyperbolic arg-cosine angle of a value in radian</returns>
		static double Acosh(double value);
		/// <summary>
		/// Returns hyperbolic arg-sine angle of a value.
		/// </summary>
		/// <param name="value">Value</param>
		/// <returns>The hyperbolic arg-sine angle of a value in radian</returns>
		static double Asinh(double value);
		/// <summary>
		/// Returns hyperbolic arg-tangent angle of a value.
		/// </summary>
		/// <param name="value">Value</param>
		/// <returns>The hyperbolic arg-tangent angle of a value in radian</returns>
		static double Atanh(double value);
#pragma endregion

#pragma region Conversion
		/// <summary>
		/// Convert a value from radian to degrees.
		/// </summary>
		/// <param name="value">Value in radian</param>
		/// <returns>Converted value</returns>
		static double RadianToDegree(double value);
		/// <summary>
		/// Convert a value from degrees to radian.
		/// </summary>
		/// <param name="value">Value in degrees</param>
		/// <returns>Converted value</returns>
		static double DegreeToRadian(double value);
#pragma endregion

#pragma region Random
		static double Random(double min, double max);
		static int Random(int min, int max);
#pragma endregion

	};
} // namespace Solar

#endif // !SOLAR_MATHF_H_
