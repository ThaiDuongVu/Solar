#include "time.h"
#include <glfw3.h>

namespace solar
{
	// Declare frame time as 0
	double Time::frame_time_ = 0.0;

	int Time::FrameRate(int seconds)
	{
		return (int)(1 / Time::frame_time_);
	}

	// Declare previous & current time
	double Time::previous_time_ = 0.0;
	double Time::current_time_ = 0.0;

	void Time::Update(double &previousTime, double &currentTime)
	{
		// Get current time
		Time::current_time_ = glfwGetTime();
		// Get frame time by suctracting previous time to current frame time
		Time::frame_time_ = currentTime - previousTime;
		// Set previous time for next frame update
		Time::previous_time_ = currentTime;
	}
} // namespace solar
