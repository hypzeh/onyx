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
		: m_Properties(properties)
	{
		Initialise();
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

	void WindowsWindow::Initialise()
	{
		WNDCLASSEXW wc;
		ZeroMemory(&wc, sizeof(wc));
		wc.cbSize			= sizeof(wc);
		wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc		= (WNDPROC)windowProc;
		wc.hInstance		= GetModuleHandleW(nullptr);
		wc.hCursor			= LoadCursorW(nullptr, IDC_ARROW);
		wc.lpszClassName	= L"ONYX_WINDOW";

		if (!RegisterClassExW(&wc))
		{
			ONYX_LOG_ERROR("Could not register window");
			return;
		}

		auto title = std::wstring(m_Properties.Title.begin(), m_Properties.Title.end());;
		m_Handle = CreateWindowExW(
			WS_EX_APPWINDOW,
			L"ONYX_WINDOW",
			title.c_str(),
			WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			m_Properties.Width,
			m_Properties.Height,
			nullptr,
			nullptr,
			GetModuleHandleW(nullptr),
			nullptr);

		if (!m_Handle)
		{
			ONYX_LOG_ERROR("Could not create window");
			return;
		}

		ShowWindow(m_Handle, SW_SHOWNA);
		SetForegroundWindow(m_Handle);
		SetFocus(m_Handle);
	}

	void WindowsWindow::Shutdown()
	{
		UnregisterClassW(L"ONYX_WINDOW", GetModuleHandleW(nullptr));
	}
}
