#include "pch.h"
#include "Application.h"

namespace Onyx::System
{
	Application::Application()
	{
		m_Window = Window::Create(WindowProperties());
		m_Window->OnEvent(std::bind(&Application::HandleEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		ONYX_LOG_TRACE("Onyx Engine.");
		while (true)
		{
			m_Window->OnUpdate();
		}
	}

	void Application::HandleEvent(const Event& event)
	{
		ONYX_LOG_TRACE("EVENT RAISED");
	}
}
