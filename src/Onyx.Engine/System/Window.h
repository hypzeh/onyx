#pragma once
#include "..\pch.h"
#include "WindowProperties.h"

namespace Onyx::Engine::System
{
	class Window
	{
	public:
		static std::unique_ptr<Window> Create(const WindowProperties& properties);

		Window(const WindowProperties& properties);
		virtual ~Window() = default;

		const WindowProperties* GetProperties() const;
		const std::string GetTitle() const;
		const unsigned int GetWidth() const;
		const unsigned int GetHeight() const;
		void OnEvent(const WindowProperties::DispatchEventFunc& callback);
		void SetTitle(const std::string& title);
		void SetSize(unsigned int& width, unsigned int& height);
		void Update() const;

	protected:
		virtual void OnSetTitle() const = 0;
		virtual void OnSetSize() const = 0;
		virtual void OnUpdate() const = 0;
		
	private:
		WindowProperties properties_;
	};
}
