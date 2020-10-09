#include <Solar.h>

void Solar::App::Init()
{
	
}

void Solar::App::Update(double frameTime)
{
	std::cout << frameTime << std::endl;
}

void Solar::App::Render()
{
	
}

void Solar::App::Shutdown()
{
	
}

int main()
{
	Solar::App* app = new Solar::App();
	app->Run();
}