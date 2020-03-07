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
    void HandleEvent(const Event& event);
    void Update();

  protected:
    virtual void OnEvent(const Event& event)  = 0;
    virtual void OnUpdate()                   = 0;

  private:
    std::string name_;
  };
}
