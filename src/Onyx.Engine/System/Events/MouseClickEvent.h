#pragma once
#include "..\..\pch.h"

namespace Onyx::Engine::System::Events
{
  class MouseClickEvent : public Event
  {
  public:
    MouseClickEvent(MouseButtonType type, MouseButtonAction action);

    std::string GetName() const override;
    EventType GetType() const override;
    MouseButtonType GetButtonType() const;
    MouseButtonAction GetButtonAction() const;

  private:
    MouseButtonType buttonType_;
    MouseButtonAction buttonAction_;
  };
}