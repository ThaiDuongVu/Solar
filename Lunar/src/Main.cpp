#include <solar.h>
using namespace solar;

Color32 background_color = Color32(34, 40, 49, 255);

// Function to demonstrate all input methods
void InputDemo(App* app)
{
	// On key pressed
	if (Input::OnKeyDown(Input::Keys::kKeyEscape))
	{
		// Quit game
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
		Debug::LogLine("Space key is down");
	}

	// While left mouse is down
	if (Input::IsMouseDown(Input::MouseButtons::kMouseLeft))
	{
		Debug::LogLine("Left mouse button is down");
	}

	// On right mouse up
	if (Input::OnMouseUp(Input::MouseButtons::kMouseRight))
	{
		Debug::LogLine("Right mouse button released");
	}

	// Scrolling speed x and y
	if (Input::ScrollDeltaY() > 0)
	{
		Debug::LogLine("Mouse scrolling up");
	}
	else if (Input::ScrollDeltaY() < 0)
	{
		Debug::LogLine("Mouse scrolling down");
	}

	// On mouse enter and exit window_
	if (Input::OnCursorEnter())
	{
		Debug::LogLine("Mouse enter");
	}
	if (Input::OnCursorExit())
	{
		Debug::LogLine("Mouse exit");
	}

	// While A button is being pressed
	if (Input::IsJoystickButtonDown(Input::JoystickButtons::kButtonA))
	{
		Debug::LogLine("A button is down");
	}

	// Trigger input
	// if (Input::GetJoystickAxes(Input::JoystickAxes::kAxesRightTrigger) > -1)
	// {
	// 	Debug::LogLine("Right trigger is down");
	// }

	// If a joystick is connected
	// if (Input::IsJoystickPresent(Input::Joysticks::kJoystick1))
	// {
	// 	Debug::LogLine("Joystick 1 present");
	// }

	// Mouse position X and Y
	// Debug::LogLine(Input::CursorPosition().x);
	// Debug::LogLine(Input::CursorPosition().y);
}

// Function to demostrate all cursor modes
void CursorModeDemo()
{
	// Hide mouse cursor
	// Input::SetCursorMode(Input::CursorModes::kModeHidden);

	// Hide mouse cursor and lock its position
	// Input::SetCursorMode(Input::CursorModes::kModeLocked);

	// Show mouse cursor and unlock its position
	Input::SetCursorMode(Input::CursorModes::kModeNormal);
}

// Initialize game elements
void App::Init()
{
	// Set window size to be 852 by 480
	App::SetWindowSize(852, 480);

	// Set window title to be "Lunar System"
	App::SetTitle("Lunar System");
}

// Handle game events
void App::Update(double frame_time)
{
	// Frames per 1 second
	// Debug::LogLine(Time::FrameRate(1));

	// InputDemo(this);

	if (Input::OnKeyDown(Input::Keys::kKeyEscape))
	{
		App::Quit();
	}
}

// Render game frames
void App::Render()
{
	// Clear background color
	App::ClearBackground(background_color.Normalize());
}

// Collect garbage on exit
void App::Exit()
{
}

int main()
{
	// Create a new app
	App* app = new App();

	// Run created app
	app->Run();
}