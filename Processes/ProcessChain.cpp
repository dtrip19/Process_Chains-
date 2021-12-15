#include "pch.h"
#include "ProcessChain.h"

void ProcessChain::Start() {
	if (started) { return; }

	started = true;
	Loop->Trigger();
}

ProcessChain* ProcessChain::CreateProcess(std::string name, Event<>* updateEvent, std::vector<Process*> processes) {
	ProcessChain* newProcess = new ProcessChain(name, updateEvent, processes);
	return newProcess;
}

std::string ProcessChain::Name() {
	return name;
}

ProcessChain::ProcessChain(std::string name, Event<>* updateEvent, std::vector<Process*> processes) {
	this->name = name;
	this->processes = processes;
	updateEvent->AddListener(Loop);
}

ProcessChain::~ProcessChain() {
	delete Loop;
	for (int i = processes.size() - 1; i >= 0; i--)
	{
		delete processes.at(i);
	}
}