#include "MouseMoveEvent.h"

namespace Onyx::Engine::System::Events
{
	MouseMoveEvent::MouseMoveEvent(float position_x, float position_y)
		: position_x_(position_x), position_y_(position_y)
	{}

	std::string MouseMoveEvent::GetName() const
	{
		return "MOUSE_MOVE_EVENT";
	}

	EventType MouseMoveEvent::GetType() const
	{
		return EventType::MouseMove;
	}

	float MouseMoveEvent::GetPositionX() const
	{
		return position_x_;
	}

	float MouseMoveEvent::GetPositionY() const
	{
		return position_y_;
	}
}