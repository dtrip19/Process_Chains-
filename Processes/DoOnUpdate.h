#pragma once
#include "Process.h"
#include <functional>

class DoOnUpdate : public Process
{
	int iterationsLeft;
	std::function<void()> action;
	std::function<bool()> condition;

public:

	bool Invoke();

	DoOnUpdate(int numIterations, std::function<void()> action, std::function<bool()> condition);
};

