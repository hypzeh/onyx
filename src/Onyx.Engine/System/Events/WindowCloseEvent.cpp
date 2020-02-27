#include "WindowCloseEvent.h"

namespace Onyx::Engine::System::Events
{
    std::string WindowCloseEvent::GetName() const
    {
      return "WINDOW_CLOSE_EVENT";
    }

    EventType WindowCloseEvent::GetType() const
    {
      return EventType::WindowClose;
    }
}
