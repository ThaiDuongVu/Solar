#pragma once

#ifndef SOLAR_DEBUG_H_
#define SOLAR_DEBUG_H_

#include <iostream>
#include <windows.h>
#include <string>
#include "core.h"

namespace Solar
{
	class SOLAR_API Debug
	{
	public:
		enum DebugColors
		{
			ColorBlack = 0,
			ColorBlue = 1,
			ColorGreen = 2,
			ColorAqua = 3,
			ColorRed = 4,
			ColorPurple = 5,
			ColorYellow = 6,
			ColorWhite = 7,
			ColorGray = 8,
			ColorLightBlue = 9,
			ColorLightGreen = 10,
			ColorLightAqua = 11,
			ColorLightRed = 12,
			ColorLightPurple = 13,
			ColorLightYellow = 14,
			ColorBrightWhite = 15,
		};

		/// <summary>
		/// Log a message to console.
		/// </summary>
		/// <typeparam name="T">Message type</typeparam>
		/// <param name="message">Message to log</param>
		template <typename T>
		inline static void Log(T message)
		{
			// Set console test color to white
			// Only works on Windows
			// TODO (Duong): Cross-platforming this
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Solar::Debug::DebugColors::ColorBrightWhite);
			std::cout << message << std::endl;
		}

		/// <summary>
		/// Log a warning message to console.
		/// </summary>
		/// <typeparam name="T">Message type</typeparam>
		/// <param name="message">Message to log</param>
		template <typename T>
		inline static void LogWarning(T message)
		{
			// Set console test color to yellow
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Solar::Debug::DebugColors::ColorYellow);
			std::cout << "Warning: " << message << std::endl;

			ResetDebugColor();
		}

		/// <summary>
		/// Log a error message to console.
		/// </summary>
		/// <typeparam name="T">Message type</typeparam>
		/// <param name="message">Message to log</param>
		template <typename T>
		inline static void LogError(T message)
		{
			// Set console test color to red
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Solar::Debug::DebugColors::ColorRed);
			std::cout << "Error: " << message << std::endl;

			ResetDebugColor();
		}

		template <typename T>
		inline static void LogColor(T message, Solar::Debug::DebugColors color = Solar::Debug::DebugColors::ColorBrightWhite)
		{
			// Set console test color to the designated color
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
			std::cout << message << std::endl;

			ResetDebugColor();
		}

	private:
		/// <summary>
		/// Reset console color to white.
		/// </summary>
		inline static void ResetDebugColor()
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Solar::Debug::DebugColors::ColorBrightWhite);
		}
	};
} // namespace Solar

#endif // !SOLAR_DEBUG_H_