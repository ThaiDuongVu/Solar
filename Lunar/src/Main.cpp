#include <solar.h>
#include "mathf_demo.h"
using namespace Solar;

Color32 background_color = Color32(34, 40, 49, 255);

Square square = Square();

void App::Init()
{
	// Set window size to 800 by 600
	App::SetSize(800, 600);
	// Set window title to "Lunar System"
	App::SetTitle("Lunar System");

	// Set viewport background color
	viewport.background_color = background_color.Normalize();

	//MathfDemo();
}

void App::Update()
{
	if (Input::OnKeyDown(Input::Keys::KeyEscape))
		Quit();
	if (Input::OnKeyDown(Input::Keys::KeyEnter))
		App::SetPosition(Vector2::Zero());

	viewport.Move(Vector2((double)Input::IsKeyDown(Input::Keys::KeyRight) - (double)Input::IsKeyDown(Input::Keys::KeyLeft), 0.0f) * Time::FrameTime());
	viewport.Move(Vector2(0.0f, (double)Input::IsKeyDown(Input::Keys::KeyUp) - (double)Input::IsKeyDown(Input::Keys::KeyDown)) * Time::FrameTime());
	viewport.Rotate(1.0f);
}

void App::Render()
{
	square.Draw(*this);
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