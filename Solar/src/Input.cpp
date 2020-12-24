#include "input.h"
#include "debug.h"
#include "app.h"
#include <glad.h>
#include <glfw3.h>

namespace solar
{
#pragma region Keyboard
	int Input::key_down_buffer = NULL;
	int Input::key_up_buffer = NULL;

	bool Input::IsKeyDown(int key)
	{
		return glfwGetKey(solar::App::window<GLFWwindow>, key) == GLFW_PRESS;
	}

	bool Input::IsKeyUp(int key)
	{
		return glfwGetKey(solar::App::window<GLFWwindow>, key) == GLFW_RELEASE;
	}

	bool Input::OnKeyDown(int key)
	{
		if (key == Input::key_down_buffer)
		{
			Input::key_down_buffer = NULL;
			return true;
		}
		return false;
	}

	bool Input::OnKeyUp(int key)
	{
		if (key == Input::key_up_buffer)
		{
			Input::key_up_buffer = NULL;
			return true;
		}
		return false;
	}
#pragma endregion

#pragma region Cursor
	double Input::cursor_x = 0;
	double Input::cursor_y = 0;

	int Input::cursor_mode = 0;

	Vector2 Input::CursorPosition()
	{
		return Vector2(cursor_x, cursor_y);
	}

	void Input::SetCursorMode(int mode)
	{
		Input::cursor_mode = mode;
	}

	bool Input::cursor_enter = false;
	bool Input::cursor_exit = false;

	bool Input::cursor_enter_exit_buffer = false;

	bool Input::OnCursorEnter()
	{
		return Input::cursor_enter;
	}

	bool Input::OnCursorExit()
	{
		return Input::cursor_exit;
	}
#pragma endregion

#pragma region Mouse
	int Input::mouse_down_buffer = NULL;
	int Input::mouse_up_buffer = NULL;

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
		if (mouse == mouse_down_buffer)
		{
			mouse_down_buffer = NULL;
			return true;
		}
		return false;
	}

	bool Input::OnMouseUp(int mouse)
	{
		if (mouse == mouse_up_buffer)
		{
			mouse_up_buffer = NULL;
			return true;
		}
		return false;
	}

	double Input::scroll_delta_x = 0;
	double Input::scroll_delta_y = 0;

	bool Input::scroll_buffer = false;

	double Input::ScrollDeltaX()
	{
		return scroll_delta_x;
	}

	double Input::ScrollDeltaY()
	{
		return scroll_delta_y;
	}
#pragma endregion

#pragma region Joystick
	bool Input::IsJoystickPresent(int joystick)
	{
		return glfwJoystickPresent(joystick);
	}

	const float* Input::joystick_axes[] = { 0 };
	int Input::joystick_axes_count = 0;

	float Input::GetJoystickAxes(int axes, int joystick)
	{
		if (!Input::IsJoystickPresent(joystick))
			return 0;

		return Input::joystick_axes[joystick][axes];
	}

	int Input::joystick_button_count = 0;

	int Input::button_down_buffer = NULL;
	int Input::button_up_buffer = NULL;

	bool Input::IsJoystickButtonDown(int button, int joystick)
	{
		if (!Input::IsJoystickPresent(joystick))
			return false;

		return glfwGetJoystickButtons(joystick, &Input::joystick_button_count)[button] == GLFW_PRESS;
	}

	bool Input::IsJoystickButtonUp(int button, int joystick)
	{
		if (!Input::IsJoystickPresent(joystick))
			return false;

		return glfwGetJoystickButtons(joystick, &Input::joystick_button_count)[button] == GLFW_RELEASE;
	}

	// Currently not working
	// TODO: Investigate further
	bool Input::OnJoystickButtonDown(int button, int joystick)
	{
		if (!Input::IsJoystickPresent(joystick))
			return false;

		return false;
	}

	bool Input::OnJoystickButtonUp(int button, int joystick)
	{
		if (!Input::IsJoystickPresent(joystick))
			return false;

		return false;
	}

#pragma endregion

