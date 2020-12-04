#include <solar.h>
using namespace solar;

// Function to demonstrate input methods
void InputDemo(App* app)
{
	// On key pressed
	if (Input::OnKeyDown(Input::Keys::kKeyEscape))
	{
		app->Quit();
	}

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
	{
		// Log a line to console
		Debug::Log("Space key is down");
	}

	// While left mouse is down
	if (Input::IsMouseDown(Input::MouseButtons::kMouseLeft))
	{
		Debug::Log("Left mouse button is down");
	}

	// On right mouse up
	if (Input::OnMouseUp(Input::MouseButtons::kMouseRight))
	{
		Debug::Log("Right mouse button released");
	}

	// Scrolling speed x and y
	if (Input::ScrollDeltaY() > 0)
	{
		Debug::Log("Mouse scrolling up");
	}
	else if (Input::ScrollDeltaY() < 0)
	{
		Debug::Log("Mouse scrolling down");
	}

	// On mouse enter and exit window_
	if (Input::OnCursorEnter())
	{
		Debug::Log("Mouse enter");
	}
	if (Input::OnCursorExit())
	{
		Debug::Log("Mouse exit");
	}

	// While A button is being pressed
	if (Input::IsJoystickButtonDown(Input::JoystickButtons::kButtonA))
	{
		Debug::Log("A button is down");
	}

	// Trigger input
	if (Input::GetJoystickAxes(Input::JoystickAxes::kAxesRightTrigger) > -1)
	{
		Debug::Log("Right trigger is down");
	}

	// If a joystick is connected
	if (Input::IsJoystickPresent(Input::Joysticks::kJoystick1))
	{
		Debug::Log("Joystick 1 present");
	}

	// Mouse position X and Y
	Debug::Log(Input::CursorPosition().x_);
	Debug::Log(Input::CursorPosition().y_);
}