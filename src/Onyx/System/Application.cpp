#include "pch.h"
#include "Application.h"

namespace Onyx::System
{
	Application::Application()
	{
		m_Window = Window::Create(WindowProperties());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		ONYX_LOG_TRACE("Onyx Engine.");
		std::cin.get();
	}
}
