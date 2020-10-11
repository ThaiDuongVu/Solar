#pragma once

#include <iostream>
#include <Windows.h>
#include "Core.h"

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

