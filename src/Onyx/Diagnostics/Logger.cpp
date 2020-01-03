#include "pch.h"
#include "Logger.h"

namespace Onyx::Diagnostics
{
	void Logger::Trace(std::string_view message)
	{
		std::cout << "\033[37m[TRACE] " << message << "\033[m\n";
	}

	void Logger::Warning(std::string_view message)
	{
		std::cout << "\033[33m[WARNING] " << message << "\033[m\n";
	}

	void Logger::Error(std::string_view message)
	{
		std::cout << "\033[31m[ERROR] " << message << "\033[m\n";
	}
}
