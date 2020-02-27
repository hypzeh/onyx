#pragma once
#include "..\pch.h"
#include <GLFW\glfw3.h>

namespace Onyx::Engine::System
{
  class WindowsWindow : public Window
  {
  public:
    WindowsWindow(const WindowProperties& properties);
    ~WindowsWindow();

  protected:
    void OnTitleChange(const std::string& title) const override;
    void OnSizeChange(const unsigned int& width, const unsigned int& height) const override;
    void OnVSyncChange(const bool& is_enabled) const override;
    void OnUpdate() const override;

  private:
    GLFWwindow* window_;

    void Initialise();
    void Shutdown();
  };
}
