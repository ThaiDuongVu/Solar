#include "Logger.h"

namespace Solar
{
	void Logger::Log(const char* message)
	{
		std::cout << message << std::endl;
	}

	void Logger::LogWarning(const char* message)
	{
		std::cout << "Warning: " << message << std::endl;
	}

	void Logger::LogError(const char* message)
	{
		std::cout << "Error: " << message << std::endl;
	}
}
