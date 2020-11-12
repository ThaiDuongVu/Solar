#pragma once

#ifndef SOLAR_VECTOR2_H_
#define SOLAR_VECTOR2_H_

#include "../core.h"

namespace solar
{
	class SOLAR_API Vector2
	{
	public:
		// Constructor and destructor
		Vector2(double x = 0.0f, double y = 0.0f);
		~Vector2();

		double x = 0.0f; // x value of vector
		double y = 0.0f; // y value of vector

		static Vector2 Zero();
		static Vector2 Identity();

		double Length();	  // Length of the vector
		Vector2 Normalized(); // Vector normalized so that its length is 1

	private:
		void Update();
	};
} // namespace solar

#endif // !SOLAR_VECTOR2_H_