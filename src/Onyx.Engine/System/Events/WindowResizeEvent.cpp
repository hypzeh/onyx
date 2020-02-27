#include "WindowResizeEvent.h"

namespace Onyx::Engine::System::Events
{
	WindowResizeEvent::WindowResizeEvent(unsigned int width, unsigned int height)
		: width_(width), height_(height)
	{}

	std::string WindowResizeEvent::GetName() const
	{
		return "WINDOW_RESIZE_EVENT";
	}

	EventType WindowResizeEvent::GetType() const
	{
		return EventType::WindowResize;
	}

	unsigned int WindowResizeEvent::GetWidth() const
	{
		return width_;
	}

	unsigned int WindowResizeEvent::GetHeight() const
	{
		return height_;
	}
}