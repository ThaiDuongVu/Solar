#include "input.h"
#include "debug.h"
#include "app.h"
#include <glad.h>
#include <glfw3.h>

namespace solar
{
#pragma region Keyboard
	int Input::key_down_buffer_ = NULL;
	int Input::key_up_buffer_ = NULL;

	bool Input::IsKeyDown(int key)
	{
		return glfwGetKey(solar::App::window_<GLFWwindow>, key) == GLFW_PRESS;
	}

	bool Input::IsKeyUp(int key)
	{
		return glfwGetKey(solar::App::window_<GLFWwindow>, key) == GLFW_RELEASE;
	}

	bool Input::OnKeyDown(int key)
	{
		if (key == Input::key_down_buffer_)
		{
			Input::key_down_buffer_ = NULL;
			return true;
		}
		return false;
	}

	bool Input::OnKeyUp(int key)
	{
		if (key == Input::key_up_buffer_)
		{
			Input::key_up_buffer_ = NULL;
			return true;
		}
		return false;
	}
#pragma endregion

#pragma region Cursor
	double Input::cursor_x_ = 0;
	double Input::cursor_y_ = 0;

	int Input::cursor_mode_ = 0;

	Vector2 Input::CursorPosition()
	{
		return Vector2(cursor_x_, cursor_y_);
	}

	void Input::SetCursorMode(int mode)
	{
		Input::cursor_mode_ = mode;
	}

	bool Input::cursor_enter_ = false;
	bool Input::cursor_exit_ = false;

	bool Input::cursor_enter_exit_buffer_ = false;

	bool Input::OnCursorEnter()
	{
		return Input::cursor_enter_;
	}

	bool Input::OnCursorExit()
	{
		return Input::cursor_exit_;
	}
#pragma endregion

#pragma region Mouse
	int Input::mouse_down_buffer_ = NULL;
	int Input::mouse_up_buffer_ = NULL;

	bool Input::IsMouseDown(int mouse)
	{
		return glfwGetMouseButton(App::window_<GLFWwindow>, mouse) == GLFW_PRESS;
	}

	bool Input::IsMouseUp(int mouse)
	{
		return glfwGetMouseButton(App::window_<GLFWwindow>, mouse) == GLFW_RELEASE;
	}

	bool Input::OnMouseDown(int mouse)
	{
		if (mouse == mouse_down_buffer_)
		{
			mouse_down_buffer_ = NULL;
			return true;
		}
		return false;
	}

	bool Input::OnMouseUp(int mouse)
	{
		if (mouse == mouse_up_buffer_)
		{
			mouse_up_buffer_ = NULL;
			return true;
		}
		return false;
	}

	double Input::scroll_delta_x_ = 0;
	double Input::scroll_delta_y_ = 0;

	bool Input::scroll_buffer_ = false;

	double Input::ScrollDeltaX()
	{
		return scroll_delta_x_;
	}

	double Input::ScrollDeltaY()
	{
		return scroll_delta_y_;
	}
#pragma endregion

#pragma region Joystick
	bool Input::IsJoystickPresent(int joystick)
	{
		return glfwJoystickPresent(joystick);
	}

	const float* Input::joystick_axes_[] = { 0 };
	int Input::joystick_axes_count_ = 0;

	float Input::GetJoystickAxes(int axes, int joystick)
	{
		if (!Input::IsJoystickPresent(joystick))
			return 0;

		return Input::joystick_axes_[joystick][axes];
	}

	int Input::joystick_button_count_ = 0;

	int Input::button_down_buffer_ = NULL;
	int Input::button_up_buffer_ = NULL;

	bool Input::IsJoystickButtonDown(int button, int joystick)
	{
		if (!Input::IsJoystickPresent(joystick))
			return false;

		return glfwGetJoystickButtons(joystick, &Input::joystick_button_count_)[button] == GLFW_PRESS;
	}

	bool Input::IsJoystickButtonUp(int button, int joystick)
	{
		if (!Input::IsJoystickPresent(joystick))
			return false;

		return glfwGetJoystickButtons(joystick, &Input::joystick_button_count_)[button] == GLFW_RELEASE;
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
		glfwGetCursorPos(solar::App::window_<GLFWwindow>, &Input::cursor_x_, &Input::cursor_y_);
		glfwSetInputMode(solar::App::window_<GLFWwindow>, GLFW_CURSOR, Input::cursor_mode_);

#pragma region Buffer Handling
		if (!Input::scroll_buffer_)
		{
			Input::scroll_delta_x_ = 0;
			Input::scroll_delta_y_ = 0;
		}
		else
		{
			Input::scroll_buffer_ = false;
		}

		if (!Input::cursor_enter_exit_buffer_)
		{
			Input::cursor_enter_ = false;
			Input::cursor_exit_ = false;
		}
		else
		{
			Input::cursor_enter_exit_buffer_ = false;
		}
#pragma endregion

		// Update all input axes
		for (int i = Input::Joysticks::kJoystick1; i <= Input::Joysticks::kJoystickLast; i++)
		{
			if (Input::IsJoystickPresent(i))
				joystick_axes_[i] = glfwGetJoystickAxes(i, &Input::joystick_axes_count_);
		}
	}
} // namespace solar
