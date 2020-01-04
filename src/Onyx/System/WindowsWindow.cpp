#include "pch.h"
#include "WindowsWindow.h"

namespace Onyx::System
{
	std::unique_ptr<Window> Window::Create(const WindowProperties& properties)
	{
		return std::make_unique<WindowsWindow>(properties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& properties)
	{

	}
}