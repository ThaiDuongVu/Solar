#include "Time.h"
#include <glfw3.h>

namespace Solar
{
	double Time::frameTime = 0;

	void Time::UpdateTime(double& previousTime, double& currentTime)
	{
		currentTime = glfwGetTime();
		Time::frameTime = currentTime - previousTime;
		previousTime = currentTime;
	}
}
