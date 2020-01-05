#include "pch.h"
#include "WindowsWindow.h"

namespace Onyx::System
{
	static auto NAME = L"Test";

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
		if (GetMessage(&msg, NULL, 0, 0) > 0) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	void WindowsWindow::Initialise(const WindowProperties& properties)
	{
		WNDCLASSEXW wc;

		ZeroMemory(&wc, sizeof(wc));
		wc.cbSize = sizeof(wc);
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = (WNDPROC)windowProc;
		wc.hInstance = GetModuleHandleW(NULL);
		wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
		wc.lpszClassName = NAME;

		if (!RegisterClassExW(&wc))
		{
			ONYX_LOG_ERROR("Could not register window");
			return;
		}

		m_window = CreateWindowExW(
			WS_EX_APPWINDOW,
			NAME,
			NAME,
			WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,
			CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720,
			NULL,
			NULL,
			GetModuleHandleW(NULL),
			NULL);

		if (!m_window)
		{
			ONYX_LOG_ERROR("Could not create window");
			return;
		}

		ShowWindow(m_window, SW_SHOWNA);
	}

	void WindowsWindow::Shutdown()
	{
		UnregisterClassW(NAME, GetModuleHandleW(NULL));
	}
}
