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

	bool Input::IsMouseDown(int button)
	{
		return glfwGetMouseButton(App::window<GLFWwindow>, button) == GLFW_PRESS;
	}

	bool Input::IsMouseUp(int button)
	{
		return glfwGetMouseButton(App::window<GLFWwindow>, button) == GLFW_RELEASE;
	}

	bool Input::OnMouseDown(int button)
	{
		if (button == mouse_down_buffer)
		{
			mouse_down_buffer = NULL;
			return true;
		}
		return false;
	}

	bool Input::OnMouseUp(int button)
	{
		if (button == mouse_up_buffer)
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

#pragma region Gamepad
	bool Input::IsGamepadPresent(int gamepad)
	{
		return glfwJoystickPresent(gamepad);
	}

	const float* Input::gamepad_axes[] = { 0 };
	int Input::gamepad_axes_count = 0;

	float Input::GetGamepadAxes(int axes, int gamepad)
	{
		if (!Input::IsGamepadPresent(gamepad))
			return 0;

		return Input::gamepad_axes[gamepad][axes];
	}

	int Input::gamepad_button_count = 0;

	int Input::button_down_buffer = NULL;
	int Input::button_up_buffer = NULL;

	bool Input::IsGamepadButtonDown(int button, int gamepad)
	{
		if (!Input::IsGamepadPresent(gamepad))
			return false;

		return glfwGetJoystickButtons(gamepad, &Input::gamepad_button_count)[button] == GLFW_PRESS;
	}

	bool Input::IsGamepadButtonUp(int button, int gamepad)
	{
		if (!Input::IsGamepadPresent(gamepad))
			return false;

		return glfwGetJoystickButtons(gamepad, &Input::gamepad_button_count)[button] == GLFW_RELEASE;
	}

	// Currently not working
	// TODO: Investigate further
	bool Input::OnGamepadButtonDown(int button, int gamepad)
	{
		if (!Input::IsGamepadPresent(gamepad))
			return false;

		return false;
	}

	bool Input::OnGamepadButtonUp(int button, int gamepad)
	{
		if (!Input::IsGamepadPresent(gamepad))
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
			return Mathf::Clamp(-(double)(IsKeyDown(Keys::kKeyLeft) || IsKeyDown(Keys::kKeyA)) + (double)(IsKeyDown(Keys::kKeyRight) || IsKeyDown(Keys::kKeyD)) + (double)(GetGamepadAxes(GamepadAxes::kAxesLeftStickX)), (double)-1.0f, (double)1.0f);
			break;
		case Input::Presets::kPresetVertical:
			return Mathf::Clamp(-(double)(IsKeyDown(Keys::kKeyDown) || IsKeyDown(Keys::kKeyS)) + (double)(IsKeyDown(Keys::kKeyUp) || IsKeyDown(Keys::kKeyW)) + (double)(-GetGamepadAxes(GamepadAxes::kAxesLeftStickY)), (double)-1.0f, (double)1.0f);
			break;

		case Input::Presets::kPresetJump:
			return IsKeyDown(Keys::kKeySpace) || IsGamepadButtonDown(GamepadButtons::kButtonA);
			break;

		case Input::Presets::kPresetFire1:
			return IsMouseDown(MouseButtons::kMouseLeft) || IsKeyDown(Keys::kKeyZ) || GetGamepadAxes(GamepadAxes::kAxesRightTrigger) > 0.0f;
			break;
		case Input::Presets::kPresetFire2:
			return IsMouseDown(MouseButtons::kMouseRight) || IsKeyDown(Keys::kKeyX) || GetGamepadAxes(GamepadAxes::kAxesLeftTrigger) > 0.0f;
			break;

		case Input::Presets::kPresetCrouch:
			return IsKeyDown(Keys::kKeyLeftCtrl) || IsGamepadButtonDown(GamepadButtons::kButtonB);
			break;

		case Input::Presets::kPresetEscape:
			return IsKeyDown(Keys::kKeyEscape) || IsGamepadButtonDown(GamepadButtons::kButtonStart);
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
			return Mathf::Clamp(-(double)(IsKeyUp(Keys::kKeyLeft) || IsKeyUp(Keys::kKeyA)) + (double)(IsKeyUp(Keys::kKeyRight) || IsKeyUp(Keys::kKeyD)) + (double)(GetGamepadAxes(GamepadAxes::kAxesLeftStickX)), (double)-1.0f, (double)1.0f);
			break;
		case Input::Presets::kPresetVertical:
			return Mathf::Clamp(-(double)(IsKeyUp(Keys::kKeyUp) || IsKeyUp(Keys::kKeyS)) + (double)(IsKeyUp(Keys::kKeyUp) || IsKeyUp(Keys::kKeyW)) + (double)(-GetGamepadAxes(GamepadAxes::kAxesLeftStickY)), (double)-1.0f, (double)1.0f);
			break;

		case Input::Presets::kPresetJump:
			return IsKeyUp(Keys::kKeySpace) || IsGamepadButtonUp(GamepadButtons::kButtonA);
			break;

		case Input::Presets::kPresetFire1:
			return IsMouseUp(MouseButtons::kMouseLeft) || IsKeyUp(Keys::kKeyZ) || GetGamepadAxes(GamepadAxes::kAxesRightTrigger) > 0.0f;
			break;
		case Input::Presets::kPresetFire2:
			return IsMouseUp(MouseButtons::kMouseRight) || IsKeyUp(Keys::kKeyX) || GetGamepadAxes(GamepadAxes::kAxesLeftTrigger) > 0.0f;
			break;

		case Input::Presets::kPresetCrouch:
			return IsKeyUp(Keys::kKeyLeftCtrl) || IsGamepadButtonUp(GamepadButtons::kButtonB);
			break;

		case Input::Presets::kPresetEscape:
			return IsKeyUp(Keys::kKeyEscape) || IsGamepadButtonUp(GamepadButtons::kButtonStart);
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
			return OnKeyDown(Keys::kKeySpace) || OnGamepadButtonDown(GamepadButtons::kButtonA);
			break;

		case Input::Presets::kPresetFire1:
			return OnMouseDown(MouseButtons::kMouseLeft) || OnKeyDown(Keys::kKeyZ) || GetGamepadAxes(GamepadAxes::kAxesRightTrigger) <= 0.0f;
			break;
		case Input::Presets::kPresetFire2:
			return OnMouseDown(MouseButtons::kMouseRight) || OnKeyDown(Keys::kKeyX) || GetGamepadAxes(GamepadAxes::kAxesLeftTrigger) <= 0.0f;
			break;

		case Input::Presets::kPresetCrouch:
			return OnKeyDown(Keys::kKeyLeftCtrl) || OnGamepadButtonDown(GamepadButtons::kButtonB);
			break;

		case Input::Presets::kPresetEscape:
			return OnKeyDown(Keys::kKeyEscape) || OnGamepadButtonDown(GamepadButtons::kButtonStart);
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
			return OnKeyUp(Keys::kKeySpace) || OnGamepadButtonUp(GamepadButtons::kButtonA);
			break;

		case Input::Presets::kPresetFire1:
			return OnMouseUp(MouseButtons::kMouseLeft) || OnKeyUp(Keys::kKeyZ) || GetGamepadAxes(GamepadAxes::kAxesRightTrigger) <= 0.0f;
			break;
		case Input::Presets::kPresetFire2:
			return OnMouseUp(MouseButtons::kMouseRight) || OnKeyUp(Keys::kKeyX) || GetGamepadAxes(GamepadAxes::kAxesLeftTrigger) <= 0.0f;
			break;

		case Input::Presets::kPresetCrouch:
			return OnKeyUp(Keys::kKeyLeftCtrl) || OnGamepadButtonUp(GamepadButtons::kButtonB);
			break;

		case Input::Presets::kPresetEscape:
			return OnKeyUp(Keys::kKeyEscape) || OnGamepadButtonUp(GamepadButtons::kButtonStart);
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
		for (int i = Input::Gamepads::kGamepad1; i <= Input::Gamepads::kGamepad1; i++)
		{
			if (Input::IsGamepadPresent(i))
				gamepad_axes[i] = glfwGetJoystickAxes(i, &Input::gamepad_axes_count);
		}
	}
} // namespace solar
