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

	Vector2 App::Size()
	{
		return Vector2(App::width, App::height);
	}
	int App::Width()
	{
		return width;
	}
	int App::Height()
	{
		return height;
	}
	std::string App::Title()
	{
		return title;
	}
	bool App::Resizable()
	{
		return resizable;
	}
	bool App::Focused()
	{
		return focused;
	}
	bool App::Maximized()
	{
		return maximized;
	}
	bool App::Visible()
	{
		return visible;
	}
	bool App::Decorated()
	{
		return decorated;
	}
	bool App::Floating()
	{
		return floating;
	}
	Vector2 App::Position()
	{
		return Vector2(position_x, position_y);
	}
	double App::PositionX()
	{
		return position_x;
	}
	double App::PositionY()
	{
		return position_y;
	}

	void App::SetSize(int width, int height)
	{
		App::width = width;
		App::height = height;
		glfwSetWindowSize(App::window<GLFWwindow>, App::width, App::height);
	}
	void App::SetWidth(int width)
	{
		App::width = width;
		glfwSetWindowSize(App::window<GLFWwindow>, App::width, App::height);
	}
	void App::SetHeight(int height)
	{
		App::height = height;
		glfwSetWindowSize(App::window<GLFWwindow>, App::width, App::height);
	}
	void App::SetTitle(std::string title)
	{
		App::title = title;
		glfwSetWindowTitle(App::window<GLFWwindow>, App::title.c_str());
	}
	void App::SetResizable(bool resizable)
	{
		App::resizable = resizable;
		glfwWindowHint(GLFW_RESIZABLE, App::resizable);
		glfwSetWindowAttrib(App::window<GLFWwindow>, GLFW_RESIZABLE, App::resizable);
	}
	void App::SetFocused(bool focused)
	{
		App::focused = focused;
		glfwWindowHint(GLFW_FOCUSED, App::focused);
		glfwSetWindowAttrib(App::window<GLFWwindow>, GLFW_FOCUSED, App::focused);
	}
	void App::SetMaximized(bool maximized)
	{
		App::maximized = maximized;
		glfwWindowHint(GLFW_MAXIMIZED, App::maximized);
		glfwSetWindowAttrib(App::window<GLFWwindow>, GLFW_MAXIMIZED, App::maximized);
	}
	void App::SetVisible(bool visible)
	{
		App::visible = visible;
		glfwWindowHint(GLFW_VISIBLE, App::visible);
		glfwSetWindowAttrib(App::window<GLFWwindow>, GLFW_MAXIMIZED, App::visible);
	}
	void App::SetDecorated(bool decorated)
	{
		App::decorated = decorated;
		glfwWindowHint(GLFW_VISIBLE, App::decorated);
		glfwSetWindowAttrib(App::window<GLFWwindow>, GLFW_MAXIMIZED, App::decorated);
	}
	void App::SetFloating(bool floating)
	{
		App::floating = floating;
		glfwWindowHint(GLFW_FLOATING, App::floating);
		glfwSetWindowAttrib(App::window<GLFWwindow>, GLFW_FLOATING, App::floating);
	}
	void App::SetPosition(int position_x, int position_y)
	{
		App::position_x = position_x;
		App::position_y = position_y;
		glfwSetWindowPos(App::window<GLFWwindow>, App::position_x, App::position_y);
	}
	void App::SetPosition(Vector2 position)
	{
		App::position_x = position.x;
		App::position_y = position.y;
		glfwSetWindowPos(App::window<GLFWwindow>, App::position_x, App::position_y);
	}
	void App::SetPositionX(int position_x)
	{
		App::position_x = position_x;
		glfwSetWindowPos(App::window<GLFWwindow>, App::position_x, App::position_y);
	}
	void App::SetPositionY(int position_y)
	{
		App::position_y = position_y;
		glfwSetWindowPos(App::window<GLFWwindow>, App::position_x, App::position_y);
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

		// Create a windowed mode window and its OpenGL context
		App::window<GLFWwindow> = glfwCreateWindow(App::width, App::height, App::title.c_str(), NULL, NULL);
		if (!App::window<GLFWwindow>)
		{
			Solar::Debug::LogError("Failed to create window");
			glfwTerminate();
			return;
		}

		SetResizable();
		SetFocused();
		SetMaximized();
		SetVisible();
		SetDecorated();
		SetFloating();

		Init();

		// Make the window's context current
		glfwMakeContextCurrent(App::window<GLFWwindow>);

		// Initialize GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Solar::Debug::LogError("Failed to initialize GLAD");
			return;
		}

		// GLAD viewport
		glViewport(0, 0, App::width, App::height);

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
