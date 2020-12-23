#include <solar.h>
using namespace solar;

Color32 background_color = Color32(34, 40, 49, 255);

Triangle triangle = Triangle();
Line line = Line();

// On game initialization
void App::Init()
{
	// Set window size to 800 by 600
	App::SetWindowSize(800, 600);

	// Set window title to "Lunar System"
	App::SetTitle("Lunar System");

	triangle.SetBounded(true);
	line.SetLength(10.0f);
}

// On game update
void App::Update(double frame_time)
{
	// Frames per 1 second
	// Debug::Log(Time::FrameRate(1));

	if (Input::IsPresetDown(Input::Presets::kPresetEscape))
		App::Quit();

	if (Input::IsPresetDown(Input::Presets::kPresetFire1))
		triangle.Rotate(1.0f);

	if (Input::IsPresetDown(Input::Presets::kPresetFire2))
		triangle.Rotate(-1.0f);

	line.Move(Vector2(Input::IsPresetDown(Input::Presets::kPresetHorizontal), Input::IsPresetDown(Input::Presets::kPresetVertical)) * 5.0f);
}

// On game render
void App::Render()
{
	// Clear background color
	App::ClearBackground(background_color.Normalize());

	triangle.Draw(*this, GameObject::DrawMode::kLine);
	line.Draw(*this);
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