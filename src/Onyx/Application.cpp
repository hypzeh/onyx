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
		std::cout << "Onyx::Run()\n";
		std::cin.get();
	}
}
