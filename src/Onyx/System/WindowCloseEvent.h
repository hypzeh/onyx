#pragma once
#include "pch.h"

namespace Onyx::System
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		std::string GetName() const override { return "WINDOW_CLOSE_EVENT"; }
	};
}
