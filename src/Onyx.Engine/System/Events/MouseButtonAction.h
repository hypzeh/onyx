#pragma once
#include "..\..\pch.h"
#include <GLFW\glfw3.h>

namespace Onyx::Engine::System::Events
{
  enum class MouseButtonAction
  {
    Press = GLFW_PRESS,
    Release = GLFW_RELEASE
  };
}
