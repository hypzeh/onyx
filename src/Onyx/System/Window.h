#pragma once
#include "pch.h"

namespace Onyx::System
{
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(
			const std::string& title	= "ONYX_ENGINE",
			unsigned int width			= 1280,
			unsigned int height			= 720)
			:	Title(title),
				Width(width),
				Height(height)
		{}
	};

	class Window
	{
	public:
		static std::unique_ptr<Window> Create(const WindowProperties& properties);

		virtual ~Window() = default;

		virtual std::string GetTitle() const = 0;
		virtual void SetTitle(const std::string& title) = 0;
		virtual void OnUpdate() = 0;
	};
}
