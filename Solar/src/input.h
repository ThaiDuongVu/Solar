#pragma once

#ifndef SOLAR_INPUT_H_
#define SOLAR_INPUT_H_

#include "core.h"
#include "types/vector2.h"
#include "mathf.h"

namespace Solar
{
	class SOLAR_API Input
	{
	public:
		/// <summary>
		/// Update input states & buffers.
		/// </summary>
		static void Update();

#pragma region Keyboard
		enum Keys
		{
			KeyUnknown = -1,
			KeySpace = 32,
			KeyApostrophe = 39, // '
			KeyComma = 44,
			KeyMinus = 45,
			KeyPeriod = 46,
			KeySlash = 47, // /
			Key0 = 48,
			Key1 = 49,
			Key2 = 50,
			Key3 = 51,
			Key4 = 52,
			Key5 = 53,
			Key6 = 54,
			Key7 = 55,
			Key8 = 56,
			Key9 = 57,
			KeySemicolon = 59, // ;
			KeyEqual = 61,		// =
			KeyA = 65,
			KeyB = 66,
			KeyC = 67,
			KeyD = 68,
			KeyE = 69,
			KeyF = 70,
			KeyG = 71,
			KeyH = 72,
			KeyI = 73,
			KeyJ = 74,
			KeyK = 75,
			KeyL = 76,
			KeyM = 77,
			KeyN = 78,
			KeyO = 79,
			KeyP = 80,
			KeyQ = 81,
			KeyR = 82,
			KeyS = 83,
			KeyT = 84,
			KeyU = 85,
			KeyV = 86,
			KeyW = 87,
			KeyX = 88,
			KeyY = 89,
			KeyZ = 90,
			KeyLeftBracket = 91,  // [
			KeyBackslash = 92,	   /* \ */
			KeyRightBracket = 93, // ]
			KeyGraveAccent = 96,  // `
			KeyWorld1 = 161,	   // non-US #1
			KeyWorld2 = 162,	   // non-US #2
			KeyEscape = 256,
			KeyEnter = 257,
			KeyTab = 258,
			KeyBackspace = 259,
			KeyInsert = 260,
			KeyDel = 261, // Delete
			KeyRight = 262,
			KeyLeft = 263,
			KeyDown = 264,
			KeyUp = 265,
			KeyPageUp = 266,
			KeyPageDown = 267,
			KeyHome = 268,
			KeyEnd = 269,
			KeyCapsLock = 280,
			KeyScrollLock = 281,
			KeyNumLock = 282,
			KeyPrtScr = 283, // Print screen
			KeyPause = 284,
			KeyF1 = 290,
			KeyF2 = 291,
			KeyF3 = 292,
			KeyF4 = 293,
			KeyF5 = 294,
			KeyF6 = 295,
			KeyF7 = 296,
			KeyF8 = 297,
			KeyF9 = 298,
			KeyF10 = 299,
			KeyF11 = 300,
			KeyF12 = 301,
			KeyF13 = 302,
			KeyF14 = 303,
			KeyF15 = 304,
			KeyF16 = 305,
			KeyF17 = 306,
			KeyF18 = 307,
			KeyF19 = 308,
			KeyF20 = 309,
			KeyF21 = 310,
			KeyF22 = 311,
			KeyF23 = 312,
			KeyF24 = 313,
			KeyF25 = 314,
			KeyKeypad0 = 320,
			KeyKeypad1 = 321,
			KeyKeypad2 = 322,
			KeyKeypad3 = 323,
			KeyKeypad4 = 324,
			KeyKeypad5 = 325,
			KeyKeypad6 = 326,
			KeyKeypad7 = 327,
			KeyKeypad8 = 328,
			KeyKeypad9 = 329,
			KeyKeypadDecimal = 330,
			KeyKeypadDivide = 331,
			KeyKeypadMultiply = 332,
			KeyKeypadSubstract = 333,
			KeyKeypadAdd = 334,
			KeyKeypadEnter = 335,
			KeyKeypadEqual = 336,
			KeyLeftShift = 340,
			KeyLeftCtrl = 341,
			KeyLeftAlt = 342,
			KeyLeftSuper = 343,
			KeyRightShift = 344,
			KeyRightCtrl = 345,
			KeyRightAlt = 346,
			KeyMenu = 348,
			KeyLast = 348
		};

		/// <summary>
		/// Returns true if a key is being held down.
		/// </summary>
		/// <param name="key">Key to check</param>
		/// <returns>Whether key is being held down</returns>
		static bool IsKeyDown(int key);
		/// <summary>
		/// Returns true if a key is NOT being held down.
		/// </summary>
		/// <param name="key">Key to check</param>
		/// <returns>Whether key is being NOT held down</returns>
		static bool IsKeyUp(int key);

