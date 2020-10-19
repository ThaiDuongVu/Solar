#include <Solar.h>

// Initialize game elements
void Solar::App::Init()
{
	// Set window size to be 852 by 480
	Solar::App::SetWindowSize(852, 480);

	// Set window title to be "Lunar System"
	Solar::App::SetTitle("Lunar System");
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

	// Mouse position X and Y
	//Solar::Debug::Log(Solar::Input::CursorPosition().X);
	//Solar::Debug::Log(Solar::Input::CursorPosition().Y);

	// Hide mouse cursor
	//Solar::Input::SetCursorMode(Solar::Input::CURSOR_MODE::Hidden);

	// Hide mouse cursor and lock its position
	//Solar::Input::SetCursorMode(Solar::Input::CURSOR_MODE::Locked);

	// Show mouse cursor and unlock its position
	//Solar::Input::SetCursorMode(Solar::Input::CURSOR_MODE::Normal);
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