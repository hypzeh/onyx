#include "..\pch.h"
#include "Application.h"

namespace Onyx::Engine::System
{
	Application::Application()
	{
		ONYX_LOG_TRACE("Onyx Engine");
		m_Window = Window::Create(WindowProperties());
		m_Window->OnEvent(std::bind(&Application::HandleEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		m_Running = true;
		while (m_Running)
		{
			m_Window->Update();
		}
	}

	void Application::HandleEvent(const Event& event)
	{
		switch (event.GetType())
		{
		case EventType::WindowClose:
		{
			ONYX_LOG_TRACE("Window closed event");
			m_Running = false;
		}
		}
	}
}
