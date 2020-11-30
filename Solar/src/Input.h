#pragma once

#ifndef SOLAR_INPUT_H_
#define SOLAR_INPUT_H_

#include "core.h"
#include "types/vector2.h"

namespace solar
{
	class SOLAR_API Input
	{
	public:
		static void Update();

#pragma region Keyboard
		// GLFW Keys input
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

		static bool IsKeyDown(int key); // Returns true if a key is being held down
		static bool IsKeyUp(int key);	// Returns true if a key is NOT being held down

		static bool OnKeyDown(int key); // Returns true FOR THE FIRST FRAME a key is held down
		static bool OnKeyUp(int key);	// Returns true FOR THE FIRST FRAME a key is released

		static int key_down_buffer_; // Buffer memory for key down
		static int key_up_buffer_;	 // Buffer memory for key up
#pragma endregion

#pragma region Cursor
		// GLFW Input modes
		enum CursorModes
		{
			kModeLocked = 212995,
			kModeHidden = 212994,
			kModeNormal = 212993
		};

		static Vector2 CursorPosition();	 // X and Y position of cursor
		static void SetCursorMode(int mode); // Set cursor mode to locked, hidden or normal

		static bool cursor_enter_;
		static bool cursor_exit_;

		static bool OnCursorEnter(); // On cursor enter window_
		static bool OnCursorExit();	 // On cursor exit window_

		static bool cursor_enter_exit_buffer_;
#pragma endregion

#pragma region Mouse
		// GLFW mouse buttons
		enum MouseButtons
		{
			kMouseLeft = 0,
			kMouseRight = 1,
			kMouseMiddle = 2
		};

		static bool IsMouseDown(int mouse); // Returns true if a mouse button is being held down
		static bool IsMouseUp(int mouse);	// Returns true if a mouse button is NOT being held down

		static bool OnMouseDown(int mouse); // Returns true FOR THE FIRST FRAME a mouse button is held down
		static bool OnMouseUp(int mouse);	// Returns true FOR THE FIRST FRAME a mouse button is released

		static int mouse_down_buffer_; // Buffer memory for mouse button down
		static int mouse_up_buffer_;   // Buffer memory for mouse button up

		static double scroll_delta_x_;
		static double scroll_delta_y_;

		static double ScrollDeltaX(); // Return mouse scrolling speed x
		static double ScrollDeltaY(); // Return mouse scrolling speed y

		static bool scroll_buffer_;
#pragma endregion

#pragma region Joystick
		enum Joysticks
		{
			kJoystick1 = 0,
			kJoystick2 = 1,
			kJoystick3 = 2,
			kJoystick4 = 3,
			kJoystick5 = 4,
			kJoystick6 = 5,
			kJoystick7 = 6,
			kJoystick8 = 7,
			kJoystick9 = 8,
			kJoystick10 = 9,
			kJoystick11 = 10,
			kJoystick12 = 11,
			kJoystick13 = 12,
			kJoystick14 = 13,
			kJoystick15 = 14,
			kJoystick16 = 15,
			kJoystickLast = 15,
		};
		enum JoystickAxes
		{
			kAxesLeftStickX = 0,
			kAxesLeftStickY = 1,
			kAxesRightStickX = 2,
			kAxesRightStickY = 3,
			kAxesLeftTrigger = 4,
			kAxesRightTrigger = 5,
		};
		enum JoystickButtons
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

		static bool IsJoystickPresent(int joystick);								  // Whether a joystick is connected
		static float GetJoystickAxes(int axes, int joystick = Joysticks::kJoystick1); // Get values of different joystick axes

		static bool IsJoystickButtonDown(int button, int joystick = Joysticks::kJoystick1); // Returns true if a joystick button is being held down
		static bool IsJoystickButtonUp(int button, int joystick = Joysticks::kJoystick1);	// Returns true if a joystick button is NOT being held down

		static bool OnJoystickButtonDown(int button, int joystick = Joysticks::kJoystick1); // Returns true FOR THE FIRST FRAME a joystick button is held down
		static bool OnJoystickButtonUp(int button, int joystick = Joysticks::kJoystick1);	// Returns true FOR THE FIRST FRAME a joystick button is released

		static int button_down_buffer_;
		static int button_up_buffer_;
#pragma endregion

		// TODO: Get vertical/horizontal axis (WASD, arrow keys, joystick)

	private:
		static double cursor_x_;
		static double cursor_y_;

		static const float *joystick_axes_[]; // 2D Array representing joystick axes
		static int joystick_axes_count_;
		static int joystick_button_count_;

		static int cursor_mode_;
	};
} // namespace solar

#endif // !SOLAR_INPUT_H_