#pragma once
#include "pch.h"

namespace Onyx::System
{
	class Event
	{
	public:
		virtual std::string GetName() const = 0;
	};
}
