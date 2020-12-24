#include "time.h"
#include <glfw3.h>

namespace solar
{
	// Declare frame time as 0
	double Time::frame_time = 0.0;

	int Time::FrameRate(int seconds)
	{
		return (int)(1 / Time::frame_time);
	}

	// Declare previous & current time
	double Time::previous_time = 0.0;
	double Time::current_time = 0.0;

	void Time::Update(double &previousTime, double &currentTime)
	{
		// Get current time
		Time::current_time = glfwGetTime();
		// Get frame time by suctracting previous time to current frame time
		Time::frame_time = currentTime - previousTime;
		// Set previous time for next frame update
		Time::previous_time = currentTime;
	}
} // namespace solar