		/// <summary>
		/// Returns true FOR THE FIRST FRAME a key is held down.
		/// </summary>
		/// <param name="key">Key to check</param>
		/// <returns>Whether key is held down during 1 frame</returns>
		static bool OnKeyDown(int key);
		/// <summary>
		/// Returns true FOR THE FIRST FRAME a key is NOT held down.
		/// </summary>
		/// <param name="key">Key to check</param>
		/// <returns>Whether key is NOT held down during 1 frame</returns>
		static bool OnKeyUp(int key);

		/// <summary>
		/// Buffer memory for key down.
		/// </summary>
		static int key_down_buffer;
		/// <summary>
		/// Buffer memory for key up.
		/// </summary>
		static int key_up_buffer;
#pragma endregion

#pragma region Cursor
		enum CursorModes
		{
			ModeLocked = 212995,
			ModeHidden = 212994,
			ModeNormal = 212993
		};

		/// <summary>
		/// x and y coordinates of cursor.
		/// </summary>
		/// <returns>Cursor position vector</returns>
		static Vector2 CursorPosition();
		/// <summary>
		/// Set cursor mode to locked, hidden or normal.
		/// </summary>
		/// <param name="mode">Mode to set</param>
		static void SetCursorMode(int mode);

		static bool cursor_enter;
		static bool cursor_exit;

		/// <summary>
		/// On cursor enter window.
		/// </summary>
		/// <returns>Whether cursor is entering window</returns>
		static bool OnCursorEnter();
		/// <summary>
		/// On cursor exit window.
		/// </summary>
		/// <returns>Whether cursor is exiting window</returns>
		static bool OnCursorExit();

		/// <summary>
		/// Buffer memory for cursor enter & exit.
		/// </summary>
		static bool cursor_enter_exit_buffer;
#pragma endregion

#pragma region Mouse
		enum MouseButtons
		{
			MouseLeft = 0,
			MouseRight = 1,
			MouseMiddle = 2
		};

		/// <summary>
		/// Returns true if a mouse button is being held down.
		/// </summary>
		/// <param name="button">Mouse button to check</param>
		/// <returns>Whether mouse button is being held down</returns>
		static bool IsMouseDown(int button);
		/// <summary>
		/// Returns true if a mouse button is NOT being held down.
		/// </summary>
		/// <param name="button">Mouse button to check</param>
		/// <returns>Whether mouse button is NOT being held down</returns>
		static bool IsMouseUp(int button);

		/// <summary>
		/// Returns true FOR THE FIRST FRAME a mouse button is held down.
		/// </summary>
		/// <param name="button">Mouse button to check</param>
		/// <returns>Whether mouse is down during 1 frame</returns>
		static bool OnMouseDown(int button);
		/// <summary>
		/// Returns true FOR THE FIRST FRAME a mouse button is released.
		/// </summary>
		/// <param name="button">Mouse button to check</param>
		/// <returns>Whether mouse is released during 1 frame</returns>
		static bool OnMouseUp(int button);

		/// <summary>
		/// Buffer memory for mouse button down.
		/// </summary>
		static int mouse_down_buffer;
		/// <summary>
		/// Buffer memory for mouse button up.
		/// </summary>
		static int mouse_up_buffer;

		static double scroll_delta_x;
		static double scroll_delta_y;

		/// <summary>
		/// Returns mouse scrolling speed x.
		/// </summary>
		/// <returns>Mouse scrolling speed x</returns>
		static double ScrollDeltaX();
		/// <summary>
		/// Returns mouse scrolling speed y.
		/// </summary>
		/// <returns>Mouse scrolling speed y</returns>
		static double ScrollDeltaY();

		/// <summary>
		/// Buffer memory for scroll delta.
		/// </summary>
		static bool scroll_buffer;
#pragma endregion

#pragma region Gamepad
		enum Gamepads
		{
			Gamepad1 = 0,
			Gamepad2 = 1,
			Gamepad3 = 2,
			Gamepad4 = 3,
			Gamepad5 = 4,
			Gamepad6 = 5,
			Gamepad7 = 6,
			Gamepad8 = 7,
			Gamepad9 = 8,
			Gamepad10 = 9,
			Gamepad11 = 10,
			Gamepad12 = 11,
			Gamepad13 = 12,
			Gamepad14 = 13,
			Gamepad15 = 14,
			Gamepad16 = 15,
			GamepadLast = 15,
		};
		enum GamepadAxes
		{
			AxesLeftStickX = 0,
			AxesLeftStickY = 1,
			AxesRightStickX = 2,
			AxesRightStickY = 3,
			AxesLeftTrigger = 4,
			AxesRightTrigger = 5,
		};
		enum GamepadButtons
		{
			ButtonA = 0,
			ButtonB = 1,
			ButtonX = 2,
			ButtonY = 3,
			ButtonLeftBumper = 4,
			ButtonRightBumper = 5,
			ButtonBack = 6,
			ButtonStart = 7,
			ButtonLeftStick = 8,
			ButtonRightStick = 9,
			ButtonDPpadUp = 10,
			ButtonDPadRight = 11,
			ButtonDPadDown = 12,
			ButtonDPadLeft = 13,
		};

