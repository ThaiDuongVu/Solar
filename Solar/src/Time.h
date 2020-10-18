#pragma once

#include "Core.h"

namespace Solar
{
	class SOLAR_API Time
	{
	public:
		// Elapsed time since last frame
		static double frameTime;

		// Previous & current time
		static double previousTime;
		static double currentTime;

		// Update frame time
		// Called every frame
		static void Update(double &previousTime, double &currentTime);
	};
} // namespace Solar
