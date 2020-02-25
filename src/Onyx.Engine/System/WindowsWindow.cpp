#include "..\pch.h"
#include "WindowsWindow.h"
#include "WindowCloseEvent.h"

namespace Onyx::Engine::System
{
	WindowsWindow::WindowsWindow(const WindowProperties& properties)
		: Window(properties)
	{
		Initialise();
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnTitleChange(const std::string& title) const
	{
		glfwSetWindowTitle(window_, title.c_str());
	}

	void WindowsWindow::OnSizeChange(const unsigned int& width, const unsigned int& height) const
	{
		glfwSetWindowSize(window_, width, height);
	}

	void WindowsWindow::OnVSyncChange(const bool& is_enabled) const
	{
		glfwSwapInterval(is_enabled ? 1 : 0);
	}

	void WindowsWindow::OnUpdate() const
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

		window_ = glfwCreateWindow(GetWidth(), GetHeight(), GetTitle().c_str(), nullptr, nullptr);

		auto properties = &GetProperties();
		glfwSetWindowUserPointer(window_, (void*)properties);
		glfwSwapInterval(properties->VSyncEnabled ? 1 : 0);

		glfwSetWindowCloseCallback(window_, [](auto window)
		{
			auto properties = (WindowProperties*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			properties->DispatchEvent(event);
		});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(window_);
		glfwTerminate();
	}
}
