#pragma once

#ifndef SOLAR_TIME_H_
#define SOLAR_TIME_H_

#include "core.h"

namespace Solar
{
	class SOLAR_API Time
	{
	public:
		/// <summary>
		/// Elapsed time since last frame.
		/// </summary>
		static double frame_time;

		/// <summary>
		/// Number of frames drawn per some seconds.
		/// </summary>
		/// <param name="seconds">Second to scale frame rate</param>
		/// <returns>Frames per second(s)</returns>
		static int FrameRate(int seconds);

		/// <summary>
		/// Set target frame rate on current window.
		/// </summary>
		/// <param name="target_frame_rate">Frame rate to target</param>
		static void SetTargetFrameRate(double target_frame_rate);

		/// <summary>
		/// Update frame time.
		/// Is called every frame.
		/// </summary>
		/// <param name="previous_time">Previous time</param>
		/// <param name="current_time">Current time</param>
		static void Update();

	private:
		/// <summary>
		/// Previous time.
		/// </summary>
		static double previous_time;
		/// <summary>
		/// Current time.
		/// </summary>
		static double current_time;

		/// <summary>
		/// Number of frames game will *try* to render per second.
		/// </summary>
		static double target_frame_rate;
	};
} // namespace Solar

#endif // !SOLAR_TIME_H_