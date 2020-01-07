#include "pch.h"
#include "Application.h"

namespace Onyx::System
{
	Application::Application()
	{
		m_Window = Window::Create(WindowProperties("Onyx Engine", 1280, 720));
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
}
