#include "Window.h"
#include "WindowsWindow.h"

namespace Onyx::Engine::System
{
	std::unique_ptr<Window> Window::Create(const WindowProperties& properties)
	{
		return std::make_unique<WindowsWindow>(properties);
	}

	Window::Window(const WindowProperties& properties)
		: properties_(properties)
	{}

	const WindowProperties& Window::GetProperties() const
	{
		return properties_;
	}

	const std::string Window::GetTitle() const
	{
		return properties_.Title;
	}

	const unsigned int Window::GetWidth() const
	{
		return properties_.Width;
	}

	const unsigned int Window::GetHeight() const
	{
		return properties_.Height;
	}

	const bool Window::IsVSyncEnabled() const
	{
		return properties_.VSyncEnabled;
	}

	void Window::OnEvent(const WindowProperties::DispatchEventFunc& callback)
	{
		properties_.DispatchEvent = callback;
	}

	void Window::SetTitle(const std::string& title)
	{
		properties_.Title = title;
		OnTitleChange(title);
	}

	void Window::SetSize(const unsigned int& width, const unsigned int& height)
	{
		properties_.Width = width;
		properties_.Height = height;
		OnSizeChange(width, height);
	}

	void Window::EnableVSync()
	{
		properties_.VSyncEnabled = true;
		OnVSyncChange(true);
	}

	void Window::DisableVSync()
	{
		properties_.VSyncEnabled = false;
		OnVSyncChange(false);
	}

	void Window::Update() const
	{
		OnUpdate();
	}
}