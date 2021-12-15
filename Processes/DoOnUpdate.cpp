#include "pch.h"
#include "DoOnUpdate.h"

bool DoOnUpdate::Invoke()
{
    if (iterationsLeft == 0) { return true; }

    if (iterationsLeft > 0)
    {
        if (action != NULL && (condition == NULL || condition != NULL && condition()))
            { action(); }

        if (condition == NULL || condition != NULL && condition())
            { iterationsLeft--; }

        return false;
    }
    else if (iterationsLeft == -1)
    {
        if (condition == NULL || condition != NULL && condition())
        {
            if (action != NULL)
                { action(); }

            return false;
        }
    }

    return true;
}

DoOnUpdate::DoOnUpdate(int numIterations, std::function<void()> action, std::function<bool()> condition)
{
    iterationsLeft = numIterations;
    this->action = action;
    this->condition = condition;
}
