#include "pch.h"
#include "Processor.h"

void Processor::StartProcess(ProcessChain* process) {
	processes.push_back(process);
	process->OnProcessComplete.AddListener(RemoveProcessFromList);
	process->Start();
}

void Processor::EndProcess(std::string processToEnd) {
	for (int i = processes.size() - 1; i >= 0; i--)
	{
		if (processToEnd == processes.at(i)->Name()) {
			delete processes.at(i);
			processes.erase(processes.begin() + i);
		}
	}
}

void Processor::EndAllProcesses() {
	for (int i = processes.size() - 1; i >= 0; i--)
	{
		delete processes.at(i);
		processes.erase(processes.begin() + i);
	}
}

Processor::~Processor() { delete RemoveProcessFromList; }