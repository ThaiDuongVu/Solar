#include "input.h"
#include "debug.h"
#include "app.h"
#include <glad.h>
#include <glfw3.h>

namespace Solar
{
#pragma region Keyboard
	int Input::key_down_buffer = NULL;
	int Input::key_up_buffer = NULL;

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
		case Input::Presets::PresetHorizontal:
			return Mathf::Clamp(-(double)(IsKeyDown(Keys::KeyLeft) || IsKeyDown(Keys::KeyA)) + (double)(IsKeyDown(Keys::KeyRight) || IsKeyDown(Keys::KeyD)) + (double)(GetGamepadAxes(GamepadAxes::AxesLeftStickX)), (double)-1.0f, (double)1.0f);
			break;
		case Input::Presets::PresetVertical:
			return Mathf::Clamp(-(double)(IsKeyDown(Keys::KeyDown) || IsKeyDown(Keys::KeyS)) + (double)(IsKeyDown(Keys::KeyUp) || IsKeyDown(Keys::KeyW)) + (double)(-GetGamepadAxes(GamepadAxes::AxesLeftStickY)), (double)-1.0f, (double)1.0f);
			break;

		case Input::Presets::PresetJump:
			return IsKeyDown(Keys::KeySpace) || IsGamepadButtonDown(GamepadButtons::ButtonA);
			break;

		case Input::Presets::PresetFire1:
			return IsMouseDown(MouseButtons::MouseLeft) || IsKeyDown(Keys::KeyZ) || GetGamepadAxes(GamepadAxes::AxesRightTrigger) > 0.0f;
			break;
		case Input::Presets::PresetFire2:
			return IsMouseDown(MouseButtons::MouseRight) || IsKeyDown(Keys::KeyX) || GetGamepadAxes(GamepadAxes::AxesLeftTrigger) > 0.0f;
			break;

		case Input::Presets::PresetCrouch:
			return IsKeyDown(Keys::KeyLeftCtrl) || IsGamepadButtonDown(GamepadButtons::ButtonB);
			break;

		case Input::Presets::PresetEscape:
			return IsKeyDown(Keys::KeyEscape) || IsGamepadButtonDown(GamepadButtons::ButtonStart);
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
		case Input::Presets::PresetHorizontal:
			return Mathf::Clamp(-(double)(IsKeyUp(Keys::KeyLeft) || IsKeyUp(Keys::KeyA)) + (double)(IsKeyUp(Keys::KeyRight) || IsKeyUp(Keys::KeyD)) + (double)(GetGamepadAxes(GamepadAxes::AxesLeftStickX)), (double)-1.0f, (double)1.0f);
			break;
		case Input::Presets::PresetVertical:
			return Mathf::Clamp(-(double)(IsKeyUp(Keys::KeyUp) || IsKeyUp(Keys::KeyS)) + (double)(IsKeyUp(Keys::KeyUp) || IsKeyUp(Keys::KeyW)) + (double)(-GetGamepadAxes(GamepadAxes::AxesLeftStickY)), (double)-1.0f, (double)1.0f);
			break;

		case Input::Presets::PresetJump:
			return IsKeyUp(Keys::KeySpace) || IsGamepadButtonUp(GamepadButtons::ButtonA);
			break;

		case Input::Presets::PresetFire1:
			return IsMouseUp(MouseButtons::MouseLeft) || IsKeyUp(Keys::KeyZ) || GetGamepadAxes(GamepadAxes::AxesRightTrigger) > 0.0f;
			break;
		case Input::Presets::PresetFire2:
			return IsMouseUp(MouseButtons::MouseRight) || IsKeyUp(Keys::KeyX) || GetGamepadAxes(GamepadAxes::AxesLeftTrigger) > 0.0f;
			break;

		case Input::Presets::PresetCrouch:
			return IsKeyUp(Keys::KeyLeftCtrl) || IsGamepadButtonUp(GamepadButtons::ButtonB);
			break;

