#include "..\pch.h"
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

	void Application::OnClose()
	{
		ONYX_LOG_TRACE("Window closed");
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
			OnClose();
			break;
		}
	}
}
