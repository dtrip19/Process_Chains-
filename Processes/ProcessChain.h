#pragma once
#include "Events.h"
#include "Process.h"
#include <vector>
#include <string>

class ProcessChain
{
	std::vector<Process*> processes;
	std::string name;
	bool started = false;
	Event<>* updateEvent;

	EventListener<>* Loop = new EventListener<>([this]() {
		if (!started) { return; }

		for (size_t i = 0; i < processes.size(); i++)
		{
			if (processes[i] && !processes[i]->Invoke()) { return; }

			if (i == processes.size() - 1) {
				OnProcessComplete.Invoke(this);
				delete this;
				break;
			}
		}
	});

	ProcessChain(std::string name, Event<>* updateEvent, std::vector<Process*> processes);

public:

	Event<ProcessChain*> OnProcessComplete;

	void Start();

	static ProcessChain* CreateProcess(std::string name, Event<>* updateEvent, std::vector<Process*> processes);

	std::string Name();

	~ProcessChain();
};