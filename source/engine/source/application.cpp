#include <application.h>

#include <SDL.h>
#include <logging.h>

bool Application::ProcessEvents(const SDL_Event* inEventPtr) const
{
    Logging::Log("Hello world!\n");

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
