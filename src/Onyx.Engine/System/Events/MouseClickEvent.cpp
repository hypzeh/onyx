#include "MouseClickEvent.h"

Onyx::Engine::System::Events::MouseClickEvent::MouseClickEvent(MouseButtonType buttonType)
  : buttonType_(buttonType)
{}

std::string Onyx::Engine::System::Events::MouseClickEvent::GetName() const
{
  return "MOUSE_CLICK_EVENT";
}

EventType Onyx::Engine::System::Events::MouseClickEvent::GetType() const
{
  return EventType::MouseClick;
}

MouseButtonType Onyx::Engine::System::Events::MouseClickEvent::GetButtonType() const
{
  return buttonType_;
}
