#pragma once

#include "../Core.h"

namespace Solar
{
	class SOLAR_API Vector2
	{
	public:
		// Constructor & destructor
		Vector2(double x = 0.0, double y = 0.0);
		~Vector2();

		double x = 0.0;
		double y = 0.0;

		float Length();

	private:
		void Update();
	};
} // namespace Solar
