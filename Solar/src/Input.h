#pragma once

#include "Core.h"
#include "App.h"
#include "Vector2.h"

namespace Solar
{
	class SOLAR_API Input
	{
	public:
		static void Update();

#pragma region Keyboard
		// GLFW Keys input
		enum KEYS
		{
			UNKNOWN = -1,
			SPACE = 32,
			APOSTROPHE = 39, // '
			COMMA = 44,
			MINUS = 45,
			PERIOD = 46,
			SLASH = 47, // /
			ZERO = 48,
			ONE = 49,
			TWO = 50,
			THREE = 51,
			FOUR = 52,
			FIVE = 53,
			SIX = 54,
			SEVEN = 55,
			EIGHT = 56,
			NINE = 57,
			SEMICOLON = 59, // ;
			EQUAL = 61,		// =
			A = 65,
			B = 66,
			C = 67,
			D = 68,
			E = 69,
			F = 70,
			G = 71,
			H = 72,
			I = 73,
			J = 74,
			K = 75,
			L = 76,
			M = 77,
			N = 78,
			O = 79,
			P = 80,
			Q = 81,
			R = 82,
			S = 83,
			T = 84,
			U = 85,
			V = 86,
			W = 87,
			X = 88,
			Y = 89,
			Z = 90,
			LEFT_BRACKET = 91,	// [
			BACKSLASH = 92,		/* \ */
			RIGHT_BRACKET = 93, // ]
			GRAVE_ACCENT = 96,	// `
			WORLD_1 = 161,		// non-US #1
			WORLD_2 = 162,		// non-US #2
			ESCAPE = 256,
			ENTER = 257,
			TAB = 258,
			BACKSPACE = 259,
			INSERT = 260,
			DEL = 261, // Delete
			RIGHT = 262,
			LEFT = 263,
			DOWN = 264,
			UP = 265,
			PAGE_UP = 266,
			PAGE_DOWN = 267,
			HOME = 268,
			END = 269,
			CAPS_LOCK = 280,
			SCROLL_LOCK = 281,
			NUM_LOCK = 282,
			PRTSCR = 283, // Print screen
			PAUSE = 284,
			F1 = 290,
			F2 = 291,
			F3 = 292,
			F4 = 293,
			F5 = 294,
			F6 = 295,
			F7 = 296,
			F8 = 297,
			F9 = 298,
			F10 = 299,
			F11 = 300,
			F12 = 301,
			F13 = 302,
			F14 = 303,
			F15 = 304,
			F16 = 305,
			F17 = 306,
			F18 = 307,
			F19 = 308,
			F20 = 309,
			F21 = 310,
			F22 = 311,
			F23 = 312,
			F24 = 313,
			F25 = 314,
			KEYPAD_ZERO = 320,
			KEYPAD_ONE = 321,
			KEYPAD_TWO = 322,
			KEYPAD_THREE = 323,
			KEYPAD_FOUR = 324,
			KEYPAD_FIVE = 325,
			KEYPAD_SIX = 326,
			KEYPAD_SEVEN = 327,
			KEYPAD_EIGHT = 328,
			KEYPAD_NINE = 329,
			KEYPAD_DECIMAL = 330,
			KEYPAD_DIVIDE = 331,
			KEYPAD_MULTIPLY = 332,
			KEYPAD_SUBTRACT = 333,
			KEYPAD_ADD = 334,
			KEYPAD_ENTER = 335,
			KEYPAD_EQUAL = 336,
			LEFT_SHIFT = 340,
			LEFT_CONTROL = 341,
			LEFT_ALT = 342,
			LEFT_SUPER = 343,
			RIGHT_SHIFT = 344,
			RIGHT_COTROL = 345,
			RIGHT_ALT = 346,
			MENU = 348,
		};

		static bool IsKeyDown(int key); // Returns true if a key is being held down
		static bool IsKeyUp(int key);	// Returns true if a key is NOT being held down

		static bool OnKeyDown(int key); // Returns true FOR THE FIRST FRAME a key is held down
		static bool OnKeyUp(int key);	// Returns true FOR THE FIRST FRAME a key is released

		static int keyDownBuffer; // Buffer memory for key down
		static int keyUpBuffer;	  // Buffer memory for key up
#pragma endregion

#pragma region Cursor
		// GLFW Input modes
		enum CURSOR_MODES
		{
			LOCKED = 212995,
			HIDDEN = 212994,
			NORMAL = 212993
		};

		static Vector2 CursorPosition();	 // X and Y position of cursor
		static void SetCursorMode(int mode); // Set cursor mode to locked, hidden or normal

		static bool cursorEnter;
		static bool cursorExit;

		static bool OnCursorEnter();
		static bool OnCursorExit();

		static bool cursorEnterExitBuffer;
#pragma endregion

#pragma region Mouse
		// GLFW mouse buttons
		enum MOUSE_BUTTONS
		{
			MOUSE_LEFT = 0,
			MOUSE_RIGHT = 1,
			MOUSE_MIDDLE = 2
		};

		static bool IsMouseDown(int mouse); // Returns true if a mouse button is being held down
		static bool IsMouseUp(int mouse);	// Returns true if a mouse button is NOT being held down

		static bool OnMouseDown(int mouse); // Returns true FOR THE FIRST FRAME a mouse button is held down
		static bool OnMouseUp(int mouse);	// Returns true FOR THE FIRST FRAME a mouse button is released

		static int mouseDownBuffer; // Buffer memory for mouse button down
		static int mouseUpBuffer;	// Buffer memory for mouse button up

		static double scrollDeltaX;
		static double scrollDeltaY;

		static double ScrollDeltaX(); // Return mouse scrolling speed x
		static double ScrollDeltaY(); // Return mouse scrolling speed y

		static bool scrollBuffer;
#pragma endregion

#pragma region Joystick
		enum JOYSTICKS
		{
			JOYSTICK_1 = 0,
			JOYSTICK_2 = 1,
			JOYSTICK_3 = 2,
			JOYSTICK_4 = 3,
			JOYSTICK_5 = 4,
			JOYSTICK_6 = 5,
			JOYSTICK_7 = 6,
			JOYSTICK_8 = 7,
			JOYSTICK_9 = 8,
			JOYSTICK_10 = 9,
			JOYSTICK_11 = 10,
			JOYSTICK_12 = 11,
			JOYSTICK_13 = 12,
			JOYSTICK_14 = 13,
			JOYSTICK_15 = 14,
			JOYSTICK_16 = 15,
		};

		static bool IsJoystickPresent(int joystick);

		// Not working
		// TODO: Investigate this further
		static bool OnJoystickConnected(int joystick);
		static bool OnJoystickDisconnected(int joystick);

		static int joystickConnectBuffer;
		static int joystickDisconnectBuffer;

#pragma endregion

	private:
		static double cursorX;
		static double cursorY;

		static int inputMode;
	};
} // namespace Solar
