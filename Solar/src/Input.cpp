#include "Input.h"
#include "Debug.h"
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
		if (key == Input::keyDownBuffer)
		{
			Input::keyDownBuffer = NULL;
			return true;
		}
		return false;
	}

	bool Input::OnKeyUp(int key)
	{
		if (key == Input::keyUpBuffer)
		{
			Input::keyUpBuffer = NULL;
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

	bool Input::cursorEnterExitBuffer = false;

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

	bool Input::scrollBuffer = false;

	double Input::ScrollDeltaX()
	{
		return scrollDeltaX;
	}

	double Input::ScrollDeltaY()
	{
		return scrollDeltaY;
	}
#pragma endregion

#pragma region Joystick
	bool Input::IsJoystickPresent(int joystick)
	{
		return glfwJoystickPresent(joystick);
	}

	const float* Input::joystickAxes = 0;
	int Input::joystickCount = 0;

	float Input::GetJoystick(int joystick)
	{
		return Input::joystickAxes[joystick];
	}

#pragma endregion

	void Input::Update()
	{
		glfwGetCursorPos(Solar::App::window<GLFWwindow>, &Input::cursorX, &Input::cursorY);
		glfwSetInputMode(Solar::App::window<GLFWwindow>, GLFW_CURSOR, Input::inputMode);

#pragma region Buffer Handling
		if (!Input::scrollBuffer)
		{
			Input::scrollDeltaX = 0;
			Input::scrollDeltaY = 0;
		}
		else
		{
			Input::scrollBuffer = false;
		}

		if (!Input::cursorEnterExitBuffer)
		{
			Input::cursorEnter = false;
			Input::cursorExit = false;
		}
		else
		{
			Input::cursorEnterExitBuffer = false;
		}
#pragma endregion

		joystickAxes = glfwGetJoystickAxes(Solar::Input::JOYSTICKS::JOYSTICK_1, &Input::joystickCount);
	}
} // namespace Solar
