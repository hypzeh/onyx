#pragma once
#include "..\..\pch.h"

namespace Onyx::Engine::System::Events
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		std::string GetName() const override;
		EventType GetType() const override;
	};
}
