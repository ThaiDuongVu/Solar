#pragma once

#include <iostream>
#include <Windows.h>
#include "Core.h"

enum DEBUG_COLORS
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	AQUA = 3,
	RED = 4,
	PURPLE = 5,
	YELLOW = 6,
	WHITE = 7,
	GRAY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_AQUA = 11,
	LIGHT_RED = 12,
	LIGHT_PURPLE = 13,
	LIGHT_YELLOW = 14,
	BRIGHT_WHITE = 15,
};

namespace Solar
{
	class SOLAR_CLASS Debug
	{
	public:
		template <typename T>
		inline static void Log(T message)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEBUG_COLORS::BRIGHT_WHITE);
			std::cout << message << std::endl;
		};

		template <typename T>
		inline static void LogWarning(T message)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEBUG_COLORS::YELLOW);
			std::cout << "Warning: " << message << std::endl;
		};

		template <typename T>
		inline static void LogError(T message)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEBUG_COLORS::RED);
			std::cout << "Error: " << message << std::endl;
		};
	};
}

