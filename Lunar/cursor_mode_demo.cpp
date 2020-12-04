#include <solar.h>
using namespace solar;

// Function to demostrate all cursor modes 
void CursorModeDemo()
{
	// Hide mouse cursor
	// Input::SetCursorMode(Input::CursorModes::kModeHidden);

	// Hide mouse cursor and lock its position
	// Input::SetCursorMode(Input::CursorModes::kModeLocked);

	// Show mouse cursor and unlock its position
	Input::SetCursorMode(Input::CursorModes::kModeNormal);
}