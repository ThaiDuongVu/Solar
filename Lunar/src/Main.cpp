#include <Solar.h>

// Initialize game elements
void Solar::App::Init()
{
	// Set window size to be 852 by 480
	Solar::App::SetWindowSize(852, 480);

	// Set window title to be "Lunar System"
	Solar::App::SetTitle("Lunar System");

	// Hide mouse cursor
	//Solar::Input::SetCursorMode(Solar::Input::CURSOR_MODES::HIDDEN);

	// Hide mouse cursor and lock its position
	//Solar::Input::SetCursorMode(Solar::Input::CURSOR_MODES::LOCKED);

	// Show mouse cursor and unlock its position
	Solar::Input::SetCursorMode(Solar::Input::CURSOR_MODES::NORMAL);
}

// Handle input and game events
void Solar::App::Update(double frameTime)
{
	// On key pressed
	if (Solar::Input::OnKeyDown(Solar::Input::KEYS::ESCAPE))
	{
		// Quit game
		Solar::App::Quit();
	}

	// On key released
	if (Solar::Input::OnKeyUp(Solar::Input::KEYS::ENTER))
	{
		// Log error
		Solar::Debug::LogError("Test Error");
		// Log warning
		Solar::Debug::LogWarning("Test warning");
	}

	// While key being pressed
	if (Solar::Input::IsKeyDown(Solar::Input::KEYS::SPACE))
	{
		// Log to console
		Solar::Debug::Log("Space key is down");
	}

	// While left mouse is down
	if (Solar::Input::IsMouseDown(Solar::Input::MOUSE_BUTTONS::MOUSE_LEFT))
	{
		Solar::Debug::Log("Left mouse button is down");
	}

	// On right mouse up
	if (Solar::Input::OnMouseUp(Solar::Input::MOUSE_BUTTONS::MOUSE_RIGHT))
	{
		Solar::Debug::Log("Right mouse button released");
	}

	if (Solar::Input::ScrollDeltaY() > 0)
	{
		Solar::Debug::Log("Mouse scrolling up");
	}
	else if (Solar::Input::ScrollDeltaY() < 0)
	{
		Solar::Debug::Log("Mouse scrolling down");
	}

	// Mouse position X and Y
	//Solar::Debug::Log(Solar::Input::CursorPosition().X);
	//Solar::Debug::Log(Solar::Input::CursorPosition().Y);
}

// Render game frames
void Solar::App::Render()
{
}

// Collect garbage on exit
void Solar::App::Exit()
{
}

int main()
{
	// Create a new app
	Solar::App *app = new Solar::App();

	// Run created app
	app->Run();
}