#include <Solar.h>
using namespace Solar;

Color32 backgroundColor = Color32(34, 40, 49, 255);

// Function to demonstrate all input methods
void InputDemo(App* app)
{
	// On key pressed
	if (Input::OnKeyDown(Input::KEYS::KEY_ESCAPE))
	{
		// Quit game
		app->Quit();
	}

	// On key released
	if (Input::OnKeyDown(Input::KEYS::KEY_ENTER))
	{
		// Log error
		Debug::LogError("Test Error");
		// Log warning
		Debug::LogWarning("Test warning");
	}

	// While key being pressed
	if (Input::IsKeyDown(Input::KEYS::KEY_SPACE))
	{
		// Log a line to console
		Debug::LogLine("Space key is down");
	}

	// While left mouse is down
	if (Input::IsMouseDown(Input::MOUSE_BUTTONS::MOUSE_LEFT))
	{
		Debug::LogLine("Left mouse button is down");
	}

	// On right mouse up
	if (Input::OnMouseUp(Input::MOUSE_BUTTONS::MOUSE_RIGHT))
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

	// On mouse enter and exit window
	if (Input::OnCursorEnter())
	{
		Debug::LogLine("Mouse enter");
	}
	if (Input::OnCursorExit())
	{
		Debug::LogLine("Mouse exit");
	}

	// While A button is being pressed
	if (Input::IsJoystickButtonDown(Input::JOYSTICK_BUTTONS::BUTTON_A))
	{
		Debug::LogLine("A button is down");
	}

	// Trigger input
	// if (Input::GetJoystickAxes(Input::JOYSTICK_AXES::AXES_RIGHT_TRIGGER) > -1)
	// {
	// 	Debug::LogLine("Right trigger is down");
	// }

	// If a joystick is connected
	// if (Input::IsJoystickPresent(Input::JOYSTICKS::JOYSTICK_1))
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
	// Input::SetCursorMode(Input::CURSOR_MODES::MODE_HIDDEN);

	// Hide mouse cursor and lock its position
	// Input::SetCursorMode(Input::CURSOR_MODES::MODE_LOCKED);

	// Show mouse cursor and unlock its position
	Input::SetCursorMode(Input::CURSOR_MODES::MODE_NORMAL);
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
void App::Update(double FrameTime)
{
	// Frames per 1 second
	// Debug::LogLine(Time::FrameRate(1));

	// InputDemo(this);
}

// Render game frames
void App::Render()
{
	// Clear background color
	App::ClearBackground(backgroundColor.Normalize());
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