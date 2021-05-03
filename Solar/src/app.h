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
		/// Current window size (width and height).
		/// </summary>
		/// <returns>Window size</returns>
		Vector2 Size();
		/// <summary>
		/// Currennt window width.
		/// </summary>
		/// <returns>Window width</returns>
		int Width();
		/// <summary>
		/// Current window height.
		/// </summary>
		/// <returns>Window height</returns>
		int Height();
		/// <summary>
		/// Current window title.
		/// </summary>
		/// <returns>Window title</returns>
		std::string Title();
		/// <summary>
		/// Current window resizable.
		/// </summary>
		/// <returns>Window resizable</returns>
		bool Resizable();
		/// <summary>
		/// Current window focused.
		/// </summary>
		/// <returns>Window focused</returns>
		bool Focused();
		/// <summary>
		/// Current window maximized.
		/// </summary>
		/// <returns>Window maximized</returns>
		bool Maximized();
		/// <summary>
		/// Current window visible.
		/// </summary>
		/// <returns>Window visible</returns>
		bool Visible();
		/// <summary>
		/// Current window decorated.
		/// </summary>
		/// <returns>Window decorated</returns>
		bool Decorated();
		/// <summary>
		/// Current window floating.
		/// </summary>
		/// <returns></returns>
		bool Floating();
		/// <summary>
		/// Current window position.
		/// </summary>
		/// <returns>Window position</returns>
		Vector2 Position();
		/// <summary>
		/// Current window position x.
		/// </summary>
		/// <returns>Window position x</returns>
		double PositionX();
		/// <summary>
		/// Current window position y.
		/// </summary>
		/// <returns>Window position y</returns>
		double PositionY();

		/// <summary>
		/// Set window width and height.
		/// </summary>
		/// <param name="width">Width to set</param>
		/// <param name="height">Height to set</param>
		void SetSize(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
		/// <summary>
		/// Set window width.
		/// </summary>
		/// <param name="width">Width to set</param>
		void SetWidth(int width);
		/// <summary>
		/// Set window height.
		/// </summary>
		/// <param name="height">Height to set</param>
		void SetHeight(int height);
		/// <summary>
		/// Set window title.
		/// </summary>
		/// <param name="title">Title to set</param>
		void SetTitle(std::string title = DEFAULT_TITLE);
		/// <summary>
		/// Set whether window is resizable.
		/// </summary>
		/// <param name="resizable">Window resizable</param>
		void SetResizable(bool resizable = DEFAULT_RESIZABLE);
		/// <summary>
		/// Set whether window is focused.
		/// </summary>
		/// <param name="focused">Window focused</param>
		void SetFocused(bool focused = DEFAULT_FOCUSED);
		/// <summary>
		/// Set whether window is maximized.
		/// </summary>
		/// <param name="maximized">Window maximized</param>
		void SetMaximized(bool maximized = DEFAULT_MAXIMIZED);
		/// <summary>
		/// Set whether window is visible.
		/// </summary>
		/// <param name="visible">Window visible</param>
		void SetVisible(bool visible = DEFAULT_VISIBLE);
		/// <summary>
		/// Set whether window is decorated.
		/// </summary>
		/// <param name="decorated">Window decorated</param>
		void SetDecorated(bool decorated = DEFAULT_DECORATED);
		/// <summary>
		/// Set whether window is always on top.
		/// </summary>
		/// <param name="floating">Window floating</param>
		void SetFloating(bool floating = DEFAULT_FLOATING);
		/// <summary>
		/// Set window position.
		/// </summary>
		/// <param name="x">Position x to set</param>
		/// <param name="y">Position y to set</param>
		void SetPosition(int position_x = DEFAULT_POSITION_X, int position_y = DEFAULT_POSITION_Y);
		/// <summary>
		/// Set window position.
		/// </summary>
		/// <param name="position">Position to set</param>
		void SetPosition(Vector2 position = Vector2(DEFAULT_POSITION_X, DEFAULT_POSITION_Y));
		void SetPositionX(int position_x = 0);
		void SetPositionY(int position_y = 0);

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
		/// Current window width.
		/// </summary>
		int width = DEFAULT_WIDTH;
		/// <summary>
		/// Current window height.
		/// </summary>
		int height = DEFAULT_HEIGHT;
		/// <summary>
		/// Current window title.
		/// </summary>
		std::string title = DEFAULT_TITLE;
		/// <summary>
		/// Current window resizable.
		/// </summary>
		bool resizable = DEFAULT_RESIZABLE;
		/// <summary>
		/// Current window focused.
		/// </summary>
		bool focused = DEFAULT_FOCUSED;
		/// <summary>
		/// Current window maximized.
		/// </summary>
		bool maximized = DEFAULT_MAXIMIZED;
		/// <summary>
		/// Current window visible.
		/// </summary>
		bool visible = DEFAULT_VISIBLE;
		/// <summary>
		/// Current window decorated.
		/// </summary>
		bool decorated = DEFAULT_DECORATED;
		/// <summary>
		/// Current window floating.
		/// </summary>
		bool floating = DEFAULT_FLOATING;
		/// <summary>
		/// Current window position x.
		/// </summary>
		int position_x = DEFAULT_POSITION_X;
		/// <summary>
		/// Current window position y.
		/// </summary>
		int position_y = DEFAULT_POSITION_Y;
	};
} // namespace Solar

#endif // !SOLAR_APP_H_