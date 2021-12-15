#include "pch.h"
#include "WaitForSeconds.h"
#include <iostream>

bool WaitForSeconds::Invoke() {
	if (firstTime) {
		*startTime = time(startTime);
		firstTime = false;
		std::cout << "Waiting for " << seconds << " seconds" << '\n';
	}

	float timeSinceStart = time(NULL) - *startTime;
	if (timeSinceStart >= seconds) { return true; }
	else { return false; }
}

WaitForSeconds::WaitForSeconds(float seconds) {
	this->seconds = seconds;
}

WaitForSeconds::~WaitForSeconds() {
	delete startTime;
}