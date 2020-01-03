#pragma once

namespace Onyx::Diagnostics
{
	class Logger
	{
	public:
		static void Trace(std::string_view message);
		static void Warning(std::string_view message);
		static void Error(std::string_view message);
	};
}

#define ONYX_LOG_TRACE(message)		Onyx::Diagnostics::Logger::Trace(message)
#define ONYX_LOG_WARNING(message)	Onyx::Diagnostics::Logger::Warning(message)
#define ONYX_LOG_ERROR(message)		Onyx::Diagnostics::Logger::Error(message)
