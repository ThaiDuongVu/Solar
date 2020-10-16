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
	if (Solar::Input::IsKeyDown(Solar::Input::KEYS::ENTER))
	{
		Solar::Debug::Log("bruh");
	}
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