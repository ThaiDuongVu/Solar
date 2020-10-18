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

	//---------- MOUSE ----------//
	double Input::mouseX = 0;
	double Input::mouseY = 0;

	Vector2 Input::MousePosition()
	{
		return Vector2(mouseX, mouseY);
	}

	//---------- MOUSE ----------//

	void Input::Update()
	{
		glfwGetCursorPos(Solar::App::window<GLFWwindow>, &mouseX, &mouseY);
	}
} // namespace Solar
