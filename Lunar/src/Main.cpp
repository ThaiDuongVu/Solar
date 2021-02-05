#include <solar.h>
using namespace Solar;

Color32 background_color = Color32(34, 40, 49, 255);

void App::Init()
{
	// Set window size to 800 by 600
	App::SetWindowSize(800, 600);

	// Set window title to "Lunar System"
	App::SetWindowTitle("Lunar System");
}

void App::Update(double frame_time)
{
}

void App::Render()
{
	// Clear background color
	App::ClearBackground(background_color.Normalize());
}

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