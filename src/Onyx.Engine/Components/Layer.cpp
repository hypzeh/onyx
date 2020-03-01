#include "Layer.h"

namespace Onyx::Engine::Components
{
  Layer::Layer(const std::string& name)
    : name_(name)
  {}

  const std::string& Layer::GetName() const
  {
    return name_;
  }
}
