#include "Application.h"
#include "magic_enum.hpp"

namespace Onyx::Engine::System
{
  Application::Application()
  {
    ONYX_LOG_TRACE("Onyx Engine");
    window_ = Window::Create(WindowProperties());
    window_->OnEvent(std::bind(&Application::HandleEvent, this, std::placeholders::_1));
  }

  Application::~Application()
  {}

  void Application::PushLayer(Layer* layer)
  {
    layers_.push_back(layer);
  }

  void Application::Run()
  {
    OnRun();
    is_running_ = true;
    while (is_running_)
    {
      window_->Update();
      for (auto layer : layers_)
      {
        layer->Update();
      }
    }
  }

  void Application::OnClose(const WindowCloseEvent& event)
  {
    ONYX_LOG_TRACE(event.GetName());
  }

  void Application::OnResize(const WindowResizeEvent& event)
  {
    std::stringstream output;
    output << event.GetName() << "\twidth: " << event.GetWidth() << "  height: " << event.GetHeight();
    ONYX_LOG_TRACE(output.str());
  }

  void Application::OnMouseMove(const MouseMoveEvent& event)
  {
    std::stringstream output;
    output << event.GetName() << "\tx: " << event.GetPositionX() << "  y: " << event.GetPositionY();
    ONYX_LOG_TRACE(output.str());

  }

  void Application::OnMouseClick(const MouseClickEvent& event)
  {
    std::stringstream output;
    output << event.GetName() << "\tbutton: " << magic_enum::enum_name(event.GetButtonType()) 
      << " action: " << magic_enum::enum_name(event.GetButtonAction());
    ONYX_LOG_TRACE(output.str());
  }

  void Application::OnRun()
  {
    ONYX_LOG_TRACE("Application run");
  }

  void Application::HandleEvent(const Event& event)
  {
    switch (event.GetType())
    {
    case EventType::WindowClose:
      is_running_ = false;
      OnClose(dynamic_cast<const WindowCloseEvent&>(event));
      break;

    case EventType::WindowResize:
      OnResize(dynamic_cast<const WindowResizeEvent&>(event));
      break;

    case EventType::MouseMove:
      OnMouseMove(dynamic_cast<const MouseMoveEvent&>(event));
      break;

    case EventType::MouseClick:
      OnMouseClick(dynamic_cast<const MouseClickEvent&>(event));
      break;

    default:
      ONYX_LOG_WARNING("Unknown event");
      break;
    }

    for (auto layer : layers_)
    {
      layer->HandleEvent(event);
    }
  }
}
