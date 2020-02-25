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

	void WindowsWindow::OnSetTitle() const
	{
		glfwSetWindowTitle(window_, GetTitle().c_str());
	}

	void WindowsWindow::OnSetSize() const
	{
		glfwSetWindowSize(window_, GetWidth(), GetHeight());
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

		glfwSetWindowUserPointer(window_, (void*)GetProperties());
		glfwSwapInterval(1); // TODO: Don't hardcode V-Sync

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
