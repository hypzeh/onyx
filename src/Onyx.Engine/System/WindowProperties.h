#pragma once
#include "..\pch.h"

namespace Onyx::Engine::System
{
  struct WindowProperties
  {
  public:
    using DispatchEventFunc = std::function<void(Event&)>;

    std::string Title;
    unsigned int Width;
    unsigned int Height;
    DispatchEventFunc DispatchEvent;
    
    WindowProperties(
      const std::string& title = "ONYX_ENGINE",
      unsigned int width = 1280,
      unsigned int height = 720,
      DispatchEventFunc dispatch = [](const Event&) {})
      : Title(title),
        Width(width),
        Height(height),
        DispatchEvent(dispatch)
    {}
  };
}
