#pragma once
#include "pch.h"

namespace Onyx::System
{
	struct WindowProperties
	{
		std::string Title;

		WindowProperties(std::string title)
			: Title(title)
		{

		}
	};

	class Window
	{
	public:
		static std::unique_ptr<Window> Create(const WindowProperties& properties);

		virtual void OnUpdate() = 0;
	};
}
