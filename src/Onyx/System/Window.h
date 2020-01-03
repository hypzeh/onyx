#pragma once
#include "pch.h"
#include "WindowProperties.h"

namespace Onyx::System
{
	class Window
	{
	public:
		static std::unique_ptr<Window> Create(const WindowProperties& properties);
	};
}
