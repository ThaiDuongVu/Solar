#include "App.h"
#include <glad.h>
#include <glfw3.h>

namespace Solar
{
	void App::Init() {}
	void App::Update(double frameTime) {}
	void App::Render() {}
	void App::Shutdown() {}

	// OpenGL window
	GLFWwindow *window;

	void App::SetWindowSize(int width, int height)
	{
		App::windowWidth = width;
		App::windowHeight = height;
	}

	void App::SetTitle(const char *title)
	{
		App::title = title;
	}

	void App::Quit()
	{
		glfwSetWindowShouldClose(window, true);
	}

	// On window resize
	void FrameBufferSizeCallback(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void App::Run()
	{
		// User-defined initialization
		Init();

		// Initialize GLFW
		if (!glfwInit())
		{
			Solar::Debug::LogError("Failed to initialize GLFW");
			return;
		}

		// Create a windowed mode window and its OpenGL context
		window = glfwCreateWindow(App::windowWidth, App::windowHeight, App::title, NULL, NULL);
		if (window == NULL)
		{
			Solar::Debug::LogError("Failed to create window");
			glfwTerminate();
			return;
		}

		// Make the window's context current
		glfwMakeContextCurrent(window);

		// Initialize GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Solar::Debug::LogError("Failed to initialize GLAD");
			return;
		}

		// GLAD viewport
		glViewport(0, 0, App::windowWidth, App::windowHeight);
		glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);

		// Main program loop
		while (!glfwWindowShouldClose(window))
		{
			// Update frame time
			Time::UpdateTime(Time::previousTime, Time::currentTime);

			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			{
				Solar::Debug::Log("nice");
			}
			// Poll for and process events
			glfwPollEvents();

			// User-defined update
			Update(Time::frameTime);

			// Clear the back ground
			glClear(GL_COLOR_BUFFER_BIT);

			// User-defined render
			Render();

			// Swap front and back buffers
			glfwSwapBuffers(window);
		}

		// User-defined shutdown
		Shutdown();
		glfwTerminate();
	}
} // namespace Solar
