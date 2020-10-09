#include "App.h"
#include <glad.h>
#include <glfw3.h>

namespace Solar
{
	void App::Init() { }
	void App::Update() { }
	void App::Render() { }
	void App::Shutdown() { }

	void App::Run(int width, int height, const char* title)
	{
		// Initialize the library
		Init();
		if (!glfwInit())
		{
			Solar::Logger::LogError("Failed to initialize GLFW");
			return;
		}

		// Create a windowed mode window and its OpenGL context 
		GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (window == NULL)
		{
			Solar::Logger::LogError("Failed to create window");
			glfwTerminate();
			return;
		}

		// Make the window's context current 
		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Solar::Logger::LogError("Failed to initialize GLAD");
			return;
		}

		glViewport(0, 0, width, height);

		double previousTime = 0.0;
		double currentTime = 0.0;

		// Loop until the user closes the window 
		while (!glfwWindowShouldClose(window))
		{
			Update();

			// Render here 
			glClear(GL_COLOR_BUFFER_BIT);

			Render();

			Time::UpdateTime(previousTime, currentTime);
			std::cout << Time::frameTime << std::endl;

			// Poll for and process events 
			glfwPollEvents();

			// Swap front and back buffers 
			glfwSwapBuffers(window);
		}

		Shutdown();
		glfwTerminate();
	}
}
