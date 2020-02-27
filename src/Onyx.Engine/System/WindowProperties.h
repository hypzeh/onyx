#pragma once
#include "..\pch.h"

using namespace Onyx::Engine::System::Events;

namespace Onyx::Engine::System
{
  struct WindowProperties
  {
  public:
    using DispatchEventFunc = std::function<void(Event&)>;

    std::string Title;
    unsigned int Width;
    unsigned int Height;
    bool VSyncEnabled;
    DispatchEventFunc DispatchEvent;
    
    WindowProperties(
      const std::string& title = "ONYX_ENGINE",
      unsigned int width = 1280,
      unsigned int height = 720,
      bool is_vsync_enabled = true,
      DispatchEventFunc dispatch = [](const Event&) {})
      : Title(title),
        Width(width),
        Height(height),
        VSyncEnabled(is_vsync_enabled),
        DispatchEvent(dispatch)
    {}
  };
}
