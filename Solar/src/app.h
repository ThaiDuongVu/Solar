#pragma once

#ifndef SOLAR_APP_H_
#define SOLAR_APP_H_

#include "core.h"
#include "types/color.h"
#include "viewport.h"

namespace Solar
{
	class SOLAR_API App
	{
	public:
		/// <summary>
		/// User-defined initialization.
		/// </summary>
		virtual void Init();
		/// <summary>
		/// User-defined update.
		/// </summary>
		/// <param name="frame_time">Current frame time</param>
		virtual void Update();
		/// <summary>
		/// User-defined rendering
		/// </summary>
		virtual void Render();
		/// <summary>
		/// User-defined shutdown
		/// </summary>
		virtual void Exit();

		/// <summary>
		/// Window width.
		/// </summary>
		/// <returns>Window width</returns>
		int Width();
		/// <summary>
		/// Window height.
		/// </summary>
		/// <returns>Window height</returns>
		int Height();

		/// <summary>
		/// Set window width and height.
		/// </summary>
		/// <param name="width">Width to set</param>
		/// <param name="height">Height to set</param>
		void SetWindowSize(int width = DEFAULT_WINDOW_WIDTH, int height = DEFAULT_WINDOW_HEIGHT);
		/// <summary>
		/// Set window title.
		/// </summary>
		/// <param name="title">Title to set</param>
		void SetWindowTitle(const char* title = DEFAULT_TITLE);

		/// <summary>
		/// Set whether window is resizable.
		/// </summary>
		/// <param name="resizable">Window resizable</param>
		void SetWindowResizable(bool resizable = false);
		/// <summary>
		/// Set whether window is focused.
		/// </summary>
		/// <param name="focused">Window focused</param>
		void SetWindowFocused(bool focused = true);
		/// <summary>
		/// Set whether window is maximized.
		/// </summary>
		/// <param name="maximized">Window maximized</param>
		void SetWindowMaximized(bool maximized = false);

		/// <summary>
		/// Run the app.
		/// </summary>
		void Run();

		/// <summary>
		/// Quit the app.
		/// </summary>
		void Quit();

		/// <summary>
		/// Current active window.
		/// Use generics type since glfw is not included in header.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		template <typename T>
		static T* window;

		/// <summary>
		/// Current window viewport.
		/// </summary>
		Viewport viewport;

	private:
		/// <summary>
		/// Default window width.
		/// </summary>
		int window_width = DEFAULT_WINDOW_WIDTH;
		/// <summary>
		/// Default window height.
		/// </summary>
		int window_height = DEFAULT_WINDOW_HEIGHT;

		/// <summary>
		/// Default window title.
		/// </summary>
		const char* title = "Solar System";
	};
} // namespace Solar

#endif // !SOLAR_APP_H_