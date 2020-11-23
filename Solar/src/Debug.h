#pragma once

#ifndef SOLAR_DEBUG_H_
#define SOLAR_DEBUG_H_

#include <iostream>
#include <windows.h>
#include <string>
#include "core.h"

namespace solar
{
	class SOLAR_API Debug
	{
	public:
		enum DebugColors
		{
			kBlack = 0,
			kBlue = 1,
			kGreen = 2,
			kAqua = 3,
			kRed = 4,
			kPurple = 5,
			kYellow = 6,
			kWhite = 7,
			kGray = 8,
			kLightBlue = 9,
			kLightGreen = 10,
			kLightAqua = 11,
			kLightRed = 12,
			kLightPurple = 13,
			kLightYellow = 14,
			kBrightWhite = 15,
		};

		template <typename T>
		inline static void Log(T message)
		{
			// Set console test color_ to white
			// Only works on Windows
			// TODO: Cross-platforming this
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), solar::Debug::DebugColors::kBrightWhite);
			std::cout << message << std::endl;
		}

		template <typename T>
		inline static void LogWarning(T message)
		{
			// Set console test color_ to yellow
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), solar::Debug::DebugColors::kYellow);
			std::cout << "Warning: " << message << std::endl;

			ResetDebugColor();
		}

		template <typename T>
		inline static void LogError(T message)
		{
			// Set console test color_ to red
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), solar::Debug::DebugColors::kRed);
			std::cout << "Error: " << message << std::endl;

			ResetDebugColor();
		}

	private:
		// Reset console color_ to white
		inline static void ResetDebugColor()
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), solar::Debug::DebugColors::kBrightWhite);
		}
	};
} // namespace solar

#endif // !SOLAR_DEBUG_H_