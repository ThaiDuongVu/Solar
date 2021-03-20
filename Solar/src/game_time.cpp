#include "game_time.h"
#include "mathf.h"
#include <glfw3.h>

namespace Solar
{
	double Time::frame_time = 0.0f;
	double Time::time_scale = 1.0f;
	double Time::target_frame_rate = 60.0f;

	double Time::previous_time = 0.0f;
	double Time::current_time = 0.0f;

	double Time::FrameTime()
	{
		return frame_time * time_scale;
	}

	double Time::FixedFrameTime()
	{
		return 1.0f / 60.0f;
	}

	double Time::TimeScale()
	{
		return time_scale;
	}

	int Time::FrameRate()
	{
		return (int)(1 / Time::frame_time);
	}

	void Time::SetTargetFrameRate(double target_frame_rate)
	{
		Time::target_frame_rate = target_frame_rate;
	}

	void Time::SetTimeScale(double time_scale)
	{
		Time::time_scale = time_scale;
		// Clamp time scale value to be between 0 and 1
		Mathf::Clamp(Time::time_scale, (double)0.0f, (double)1.0f);
	}

	void Time::Update()
	{
		// Get current time
		current_time = glfwGetTime();
		// Get frame time by suctracting previous time to current frame time
		frame_time = current_time - previous_time;
		// Set previous time for next frame update
		previous_time = current_time;

		while (glfwGetTime() < current_time + 1.0f / target_frame_rate)
		{
			// Simply do nothing while waiting for frame to pass
		}
		current_time += 1.0f / target_frame_rate;
	}
} // namespace Solar
