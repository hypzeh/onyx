#include "pch.h"
#include "Application.h"

namespace Onyx
{
	Application::Application()
	{

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
