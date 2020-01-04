#pragma once
#include "pch.h"

namespace Onyx::System
{
	struct WindowProperties
	{
		std::string Title;
	};

	class Window
	{
	public:
		static std::unique_ptr<Window> Create(const WindowProperties& properties);
	};
}
