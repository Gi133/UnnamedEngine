#pragma once
#include <engine.h>

union SDL_Event;

class ENGINE_EXPORT Application
{
public:
    bool ProcessEvents(const SDL_Event* inEventPtr) const;
};