		case Input::Presets::PresetEscape:
			return IsKeyUp(Keys::KeyEscape) || IsGamepadButtonUp(GamepadButtons::ButtonStart);
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
		case Input::Presets::PresetHorizontal:
			return -(double)(OnKeyDown(Keys::KeyLeft) || OnKeyDown(Keys::KeyA)) + (double)(OnKeyDown(Keys::KeyRight) || OnKeyDown(Keys::KeyD));
			break;
		case Input::Presets::PresetVertical:
			return -(double)(OnKeyDown(Keys::KeyDown) || OnKeyDown(Keys::KeyS)) + (double)(OnKeyDown(Keys::KeyUp) || OnKeyDown(Keys::KeyW));
			break;

		case Input::Presets::PresetJump:
			return OnKeyDown(Keys::KeySpace) || OnGamepadButtonDown(GamepadButtons::ButtonA);
			break;

		case Input::Presets::PresetFire1:
			return OnMouseDown(MouseButtons::MouseLeft) || OnKeyDown(Keys::KeyZ) || GetGamepadAxes(GamepadAxes::AxesRightTrigger) <= 0.0f;
			break;
		case Input::Presets::PresetFire2:
			return OnMouseDown(MouseButtons::MouseRight) || OnKeyDown(Keys::KeyX) || GetGamepadAxes(GamepadAxes::AxesLeftTrigger) <= 0.0f;
			break;

		case Input::Presets::PresetCrouch:
			return OnKeyDown(Keys::KeyLeftCtrl) || OnGamepadButtonDown(GamepadButtons::ButtonB);
			break;

		case Input::Presets::PresetEscape:
			return OnKeyDown(Keys::KeyEscape) || OnGamepadButtonDown(GamepadButtons::ButtonStart);
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
		case Input::Presets::PresetHorizontal:
			return -(double)(OnKeyUp(Keys::KeyLeft) || OnKeyUp(Keys::KeyA)) + (double)(OnKeyUp(Keys::KeyRight) || OnKeyUp(Keys::KeyD));
			break;
		case Input::Presets::PresetVertical:
			return -(double)(OnKeyUp(Keys::KeyUp) || OnKeyUp(Keys::KeyS)) + (double)(OnKeyUp(Keys::KeyUp) || OnKeyUp(Keys::KeyW));
			break;

		case Input::Presets::PresetJump:
			return OnKeyUp(Keys::KeySpace) || OnGamepadButtonUp(GamepadButtons::ButtonA);
			break;

		case Input::Presets::PresetFire1:
			return OnMouseUp(MouseButtons::MouseLeft) || OnKeyUp(Keys::KeyZ) || GetGamepadAxes(GamepadAxes::AxesRightTrigger) <= 0.0f;
			break;
		case Input::Presets::PresetFire2:
			return OnMouseUp(MouseButtons::MouseRight) || OnKeyUp(Keys::KeyX) || GetGamepadAxes(GamepadAxes::AxesLeftTrigger) <= 0.0f;
			break;

		case Input::Presets::PresetCrouch:
			return OnKeyUp(Keys::KeyLeftCtrl) || OnGamepadButtonUp(GamepadButtons::ButtonB);
			break;

		case Input::Presets::PresetEscape:
			return OnKeyUp(Keys::KeyEscape) || OnGamepadButtonUp(GamepadButtons::ButtonStart);
			break;

		default:
			return 0;
			break;
		}
	}
#pragma endregion

	void Input::Update()
	{
		glfwGetCursorPos(Solar::App::window<GLFWwindow>, &Input::cursor_x, &Input::cursor_y);
		glfwSetInputMode(Solar::App::window<GLFWwindow>, GLFW_CURSOR, Input::cursor_mode);

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
		for (int i = Input::Gamepads::Gamepad1; i <= Input::Gamepads::Gamepad1; i++)
		{
			if (Input::IsGamepadPresent(i))
				gamepad_axes[i] = glfwGetJoystickAxes(i, &Input::gamepad_axes_count);
		}
	}
} // namespace Solar
