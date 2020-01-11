#pragma once
#include "pch.h"

namespace Onyx::System
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& properties);
		~WindowsWindow();
		void OnUpdate() override;
	private:
		HWND m_Handle;
		WindowProperties m_Properties;

		void Initialise();
		void Shutdown();
	};
}
