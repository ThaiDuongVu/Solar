#include "Input.h"
#include <glad.h>
#include <glfw3.h>

namespace Solar
{
	//---------- KEYBOARD ----------//
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
	//---------- KEYBOARD ----------//

	//---------- CURSOR ----------//
	double Input::cursorX = 0;
	double Input::cursorY = 0;

	int Input::inputMode = 0;

	Vector2 Input::CursorPosition()
	{
		return Vector2(cursorX, cursorY);
	}

	void Input::SetCursorMode(int mode)
	{
		Input::inputMode = mode;
	}
	//---------- CURSOR ----------//

	void Input::Update()
	{
		glfwGetCursorPos(Solar::App::window<GLFWwindow>, &Input::cursorX, &Input::cursorY);
		glfwSetInputMode(Solar::App::window<GLFWwindow>, GLFW_CURSOR, Input::inputMode);
	}
} // namespace Solar
