#include "..\pch.h"
#include "WindowsWindow.h"
#include "WindowCloseEvent.h"

namespace Onyx::Engine::System
{
	std::unique_ptr<Window> Window::Create(const WindowProperties& properties)
	{
		return std::make_unique<WindowsWindow>(properties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& properties)
		: m_Properties(properties)
	{
		Initialise();
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::SetTitle(const std::string& title)
	{
		m_Properties.Title = title;
		glfwSetWindowTitle(m_Handle, m_Properties.Title.c_str());
	}

	void WindowsWindow::Update()
	{
		glfwPollEvents();
	}

	void WindowsWindow::Initialise()
	{
		if (!glfwInit())
		{
			ONYX_LOG_ERROR("Could not initialise GLFW");
			return;
		}

		m_Handle = glfwCreateWindow(m_Properties.Width, m_Properties.Height, m_Properties.Title.c_str(), nullptr, nullptr);
		glfwSetWindowUserPointer(m_Handle, &m_Properties);
		glfwSwapInterval(1); // TODO: Don't hardcode V-Sync

		glfwSetWindowCloseCallback(m_Handle, [](auto window)
		{
			auto properties = (WindowProperties*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			properties->DispatchEvent(event);
		});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Handle);
		glfwTerminate();
	}
}
