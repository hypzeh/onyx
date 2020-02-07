#pragma once
#include "..\pch.h"

namespace Onyx::Engine::System
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& properties);
		~WindowsWindow();

		std::string GetTitle() const override { return m_Properties.Title; }
		void SetTitle(const std::string& title) override;
		void OnEvent(const WindowProperties::DispatchEventFunc& callback) override { m_Properties.DispatchEvent = callback; }
		void Update() override;
	private:
		WindowProperties m_Properties;
		HWND m_Handle;

		void Initialise();
		void Shutdown();
	};
}