		/// <summary>
		/// Returns true if a gamepad is connected.
		/// </summary>
		/// <param name="gamepad">Gamepad to check</param>
		/// <returns>Whether gamepad is connected</returns>
		static bool IsGamepadPresent(int gamepad);
		/// <summary>
		/// Get values of different gamepad axes.
		/// </summary>
		/// <param name="axes">Axes to get</param>
		/// <param name="gamepad">Gamepad to get</param>
		/// <returns>Gamepad axes value</returns>
		static float GetGamepadAxes(int axes, int gamepad = Gamepads::Gamepad1);

		/// <summary>
		/// Returns true if a gamepad button is being held down.
		/// </summary>
		/// <param name="button">Gamepad button to check</param>
		/// <param name="gamepad">Gamepad to check</param>
		/// <returns>Whether a gamepad button is being held down</returns>
		static bool IsGamepadButtonDown(int button, int gamepad = Gamepads::Gamepad1);
		/// <summary>
		/// Returns true if a gamepad button is NOT being held down.
		/// </summary>
		/// <param name="button">Gamepad button to check</param>
		/// <param name="gamepad">Gamepad to check</param>
		/// <returns>Whether a gamepad button is NOT being held down</returns>
		static bool IsGamepadButtonUp(int button, int gamepad = Gamepads::Gamepad1);

		/// <summary>
		/// Returns true FOR THE FIRST FRAME a gamepad button is held down.
		/// </summary>
		/// <param name="button">Gamepad button to check</param>
		/// <param name="gamepad">Gamepad to check</param>
		/// <returns>Whether gamepad button is held down during 1 frame</returns>
		static bool OnGamepadButtonDown(int button, int gamepad = Gamepads::Gamepad1);
		/// <summary>
		/// Returns true FOR THE FIRST FRAME a gamepad button is released.
		/// </summary>
		/// <param name="button">Gamepad button to check</param>
		/// <param name="gamepad">Gamepad to check</param>
		/// <returns>Whether gamepad button is released during 1 frame</returns>
		static bool OnGamepadButtonUp(int button, int gamepad = Gamepads::Gamepad1);

		/// <summary>
		/// Buffer memory for gamepad button down.
		/// </summary>
		static int button_down_buffer;
		/// <summary>
		/// Buffer memory for gamepad button up.
		/// </summary>
		static int button_up_buffer;
#pragma endregion

#pragma region Presets
		enum class Presets
		{
			PresetHorizontal,
			PresetVertical,
			PresetJump,
			PresetFire1,
			PresetFire2,
			PresetCrouch,
			PresetEscape
		};

		/// <summary>
		/// Returns true if a preset input is being held down.
		/// </summary>
		/// <param name="preset">Preset to check</param>
		/// <returns>Whether preset input is being held down</returns>
		static double IsPresetDown(Presets preset);
		/// <summary>
		/// Returns true if a preset input is NOT being held down.
		/// </summary>
		/// <param name="preset">Preset to check</param>
		/// <returns>Whether preset input is NOT being held down</returns>
		static double IsPresetUp(Presets preset);

		/// <summary>
		/// Returns true FOR THE FIRST FRAME a preset input is held down.
		/// </summary>
		/// <param name="preset">Preset to check</param>
		/// <returns>Whether input is held down during 1 frame</returns>
		static double OnPresetDown(Presets preset);
		/// <summary>
		/// Returns true FOR THE FIRST FRAME a preset input is released.
		/// </summary>
		/// <param name="preset">Preset to check</param>
		/// <returns>Whether input is released during 1 frame</returns>
		static double OnPresetUp(Presets preset);
#pragma endregion

	private:
		/// <summary>
		/// Current cursor coordinates x.
		/// </summary>
		static double cursor_x;
		/// <summary>
		/// Current cursor coordinates y.
		/// </summary>
		static double cursor_y;

		/// <summary>
		/// 2D array representing gamepad axes.
		/// </summary>
		static const float* gamepad_axes[];

		static int gamepad_axes_count;
		static int gamepad_button_count;

		/// <summary>
		/// Current cursor mode.
		/// </summary>
		static int cursor_mode;
	};
} // namespace Solar

#endif // !SOLAR_INPUT_H_