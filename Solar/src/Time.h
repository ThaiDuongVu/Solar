#pragma once

#include "Core.h"

namespace Solar
{
	class SOLAR_CLASS Time
	{
	public:
		static double frameTime;
		static void UpdateTime(double& previousTime, double& currentTime);
	};
}

