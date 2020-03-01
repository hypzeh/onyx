#include "LayerStack.h"

namespace Onyx::Engine::Components
{
  LayerStack::LayerStack()
  {}

  void LayerStack::PushLayer(const Layer* layer)
  {
    layers_.push_back(layer);
  }
}
