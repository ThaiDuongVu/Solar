#pragma once

#ifndef SOLAR_INPUT_H_
#define SOLAR_INPUT_H_

#include "core.h"
#include "types/vector2.h"
#include "mathf.h"

namespace solar
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
			kKeyUnknown = -1,
			kKeySpace = 32,
			kKeyApostrophe = 39, // '
			kKeyComma = 44,
			kKeyMinus = 45,
			kKeyPeriod = 46,
			kKeySlash = 47, // /
			kKey0 = 48,
			kKey1 = 49,
			kKey2 = 50,
			kKey3 = 51,
			kKey4 = 52,
			kKey5 = 53,
			kKey6 = 54,
			kKey7 = 55,
			kKey8 = 56,
			kKey9 = 57,
			kKeySemicolon = 59, // ;
			kKeyEqual = 61,		// =
			kKeyA = 65,
			kKeyB = 66,
			kKeyC = 67,
			kKeyD = 68,
			kKeyE = 69,
			kKeyF = 70,
			kKeyG = 71,
			kKeyH = 72,
			kKeyI = 73,
			kKeyJ = 74,
			kKeyK = 75,
			kKeyL = 76,
			kKeyM = 77,
			kKeyN = 78,
			kKeyO = 79,
			kKeyP = 80,
			kKeyQ = 81,
			kKeyR = 82,
			kKeyS = 83,
			kKeyT = 84,
			kKeyU = 85,
			kKeyV = 86,
			kKeyW = 87,
			kKeyX = 88,
			kKeyY = 89,
			kKeyZ = 90,
			kKeyLeftBracket = 91,  // [
			kKeyBackslash = 92,	   /* \ */
			kKeyRightBracket = 93, // ]
			kKeyGraveAccent = 96,  // `
			kKeyWorld1 = 161,	   // non-US #1
			kKeyWorld2 = 162,	   // non-US #2
			kKeyEscape = 256,
			kKeyEnter = 257,
			kKeyTab = 258,
			kKeyBackspace = 259,
			kKeyInsert = 260,
			kKeyDel = 261, // Delete
			kKeyRight = 262,
			kKeyLeft = 263,
			kKeyDown = 264,
			kKeyUp = 265,
			kKeyPageUp = 266,
			kKeyPageDown = 267,
			kKeyHome = 268,
			kKeyEnd = 269,
			kKeyCapsLock = 280,
			kKeyScrollLock = 281,
			kKeyNumLock = 282,
			kKeyPrtScr = 283, // Print screen
			kKeyPause = 284,
			kKeyF1 = 290,
			kKeyF2 = 291,
			kKeyF3 = 292,
			kKeyF4 = 293,
			kKeyF5 = 294,
			kKeyF6 = 295,
			kKeyF7 = 296,
			kKeyF8 = 297,
			kKeyF9 = 298,
			kKeyF10 = 299,
			kKeyF11 = 300,
			kKeyF12 = 301,
			kKeyF13 = 302,
			kKeyF14 = 303,
			kKeyF15 = 304,
			kKeyF16 = 305,
			kKeyF17 = 306,
			kKeyF18 = 307,
			kKeyF19 = 308,
			kKeyF20 = 309,
			kKeyF21 = 310,
			kKeyF22 = 311,
			kKeyF23 = 312,
			kKeyF24 = 313,
			kKeyF25 = 314,
			kKeyKeypad0 = 320,
			kKeyKeypad1 = 321,
			kKeyKeypad2 = 322,
			kKeyKeypad3 = 323,
			kKeyKeypad4 = 324,
			kKeyKeypad5 = 325,
			kKeyKeypad6 = 326,
			kKeyKeypad7 = 327,
			kKeyKeypad8 = 328,
			kKeyKeypad9 = 329,
			kKeyKeypadDecimal = 330,
			kKeyKeypadDivide = 331,
			kKeyKeypadMultiply = 332,
			kKeyKeypadSubstract = 333,
			kKeyKeypadAdd = 334,
			kKeyKeypadEnter = 335,
			kKeyKeypadEqual = 336,
			kKeyLeftShift = 340,
			kKeyLeftCtrl = 341,
			kKeyLeftAlt = 342,
			kKeyLeftSuper = 343,
			kKeyRightShift = 344,
			kKeyRightCtrl = 345,
			kKeyRightAlt = 346,
			kKeyMenu = 348,
			kKeyLast = 348
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
			kModeLocked = 212995,
			kModeHidden = 212994,
			kModeNormal = 212993
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
			kMouseLeft = 0,
			kMouseRight = 1,
			kMouseMiddle = 2
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
			kGamepad1 = 0,
			kGamepad2 = 1,
			kGamepad3 = 2,
			kGamepad4 = 3,
			kGamepad5 = 4,
			kGamepad6 = 5,
			kGamepad7 = 6,
			kGamepad8 = 7,
			kGamepad9 = 8,
			kGamepad10 = 9,
			kGamepad11 = 10,
			kGamepad12 = 11,
			kGamepad13 = 12,
			kGamepad14 = 13,
			kGamepad15 = 14,
			kGamepad16 = 15,
			kGamepadLast = 15,
		};
		enum GamepadAxes
		{
			kAxesLeftStickX = 0,
			kAxesLeftStickY = 1,
			kAxesRightStickX = 2,
			kAxesRightStickY = 3,
			kAxesLeftTrigger = 4,
			kAxesRightTrigger = 5,
		};
		enum GamepadButtons
		{
			kButtonA = 0,
			kButtonB = 1,
			kButtonX = 2,
			kButtonY = 3,
			kButtonLeftBumper = 4,
			kButtonRightBumper = 5,
			kButtonBack = 6,
			kButtonStart = 7,
			kButtonLeftStick = 8,
			kButtonRightStick = 9,
			kButtonDPpadUp = 10,
			kButtonDPadRight = 11,
			kButtonDPadDown = 12,
			kButtonDPadLeft = 13,
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
		static float GetGamepadAxes(int axes, int gamepad = Gamepads::kGamepad1);

		/// <summary>
		/// Returns true if a gamepad button is being held down.
		/// </summary>
		/// <param name="button">Gamepad button to check</param>
		/// <param name="gamepad">Gamepad to check</param>
		/// <returns>Whether a gamepad button is being held down</returns>
		static bool IsGamepadButtonDown(int button, int gamepad = Gamepads::kGamepad1);
		/// <summary>
		/// Returns true if a gamepad button is NOT being held down.
		/// </summary>
		/// <param name="button">Gamepad button to check</param>
		/// <param name="gamepad">Gamepad to check</param>
		/// <returns>Whether a gamepad button is NOT being held down</returns>
		static bool IsGamepadButtonUp(int button, int gamepad = Gamepads::kGamepad1);

		/// <summary>
		/// Returns true FOR THE FIRST FRAME a gamepad button is held down.
		/// </summary>
		/// <param name="button">Gamepad button to check</param>
		/// <param name="gamepad">Gamepad to check</param>
		/// <returns>Whether gamepad button is held down during 1 frame</returns>
		static bool OnGamepadButtonDown(int button, int gamepad = Gamepads::kGamepad1);
		/// <summary>
		/// Returns true FOR THE FIRST FRAME a gamepad button is released.
		/// </summary>
		/// <param name="button">Gamepad button to check</param>
		/// <param name="gamepad">Gamepad to check</param>
		/// <returns>Whether gamepad button is released during 1 frame</returns>
		static bool OnGamepadButtonUp(int button, int gamepad = Gamepads::kGamepad1);

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
			kPresetHorizontal,
			kPresetVertical,
			kPresetJump,
			kPresetFire1,
			kPresetFire2,
			kPresetCrouch,
			kPresetEscape
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
} // namespace solar

#endif // !SOLAR_INPUT_H_