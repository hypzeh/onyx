#pragma once
#include "..\pch.h"
#include "..\Components\Layer.h"

using namespace Onyx::Engine::Components;
using namespace Onyx::Engine::System::Events;

namespace Onyx::Engine::System
{
  class Application
  {
  public:
    Application();
    ~Application();

    void Run();

  protected:
    void PushLayer(Layer* layer);

    virtual void OnClose(const WindowCloseEvent& event);
    virtual void OnResize(const WindowResizeEvent& event);
    virtual void OnMouseMove(const MouseMoveEvent& event);
    virtual void OnMouseClick(const MouseClickEvent& event);
    virtual void OnRun();

  private:
    std::unique_ptr<Window> window_;
    std::vector<Layer*> layers_;
    bool is_running_;

    void HandleEvent(const Event& event);
  };
}
