#pragma once
#include "..\..\pch.h"

namespace Onyx::Engine::System::Events
{
	class Event
	{
	public:
		virtual std::string GetName() const = 0;
		virtual EventType GetType() const		= 0;
	};
}
