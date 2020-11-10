#pragma once

#include "../Core.h"

namespace Solar
{
	class SOLAR_API Vector2
	{
	public:
		// Constructor & destructor
		Vector2(double x = 0.0f, double y = 0.0f);
		~Vector2();

		double x = 0.0f;
		double y = 0.0f;

		double Length(); // Length of the vector
		Vector2 Normalized(); // Vector normalized so that its length is 1

	private:
		void Update();
	};
} // namespace Solar
