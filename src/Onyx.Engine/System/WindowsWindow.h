#pragma once
#include "..\pch.h"
#include <GLFW\glfw3.h>

namespace Onyx::Engine::System
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& properties);
		~WindowsWindow();

	protected:
		void OnSetTitle() const override;
		void OnSetSize() const override;
		void OnUpdate() const override;

	private:
		GLFWwindow* window_;

		void Initialise();
		void Shutdown();
	};
}
