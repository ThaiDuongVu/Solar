#include <Solar.h>

// Initialise game elements
void Solar::App::Init()
{
	Solar::App::SetWindowSize(640, 480);
	Solar::App::SetTitle("Lunar System");
}

// Handle input and events
void Solar::App::Update(double frameTime)
{

}

// Render game behaviours
void Solar::App::Render()
{

}

// On shutdown
void Solar::App::Shutdown()
{

}

int main()
{
	// Create a new app
	Solar::App* app = new Solar::App();
	// Run created app
	app->Run();
}