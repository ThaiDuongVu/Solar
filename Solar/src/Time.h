#pragma once

#include "Core.h"

namespace Solar
{
	class SOLAR_CLASS Time
	{
	public:
		// Elapsed time since last frame
		static double FrameTime;

		// Update frame time
		// Called every frame
		static void UpdateTime(double& previousTime, double& currentTime);
	};
}

