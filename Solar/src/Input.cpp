#include "Input.h"
#include <glad.h>
#include <glfw3.h>

namespace Solar
{
#pragma region Keyboard
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
#pragma endregion

#pragma region Cursor
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

	bool Input::cursorEnter = false;
	bool Input::cursorExit = false;

	bool Input::isCursorEnterExit = false;

	bool Input::OnCursorEnter()
	{
		return Input::cursorEnter;
	}

	bool Input::OnCursorExit()
	{
		return Input::cursorExit;
	}
#pragma endregion

#pragma region Mouse
	int Input::mouseDownBuffer = NULL;
	int Input::mouseUpBuffer = NULL;

	bool Input::IsMouseDown(int mouse)
	{
		return glfwGetMouseButton(App::window<GLFWwindow>, mouse) == GLFW_PRESS;
	}

	bool Input::IsMouseUp(int mouse)
	{
		return glfwGetMouseButton(App::window<GLFWwindow>, mouse) == GLFW_RELEASE;
	}

	bool Input::OnMouseDown(int mouse)
	{
		if (mouse == mouseDownBuffer)
		{
			mouseDownBuffer = NULL;
			return true;
		}
		return false;
	}

	bool Input::OnMouseUp(int mouse)
	{
		if (mouse == mouseUpBuffer)
		{
			mouseUpBuffer = NULL;
			return true;
		}
		return false;
	}

	double Input::scrollDeltaX = 0;
	double Input::scrollDeltaY = 0;

	bool Input::isScrolling = false;

	double Input::ScrollDeltaX()
	{
		return scrollDeltaX;
	}

	double Input::ScrollDeltaY()
	{
		return scrollDeltaY;
	}
#pragma endregion

	void Input::Update()
	{
		glfwGetCursorPos(Solar::App::window<GLFWwindow>, &Input::cursorX, &Input::cursorY);
		glfwSetInputMode(Solar::App::window<GLFWwindow>, GLFW_CURSOR, Input::inputMode);

		if (!Input::isScrolling)
		{
			Input::scrollDeltaX = 0;
			Input::scrollDeltaY = 0;
		}
		else
		{
			Input::isScrolling = false;
		}

		if (!Input::isCursorEnterExit)
		{
			Input::cursorEnter = false;
			Input::cursorExit = false;
		}
		else
		{
			Input::isCursorEnterExit = false;
		}
	}
} // namespace Solar
