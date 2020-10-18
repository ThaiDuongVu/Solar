#pragma once

#include "Core.h"

namespace Solar
{
	class SOLAR_API Vector2
	{
	public:
		Vector2(double x = 0, double y = 0);

		double* X = 0;
		double* Y = 0;
	};
}
