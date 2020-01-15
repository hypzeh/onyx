#pragma once
#include "pch.h"

namespace Onyx::System
{
	class Application
	{
	public:
		Application();
		~Application();
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		void HandleEvent(const Event& event);
	};
}
