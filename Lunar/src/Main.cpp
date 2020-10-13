#include <Solar.h>

// Initialize game elements
void Solar::App::Init()
{
	// Set window size to be 640 wide and 480 high
	Solar::App::SetWindowSize(640, 480);
	// Set window title to be "Lunar System"
	Solar::App::SetTitle("Lunar System");
}

// Handle input and game events
void Solar::App::Update(double frameTime)
{
	if (Solar::Input::IsKeyDown(Solar::KEYS::ESCAPE))
	{
		Solar::App::Quit();
	}
}

// Render game frames
void Solar::App::Render()
{
}

// Collect garbage on exit
void Solar::App::Shutdown()
{
}

int main()
{
	// Create a new app
	Solar::App *app = new Solar::App();
	// Run created app
	app->Run();
}