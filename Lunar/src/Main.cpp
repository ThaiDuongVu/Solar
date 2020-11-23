#include <solar.h>
using namespace solar;

Color32 background_color = Color32(34, 40, 49, 255);

Text test = Text("hello world", Color(34, 40, 49, 255));

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
	// if (Input::GetJoystickAxes(Input::JoystickAxes::kAxesRightTrigger) > -1)
	// {
	// 	Debug::Log("Right trigger is down");
	// }

	// If a joystick is connected
	if (Input::IsJoystickPresent(Input::Joysticks::kJoystick1))
	{
		Debug::Log("Joystick 1 present");
	}

	// Mouse position X and Y
	Debug::Log(Input::CursorPosition().x_);
	Debug::Log(Input::CursorPosition().y_);
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

// Function to demonstrate math methods provided
void MathfDemo()
{

}

// Function to demonstrate vector2 type
void Vector2Demo()
{

}

// On game initialization
void App::Init()
{
	// Set window size to be 800 by 600
	App::SetWindowSize(800, 600);

	// Set window title to be "Lunar System"
	App::SetTitle("Lunar System");
}

// On game update
void App::Update(double frame_time)
{
	// Frames per 1 second
	// Debug::Log(Time::FrameRate(1));

	if (Input::OnKeyDown(Input::Keys::kKeyEscape))
	{
		App::Quit();
	}
}

// On game render
void App::Render()
{
	// Clear background color_
	App::ClearBackground(background_color.Normalize());
}

// On game exit
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