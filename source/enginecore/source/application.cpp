#include "include\application.h"

#include <SDL.h>

bool Application::ProcessEvents(const SDL_Event* inEventPtr)
{
    if (inEventPtr == nullptr)
    {
        return true;
    }

    if (inEventPtr->type == SDL_QUIT)
    {
        return false;
    }

    return true;
}
