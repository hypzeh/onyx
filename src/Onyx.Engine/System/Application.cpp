#include "Application.h"

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

	void Application::Run()
	{
		OnRun();
		is_running_ = true;
		while (is_running_)
		{
			window_->Update();
		}
	}

	void Application::OnClose(const WindowCloseEvent& event)
	{
		ONYX_LOG_TRACE("Window closed");
	}

	void Application::OnResize(const WindowResizeEvent& event)
	{
		std::stringstream output;
		output << "Window Resized\twidth: " << event.GetWidth() << "  height: " << event.GetHeight();
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

		default:
			ONYX_LOG_WARNING("Unknown event");
			break;
		}
	}
}
