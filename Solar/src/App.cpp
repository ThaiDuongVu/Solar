#include "App.h"
#include "Debug.h"
#include "Time.h"
#include "Input.h"
#include <glad.h>
#include <glfw3.h>

namespace Solar
{
	void App::Init() {}
	void App::Update(double frameTime) {}
	void App::Render() {}
	void App::Exit() {}

	// OpenGL window
	template <typename T>
	T *App::window;

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
		glfwSetWindowShouldClose(App::window<GLFWwindow>, true);
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
		App::window<GLFWwindow> = glfwCreateWindow(App::windowWidth, App::windowHeight, App::title, NULL, NULL);
		if (App::window<GLFWwindow> == NULL)
		{
			Solar::Debug::LogError("Failed to create window");
			glfwTerminate();
			return;
		}

		// Make the window's context current
		glfwMakeContextCurrent(App::window<GLFWwindow>);

		// Initialize GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Solar::Debug::LogError("Failed to initialize GLAD");
			return;
		}

		// GLAD viewport
		glViewport(0, 0, App::windowWidth, App::windowHeight);
		glfwSetFramebufferSizeCallback(App::window<GLFWwindow>, FrameBufferSizeCallback);

		// Main program loop
		while (!glfwWindowShouldClose(App::window<GLFWwindow>))
		{
			// Update frame time
			Time::UpdateTime(Time::previousTime, Time::currentTime);

			// Poll for and process events
			glfwPollEvents();

			// User-defined update
			Update(Time::frameTime);

			// Clear the back ground
			glClear(GL_COLOR_BUFFER_BIT);

			// User-defined render
			Render();

			// Swap front and back buffers
			glfwSwapBuffers(App::window<GLFWwindow>);
		}

		// User-defined shutdown
		Exit();
		glfwTerminate();
	}
} // namespace Solar
