#pragma once
#include "Process.h"
#include <time.h>

class WaitForSeconds : public Process
{
	bool firstTime = true;
	float seconds;
	time_t* startTime = new time_t(0);

public:

	bool Invoke();

	WaitForSeconds(float seconds);

	~WaitForSeconds();
};

