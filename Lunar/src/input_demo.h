#include <solar.h>
using namespace solar;

/// <summary>
/// Demonstrate input methods.
/// </summary>
/// <param name="app">Current app</param>
inline void InputDemo(App* app)
{
	// On key released
	if (Input::OnKeyDown(Input::Keys::kKeyEnter))
	{
		// Log error
		Debug::LogError("Test Error");
		// Log warning
		Debug::LogWarning("Test warning");
	}

	// While key being pressed
	if (Input::IsKeyDown(Input::Keys::kKeySpace))
		// Log a line to console
		Debug::Log("Space key is down");

	// While left mouse is down
	if (Input::IsMouseDown(Input::MouseButtons::kMouseLeft))
		Debug::Log("Left mouse button is down");

	// On right mouse up
	if (Input::OnMouseUp(Input::MouseButtons::kMouseRight))
		Debug::Log("Right mouse button released");

	// Scrolling speed x and y
	if (Input::ScrollDeltaY() > 0)
		Debug::Log("Mouse scrolling up");
	else if (Input::ScrollDeltaY() < 0)
		Debug::Log("Mouse scrolling down");

	// On mouse enter and exit window
	if (Input::OnCursorEnter())
		Debug::Log("Mouse enter");
	if (Input::OnCursorExit())
		Debug::Log("Mouse exit");

	// While A button is being pressed
	if (Input::IsGamepadButtonDown(Input::GamepadButtons::kButtonA))
		Debug::Log("A button is down");

	// If a joystick is connected
	if (Input::IsGamepadPresent(Input::Gamepads::kGamepad1))
	{
		Debug::Log("Joystick 1 present");

		// Trigger input
		if (Input::GetGamepadAxes(Input::GamepadAxes::kAxesRightTrigger) > -1)
			Debug::Log("Right trigger is down");
	}

	Vector2 direction = Vector2(Input::IsPresetDown(Input::Presets::kPresetHorizontal), Input::IsPresetDown(Input::Presets::kPresetVertical));
	if (direction != Vector2::Zero())
		Debug::Log(direction.ToString());

	// Mouse position X and Y
	// Debug::Log(Input::CursorPosition().x);
	// Debug::Log(Input::CursorPosition().y);
}