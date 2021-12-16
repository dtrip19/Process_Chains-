#include "pch.h"
#include "GlobalEvents.h"
#include "Processor.h"
#include <iostream>

class Test : Processor
{
    int num = 1000;

    void OtherFunction()
    {
        std::cout << "num has been reduced by 1, num is now " << num << '\n';
    }

public:

    Event<> OnEndProcess;

    void SomeFunction()
    {
        StartProcess(ProcessChain::CreateProcess("name", &OnUpdate, std::vector<Process*>
        {
            new DoOnUpdate(-1, [this]() { num--; OtherFunction(); }, [this]() { return num > 0; }),
            new DoOnUpdate(5, []() { std::cout << "This is a message\n"; }, NULL),
            new DoOnce([this]() { OnEndProcess.Invoke(); })
        }));
    }
};

int main()
{ 
    bool* loop = new bool(true);
    Test test;

    test.SomeFunction();
    EventListener<>* listener = test.OnEndProcess.AddListener(new EventListener<>([listener, loop]() { *loop = false; std::cout << "Setting loop to false\n"; }));

	while (*loop == true) {
        if (*loop == false) { std::cout << "This should not be possible\n"; }
		OnUpdate.Invoke();
	}

    delete listener;
}