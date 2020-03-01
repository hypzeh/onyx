#pragma once
#include "..\pch.h"

namespace Onyx::Engine::Components
{
  class Layer
  {
  public:
    Layer(const std::string& name);
    virtual ~Layer() = default;

    const std::string& GetName() const;
    void Update() const;

  protected:
    virtual void OnUpdate() const = 0;

  private:
    std::string name_;
  };
}
