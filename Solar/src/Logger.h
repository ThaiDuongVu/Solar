#pragma once

#include <iostream>
#include <Windows.h>
#include "Core.h"

namespace Solar
{
	class SOLAR_CLASS Logger
	{
	public:
		static void Log(const char* message);
		static void LogWarning(const char* message);
		static void LogError(const char* message);
	};
}

