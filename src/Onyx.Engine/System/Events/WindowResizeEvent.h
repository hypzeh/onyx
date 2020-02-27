#pragma once
#include "..\..\pch.h"

namespace Onyx::Engine::System::Events
{
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height);

		std::string GetName() const override;
		EventType GetType() const override;
		unsigned int GetWidth() const;
		unsigned int GetHeight() const;

	private:
		unsigned int width_;
		unsigned int height_;
	};
}
