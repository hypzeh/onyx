#pragma once
#include "..\pch.h"

namespace Onyx::Engine::Components
{
  class Layer
  {
  public:
    Layer(const std::string& name);

  private:
    std::string name_;
  };
}
