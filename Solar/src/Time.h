#pragma once

#ifndef SOLAR_TIME_H_
#define SOLAR_TIME_H_

#include "core.h"

namespace solar
{
	class SOLAR_API Time
	{
	public:
		// Elapsed time since last frame
		static double frame_time;
		// How many frames drawn per some seconds
		static int FrameRate(int seconds);

		// Previous & current time
		static double previous_time;
		static double current_time;

		// Update frame time
		// Is called every frame
		static void Update(double &previous_time, double &current_time);
	};
} // namespace solar

#endif // !SOLAR_TIME_H_