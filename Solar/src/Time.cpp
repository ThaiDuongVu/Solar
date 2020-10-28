#include "Time.h"
#include <glfw3.h>

namespace Solar
{
	// Declare frame time as 0
	double Time::FrameTime = 0.0;

	int Time::FrameRate(int seconds)
	{
		return (int)(1 / Time::FrameTime);
	}

	// Declare previous & current time
	double Time::previousTime = 0.0;
	double Time::currentTime = 0.0;

	void Time::Update(double &previousTime, double &currentTime)
	{
		// Get current time
		Time::currentTime = glfwGetTime();
		// Get frame time by suctracting previous time to current frame time
		Time::FrameTime = currentTime - previousTime;
		// Set previous time for next frame update
		Time::previousTime = currentTime;
	}
} // namespace Solar
