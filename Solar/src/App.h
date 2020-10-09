#pragma once

#include <iostream>
#include "Core.h"
#include "Logger.h"
#include "Time.h"
#include "Input.h"

namespace Solar
{
	class SOLAR_CLASS App
	{
	public:
		// User-defined functions	
		virtual void Init();
		virtual void Update(double frameTime);
		virtual void Render();
		virtual void Shutdown();

		// Set window width and height
		void SetWindowSize(int width = DEFAULT_WINDOW_WIDTH, int height = DEFAULT_WINDOW_HEIGHT);

		// Set window title
		void SetTitle(const char* title = DEFAULT_TITLE);

		// Run the app
		void Run();

	private:
		// Screen dimension
		int windowWidth = DEFAULT_WINDOW_WIDTH;
		int windowHeight = DEFAULT_WINDOW_HEIGHT;

		// Game window title
		const char* title = "Solar System";
	};
}
