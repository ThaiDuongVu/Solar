#include "App.h"
#include "Debug.h"
#include "Time.h"
#include "Input.h"
#include "Vector2.h"
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
	T* App::window;

	void App::SetWindowSize(int width, int height)
	{
		App::windowWidth = width;
		App::windowHeight = height;
	}

	void App::SetTitle(const char* title)
	{
		App::title = title;
	}

	void App::Quit()
	{
		glfwSetWindowShouldClose(App::window<GLFWwindow>, true);
	}

	// On window resize
	void FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

#pragma region Input Callbacks
	// Keyboard callback
	void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		// Set key buffers
		if (action == GLFW_PRESS)
		{
			Input::keyDownBuffer = key;
		}
		else if (action == GLFW_RELEASE)
		{
			Input::keyUpBuffer = key;
		}
	}

	// On cursor enter or exit callback
	void CursorEnterCallback(GLFWwindow* window, int entered)
	{
		if (entered)
		{
			Input::cursorEnter = true;
		}
		else
		{
			Input::cursorExit = true;
		}

		Input::isCursorEnterExit = true;
	}

	// Mouse button callback
	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		// Set mouse buffers
		if (action == GLFW_PRESS)
		{
			Input::mouseDownBuffer = button;
		}
		else if (action == GLFW_RELEASE)
		{
			Input::mouseUpBuffer = button;
		}
	}

	// Mouse scroll callback
	void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{
		Input::scrollDeltaX = xoffset;
		Input::scrollDeltaY = yoffset;

		Input::isScrolling = true;
	}
#pragma endregion

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

		glfwSetKeyCallback(App::window<GLFWwindow>, KeyboardCallback);
		glfwSetCursorEnterCallback(App::window<GLFWwindow>, CursorEnterCallback);
		glfwSetMouseButtonCallback(App::window<GLFWwindow>, MouseButtonCallback);
		glfwSetScrollCallback(App::window<GLFWwindow>, ScrollCallback);

		// Main program loop
		while (!glfwWindowShouldClose(App::window<GLFWwindow>))
		{
			// Update frame time
			Time::Update(Time::previousTime, Time::currentTime);
			Input::Update();

			// User-defined update
			Update(Time::frameTime);

			// Poll for and process events
			glfwPollEvents();

			// Clear the back ground
			glClear(GL_COLOR_BUFFER_BIT);

			// User-defined render
			Render();

			// Swap front and back buffers
			glfwSwapBuffers(App::window<GLFWwindow>);
		}

		// User-defined shutdown
		Exit();

		Debug::ResetDebugColor();
		glfwTerminate();
	}
} // namespace Solar
