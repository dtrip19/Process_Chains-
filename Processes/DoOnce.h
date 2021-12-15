#pragma once
#include "Process.h"
#include <functional>

class DoOnce : public Process
{
	bool hasBeenInvoked = false;
	std::function<void()> action;

public:

	bool Invoke();

	DoOnce(std::function<void()> action);
};

