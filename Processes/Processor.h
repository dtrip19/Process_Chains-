#pragma once
#include "ProcessChain.h"
#include "DoOnce.h"
#include "DoOnUpdate.h"
#include "WaitForSeconds.h"
#include <vector>
#include <iostream>

class Processor
{
	std::vector<ProcessChain*> processes;

public:

	void StartProcess(ProcessChain* process);

	void EndProcess(std::string processToEnd);

	void EndAllProcesses();

	EventListener<ProcessChain*>* RemoveProcessFromList = new EventListener<ProcessChain*>([this](ProcessChain* process) {
		std::cout << "OnProcessComplete call received\n";
		for (size_t i = 0; i < processes.size(); i++)
		{
			if (processes[i] == process) {
				processes.erase(processes.begin() + i);
			}
		}
	});

	virtual ~Processor() = 0;
};

