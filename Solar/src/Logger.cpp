#include "Logger.h"

namespace Solar
{
	void Logger::Log(const char* message)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLORS::BRIGHT_WHITE);
		std::cout << message << std::endl;
	}

	void Logger::LogWarning(const char* message)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLORS::YELLOW);
		std::cout << "Warning: " << message << std::endl;
	}

	void Logger::LogError(const char* message)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLORS::RED);
		std::cout << "Error: " << message << std::endl;
	}
}
