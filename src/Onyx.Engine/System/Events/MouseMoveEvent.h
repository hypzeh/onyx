#pragma once
#include "..\..\pch.h"

namespace Onyx::Engine::System::Events
{
	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float position_x, float position_y);

		std::string GetName() const override;
		EventType GetType() const override;
		float GetPositionX() const;
		float GetPositionY() const;

	private:
		float position_x_;
		float position_y_;
	};
}
