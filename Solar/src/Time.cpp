#include "Time.h"
#include <glfw3.h>

namespace Solar
{
	double Time::FrameTime = 0;

	void Time::UpdateTime(double& previousTime, double& currentTime)
	{
		currentTime = glfwGetTime();
		Time::FrameTime = currentTime - previousTime;
		previousTime = currentTime;
	}
}
