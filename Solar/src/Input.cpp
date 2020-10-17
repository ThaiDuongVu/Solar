#include "Input.h"
#include <glad.h>
#include <glfw3.h>

namespace Solar
{
	int Input::keyDownBuffer = NULL;
	int Input::keyUpBuffer = NULL;

	bool Input::IsKeyDown(int key)
	{
		return glfwGetKey(Solar::App::window<GLFWwindow>, key) == GLFW_PRESS;
	}

	bool Input::IsKeyUp(int key)
	{
		return glfwGetKey(Solar::App::window<GLFWwindow>, key) == GLFW_RELEASE;
	}

	bool Input::OnKeyDown(int key)
	{
		if (key == keyDownBuffer)
		{
			keyDownBuffer = NULL;
			return true;
		}
		return false;
	}

	bool Input::OnKeyUp(int key)
	{
		if (key == keyUpBuffer)
		{
			keyUpBuffer = NULL;
			return true;
		}
		return false;
	}
} // namespace Solar
