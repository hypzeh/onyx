#pragma once
#include "..\..\pch.h"

namespace Onyx::Engine::System::Events
{
  class MouseClickEvent : public Event
  {
  public:
    MouseClickEvent(MouseButtonType buttonType);

    std::string GetName() const override;
    EventType GetType() const override;
    MouseButtonType GetButtonType() const;

  private:
    MouseButtonType buttonType_;
  };
}