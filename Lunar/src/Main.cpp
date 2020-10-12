#include <Solar.h>

// Initialize game elements
void Solar::App::Init()
{
	Solar::App::SetWindowSize(640, 480);
	Solar::App::SetTitle("Lunar System");
}

// Handle input and game events
void Solar::App::Update(double frameTime)
{

}

// Render game frames
void Solar::App::Render()
{
}

// On game exit
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