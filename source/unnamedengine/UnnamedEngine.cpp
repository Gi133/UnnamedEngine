#include "UnnamedEngine.h"

#include <SDL.h>
#include <application.h>

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	const std::unique_ptr<Application> applicationPtr = std::make_unique<Application>();

	auto* windowPtr = SDL_CreateWindow(
		"Unnamed Engine"
		, SDL_WINDOWPOS_UNDEFINED
		, SDL_WINDOWPOS_UNDEFINED
		, 800
		, 600
		, SDL_WINDOW_OPENGL
	);

	if (windowPtr == nullptr)
	{
		std::printf("Could not create window: %s", SDL_GetError());
		return 1;
	}

	bool running = true;
	do
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			// while i come up with a better way to do this.
			running = applicationPtr->ProcessEvents(&event);
		}
	} 	while (running == true);

	SDL_DestroyWindow(windowPtr);

	return 0;
}
