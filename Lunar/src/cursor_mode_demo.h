#include <solar.h>
using namespace Solar;

/// <summary>
/// Demostrate all cursor modes.
/// </summary>
inline void CursorModeDemo()
{
	// Hide mouse cursor
	// Input::SetCursorMode(Input::CursorModes::ModeHidden);

	// Hide mouse cursor and lock its position
	// Input::SetCursorMode(Input::CursorModes::ModeLocked);

	// Show mouse cursor and unlock its position
	Input::SetCursorMode(Input::CursorModes::ModeNormal);
}