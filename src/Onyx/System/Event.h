#pragma once
#include "pch.h"

namespace Onyx::System
{
	class Event
	{
	public:
		std::string GetName() const { return "MY_TEST_EVENT"; }
	};
}
