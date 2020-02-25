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

	const WindowProperties* Window::GetProperties() const
	{
		return &properties_;
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

	void Window::OnEvent(const WindowProperties::DispatchEventFunc& callback)
	{
		properties_.DispatchEvent = callback;
	}

	void Window::SetTitle(const std::string& title)
	{
		properties_.Title = title;
		OnSetTitle();
	}

	void Window::SetSize(unsigned int& width, unsigned int& height)
	{
		properties_.Width = width;
		properties_.Height = height;
		OnSetSize();
	}

	void Window::Update() const
	{
		OnUpdate();
	}
}