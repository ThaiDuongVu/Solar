#include "App.h"
#include <glad.h>
#include <glfw3.h>

namespace Solar
{
	void App::Init() { }
	void App::Update(double frameTime) { }
	void App::Render() { }
	void App::Shutdown() { }

	void App::SetWindowSize(int width, int height)
	{
		App::windowWidth = width;
		App::windowHeight = height;
	}

	void App::SetTitle(const char* title)
	{
		App::title = title;
	}

	// On window resize
	void FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void App::Run()
	{
		// User-defined init
		Init();

		// Initialize GLFW
		if (!glfwInit())
		{
			Solar::Logger::LogError("Failed to initialize GLFW");
			return;
		}

		// Create a windowed mode window and its OpenGL context
		GLFWwindow* window = glfwCreateWindow(App::windowWidth, App::windowHeight, App::title, NULL, NULL);
		if (window == NULL)
		{
			Solar::Logger::LogError("Failed to create window");
			glfwTerminate();
			return;
		}

		// Make the window's context current
		glfwMakeContextCurrent(window);

		// Initialize GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Solar::Logger::LogError("Failed to initialize GLAD");
			return;
		}

		// GLAD viewport
		glViewport(0, 0, App::windowWidth, App::windowHeight);
		glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);

		//Handle frame time
		double previousTime = 0.0;
		double currentTime = 0.0;

		// Main program loop
		while (!glfwWindowShouldClose(window))
		{
			// Update frame time
			Time::UpdateTime(previousTime, currentTime);

			// User-defined update
			Update(Time::FrameTime);

			// Clear the back ground
			glClear(GL_COLOR_BUFFER_BIT);

			// User-defined render
			Render();

			// Poll for and process events
			glfwPollEvents();

			// Swap front and back buffers
			glfwSwapBuffers(window);
		}

		// User-defined shutdown
		Shutdown();
		glfwTerminate();
	}
}
