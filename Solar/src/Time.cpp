#include "Time.h"
#include <glfw3.h>

namespace Solar
{
	// Declare frame time as 0
	double Time::frameTime = 0.0;

	// Declare previous & current time
	double Time::previousTime = 0.0;
	double Time::currentTime = 0.0;

	void Time::Update(double &previousTime, double &currentTime)
	{
		// Get current time
		currentTime = glfwGetTime();
		// Get frame time by suctracting previous time to current frame time
		Time::frameTime = currentTime - previousTime;
		// Set previous time for next frame update
		previousTime = currentTime;
	}
} // namespace Solar
