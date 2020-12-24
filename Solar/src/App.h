#pragma once

#ifndef SOLAR_APP_H_
#define SOLAR_APP_H_

#include "core.h"
#include "types/color.h"

namespace solar
{
	class SOLAR_API App
	{
	public:
		// User-defined initialization
		virtual void Init();
		// User-defined update
		virtual void Update(double frame_time);
		// User-defined rendering
		virtual void Render();
		// User-defined shutdown
		virtual void Exit();

		// Window width
		int Width();
		// Window height
		int Height();

		// Set window width and height
		void SetWindowSize(int width = DEFAULT_WINDOW_WIDTH, int height = DEFAULT_WINDOW_HEIGHT);
		// Set window title
		void SetTitle(const char* title = DEFAULT_TITLE);

		// Set whether window is resizable
		void SetResizable(bool resizable = false);
		// Set whether window is focused
		void SetFocused(bool focused = true);
		// Set whether window is maximized
		void SetMaximized(bool maximized = false);

		// Clear background
		void ClearBackground(Color color = Color());

		// Run the app
		void Run();

		// Quit the app
		void Quit();

		// Current active window
		// Use generics type since glfw is not included in header
		template <typename T>
		static T* window;

	private:
		// Default screen dimension
		int window_width = DEFAULT_WINDOW_WIDTH;
		int window_height = DEFAULT_WINDOW_HEIGHT;

		// Default game window title
		const char* title = "Solar System";
	};
} // namespace solar

#endif // !SOLAR_APP_H_