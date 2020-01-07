#include "pch.h"
#include "WindowsWindow.h"

namespace Onyx::System
{
	static LRESULT CALLBACK windowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProcW(hWnd, uMsg, wParam, lParam);
	}

	std::unique_ptr<Window> Window::Create(const WindowProperties& properties)
	{
		return std::make_unique<WindowsWindow>(properties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& properties)
	{
		Initialise(properties);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		MSG msg;
		if (GetMessage(&msg, nullptr, 0, 0) > 0) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	void WindowsWindow::Initialise(const WindowProperties& properties)
	{
		auto id = std::wstring(properties.Identifier.begin(), properties.Identifier.end());
		m_windowID = id.c_str();

		WNDCLASSEXW wc;
		ZeroMemory(&wc, sizeof(wc));
		wc.cbSize			= sizeof(wc);
		wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc		= (WNDPROC)windowProc;
		wc.hInstance		= GetModuleHandleW(nullptr);
		wc.hCursor			= LoadCursorW(nullptr, IDC_ARROW);
		wc.lpszClassName	= m_windowID;

		if (!RegisterClassExW(&wc))
		{
			ONYX_LOG_ERROR("Could not register window");
			return;
		}

		auto name = std::wstring(properties.Title.begin(), properties.Title.end());;
		m_window = CreateWindowExW(
			WS_EX_APPWINDOW,
			m_windowID,
			name.c_str(),
			WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			properties.Width,
			properties.Height,
			nullptr,
			nullptr,
			GetModuleHandleW(nullptr),
			nullptr);

		if (!m_window)
		{
			ONYX_LOG_ERROR("Could not create window");
			return;
		}

		ShowWindow(m_window, SW_SHOWNA);
		SetForegroundWindow(m_window);
		SetFocus(m_window);
	}

	void WindowsWindow::Shutdown()
	{
		UnregisterClassW(m_windowID, GetModuleHandleW(nullptr));
	}
}
