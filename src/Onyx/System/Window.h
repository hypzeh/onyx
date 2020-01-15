#pragma once
#include "pch.h"
#include "System\Event.h"

namespace Onyx::System
{
	struct WindowProperties
	{
		using DispatchEventFunc = std::function<void(Event&)>;

		std::string Title;
		unsigned int Width;
		unsigned int Height;
		DispatchEventFunc DispatchEvent;

		WindowProperties(
			const std::string& title	= "ONYX_ENGINE",
			unsigned int width			= 1280,
			unsigned int height			= 720,
			DispatchEventFunc dispatch	= [](const Event&) {})
			:	Title(title),
				Width(width),
				Height(height),
				DispatchEvent(dispatch)
		{}
	};

	class Window
	{
	public:
		static std::unique_ptr<Window> Create(const WindowProperties& properties);

		virtual ~Window() = default;

		virtual std::string GetTitle() const = 0;
		virtual void SetTitle(const std::string& title) = 0;
		virtual void OnEvent(const WindowProperties::DispatchEventFunc& callback) = 0;
		virtual void OnUpdate() = 0;
	};
}
