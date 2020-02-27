#pragma once
#include "..\pch.h"

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
    virtual void OnClose();
    virtual void OnRun();

  private:
    std::unique_ptr<Window> window_;
    bool is_running_;

    void HandleEvent(const Event& event);
  };
}
