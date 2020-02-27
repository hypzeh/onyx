#pragma once
#include "..\..\pch.h"

namespace Onyx::Engine::System::Events
{
	enum class EventType
	{
		None					= 0,
		WindowClose		= 1,
		WindowResize	= 2,
	};
}