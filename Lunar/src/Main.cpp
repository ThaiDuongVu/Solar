#include <solar.h>
using namespace solar;

Color32 background_color = Color32(34, 40, 49, 255);

Line line = Line();
Triangle triangle = Triangle();

void App::Init()
{
	// Set window size to 800 by 600
	App::SetWindowSize(800, 600);

	// Set window title to "Lunar System"
	App::SetWindowTitle("Lunar System");

	triangle.is_bounded = true;
}

void App::Update(double frame_time)
{
	// Frames per 1 second
	// Debug::Log(Time::FrameRate(1));

	if (Input::OnPresetDown(Input::Presets::kPresetEscape))
		App::Quit();

	if (Input::OnKeyDown(Input::Keys::kKeySpace))
		triangle.color = Color::Red();

	triangle.Move(Vector2(Input::IsPresetDown(Input::Presets::kPresetHorizontal), Input::IsPresetDown(Input::Presets::kPresetVertical)) * 5.0f);
}

void App::Render()
{
	// Clear background color
	App::ClearBackground(background_color.Normalize());

	line.Draw(*this);
	triangle.Draw(*this, GameObject::DrawMode::kLine);
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