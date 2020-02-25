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

		const WindowProperties& GetProperties() const;
		const std::string GetTitle() const;
		const unsigned int GetWidth() const;
		const unsigned int GetHeight() const;
		const bool IsVSyncEnabled() const;
		void OnEvent(const WindowProperties::DispatchEventFunc& callback);
		void SetTitle(const std::string& title);
		void SetSize(const unsigned int& width, const unsigned int& height);
		void EnableVSync();
		void DisableVSync();
		void Update() const;

	protected:
		virtual void OnTitleChange(const std::string& title) const = 0;
		virtual void OnSizeChange(const unsigned int& width, const unsigned int& height) const = 0;
		virtual void OnVSyncChange(const bool& is_enabled) const = 0;
		virtual void OnUpdate() const = 0;
		
	private:
		WindowProperties properties_;
	};
}
