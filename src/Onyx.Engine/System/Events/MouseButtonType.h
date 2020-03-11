#pragma once
#include "..\..\pch.h"
#include <GLFW\glfw3.h>

namespace Onyx::Engine::System::Events
{
  enum class MouseButtonType
  {
    Left = GLFW_MOUSE_BUTTON_LEFT,
    Middle = GLFW_MOUSE_BUTTON_MIDDLE,
    Right = GLFW_MOUSE_BUTTON_RIGHT
  };
}
