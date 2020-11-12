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
		// User-defined functions
		virtual void Init();
		virtual void Update(double frame_time);
		virtual void Render();
		virtual void Exit();

		// Set window_ width and height
		void SetWindowSize(int width = DEFAULT_WINDOW_WIDTH, int height = DEFAULT_WINDOW_HEIGHT);

		// Set window_ title_
		void SetTitle(const char *title = DEFAULT_TITLE);

		// Clear background
		void ClearBackground(Color color = Color());

		// Run the app
		void Run();

		// Quit the app
		void Quit();

		// Current active window_
		// Use generics type since glfw is not included in header
		template <typename T>
		static T *window_;

	private:
		// Default screen dimension
		int window_width_ = DEFAULT_WINDOW_WIDTH;
		int window_height_ = DEFAULT_WINDOW_HEIGHT;

		// Default game window_ title_
		const char *title_ = "Solar System";
	};
} // namespace solar

#endif // !SOLAR_APP_H_