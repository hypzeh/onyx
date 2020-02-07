#pragma once
#include "..\pch.h"

namespace Onyx::Engine::System
{
	enum class EventType
	{
		None = 0,
		WindowClose = 1
	};

	class Event
	{
	public:
		virtual std::string GetName() const = 0;
		virtual EventType GetType() const = 0;
	};
}