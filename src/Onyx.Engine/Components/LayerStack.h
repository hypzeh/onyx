#pragma once
#include "..\pch.h"

namespace Onyx::Engine::Components
{
  class LayerStack
  {
  public:
    LayerStack();
    virtual ~LayerStack() = default;

    void PushLayer(const Layer* layer);

  private:
    std::vector<const Layer*> layers_;
  };
}
