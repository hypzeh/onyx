#pragma once
#include "pch.h"

namespace Onyx::System
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow();
	private:
		virtual void Initialise(const WindowProperties& properties);
		virtual void Shutdown();
	private:
		HWND m_window;
	};
}