#pragma region Presets
	double Input::IsPresetDown(Presets preset)
	{
		switch (preset)
		{
		case Input::Presets::kPresetHorizontal:
			return Mathf::Clamp(-(double)(IsKeyDown(Keys::kKeyLeft) || IsKeyDown(Keys::kKeyA)) + (double)(IsKeyDown(Keys::kKeyRight) || IsKeyDown(Keys::kKeyD)) + (double)(GetJoystickAxes(JoystickAxes::kAxesLeftStickX)), (double)-1.0f, (double)1.0f);
			break;
		case Input::Presets::kPresetVertical:
			return Mathf::Clamp(-(double)(IsKeyDown(Keys::kKeyDown) || IsKeyDown(Keys::kKeyS)) + (double)(IsKeyDown(Keys::kKeyUp) || IsKeyDown(Keys::kKeyW)) + (double)(-GetJoystickAxes(JoystickAxes::kAxesLeftStickY)), (double)-1.0f, (double)1.0f);
			break;

		case Input::Presets::kPresetJump:
			return IsKeyDown(Keys::kKeySpace) || IsJoystickButtonDown(JoystickButtons::kButtonA);
			break;

		case Input::Presets::kPresetFire1:
			return IsMouseDown(MouseButtons::kMouseLeft) || IsKeyDown(Keys::kKeyZ) || GetJoystickAxes(JoystickAxes::kAxesRightTrigger) > 0.0f;
			break;
		case Input::Presets::kPresetFire2:
			return IsMouseDown(MouseButtons::kMouseRight) || IsKeyDown(Keys::kKeyX) || GetJoystickAxes(JoystickAxes::kAxesLeftTrigger) > 0.0f;
			break;

		case Input::Presets::kPresetCrouch:
			return IsKeyDown(Keys::kKeyLeftCtrl) || IsJoystickButtonDown(JoystickButtons::kButtonB);
			break;

		case Input::Presets::kPresetEscape:
			return IsKeyDown(Keys::kKeyEscape) || IsJoystickButtonDown(JoystickButtons::kButtonStart);
			break;

		default:
			return 0;
			break;
		}
	}
	double Input::IsPresetUp(Presets preset)
	{
		switch (preset)
		{
		case Input::Presets::kPresetHorizontal:
			return Mathf::Clamp(-(double)(IsKeyUp(Keys::kKeyLeft) || IsKeyUp(Keys::kKeyA)) + (double)(IsKeyUp(Keys::kKeyRight) || IsKeyUp(Keys::kKeyD)) + (double)(GetJoystickAxes(JoystickAxes::kAxesLeftStickX)), (double)-1.0f, (double)1.0f);
			break;
		case Input::Presets::kPresetVertical:
			return Mathf::Clamp(-(double)(IsKeyUp(Keys::kKeyUp) || IsKeyUp(Keys::kKeyS)) + (double)(IsKeyUp(Keys::kKeyUp) || IsKeyUp(Keys::kKeyW)) + (double)(-GetJoystickAxes(JoystickAxes::kAxesLeftStickY)), (double)-1.0f, (double)1.0f);
			break;

		case Input::Presets::kPresetJump:
			return IsKeyUp(Keys::kKeySpace) || IsJoystickButtonUp(JoystickButtons::kButtonA);
			break;

		case Input::Presets::kPresetFire1:
			return IsMouseUp(MouseButtons::kMouseLeft) || IsKeyUp(Keys::kKeyZ) || GetJoystickAxes(JoystickAxes::kAxesRightTrigger) > 0.0f;
			break;
		case Input::Presets::kPresetFire2:
			return IsMouseUp(MouseButtons::kMouseRight) || IsKeyUp(Keys::kKeyX) || GetJoystickAxes(JoystickAxes::kAxesLeftTrigger) > 0.0f;
			break;

		case Input::Presets::kPresetCrouch:
			return IsKeyUp(Keys::kKeyLeftCtrl) || IsJoystickButtonUp(JoystickButtons::kButtonB);
			break;

		case Input::Presets::kPresetEscape:
			return IsKeyUp(Keys::kKeyEscape) || IsJoystickButtonUp(JoystickButtons::kButtonStart);
			break;

		default:
			return 0;
			break;
		}
	}

	double Input::OnPresetDown(Presets preset)
	{
		switch (preset)
		{
		case Input::Presets::kPresetHorizontal:
			return -(double)(OnKeyDown(Keys::kKeyLeft) || OnKeyDown(Keys::kKeyA)) + (double)(OnKeyDown(Keys::kKeyRight) || OnKeyDown(Keys::kKeyD));
			break;
		case Input::Presets::kPresetVertical:
			return -(double)(OnKeyDown(Keys::kKeyDown) || OnKeyDown(Keys::kKeyS)) + (double)(OnKeyDown(Keys::kKeyUp) || OnKeyDown(Keys::kKeyW));
			break;

		case Input::Presets::kPresetJump:
			return OnKeyDown(Keys::kKeySpace) || OnJoystickButtonDown(JoystickButtons::kButtonA);
			break;

		case Input::Presets::kPresetFire1:
			return OnMouseDown(MouseButtons::kMouseLeft) || OnKeyDown(Keys::kKeyZ) || GetJoystickAxes(JoystickAxes::kAxesRightTrigger) <= 0.0f;
			break;
		case Input::Presets::kPresetFire2:
			return OnMouseDown(MouseButtons::kMouseRight) || OnKeyDown(Keys::kKeyX) || GetJoystickAxes(JoystickAxes::kAxesLeftTrigger) <= 0.0f;
			break;

		case Input::Presets::kPresetCrouch:
			return OnKeyDown(Keys::kKeyLeftCtrl) || OnJoystickButtonDown(JoystickButtons::kButtonB);
			break;

		case Input::Presets::kPresetEscape:
			return OnKeyDown(Keys::kKeyEscape) || OnJoystickButtonDown(JoystickButtons::kButtonStart);
			break;

		default:
			return 0;
			break;
		}
	}
	double Input::OnPresetUp(Presets preset)
	{
		switch (preset)
		{
		case Input::Presets::kPresetHorizontal:
			return -(double)(OnKeyUp(Keys::kKeyLeft) || OnKeyUp(Keys::kKeyA)) + (double)(OnKeyUp(Keys::kKeyRight) || OnKeyUp(Keys::kKeyD));
			break;
		case Input::Presets::kPresetVertical:
			return -(double)(OnKeyUp(Keys::kKeyUp) || OnKeyUp(Keys::kKeyS)) + (double)(OnKeyUp(Keys::kKeyUp) || OnKeyUp(Keys::kKeyW));
			break;

		case Input::Presets::kPresetJump:
			return OnKeyUp(Keys::kKeySpace) || OnJoystickButtonUp(JoystickButtons::kButtonA);
			break;

		case Input::Presets::kPresetFire1:
			return OnMouseUp(MouseButtons::kMouseLeft) || OnKeyUp(Keys::kKeyZ) || GetJoystickAxes(JoystickAxes::kAxesRightTrigger) <= 0.0f;
			break;
		case Input::Presets::kPresetFire2:
			return OnMouseUp(MouseButtons::kMouseRight) || OnKeyUp(Keys::kKeyX) || GetJoystickAxes(JoystickAxes::kAxesLeftTrigger) <= 0.0f;
			break;

		case Input::Presets::kPresetCrouch:
			return OnKeyUp(Keys::kKeyLeftCtrl) || OnJoystickButtonUp(JoystickButtons::kButtonB);
			break;

		case Input::Presets::kPresetEscape:
			return OnKeyUp(Keys::kKeyEscape) || OnJoystickButtonUp(JoystickButtons::kButtonStart);
			break;

		default:
			return 0;
			break;
		}
	}
#pragma endregion

	void Input::Update()
	{
		glfwGetCursorPos(solar::App::window<GLFWwindow>, &Input::cursor_x, &Input::cursor_y);
		glfwSetInputMode(solar::App::window<GLFWwindow>, GLFW_CURSOR, Input::cursor_mode);

#pragma region Buffer Handling
		if (!Input::scroll_buffer)
		{
			Input::scroll_delta_x = 0;
			Input::scroll_delta_y = 0;
		}
		else
		{
			Input::scroll_buffer = false;
		}

		if (!Input::cursor_enter_exit_buffer)
		{
			Input::cursor_enter = false;
			Input::cursor_exit = false;
		}
		else
		{
			Input::cursor_enter_exit_buffer = false;
		}
#pragma endregion

		// Update all input axes
		for (int i = Input::Joysticks::kJoystick1; i <= Input::Joysticks::kJoystickLast; i++)
		{
			if (Input::IsJoystickPresent(i))
				joystick_axes[i] = glfwGetJoystickAxes(i, &Input::joystick_axes_count);
		}
	}
} // namespace solar
