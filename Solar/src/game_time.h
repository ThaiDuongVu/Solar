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
		/// Returns elapsed time since last frame.
		/// </summary>
		/// <returns>Elapsed time</returns>
		static double FrameTime();

		/// <summary>
		/// Returns elapsed time at 60fps.
		/// </summary>
		/// <returns>Elapsed time</returns>
		static double FixedFrameTime();

		/// <summary>
		/// Returns current scale of elapsed time.
		/// </summary>
		/// <returns>Time scale ranging from 0 to 1</returns>
		static double TimeScale();

		/// <summary>
		/// Number of frames drawn per some seconds.
		/// </summary>
		/// <returns>Frames per second(s)</returns>
		static int FrameRate();

		/// <summary>
		/// Set target frame rate on current window.
		/// </summary>
		/// <param name="target_frame_rate">Frame rate to target</param>
		static void SetTargetFrameRate(double target_frame_rate);

		/// <summary>
		/// Set scale of elapsed time.
		/// </summary>
		/// <param name="time_scale">Time scale to set</param>
		static void SetTimeScale(double time_scale);

		/// <summary>
		/// Update frame time.
		/// Is called every frame.
		/// </summary>
		/// <param name="previous_time">Previous time</param>
		/// <param name="current_time">Current time</param>
		static void Update();

	private:
		/// <summary>
		/// Elapsed time since last frame.
		/// </summary>
		static double frame_time;

		/// <summary>
		/// Scale of elapsed time from 0 to 1.
		/// </summary>
		static double time_scale;

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