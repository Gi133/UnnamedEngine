union SDL_Event;

class Application
{
public:
    bool ProcessEvents(const SDL_Event* inEventPtr);
};