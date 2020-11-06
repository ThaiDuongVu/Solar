#pragma once

#include "Core.h"
#include "App.h"
#include "types/Vector2.h"

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
			KEY_UNKNOWN = -1,
			KEY_SPACE = 32,
			KEY_APOSTROPHE = 39, // '
			KEY_COMMA = 44,
			KEY_MINUS = 45,
			KEY_PERIOD = 46,
			KEY_SLASH = 47, // /
			KEY_ZERO = 48,
			KEY_ONE = 49,
			KEY_TWO = 50,
			KEY_THREE = 51,
			KEY_FOUR = 52,
			KEY_FIVE = 53,
			KEY_SIX = 54,
			KEY_SEVEN = 55,
			KEY_EIGHT = 56,
			KEY_NINE = 57,
			KEY_SEMICOLON = 59, // ;
			KEY_EQUAL = 61,		// =
			KEY_A = 65,
			KEY_B = 66,
			KEY_C = 67,
			KEY_D = 68,
			KEY_E = 69,
			KEY_F = 70,
			KEY_G = 71,
			KEY_H = 72,
			KEY_I = 73,
			KEY_J = 74,
			KEY_K = 75,
			KEY_L = 76,
			KEY_M = 77,
			KEY_N = 78,
			KEY_O = 79,
			KEY_P = 80,
			KEY_Q = 81,
			KEY_R = 82,
			KEY_S = 83,
			KEY_T = 84,
			KEY_U = 85,
			KEY_V = 86,
			KEY_W = 87,
			KEY_X = 88,
			KEY_Y = 89,
			KEY_Z = 90,
			KEY_LEFT_BRACKET = 91,	// [
			KEY_BACKSLASH = 92,		/* \ */
			KEY_RIGHT_BRACKET = 93, // ]
			KEY_GRAVE_ACCENT = 96,	// `
			KEY_WORLD_1 = 161,		// non-US #1
			KEY_WORLD_2 = 162,		// non-US #2
			KEY_ESCAPE = 256,
			KEY_ENTER = 257,
			KEY_TAB = 258,
			KEY_BACKSPACE = 259,
			KEY_INSERT = 260,
			KEY_DEL = 261, // Delete
			KEY_MOUSE_RIGHT = 262,
			KEY_MOUSE_LEFT = 263,
			KEY_DOWN = 264,
			KEY_UP = 265,
			KEY_PAGE_UP = 266,
			KEY_PAGE_DOWN = 267,
			KEY_HOME = 268,
			KEY_END = 269,
			KEY_CAPS_LOCK = 280,
			KEY_SCROLL_LOCK = 281,
			KEY_NUM_LOCK = 282,
			KEY_PRTSCR = 283, // Print screen
			KEY_PAUSE = 284,
			KEY_F1 = 290,
			KEY_F2 = 291,
			KEY_F3 = 292,
			KEY_F4 = 293,
			KEY_F5 = 294,
			KEY_F6 = 295,
			KEY_F7 = 296,
			KEY_F8 = 297,
			KEY_F9 = 298,
			KEY_F10 = 299,
			KEY_F11 = 300,
			KEY_F12 = 301,
			KEY_F13 = 302,
			KEY_F14 = 303,
			KEY_F15 = 304,
			KEY_F16 = 305,
			KEY_F17 = 306,
			KEY_F18 = 307,
			KEY_F19 = 308,
			KEY_F20 = 309,
			KEY_F21 = 310,
			KEY_F22 = 311,
			KEY_F23 = 312,
			KEY_F24 = 313,
			KEY_F25 = 314,
			KEY_KEYPAD_ZERO = 320,
			KEY_KEYPAD_ONE = 321,
			KEY_KEYPAD_TWO = 322,
			KEY_KEYPAD_THREE = 323,
			KEY_KEYPAD_FOUR = 324,
			KEY_KEYPAD_FIVE = 325,
			KEY_KEYPAD_SIX = 326,
			KEY_KEYPAD_SEVEN = 327,
			KEY_KEYPAD_EIGHT = 328,
			KEY_KEYPAD_NINE = 329,
			KEY_KEYPAD_DECIMAL = 330,
			KEY_KEYPAD_DIVIDE = 331,
			KEY_KEYPAD_MULTIPLY = 332,
			KEY_KEYPAD_SUBTRACT = 333,
			KEY_KEYPAD_ADD = 334,
			KEY_KEYPAD_ENTER = 335,
			KEY_KEYPAD_EQUAL = 336,
			KEY_LEFT_SHIFT = 340,
			KEY_LEFT_CONTROL = 341,
			KEY_LEFT_ALT = 342,
			KEY_LEFT_SUPER = 343,
			KEY_RIGHT_SHIFT = 344,
			KEY_RIGHT_COTROL = 345,
			KEY_RIGHT_ALT = 346,
			KEY_MENU = 348,
			KEY_LAST = 348
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
			MODE_LOCKED = 212995,
			MODE_HIDDEN = 212994,
			MODE_NORMAL = 212993
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
			JOYSTICK_LAST = 15,
		};
		enum JOYSTICK_AXES
		{
			AXES_LEFT_STICK_X = 0,
			AXES_LEFT_STICK_Y = 1,
			AXES_RIGHT_STICK_X = 2,
			AXES_RIGHT_STICK_Y = 3,
			AXES_LEFT_TRIGGER = 4,
			AXES_RIGHT_TRIGGER = 5,
		};
		enum JOYSTICK_BUTTONS
		{
			BUTTON_A = 0,
			BUTTON_B = 1,
			BUTTON_X = 2,
			BUTTON_Y = 3,
			BUTTON_LEFT_BUMPER = 4,
			BUTTON_RIGHT_BUMPER = 5,
			BUTTON_BACK = 6,
			BUTTON_START = 7,
			BUTTON_LEFT_STICK = 8,
			BUTTON_RIGHT_STICK = 9,
			BUTTON_DPAD_UP = 10,
			BUTTON_DPAP_RIGHT = 11,
			BUTTON_DPAD_DOWN = 12,
			BUTTON_DPAD_LEFT = 13,
		};

		static bool IsJoystickPresent(int joystick);								  // Whether a joystick is connected
		static float GetJoystickAxes(int axes, int joystick = JOYSTICKS::JOYSTICK_1); // Get values of different joystick axes

		static bool IsJoystickButtonDown(int button, int joystick = JOYSTICKS::JOYSTICK_1); // Returns true if a joystick button is being held down
		static bool IsJoystickButtonUp(int button, int joystick = JOYSTICKS::JOYSTICK_1);	// Returns true if a joystick button is NOT being held down

		static bool OnJoystickButtonDown(int button, int joystick = JOYSTICKS::JOYSTICK_1); // Returns true FOR THE FIRST FRAME a joystick button is held down
		static bool OnJoystickButtonUp(int button, int joystick = JOYSTICKS::JOYSTICK_1);	// Returns true FOR THE FIRST FRAME a joystick button is released

		static int buttonDownBuffer;
		static int buttonUpBuffer;
#pragma endregion

	private:
		static double cursorX;
		static double cursorY;

		static const float *joystickAxes[]; // 2D Array representing joystick axes
		static int joystickAxesCount;
		static int joystickButtonCount;

		static int cursorMode;
	};
} // namespace Solar
