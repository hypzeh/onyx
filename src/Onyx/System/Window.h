#pragma once
#include "pch.h"

namespace Onyx::System
{
	struct WindowProperties
	{
		std::string Identifier;
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(std::string identifier, std::string title, unsigned int width, unsigned int height)
			: Identifier(identifier), Title(title), Width(width), Height(height)
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
