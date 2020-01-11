#pragma once
#include "pch.h"

namespace Onyx::System
{
	struct WindowProperties
	{
		std::string ID;
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(
			const std::string& id,
			const std::string& title	= "ONYX_ENGINE",
			unsigned int width			= 1280,
			unsigned int height			= 720)
			:	ID(id),
				Title(title),
				Width(width),
				Height(height)
		{}
	};

	class Window
	{
	public:
		static std::unique_ptr<Window> Create(const WindowProperties& properties);

		virtual void OnUpdate() = 0;
	};
}
