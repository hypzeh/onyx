#include "WindowsWindow.h"

namespace Onyx::Engine::System
{
  WindowsWindow::WindowsWindow(const WindowProperties& properties)
    : Window(properties)
  {
    Initialise();
  }

  WindowsWindow::~WindowsWindow()
  {
    Shutdown();
  }

  void WindowsWindow::OnTitleChange(const std::string& title) const
  {
    glfwSetWindowTitle(window_, title.c_str());
  }

  void WindowsWindow::OnSizeChange(const unsigned int& width, const unsigned int& height) const
  {
    glfwSetWindowSize(window_, width, height);
  }

  void WindowsWindow::OnVSyncChange(const bool& is_enabled) const
  {
    glfwSwapInterval(is_enabled ? 1 : 0);
  }

  void WindowsWindow::OnUpdate() const
  {
    glfwPollEvents();
  }

  void WindowsWindow::Initialise()
  {
    if (!glfwInit())
    {
      ONYX_LOG_ERROR("Could not initialise GLFW");
      return;
    }

    window_ = glfwCreateWindow(GetWidth(), GetHeight(), GetTitle().c_str(), nullptr, nullptr);

    auto* properties = GetProperties();
    glfwSetWindowUserPointer(window_, (void*)properties);
    glfwSwapInterval(properties->VSyncEnabled ? 1 : 0);

    glfwSetWindowCloseCallback(window_, [](auto window)
    {
      auto properties = (WindowProperties*)glfwGetWindowUserPointer(window);
      auto event      = WindowCloseEvent();
      properties->DispatchEvent(event);
    });

    glfwSetWindowSizeCallback(window_, [](auto window, int width, int height)
    {
      auto properties     = (WindowProperties*)glfwGetWindowUserPointer(window);
      auto event          = WindowResizeEvent(width, height);
      properties->Width   = width;
      properties->Height  = height;
      properties->DispatchEvent(event);
    });

    glfwSetCursorPosCallback(window_, [](auto window, double position_x, double position_y)
    {
      auto properties = (WindowProperties*)glfwGetWindowUserPointer(window);
      auto event      = MouseMoveEvent((float)position_x, (float)position_y);
      properties->DispatchEvent(event);
    });

    glfwSetMouseButtonCallback(window_, [](auto window, auto button, auto action, auto modifiers)
    {
      auto properties = (WindowProperties*)glfwGetWindowUserPointer(window);
      auto event = MouseClickEvent(static_cast<MouseButtonType>(button));
      properties->DispatchEvent(event);
    });
  }

  void WindowsWindow::Shutdown()
  {
    glfwDestroyWindow(window_);
    glfwTerminate();
  }
}
