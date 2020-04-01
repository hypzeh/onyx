#include "MouseClickEvent.h"

Onyx::Engine::System::Events::MouseClickEvent::MouseClickEvent(MouseButtonType type, MouseButtonAction action)
  : buttonType_(type), buttonAction_(action)
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

MouseButtonAction Onyx::Engine::System::Events::MouseClickEvent::GetButtonAction() const
{
  return buttonAction_;
}
