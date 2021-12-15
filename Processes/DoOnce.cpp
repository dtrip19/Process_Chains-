#include "pch.h"
#include "DoOnce.h"

bool DoOnce::Invoke() {
	if (action != NULL && !hasBeenInvoked) {
		action();
	}

	hasBeenInvoked = true;
	return true;
}

DoOnce::DoOnce(std::function<void()> action) {
	this->action = action;
}