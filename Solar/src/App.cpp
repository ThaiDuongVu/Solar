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

	void App::Run()
	{
		// Initialize the library
		Init();
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

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Solar::Logger::LogError("Failed to initialize GLAD");
			return;
		}

		glViewport(0, 0, App::windowWidth, App::windowHeight);

		double previousTime = 0.0;
		double currentTime = 0.0;

		// Loop until the user closes the window 
		while (!glfwWindowShouldClose(window))
		{
			Update(Time::FrameTime);

			// Render here 
			glClear(GL_COLOR_BUFFER_BIT);

			Render();

			// Poll for and process events 
			glfwPollEvents();

			// Update frame time
			Time::UpdateTime(previousTime, currentTime);

			// Swap front and back buffers 
			glfwSwapBuffers(window);
		}

		Shutdown();
		glfwTerminate();
	}
}
