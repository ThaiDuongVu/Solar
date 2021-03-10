#include "app.h"
#include "debug.h"
#include "game_time.h"
#include "input.h"
#include "types/vector2.h"
#include <glad.h>
#include <glfw3.h>

namespace Solar
{
	void App::Init() {}
	void App::Update() {}
	void App::Render() {}
	void App::Exit() {}

	// OpenGL window
	template <typename T>
	T* App::window;

	int App::Width()
	{
		return window_width;
	}
	int App::Height()
	{
		return window_height;
	}

	void App::SetWindowSize(int width, int height)
	{
		App::window_width = width;
		App::window_height = height;
	}
	void App::SetWindowTitle(const char* title)
	{
		App::title = title;
	}

	void App::SetWindowResizable(bool resizable)
	{
		glfwWindowHint(GLFW_RESIZABLE, resizable);
	}
	void App::SetWindowFocused(bool focused)
	{
		glfwWindowHint(GLFW_FOCUSED, focused);
	}
	void App::SetWindowMaximized(bool maximized)
	{
		glfwWindowHint(GLFW_MAXIMIZED, maximized);
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
			Input::key_down_buffer = key;
		else if (action == GLFW_RELEASE)
			Input::key_up_buffer = key;
	}

	// On cursor enter or exit callback
	void CursorEnterCallback(GLFWwindow* window, int entered)
	{
		if (entered)
			Input::cursor_enter = true;
		else
			Input::cursor_exit = true;

		Input::cursor_enter_exit_buffer = true;
	}

	// Mouse button callback
	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		// Set mouse buffers
		if (action == GLFW_PRESS)
			Input::mouse_down_buffer = button;
		else if (action == GLFW_RELEASE)
			Input::mouse_up_buffer = button;
	}

	// Mouse scroll callback
	void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{
		Input::scroll_delta_x = xoffset;
		Input::scroll_delta_y = yoffset;

		Input::scroll_buffer = true;
	}
#pragma endregion

	void App::Run()
	{
		// Initialize GLFW
		if (!glfwInit())
		{
			Solar::Debug::LogError("Failed to initialize GLFW");
			return;
		}

		viewport = Viewport();

		// Disable resizability by default
		SetWindowResizable();
		// Focus window by default
		SetWindowFocused();
		// Disable window maximized by default
		SetWindowMaximized();

		Init();

		// Create a windowed mode window and its OpenGL context
		App::window<GLFWwindow> = glfwCreateWindow(App::window_width, App::window_height, App::title, NULL, NULL);
		if (!App::window<GLFWwindow>)
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
		glViewport(0, 0, App::window_width, App::window_height);

		// Buffer size callback
		glfwSetFramebufferSizeCallback(App::window<GLFWwindow>, FrameBufferSizeCallback);

		// Input callbacks
		glfwSetKeyCallback(App::window<GLFWwindow>, KeyboardCallback);
		glfwSetCursorEnterCallback(App::window<GLFWwindow>, CursorEnterCallback);
		glfwSetMouseButtonCallback(App::window<GLFWwindow>, MouseButtonCallback);
		glfwSetScrollCallback(App::window<GLFWwindow>, ScrollCallback);

		// Main program loop
		while (!glfwWindowShouldClose(App::window<GLFWwindow>))
		{
			// Update frame time
			Time::Update();
			// Update input handler
			Input::Update();

			Update();

			// Shake current viewport if needed
			if (viewport.is_shaking)
				viewport.Shake();

			// Clear the viewport background
			glClearColor(viewport.background_color.r, viewport.background_color.g, viewport.background_color.b, viewport.background_color.a);
			glClear(GL_COLOR_BUFFER_BIT);

			Render();

			// Swap front and back buffers
			glfwSwapBuffers(App::window<GLFWwindow>);
			// Poll for and process events
			glfwPollEvents();
		}

		Exit();
		glfwTerminate();
	}
} // namespace Solar
