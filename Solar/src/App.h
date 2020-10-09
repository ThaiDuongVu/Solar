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
		virtual void Update();
		virtual void Render();
		virtual void Shutdown();

		// Run the app
		void Run(int width = 800, int height = 600, const char* title = "Solar System");
	};
}
