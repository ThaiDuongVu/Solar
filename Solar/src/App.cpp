#include "app.h"
#include "debug.h"
#include "time.h"
#include "input.h"
#include "types/vector2.h"
#include <glad.h>
#include <glfw3.h>

namespace solar
{
	void App::Init() {}
	void App::Update(double FrameTime) {}
	void App::Render() {}
	void App::Exit() {}

	// OpenGL window
	template <typename T>
	T* App::window_;

	int App::Width()
	{
		return window_width_;
	}
	int App::Height()
	{
		return window_height_;
	}

	void App::SetWindowSize(int width, int height)
	{
		App::window_width_ = width;
		App::window_height_ = height;
	}
	void App::SetTitle(const char* title)
	{
		App::title_ = title;
	}

	void App::SetResizable(bool resizable)
	{
		glfwWindowHint(GLFW_RESIZABLE, resizable);
	}
	void App::SetFocused(bool focused)
	{
		glfwWindowHint(GLFW_FOCUSED, focused);
	}
	void App::SetMaximized(bool maximized)
	{
		glfwWindowHint(GLFW_MAXIMIZED, maximized);
	}

	void App::Quit()
	{
		glfwSetWindowShouldClose(App::window_<GLFWwindow>, true);
	}

	void App::ClearBackground(Color color)
	{
		glClearColor(color.r_, color.g_, color.b_, color.a_);
		glClear(GL_COLOR_BUFFER_BIT);
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
			Input::key_down_buffer_ = key;
		else if (action == GLFW_RELEASE)
			Input::key_up_buffer_ = key;
	}

	// On cursor enter or exit callback
	void CursorEnterCallback(GLFWwindow* window, int entered)
	{
		if (entered)
			Input::cursor_enter_ = true;
		else
			Input::cursor_exit_ = true;

		Input::cursor_enter_exit_buffer_ = true;
	}

	// Mouse button callback
	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		// Set mouse buffers
		if (action == GLFW_PRESS)
			Input::mouse_down_buffer_ = button;
		else if (action == GLFW_RELEASE)
			Input::mouse_up_buffer_ = button;
	}

	// Mouse scroll callback
	void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{
		Input::scroll_delta_x_ = xoffset;
		Input::scroll_delta_y_ = yoffset;

		Input::scroll_buffer_ = true;
	}
#pragma endregion

	void App::Run()
	{
		// Initialize GLFW
		if (!glfwInit())
		{
			solar::Debug::LogError("Failed to initialize GLFW");
			return;
		}

		// Disable resizability by default
		SetResizable();
		// Focus window by default
		SetFocused();
		// Disable window maximized by default
		SetMaximized();

		// User-defined initialization
		Init();

		// Create a windowed mode window and its OpenGL context
		App::window_<GLFWwindow> = glfwCreateWindow(App::window_width_, App::window_height_, App::title_, NULL, NULL);
		if (!App::window_<GLFWwindow>)
		{
			solar::Debug::LogError("Failed to create window");
			glfwTerminate();
			return;
		}

		// Make the window's context current
		glfwMakeContextCurrent(App::window_<GLFWwindow>);

		// Initialize GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			solar::Debug::LogError("Failed to initialize GLAD");
			return;
		}

		// GLAD viewport
		glViewport(0, 0, App::window_width_, App::window_height_);

		// Buffer size callback
		glfwSetFramebufferSizeCallback(App::window_<GLFWwindow>, FrameBufferSizeCallback);

		// Set input callbacks
		glfwSetKeyCallback(App::window_<GLFWwindow>, KeyboardCallback);
		glfwSetCursorEnterCallback(App::window_<GLFWwindow>, CursorEnterCallback);
		glfwSetMouseButtonCallback(App::window_<GLFWwindow>, MouseButtonCallback);
		glfwSetScrollCallback(App::window_<GLFWwindow>, ScrollCallback);

		// Main program loop
		while (!glfwWindowShouldClose(App::window_<GLFWwindow>))
		{
			// Update frame time
			Time::Update(Time::previous_time_, Time::current_time_);
			Input::Update();

			// User-defined update
			Update(Time::frame_time_);

			// Clear the back ground
			glClear(GL_COLOR_BUFFER_BIT);

			// User-defined render
			Render();

			// Swap front and back buffers
			glfwSwapBuffers(App::window_<GLFWwindow>);
			// Poll for and process events
			glfwPollEvents();
		}

		// User-defined shutdown
		Exit();
		glfwTerminate();
	}
} // namespace solar
